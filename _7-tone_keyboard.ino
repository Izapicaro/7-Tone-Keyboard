//7 tone keyboard program by Nathan Bhak and Chris Ye

int buttons[] = {3,4,5,6,7,8,9];
int buttonStates[] = {0,0,0,0,0,0,0};
int speaker = 2;
int curTone = 0;

//array of pitches
const char pitches[] = {'C','D','E','F','G','A','B'};
//array of frequencies
const double freq[] = {130.81,146.83,164.81,174.61,196.00,220.00,246.94};

void toneFunc(button,buttonstate,frequency) {
  if (buttonState == HIGH){
    curTone = freq[button] 
  }
}

void setup() {
  
  for(int i=0; i<=6; i++){
    pinMode(buttons[i],INPUT);
  }

  pinMode(speaker, OUTPUT);

}

void loop() {

  for(int i=0; i<=6; i++){
    buttonsStates[i]=digitalRead(buttonsStates[i]);
  }

}
