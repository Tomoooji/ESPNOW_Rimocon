#include <Rimocon_ESPNOW.h>

constexpr uint8_t receiverAddress[] = {0x68,0x25,0xdd,0x32,0x12,0x50};//{0x80, 0xf3, 0xda, 0x41, 0x47, 0xe8};//

#pragma pack(puch, 1)
struct message{
  bool left, right;
  int num;
};
#pragma pack(pop)

ESPnowRimocon<message> rimocon(receiverAddress);
//ESPnowRimocon<message> rimocon;


void setup(){
  Serial.begin(115200);
  if(!rimocon.init())return;
  //if(!rimocon.init(receiverAddress))return;
  pinMode(21, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
}

void loop(){
  rimocon.sending.left = !digitalRead(21);
  rimocon.sending.right = !digitalRead(19);
  rimocon.sending.num += rimocon.sending.num<100? 1: -100;

  rimocon.send();
  delay(1);
  
  if(rimocon.success_send){
    Serial.println(rimocon.sending.num);
  }else{
    Serial.println("....");
  }
}
