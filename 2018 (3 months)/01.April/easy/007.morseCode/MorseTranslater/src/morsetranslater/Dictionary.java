package morsetranslater;

import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.LinkOption;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Dictionary {
    private Map <String, String> dictionary;
    
    public Dictionary(){
        dictionary = new HashMap <String, String>();
        
        loadDictionary();
    }
    
    public Map<String, String> getTranslation(){
        return dictionary;
    }
    
    private void loadDictionary(){
        Path p = FileSystems.getDefault().getPath(System.getProperty("user.dir").toString()+"/abecedarium.txt");
        List<String> lines = new ArrayList<>();
        
        if(!Files.exists(p,LinkOption.NOFOLLOW_LINKS)){
            System.out.println("File " + p.getFileName()+" does not exists. ");
            return;
        }
        
        try{
            lines = Files.readAllLines(p, Charset.defaultCharset());
            String [] key_value;
            for(String line : lines){
                key_value = line.split(" ");
                dictionary.put(key_value[0], key_value[1]);
            }
        } catch (IOException e){
            System.out.println("Couldn't access to file. ");
            return;
        }
    }
    
    public String translate(String sentence){
        String translatedSentence = "";

        for(int i = 0; i< sentence.length(); i++){
            String ch = (sentence.charAt(i)+"").toUpperCase();
            if(ch.equals(" ")){
                translatedSentence += "/";
            } else {
                translatedSentence += (String) dictionary.get(ch);
                translatedSentence += " ";
            }
        }
        
        return translatedSentence;
    }
}
