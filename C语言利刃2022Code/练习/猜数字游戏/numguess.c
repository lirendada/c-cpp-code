#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#include<time.h>
#include<stdlib.h>
void menu()
{
	printf("*****************************\n");
	printf("****  1.play    2.exit   ****\n");
	printf("*****************************\n");
}
void game()
{
	int a = 0;
	int guess = 0;
	a = rand() % 1000 + 1;
	while (1)
	{
		printf("请输入你的数字:");
		scanf("%d", &guess);
		if (guess > a)
			printf("大了\n");
		else if (guess < a)
			printf("小了\n");
		else
		{
			printf("找到了!\n");
			break;
		}
	}
}

int main()
{
	int choice = 0;
	srand((unsigned int)time(NULL));
	menu();
	do
	{
		printf("请确认》：");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			game();
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (choice == 1);
	return 0;
}