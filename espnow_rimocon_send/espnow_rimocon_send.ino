#include "Rimocon_ESPNOW.h"

constexpr uint8_t receiverAddress[] = {0x68,0x25,0xdd,0x32,0x12,0x50};//{0x80, 0xf3, 0xda, 0x41, 0x47, 0xe8};//

/*
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
  if(!rimocon.init())return;//receiverAddressはinitで渡してもok
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

//*/
#pragma pack(push, 1)
struct Controller{
  static constexpr uint8_t num = 2;
  bool state[num];
};
#pragma pack(pop)

constexpr uint8_t pins[] = {19,21};

class myRimocon: public ESPnowRimocon<Controller>{
 public:
  const uint8_t num_button = Controller::num;
  const uint8_t* const pins_button;

  myRimocon(const uint8_t* PinforButtons, const uint8_t* address = nullptr):
    ESPnowRimocon<Controller>(address), pins_button(PinforButtons)
  {}
  
  bool begin(const uint8_t* address = nullptr)override{
    if(!this->init(address))return false;
    for(int i=0; i<this->num_button; i++){
      pinMode(this->pins_button[i], INPUT_PULLUP);
    }
    return true;
  }

  void update()override{
    for(int i=0; i<this->num_button; i++){
      this->sending.state[i] = !digitalRead(this->pins_button[i]);
    }
    this->send();
  }
} rimocon(pins,receiverAddress);

void setup(){
  rimocon.begin();
}
void loop(){
  rimocon.update();
  delay(1);
}

//*/