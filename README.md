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
  1. やり取りしたいデータの型(多分配列は無理なので複数あるならstructを作る)をテンプレート引数にしてESPnowRimoconクラスのオブジェクトを作成(複数作るとバグるはずなので1個に集約)する。
  2. setup()内: init()を呼び出す(送信側は相手のMACアドレスをコンストラクタかinit()の引数に渡す必要がある)。**注意：やり取りするデータ型の定義は送受信問わず両方に書いてください。**(#pragma(pack,1)をしておくと無駄のない通信ができるかも)
  3. loop()内:  
    <送信側>オブジェクト.sendingに指定した型のデータがあるので適宜編集し、send()で送る。成功したかはオブジェクト.success_sendで確認(非同期なので直後だと反映されないかも？)  
    <受信側>オブジェクト.recieve_newで条件分岐して直後にrecieve_new = false;を入れた後、オブジェクト.receivedに指定した型のデータが届いてるのでそれを使う。
### 応用ver
  1. やり取りするデータ型の定義をした後、ESPnowRimoconクラスのラッパークラスを作って(テンプレート引数を渡した状態での継承が楽かも)、初期化処理とloop内処理をそれぞれvoid begin()とvoid update()にoverrideする形で記述する。
  2. いい感じにbegin()してupdate()してくださいな。

---
作成者:Tomoooji in AiMEiBA  
最終更新日:2026/03/21
