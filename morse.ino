#include <LiquidCrystal.h>
 
int dotButtonPin = 10;
int dashButtonPin = 9;
int enter = 8;
int spaceBar = 7;

int ledPin = 13;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);;

String morseBuffer = "";
String translatedText = "";

void setup() {
  pinMode(dotButtonPin, INPUT_PULLUP);
  pinMode(dashButtonPin, INPUT_PULLUP);
  pinMode(spaceBar, INPUT_PULLUP);
  pinMode(enter, INPUT_PULLUP);

  pinMode(ledPin, OUTPUT);

  lcd.begin(16, 2);
  //lcd.print("Morse to Text:");
}

void loop() {
  if (digitalRead(dotButtonPin) == LOW) {
    addToBuffer(".");
    delay(200); // Debouncing delay
  }

  if (digitalRead(dashButtonPin) == LOW) {
    addToBuffer("-");
    delay(200); // Debouncing delay
  }

 
  /*if (digitalRead(spaceBar) == 1) {
    addToBuffer(" ");
    delay(200); // Debouncing delay
  }*/


  if (digitalRead(enter) == LOW) {
    if (morseBuffer.length() > 0) {
      translateAndDisplay();
      morseBuffer = "";
    }
    delay(1000); // Longer delay for word separation
  }
}

void addToBuffer(String symbol) {
  morseBuffer += symbol;
  lcd.setCursor(0, 1);
  lcd.print(morseBuffer);
}

void translateAndDisplay() {
  char translatedChar = morseToChar(morseBuffer);
  translatedText += translatedChar;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Morse to Text:");
  lcd.setCursor(0, 1);
  lcd.print(translatedText);
}
char morseToChar(String morse) {
  // Morse to English mapping using if statements
  //if (digitalRead(spaceBar) == LOW) return ' ';
  if (morse == ".-") return 'A';
  else if (morse == "-...") return 'B';
  else if (morse == "-.-.") return 'C';
  else if (morse == "-..") return 'D';
  else if (morse == ".") return 'E';
  else if (morse == "..-.") return 'F';
  else if (morse == "--.") return 'G';
  else if (morse == "....") return 'H';
  else if (morse == "..") return 'I';
  else if (morse == ".---") return 'J';
  else if (morse == "-.-") return 'K';
  else if (morse == ".-..") return 'L';
  else if (morse == "--") return 'M';
  else if (morse == "-.") return 'N';
  else if (morse == "---") return 'O';
  else if (morse == ".--.") return 'P';
  else if (morse == "--.-") return 'Q';
  else if (morse == ".-.") return 'R';
  else if (morse == "...") return 'S';
  else if (morse == "-") return 'T';
  else if (morse == "..-") return 'U';
  else if (morse == "...-") return 'V';
  else if (morse == ".--") return 'W';
  else if (morse == "-..-") return 'X';
  else if (morse == "-.--") return 'Y';
  else if (morse == "--..") return 'Z';
  else return '?'; // Character not recognized
}