/*
 * main.cpp
 *
 */

#include <iostream>
#include <dpy/gnssApi.h>
#include <dpyutils/logging.h>
#include <dpy/geofencingApi.h>
#include <dpy/mcuApi.h>
#include <dpy/smsApi.h>

class GeofencingObserver : public IgeofencingObserver {
	private:
		bool inZone;
		bool changed;

	public:
		GeofencingObserver(){
			changed = false;
			inZone = false;
		}
		~GeofencingObserver(){
		}
		void NewEvent (dpyGeofencing::Event event, int id, dpyGeofencing::Geofence geofence,double angle);
		bool isInZone(){
			return inZone;
		}

		bool isChanged(){
			return changed;
		}
		void setChanged(bool value){
			changed = value;
		}
};

void GeofencingObserver::NewEvent (dpyGeofencing::Event event, int id, dpyGeofencing::Geofence geofence,double angle){
	if(event == dpyGeofencing::ENTER){
		inZone = true;
		changed = true;
	} else if (event == dpyGeofencing::EXIT ){
		inZone = false;
		changed = true;
	}
}



void result_async_handler(boost::system::error_code ec)
{
    if (ec) {
        std::cout << "\rError : " << ec.message() << std::endl;
    } else {
        std::cout << "\rAsynchronous operation forwarded successfully" << std::endl;
    }
}

void leds_handler(boost::system::error_code error_code, dpyMcu::LedsConfig & leds_struct)
{
    std::string color;
    if (error_code.value() != 0) {
        std::cout << "Message Error " << error_code.value() << ": " <<error_code.message().c_str() << std::endl;
    } else {
        std::cout << "Message OK" << std::endl;
        std::cout << "Date: " << leds_struct.timestamp << std::endl;
        switch (leds_struct.color) {
            case dpyMcu::LedsColor::BLUE:
                color = "Blue";
            break;
            case dpyMcu::LedsColor::RED:
                color = "Red";
                break;
            case dpyMcu::LedsColor::GREEN:
                color = "Green";
                break;
            case dpyMcu::LedsColor::MAGENTA:
                color = "Magenta";
                break;
            case dpyMcu::LedsColor::YELLOW:
                color = "Yellow";
                break;
            case dpyMcu::LedsColor::CYAN:
                color = "Cyan";
                break;
            case dpyMcu::LedsColor::UNDEFINED:
                color = "Undefined";
                break;
        }
        std::cout << "Color: " << color << std::endl;
        std::cout << "Period: " << leds_struct.period << " seconds" << std::endl;
        std::cout << "Duty Cycle: " << leds_struct.duty_cycle << " %" << std::endl;
    }
}


void confirmation_handler(boost::system::error_code& error_code)
{
    if (error_code) {
        printf("result = %d, %s\n", error_code.value(), error_code.message().c_str());

    } else {
        std::cout << "Request has been processed." << std::endl;
    }
}

int main(int argc, char **argv)
{
   //name introduced in the logging object cannot contain special characters or spaces
   Logging log("app");
   DPYLOG_INFO("Starting App"); // @suppress("Method cannot be resolved")

   GeofencingObserver geofencingObserver;
   Geofencing geofencing;
   //geofencing = Geofencing();

   std::vector<std::pair<double, double>> positionList;
   positionList.push_back(std::pair<double, double>(35.1714917,33.3503306));
   positionList.push_back(std::pair<double, double>(35.1659056,33.3503222));
   positionList.push_back(std::pair<double, double>(35.1692000,33.3576694));
   positionList.push_back(std::pair<double, double>(35.1659056,33.3581444));
   geofencing.addGeofence(result_async_handler,96,"geofence_name",positionList);
   geofencing.enableGeofence(result_async_handler,96);
   geofencing.subscribePeriodicPosition(&geofencingObserver);

   Sms smsManager;

   Mcu mcu;
   std::uint32_t period = 0;
   std::uint32_t duty_cycle = 1;
   mcu.setLedsConfig(leds_handler, dpyMcu::LedsColor::RED, period, duty_cycle);
   int x = 1;
   while(1){
	   if(geofencingObserver.isChanged()){
		   geofencingObserver.setChanged(false);
		   if(geofencingObserver.isInZone()){
			   //poner led verde
			   mcu.setLedsConfig(leds_handler, dpyMcu::LedsColor::BLUE, period, duty_cycle);
		   } else {
			   //poner led rojo
			   mcu.setLedsConfig(leds_handler, dpyMcu::LedsColor::RED, period, duty_cycle);
			   if (x==1){
				   smsManager.sendSms("El bus salio bien", "601026421", confirmation_handler);
				   x=2;
			   }
		   }
	   }
	   sleep(1);
   }

}

