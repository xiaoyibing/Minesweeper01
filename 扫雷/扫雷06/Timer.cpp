#include "Timer.h"
Timer::Timer(int a, int b, int w, int l) :x(a), y(b),width(w), leght(l) {
	Count(0);
}
//开始
void Timer::start() {
    startTime = steady_clock::now();
}
//计算时间差
void Timer::CountTime() {
    auto duration = duration_cast<seconds>(steady_clock::now() - startTime);
	Count(duration.count());
}
//绘制
void Timer::drawCounter(int a, int b, int c) {
	loadimage(&img, fileloads[a], width, leght);
	putimage(x, y, &img);
	loadimage(&img, fileloads[b], width, leght);
	putimage(x + width, y, &img);
	loadimage(&img, fileloads[c], width, leght);
	putimage(x + width * 2, y, &img);
}
//将大数字分成个位十位和百位
void Timer::Count(int num) {
	number[0] = num / 100;
	number[1] = num / 10 % 10;
	number[2] = num % 10;
	drawCounter(number[0], number[1], number[2]);
}