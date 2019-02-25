package hamurabi;

import java.util.Random;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class Hamurabi {
  //Administrator of Summeria:
  private int bushels;
  private int acres;
  private int plantedAcres;

  private int feed;
  private int people;
  private int starvingPeople;

  private int year;
  private int price;

  public static void main(){

    Hamurabi hamurabi = new Hamurabi();

    hamurabi.startGame();
  }

  public Hamurabi(){
    this.acres = 1000;
    this.plantedAcres = 0;
    this.people = 100;
    this.bushels = 3000;
    this.year = 0;
  }

  static public void startGame(){
    Random random = new Random();
    while(this.year < 10){
      System.out.printf("Year: %d - People: %d - Starving: %d - bushels: %d - acres: %d\n", this.price, this.people, this.starvingPeople, this.bushels, this.acres);
      this.price = random.nextInt(9)+17;
      System.out.printf("This years price: %d\n", this.price);

      this.sellBushels();
      this.buyBushels();
      this.feedPeople();
      this.plant();

      this.randomEvent();
      this.passYear();
    }
  }

  static public void buyBushels(){
    System.out.print("How many bushels do you want to buy?: ");
    Scanner s = new Scanner(System.in);
    int number = s.nextInt();
    if((this.acres - number/this.price) < 0){
      System.out.print("Not enough acres.\n");
    } else {
      this.bushels += number;
      this.acres -= number/this.price;
    }
  }

  static public void sellBushels(){
    System.out.print("How many bushels do you want to sell?: ");
    Scanner s = new Scanner(System.in);
    int number = s.nextInt();
    if((this.bushels - number) < 0){
      System.out.print("Not enough bushels.\n");
    } else {
      this.bushels -= number;
      this.acres += bushels/this.price;
    }
  }

  static public void feedPeople(){
    System.out.print("How many bushels do you wana use to feed?: ");
    Scanner s = new Scanner(System.in);
    int number = s.nextInt();
    if((this.bushels - number) < 0){
      System.out.print("Not enough bushels.\n");
    } else {
      this.bushels -= number;
      this.feed += number;
    }
  }

  static public void plant(){
    System.out.print("How many acres do you wana plant?: ");
    Scanner s = new Scanner(System.in);
    int number = s.nextInt();
    if((this.acres - number) < 0){
      System.out.print("Not enough acres.\n");
    } else {
      this.bushels -= number;
      this.plantedAcres += number;
  }

  static public void randomEvent(){
    Random random = new Random();
    int possibilities;
    int cuantity;
    //rats
    possibilities = random.nextInt(20);
    if(possibilities == 10){
      cuantity = random.nextInt(5) + 15;
      cuantity = this.bashels / cuantity;
      this.bashels -= cuantity;
      System.out.printf("Rats ate %d bashels.\n ", cuantity);
    }
    //crops
    possibilities = random.nextInt(15);
    if(possibilities == 10){
      cuantity = random.nextInt(5) + 13;
      cuantity = this.plantedAcres / cuantity;
      this.plantedAcres -= cuantity;
      System.out.printf("%d crops are destroid.\n ", cuantity);
    }
  }

  static public void passYear(){
    //planted
    this.bushels += this.plantedAcres * 2;
    this.plantedAcres = 0;

    //people comes/leave
    int needs = this.people * 4 + this.starvingPeople * 2;
    needs -= this.feed;
    this.feed = 0;

    int peopleLeft = 0;
    if(this.need<0){
      peopleLeft = this.starvingPeople;
      System.out.printf("%d people left.\n", peopleLeft);
      this.starvingPeople = (-1)*needs/3;
    } else {
      this.starvingPeople = 0;
      this.people += needs/4;
      System.out.printf("%d people came.\n", needs/4);
    }

    //year pases
    this.year++;
  }
}
