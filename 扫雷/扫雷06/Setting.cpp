#include "Setting.h"


Setting::Setting(int x, int y, int w, int l) :x(x), y(y), width(w), leght(l), NumRow(10), NumColumn(10), NumMine(10){
	loadimage(&img, fileloads[0], width, leght);
	putimage(x, y, &img);
}

void Setting::SettingGame() {
	cout << "���������������������������磨10 10 10��" << endl;
	cin >> NumRow;
	cin >> NumColumn;
	cin >> NumMine;
}


void Setting::DrawSetting() {
}
