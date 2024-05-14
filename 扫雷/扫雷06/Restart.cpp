#include "Restart.h"
Restart::Restart(int x, int y, int w, int l):x(x),y(y), width(w), leght(l) {
	loadimage(&img, fileloads[0], width, leght);
	putimage(x, y, &img);
}
//抬起时绘制
void Restart::DrawLaUp() {
	loadimage(&img, fileloads[0], width, leght);
	putimage(x, y, &img);
}
//重新开始游戏，还不知道怎么写
void Restart::restartGame(int r, int m) {

}
//按下时绘制
void Restart::DrawLaDown() {
	loadimage(&img, fileloads[1], width, leght);
	putimage(x, y, &img);
}
//游戏胜利时绘制
void Restart::DrawLawin() {
	loadimage(&img, fileloads[3], width, leght);
	putimage(x, y, &img);
}
//游戏失败时绘制
void Restart::DrawLaFalse() {
	loadimage(&img, fileloads[2], width, leght);
	putimage(x, y, &img);
}