//external library required for programming lcd display
#include <LiquidCrystal.h>

//7 tone keyboard program by Nathan Bhak and Chris Ye

//sets pins for LCD display
LiquidCrystal lcd(13,12,11,10,9,8);

//sets pins for each button
const int buttons[] = {A5,A4,A3,A2,A1,A0,3};
const int octButtons[] = {4,5};
//sets pin for speaker
const int speaker = 2;

//array of pitches
const char pitches[] = {'B','A','G','F','E','D','C'};
//array of frequencies
const int tones[] = {494,440,392,349,330,294,262};
const int lowTones[] = {247,220,196,175,165,147,131};

//represents the pitch
int noteTone = 0;

//represents current octave
int octave = 2;


//function
void playNote(int x, int oct){
      
      //displays the note being played
      lcd.print(pitches[x]);

      
      if(oct == 1){
        //sets the pitch to the note represented by the button pressed
        noteTone = tones[x];
      }

      else if(oct == 2){
        //sets the pitch to the note represented by the button pressed
        noteTone = lowTones[x];
      }

      //plays the note with the correct frequency
      tone(speaker,noteTone);
  
}

void setup() {

  //number of columns and rows that can used on the display
  lcd.begin(16,2);

  //sets buttons as input devices
  for(int i=0; i<=6; i++){
    pinMode(buttons[i],INPUT);
  }

  for(int i=0; i<=1; i++){
    pinMode(octButtons[i],INPUT);
  }

  //sets the speaker as an output device
  pinMode(speaker, OUTPUT);

}

void loop() {
    
    //switches to higher octave if relevant button is pressed
    if(! digitalRead(octButtons[0])){
      octave = 1;
    }
    
    //switches to lower octave if relevant button is pressed
    else if(! digitalRead(octButtons[1])){
      octave = 2;
    }
  
    //sets the location of the text on the display
    lcd.setCursor(0,0);
    
      
    //runs function to play note when relevant button is pressed
      
    if(! digitalRead(buttons[0])){
      playNote(0,octave);
    }
 
    else if(! digitalRead(buttons[1])){
      playNote(1,octave);
    }

    else if(! digitalRead(buttons[2])){
      playNote(2,octave);
    }

    else if(! digitalRead(buttons[3])){
      playNote(3,octave);
    }

    else if(! digitalRead(buttons[4])){
      playNote(4,octave);
    }
 
    else if(! digitalRead(buttons[5])){
      playNote(5,octave);
    }

    else if(! digitalRead(buttons[6])){
      playNote(6,octave);
    }
    
    else{
      //if no button is pressed, then turn off the speaker
      noTone(speaker);
    }

}
