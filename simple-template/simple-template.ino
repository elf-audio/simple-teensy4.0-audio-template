

#include <Audio.h>
#include <SD.h>


void setup() {
  AudioMemory(4);
}



///////////////
// CODE GOES HERE
float getSample() { 
    return (random() %10000)/10000.f;
}



void loop() {
  delay(100);
   // read inputs here
   // and send them to audio code
}
