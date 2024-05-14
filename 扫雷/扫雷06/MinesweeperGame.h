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
	IMAGE img;									//ͼƬ
	const TCHAR* fileloads[2] = { _T("./image/back0.png"),_T("./image/back1.png")};//�洢ͼƬ��ַ
	int NumRow;									//����
	int NumMine;								//����
	int NumColumn;								//����
	int ScreenWidth[7];							//����Ļ��ȣ��ϰ벿�ֿ�ȣ��°�������ȣ���������ȣ���ʱ�����,������ť���,���ð�ť�Ŀ��
	int ScreenLeight[7];						//�߶�
	int Screenx[7];								//���Ͻ�x����
	int Screeny[7];								//���Ͻ�y����	
	int Numdeflag;								//���µ�������������������ʾ������
	bool startgame;								//�Ƿ��Ѿ���ʼ��Ϸ����Ҫ���ڿ�����ʱ��
	bool startmine;
	Timer* timer;								//��ʱ������
	Minefield* minefield;						// ɨ�׳�����ָ��
	Counter* counter;							//����������
	Restart* restart;							//Ц����ť����
	Setting* setting;							//���ö���

	void LMouseClick(int x, int y);				//�������
	void RMouseClick(int x, int y);				//�һ�����
	void LMouseClickUp(int x, int y);			//���̧��
	void settinggame();//���ã�����Ӧ�ó������������
	bool LFinishgame(int x, int y);				//������ж��Ƿ����
	bool RFinishgame(int x, int y);				//�һ����ж��Ƿ����
	void restartgame();//������Ϸ������Ӧ�ó������������
public:
	int a;
	MinesweeperGame(int row, int column, int mine);							//���캯��
	~MinesweeperGame();							//�����ͷſռ�

	void run();									//����
};

