#include <ESPNOW_Rimocon.h>

#pragma pack(push, 1)
struct Controller{
  static constexpr uint8_t num = 2;
  bool state[num];
};
#pragma pack(pop)

ESPnowRimocon<Controller> rimocon;

void setup(){
  Serial.begin(115200);

  if(!rimocon.init())return;

  pinMode(2,OUTPUT);
  pinMode(17,OUTPUT);
  pinMode(16,OUTPUT);
}

void loop(){
  digitalWrite(2,rimocon.receive_new);
  if(rimocon.receive_new){
    rimocon.receive_new = false;
    //Serial.println(rimocon.received.num);
    //digitalWrite(17, rimocon.received.left);
    //digitalWrite(16, rimocon.received.right);
    digitalWrite(17, rimocon.received.state[0]);
    digitalWrite(16, rimocon.received.state[1]);
  }
}
