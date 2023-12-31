//Interfacing EM-18 RFID READER MODULE with STM32F103C8

//Circuit Digest

#include <LiquidCrystal.h>                                               //Library for using LCD display functions

const int rs = B11, en = PB10, d4 = PB0, d5 = PB1, d6 = PC13, d7 = PC14; //mention the pin names to with LCD is connected to STM32F103C8

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);                                //Initialize the LCD display

int count = 0;          

char RFID[12];                                                             //Arrary for storing 12 characters of ID

 

 

void setup()

{

lcd.begin(16, 2);                  // setting LCD as 16x2 type

Serial.begin(9600);               //begins serial communication at 9600 baud rate

pinMode(PA10,INPUT);               //Set PA10 as input pin from EM-18

lcd.print("CIRCUIT DIGEST");       //Prints at LCD display

lcd.setCursor(0, 1);               //Set courser to second line

lcd.print("RFID WITH STM32");      //Prints at LCD display

delay(5000);                       //Delay for 5 Seconds

 lcd.clear();                       //Clears LCD display

 lcd.setCursor(0,0);                //Sets cursor at First Line

 lcd.print("RFID TAG NO:");         //Prints at LCD display

 lcd.setCursor(0,1);                //Sets cursor at Second line

}

 

 

void loop()

{    

while(Serial.available() && count < 12)          // While loop to read 12 characters and store them in input array

{

RFID[count] = Serial.read();                  //storing 12 characters one by one

    count++;

    lcd.print(RFID[count]);                         //showing 12 characters on LCD one by one

 

if (count==12)

    {

lcd.print("             ");

count = 0;                          // once 12 characters are read get to start and wait for second ID

lcd.setCursor(0, 1);                //move courser to start.

}

}

}              
