#include <LiquidCrystal.h>

//7 tone keyboard program by Nathan Bhak and Chris Ye

//sets pins for LCD display
LiquidCrystal lcd(13,12,11,10,9,8);

//sets pins for each button
const int buttons[7] = {A5,A4,A3,A2,A1,A0,3};
//sets pin for speaker
const int speaker = 2;

//array of pitches
const char pitches[7] = {'B','A','G','F','E','D','C'};
//array of frequencies
const int tones[7] = {494,440,392,349,330,294,262};

//represents the pitch
int noteTone = 0;

void playNote(int x){
      
      //displays the note
      lcd.print(pitches[x]);

      //sets the pitch to the note represented by the button pressed
      noteTone = tones[x];

      //plays the note with the correct frequency
      tone(speaker,noteTone);
  
}

void setup() {

  //number of columns and rows being used on the display
  lcd.begin(16,2);

  //sets all buttons as input devices
  for(int i=0; i<=6; i++){
    pinMode(buttons[i],INPUT_PULLUP);
  }

  //sets the speaker as an output device
  pinMode(speaker, OUTPUT);

}

void loop() {
  
    //sets the location of the text on the display
    lcd.setCursor(0,0);
    
    if(! digitalRead(buttons[0])){
      playNote(0);
    }
 
    else if(! digitalRead(buttons[1])){
      playNote(1);
    }

    else if(! digitalRead(buttons[2])){
      playNote(2);
    }

    else if(! digitalRead(buttons[3])){
      playNote(3);
    }

    else if(! digitalRead(buttons[4])){
      playNote(4);
    }
 
    else if(! digitalRead(buttons[5])){
      playNote(5);
    }

    else if(! digitalRead(buttons[6])){
      playNote(6);
    }

    else if(! digitalRead(buttons[7])){
      playNote(7);
    }
    
    else{
      //if no button is pressed, then turn off the speaker
      noTone(speaker);
    }

}
