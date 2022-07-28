#include <Keypad.h>
#include <LiquidCrystal.h>

const byte ROWS = 4;
const byte COLS = 3; 
char keys[ROWS][COLS] = {
  {'A','B','C'},
  {'D','E','F'},
  {'G','H','I'},
  {'N','K','J'}
};
byte rowPins[ROWS] = {10, 9, 8, 7}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {13, 12, 11}; //connect to the column pinouts of the keypad

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
char password[] = {'H','I','N','D'};
int i = 0;
int j = 0;
void setup(){
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Enter password");
  Serial.println("Enter password");
  lcd.setCursor(1,2);
}
  
void loop(){
  char keyPressed = keypad.getKey();
  char input [sizeof(password)];
  if (keyPressed){
    Serial.print(keyPressed);
    lcd.print(keyPressed);
    input[i]= keyPressed;
    i++;
  }
  if ( i == 4){
    for ( j =0;j<4;j++){
      
      if (password[j] != input[j]) {
        lcd.clear();
        lcd.setCursor(1,2);
        lcd.write("wrong password");
        Serial.println();
        Serial.println("wrong password");
        delay(1000);
  lcd.begin(16, 2);
  lcd.print("Enter password");
  Serial.println("Enter password");
  lcd.setCursor(1,2);
    i=0;
        break;
        }
        if(password[j] == input[j]) {
          lcd.clear();
        lcd.setCursor(1,2);
        Serial.println();
        lcd.write("correct password");
        Serial.println("correct password");
        i=0;}
  }
  }

  
}
