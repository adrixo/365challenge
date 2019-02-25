#include <iostream>
#include <string>
//http://www.cplusplus.com/reference/string/string/
using namespace std;

void divide(string inputSentence);

int main() {
  string inputSentence;

  cout << "Enter a sentence: ";
  getline(cin, inputSentence);

  divide(inputSentence);
}

void divide(string inputSentence){
  string firstSentence, secondSentence;
  int splitPosition;

  splitPosition = inputSentence.find_first_of(";,.!?");

  //http://www.cplusplus.com/reference/string/string/substr/
  firstSentence = inputSentence.substr(0,splitPosition);
  secondSentence = inputSentence.substr(splitPosition+1, inputSentence.length());

  if(firstSentence.length() < secondSentence.length())
    cout << firstSentence.length << ": " << firstSentence;
  else
    cout << secondSentence.length << ": " << secondSentence;
}
