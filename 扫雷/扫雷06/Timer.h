#pragma once
#include <iostream>
#include <ctime>
#include <thread> // ����˯�ߺ���
#include <graphics.h>
using namespace std;
using namespace std::chrono;
class Timer
{
private:
	int number[3];//��ʱ���ĵ�������
	int x;//x����
	int y;//y����
	int width;//���
	int leght;//�߶�
	IMAGE img;//ͼƬ
	//ͼƬ��ַ
	const TCHAR* fileloads[10] = { _T("./image/10.png"),_T("./image/11.png"), _T("./image/12.png"),_T("./image/13.png"),
		_T("./image/14.png"),
		_T("./image/15.png"), _T("./image/16.png"),_T("./image/17.png"),_T("./image/18.png"),_T("./image/19.png") };
	//���濪ʼ��ʱ��
	steady_clock::time_point startTime;

public:
	//���캯��
	Timer(int a, int b, int w, int l);
	void start();//��ʼ
	void CountTime();//����ʱ���
	void drawCounter(int a, int b, int c);//����
	void Count(int num);//�������ֳַɸ�λʮλ�Ͱ�λ
};
