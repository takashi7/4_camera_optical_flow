// client.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include<stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <tchar.h>

#include "video.h"
#include "display.h"
#include "lkflow.h"
#include "timer.h"
#include "draw_graph.h"
#include "filter.h"

#include <iostream>
#include <opencv2\opencv.hpp>
#include <thread>
#include <fstream>

const int cycle = 1;


//-- 構造体の定義  main関数の外にコピペ ---
typedef struct {
	int sequence;
	//int q[4];
	//int grip;
	double w[4];
}Data;
//------------------------------------------



int _tmain(int argc, _TCHAR* argv[]) {

	//---------------------------------------------------------------------------------------
	Lkflow Lkflow_test0, Lkflow_test1, Lkflow_test2, Lkflow_test3;
	//Display Display_test0(0), Display_test1(1), Display_test2(2), Display_test3(3);
	//Display Display_test1(1), Display_test3(3);
	Timer Timer_test;
	Filter Filter_test;
	//Graph Graph_test;

	//------------------------------------
	// File
	std::ofstream record("4camera_test.csv");
	int ft = 0;
	//------------------------------------

	//---------------------------------------------------------------------------------------

	//----設定  ここから ----------------------------------------------
	WSADATA data;
	WSAStartup(MAKEWORD(2, 0), &data);

	int port = 35000;
	struct sockaddr_in me;
	memset(&me, 0, sizeof(me));
	me.sin_family = AF_INET;
	me.sin_addr.s_addr = htonl(INADDR_ANY);
	me.sin_port = htons(port);


	struct hostent *server_ent = gethostbyname("192.168.10.95");
	//サーバ(slave)のIPアドレスを書き込む

	struct sockaddr_in server;
	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	memcpy(&server.sin_addr, server_ent->h_addr, server_ent->h_length);


	int sock = socket(AF_INET, SOCK_DGRAM, 0);
	int ret = bind(sock, (struct sockaddr *)&me, sizeof(me));
	if (ret<0) {
		perror("bind");
		return -1;
	}

	Data buf;
	buf.sequence = 0;
	//-------- ここまでを 計測ループの前にコピペ -----------------------


	//---------------------------------------------------------------------------------------
	while (1) {
		Timer_test.start_TickMeter();

		//----------------------------------------------------------------------------------------------------
		std::thread th0_process(&Lkflow::process, &Lkflow_test0);
		std::thread th1_process(&Lkflow::process, &Lkflow_test1);
		std::thread th2_process(&Lkflow::process, &Lkflow_test2);
		std::thread th3_process(&Lkflow::process, &Lkflow_test3);
		th0_process.join();
		th1_process.join();
		th2_process.join();
		th3_process.join();

		std::vector<double> flowx{ Lkflow_test0.m_meanflowx, Lkflow_test1.m_meanflowx, Lkflow_test2.m_meanflowx, Lkflow_test3.m_meanflowx };
		std::vector<double> flowy{ Lkflow_test0.m_meanflowy, Lkflow_test1.m_meanflowy, Lkflow_test2.m_meanflowy, Lkflow_test3.m_meanflowy };
		Filter_test.calc_vw(flowx, flowy);

		//------------------------------------------------------------------
		//File
		record << ft << ",";
		record << Filter_test.m_vx << "," << Filter_test.m_vy << "," << Filter_test.m_vz << ",";
		record << Filter_test.m_wx << "," << Filter_test.m_wy << "," << Filter_test.m_wz << ",";
		//------------------------------------------------------------------

		std::vector<double> T{ Filter_test.m_vx * 5 , Filter_test.m_vy * 5 , Filter_test.m_vz * 5 , Filter_test.m_wx * 5 , Filter_test.m_wy * 5 , Filter_test.m_wz * 5 };

		std::thread th0_loop(&Lkflow::lkloop, &Lkflow_test0);
		std::thread th1_loop(&Lkflow::lkloop, &Lkflow_test1);
		std::thread th2_loop(&Lkflow::lkloop, &Lkflow_test2);
		std::thread th3_loop(&Lkflow::lkloop, &Lkflow_test3);
		th0_loop.join();
		th1_loop.join();
		th2_loop.join();
		th3_loop.join();

		//Display_test0.show(Lkflow_test0.get_frame());
		//Display_test1.show(Lkflow_test1.get_frame());
		//Display_test2.show(Lkflow_test2.get_frame());
		//Display_test3.show(Lkflow_test3.get_frame());

		//Graph_test.draw_3d_graph(T[0] * 3, T[1] * 3, T[2] * 3);
		//Graph_test.draw_3d_graph(T[3] * 3, T[4] * 3, T[5] * 3);
		if (cv::waitKey(cycle) == 27) break;
		//----------------------------------------------------------------------------------------------------

		Timer_test.end_TickMeter_1frme();

		//----------------------------------
		// File
		record << Timer_test.msec();
		record << std::endl;
		++ft;
		//----------------------------------
		//---------------------------------------------------------------------------------------


	    //---- ここから計測ループ内   読み取ったデータを逐次送る　for文の中にコピペ---
		++buf.sequence;

		//// ポテンショの角度 int で送るので1000倍する
		//buf.q[0] = 1000 * 5.0;     // 第1関節の角度を1000倍して代入
		//buf.q[1] = 1000 * 20.0;
		//buf.q[2] = 1000 * (-15.0);
		//buf.q[3] = 1000 * 12.0;   //第4関節
		//buf.grip = 1; // グリッパのスイッチ　0 or 1

		buf.w[0] = T[3];
		buf.w[1] = T[4];
		buf.w[2] = T[5];
		buf.w[3] = T[2];


		sendto(sock, (const char*)&buf, sizeof(buf), 0,
			(struct sockaddr*)&server, sizeof(server));
		//----------------------------------------------------------------------------

	}



	//---- 後処理 ループの後にコピペ----
	closesocket(sock);
	WSACleanup();
	//----------------------------------
	return 0;
}


