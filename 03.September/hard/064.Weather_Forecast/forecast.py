#!/usr/bin/python

# Using forecast https://pypi.org/project/weather-api/
# Requires instalation:
# emerge dev-python/pip
# pip install --user weather-api
from weather import Weather, Unit

weather = Weather(unit=Unit.CELSIUS)

print("Wellcome to forecast! ")
answer = str(input("Enter a city: "))
while answer != "quit":
    location = weather.lookup_by_location(answer)

    if location is None:
        print("Theres no city like this one. ")
        print()
    else:
        condition = location.condition
        forecast = location.forecast
        print(condition.text,"-", condition.temp,"º")
        print()
        print(forecast[0].date)
        print("Todays condition:", forecast[0].text)
        print("Max:",forecast[0].high,"Min:", forecast[0].low)
        print()

    answer = str(input("Enter a city: "))

# next time try google's api
