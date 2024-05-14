#pragma once
#include <iostream>
#include <ctime>
#include <thread> // 用于睡眠函数
#include <graphics.h>
using namespace std;
using namespace std::chrono;
class Timer
{
private:
	int number[3];//计时器的单个数字
	int x;//x坐标
	int y;//y坐标
	int width;//宽度
	int leght;//高度
	IMAGE img;//图片
	//图片地址
	const TCHAR* fileloads[10] = { _T("./image/10.png"),_T("./image/11.png"), _T("./image/12.png"),_T("./image/13.png"),
		_T("./image/14.png"),
		_T("./image/15.png"), _T("./image/16.png"),_T("./image/17.png"),_T("./image/18.png"),_T("./image/19.png") };
	//储存开始的时间
	steady_clock::time_point startTime;

public:
	//构造函数
	Timer(int a, int b, int w, int l);
	void start();//开始
	void CountTime();//计算时间差
	void drawCounter(int a, int b, int c);//绘制
	void Count(int num);//将大数字分成个位十位和百位
};
