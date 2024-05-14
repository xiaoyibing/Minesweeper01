#include "MinesweeperGame.h"



MinesweeperGame::MinesweeperGame(int row ,int column,int mine) :NumColumn(column), NumMine(mine), 
    NumRow(row), ScreenWidth{ NumRow *30,NumRow *30,NumRow *30,20,20,30,30},
    ScreenLeight{ NumColumn *30+70,70,NumColumn *30,50,50,30,30},
    Screenx{ 0,0,0,10,ScreenWidth[0] - 20 - ScreenWidth[4] * 3,ScreenWidth [0]/2- ScreenWidth [5],20+ ScreenWidth[4] * 3 },
    Screeny{0,0,70,10,10,20,20}, startgame(false){//调整参数
    if (ScreenWidth[0] < 300) {
        ScreenWidth[0] = 300;
        ScreenWidth[1] = 300;
        ScreenLeight[2] = 300;
        Screenx[4] = ScreenWidth[0] - 20 - ScreenWidth[4] * 3;
        Screenx[5] = ScreenWidth[0] / 2 - ScreenWidth[5];

    }

    initgraph(ScreenWidth[0], ScreenLeight[0]);        //初始化窗口
    restartgame();

}
//结束释放空间
MinesweeperGame::~MinesweeperGame() {
    delete minefield;                           
    delete counter;
    delete timer;
    delete restart;
}
//重启游戏，好像不应该出现在这个类中
void MinesweeperGame::restartgame() {
    Numdeflag = NumMine;
    startmine = true;
    startgame = false;
    cleardevice();                                     // 清屏
    //绘制背景板
    loadimage(&img, fileloads[0], ScreenWidth[1], ScreenLeight[1]);
    putimage(Screenx[1], Screeny[1], &img);
    //loadimage(&img, fileloads[1], ScreenWidth[2], ScreenLeight[2]);
    //putimage(Screenx[2], Screeny[2], &img);
    //构建对象
    //cout << NumRow << endl;
    minefield = new Minefield(NumRow, NumColumn, NumMine);
    counter = new Counter(Screenx[3], Screeny[3], Numdeflag, ScreenWidth[3], ScreenLeight[3]);
    timer = new Timer(Screenx[4], Screeny[4], ScreenWidth[4], ScreenLeight[4]);
    restart = new Restart(Screenx[5], Screeny[5], ScreenWidth[5], ScreenLeight[5]);
    setting = new Setting(Screenx[6], Screeny[6], ScreenWidth[6], ScreenLeight[6]);
}

void MinesweeperGame::settinggame() {
    cout << "请输入行数，列数，雷数，比如（10 10 10）" << endl;
    cin >> NumRow;
    cin >> NumColumn;
    cin >> NumMine;

    ScreenWidth[0] = NumRow * 30;
    ScreenWidth[1] = NumRow * 30;
    ScreenWidth[2] = NumRow * 30;
    ScreenLeight[0] = NumColumn * 30 + 70;
    ScreenLeight[2] = NumColumn * 30;
    Screenx[4] = ScreenWidth[0] - 20 - ScreenWidth[4] * 3;
    Screenx[5] = ScreenWidth[0] / 2 - ScreenWidth[5];
    Screenx[6] = 20 + ScreenWidth[4] * 3;
    if (ScreenWidth[0] < 300) {
        ScreenWidth[0] = 300;
        ScreenWidth[1] = 300;
        ScreenLeight[2] = 300;
        Screenx[4] = ScreenWidth[0] - 20 - ScreenWidth[4] * 3;
        Screenx[5] = ScreenWidth[0] / 2 - ScreenWidth[5];

    }

    initgraph(ScreenWidth[0], ScreenLeight[0]);        //初始化窗口
    restartgame();
}
void MinesweeperGame::run() {
    while (true) {
        if (MouseHit()) {                       // 检测鼠标点击事件
            MOUSEMSG msg = GetMouseMsg();       // 获取鼠标消息
            if (msg.uMsg == WM_LBUTTONDOWN) {   // 如果是左键点击
                LMouseClick(msg.x, msg.y);      // 处理鼠标左点击事件
                if (LFinishgame(msg.x, msg.y)) {
                    startmine = false;
                    //break;                          // 结束游戏循环
                }
            }
            else if (msg.uMsg == WM_RBUTTONDOWN) {
                RMouseClick(msg.x, msg.y);      // 处理鼠标右点击事件
                if (RFinishgame(msg.x, msg.y)) {
                    startmine = false;
                    //break;                          // 结束游戏循环
                }
            }
            else if (msg.uMsg == WM_LBUTTONUP) {// 处理鼠标左点击事件
                LMouseClickUp(msg.x, msg.y);
            }
        }
        if (!startgame) {//必须放在重启与timer->CountTime();之间
            timer->start();
        }
        if (startgame) {
            timer->CountTime();
        }
    }
}
//左击抬起
void MinesweeperGame::LMouseClickUp(int x, int y) {
    if (x > Screenx[5] && x < Screenx[5]+ScreenWidth[5] && y>Screeny[5] && y < Screeny[5]+ScreenLeight[5]) {
        restart->DrawLaUp();//重启按钮抬起变化
        restartgame();
    }
}
//左击按下
void MinesweeperGame::LMouseClick(int x, int y) {

    if (x > Screenx[5] && x < Screenx[5] + ScreenWidth[5] && y>Screeny[5] && y < Screeny[5] + ScreenLeight[5]) {
        restart->DrawLaDown();//重启按钮按下变化
    }
    else if (x > Screenx[6] && x < Screenx[6] + ScreenWidth[6] && y>Screeny[6] && y < Screeny[6] + ScreenLeight[6]) {
        //setting->SettingGame();
        settinggame();
    }
    else if (x > Screenx[2] && x < ScreenWidth[2]+ Screenx[2] && y>Screeny[2] && y < ScreenLeight[2] + Screeny[2] && startmine) {
        if(!startgame)
            startgame = !startgame;//第一次按下以后将游戏状态改为开始，从而启动计时器
        //下半雷区
        int dx = x/30;
        int dy = (y-70)/30;
        minefield->OpenMines(dx, dy);//打开雷块
    }

}
//右击按下
void MinesweeperGame::RMouseClick(int x, int y) {
    if (x > Screenx[2] && x < ScreenWidth[2] + Screenx[2] && y>Screeny[2] && y < ScreenLeight[2] + Screeny[2] && startmine) {
        if (!startgame)//第一次按下以后将游戏状态改为开始，从而启动计时器
            startgame = !startgame;
        int dx = x / 30;
        int dy = (y - 70) / 30;
        Numdeflag = minefield->ChangeFlag(dx, dy);//改变插旗雷块
        counter->Count(Numdeflag);//改变计数器
    }
}
//左击后判断是否结束
bool MinesweeperGame::LFinishgame(int x, int y) {
    if (x > Screenx[2] && x < ScreenWidth[2] + Screenx[2] && y>Screeny[2] && y < ScreenLeight[2] + Screeny[2]) {
        int dx = x / 30;
        int dy = (y - 70) / 30;
        if (minefield->Fail(dx, dy)) {
            restart->DrawLaFalse();
            return true;
        }
        if (minefield->Win()) {
            restart->DrawLawin();
            return true;
        }
    }
    return false;
}
//右击后判断是否结束
bool MinesweeperGame::RFinishgame(int x,int y) {
    if (x > Screenx[2] && x < ScreenWidth[2] + Screenx[2] && y>Screeny[2] && y < ScreenLeight[2] + Screeny[2]) {
        int dx = x / 30;
        int dy = (y - 70) / 30;
        if (minefield->Win()) {
            restart->DrawLawin();
            return true;
        }
    }
    return false;
}