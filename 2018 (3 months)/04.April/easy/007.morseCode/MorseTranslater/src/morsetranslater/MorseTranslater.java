package morsetranslater;

import java.util.Scanner;
import morsetranslater.Dictionary;

public class MorseTranslater {

    public static void main(String[] args) {
        Dictionary d = new Dictionary();
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Wellcome to morse translater. Write a sentence. \007");
        String sentence = sc.nextLine();
        
        sentence = d.translate(sentence);
        System.out.println("Translated: "+sentence);
    }
    
}
