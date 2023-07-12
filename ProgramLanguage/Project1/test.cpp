#define _CRT_SECURE_NO_WARNINGS
//
//
////void test(void)
////{
////	char* str = (char*)malloc(100);
////	strcpy(str, "liren");
////	free(str);
////	if (str != NULL)
////	{
////		strcpy(str, "love tongtong");
////		printf(str);
////	}
////}
////int main()
////{
////	test();
////	return 0;
////}
//
//
//
//
////int main(int argc, char* argv[])
////{
////	// 请在此输入您的代码
////	int n, ch[10001], i, a = 0, b = 0;
////	scanf("%d", &n);
////	for (i = 0; i < n; i++)
////	{
////		scanf("%d", &ch[i]);
////		if (ch[i] >= 60)
////			a++;
////		if (ch[i] >= 85)
////			b++;
////	}
////	printf("%.0f%%\n", (a * 100) / (n * 1.0));
////	printf("%.0f%%\n", (b * 100) / (n * 1.0));
////	return 0;
////}
//
//
////int main(int argc, char* argv[])
////{
////    int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
////    long date = 0;
////    scanf("%ld", &date);
////    int year = date / 10000;
////    int month = (date / 100) % 100;
////    int day = date % 100;
////    int i = 0;
////    //判断闰年
////    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
////        mon[1] = 29;
////    int arr[8] = { 0 };
////    int arr1[3] = { year,month,day };
////    for (year; year < 9321; year++)
////    {
////        for (month; month < 13; month++)
////        {
////            for (day; day < mon[month - 1]; day++)
////            {
////                for (i = 7; i >= 0; i--)
////                {
////                    arr[i] = date % 10;
////                    date = date / 10;
////                }
////                int j = 0;
////                for (j = 0; j < 4; j++)
////                {
////                    if (arr[j] == arr[7 - j])
////                        continue;
////                    else
////                        break;
////                }
////                if (arr1[2] < mon[month - 1])
////                    arr1[2]++;
////            }
////            day = 1;
////            arr1[2] = 1;
////        }
////    }
////    return 0;
////}
//
//
////#include<stdio.h>
////#include<math.h>
////int main()
////{
////    double a = 0, b = 0, c = 0;
////    double p = 0;
////    scanf("%lf %lf %lf", &a, &b, &c);
////    p = (a + b + c) /2.0;
////    printf("%.1lf", sqrt(p * (p - a) * (p - b) * (p - c)));
////    return 0;
////}
//
//
////#include <iostream>
////#include <set>
////
////using namespace std;
////
////int main()
////{
////    set<int> s;
////    s.insert(1);
////    s.insert(2);
////    s.insert(3);
////    s.insert(1);
////    cout << "set 的 size 值为 ：" << s.size() << endl;
////    cout << "set 的 maxsize的值为 ：" << s.max_size() << endl;
////    cout << "set 中的第一个元素是 ：" << *s.begin() << endl;
////    cout << "set 中的最后一个元素是:" << *s.end() << endl;
////    s.clear();
////    if (s.empty())
////    {
////        cout << "set 为空 ！！！" << endl;
////    }
////    cout << "set 的 size 值为 ：" << s.size() << endl;
////    cout << "set 的 maxsize的值为 ：" << s.max_size() << endl;
////    return 0;
////}
//
////#include<stdio.h>
////#include<math.h>
////int isprime(int n)
////{
////	int i = 0;
////	for (i = 2; i <= sqrt(n); i++)
////	{
////		if (n % i == 0)
////			return 0;
////	}
////	return 1;
////}
////int main()
////{
////	int i = 0;
////	for (i = 100; i <= 200; i++)
////	{
////		if (isprime(i))
////			printf("%d ", i);
////	}
////	return 0;
////}
//
//
////#include<stdio.h>
////int main()
////{
////	int tmp = 1, sum = 0, i = 0;
////	for (i = 1; i <= 10; i++)
////	{
////		tmp *= i;
////		sum += tmp;
////	}
////	printf("%d\n", sum);
////	return 0;
////}
//
//
////#include<stdio.h>
////#include<string.h>
////#include<windows.h>
////int main()
////{
////	char arr1[] = "*************";
////	char arr2[] = "lirendadalove";
////	int left = 0;
////	int right = strlen(arr1) - 1;
////	while (left <= right)
////	{
////		arr1[left] = arr2[left];
////		arr1[right] = arr2[right];
////		printf("%s", arr1);
////		Sleep(100);
////		system("cls");
////		left++;
////		right--;
////	}
////	printf("%s", arr1);
////	return 0;
////}
//
//
////#include<stdio.h>
////int isleapyear(int year)
////{
////	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
////		return 1;
////	return 2;
////}
////int main()
////{
////	int year = 0;
////	scanf("%d", &year);
////	int n = isleapyear(year);
////	if (n == 1)
////		printf("是闰年.\n");
////	else
////		printf("不是闰年.\n");
////	return 0;
////}
//
//
//
////#include<stdio.h>
////void tearnum(unsigned int n)
////{
////	if(n>9)
////		tearnum(n/10);
////	printf("%d ", n % 10);
////}
////int main()
////{
////	unsigned int n = 0;
////	scanf("%u", &n);
////	tearnum(n);
////	return 0;
//
//
//
////#include<stdio.h>
////unsigned int recursion(unsigned int n)
////{
////	if (n == 1)
////		return 1;
////	else
////		return n * recursion(n - 1);
////}
////unsigned int no_recursion(unsigned int n)
////{
////	unsigned int sum = 1;
////	while (n > 0)
////	{
////		sum *= n;
////		n--;
////	}
////	return sum;
////}
////int main()
////{
////	unsigned int n = 0;
////	scanf("%u", &n);
////	int a=recursion(n);
////	int b=no_recursion(n);
////	printf("%u %u", a, b);
////	return 0;
////}
//
//
////#include<stdio.h>
////int my_recursionstrlen1(char* str)
////{
////	if (*str == 0)
////		return 0;
////	else
////		return 1 + my_recursionstrlen1(str + 1);
////}
////int my_strlen2(char* str)
////{
////	int count = 0;
////	while (*str != '\0')
////	{
////		count++;
////		str++;
////	}
////	return count;
////}
////int main()
////{
////	char arr[] = "lirendada";
////	int len1 = my_recursionstrlen1(arr);
////	int len2 = my_strlen2(arr);
////	printf("%d\n", len1);
////	printf("%d\n", len2);
////	return 0;
////}
//
//
////#include<stdio.h>
////int fac(int n)
////{
////	if (n <= 2)
////		return 1;
////	else
////		return fac(n - 1) + fac(n - 2);
////}
////int nofac(int n)
////{
////	int a = 1, b = 1, c = 1;
////	while (n>2)
////	{
////		c = a + b;
////		a = b;
////		b = c;
////		n--;
////	}
////	return c;
////}
////int main()
////{
////	int n = 0;
////	scanf("%d", &n);
////	int a = fac(n);
////	int b = nofac(n);
////	printf("%d %d", a, b);
////	return 0;
////}
//
//
////#include<stdio.h>
////void reverse_string(char* str)
////{
////	if (*str != '\0')
////	{
////		reverse_string(str + 1);
////		printf("%c", *str);
////	}
////}
////int main()
////{
////	char arr[] = "abcdef";
////	reverse_string(arr);
////	return 0;
////}
//
//
////#include<stdio.h>
////int DigitSum(unsigned int n)
////{
////	int sum = 0;
////	if (n % 10 != 0)
////	{
////		sum = n % 10 + DigitSum(n / 10);
////	}
////	return sum;
////}
////int main()
////{
////	unsigned int n = 0;
////	scanf("%d", &n);
////	int a = DigitSum(n);
////	printf("%d\n", a);
////	return 0;
////}
//
//
////#include<stdio.h>
////double korder(unsigned int n, int k)
////{
////	if (k == 0)
////		return 1;
////	else if (k > 0)
////	{
////		return n * korder(n, k - 1);
////	}
////	else
////	{
////		return 1.0 / n / korder(n, -k - 1);
////	}
////}
////int main()
////{
////	unsigned n = 0;
////	int k = 0;
////	scanf("%u %d", &n, &k);
////	double a = korder(n, k);
////	printf("%lf\n", a);
////	return 0;
////}
//
//
////#include<stdio.h>
////void bubblesort(int arr[], int sz)
////{
////	int flag = 1;
////	for (int i = 0; i < sz - 1; i++)
////	{
////		for (int j = 0; j < sz - 1 - i; j++)
////		{
////			if (arr[j] > arr[j + 1])
////			{
////				int tmp = arr[j];
////				arr[j] = arr[j + 1];
////				arr[j + 1] = tmp;
////				flag = 0;
////			}
////		}
////		if (flag == 1)
////			break;
////	}
////}
////int main()
////{
////	int arr[] = { 1,3,896,13,6,64,24,61,2,84,66 };
////	int sz = sizeof(arr) / sizeof(arr[0]);
////	bubblesort(arr, sz);
////	for (int i = 0; i < sz; i++)
////		printf("%d ", arr[i]);
////	return 0;
////}
//
////#include<stdio.h>
////int* missingTwo(int* nums, int numsSize, int* returnSize) {
////    *returnSize = 2;
////    int tmp = 0;
////    for (int i = 0; i < numsSize; i++)
////        tmp ^= nums[i];
////
////    int n1 = 0;
////    while ((tmp & 1) == 0)
////    {
////        tmp >> 1;
////        n1++;
////    }
////
////    int arr1[30000] = { 0 };
////    int arr0[30000] = { 0 };
////    int n3 = 0;
////    int n4 = 0;
////    for (int i = 0; i < numsSize; i++)
////    {
////        if (((nums[i] >> n1) & 1) == 0)
////        {
////            arr0[n3] = nums[i];
////            n3++;
////        }
////        else if (((nums[i] >> n1) & 1) == 1)
////        {
////            arr1[n4] = nums[i];
////            n4++;
////        }
////    }
////
////    int tmp0 = 0, tmp1 = 0;
////    for (int i = 0; i < n3; i++)
////    {
////        tmp0 ^= arr0[i];
////    }
////    for (int i = 0; i < n4; i++)
////    {
////        tmp1 ^= arr1[i];
////    }
////    int* arr3 = (int*)malloc(sizeof(int) * 2);
////    arr3[0] = tmp0;
////    arr3[1] = tmp1;
////    return arr3;
////}
//
//
////#include<stdio.h>
////int* singleNumber(int* nums, int numsSize, int* returnSize) {
////    *returnSize = 2;
////    int tmp = 0;
////    for (int i = 0; i < numsSize; i++)
////        tmp ^= nums[i];
////
////    int n1 = 0;
////    while ((tmp & 1) == 0)
////    {
////        tmp=tmp >> 1;
////        n1++;
////    }
////
////    int tmp0 = 0, tmp1 = 0;
////    for (int i = 0; i < numsSize; i++)
////    {
////        if ((nums[i] >> n1) & 1)
////            tmp0 ^= nums[i];
////        else
////            tmp1 ^= nums[i];
////    }
////
////    int* arr3 = (int*)malloc(sizeof(int) * 2);
////    arr3[0] = tmp0;
////    arr3[1] = tmp1;
////    return arr3;
////}
////int main()
////{
////	int nums[] = { 1, 2, 1, 3, 2, 5 };
////	int sz = sizeof(nums) / sizeof(nums[0]);
////    int a = 0;
////    int* b = &a;
////    int* arr = singleNumber(nums, sz, b);
////    for (int i = 0; i < b; i++)
////    {
////        printf("%d ", arr[i]);
////    }
////	return 0;
////}
//
//
////#include<stdio.h>
////void reverse(char* str)
////{
////    char tmp = *str;
////    int len = strlen(str) - 1;
////    *str = *(str + len);
////    *(str + len) = '\0';
////    if (strlen(str+1)>1)
////        reverse(str + 1);
////    *(str + len) = tmp;
////}
////int main()
////{
////    char arr[] = "abcdefg";
////    reverse(arr);
////    printf("%s\n", arr);
////    return 0;
////}
//
//
////#include<stdio.h>
////#include<string.h>
////void reverse(char* begin, char* end)
////{
////    while (begin < end)
////    {
////        int tmp = *begin;
////        *begin = *end;
////        *end = tmp;
////        begin++;
////        end--;
////    }
////
////}
////int main()
////{
////    char arr[100] = { 0 };
////    gets(arr);
////    int n = strlen(arr);
////    int* begin = arr;
////    int* end = arr + n - 1;
////    reverse(begin,end);
////    char* cur = arr;
////    char* start = arr;
////    while (*cur != '\0')
////    {
////        while(*cur != ' ' && *cur != '\0')
////            cur++;
////        reverse(start, cur - 1);
////        start = cur + 1;
////        if (*cur != '\0')
////             cur++;
////    }
////    printf("%s\n", arr);
////    return 0;
////}
//
//
////#include<stdio.h>
////int main()
////{
////    int year = 0, month = 0, day = 0;
////    int d[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
////    while (scanf("%d%d", &year, &month) == 2)
////    {
////        day = d[month];
////        if ((month == 2)&&((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
////            day++;
////        printf("%d", day);
////        printf("\n");
////    }
////    return 0;
////}
//
//
////#include<stdio.h>
////#include<assert.h>
////char* my_strcpy(char* dst, const char* src)
////{
////	assert(dst);
////	assert(src);
////	char* tmp = dst;
////	while (*dst++ = *src++) {}
////	return tmp;
////}
////int main()
////{
////	char arr[] = "lirendada";
////	char arr1[20] = "*************";
////	printf("%s\n", my_strcpy(arr1,arr));
////}
//
//
////#include<stdio.h>
////void change(int arr[], int n)
////{
////	int src = 0, dst = 0;
////	while (src < n)
////	{
////		if (arr[src] % 2 == 1 && arr[dst] % 2 == 1)
////		{
////			src++;
////			dst++;
////		}
////		if (arr[dst] % 2 == 0)
////		{
////			if (arr[src] % 2 == 0)
////				src++;
////			else if (arr[src] % 2 == 1)
////			{
////				int tmp = arr[src];
////				arr[src] = arr[dst];
////				arr[dst] = tmp;
////				dst++;
////				src++;
////			}
////		}
////	}
////}
////int main()
////{
////	int arr[] = { 4,4,4,5,3,8,4,1 };
////	int len = sizeof(arr) / sizeof(arr[0]);
////	change(arr, len);
////	for (int i = 0; i < len; i++)
////		printf("%d ", arr[i]);
////	return 0;
////}
//
////#include<stdio.h>
////int main() {
////    int arr1[1001] = { 0 };
////    int arr2[1001] = { 0 };
////    int arr[2002] = { 0 };
////    int n = 0, m = 0;
////    scanf("%d%d", &n, &m);
////    for (int i = 0; i < n; i++)
////        scanf("%d", &arr1[i]);
////    for (int i = 0; i < m; i++)
////        scanf("%d", &arr2[i]);
////    int a1 = 0, a2 = 0, i = 0;
////    while ((a1<n) || (a2 < m))
////    {
////        if (a1 < n && a2 < m)
////        {
////            if (arr1[a1] < arr2[a2])
////            {
////                arr[i] = arr1[a1];
////                i++;
////                a1++;
////            }
////            else if (arr1[a1] > arr2[a2])
////            {
////                arr[i] = arr2[a2];
////                i++;
////                a2++;
////            }
////            else
////            {
////                arr[i]=arr1[a1];
////                arr[i + 1] = arr[i];
////                a1++;
////                a2++;
////                i += 2;
////            }
////        }
////        if (a1 == n && a2 < m)
////        {
////            arr[i] = arr2[a2];
////            a2++;
////            i++;
////        }
////        if (a1 < n && a2 == m)
////        {
////            arr[i] = arr1[a1];
////            a1++;
////            i++;
////        }
////    }
////    for (int j = 0; j < i; j++)
////        printf("%d ", arr[j]);
////    return 0;
////}
//
//
////#include<stdio.h>
////int main()
////{
////    long n = 0;
////    scanf("%ld", &n);
////    long tmp = n;
////    int count = 0;
////    while (tmp % 10)
////    {
////        count++;
////        tmp /= 10;
////    }
////    int arr[10] = { 0 };
////    for (int i = 0; i < count; i++)
////    {
////        tmp = n % 10;
////        n /= 10;
////        if (tmp % 2 == 0)
////        {
////            arr[count - 1 - i] = 0;
////        }
////        else
////            arr[count - 1 - i] = 1;
////    }
////    long ret = 1;
////    for (int i = 0; i < count; i++)
////    {
////        if (i == 0)
////            tmp = arr[count - 1 - i] * ret;
////        else
////        {
////            ret *= 10;
////            tmp = arr[count - 1 - i] * ret + tmp;
////        }
////    }
////    printf("%d\n", tmp);
////    return 0;
////}
//
//
////#include <stdio.h>
////int main()
////{
////    int a = 0, b = 0, c = 0, d = 0, e = 0;
////    for (a = 1; a <= 5; a++)
////    {
////        for (b = 1; b <= 5; b++)
////        {
////            for (c = 1; c <= 5; c++)
////            {
////                for (d = 1; d <= 5; d++)
////                {
////                    for (e = 1; e <= 5; e++)
////                    {
////                        if (((a == 3) + (b == 2) == 1) &&
////                            ((c == 1) + (d == 2) == 1) &&
////                            ((b == 2) + (e == 4) == 1) &&
////                            ((a == 1) + (e == 4) == 1))
////                        {
////                            if (a * b * c * d * e == 120)
////                            {
////                                printf("%d %d %d %d %d\n", a, b, c, d, e);
////                            }
////                        }
////                    }
////                }
////            }
////        }
////    }
////    return 0;
////}
//
//
////#include<stdio.h>
////Murder()//谋杀案
////{
////    char k;//代表凶手
////    for (k = 'A'; k <= 'D'; k++)//让凶手四人分别去验证if条件，满足条件者就是凶手
////    {
////        if (3 == ((k != 'A') + (k == 'C') + (k == 'D') + (k != 'D')))//只有满足三个人说真话，一个假话，他们之和为3这个条件，就能确定此人是凶手
////        {
////            printf("凶手是：%c\n", k);
////        }
////    }
////
////}
////int main()
////{
////    Murder();
////    return 0;
////}
//
//
////#include<stdio.h>
////#include<string.h>
////void reverse(char* arr, int left, int right)
////{
////	while (right > left)
////	{
////		char tmp = *(arr + left);
////		*(arr + left) = *(arr + right);
////		*(arr + right) = tmp;
////		left++;
////		right--;
////	}
////}
////int judge(char* arr1, char* arr2, int len)
////{
////	while (len)
////	{
////		if (strcmp(arr1, arr2) == 0)
////		{
////			return 1;
////		}
////		char tmp = arr2[0];
////		char* str = arr2;
////		int i = 1;
////		while (str[i] != '\0')
////		{
////			str[i - 1] = str[i];
////			i++;
////		}
////		str[i - 1] = tmp;
////		len--;
////	}
////	return 0;
////}
////int main()
////{
////	char arr1[20] = { 0 };
////	char arr2[20] = { 0 };
////	gets(arr1);
////	gets(arr2);
////	int len1 = strlen(arr1);
////	int len2 = strlen(arr2);
////	if (len1 != len2)
////	{
////		printf("no!\n");
////		return 0;
////	}
////	if (judge(arr1, arr2, len1))
////	{
////		printf("yes!\n");
////	}
////	else
////	{
////		printf("no!\n");
////	}
////	return 0;
//
////
////#include <stdio.h>
////#include <stdlib.h>
////#include <math.h>
////#include<string.h>
////typedef struct
////{
////    char CH;//字符
////    int weight;//权值
////    int parent, lchild, rchild;//双亲，左孩子，右孩子
////}DATA;//树的结构体
////typedef struct
////{
////    char code[30];
////    int cnt;
////}codetype;
////void Createtree(DATA* hfmTree, int N)//构建哈夫曼树，传数组hfmTree和字符个数N做参数
////{
////    int i, j, min, cmin;
////    int m, c;
////    hfmTree[0].CH = ' ';//空格用0号单元直接存（特殊处理）
////    hfmTree[0].parent = hfmTree[0].lchild = hfmTree[0].rchild = -1;
////    scanf("%d", &hfmTree[0].weight);//输入空格的权值
////    /*输入A~Z的权值初始化哈夫曼树*/
////    for (i = 1; i < N; i++)
////    {
////        hfmTree[i].CH = 'A' + i - 1;
////        hfmTree[i].parent = hfmTree[i].lchild = hfmTree[i].rchild = -1;
////        scanf("%d", &hfmTree[i].weight);
////    }
////    /*构建哈夫曼的过程注意 找到的最小值作为新根的左孩子，次小值作为右孩子*/
////    for (i = N; i < 2 * N - 1; i++)
////    {
////        min = 99999;//最小值
////        cmin = 99999;//次小值
////        m = 0; c = 0;//记录最小值和次小值的下标
////        for (j = 0; j < i; j++)
////        {
////            if (hfmTree[j].parent == -1)
////                if (hfmTree[j].weight < min)
////                {
////                    c = m;
////                    cmin = min;
////                    min = hfmTree[j].weight;
////                    m = j;
////                }
////                else if (hfmTree[j].weight < cmin)
////                {
////                    cmin = hfmTree[j].weight;
////                    c = j;
////                }
////
////        }
////        hfmTree[i].weight = min + cmin;//hfmTree[m].weight+hfmTree[c].weight;
////        hfmTree[i].CH = ' ';//方便整体输出加个字符空格
////        hfmTree[i].lchild = m;
////        hfmTree[i].rchild = c;
////        hfmTree[m].parent = i;
////        hfmTree[c].parent = i;
////        hfmTree[i].parent = -1;//新结点的双亲没有为-1
////
////    }
////}
////void Hfmcode(DATA* hfmTree, codetype* codeFile, int N)//哈夫曼编码
////{
////    int i, p, c;
////    codetype S;
////    for (i = 0; i < N; i++)//对N的字符进行编码
////    {
////        c = i;//意思是将树中的第一个字符的下标给c暂存
////        p = hfmTree[c].parent;//找得到c下标字符的双亲（是地址）给p暂存
////        S.cnt = N;//把cnt的值初始化为N，后续再用数组(S->code[])存字符的编码时,倒着存
////        S.code[N] = '\0';
////        while (p != -1)//要将第i个字符从它自身找到它的双亲为止
////        {
////            if (hfmTree[p].lchild == c)//第i个字符是双亲p的左孩子，S.code[]中存‘0’；
////                S.code[--S.cnt] = '0';
////            else//否则存‘1’
////                S.code[--S.cnt] = '1';
////            c = p;
////            p = hfmTree[c].parent;
////        }
////
////        codeFile[i] = S;//第i个字符的编码存入codeFile
////    }
////
////}
////void Decode(DATA* hfmTree, char* ToBeTran, int N)//解码过程
////{
////    int i, ct = 0;
////    char ch;
////    scanf("%c", &ch);
////    i = 2 * N - 2;//根结点的小标（地址）为2*N-2
////    while (ch != '#')//#结束后不再翻译
////    {
////        if (ch == '0')//‘0’判断左走
////            i = hfmTree[i].lchild;
////        else if (ch == '1')//‘1’判断右走
////            i = hfmTree[i].rchild;
////        if (hfmTree[i].lchild == -1 || hfmTree[i].rchild == -1)//从根结点一直找到叶子
////        {
////            ToBeTran[ct++] = hfmTree[i].CH;
////            i = 2 * N - 2;//译完一段编码后置为头结点继续翻译
////        }
////        scanf("%c", &ch);
////    }
////    if ((hfmTree[i].lchild != -1 || hfmTree[i].rchild != -1) && i != 2 * N - 2)
////        printf("编码有误！");
////    ToBeTran[ct] = '\0';
////
////}
////int main()
////{
////    int N;
////    int i, j;
////    //char str[]="THIS PROGRAM IS MY FAVORITE";
////    char str[200];
////    char* ToBeTran, c;
////    DATA* hfmTree;
////    codetype* codeFile;//定义一个存编码信息的数组，大小动态分配
////
////    printf("字符集大小:");
////    scanf("%d", &N);//字符个数
////    ToBeTran = (char*)malloc(sizeof(char) * 40);
////    codeFile = (codetype*)malloc(sizeof(codetype) * N);//给codeFile数组分配空间
////    hfmTree = (DATA*)malloc(sizeof(DATA) * (2 * N - 1));//哈夫曼树结点个数
////    printf("输入空格和A~Z字母的频度：\n");
////    Createtree(hfmTree, N);//建树
////    Hfmcode(hfmTree, codeFile, N);//编码
////    /*for (i = 0; i<N; i++)
////    {
////        printf("%c字符的编码：", hfmTree[i].CH);
////        printf("%s", codeFile[i].code + codeFile[i].cnt);
////        printf("\n");
////    }*/
////    scanf("%c", &c);//接收回车符的不然会被gets(str)这句录入
////    printf("请输入需要编码的字符串：\n");
////    gets(str);
////    printf("\n");
////    printf("该字符串编码为：\n");
////    for (i = 0; i < strlen(str); i++)
////    {
////        if (str[i] == ' ')
////            printf("%s", codeFile[0].code + codeFile[0].cnt);
////        else
////            printf("%s", codeFile[str[i] - 'A' + 1].code + codeFile[str[i] - 'A' + 1].cnt);//由于是倒着存的所以正着输出时要找到起始点
////    }
////    printf("\n\n");
////    printf("输入需要译文的编码（以#号结束）：\n");
////    Decode(hfmTree, ToBeTran, N);
////    printf("\n");
////    printf("编码译文为：\n");
////    printf("%s", ToBeTran);
////    return 0;
////}
////
//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//#include <algorithm>
//using namespace std;
//struct node
//{
//	int _val;
//	char _c;
//	node* _left;
//	node* _right;
//	node(int val, char c = '*')
//	{
//		_val = val;
//		_c = c;
//		_left = NULL;
//		_right = NULL;
//	}
//};
//struct compareval
//{
//	bool operator()(const node* n1, const node* n2)
//	{
//		return n1->_val > n2->_val;
//	}
//};
//class huffman
//{
//public:
//	// 构建哈夫曼树
//	huffman(const int& n, map<char, int>& countmap)
//	{
//		// 将节点按值的大小从大到小存到_v中
//		_v.resize(n);
//		int i = 0;
//		map<char, int>::iterator it = countmap.begin();
//		while (it != countmap.end())
//		{
//			_v[i] = new node(it->second, it->first);
//			++i;
//			++it;
//		}
//		std::sort(_v.begin(), _v.end(), compareval());
//
//		// 构建
//		while (_v.size() >= 2)
//		{
//			// 将新节点左右孩子链接上
//			node* newnode = new node(_v[_v.size() - 1]->_val + _v[_v.size() - 2]->_val);
//			newnode->_left = _v[_v.size() - 1];
//			newnode->_right = _v[_v.size() - 2];
//
//			// 将两个已经链接完成的子节点从vector中pop掉
//			_v.pop_back();
//			_v.pop_back();
//
//			// 将新节点newnode加入到vector中，并重新排序
//			_v.push_back(newnode);
//			std::sort(_v.begin(), _v.end(), compareval());
//		}
//
//		inorder(_v[0]);
//	}
//
//	// 哈夫曼树编码
//	string huffmancode(string& txt)
//	{
//		// 进行哈夫曼编码
//		huffmancode(_v[0], "");
//
//		string tmp;
//		// 根据原来的字符串txt打印出其哈夫曼编码
//		for (size_t i = 0; i < txt.size(); ++i)
//		{
//			tmp += _s[txt[i]];
//		}
//		return tmp;
//	}
//
//	void huffmancode(node* root, string s)
//	{
//		if (root == NULL)
//			return;
//
//		if (root->_left == NULL && root->_right == NULL)
//		{
//			_s[root->_c] = s;
//		}
//
//		huffmancode(root->_left, s + '0');
//		huffmancode(root->_right, s + '1');
//	}
//
//	// 哈夫曼树解码
//	string huffmandecode(string& txt)
//	{
//		string tmp;
//		for (size_t i = 0; i < txt.size(); )
//		{
//			node* cur = _v[0];
//
//			// 从根开始遍历，直到读到叶子节点
//			while (!(cur->_left == NULL && cur->_right == NULL))
//			{
//				if (txt[i] == '0')
//					cur = cur->_left;
//				else
//					cur = cur->_right;
//				++i;
//			}
//
//			tmp += cur->_c;
//		}
//		return tmp;
//	}
//
//	void inorder(node* node)
//	{
//		if (node == NULL)
//			return;
//
//		inorder(node->_left);
//		cout << node->_c << ":" << node->_val << " ";
//		inorder(node->_right);
//	}
//	
//private:
//	vector<node*> _v; // 存放根节点
//	map<char, string> _s; // 存放哈夫曼编码后每个字符的编码
//};
//
//void count(const string& s, int& n, map<char, int>& countmap)
//{
//	for (size_t i = 0; i < s.size(); ++i)
//		countmap[s[i]]++;
//
//	map<char, int>::iterator it = countmap.begin();
//	while (it != countmap.end())
//	{
//		n++;
//		cout << it->first << " 出现 " << it->second << " 次" << endl;
//		++it;
//	}
//}
// 
//int main()
//{
//	string s;
//	getline(cin, s);
//
//	// 统计电文中字符的出现频率 
//	int validnum = 0;
//	map<char, int> countmap;
//	count(s, validnum, countmap);
//
//	// 创建哈夫曼树 
//	huffman hm(validnum, countmap);
//	cout << endl;
//
//	// 打印出对应的哈夫曼树编码
//	cout << "哈夫曼编码: " << hm.huffmancode(s) << endl;
//	cout << "编码长度为：" << hm.huffmancode(s).size() << endl;
//
//	// 打印出对应的哈夫曼树编码的解码
//	string tmp = hm.huffmancode(s);
//	cout << "哈夫曼编码的解码：" << hm.huffmandecode(tmp) << endl;
//	return 0;
//}


//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	FILE* in = fopen("sort.in", "r");
//	FILE* out = fopen("sort.out", "w");
//	if (!in || !out)
//		exit(-1);
//
//	char arr[50][50];
//	memset(arr, 0, sizeof(arr)); // 初始化为0，这样子后面就不用去设置\0 
//	int k = 0; // 表示单词的个数 
//	// 将每个单词放到数组中 
//	while (!feof(in))
//	{
//		char tmp;
//		int i = 0;
//		while (!feof(in))
//		{
//			tmp = fgetc(in);
//			if (tmp == ' ' || tmp == '\n' || tmp == -1)
//			{
//				break;
//			}
//			arr[k][i++] = tmp;
//		}
//		k++;
//	}
//	// 进行排序,这里使用冒泡
//	int i, j;
//	for (i = 0; i < k - 1; ++i)
//	{
//		for (j = 0; j < k - 1 - i; ++j)
//		{
//			if (strcmp(arr[j], arr[j + 1]) > 0)
//			{
//				char tmp[100];
//				memset(tmp, 0, 50);
//				strcpy(tmp, arr[j]);
//				strcpy(arr[j], arr[j + 1]);
//				strcpy(arr[j + 1], tmp);
//			}
//		}
//	}
//
//	for (i = 0; i < k; ++i)
//	{
//		while (strcmp(arr[i], arr[i + 1]) == 0)
//			i++;
//
//		if (i < k - 1)
//			fprintf(out, "%s ", arr[i]);
//		else
//			fprintf(out, "%s", arr[i]);
//	}
//
//	fclose(in);
//	fclose(out);
//	return 0;
//}

//#include <iostream>
//#include <unordered_map>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//    int findLHS(vector<int>& nums) {
//        unordered_map<int, int> hash;
//        for (size_t i = 0; i < nums.size(); ++i)
//            hash[nums[i]]++;
//        int Max = 0;
//        for (auto e : hash)
//        {
//            if (hash[e.first + 1] != 0)
//            {
//                Max = std::max(Max, e.second + hash[e.first + 1]);
//            }
//        }
//        return Max;
//    }
//};
//int main()
//{
//    vector<int> v{1,3,5,7,9,11,13,15,17};
//    Solution s;
//    cout << s.findLHS(v);
//	return 0;
//}
//
//#include <algorithm>
//#include <list>
//#include <iostream>
//using namespace std;
//
//namespace bit
//{
//	class string
//	{
//	public:
//		typedef char* iterator;
//		iterator begin()
//		{
//			return _str;
//		}
//
//		iterator end()
//		{
//			return _str + _size;
//		}
//
//		string(const char* str = "")
//			:_size(strlen(str))
//			, _capacity(_size)
//		{
//			cout << "string(char* str)" << endl;
//
//			_str = new char[_capacity + 1];
//			strcpy(_str, str);
//		}
//
//		// s1.swap(s2)
//		void swap(string& s)
//		{
//			::swap(_str, s._str);
//			::swap(_size, s._size);
//			::swap(_capacity, s._capacity);
//		}
//
//		// 拷贝构造
//		string(const string& s)
//			:_str(nullptr)
//			, _size(0)
//			, _capacity(0)
//		{
//			cout << "string(const string& s) -- 深拷贝" << endl;
//
//			string tmp(s._str);
//			swap(tmp);
//		}
//
//		// 移动构造
//		string(string&& s)
//			:_str(nullptr)
//			, _size(0)
//			, _capacity(0)
//		{
//			cout << "string(string&& s) -- 资源转移" << endl;
//
//			this->swap(s);
//		}
//
//		// 移动赋值
//		string& operator=(string&& s)
//		{
//			cout << "string& operator=(string&& s) -- 转移资源" << endl;
//			swap(s);
//
//			return *this;
//		}
//
//		string& operator=(const string& s)
//		{
//			cout << "string& operator=(string s) -- 深拷贝" << endl;
//			string tmp(s);
//			swap(tmp);
//
//			return *this;
//		}
//
//		~string()
//		{
//			//cout << "~string()" << endl;
//
//			delete[] _str;
//			_str = nullptr;
//		}
//
//		char& operator[](size_t pos)
//		{
//			return _str[pos];
//		}
//
//		void reserve(size_t n)
//		{
//			if (n > _capacity)
//			{
//				char* tmp = new char[n + 1];
//				strcpy(tmp, _str);
//				delete[] _str;
//				_str = tmp;
//
//				_capacity = n;
//			}
//		}
//
//		void push_back(char ch)
//		{
//			if (_size >= _capacity)
//			{
//				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
//				reserve(newcapacity);
//			}
//
//			_str[_size] = ch;
//			++_size;
//			_str[_size] = '\0';
//		}
//
//		//string operator+=(char ch)
//		string& operator+=(char ch)
//		{
//			push_back(ch);
//			return *this;
//		}
//
//		string operator+(char ch)
//		{
//			string tmp(*this);
//			push_back(ch);
//
//			return tmp;
//		}
//
//		const char* c_str() const
//		{
//			return _str;
//		}
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity; // 不包含最后做标识的\0
//	};
//
//	bit::string to_string(int value)
//	{
//		bit::string str;
//		while (value)
//		{
//			int val = value % 10;
//			str += ('0' + val);
//			value /= 10;
//		}
//		reverse(str.begin(), str.end());
//
//		return str;
//	}
//}
//
//int main()
//{
//	bit::string s("11111");
//	list<bit::string> lt;
//	lt.push_back(s);
//	lt.push_back("123344");
//	return 0;
//}

#include <iostream>
using namespace std;
//class CParent
//{
//public: virtual void Intro()
//{
//	printf("I'm a Parent, "); Hobby();
//}
//	  virtual void Hobby()
//	  {
//		  printf("I like football!");
//	  }
//};
//class CChild : public CParent {
//public: virtual void Intro()
//{
//	printf("I'm a Child, "); Hobby();
//}
//	  virtual void Hobby()
//	  {
//		  printf("I like basketball!\n");
//	  }
//};
//int main()
//{
//	CChild* pChild = new CChild();
//	CParent* pParent = (CParent*)pChild;
//	pParent->Intro();
//	return 0;
//}
//#include <vector>
//int getMid(vector<int>& arr, int left, int right)
//{
//    int mid = left + (right - left) / 2;
//    if (arr[left] < arr[mid])
//    {
//        if (arr[mid] < arr[right])
//            return mid;
//        else if (arr[left] > arr[right])
//            return left;
//        else
//            return right;
//    }
//    else // arr[left] >= arr[mid]
//    {
//        if (arr[mid] > arr[right])
//            return mid;
//        else if (arr[left] < arr[right])
//            return left;
//        else
//            return right;
//    }
//}
//int quickMethod(vector<int>& arr, int left, int right)
//{
//    int mid = getMid(arr, left, right);
//    swap(arr[left], arr[mid]);
//
//    int hole = arr[left];
//    while (left < right)
//    {
//        while (left < right && arr[right] >= hole)
//            right--;
//        arr[left] = arr[right];
//
//        while (left < right && arr[left] <= hole)
//            left++;
//        arr[right] = arr[left];
//    }
//    arr[left] = hole;
//    return left;
//}
//void insert(vector<int>& nums, int left, int n)
//{
//    for (int i = left; i < n - 1; ++i)
//    {
//        int end = i;
//        int tmp = nums[end + 1];
//        while (end >= left)
//        {
//            if (nums[end] > tmp)
//            {
//                nums[end + 1] = nums[end];
//                end--;
//            }
//            else
//                break;
//        }
//        nums[end + 1] = tmp;
//    }
//}
//void quick(vector<int>& arr, int left, int right)
//{
//    if (left >= right)
//        return;
//
//    if (right - left > 10)
//    {
//        int key = quickMethod(arr, left, right);
//        quick(arr, left, key - 1);
//        quick(arr, key + 1, right);
//    }
//    else
//        insert(arr, left, right + 1);
//}
//int main()
//{
//	vector<int> v{ -74,48,-20,2,10,-84,-5,-9,11,-24,-91,2,-71,64,63,80,28,-30,-58,-11,-44,-87,-22,54,-74,-10,-55,-28,-46,29,10,50,-72,34,26,25,8,51,13,30,35,-8,50,65,-6,16,-2,21,-78,35,-13,14,23,-3,26,-90,86,25,-56,91,-13,92,-25,37,57,-20,-69,98,95,45,47,29,86,-28,73,-44,-46,65,-84,-96,-24,-12,72,-68,93,57,92,52,-45,-2,85,-63,56,55,12,-85,77,-39 };
//	quick(v, 0, v.size() - 1);
//    for (auto e : v)
//    {
//        cout << e << " ";
//    }
//}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int n = 0;
    cin >> n;
    vector<vector<int>> vv(n + 2, vector<int>(n + 2, -1));
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j <= i; ++j)
            cin >> vv[i][j];
    }
    for (int i = 0; i < n + 2; ++i)
    {
        for (int j = 0; j < n + 2; ++j)
            cout << vv[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    for (int i = 2; i < n + 1; ++i)
    {
        if (i % 2 == 0)
        {
            int a1 = i / 2;
            int a2 = i / 2 + 1;
            int up = vv[i - 1][a1];
            vv[i][a1] += up;
            vv[i][a2] += up;
        }
        else
        {
            int a = i / 2 + 1;
            vv[i][a] = max(vv[i - 1][a - 1], vv[i - 1][a]) + vv[i][a];
        }
    }

    for (int i = 0; i < n + 2; ++i)
    {
        for (int j = 0; j < n + 2; ++j)
            cout << vv[i][j] << " ";
        cout << endl;
    }

    if (n % 2 == 0)
        cout << max(vv[n][n / 2], vv[n][n / 2 + 1]) << endl;
    else
        cout << vv[n][n / 2 + 1] << endl;
    return 0;
}