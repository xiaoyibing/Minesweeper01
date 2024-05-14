#pragma once
#include "Minefield.h"
#include "Setting.h"
#include "Counter.h"
#include "Timer.h"
#include "Restart.h"
#include <graphics.h>
#include <iostream>

using namespace std;


class MinesweeperGame
{
private:
	IMAGE img;									//图片
	const TCHAR* fileloads[2] = { _T("./image/back0.png"),_T("./image/back1.png")};//存储图片地址
	int NumRow;									//行数
	int NumMine;								//雷数
	int NumColumn;								//列数
	int ScreenWidth[7];							//总屏幕宽度，上半部分宽度，下半雷区宽度，计数器宽度，计时器宽度,重启按钮宽度,设置按钮的宽度
	int ScreenLeight[7];						//高度
	int Screenx[7];								//右上角x坐标
	int Screeny[7];								//右上角y坐标	
	int Numdeflag;								//余下的旗子数，计数器上显示的数字
	bool startgame;								//是否已经开始游戏，主要用于开启计时器
	bool startmine;
	Timer* timer;								//计时器对象
	Minefield* minefield;						// 扫雷场对象指针
	Counter* counter;							//计数器对象
	Restart* restart;							//笑脸按钮对象
	Setting* setting;							//设置对象

	void LMouseClick(int x, int y);				//左击按下
	void RMouseClick(int x, int y);				//右击按下
	void LMouseClickUp(int x, int y);			//左击抬起
	void settinggame();//设置，好像不应该出现在这个类中
	bool LFinishgame(int x, int y);				//左击后判断是否结束
	bool RFinishgame(int x, int y);				//右击后判断是否结束
	void restartgame();//重启游戏，好像不应该出现在这个类中
public:
	int a;
	MinesweeperGame(int row, int column, int mine);							//构造函数
	~MinesweeperGame();							//结束释放空间

	void run();									//运行
};

