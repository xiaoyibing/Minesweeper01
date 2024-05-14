#pragma once
#include <vector>
#include "Mine.h"
using namespace std;
class Minefield
{
private:
	vector<vector<Mine>> mines;					//��ά����װ��
	int NumRow;									//����
	int NumColumn;								//����
	int NumMine;								//����
	int NumisOpen;								//�Ѿ��򿪵�����
	int NumisFlag;								//������
	int NumRightFlag;							//��ȷ�Ĳ�����

	void PlaceMines();							//��������
	void PlusnumMine(int x, int y);				//����Աߵ��׵ĸ���
public:
	Minefield(int numrow, int numcolumn, int nummine);//���캯��
	void DrawBoard();		//��ͼ
	bool Win();				//�ж�ʤ��
	bool Fail(int x, int y);//�ж�ʧ��
	int ChangeFlag(int x, int y);//�ı������
	void OpenMines(int x, int y);//�ҿ�
	void FinishopenBomn();//�㵽ը���Ժ���ʾȫ��ը��
};

