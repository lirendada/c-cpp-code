#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//int main()
//{
//	using namespace std;
//	const int arsize = 20;
//	char name[arsize];
//	char dessert[arsize];
//
//	cout << "enter your name:\n";
//	cin.getline(name,arsize);
//	cout << "enter your favourite dessert:\n";
//	cin.getline(dessert, arsize);
//	cout << "i have some delicious " << dessert << " for you," << name << ".\n";
//	return 0;
//}


//int main()
//{
//	using namespace std;
//	const int arsize = 20;
//	char name[arsize];
//	char dessert[arsize];
//
//	cout << "enter your name:\n";
//	cin.get(name, arsize).get();
//	cout << "enter your favourite dessert:\n";
//	cin.get(dessert, arsize).get();
//	cout << "i have some delicious " << dessert << " for you," << name << ".\n";
//	return 0;
//}


//int main()
//{
//	using namespace std;
//	cout << "what year was your house built?\n";
//	int year;
//	(cin >> year).get();
//	/*cin.get();*/
//	cout << "what is its street address?\n";
//	char address[80];
//	cin.getline(address, 80);
//	cout << "year built: " << year << endl;
//	cout << "address: " << address << endl;
//	cout << "done!\n";
//	return 0;
//}


//#include<string>
//int main()
//{
//	using namespace std;
//	string first{ "liren" };
//	string second;
//	second = first;
//	int len = first.size();
//	cout << len << endl;
//	cout << first << endl;
//	cout << second << endl;
//	cout << first+second << endl;
//	first = "tongtong";
//	cout << first << endl;
//	len = first.size();
//	cout << len << endl;
//	return 0;
//}



//#include<string>
//#include<cstring>
//int main()
//{
//	using namespace std;
//	char arr[20];
//	string str;
//
//	cout << strlen(arr) << endl;
//	cout << str.size() << endl;
//
//	cin.getline(arr, 20);
//	/*cin.clear();*/
//	getline(cin, str);
//	cout << arr << endl;
//	cout << str << endl;
//
//	cout << strlen(arr) << endl;
//	cout << str.size() << endl;
//	return 0;
//}


//int main()
//{
//	std::cout << R"s("(what do you want?)",he whispered.)s";
//	return 0;
//}


//#include <iostream>
//#include <locale>           //setlocale函数在locale头文件中定义
//using namespace std;
//int main()
//{
//	//使用setlocale函数将本机的语言设置为中文简体
//	//LC_ALL表示设置所有的选项（包括金融货币、小数点，时间日期格式、语言字符串的使用习惯等），chs表示中文简体
//	setlocale(LC_ALL, "chs");
//	wchar_t wt[] = L"中国伟大复兴梦";   //大写字母L告诉编译器为"中"字分配两个字节的空间
//	wcout << wt << endl;               //使用wcout来代替cout输出宽字符
//	return 0;
//}



//struct student
//{
//	char name[20];
//	float volume;
//	double price;
//};
//
//struct teacher
//{
//	std::string name;
//	int age;
//	std::string tele;
//};
//
//int main()
//{
//	using namespace std;
//	student liren = { "lirendada",13.2,25.32 };
//	cout << liren.name << endl << liren.price << endl << liren.volume << endl;
//
//	student tongtong{ "yangtong",12.2,35 };
//	cout << tongtong.name << endl << tongtong.price << endl << tongtong.volume << endl;
//
//	teacher hengge{ "lirendada",21,"15815307247" };
//	cout << hengge.name << endl << hengge.age << endl << hengge.tele << endl;
//
//	student stu[3];
//	stu[0] = liren;
//	stu[1] = tongtong;
//	cout << stu[0].name << endl << stu[0].price << endl << stu[0].volume << endl;
//	return 0;
//}



//int main()
//{
//	using namespace std;
//	int donuts = 5;
//	double cups = 4.5;
//
//	cout << "donuts = " << donuts << " and donuts address = " << &donuts << endl;
//	cout << "cups = " << cups << " and cups address = " << &cups << endl;
//	return 0;
//}


//int main()
//{
//	using namespace std;
//
//	double* p = new double[3];
//	p[0] = 1.23;
//	p[1] = 4.56;
//	p[2] = 7.89;
//	cout << p[0] << endl << p[1] << endl << p[2] << endl;
//	p = p + 1;
//	cout << p[0] << endl << p[1] << endl<<p[2];
//	p = p - 1;
//	delete[]p;
//	return 0;
//}


//int main()
//{
//	using namespace std;
//	double wages[3] = { 10000.0,20000.0,30000.0 };
//	double* ps = wages;
//	cout << sizeof(wages) << endl << sizeof(ps) << endl;
//	return 0;
//}


//#include<string>
//int main()
//{
//	using namespace std;
//	char animal[20] = "bear";
//	const char* bird = "wren";
//	char* ps;
//
//	cout << animal << " and " << bird << "\n";
//	/*cout << ps << endl;*/
//
//	cout << "Enter a kind of animal: ";
//	cin >> animal;
//
//	ps = animal;
//	cout << ps << endl;
//	cout << animal << " at " << (int*)animal << endl;
//	cout << animal << " at " << &animal << endl;
//	cout << ps << " at " << (int*)ps << endl;
//
//	ps = new char[strlen(animal) + 1];
//	strcpy(ps, animal);
//	cout << animal << " at " << (int*)animal << endl;
//	cout << ps << " at " << (int*)ps << endl;
//	return 0;
//}


//struct things
//{
//	char name[20];
//	float volume;
//	double price;
//};
//int main()
//{
//	using namespace std;
//	things* ps = new things;
//	cin.get(ps->name, 20);
//	cin >> (*ps).volume;
//	cin >> ps->price;
//	cout << (*ps).name<<endl;
//	cout << ps->volume<<endl;
//	cout << ps->price;
//	delete ps;
//	return 0;
//}


//#include<cstring>
//using namespace std;
//char* getname()
//{
//	char tmp[80];
//	cout << "enter last name: ";
//	cin >> tmp;
//	char* pn = new char[strlen(tmp) + 1];
//	strcpy(pn, tmp);
//	return pn;
//}
//char* getname()
//{
//	string tmp;
//	cout << "enter last name: ";
//	cin >> tmp;
//	string*pn=new char
//}
//int main()
//{
//	char* name;
//	name = getname();
//	cout << name << " at " << &name << "\n";
//	delete [] name;
//
//	name = getname();
//	cout << name << " at " << (int*)name << "\n";
//	delete[] name;
//	return 0;
//}


//int main()
//{
//	char ch = 0;
//	cin.get(ch);
//	while (!cin.fail())
//	{
//		cout << ch ;
//		cin.get(ch);
//	}
//	return 0;
//}


//int main()
//{
//	using namespace std;
//	char ch;
//	cin.get(ch);
//	while (ch != '.')
//	{
//		if (ch == '\n')
//			cout << ch;
//		else
//			cout << ch + 1;
//		cin.get(ch);
//	}
//	return 0;
//}



using namespace std;
int main()
{
    bool bV1 = true, bV2 = false;
    cout <<  bV1 << endl;
    cout <<  bV2 << endl;
    int nV1 = bV1, nV2 = 0;
    bV1 = nV2;
    cout <<  nV1 << endl;
    cout <<  bV1 << endl;
    return 0;
}

