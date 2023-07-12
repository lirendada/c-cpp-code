#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
//实验二
int main()
{
	float r = 0.0,p;
	int n = 0;
	printf("请输入年增长率：");
	scanf("%f", &r);
	getchar();
	printf("请输入年数：");
	scanf("%d", &n);
	p = pow((1+r),n);
	printf("%d年后我国国名生产总值与现在相比增长%f百分比\n", n, p);
	return 0;
}
