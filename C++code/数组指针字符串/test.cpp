#define _CRT_SECURE_NO_WARNINGS/*
#include<iostream>
using namespace std;*/

//class Cat
//{
//public:
//	Cat(int newage = 0) :age(newage) { numOFCats++; }
//	Cat(Cat& c)
//	{
//		age = c.age;
//		numOFCats++;
//	}
//	~Cat() { numOFCats--; }
//	int getage() { return age; }
//	static void getNumOfCats()
//	{
//		cout << "the num of cats is " << numOFCats << endl;
//	}
//private:
//	static int numOFCats;
//	int age;
//};
//int Cat::numOFCats = 0;
//int main()
//{
//	Cat orangecat(2);
//	Cat::getNumOfCats();
//
//	Cat browncat(3);
//	Cat::getNumOfCats();
//	return 0;
//}


//int main()
//{
//	int line1[] = { 1,2,3 };
//	int line2[] = { 4,5,6 };
//	int line3[] = { 7,8,9 };
//	int* pline[3] = { line1,line2,line3 };
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//			cout << pline[i][j] << " ";
//		cout << endl;
//	}
//	return 0;
//}



//#include<stdio.h>
//void sort(int n, char ch[])//n为一维数组ch的长度
//{
//    int i, j;
//    char k;
//    for (i = 0; i < n - 1; i++)
//    {
//        for (j = 0; j < n - 1 - i; j++)
//        {
//            if (ch[j] > ch[j + 1])
//            {
//                k = ch[j];
//                ch[j] = ch[j + 1];
//                ch[j + 1] = k;
//            }
//        }
//    }
//    printf("从小到大排序好的字符串为\n");
//    for (i = 0; i < n; i++)
//        printf("%c  ", ch[i]);
//}
//int main()
//{
//    char ch[10];
//    printf("请输入需要排序的字符串\n");
//    scanf("%s", ch);
//    sort(10, ch);//对数组排序并输出
//    return 0;
//}


//#include<iostream>
//using namespace std;
//#define PI 3.1415926
//class SimpleCircle
//{
//public:
//	SimpleCircle(int* r1) :itsRadius(r1) { num++; }
//	SimpleCircle(const SimpleCircle& r1) { itsRadius = r1.itsRadius; num++; }
//	~SimpleCircle() { num--; }
//	double calarea() const { return PI * (*itsRadius) * (*itsRadius); }
//	void showcirclenum()const { cout << "the num of circle is " << num << endl; }
//private:
//	int* itsRadius;
//	static int num;
//};
//int SimpleCircle::num = 0;
//int main()
//{
//	int r = 3;
//	SimpleCircle a(&r);
//	cout << "the area of the circle is : " << a.calarea() << endl;
//	a.showcirclenum();
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int alphabetnum(const char* s)
//{
//	int num=0;
//	while (( * s) != '\0')
//	{
//		if (((*s) >= 'a' && (*s) <= 'z') || ((*s) >= 'A' && (*s) <= 'Z'))
//			num++;
//		s++;
//	}
//	return num;
//}
//int main()
//{
//	const char* s = "p1kj2ne1o09 asd123";
//	cout << "the alphabet num in sentence is " << alphabetnum(s) << endl;
//	return 0;
//}


//#include<iostream>
//#include<ctime>
//#include<cstdlib>
//using namespace std;
//void transarr(int (*arr)[100], int row, int col)
//{
//	for (int i = 0; i < col; i++)
//	{
//		for (int j = 0; j < row; j++)
//		{
//			cout << arr[j][i] << "  ";
//		}
//		cout << endl;
//	}
//}
//int main()
//{
//	srand((unsigned int)NULL);
//	int row = 0, col = 0, arr[100][100]={0};
//	cout << "请输入矩阵的行与列：";
//	cin >> row >> col;
//	cout << "转置前生成的矩阵为：" << endl;
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			arr[i][j] = rand() % 9 + 1;
//			cout << arr[i][j] << "  ";
//		}
//		cout << endl;
//	}
//	cout << "转置后生成的矩阵为：" << endl;
//	transarr(arr, row, col);
//	return 0;
//}



#include<iostream>
using namespace std;
class Employee
{
public:
	void setName() { cout << "请输入名字："; cin >> name; }
	void setAddr() { cout << "请输入地址："; cin >> addr; }
	void setCity() { cout << "请输入城市："; cin >> city; }
	void setpostcode() { cout << "请输入邮编："; cin >> postcode; }
	void display()
	{
		cout << "名字：" << name << endl;
		cout << "地址：" << addr << endl;
		cout << "城市：" << city << endl;
		cout << "邮编：" << postcode << endl;
	}
private:
	char name[15];
	char addr[20];
	char city[15];
	int postcode;
};
int main()
{
	Employee e1;
	e1.setName();
	e1.setAddr();
	e1.setCity();
	e1.setpostcode();
	e1.display();
	return 0;
}