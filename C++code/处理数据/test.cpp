#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

//#include<climits>
//int main()
//{
//	using namespace std;
//	int n_int = INT_MAX;
//	short n_short = SHRT_MAX;
//	long n_long = LONG_MAX;
//	long long n_llong = LLONG_MAX;
//	
//	cout << "int is " << sizeof(int) << " bytes." << endl;
//	cout << "short is " << sizeof(n_short) << " bytes." << endl;
//	cout << "long is " << sizeof(n_long) << " bytes." << endl;
//	cout << "long long is " << sizeof(n_llong) << " bytes." << endl;
//	cout << endl;
//
//	cout << "Maximum values:" << endl;
//	cout << "int: " << n_int << endl;
//	cout << "short: " << n_short << endl;
//	cout << "long: " << n_long << endl;
//	cout << "long long: " << n_llong << endl << endl;
//
//	cout << "Minimum int value = " << INT_MIN << endl;
//	cout << "Minimum short value = " << SHRT_MIN << endl;
//	cout << "Bits per byte = " << CHAR_BIT << endl;
//	return 0;
//}



//int main()
//{
//	int emus{ 3 };
//	int emus1{  };
//	float emus2{ 3.14 };
//	std::cout << emus << std::endl;
//	std::cout << emus1 << std::endl;
//	std::cout << emus2 << std::endl;
//	return 0;
//}



//#define ZERO 0
//#include<climits>
//int main()
//{
//	using namespace std;
//	short sam = SHRT_MAX;
//	unsigned short sue = sam;
//
//	cout << "Sam has " << sam << " dollars and Sue has " << sue;
//	cout << " dollars deposited." << endl << "Add $1 to each account." << endl << "Now ";
//	sam = sam + 1;
//	sue = sue + 1;
//	cout << "Sam has " << sam << " dollars and Sue has " << sue;
//	cout << " dollars deposited.\nPoor Sam!" << endl;
//	sam = ZERO;
//	sue = ZERO;
//	cout << "Sam has " << sam << " dollars and Sue has " << sue;
//	cout << " dollars deposited." << endl;
//	cout << "Take $1 from each account." << endl << "Now ";
//	sam = sam - 1;
//	sue = sue - 1;
//	cout << "Sam has " << sam << " dollars and Sue has " << sue;
//	cout << " dollars deposited.\n" << "Lucky Sue!" << endl;
//}


//int main()
//{
//	using namespace std;
//	int chest = 42;
//	int waist = 0x42;
//	int inseam = 042;
//
//	cout << "Monsieur cuts a striking figure!\n";
//	cout << "chest = " << chest << "(42 in decimal)\n";
//	cout << "waist = " << waist << "(0x42 in hex)\n";
//	cout << "inseam = " << inseam << "(042 in octal)\n";
//	return 0;
//}


//int main()
//{
//	using namespace std;
//	int chest = 42;
//	int waist = 0x42;
//	int inseam = 042;
//
//	cout << "Monsieur cuts a striking figure!\n";
//	cout << "chest = " << chest << "(42 in decimal)\n";
//	cout << hex;
//	cout << "waist = " << waist << "(0x42 in hex)\n";
//	cout << oct;
//	cout << "inseam = " << inseam << "(042 in octal)\n";
//	return 0;
//}


//int main()
//{
//	using namespace std;
//	char ch1;
//	int ch2;
//
//	cout << "Enter a character: ";
//	cin >> ch1;
//	cout << "Hola! ";
//	cout << "Thank you for the " << ch1 << " character." << endl;
//	cout << "Enter a character: ";
//	cin >> ch2;
//	cout << "Hola! ";
//	cout << "Thank you for the " << ch2 << " character." << endl;
//	return 0;
//}


//int main()
//{
//	using namespace std;
//	char ch = 'W';
//	int i = ch;
//	cout << "The ASCII code for " << ch << " is " << i << endl;
//
//	cout << "Add one to the character code:" << endl;
//	ch = ch + 1;
//	i = ch;
//	cout << "The ASCII code for " << ch << " is " << i << endl;
//
//	cout << "Displaying char ch using cout.put(ch):";
//	cout.put(ch);
//
//	cout.put('!');
//	cout << endl << "Done" << endl;
//	return 0;
//}


//int main()
//{
//	using namespace std;
//	cout.put('$');
//	cout << "hi\x1a there\n";
//	cout << "\032";
//	return 0;
//}


//int main()
//{
//	using namespace std;
//	cout << "enter your agent code:_______\b\b\b\b\b\b\b";
//	long code;
//	cin >> code;
//	cout << "\ayou entered " << code << "……\n";
//	return 0;
//}


//int main()
//{
//	int k\u00F6rper;
//	std::cout << "Let them eat g\u00E2teau.\n";
//	return 0;
//}


//int main()
//{
//	using namespace std;
//	wchar_t bob = L'P';
//	wcout << L"tall" << endl;
//	return 0;
//}


//int main()
//{
//	using namespace std;
//	char16_t ch1 = u'r';
//	char32_t ch2 = U'\U0000222A';
//	cout << ch1 << endl;
//	cout << ch2 << endl;
//	return 0;
//}


//int main()
//{
//	using namespace std;
//	bool is_ready = true;
//	int ans = true;
//	int promise = false;
//	cout << is_ready << endl;
//	cout << ans << endl;
//	cout << promise << endl;
//	return 0;
//}


//int main()
//{
//	using namespace std;
//	const int toes=100;
//	toes = 10;
//	return 0;
//}


//int main()
//{
//	using namespace std;
//	cout.setf(ios_base::fixed, ios_base::floatfield);
//	float tub = 10.0 / 3.0;
//	double mint = 10.0 / 3.0;
//	const float million = 1.0e6;
//
//	cout << "tub= " << tub;
//	cout << ", a million tubs=" << million * tub;
//	cout << ",\nand ten million tubs = ";
//	cout << 10 * million * tub << endl;
//
//	cout << "mint= " << mint << " and a million mints = ";
//	cout << million * mint << endl;
//	return 0;
//}


//int main()
//{
//	using namespace std;
//	float a = 2.34E+22f;
//	float b = a + 1.0f;
//
//	cout << "a= " << a << endl;
//	cout << "b-a= " << b - a << endl;
//	return 0;
//}


//int main()
//{
//	using namespace std;
//	cout.setf(ios_base::fixed, ios_base::floatfield);
//	float tree = 3;
//	int guess{ 2.5433 };//报错，与{}的用法有关
//	int debt = 7.2e12;
//	cout << "tree=" << tree << endl;
//	cout << "guess=" << guess << endl;
//	cout << "debt=" << debt << endl;
//	return 0;
//}


//int main()
//{
//	using namespace std;
//	cout << (int)'Q';
//	return 0;
//}


int main()
{
	using namespace std;
	int auks, bats, coots;

	auks = 19.99 + 11.99;
	bats = (int)19.99 + (int)11.99;
	coots = int(19.99) + int(11.99);

	cout << "auks = " << auks << ",bats = " << bats << ",coots = " << coots << endl;

	char ch = 'Z';
	cout << "The code for " << ch << " is ";
	cout << int(ch) << endl;
	cout << "Yes,the code is ";
	cout << static_cast<int>(ch) << endl;
	return 0;
}