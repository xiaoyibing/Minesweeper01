#pragma once
#include <graphics.h>
#include <iostream>

using namespace std;
class Counter
{
private:
	int number[3];//����������������
	int x;//x����
	int y;//y����
	int width;//���
	int leght;//�߶�
	int flagNum;//Ҫ��ʾ������
	IMAGE img;//ͼƬ
	//ͼƬ��ַ
	const TCHAR* fileloads[10] = { _T("./image/10.png"),_T("./image/11.png"), _T("./image/12.png"),_T("./image/13.png"),
		_T("./image/14.png"),
		_T("./image/15.png"), _T("./image/16.png"),_T("./image/17.png"),_T("./image/18.png"),_T("./image/19.png")};
public:
	Counter(int a, int b, int numflag,int w,int l);//���캯��
	void drawCounter(int a, int b, int c);//����
	void Count(int num);//�������ֳַɸ�λʮλ�Ͱ�λ
};

