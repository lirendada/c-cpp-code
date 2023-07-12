#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
//int main()
//{
//	int i = 0, j = 0,line=0;
//	int arr[101];
//	for (i = 2; i < 101; i++)
//	{
//		arr[i] = i;
//	}
//	for (i = 3; i < 101; i++)
//	{
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			if (arr[i] % j == 0)
//			{
//				arr[i] = 0;
//				break;
//			}
//		}
//	}
//	for (i = 2,line=0; i < 101; i++)
//	{
//		if (arr[i] != 0)
//		{
//			printf("%-4d", arr[i]);
//			line++;
//		}
//		if (line == 10)
//		{
//			printf("\n");
//			line = 0;
//		}
//	}
//	printf("\n");
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz / 2; i++)
//	{
//		int tmp = 0;
//		tmp = arr[i];
//		arr[i] = arr[sz - 1 - i];
//		arr[sz - 1 - i] = tmp;
//	}
//	for (i = 0; i < sz ; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}

//int main()
//{
//	int a[2][3] = { {1,2,3},{4,5,6} };
//	int b[3][2],i,j;
//	printf("没变之前：\n");
//	for (i = 0; i < 2; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			printf(" %d ", a[i][j]);
//			b[j][i] = a[i][j];
//		}
//		printf("\n");
//	}
//	printf("改变后：\n");
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 2; j++)
//			printf(" %d ", b[i][j]);
//		printf("\n");
//	}
//	return 0;
//}

//void yhtri(int line)
//{
//	int i = 0, j = 0;
//	int arr[20][20]={0};
//	for (i = 0; i <= line-1; i++)
//	{
//		if (i == 0)
//			arr[0][0] = 1;
//		else if (i == 1)
//		{
//			arr[1][0] = 1;
//			arr[1][1] = 1;
//		}
//		else
//		{
//			for (j = 1; j < i; j++)
//			{
//				arr[i][0] = 1;
//				arr[i][i] = 1;
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//	}
//	for (i = 0; i <line; i++)
//	{
//		for (j = line; j >i+1; j--)
//		{
//			printf("   ");
//		}
//		for (j = 0; j <= i; j++)
//		{
//			printf("%-6d", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int line = 0;
//	printf("请输入杨辉三角的行数：");
//	scanf("%d", &line);
//	yhtri(line);
//	return 0;
//}

int main()
{
	int i = 0;
	char s[9]={0};
	scanf("%s",s);
	for (i = 0; i < 9; i++)
	{
		printf("%c", s[i]);
	}
	printf("\n");
	printf("%s\n", s);
	puts(s);
	return 0;
}

//main()
//{
//	char s[9];
//	scanf("%s", s);
//	printf("%s\n", s);
//	return 0;
//}
//
//int main()
//{
//	char s[] = "abc";
//	printf("%s\n", s);
//	printf("%c\n", s[0]);
//	s[1] = 'w';
//	printf("%s\n", s);
//	return 0;
//}
//int main()
//{
//	char s[9];
//	gets(s);
//	puts(s);
//	return 0;
//}
//int main()
//{
//	int i = 0,m=0,en=0,oth=0;
//	char input[40]={0};
//	char math[40], english[40], others[40];
//	printf("请输入字符串：");
//	gets(input);
//	for (i = 0; input[i] != '\0'; i++)
//	{
//		if (input[i] >= '1' && input[i] <= '9')
//			math[m++] = input[i];
//		else if (input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z')
//			english[en++] = input[i];
//		else
//			others[oth++] = input[i];
//	}
//	for (i = 0; i < m; i++)
//	{
//		printf("%c", math[i]);
//	}
//	printf("\n");
//	for (i = 0; i < en; i++)
//	{
//		printf("%c", english[i]);
//	}
//	printf("\n");
//	for (i = 0; i < oth; i++)
//	{
//		printf("%c", others[i]);
//	}
//	printf("\n");
//	return 0;
//}


//void array(int arr[],int sz)
//{
//	int i = 0, j = 0,tmp=0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;
//		for (j = 0; j < sz - 1-i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				tmp = arr[j];
//				arr[j] = arr[j  + 1];
//				arr[j  + 1] = tmp;
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//			break;
//	}
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	int n = 0;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	array(arr,n);
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//
//int main()
//{
//	int arr1[2][3] = { {1,2,3},{4,5,6} };
//	int arr2[3][2] = { 0 };
//	int i = 0, j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 2; j++)
//		{
//			arr2[i][j] = arr1[j][i];
//			printf("%d ", arr2[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//int main()
//{
//	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
//	int i = 0, j = 0;
//	printf("改变前：\n");
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//			printf("%d ", arr[i][j]);
//		printf("\n");
//	}
//	printf("改变后：\n");
//	for (i = 0; i < 3; i++)
//	{
//		for (j = i + 1; j < 3; j++)
//		{
//			int tmp = 0;
//			tmp = arr[i][j];
//			arr[i][j] = arr[j][i];
//			arr[j][i] = tmp;
//		}
//	}
//	for (i = 0; i < 3; i++)
//	{
//		for(j=0;j<3;j++)
//			printf("%d ", arr[i][j]);
//		printf("\n");
//	}
//	return 0;
//}