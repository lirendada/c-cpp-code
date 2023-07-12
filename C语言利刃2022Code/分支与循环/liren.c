#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

///////////////////////////////////////////////////判断该数是否为奇数
//int main()
//{
//	int a;
//	a=0;
//	printf("请输入一个数字判断是否为奇数：");
//	scanf("%d",&a);
//	if(a%2==1)
//	{
//		printf("该数为奇数\n");
//	}
//	else
//	{
//		printf("该数为偶数\n");
//	}
//	return 0;
//}

/////////////////////////////////////////////////////////输出1-100的奇数
//int main()       
//{
//	int i=1;
//	while(i<=100)
//	{
//		if(i%2==1)
//			printf("%d  ",i);
//		i++;
//	}
//	return 0;
//}

//
//int main()
//{
//	int day=0;
//	scanf("%d",&day);
//	switch(day)
//	{
//case 1:
//case 2:
//case 3:
//case 4:
//case 5:
//	printf("工作日\n");
//	break;
//case 6:
//case 7:
//	printf("休息日\n");
//	break;
//default:
//	printf("输入错误\n");
//	}
//	return 0;
//}

//int main()
//{
//	char ch;
//	while((ch=getchar()) != EOF)
//	{
//		putchar(ch);
//	};
//	return 0;
//}


//int main()
//{
//	char ch;
//	scanf("%c",&ch);
//	ch=(ch>='A' && ch<='Z')?(ch+32):ch;
//	printf("%c\n",ch);
//	return 0;
//}

//int main()
//{
//	float m,d,t;
//	printf("请输入购物款:\n");
//	scanf("%f",&m);
//	if(m<250)
//		d=0;
//	else if(m>=250 && m<500)
//		d=0.05;
// 
//	else if(m>=500 && m<=1000)
//		d=0.075;
//	else
//		d=0.15;
//	t=m*(1-d);
//	printf("实际应付款：%5.2f\n",t);
//	return 0;
//}

//int main()
//{
//	int i,j,k;
//	for(i=0;i<10;i++)
//	{
//		for(j=9;j>i;j--) printf("   ");
//		for(k=0;k<=i;k++) printf("* ");
//		printf("\n");
//	};
//	return 0;
//}

//int main()
//{
//	int i,j;
//	for(i=0;i<=10;i++)
//	{
//		for(j=0;j<=i;j++)
//			printf("* ");
//		printf("\n");
//	};
//	return 0;
//}

//int main()
//{
//	int i,j;
//	for(i=0;i<=10;i++)
//	{
//		j=0;
//		while(j<=i)
//		{
//			printf("* ");
//			j++;
//		};
//		printf("\n");
//	};
//	return 0;
//}

//int main()
//{
//	int i,j;
//	for(i=0;i<=10;i++)
//	{
//		for(j=0;j<=i;j++)
//			printf("* ");
//		printf("\n");
//	};
//	return 0;
//}

//int main()
//{
//	int i,j,k;
//	for(i=0;i<10;i++)
//	{
//		for(j=10;j>=i;j--)
//			printf(" ");
//		for(k=0;k<=i;k++)
//			printf("* ");
//		printf("\n");
//	};
//	return 0;
//}

//int main()
//{
//	int i,j;
//	for(i=0;i<=10;i++)
//	{
//		for(j=10;j>=i;j--)
//			printf("* ");
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int i,j,k;
//	for(i=0;i<10;i++)
//	{
//		for(k=0;k<i;k++)
//			printf("  ");
//		for(j=9;j>=i;j--)
//			printf("* ");
//		printf("\n");
//	}
//	return 0;
//}


//int main()
//{
//	int i,j,k;
//	for(i=0;i<10;i++)
//	{
//		for(j=9;j>i;j--)
//			printf("  ");
//		for(k=0;k<=i;k++)
//			printf("* ");
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int i,j,k;
//	for(i=0;i<10;i++)
//	{
//		for(j=9;j>i;j--)
//			printf(" ");
//		for(k=0;k<=i;k++)
//			printf("* ");
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int i,j,k;
//	for(i=0;i<=5;i++)
//	{
//		for(j=0;j<=i;j++)
//			printf("* ");
//		printf("\n");
//	}
//	for(i=0;i<5;i++)
//	{
//		for(k=5;k>i;k--)
//			printf("* ");
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int i,j,k;
//	for(i=0;i<10;i++)
//	{
//		for(k=0;k<i;k++)
//			printf(" ");
//		for(j=10;j>i;j--)
//			printf("* ");
//
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int i,j,k;
//	for(i=0;i<=5;i++)
//	{
//		for(j=5;j>i;j--)
//			printf("  ");
//		for(k=0;k<=i;k++)
//			printf("* ");
//		printf("\n");
//	}
//	for(i=0;i<5;i++)
//	{
//		for(j=0;j<=i;j++)
//			printf("  ");
//		for(k=5;k>i;k--)
//			printf("* ");
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int i,j,k;
//	for(i=0;i<10;i++)
//	{
//		for(j=10;j>i;j--)
//			printf(" ");
//		for(k=0;k<=i;k++)
//			printf("* ");
//		printf("\n");
//	}
//	for(i=0;i<4;i++)
//	{
//		printf("       *    *\n");
//	}
//	printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯");
//	return 0;
//}


//int main()
//{
//	int i,j,k,n;
//	scanf("%d",&n);
//	for(i=0;i<=n;i++)
//	{
//		for(j=n;j>i;j--)
//			printf(" ");
//		for(k=0;k<=i;k++)
//			printf("* ");
//		printf("\n");
//	}
//	for(i=0;i<n;i++)
//	{
//		for(j=0;j<=i;j++)
//			printf(" ");
//		for(k=n;k>i;k--)
//			printf("* ");
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int i,n;
//	scanf("%d",&n);
//	for(i=2;i<n;i++)
//	{
//	if(n%i==0)
//	{
//		printf("不是");
//		break;
//	}
//	else
//	{
//		printf("是");
//		break;
//	}
//	}
//		return 0;
//}

//int main()
//{
//	int i,j,sum,fs;
//	for(j=1;j<=5;j++)
//	{
//		sum=0;
//		for(i=1;i<=10;i++)
//		{
//			scanf("%d",&fs);
//			if(fs>95)
//				sum +=1;
//		}
//		printf("sum=%d\n",sum);
//	}
//	return 0;
//}

//int main()
//{
//	int i=3,j;
//	for(j=1;j<=i;j++)
//	{
//		if(i%j==0)
//			break;
//		printf("ss");
//	}
//	printf("aa");
//	return 0;
//}
//#include<conio.h>
//int main()
//{
//	char c='\0';
//	printf("请输入你的密码：\n");
//	while(c != 13)
//	{
//		c=getch();
//		putchar('*');
//		putchar(c);
//	}
//	/*putchar('\n');*/
//	return 0;
//}

//int main()
//{
//	int r,w,b,n=0;
//	for(r=0;r<=3;r++)
//	{
//		for(w=0;w<=3;w++)
//			if(r+w>=2)
//				n++;
//		
//	}
//	printf("%d\n",n);
//	return 0;
//}
//
//int main()
//{
//	int i,j;
//	for(i=1;i<10;i++)
//	{
//		for(j=1;j<=i;j++)
//			printf("%d*%d=%-2d ",i,j,i*j);
//		printf("\n");
//	}
//}

//int main()
//{
//	int a,b,n;
//	printf("请输入两个数字：\n");
//	scanf("%d%d",&a,&b);
//	while(a%b!=0)
//	{
//		n=a%b;
//		a=b;
//		b=n;
//	}
//	printf("%d\n",n);
//	return 0;
//}

//int main()
//{
//	int i=0;
//	double sum=0.0;
//	for(i=1;i<=100;i++)
//	{
//		sum=sum+1.0/i;
//	}
//	printf("%lf\n",sum);
//	return 0;
//}


//int main()
//{
//	int i,n;
//	int sum=1;
//	scanf("%d",&n);
//	for(i=1;i<=n;i++)
//	{
//		sum=sum*i;
//	}
//	printf("%d!=%d\n",n,sum);
//	return 0;
//}

//int main()
//{
//	int i=0,sg=1,j,sum=0;
//	for(j=1;j<=10;j++)
//	{
//		for(i=1,sg=1;i<=j;i++)
//		{
//			sg=sg*i;
//		}
//	sum=sum+sg;
//	}
//	printf("1!+2!+3!+.....+10!=%d\n",sum);
//	return 0;
//}

//int main()
//{
//	int i,sum=0,n=1;
//	for(i=1;i<=10;i++)
//	{
//		n=n*i;
//		sum=sum+n;
//	}
//	printf("%d\n",sum);
//}

//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int sz=sizeof(arr)/sizeof(arr[0]);
//	int left=0,right=sz-1;
//	int k=17;
//	while(left<=right)
//	{
//	int mid=(left+right)/2;
//	if(arr[mid]>k)
//		right=mid-1;
//	else if(arr[mid]<k)
//		left=mid+1;
//	else
//		{
//			printf("找到了,下标为：%d\n",mid);
//			break;
//		}
//	}
//	if(left>right)
//		printf("找不到\n");
//	return 0;
//}
#include<windows.h>
#include<stdlib.h>
//int main()
//{
//	char arr1[]="haoheng is the best man in the world";
//	char arr2[]="                                    ";
//	int sz=strlen(arr1);
//	int left=0,right=sz-1;
//	while(left<=right)
//	{
//	arr2[left]=arr1[left];
//	arr2[right]=arr1[right];
//	left++;
//	right--;
//	printf("%s\n",arr2);
//	Sleep(50);//休息一秒
//	system("cls");//执行系统命令的一个函数cls - 清空屏幕
//	}
//	printf("%s\n",arr2);
//	return 0;
//}

//int main()
//{
//	int i=0;
//	char password[20];
//	for(i;i<3;i++)
//	{
//		printf("请输入密码:");
//		scanf("%s",&password);
//		getchar();
//		if(strcmp(password,"123456")==0)
//		{
//			printf("密码正确\n");
//			break;
//		}
//		else
//			printf("密码错误\n");
//	}
//	return 0;
//}



//int sum(int m, int n)
//{
//    int i=m+1,s=0;
//    if(m<n)
//    {
//        while(i<n)
//        {
//            s=s+i;
//            i++;
//        }
//    }
//    else
//        printf("m需要小于n，错误\n");
//    return s;
//}
//
//int main()
//{
//    int m, n;
//    
//    scanf("%d %d", &m, &n);
//    printf("sum = %d\n", sum(m, n));
//    
//    return 0;
//}

//int main()
//{
//int  i = 0;
//while(1) {
//    if (i % 2 == 0) {
//        printf(" *** *** \n");
//        printf("*********\n");
//        printf(" *******\n");
//        printf("  ****\n");
//        printf("   **\n");
//    }
//	else
//    {
//        printf("\n");
//        printf("   ** ** \n");
//        printf("  *******\n");
//        printf("   *****\n");
//        printf("    **\n");
//    }
//    Sleep(5);
//    i++;
//    system("cls");
//}
//}


//#include <stdio.h>
//int main(){
//    int number;
//    int value;
//	int* p=&number;
//    number = 22;
//    value = 666;
//    printf("&number = %p\n", &number); // 0060FEAC
//	printf("&number = %d\n", *p);
//    printf("&value = %p\n", &value);   // 0060FEA8
//}
//int main()
//{
//	int i,j;
//for (i = 0; i < 3; i++) {
//    for (j = 0; j <= i; j++) {
//        printf("%d", j+1);
//    }
//    printf("\n");
//}
//}

//int main()
//{
//	int i,j;
//	for(i=0;i<10;i++)
//	{
//		printf("%-2d ",i+1);
//		for(j=0;j<i;j++)
//		{
//			printf("%-2d ",i+1);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int i,j;
//	for(i=1;i<10;i++)
//	{
//		for(j=1;j<=i;j++)
//		{
//			printf("%d*%d=%-2d ",i,j,i*j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int i,sum=0;
//	for(i=2000;i<=3000;i++)
//	{
//		if(i%4==0 && i%100!=0)
//		{
//			printf("%d ",i);
//			sum++;
//		}
//		else if(i%400==0)
//		{
//			printf("%d ",i);
//			sum++;
//		}
//	}
//	printf("\nsum=%d\n",sum);
//	return 0;
//}

int main()
{
	int a,b,n;
	scanf("%d%d",&a,&b);
	while(a%b!=0)
	{
		n=a%b;
		a=b;
		b=n;
	}
	printf("%d\n",n);
	return 0;
}
//int main()
//{
//	int i,j;
//	for(i=100;i<=200;i++)
//	{
//		for(j=2;j<i;j++)
//		{
//			if(i%j==0)
//				break;
//		}
//		if(j==i)
//			printf("%-3d ",i);
//	}
//	return 0;
//}

//int main()
//{
//	int i=0;
//	double sum=0.0;
//	int flag=1;
//	for(i=1;i<=100;i++)
//	{
//		sum += flag*(1.0/i);
//		flag=-flag;
//	}
//	printf("sum=%lf\n",sum);
//	return 0;
//}

//int main()
//{
//	int arr[]={-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
//	int i=0;
//	int max=arr[0];
//	int sz=sizeof(arr)/sizeof(arr[0]);
//	for(i=1;i<sz;i++)
//	{
//		if(arr[i]>max)
//			max=arr[i];
//	}
//	printf("%d\n",max);
//	return 0;
//}

//int main()
//{
//	int arr[]={1,2,3,4,5,6,7,8,9,10};
//	int left=0;
//	int sz=sizeof(arr)/sizeof(arr[0]);
//	int right=sz-1;
//	int k;
//	scanf("%d",&k);
//	while(left<=right)
//	{
//		int mid=(right+left)/2;
//		if(arr[mid]<k)
//			left=mid+1;
//		else if(arr[mid]>k)
//			right=mid-1;
//		else
//		{
//			printf("找到了，下标是：%d\n",mid);
//			break;
//		}
//	}
//	if(left>right)
//		printf("找不到\n");
//	return 0;
//}
#include<time.h>
#include<stdlib.h>
//void menu()
//{
//	printf("*****************************\n");
//	printf("****  1.play    2.exit   ****\n");
//	printf("*****************************\n");
//}
//void game()
//{
//	int a = 0;
//	int guess = 0;
//	a = rand() % 1000 + 1;
//	while (1)
//	{
//		printf("请输入你的数字:");
//		scanf("%d", &guess);
//		if (guess > a)
//			printf("大了\n");
//		else if (guess < a)
//			printf("小了\n");
//		else
//		{
//			printf("找到了!\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int choice = 0;
//	srand((unsigned int)time(NULL));
//	menu();
//	do
//	{
//		printf("请确认》：");
//		scanf("%d", &choice);
//		switch (choice)
//		{
//		case 1:
//			game();
//			break;
//		case 2:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("输入错误\n");
//			break;
//		}
//	} while (choice == 1);
//	return 0;
//}
//#include<string.h>
//#include<stdlib.h>
//int main()
//{
//	char input[20]={0};
//	system("shutdown -s -t 60");
//	printf("小宝贝，你的电脑60秒后会被关机！！！！\n");
//again:
//	printf("在屏幕上面打“我是猪”即可取消，否则我也没办法啊，哈哈哈！！！\n");
//	printf("请输入：");
//	scanf("%s",&input);
//	if(strcmp(input,"我是猪")==0)
//	{
//		system("shutdown -a");
//		printf("乖猪猪，不哭哦!\n");
//		printf("已经取消关机，你是猪猪^(*￣(oo)￣)^!\n");
//	}
//	else
//	{
//		printf("宝宝呀，再给你一次机会:");
//		goto again;
//	}
//	return 0;
//}