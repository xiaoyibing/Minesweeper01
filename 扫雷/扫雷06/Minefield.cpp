#include "Minefield.h"
#include <ctime>

#include <iostream>
using namespace std;

Minefield::Minefield(int numrow,int numcolumn,int nummine) :NumColumn(numcolumn), NumisFlag(0), NumisOpen(0),
	NumMine(nummine), NumRightFlag(0), NumRow(numrow){
    //��ʼ����ά����
    for (int i = 0; i < numrow; i++) {
        vector<Mine> row;//����һ��
        for (int j=0; j < numcolumn; j++) {
            row.push_back(Mine(i, j));//Ϊ�������
        }
        mines.push_back(row);//����ʼ���õ�����Ӹ�mines
    }
	PlaceMines();
}
//����
void Minefield::PlaceMines() {
    srand((unsigned int)time(NULL));    //�����
    int placedMines = 0;                //�Ѿ����õ�����
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
//����Աߵ��׵ĸ���
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
//�ж�ʤ��
bool Minefield::Win() {
	if (NumisOpen == (NumRow * NumColumn - NumMine) || (NumRightFlag == NumMine)) {
		cout << "ʤ����" << endl;
		FinishopenBomn();
		return true;
	}
	return false;
}
//�㵽ը���Ժ���ʾȫ��ը��
void Minefield::FinishopenBomn() {
	for (int i = 0; i < NumRow; i++) {
		for (int j = 0; j < NumColumn; j++) {
			mines[i][j].FinshdrawBomn();
		}
	}
}
//�ж�ʧ��
bool Minefield::Fail(int x, int y) {
	if (mines[x][y].isMine == true) {
		cout << "ʧ�ܣ�" << endl;
		FinishopenBomn();
		return true;
	}
	return false;
}

//�ı�����״̬���ı���ȷ�Ĳ������
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

//�ݹ�ҿ�
void Minefield::OpenMines(int x, int y) {
	if (mines[x][y].isOpen) return;//�Ѿ���ֱ�ӷ���
	mines[x][y].ChangeisOpen();//��
	NumisOpen++;//��������һ
	mines[x][y].DrawMine();
	//��8������ݹ�
	if (mines[x][y].roundMinenum == 0) {
		for (int dx = -1; dx <= 1; dx++) {
			for (int dy = -1; dy <= 1; dy++) {
				int nx = x + dx;
				int ny = y + dy;
				//�жϷ�Χ���Ƿ����
				if (nx >= 0 && nx < NumRow && ny >= 0 && ny < NumColumn && mines[nx][ny].isflag == false) {
					OpenMines(nx, ny);            //�ݹ�ҿ�����
				}
			}
		}
	}
}
//����
void Minefield::DrawBoard() {
	for (int i=0; i < NumRow; i++) {
		for (int j=0; j < NumColumn; j++) {
			mines[i][j].DrawMine();//�����׿��ͼ��
		}
	}
}