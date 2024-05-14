#include <iostream>
#include "MinesweeperGame.h"
using namespace std;

int main() {
    MinesweeperGame* game = new MinesweeperGame(5,8,10);  //创建游戏对象
    game->run();//开启游戏进程
    delete game;//释放空间
    system("pause");
    return 0;
}