#pragma once
#include <graphics.h>
#include <iostream>
using namespace std;
class Mine
{
private:
    IMAGE img;//ͼƬ
    const TCHAR* fileloads[13] = {_T("./image/0.png"),_T("./image/1.png"), _T("./image/2.png"),_T("./image/3.png"),_T("./image/4.png"),
        _T("./image/5.png"), _T("./image/6.png"),_T("./image/7.png"),_T("./image/8.png"),_T("./image/flag.png"),_T("./image/bombed.png"),
        _T("./image/Unbombed.png"), _T("./image/00.png") };//�洢ͼƬ��ַ
public:
    int x, y;//����
    int i, j;//����
    bool isMine;            //�Ƿ�����
    bool isOpen;            //�Ƿ���ʹ�
    int roundMinenum;       //�Աߵĵ�����
    bool isflag;            //�Ƿ����

    Mine(int i, int j);
    void ChangeisMine();        //�ı��Ƿ�����
    void ChangeisOpen();        //�ı��Ƿ����
    void Changeisflag();        //�ı��Ƿ����
    void PlusroundMinenum();    //�����Աߵĵ�����
    void DrawMine();//����
    void FinshdrawBomn();//��������к�ĵ��ף��㵽���Ǹ����Լ���ɫ���ף�����δ�㵽�ģ�,����������һ�����ж��ٻ��Ƶĺ���
};

