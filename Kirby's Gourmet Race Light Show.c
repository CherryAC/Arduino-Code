//LIGHT SHOW TO “KIRBY’S GOURMET RACE” SONG
//play this video https://www.youtube.com/watch?v=3w4B16TRsPM after the third beep sounds to sync the lights and music
//light show stops at 1:04
int red1=2, red2=11, green1=3, green2=10, blue1=4, blue2=9, yellow1=5, yellow2=8;

int buzzerPin=7;

int counter;

int i;

int Lights[]={red1, red2, green1, green2, blue1, blue2, yellow1, yellow2};
int Lights2[]={red1, green1, blue1, yellow1, yellow2, blue2, green2, red2};

void setup(){
  for(i=0;i<=7;i++){
    pinMode(Lights[i],OUTPUT);
  }
  int duration=250;
  tone(buzzerPin, 300, duration);
  delay(1000);
  tone(buzzerPin, 300, duration);
  delay(1000);
  tone(buzzerPin, 300, duration);
  delay(1000);
  Intro();
  Chorus();
  Chorus2();
  Chorus3();
  Chorus4();
  Chorus5();
  Chorus6();
  Chorus7();
  Chorus8();
  Chorus9();
  Chorus10();
}

void loop(){
  
}

void Intro(){
  //All lights on at same time for first note
  for(i=0;i<=7;i++){
    digitalWrite(Lights[i],HIGH);
  }
  delay(323);
  //First eighth note run (measure 1)
  for(i=0;i<=4;i++){
    digitalWrite(Lights[i],LOW);
    delay(152);
  }
  delay(161);
  //Second eighth note run (measure 2)
  for(i=4;i<=7;i++){
    digitalWrite(Lights[i],LOW);
    delay(152);
  }
  //High eighth (second to last note of measure 2)
  for(i=7;i>=0;i=i-2){
    digitalWrite(Lights[i],HIGH);
    digitalWrite(Lights[i-1],HIGH);
    delay(35.5);
  }
  //Low half (last note of measure 2)
  for(i=7;i>=0;i=i-2){
    digitalWrite(Lights[i],LOW);
    digitalWrite(Lights[i-1],LOW);
    delay(35.5);
  }
  delay(611);
}

void Chorus(){
  //First chord (first half of measure 3)
  for(i=0;i<=7;i++){
    digitalWrite(Lights[i],HIGH);
  }
  delay(646);
  //Second chord (second half of measure 3)
  digitalWrite(red1,LOW);
  digitalWrite(red2,LOW);
  delay(400);
  //First chord run (measure 4)
  for(i=0;i<=7;i=i+2){
    digitalWrite(Lights[i],LOW);
    digitalWrite(Lights[i+1],LOW);
    delay(323);
  }
  delay(323);
  //Random chord run (measure 5-6)
  digitalWrite(red1,HIGH);
  delay(275);
  digitalWrite(yellow2,HIGH);
  delay(323);
  digitalWrite(blue1,HIGH);
  delay(323);
  digitalWrite(green2,HIGH);
  delay(323);
  digitalWrite(green1,HIGH);
  delay(323);
  digitalWrite(blue2,HIGH);
  delay(323);
  digitalWrite(yellow1,HIGH);
  delay(323);
  digitalWrite(red2,HIGH);
  delay(323);
  //First chord rep. (first half of measure 7)
  for(i=0;i<=7;i++){
    digitalWrite(Lights[i],LOW);
  }
  delay(646);
  //Second chord rep. (second half of measure 7)
  digitalWrite(red1,HIGH);
  digitalWrite(red2,HIGH);
  delay(400);
  //First chord run
  for(i=0;i<=7;i=i+2){
    digitalWrite(Lights[i],HIGH);
    digitalWrite(Lights[i+1],HIGH);
    delay(250);
  }
  //repeating light flash, after chord repeat (
  for(counter=0;counter<=4;counter++){
    for(i=7;i>=0;i=i-2){
      digitalWrite(Lights[i],HIGH);
      digitalWrite(Lights[i-1],HIGH);
      delay(70);
    }
    for(i=7;i>=0;i=i-2){
      digitalWrite(Lights[i],LOW);
      digitalWrite(Lights[i-1],LOW);
      delay(70);
    }
  }
  delay(50);
}

void Chorus2(){
  digitalWrite(red1,HIGH);
  digitalWrite(green1,HIGH);
  delay(646);
  digitalWrite(blue1,HIGH);
  digitalWrite(yellow1,HIGH);
  delay(646);
  digitalWrite(yellow2,HIGH);
  delay(323);
  digitalWrite(blue2,HIGH);
  delay(323);
  digitalWrite(green2,HIGH);
  digitalWrite(red2,HIGH);
  delay(646);
  for(i=7;i>=0;i--){
    digitalWrite(Lights2[i],LOW);
    delay(323);
  }
}

void Chorus3(){
  for(i=0;i<=7;i++){
    digitalWrite(Lights2[i],HIGH);
    delay(75);
    digitalWrite(Lights2[i],LOW);
  }
  for(i=7;i>=0;i--){
    digitalWrite(Lights2[i],HIGH);
    delay(75);
    digitalWrite(Lights2[i],LOW);
  }
}
void Chorus4(){
  for(i=7;i>=4;i--){
    digitalWrite(Lights2[i],HIGH);
    delay(75);
  }
  for(i=0;i<=3;i++){
    digitalWrite(Lights2[i],HIGH);
    delay(75);
  }
  delay(150);
  for(i=4;i<=7;i++){
    digitalWrite(Lights2[i],LOW);
    delay(75);
  }
  for(i=3;i>=0;i--){
    digitalWrite(Lights2[i],LOW);
    delay(75);
  }
  digitalWrite(blue1, HIGH);
  delay(323);
  digitalWrite(blue2, HIGH);
  delay(323);
  digitalWrite(blue1, LOW);
  delay(323);
  digitalWrite(blue2, LOW);
  delay(323);
  for(counter=0;counter<=7;counter++){
    for(i=0;i<=7;i++){
      digitalWrite(Lights[i], HIGH);
    }
    delay(75);
    for(i=0;i<=7;i++){
      digitalWrite(Lights[i], LOW);
    }
    delay(75);
  }
}
void Chorus5(){
  //Each half flashes twice
  for(counter=0;counter<=1;counter++){
    for(i=0;i<=3;i++){
      digitalWrite(Lights2[i], HIGH);
    }
    delay(270);
    for(i=0;i<=3;i++){
      digitalWrite(Lights2[i], LOW);
    }
    delay(53);
  }
  for(counter=0;counter<=1;counter++){
    for(i=7;i>=4;i--){
      digitalWrite(Lights2[i], HIGH);
    }
    delay(270);
    for(i=7;i>=4;i--){
      digitalWrite(Lights2[i], LOW);
    }
    delay(53);
  }
  //Descending hopscotch
  digitalWrite(red1,HIGH);
  digitalWrite(red2,HIGH);
  delay(323);
  digitalWrite(red1,LOW);
  digitalWrite(red2,LOW);
  digitalWrite(blue1,HIGH);
  digitalWrite(blue2,HIGH);
  delay(323);
  digitalWrite(blue1,LOW);
  digitalWrite(blue2,LOW);
  digitalWrite(green1,HIGH);
  digitalWrite(green2,HIGH);
  delay(323);
  digitalWrite(green1,LOW);
  digitalWrite(green2,LOW);
  digitalWrite(yellow1,HIGH);
  digitalWrite(yellow2,HIGH);
  delay(323);
  digitalWrite(yellow1,LOW);
  digitalWrite(yellow2,LOW);
  //Ascending hopscotch
  delay(50);
  digitalWrite(yellow1,HIGH);
  digitalWrite(yellow2,HIGH);
  delay(323);
  digitalWrite(yellow1,LOW);
  digitalWrite(yellow2,LOW);
  digitalWrite(green1,HIGH);
  digitalWrite(green2,HIGH);
  delay(323);
  digitalWrite(green1,LOW);
  digitalWrite(green2,LOW);
  digitalWrite(blue1,HIGH);
  digitalWrite(blue2,HIGH);
  delay(323);
  digitalWrite(blue1,LOW);
  digitalWrite(blue2,LOW);
  digitalWrite(red1,HIGH);
  digitalWrite(red2,HIGH);
  delay(323);
  digitalWrite(red1,LOW);
  digitalWrite(red2,LOW);
  //Ascending notes - measure 22
  digitalWrite(red1, HIGH);
  digitalWrite(red2, HIGH);
  digitalWrite(green1, HIGH);
  digitalWrite(green2, HIGH);
  delay(323);
  digitalWrite(blue1, HIGH);
  digitalWrite(blue2, HIGH);
  digitalWrite(yellow1, HIGH);
  digitalWrite(yellow2, HIGH);
  delay(323);
  //repeating light flash on half note
  for(counter=0; counter<=6; counter++){
    for(i=0;i<=7;i++){
      digitalWrite(Lights[i],LOW);
    }
    delay(50);
    for(i=0;i<=7;i++){
      digitalWrite(Lights[i],HIGH);
    }
    delay(50);
  }
}

void Chorus6(){
  //for the first part of the fast-paced flute part, have the lights burst in 
  for(counter=0; counter<=17; counter++){
    for(i=0;i<=7;i=i+2){
    digitalWrite(Lights[i],HIGH);
    digitalWrite(Lights[i+1],HIGH);
    delay(36);
    digitalWrite(Lights[i],LOW);
    digitalWrite(Lights[i+1],LOW);
    delay(36);
    }
  }
}

//the lights turn on in a random sequence starting at measure 26
void Chorus7(){
  for(counter=0; counter<=1; counter++){
    digitalWrite(green1, HIGH);
    delay(270);
    digitalWrite(green1, LOW);
    delay(53);
    //an LED is added
    digitalWrite(green1, HIGH);
    digitalWrite(yellow2, HIGH);
    delay(270);
    digitalWrite(green1, LOW);
    digitalWrite(yellow2, HIGH);
    delay(53);
    //an LED is added
    digitalWrite(green1, HIGH);
    digitalWrite(yellow2, HIGH);
    digitalWrite(red2, HIGH);
    delay(270);
    digitalWrite(green1, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(red2, LOW);
    delay(53);
    //an LED is added
    digitalWrite(green1, HIGH);
    digitalWrite(yellow2, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(blue2, HIGH);
    delay(270);
    digitalWrite(green1, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(blue2, LOW);
    delay(53);
    //an LED is added
    digitalWrite(green1, HIGH);
    digitalWrite(yellow2, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(blue2, HIGH);
    digitalWrite(blue1, HIGH);
    delay(270);
    //an LED is added
    digitalWrite(green1, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(blue2, LOW);
    digitalWrite(blue1, LOW);
    delay(53);
    //another LED is added
    digitalWrite(green1, HIGH);
    digitalWrite(yellow2, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(blue2, HIGH);
    digitalWrite(blue1, HIGH);
    digitalWrite(green2, HIGH);
    delay(270);
    digitalWrite(green1, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(blue2, LOW);
    digitalWrite(blue1, LOW);
    digitalWrite(green2, LOW);
    delay(53);
    //another LED added
    digitalWrite(green1, HIGH);
    digitalWrite(yellow2, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(blue2, HIGH);
    digitalWrite(blue1, HIGH);
    digitalWrite(green2, HIGH);
    digitalWrite(red1, HIGH);
    delay(270);
    digitalWrite(green1, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(blue2, LOW);
    digitalWrite(blue1, LOW);
    digitalWrite(green2, LOW);
    digitalWrite(red1, LOW);
    delay(53);
    //last LED added
    digitalWrite(green1, HIGH);
    digitalWrite(yellow2, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(blue2, HIGH);
    digitalWrite(blue1, HIGH);
    digitalWrite(green2, HIGH);
    digitalWrite(red1, HIGH);
    digitalWrite(yellow1, HIGH);
    delay(270);
    digitalWrite(green1, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(blue2, LOW);
    digitalWrite(blue1, LOW);
    digitalWrite(green2, LOW);
    digitalWrite(red1, LOW);
    digitalWrite(yellow1, LOW);
    delay(53);
  }
}

//perfect the timing on these sections 

void Chorus8(){
  //lights ping pong across - needs to run for 2,585 milliseconds
  for(counter=0; counter<=2; counter++){
    for(i=0; i<=7; i++){
      digitalWrite(Lights2[i], HIGH);
      delay(38.5);
    }
    for(i=0; i<=7; i++){
      digitalWrite(Lights2[i], LOW);
    }
    delay(35.5);
    for(i=7; i>=0; i--){
      digitalWrite(Lights2[i], HIGH);
      delay(38.5);
    }
    for(i=7; i>=0; i--){
      digitalWrite(Lights2[i], LOW);
    }
    delay(36);
  }
}

void Chorus9(){
  for(counter=0;counter<=14;counter++){
    for(i=7;i>=0;i--){
      digitalWrite(Lights2[i],HIGH);
    }
    delay(70);
    for(i=7;i>=0;i--){
      digitalWrite(Lights2[i],LOW);
    }
    delay(50);
  }
  for(i=7; i>=0; i--){
    digitalWrite(Lights2[i], HIGH);
  }
  delay(646);
}

//TEMPO CHANGE TO 189 BPM

void Chorus10(){
  delay(323);
  for(i=0; i<=7; i++){
    digitalWrite(Lights2[i], HIGH);
  }
  delay(280);
  //lights ping across and back very fast
  for(counter=0; counter<=15; counter++){
    for(i=0; i<=7; i++){
      digitalWrite(Lights2[i], HIGH);
      delay(36);
    }
    delay(21);
    for(i=7; i>=0; i--){
      digitalWrite(Lights2[i], LOW);
      delay(35);
    }
    delay(20);
  }
  for(counter=0; counter<=12; counter++){
    for(i=7; i>=0; i--){
      digitalWrite(Lights2[i], HIGH);
      delay(35);
    }
    delay(20);
    for(i=0; i<=7; i++){
      digitalWrite(Lights2[i], LOW);
      delay(35);
    }
    delay(20);
    }
    for(counter=0;counter<=4;counter++){
      digitalWrite(red1, HIGH);
      digitalWrite(green1, HIGH);
      digitalWrite(blue1, HIGH);
      digitalWrite(yellow1, HIGH);
      delay(125);
      digitalWrite(red1, LOW);
      digitalWrite(green1, LOW);
      digitalWrite(blue1, LOW);
      digitalWrite(yellow1, LOW);
      delay(75);
      digitalWrite(red2, HIGH);
      digitalWrite(green2, HIGH);
      digitalWrite(blue2, HIGH);
      digitalWrite(yellow2, HIGH);
      delay(125);
      digitalWrite(red2, LOW);
      digitalWrite(green2, LOW);
      digitalWrite(blue2, LOW);
      digitalWrite(yellow2, LOW);
      delay(75);
    }
    //lights flash on for the last note 
    for(i=7;i>=0;i--){
      digitalWrite(Lights2[i],HIGH);
    }
    delay(250);
    for(i=7;i>=0;i--){
      digitalWrite(Lights2[i],LOW);
    }
    delay(50);
}

  
  


