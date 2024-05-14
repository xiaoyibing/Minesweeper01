#include "Counter.h"

//���캯��
Counter::Counter(int a, int b, int numflag, int w, int l) :x(a), y(b), flagNum(numflag),width(w),leght(l) {
	Count(flagNum);
}

//����
void Counter::drawCounter(int a,int b,int c) {
	loadimage(&img, fileloads[a], width, leght);
	putimage(x, y, &img);
	loadimage(&img, fileloads[b], width, leght);
	putimage(x + width, y, &img);
	loadimage(&img, fileloads[c], width, leght);
	putimage(x + width*2, y, &img);
}
//�������ֳַɸ�λʮλ�Ͱ�λ
void Counter::Count(int num) {
	number[0] = num/100;
	number[1] = num/10%10;
	number[2] = num%10;
	drawCounter(number[0], number[1], number[2]);
}