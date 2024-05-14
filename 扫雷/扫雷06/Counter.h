#pragma once
#include <graphics.h>
#include <iostream>

using namespace std;
class Counter
{
private:
	int number[3];//计数器的三个数字
	int x;//x坐标
	int y;//y坐标
	int width;//宽度
	int leght;//高度
	int flagNum;//要显示的数字
	IMAGE img;//图片
	//图片地址
	const TCHAR* fileloads[10] = { _T("./image/10.png"),_T("./image/11.png"), _T("./image/12.png"),_T("./image/13.png"),
		_T("./image/14.png"),
		_T("./image/15.png"), _T("./image/16.png"),_T("./image/17.png"),_T("./image/18.png"),_T("./image/19.png")};
public:
	Counter(int a, int b, int numflag,int w,int l);//构造函数
	void drawCounter(int a, int b, int c);//绘制
	void Count(int num);//将大数字分成个位十位和百位
};

