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
//#define COM_PORT_NAME _T("COM4")  // �|�[�g���̎w��B
////#define COM_PORT_NAME _T("\\\\.\\COM16") // COM10�ȏ�̏ꍇ
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
//	conv_Init(); // ���b�Z�[�W�ϊ��̏�����	
//	if (!com_Open(COM_PORT_NAME)) { // �|�[�g�̃I�[�v��
//		_ftprintf(stderr, _T("can not open the port %s.\n"), COM_PORT_NAME);
//		return 1;
//	}
//	Sleep(1000);
//	conv_SetupFactors(31, HARDWARE_IMUZ_2, Range2g, Range500dps, Range1_3Ga, FALSE); //�����W���Z�b�g.
//	com_SendString("BI311\r\n"); // �R�}���h���M, �o�C�i�����[�h�ɂ���
//	//-------------------------------------------------------------------------------------------------
//
//	//---------------------------------------------------------------------------------------------------------
//	// Bluetooth�@Loop
//	while (!_kbhit()) { // _kbhit�̓L�[����������&0�ȊO�̒l��Ԃ��B ����ȊO�̏ꍇ��0��Ԃ�
//						
//		if (com_ReadPacket(buff, BUFF_SIZE))  // �p�P�b�g1��ǂ�			
//			on_BinaryMessage(buff); // �p�P�b�g��M����
//		else 			
//			Sleep(10); // �p�P�b�g���������Ă��Ȃ��̂ő҂�
//		
//	}
//	//---------------------------------------------------------------------------------------------------------
//
//
//	com_Close();
//
//	return 0;
//}