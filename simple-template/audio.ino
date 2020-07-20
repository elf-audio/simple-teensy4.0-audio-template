
#include <Audio.h>

#include <SD.h>



class MyOutput : public AudioStream {
public:
  MyOutput() : AudioStream(0, NULL) {}




  
  virtual void update(void){
    audio_block_t *blockL = allocate();
    audio_block_t *blockR = allocate();
    if(blockL && blockR) { 
      for (int i=0; i < AUDIO_BLOCK_SAMPLES; i++) {
        blockR->data[i] = blockL->data[i] = getSample() * 32767.f;
      }
    }
    transmit(blockL, 0);
    transmit(blockL, 1);
    release(blockL);
    release(blockR);
  }
};


// GUItool: begin automatically generated code
MyOutput       myOutput;      //xy=158,759
AudioOutputMQS           mqs;            //xy=374,758
AudioConnection          patchCord1(myOutput, 0, mqs, 0);
AudioConnection          patchCord2(myOutput, 0, mqs, 1);
// GUItool: end automatically generated code
