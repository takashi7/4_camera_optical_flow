////--------------------------------
//// IMU
//#include "IMU/IMU_Communication.h"
//#include "IMU/IMU_imuz_msg.h"
//#include "IMU/IMU_Communication.h"
//#include "IMU/IMU_ValueConvert.h"
//#include "IMU/IMU_Display.h"
//#include "IMU/IMU_Proccess.h"
//
//#include <windows.h>
//#include <stdio.h>
//#include <tchar.h>
//#include <conio.h>
////--------------------------------
//
//
////--------------------------------
//// Camera
//#include "video.h"
//#include "display.h"
//#include "lkflow.h"
//#include "timer.h"
//#include "draw_graph.h"
//
//#include <iostream>
//#include <opencv2\opencv.hpp>
//#include <fstream>
////--------------------------------
//
//
//#define COM_PORT_NAME _T("COM4")  // ポート名の指定。
////#define COM_PORT_NAME _T("\\\\.\\COM16") // COM10以上の場合
//
//#define BUFF_SIZE 200
//
//const int cycle = 1;
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
//	//----------------------
//	// Camera
//	Lkflow Lkflow_test;
//	//Display Display_test(0);
//	Timer Timer_test;
//	//Graph Graph_test;
//	//----------------------
//
//	//------------------------------------
//	// File
//	/*std::ofstream record("imu_camera.csv");
//	int ft = 0;*/
//	//------------------------------------
//
//	while (1) {
//		Timer_test.start_TickMeter();
//
//		if (com_ReadPacket(buff, BUFF_SIZE)) { // パケット1つを読む			
//			on_BinaryMessage(buff);
//			/*record << ft << ",";
//			record << mess.gyro[0] << "," << mess.gyro[1] << "," << mess.gyro[2] << ",";*/
//		}
//
//		//----------------------------------------------------------------------------------
//		Lkflow_test.process();
//		//Display_test.show(Lkflow_test.get_frame());
//		//Graph_test.draw_2d_graph(3 * Lkflow_test.m_meanflowx, 3 * Lkflow_test.m_meanflowy);
//
//	    //------------------------------------------------------------------
//		/*record << Lkflow_test.m_meanflowx << "," << Lkflow_test.m_meanflowy;
//		record << std::endl;
//		++ft;*/		
//	    //------------------------------------------------------------------
//
//		Lkflow_test.lkloop();
//		//if (cv::waitKey(cycle) == 27) break;
//		//----------------------------------------------------------------------------------
//
//		
//		Timer_test.end_TickMeter_1frme();
//	
//	}
//
//	com_Close();
//
//	return 0;
//}
//
