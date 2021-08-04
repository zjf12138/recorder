#include "DFRobot_VoiceRecorder.h"

#define I2C_ADDRESS  (0x30)
DFRobot_VoiceRecorder_I2C voicerecorder(&Wire, I2C_ADDRESS);

uint8_t buttonPin=D9; 
bool playing=false;

void setup() {
  pinMode(buttonPin,INPUT);
  Serial.begin(115200);
  while (voicerecorder.begin() != 0)
  {
    Serial.println("i2c device number error!");
    delay(1000);
  }
  Serial.println("i2c connect success!");
}

void loop() {
if((digitalRead(buttonPin)==HIGH)&&(playing==false))//按下按钮的时候
{
  voicerecorder.setVoiceNumber(VOICE_NUMBER_2);//选择二号音频
  voicerecorder.deleteVoice();//删除音频
  Serial.println("删除");
  Serial.println("录音开始");
  voicerecorder.recordvoiceStart();
  for (int8_t n = 20; n > 0; n--)
  {
    Serial.println(n);
    delay(1000);
  }
  voicerecorder.recordVoiceEnd();//结束录音
  Serial.println("录音结束");
  playing=true;
  }
else if((digitalRead(buttonPin)==LOW)&&(playing==true)){//松开按钮
  voicerecorder.playVoiceStart();//开始播放
  Serial.println("开始播放");
  for (int8_t n = 22; n > 0; n--)
  {
    Serial.println(n);
    delay(1000);
  }
  playing=false;
  }
}
