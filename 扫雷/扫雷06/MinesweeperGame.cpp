#include "MinesweeperGame.h"



MinesweeperGame::MinesweeperGame(int row ,int column,int mine) :NumColumn(column), NumMine(mine), 
    NumRow(row), ScreenWidth{ NumRow *30,NumRow *30,NumRow *30,20,20,30,30},
    ScreenLeight{ NumColumn *30+70,70,NumColumn *30,50,50,30,30},
    Screenx{ 0,0,0,10,ScreenWidth[0] - 20 - ScreenWidth[4] * 3,ScreenWidth [0]/2- ScreenWidth [5],20+ ScreenWidth[4] * 3 },
    Screeny{0,0,70,10,10,20,20}, startgame(false){//��������
    if (ScreenWidth[0] < 300) {
        ScreenWidth[0] = 300;
        ScreenWidth[1] = 300;
        ScreenLeight[2] = 300;
        Screenx[4] = ScreenWidth[0] - 20 - ScreenWidth[4] * 3;
        Screenx[5] = ScreenWidth[0] / 2 - ScreenWidth[5];

    }

    initgraph(ScreenWidth[0], ScreenLeight[0]);        //��ʼ������
    restartgame();

}
//�����ͷſռ�
MinesweeperGame::~MinesweeperGame() {
    delete minefield;                           
    delete counter;
    delete timer;
    delete restart;
}
//������Ϸ������Ӧ�ó������������
void MinesweeperGame::restartgame() {
    Numdeflag = NumMine;
    startmine = true;
    startgame = false;
    cleardevice();                                     // ����
    //���Ʊ�����
    loadimage(&img, fileloads[0], ScreenWidth[1], ScreenLeight[1]);
    putimage(Screenx[1], Screeny[1], &img);
    //loadimage(&img, fileloads[1], ScreenWidth[2], ScreenLeight[2]);
    //putimage(Screenx[2], Screeny[2], &img);
    //��������
    //cout << NumRow << endl;
    minefield = new Minefield(NumRow, NumColumn, NumMine);
    counter = new Counter(Screenx[3], Screeny[3], Numdeflag, ScreenWidth[3], ScreenLeight[3]);
    timer = new Timer(Screenx[4], Screeny[4], ScreenWidth[4], ScreenLeight[4]);
    restart = new Restart(Screenx[5], Screeny[5], ScreenWidth[5], ScreenLeight[5]);
    setting = new Setting(Screenx[6], Screeny[6], ScreenWidth[6], ScreenLeight[6]);
}

void MinesweeperGame::settinggame() {
    cout << "���������������������������磨10 10 10��" << endl;
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

    initgraph(ScreenWidth[0], ScreenLeight[0]);        //��ʼ������
    restartgame();
}
void MinesweeperGame::run() {
    while (true) {
        if (MouseHit()) {                       // ���������¼�
            MOUSEMSG msg = GetMouseMsg();       // ��ȡ�����Ϣ
            if (msg.uMsg == WM_LBUTTONDOWN) {   // �����������
                LMouseClick(msg.x, msg.y);      // ������������¼�
                if (LFinishgame(msg.x, msg.y)) {
                    startmine = false;
                    //break;                          // ������Ϸѭ��
                }
            }
            else if (msg.uMsg == WM_RBUTTONDOWN) {
                RMouseClick(msg.x, msg.y);      // ��������ҵ���¼�
                if (RFinishgame(msg.x, msg.y)) {
                    startmine = false;
                    //break;                          // ������Ϸѭ��
                }
            }
            else if (msg.uMsg == WM_LBUTTONUP) {// ������������¼�
                LMouseClickUp(msg.x, msg.y);
            }
        }
        if (!startgame) {//�������������timer->CountTime();֮��
            timer->start();
        }
        if (startgame) {
            timer->CountTime();
        }
    }
}
//���̧��
void MinesweeperGame::LMouseClickUp(int x, int y) {
    if (x > Screenx[5] && x < Screenx[5]+ScreenWidth[5] && y>Screeny[5] && y < Screeny[5]+ScreenLeight[5]) {
        restart->DrawLaUp();//������ţ̌��仯
        restartgame();
    }
}
//�������
void MinesweeperGame::LMouseClick(int x, int y) {

    if (x > Screenx[5] && x < Screenx[5] + ScreenWidth[5] && y>Screeny[5] && y < Screeny[5] + ScreenLeight[5]) {
        restart->DrawLaDown();//������ť���±仯
    }
    else if (x > Screenx[6] && x < Screenx[6] + ScreenWidth[6] && y>Screeny[6] && y < Screeny[6] + ScreenLeight[6]) {
        //setting->SettingGame();
        settinggame();
    }
    else if (x > Screenx[2] && x < ScreenWidth[2]+ Screenx[2] && y>Screeny[2] && y < ScreenLeight[2] + Screeny[2] && startmine) {
        if(!startgame)
            startgame = !startgame;//��һ�ΰ����Ժ���Ϸ״̬��Ϊ��ʼ���Ӷ�������ʱ��
        //�°�����
        int dx = x/30;
        int dy = (y-70)/30;
        minefield->OpenMines(dx, dy);//���׿�
    }

}
//�һ�����
void MinesweeperGame::RMouseClick(int x, int y) {
    if (x > Screenx[2] && x < ScreenWidth[2] + Screenx[2] && y>Screeny[2] && y < ScreenLeight[2] + Screeny[2] && startmine) {
        if (!startgame)//��һ�ΰ����Ժ���Ϸ״̬��Ϊ��ʼ���Ӷ�������ʱ��
            startgame = !startgame;
        int dx = x / 30;
        int dy = (y - 70) / 30;
        Numdeflag = minefield->ChangeFlag(dx, dy);//�ı�����׿�
        counter->Count(Numdeflag);//�ı������
    }
}
//������ж��Ƿ����
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
//�һ����ж��Ƿ����
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