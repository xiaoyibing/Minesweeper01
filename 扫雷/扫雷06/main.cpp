#include <iostream>
#include "MinesweeperGame.h"
using namespace std;

int main() {
    MinesweeperGame* game = new MinesweeperGame(5,8,10);  //������Ϸ����
    game->run();//������Ϸ����
    delete game;//�ͷſռ�
    system("pause");
    return 0;
}