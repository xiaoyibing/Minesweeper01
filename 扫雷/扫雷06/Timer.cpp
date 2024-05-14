#include "Timer.h"
Timer::Timer(int a, int b, int w, int l) :x(a), y(b),width(w), leght(l) {
	Count(0);
}
//��ʼ
void Timer::start() {
    startTime = steady_clock::now();
}
//����ʱ���
void Timer::CountTime() {
    auto duration = duration_cast<seconds>(steady_clock::now() - startTime);
	Count(duration.count());
}
//����
void Timer::drawCounter(int a, int b, int c) {
	loadimage(&img, fileloads[a], width, leght);
	putimage(x, y, &img);
	loadimage(&img, fileloads[b], width, leght);
	putimage(x + width, y, &img);
	loadimage(&img, fileloads[c], width, leght);
	putimage(x + width * 2, y, &img);
}
//�������ֳַɸ�λʮλ�Ͱ�λ
void Timer::Count(int num) {
	number[0] = num / 100;
	number[1] = num / 10 % 10;
	number[2] = num % 10;
	drawCounter(number[0], number[1], number[2]);
}