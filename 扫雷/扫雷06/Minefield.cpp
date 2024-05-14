#include "Minefield.h"
#include <ctime>

#include <iostream>
using namespace std;

Minefield::Minefield(int numrow,int numcolumn,int nummine) :NumColumn(numcolumn), NumisFlag(0), NumisOpen(0),
	NumMine(nummine), NumRightFlag(0), NumRow(numrow){
    //初始化二维数组
    for (int i = 0; i < numrow; i++) {
        vector<Mine> row;//定义一行
        for (int j=0; j < numcolumn; j++) {
            row.push_back(Mine(i, j));//为行添加列
        }
        mines.push_back(row);//将初始化好的行添加给mines
    }
	PlaceMines();
}
//铺雷
void Minefield::PlaceMines() {
    srand((unsigned int)time(NULL));    //随机数
    int placedMines = 0;                //已经放置的雷数
    while (placedMines < NumMine) {
        int x = rand() % NumRow;
        int y = rand() % NumColumn;
        if (mines[x][y].isMine == false) {
            mines[x][y].ChangeisMine();
            PlusnumMine(x, y);
            placedMines++;
        }
    }
}
//添加旁边的雷的个数
void Minefield::PlusnumMine(int x, int y) {
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < NumRow && ny >= 0 && ny < NumColumn && !(dx == 0 && dy == 0)) {
                mines[nx][ny].PlusroundMinenum();
            }
        }
    }
}
//判断胜利
bool Minefield::Win() {
	if (NumisOpen == (NumRow * NumColumn - NumMine) || (NumRightFlag == NumMine)) {
		cout << "胜利！" << endl;
		FinishopenBomn();
		return true;
	}
	return false;
}
//点到炸弹以后显示全部炸弹
void Minefield::FinishopenBomn() {
	for (int i = 0; i < NumRow; i++) {
		for (int j = 0; j < NumColumn; j++) {
			mines[i][j].FinshdrawBomn();
		}
	}
}
//判断失败
bool Minefield::Fail(int x, int y) {
	if (mines[x][y].isMine == true) {
		cout << "失败！" << endl;
		FinishopenBomn();
		return true;
	}
	return false;
}

//改变插旗的状态，改变正确的插旗个数
int Minefield::ChangeFlag(int x, int y) {
	if (mines[x][y].isOpen) return NumMine - NumisFlag;
	if (mines[x][y].isflag == false && NumisFlag != NumMine)
	{
		mines[x][y].Changeisflag();
		NumisFlag++;
		if (mines[x][y].isMine == true) {
			NumRightFlag++;
		}
	}
	else if (mines[x][y].isflag == true && NumisFlag != 0)
	{
		mines[x][y].Changeisflag();
		NumisFlag--;
		if (mines[x][y].isMine == true) {
			NumRightFlag--;
		}
	}
	mines[x][y].DrawMine();
	return NumMine - NumisFlag;
}

//递归揭开
void Minefield::OpenMines(int x, int y) {
	if (mines[x][y].isOpen) return;//已经打开直接返回
	mines[x][y].ChangeisOpen();//打开
	NumisOpen++;//打开数量加一
	mines[x][y].DrawMine();
	//向8个方向递归
	if (mines[x][y].roundMinenum == 0) {
		for (int dx = -1; dx <= 1; dx++) {
			for (int dy = -1; dy <= 1; dy++) {
				int nx = x + dx;
				int ny = y + dy;
				//判断范围和是否插旗
				if (nx >= 0 && nx < NumRow && ny >= 0 && ny < NumColumn && mines[nx][ny].isflag == false) {
					OpenMines(nx, ny);            //递归揭开格子
				}
			}
		}
	}
}
//绘制
void Minefield::DrawBoard() {
	for (int i=0; i < NumRow; i++) {
		for (int j=0; j < NumColumn; j++) {
			mines[i][j].DrawMine();//绘制雷块的图案
		}
	}
}