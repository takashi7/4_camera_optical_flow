//#include "IMU/IMU_Communication.h"
//#include "IMU/IMU_imuz_msg.h"
//#include "IMU/IMU_Communication.h"
//
//#include "IMU/IMU_ValueConvert.h"
//#include "IMU/IMU_Display.h"
//#include "IMU/IMU_Proccess.h"
//
//#include <windows.h>
//#include <stdio.h>
//#include <tchar.h>
//#include <conio.h>
//
//
//#define COM_PORT_NAME _T("COM4")  // ポート名の指定。
////#define COM_PORT_NAME _T("\\\\.\\COM16") // COM10以上の場合
//
//#define BUFF_SIZE 200
//
//
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	//-------------------------------------------------------------------------------------------------
//	// Bluetooth
//	BYTE buff[BUFF_SIZE];
//	memset(buff, 0x00, sizeof(buff));
//	conv_Init(); // メッセージ変換の初期化	
//	if (!com_Open(COM_PORT_NAME)) { // ポートのオープン
//		_ftprintf(stderr, _T("can not open the port %s.\n"), COM_PORT_NAME);
//		return 1;
//	}
//	Sleep(1000);
//	conv_SetupFactors(31, HARDWARE_IMUZ_2, Range2g, Range500dps, Range1_3Ga, FALSE); //レンジをセット.
//	com_SendString("BI311\r\n"); // コマンド送信, バイナリモードにする
//	//-------------------------------------------------------------------------------------------------
//
//	//---------------------------------------------------------------------------------------------------------
//	// Bluetooth　Loop
//	while (!_kbhit()) { // _kbhitはキーが押されると&0以外の値を返す。 それ以外の場合は0を返す
//						
//		if (com_ReadPacket(buff, BUFF_SIZE))  // パケット1つを読む			
//			on_BinaryMessage(buff); // パケット受信処理
//		else 			
//			Sleep(10); // パケットが到着していないので待ち
//		
//	}
//	//---------------------------------------------------------------------------------------------------------
//
//
//	com_Close();
//
//	return 0;
//}