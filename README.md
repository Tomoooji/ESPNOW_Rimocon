# ESP32用ESP-NOWリモコン
自作リモコン基盤上のESP32とロボットに搭載したESP32の間でESP-NOWによるpeer to peer通信を行うためのライブラリです。  
**ESP32以外のESP系マイコンでの動作検証はしてないです。悪しからず。**

## ファイル構成
- src  
  * ESPNOW_Rimocon.h -ライブラリ本体(ESPNOWRimoconクラス)
- examples
  * espnow_rimicon_send -シンプルver(送信側)  
    espnow_rimicon_send.ino
  * espnow_rimicon_recv -シンプルver(受信側)  
    espnow_rimicon_recv.ino  
  * espnow_rimicon_send_inherited -応用ver(送信側)  
    espnow_rimicon_send_inherited.ino  
  * espnow_rimicon_recv_inherited -応用ver(受信側)  
    espnow_rimicon_recv_inherited.ino  
## ライブラリのインクルード
## 使い方
### シンプルver
### 応用ver