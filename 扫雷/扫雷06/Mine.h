#pragma once
#include <graphics.h>
#include <iostream>
using namespace std;
class Mine
{
private:
    IMAGE img;//图片
    const TCHAR* fileloads[13] = {_T("./image/0.png"),_T("./image/1.png"), _T("./image/2.png"),_T("./image/3.png"),_T("./image/4.png"),
        _T("./image/5.png"), _T("./image/6.png"),_T("./image/7.png"),_T("./image/8.png"),_T("./image/flag.png"),_T("./image/bombed.png"),
        _T("./image/Unbombed.png"), _T("./image/00.png") };//存储图片地址
public:
    int x, y;//坐标
    int i, j;//行列
    bool isMine;            //是否是雷
    bool isOpen;            //是否访问过
    int roundMinenum;       //旁边的地雷数
    bool isflag;            //是否插旗

    Mine(int i, int j);
    void ChangeisMine();        //改变是否是雷
    void ChangeisOpen();        //改变是否访问
    void Changeisflag();        //改变是否插旗
    void PlusroundMinenum();    //增添旁边的地雷数
    void DrawMine();//绘制
    void FinshdrawBomn();//由于最后有红的的雷（点到的那个）以及白色的雷（其他未点到的）,所以设置了一个先判断再绘制的函数
};

