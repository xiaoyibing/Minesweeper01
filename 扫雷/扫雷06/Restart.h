#pragma once
#include <graphics.h>
using namespace std;
#include <iostream>
class Restart
{
private:
	int x;//x坐标
	int y;//y坐标
	int width;//宽度
	int leght;//高度
	IMAGE img;//图片
	//图片地址
	const TCHAR* fileloads[4] = { _T("./image/ReStart0.png"),_T("./image/ReStart1.png") ,_T("./image/ReStart2.png") ,
	_T("./image/ReStart3.png") };
public:
	Restart(int x, int y, int w, int l);//构造函数
	void restartGame(int r, int m);//重新开始游戏，还不知道怎么写
	void DrawLaDown();//按下时绘制
	void DrawLaUp();//抬起时绘制
	void DrawLawin();//游戏胜利时绘制
	void DrawLaFalse();//游戏失败时绘制
};

