package calendar;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import java.util.Scanner;
/*

Create a program which prints out a table with the month's calendar in it, when the month and year is given as input.

Extra points for highlighting the current day and providing links to next and previous months.

Happy coding :)
*/

public class Calendar{

	public static void main(String[] args){
            Month m;
            String answer;
            
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter a year: ");
            int year = sc.nextInt();
            System.out.println("Enter a month: ");
            int month = sc.nextInt();

            do{
                if(month >13 || month<1){
                    System.out.println("Invalid. Enter a month: ");
                    month = sc.nextInt();
                } else {
                    m = new Month(year,month);
                    m.printMonth();
                    System.out.println("left/right: ");
                    answer = sc.nextLine();
                    switch(answer){
                        case "left":
                            if(month==1){
                                month=12;
                                year--;
                            } else {
                                month--;
                            }
                            break;
                        case "right":
                            if(month==12){
                                month=1;
                                year++;
                            } else {
                                month++;
                            }
                            break;
                    }
                }
            } while(true);
	}

}

class Month{

	private List<Integer> days;
        private int year;
        private int monthNumber;

	public Month(int year,int monthNumber){
                this.year=year;
                this.monthNumber = monthNumber;
                
		this.days = new ArrayList<>();
                int nDays = 31;
                
                if(monthNumber%2==0)
                    nDays=30;
                if(monthNumber==2){
                    if (isLeap(year))
                        nDays=29;
                    else
                        nDays=28;
                }
		for(int i=0; i<nDays; i++){
			days.add(i+1);
		}
	}

	public void printMonth(){
            	System.out.printf("\t%d : %d \n\n", this.year, this.monthNumber);
		for(int i : days){
			System.out.printf("\t%d ",i);
			if(i%7==0)
				System.out.printf("\n");
		}
                System.out.printf("\n");
	}
        
        private static boolean isLeap(int year){
            if((year % 4 == 0 &&
                year % 100 !=0 ) ||
                year % 400 == 0)
                return true;
            return false;
        }
}

