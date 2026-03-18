#include <Rimocon_ESPNOW.h>

#pragma pack(puch, 1)
struct message{
  bool left, right;
  int num;
};
#pragma pack(pop)
ESPnowRimocon<message> rimocon;

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
    Serial.println(rimocon.received.num);
    digitalWrite(17, rimocon.received.left);
    digitalWrite(16, rimocon.received.right);
  }
}
