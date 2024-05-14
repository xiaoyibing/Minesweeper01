#include "Mine.h"

Mine::Mine(int i,int j):isMine(false), isOpen(false), roundMinenum(0), isflag(false),i(i),j(j) {
	x = i * 30;
	y = j * 30+70;
	DrawMine();
}
//改变是否是雷
void Mine::ChangeisMine()       
{
	isMine = true;
}
//改变访问状态
void Mine::ChangeisOpen() {
	isOpen = true;
}
//改变插旗状态
void Mine::Changeisflag() {
	isflag = !isflag;
}
//计算旁边的地雷数
void Mine::PlusroundMinenum() {
	roundMinenum++;
}
//游戏结束时地雷的绘制
void Mine::FinshdrawBomn() {
	if (isMine) {
		if (isOpen) {
			loadimage(&img, fileloads[10], 30, 30);
			putimage(x, y, &img);
			//是炸弹
		}
		else {
			loadimage(&img, fileloads[11], 30, 30);
			putimage(x, y, &img);
			//是炸弹
		}
	}

}
//普通点开绘制
void Mine::DrawMine() {
	if (isOpen) {//打开
		if (isMine) {
			loadimage(&img, fileloads[10],30,30);
			putimage(x,y, &img);
			//是炸弹
		}
		else {
			loadimage(&img, fileloads[roundMinenum], 30, 30);
			putimage(x, y, &img);
			//不是炸弹
		}
	}
	else {//未打开
		if (isflag) {
			loadimage(&img, fileloads[9], 30, 30);
			putimage(x, y, &img);
			//插旗
		}
		else {
			loadimage(&img, fileloads[12], 30, 30);
			putimage(x, y, &img);
			//未插旗
		}

	}
}