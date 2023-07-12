#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<ctime>
#include <windows.h>
#include <conio.h>
using namespace std;
clock_t startTime, endTime;

int main() {
	startTime = clock();		//程序开始计时
	double sum = 5;	//60秒
	double time = .0;
	int flag = 1;
	while (1)
	{
		endTime = clock();
		time = (double)(endTime - startTime) / 1000;

		if (flag == 1)
		{
			cout << "00:" << sum << endl;
			flag = 0;
		}
		if (time > 1)
		{
			sum--;
			time -= 1;
			flag = 1;
			startTime = endTime;
		}
		/*if (sum == 0 || _kbhit())
		{
			ch = _getch();
			if (ch != 'h')
				continue;
			else
			{
				sum = 180;
				continue;
			}
			sum = 180;
			printf("\a");
		}*/
		if (sum == 0)
		{
			keybd_event(0x42, MapVirtualKeyW(0x42, 0), 0, 0);
			sum = 60;
		}
	}
	system("pause");
	return 0;
}
