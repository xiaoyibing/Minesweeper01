#pragma once
#include <graphics.h>
using namespace std;
#include <iostream>
class Setting
{
private:
	int x;//x����
	int y;//y����
	int width;//���
	int leght;//�߶�
	int NumRow;									//����
	int NumMine;								//����
	int NumColumn;								//����
	IMAGE img;//ͼƬ
	//ͼƬ��ַ
	const TCHAR* fileloads[1] = { _T("./image/setting0.png") };
public:
	Setting(int x, int y, int w, int l);//���캯��
	void SettingGame();//�Զ������
	void DrawSetting();//����

};

