#include "Mine.h"

Mine::Mine(int i,int j):isMine(false), isOpen(false), roundMinenum(0), isflag(false),i(i),j(j) {
	x = i * 30;
	y = j * 30+70;
	DrawMine();
}
//�ı��Ƿ�����
void Mine::ChangeisMine()       
{
	isMine = true;
}
//�ı����״̬
void Mine::ChangeisOpen() {
	isOpen = true;
}
//�ı����״̬
void Mine::Changeisflag() {
	isflag = !isflag;
}
//�����Աߵĵ�����
void Mine::PlusroundMinenum() {
	roundMinenum++;
}
//��Ϸ����ʱ���׵Ļ���
void Mine::FinshdrawBomn() {
	if (isMine) {
		if (isOpen) {
			loadimage(&img, fileloads[10], 30, 30);
			putimage(x, y, &img);
			//��ը��
		}
		else {
			loadimage(&img, fileloads[11], 30, 30);
			putimage(x, y, &img);
			//��ը��
		}
	}

}
//��ͨ�㿪����
void Mine::DrawMine() {
	if (isOpen) {//��
		if (isMine) {
			loadimage(&img, fileloads[10],30,30);
			putimage(x,y, &img);
			//��ը��
		}
		else {
			loadimage(&img, fileloads[roundMinenum], 30, 30);
			putimage(x, y, &img);
			//����ը��
		}
	}
	else {//δ��
		if (isflag) {
			loadimage(&img, fileloads[9], 30, 30);
			putimage(x, y, &img);
			//����
		}
		else {
			loadimage(&img, fileloads[12], 30, 30);
			putimage(x, y, &img);
			//δ����
		}

	}
}