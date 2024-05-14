#pragma once
#include <graphics.h>
using namespace std;
#include <iostream>
class Setting
{
private:
	int x;//x坐标
	int y;//y坐标
	int width;//宽度
	int leght;//高度
	int NumRow;									//行数
	int NumMine;								//雷数
	int NumColumn;								//列数
	IMAGE img;//图片
	//图片地址
	const TCHAR* fileloads[1] = { _T("./image/setting0.png") };
public:
	Setting(int x, int y, int w, int l);//构造函数
	void SettingGame();//自定义参数
	void DrawSetting();//绘制

};

