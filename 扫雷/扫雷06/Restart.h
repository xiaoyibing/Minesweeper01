#pragma once
#include <graphics.h>
using namespace std;
#include <iostream>
class Restart
{
private:
	int x;//x����
	int y;//y����
	int width;//���
	int leght;//�߶�
	IMAGE img;//ͼƬ
	//ͼƬ��ַ
	const TCHAR* fileloads[4] = { _T("./image/ReStart0.png"),_T("./image/ReStart1.png") ,_T("./image/ReStart2.png") ,
	_T("./image/ReStart3.png") };
public:
	Restart(int x, int y, int w, int l);//���캯��
	void restartGame(int r, int m);//���¿�ʼ��Ϸ������֪����ôд
	void DrawLaDown();//����ʱ����
	void DrawLaUp();//̧��ʱ����
	void DrawLawin();//��Ϸʤ��ʱ����
	void DrawLaFalse();//��Ϸʧ��ʱ����
};

