#include "Restart.h"
Restart::Restart(int x, int y, int w, int l):x(x),y(y), width(w), leght(l) {
	loadimage(&img, fileloads[0], width, leght);
	putimage(x, y, &img);
}
//̧��ʱ����
void Restart::DrawLaUp() {
	loadimage(&img, fileloads[0], width, leght);
	putimage(x, y, &img);
}
//���¿�ʼ��Ϸ������֪����ôд
void Restart::restartGame(int r, int m) {

}
//����ʱ����
void Restart::DrawLaDown() {
	loadimage(&img, fileloads[1], width, leght);
	putimage(x, y, &img);
}
//��Ϸʤ��ʱ����
void Restart::DrawLawin() {
	loadimage(&img, fileloads[3], width, leght);
	putimage(x, y, &img);
}
//��Ϸʧ��ʱ����
void Restart::DrawLaFalse() {
	loadimage(&img, fileloads[2], width, leght);
	putimage(x, y, &img);
}