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
## Arduino IDEへのインクルード
ここのフォルダを.zipでダウンロードして読み込むか、コードのフォルダがあるところにあるlibrariesフォルダにそのまま突っ込むかしてくださいな
## 使い方
### シンプルver
  1. やり取りしたいデータの型(多分配列は無理なので複数あるならstructを作る)をテンプレート引数にしてオブジェクトを作成(複数作るとバグるはずなので1個に集約)する。
  2. setup()内:init()を呼び出す(送信側は相手のMACアドレスをコンストラクタかinit()の引数に渡す必要がある)。
  3. loop()内:  
    <送信側>オブジェクト.sendingに指定した型のデータがあるので適宜編集し、send()で送る。成功したかはオブジェクト.success_sendで確認(非同期なので直後だと反映されないかも？)  
    <受信側>  
### 応用ver
