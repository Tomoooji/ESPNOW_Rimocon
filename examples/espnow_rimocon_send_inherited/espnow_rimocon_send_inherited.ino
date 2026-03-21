#include <ESPNOW_Rimocon.h>

constexpr uint8_t receiverAddress[] = {0x68,0x25,0xdd,0x32,0x12,0x50};//{0x80, 0xf3, 0xda, 0x41, 0x47, 0xe8};//

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
}
