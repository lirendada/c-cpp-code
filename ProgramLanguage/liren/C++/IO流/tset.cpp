#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <fstream>
#include "date.h"
#include <sstream>
using namespace std;

//class Date
//{
//    friend ostream& operator << (ostream& out, const Date& d);
//    friend istream& operator >> (istream& in, Date& d);
//public:
//    Date(int year = 1, int month = 1, int day = 1)
//        :_year(year)
//        , _month(month)
//        , _day(day)
//    {}
//    operator bool()
//    {
//        // 这里是随意写的，假设输入_year为0，则结束
//        if (_year == 0)
//            return false;
//        else
//            return true;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//istream& operator >> (istream& in, Date& d)
//{
//    in >> d._year >> d._month >> d._day;
//    return in;
//}
//ostream& operator << (ostream& out, const Date& d)
//{
//    out << d._year << " " << d._month << " " << d._day;
//    return out;
//}
//
//// C++ IO流，使用面向对象+运算符重载的方式
//// 能更好的兼容自定义类型，流插入和流提取
//int main()
//{
//    // 自动识别类型的本质--函数重载
//    // 内置类型可以直接使用--因为库里面ostream类型已经实现了
//    int i = 1;
//    double j = 2.2;
//    cout << i << endl;
//    cout << j << endl;
//    // 自定义类型则需要我们自己重载<< 和 >>
//    Date d(2022, 4, 10);
//    cout << d;
//    while (d)
//    {
//        cin >> d;
//        cout << d;
//    }
//    return 0;
//}

//struct Student
//{
//	string _name = "liren";
//	int _age = 20;
//};
//
//
////int main()
////{
////	Student s;
////	cin >> s._name >> s._age;
////	cout << "名字：" << s._name << " 年龄：" << s._age << endl;
////
////	scanf("%s%d", s._name.c_str(), &s._age);
////	printf("名字：%s 年龄：%d\n", s._name.c_str(), s._age);
////}
//
//
//int main()
//{
//	Student s;
//
//	cin >> s._name >> s._age;
//	printf("名字：%s 年龄：%d\n", s._name.c_str(), s._age);
//	cout << "名字：" << s._name << " 年龄：" << s._age << endl;
//
//	s._name.resize(100);
//
//	scanf("%s%d", s._name.c_str(), &s._age);
//	printf("名字：%s 年龄：%d\n", s._name.c_str(), s._age);
//	cout << "名字：" << s._name << " 年龄：" << s._age << endl;
//
//	return 0;
//}



// 使用文件IO流用文本及二进制方式演示读写配置文件
//struct ServerInfo
//{
//    char _ip[32]; // ip
//    int _port; // 端口
//};
//struct ConfigManager
//{
//public:
//    ConfigManager(const char* configfile = "liren.config")
//        :_configfile(configfile)
//    {}
//
//    void WriteBin(const ServerInfo& info)
//    {
//        // 这里注意使用二进制方式打开写
//        ofstream ofs(_configfile, ifstream::out | ifstream::binary);
//        ofs.write((const char*)&info, sizeof(ServerInfo));
//    }
//
//    void ReadBin(ServerInfo& info)
//    {
//        // 这里注意使用二进制方式打开读
//        ifstream ifs(_configfile, ifstream::in | ifstream::binary);
//        ifs.read((char*)&info, sizeof(ServerInfo));
//    }
//
//    // C++文件流的优势就是可以对内置类型和自定义类型，都使用
//    // 一样的方式，去流插入和流提取数据
//    // 当然这里自定义类型Date需要重载>> 和 <<
//    // istream& operator >> (istream& in, Date& d)
//    // ostream& operator << (ostream& out, const Date& d)
//
//    void WriteText(const ServerInfo& info)
//    {
//        // 这里会发现IO流写整形比C语言那套就简单多了，
//        // C 语言得先把整形itoa再写
//        ofstream ofs(_configfile);
//        ofs << info._ip << endl << info._port << endl;
//    }
//
//    void ReadText(ServerInfo& info)
//    {
//        // 这里会发现IO流读整形比C语言那套就简单多了，
//        // C 语言得先读字符串，再atoi
//        ifstream ifs(_configfile);
//        ifs >> info._ip >> info._port;
//    }
//private:
//    string _configfile; // 配置文件
//};
//
//int main()
//{
//    ConfigManager cfgMgr;
//    ServerInfo winfo = { "192.0.0.1", 80 };
//    ServerInfo rdinfo;
//
//    // 二进制读写
//    cfgMgr.WriteBin(winfo);
//    cfgMgr.ReadBin(rdinfo);
//    cout << rdinfo._ip << endl;
//    cout << rdinfo._port << endl;
//
//    // 文本读写
//    cfgMgr.WriteText(winfo);
//    cfgMgr.ReadText(rdinfo);
//    cout << rdinfo._ip << endl;
//    cout << rdinfo._port << endl;
//    return 0;
//}

//int main()
//{
//    int a = 12345678;
//    string sa;
//
//    // 将一个整形变量转化为字符串，存储到string类对象中
//    stringstream s;
//    s << a;
//    s >> sa;
//
//    // clear()
//    // 注意多次转换时，必须使用clear将上次转换状态清空掉
//    // stringstreams在转换结尾时(即最后一个转换后),会将其内部状态设置为badbit
//    // 因此下一次转换是必须调用clear()将状态重置为goodbit才可以转换
//    // 但是clear()不会将stringstreams底层字符串清空掉
//
//    // s.str("");
//    // 将stringstream底层管理string对象设置成"", 
//    // 否则多次转换时，会将结果全部累积在底层string对象中
//
//    s.str("");
//    s.clear();  // 清空s, 不清空会转化失败
//    double d = 12.34;
//    s << d;
//    s >> sa;
//
//    string sValue;
//    sValue = s.str(); // str()方法：返回stringsteam中管理的string类型
//    cout << sValue << endl;
//    return 0;
//}


//int main()
//{
//    stringstream sstream;
//
//    // 将多个字符串放入 sstream 中
//    sstream << "first" << " " << "string,";
//    sstream << " second string";
//    cout << "strResult is: " << sstream.str() << endl;
//
//    // 清空 sstream
//    sstream.str("");
//    sstream << "third string";
//    cout << "After clear, strResult is: " << sstream.str() << endl;
//
//    return 0;
//}

struct ChatInfo
{
    string _name; // 名字
    int _id; // id
    Date _date; // 时间
    string _msg; // 聊天信息
};

int main()
{
    // 结构信息序列化为字符串
    ChatInfo winfo = { "张三", 135246, { 2022, 4, 10 }, "晚上一起看电影吧" };
    stringstream oss;
    oss << winfo._name << " " << winfo._id << " " << winfo._date << " " << winfo._msg;
    string str = oss.str();
    cout << str << endl << endl;

    // 我们通过网络这个字符串发送给对象，实际开发中，信息相对更复杂，
    // 一般会选用Json、xml等方式进行更好的支持
    // 字符串解析成结构信息
    ChatInfo rInfo;
    stringstream iss(str);
    iss >> rInfo._name >> rInfo._id >> rInfo._date >> rInfo._msg;
    cout << "-------------------------------------------------------" << endl;
    cout << "姓名：" << rInfo._name << "(" << rInfo._id << ") ";
    cout << rInfo._date << endl;
    cout << rInfo._name << ":>" << rInfo._msg << endl;
    cout << "-------------------------------------------------------" << endl;

    return 0;
}