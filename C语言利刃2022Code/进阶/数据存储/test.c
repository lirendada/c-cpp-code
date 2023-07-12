#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

                      //写一个代码告诉我们当前机器的字节序是什么
//int main()
//{
//	int a = 1;
//	char* p = (char*)&a;
//	if (*p == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}



                                    //实例(考查原反补码以及char类型的存储）p113
//int main()
//{
//    char a = -1;
//    signed char b = -1;
//    unsigned char c = -1;
//    printf("%d %d %d\n", a, b, c);
//    return 0;
//}


                                  //实例p113
//int main()
//{
//    char a = -128;
//    char b = 128;
//    printf("%u %u", a, b);
//    return 0;
//}



                                   //实例p115
//int main()
//{
//    int i = -20;
//    unsigned int j = 10;
//    printf("%d\n", i + j);
//    return 0;
//}



                                   //实例115
//int main()
//{
//    unsigned int i;
//    for (i = 9; i >= 0; i--)
//    {
//        printf("%u\n", i);
//    }
//    return 0;
//}



                                //实例（考查char类型的数据范围为-128到127）p115
//int main()
//{
//    char a[1000];
//    int i = 0;
//    for (i = 0; i < 1000; i++)
//    {
//        a[i] = -1 - i;
//    }
//    printf("%d\n", strlen(a));
//    for (i = 0; i < strlen(a); i++)
//    {
//        printf("%d\n", a[i]);
//    }
//    return 0;
//


       
                                 //实例p115
//unsigned char i = 0;
//int main()
//{
//    for (i = 0; i <= 255; i++)//此处为266，而无符号的char最高为255，所以重置为0后死循环
//    {
//        printf("利刃", i);
//    }
//    return 0;
//}



                                 //实例p118（浮点类型数据的存放）
int main()
{
    int n = 9;//0 00000000 00000000000000000000101 - 补码
    float* p = (float*)&n;//(-1)^0 * 0.00000000000000000000101 * 2^126
    printf("%d\n", n);
    printf("%f\n", *p);

    *p = 9.0;
    //转化为二进制：1001.0
    //接着变成1.001*2^3
    //然后(-1)^0 * 1.001 *2^3
    //最后变成*p=0 10000010 00100000000000000000000 -补码

    //而n也等于*p=01000001000100000000000000000000
    printf("%d\n", n);
    printf("%f\n", *p);
    return 0;
}