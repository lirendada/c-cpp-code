#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<time.h>
//int main()
//{
//	char wday[][4] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};;
//	time_t timep;
//	struct tm* p;
//	time(&timep);
//	printf("当地时间：%s", ctime(&timep));
//
//	p = gmtime(&timep);
//	printf("%s", asctime(p));
//	printf("UTC时间：%d-%d-%d ", (1900+p->tm_year),(1+p->tm_mon),(p->tm_mday));
//	printf("%s %d:%d:%d\n",wday[p->tm_wday],(p->tm_hour),(p->tm_min),p->tm_sec);
//
//	p = localtime(&timep);
//	printf("当地时间：%d-%d-%d ", (1900 + p->tm_year), (1 + p->tm_mon), (p->tm_mday));
//	printf("%s %d:%d:%d\n", wday[p->tm_wday], (p->tm_hour), (p->tm_min), p->tm_sec);
//	return 0;
//}

//int main()
//{
//	char d1[20] = "hello";
//	char s1[] = "worldabc";
//	strncat(d1, s1, 6);
//	printf("%s\n", d1);
//	return 0;
//}


//int main()
//{
//    time_t cur_time;      //定义变量
//    time(&cur_time);    //获取当前时间
//    printf("%lld\n", cur_time);   //将当前时间直接输出
//    return 0;
//}

int main()
{
	int x = 0, y = 0;
	srand((unsigned int)time(0));
	x= x = rand() % 3;
	y = rand() % 3;
	printf("%d %d", x, y);
}
