#pragma once
#include <vector>
#include "Mine.h"
using namespace std;
class Minefield
{
private:
	vector<vector<Mine>> mines;					//二维数组装雷
	int NumRow;									//行数
	int NumColumn;								//列数
	int NumMine;								//雷数
	int NumisOpen;								//已经打开的雷数
	int NumisFlag;								//插旗数
	int NumRightFlag;							//正确的插旗数

	void PlaceMines();							//随机雷添加
	void PlusnumMine(int x, int y);				//添加旁边的雷的个数
public:
	Minefield(int numrow, int numcolumn, int nummine);//构造函数
	void DrawBoard();		//绘图
	bool Win();				//判断胜利
	bool Fail(int x, int y);//判断失败
	int ChangeFlag(int x, int y);//改变插旗数
	void OpenMines(int x, int y);//揭开
	void FinishopenBomn();//点到炸弹以后显示全部炸弹
};

