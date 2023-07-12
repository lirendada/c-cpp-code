#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <queue>
#include<list>
#include <functional> // greater算法的头文件
#include<deque>
#include "stack.h"
#include "queue.h"
#include "priority_queue.h"
using namespace std;

void test_queue() {
    /* 创建一个存储整型的队列 */
    queue<int> Q;

    /* 入队 */
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);

    /* 打印队列 */
    while (!Q.empty()) {             // 如果队列不为空则进入循环
        cout << Q.front() << " ";    // 打印队头元素
        Q.pop();                     // 出队
    }
    cout << endl;
}
void TestPriorityQueue()
{
	// 默认情况下，创建的是大堆，其底层按照小于号比较
	vector<int> v{ 3,2,7,6,0,4,1,9,8,5 };
	priority_queue<int> q1;
	for (auto& e : v)
		q1.push(e);
	cout << q1.top() << endl;
	// 如果要创建小堆，将第三个模板参数换成greater比较方式
	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());
	cout << q2.top() << endl;
}

class Date
{
public:
    Date(int year = 1900, int month = 1, int day = 1)
        : _year(year)
        , _month(month)
        , _day(day)
    {}
    bool operator<(const Date& d)const
    {
        return (_year < d._year) ||
            (_year == d._year && _month < d._month) ||
            (_year == d._year && _month == d._month && _day < d._day);
    }
    bool operator>(const Date& d)const
    {
        return (_year > d._year) ||
            (_year == d._year && _month > d._month) ||
            (_year == d._year && _month == d._month && _day > d._day);
    }
    friend ostream& operator<<(ostream& _cout, const Date& d)
    {
        _cout << d._year << "-" << d._month << "-" << d._day;
        return _cout;
    }
private:
    int _year;
    int _month;
    int _day;
};
void TestPriorityQueue2()
{
    // 大堆，需要用户在自定义类型中提供<的重载
    priority_queue<Date> q1;
    q1.push(Date(2018, 10, 29));
    q1.push(Date(2018, 10, 28));
    q1.push(Date(2018, 10, 30));
    cout << q1.top() << endl;

    // 如果要创建小堆，需要用户提供>的重载
    priority_queue<Date, vector<Date>, greater<Date>> q2;
    q2.push(Date(2018, 10, 29));
    q2.push(Date(2018, 10, 28));
    q2.push(Date(2018, 10, 30));
    cout << q2.top() << endl;
}

void testDeque()
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(2);

    deque<int>::iterator it = dq.begin();
    while (it != dq.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    it = dq.erase(--it);
    it = dq.begin();
    while (it != dq.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

void Testmystack()
{
    liren::stack<int> st;
    st.push(1);
    st.push(4);
    st.push(3);
    st.push(2);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    //也可以传不同的适配器，照样能跑
    liren::stack<int, vector<int>> s;
    s.push(1);
    s.push(4);
    s.push(3);
    s.push(2);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void Testmyqueue()
{
    liren::queue<int> q;
    q.push(1);
    q.push(3);
    q.push(4);
    q.push(2);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    //也可以传list容器，照样能跑
    liren::queue<int, list<int>> q1;
    q1.push(1);
    q1.push(3);
    q1.push(4);
    q1.push(2);
    while (!q1.empty())
    {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl;

    /*liren::queue<int, vector<int>> q2;
    q2.push(1);
    q2.push(1);
    q2.push(1);
    q2.push(1);
    while (!q2.empty())
    {
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << endl;*/
}

//仿函数 -- 函数对象（可以像函数一样去使用）
struct lessInt
{
    bool operator()(int left, int right)
    {
        return left < right;
    }
};

//函数的正常形式
bool lessFunc(int left, int right)
{
    return left < right;
}

void testFunctor()
{
    //仿函数的使用
    lessInt less;
    cout << less(1, 2) << endl;

    //正常函数的使用
    cout << lessFunc(1, 2) << endl;
}

void testMypriority_queue()
{
    liren::priority_queue<int> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    //也可以将其改为小堆顺序
    liren::priority_queue<int, vector<int>, liren::greater<int>> pq2;
    pq2.push(1);
    pq2.push(2);
    pq2.push(3);
    pq2.push(4);
    pq2.push(5);
    while (!pq2.empty())
    {
        cout << pq2.top() << " ";
        pq2.pop();
    }
    cout << endl;

    //还可用迭代器构造区间
    vector<int> v{ 5,1,4,2,3,6 };
    liren::priority_queue<int, vector<int>, liren::greater<int>> q2(v.begin(), v.end());
    cout << q2.top() << endl;

    q2.pop();
    q2.pop();
    cout << q2.top() << endl;
}

int main()
{
    //test_queue();
    //TestPriorityQueue2();
    //testDeque();
    //Testmyqueue();
    //testFunctor();
    testMypriority_queue();
	return 0;
}