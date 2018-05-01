
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.LinkOption;
import java.nio.file.Path;
import java.nio.charset.Charset;

import java.util.concurrent.ThreadLocalRandom;

public class HangmanMainWindow extends JFrame
{
	private JPanel HangmanDrawPanel;
	private JPanel TextInputPanel;
	private JSplitPane mainPanel;
	private JLabel topLabel;
	private JLabel bottomLabel;

	private JTextField letterInput = new JTextField(2);

	static private List<String> words;

	static String word;		// word to discover
	static String unkownWord; // word being discover
	static String oldLetters = "";
	static String usedLetters = "     ";

	static int lives = 10;
	static int hits = 0;
	public static void main(String[] args) {

		importWords("english");
		new HangmanMainWindow();

	}

	public HangmanMainWindow() {

		this.setTitle("Hangman 0.1");
		this.setSize(600,500);
		this.setResizable(false);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);

	//top panel
		createHangmanPanel();
	//bottom panel
		createTextInputPanel();

	//insert ^ panels into a splitted one
		mainPanel = new JSplitPane( JSplitPane.VERTICAL_SPLIT );
		mainPanel.setTopComponent( HangmanDrawPanel );
		mainPanel.setBottomComponent( TextInputPanel );
		mainPanel.setDividerSize(1);
		mainPanel.setEnabled( false );

		this.add(mainPanel);

	}

//
//	top
//
	private void createHangmanPanel(){
		HangmanDrawPanel = new JPanel();
		//JLabel topLabel = new JLabel("Hangman:");
		HangmanDrawPanel.setMinimumSize( new Dimension( 600, 300 ) );
		//HangmanDrawPanel.add(topLabel);
	}

//
//	bottom
//
	private void createTextInputPanel(){
	//content
		TextInputPanel = new JPanel(new BorderLayout());
		JLabel botLabel = new JLabel("    Play:");
		TextInputPanel.add(botLabel, BorderLayout.WEST);

		//taking the random word
		int randomNum = ThreadLocalRandom.current().nextInt(0, words.size()-1);
		word = words.get(randomNum);

		//Text input to write
		letterInput.addActionListener( new letterPress());

		TextInputPanel.add(letterInput, BorderLayout.CENTER);

		//Top info
		unkownWord = inicializeUnkownWord(word);

		topLabel = new JLabel(unkownWord, SwingConstants.CENTER);
		bottomLabel = new JLabel( usedLetters);

		TextInputPanel.add(topLabel, BorderLayout.NORTH);
		TextInputPanel.add(bottomLabel, BorderLayout.SOUTH);
	}


//
//	Complementary methods
//
//
//	text action
	class letterPress implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			topLabel.setText(tryLetter(letterInput.getText()));
			letterInput.setText("");
			bottomLabel.setText(usedLetters);
		}
	}

// game's firs call
	static private String inicializeUnkownWord(String word){
		String unkownWord = "Lives " + String.valueOf(lives) + ": ";

		for(int i=0; i < word.length(); i++){
			unkownWord = unkownWord + " - " ;
		}

		return unkownWord;
	}



// representation after input
	static private String tryLetter(String letter){

		String auxWord = "";
		Boolean error = true;

		for(int i=0; i < word.length() ; i++){
			if(letter.charAt(0) == word.charAt(i)){
				addToOld(letter.charAt(0));		
				auxWord = auxWord + " " + letter + " ";
				error = false;
				hits ++;
			} else {
				if( isOld(word.charAt(i)) ){
					auxWord = auxWord + " "+ word.charAt(i) +" ";
				} else {
					addToUsed(letter.charAt(0));
					auxWord = auxWord + " - ";
				}
			}
		}
	
		if(error){
			if(isUsed(letter.charAt(0))){
				lives--;
			}
		}
		error = true;

		unkownWord = "Lives " + String.valueOf(lives) + ": " + auxWord;

		if(hits >= word.length()){
			unkownWord = "Winner - " + word;
		} else if(lives <= 0){
			unkownWord = "Loser - " + word;
		}
		return unkownWord;
	}

//add to tried words
	static private void addToOld(char letter){
		Boolean exists = false;

		for(int i=0; i < oldLetters.length(); i++){
			if(letter == oldLetters.charAt(i)){
				exists = true;
				break;
			}
		}

		if(!exists)
			oldLetters = oldLetters + letter;
	}

//chekc if the letter was tried
	static private Boolean isOld(char letter){
		Boolean exists = false;

		for(int i=0; i < oldLetters.length(); i++){
			if(letter == oldLetters.charAt(i)){
				exists = true;
				break;
			}
		}

		return exists;
	}

	static private void addToUsed(char letter){
		Boolean exists = false;

		for(int i=0; i < usedLetters.length(); i++){
			if(letter == usedLetters.charAt(i)){
				exists = true;
				break;
			}
		}

		if(!exists)
			usedLetters = usedLetters + letter;
	}

	static private Boolean isUsed(char letter){
		Boolean exists = false;

		for(int i=0; i < usedLetters.length()-2; i++){
			if(letter == usedLetters.charAt(i)){
				exists = true;
				break;
			}
		}

		return exists;
	}

//Word array inicialization from assets/*.txt file
	static private void importWords(String languaje){

		switch(languaje){
				case "english":
					languaje = "english.txt";
					break;
				case "spanish":
					languaje = "spanish.txt";
					break;
				default:
					languaje = "english.txt";
		}
		words = new ArrayList<>();

		//geting current directory + word file
		String spath = System.getProperty("user.dir") + File.separator + "assets" + File.separator + languaje;

		if(spath==null){
			return;
		}
        Path path = FileSystems.getDefault().getPath(spath);

		
		if(!Files.exists(path,LinkOption.NOFOLLOW_LINKS)){
			System.out.println("The file " + path.getFileName() + "Doesn't exist.");
		}

		try {
			words = Files.readAllLines(path, Charset.defaultCharset());
		} catch (IOException e) {
            System.out.println("Error: reading words file. ");
            return;
		}
		return;
	}
}
