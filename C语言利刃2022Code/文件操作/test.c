#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int main()
//{
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//写文件
//	/*fputs("liren", pf);*/
//	/*读文件*/
//	int ret=fgetc(pf);
//	printf("%c\n", ret);
//	ret = fgetc(pf);
//	printf("%c\n", ret);
//	ret = fgetc(pf);
//	printf("%c\n", ret);
//	ret = fgetc(pf);
//	printf("%c\n", ret);
//
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("data.txt", "w");
//	if (pf == NULL)
//		return 1;
//	//写入操作
//	fputs("liren\nlove\ntongtong", pf);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	char arr[30] = { 0 };
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//		return 1;
//	//读取操作
//	fgets(arr,6, pf);
//	printf("%s",arr);
//	fgets(arr,3, pf);
//	printf("%s", arr);
//	fgets(arr,4, pf);
//	printf("%s", arr);
//
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//
//struct S
//{
//	char arr[10];
//	int a;
//	float f;
//};
//int main()
//{
//	struct S s = { "liren",20,3.14 };
//	//对格式化的数据进行写文件
//	FILE*pf=fopen("data.txt", "w");
//	if (pf == NULL)
//	{
//		printf("fopen");
//		return 1;
//	}
//	//写文件
//	fprintf(pf, "%s  %d   %.3f", s.arr, s.a, s.f);
//
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}



//struct S
//{
//	char arr[10];
//	int a;
//	float f;
//};
//int main()
//{
//	struct S s = {0 };
//	//对格式化的数据进行写文件
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		printf("fopen");
//		return 1;
//	}
//	//读文件
//	fscanf(pf, "%s %d %f", s.arr, &(s.a), &(s.f));
//	//打印
//	fprintf(stdout,"%s  %d  %.2f", s.arr, s.a, s.f);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//struct S
//{
//	char arr[10];
//	int a;
//	float f;
//};
//int main()
//{
//	struct S s = { "liren",5,3.14 };
//	//二进制的写
//	FILE* pf = fopen("data.txt", "w");
//	if (pf == NULL)
//	{
//		printf("fopen");
//		return 1;
//	}
//	//写文件
//	fwrite(&s, sizeof(struct S), 1, pf);
//
//	printf("%s  %d  %f", s.arr, s.a, s.f);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//int main()
//{
//	struct S s = { 0 };
//	//二进制的读
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		printf("fopen");
//		return 1;
//	}
//	//写文件
//	fread(&s, sizeof(struct S), 1, pf);
//
//	printf("%s  %d  %f", s.arr, s.a, s.f);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//struct S
//{
//	char arr[20];
//	int a;
//	float f;
//};
//int main()
//{
//	struct S tmp = { "liren",21,3.14 };
//	struct S tmp1 = { 0 };
//
//	char buf[30] = { 0 };
//	sprintf(&buf, "%s %d %f", tmp.arr, tmp.a, tmp.f);
//	printf("%s\n", buf);
//
//	sscanf(buf, "%s %d %f", tmp1.arr,&(tmp1.a), &(tmp1.f));
//	printf("%s %d %f\n", tmp1.arr, tmp1.a, tmp1.f);
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	int c = fgetc(pf);
//	printf("%c\n", c);//a
//	c = fgetc(pf);
//	printf("%c\n", c);//b
//
//	fseek(pf, 3, SEEK_CUR);
//
//	c = fgetc(pf);
//	printf("%c\n", c);
//	c = fgetc(pf);
//	printf("%c\n", c);
//
//	int ret = ftell(pf);
//	printf("%d\n", ret);
//
//	rewind(pf);
//	c = fgetc(pf);
//	printf("%c\n", c);
//	ret = ftell(pf);
//	printf("%d\n", ret);
//	
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("data.txt", "wb");
//	if (pf == NULL)
//		return 1;
//
//	fwrite(&a, sizeof(int), 1, pf);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//拷贝文本data.txt
//int main()
//{
//	FILE* pfread = fopen("data.txt", "r");
//	if (pfread == NULL)
//		return 1;
//	FILE* pfwrite = fopen("data2.txt", "w");
//	if (pfwrite == NULL)
//	{
//		fclose(pfread);
//		pfread = NULL;
//		return 1;
//	}
//	int ch = 0;
//	while ((ch = fgetc(pfread)) != EOF)
//	{
//		fputc(ch, pfwrite);
//	}
//
//	fclose(pfread);
//	fclose(pfwrite);
//	pfread = NULL;
//	pfwrite = NULL;
//	return 0;
//}


//#include<windows.h>
//int main()
//{
//	FILE* pf = fopen("data.txt", "w");
//	fputs("lirendada", pf);
//
//	printf("睡眠5秒\n");
//	Sleep(5000);
//	printf("刷新缓冲区\n");
//	fflush(pf);
//	printf("再睡眠5秒\n");
//	Sleep(5000);
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("data.txt", "w+");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	char c = 0;
//	do
//	{
//		c = getchar();
//		fputc(c, pf);
//	} while (c != 'q');
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("data.txt", "w+");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}