#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//class Clock
//{
//public:
//	Clock(int newh , int newm , int news );
//	Clock() :hour(0), minute(0), second(0) {};
//	void settime(int newh, int newm, int news);
//	void updatetime();
//	void showtime();
//private:
//	int hour, minute, second;
//};
////clock::clock() :hour(0), minute(0), second(0) {}
//Clock::Clock(int newh, int newm, int news) : hour(newh), minute(newm), second(news) {}
//void Clock::settime(int newh, int newm, int news)
//{
//	hour = newh;
//	minute = newm;
//	second = news;
//}
//void Clock::updatetime()
//{
//	second++;
//	if (second == 60)
//	{
//		second = 0;
//		minute++;
//	}
//	if (minute == 60)
//	{
//		minute = 0;
//		hour++;
//	}
//	if (hour == 24)
//	{
//		hour = 0;
//	}
//}
//inline void Clock::showtime()
//{
//	cout << hour << ":" << minute << ":" << second << endl;
//}
//int main()
//{
//	Clock c1;
//	for (int i = 0; i < 10; i++)
//	{
//		c1.updatetime();
//		c1.showtime();
//	}
//	Clock c2(23, 59, 57);
//	for (int i = 0; i < 10; i++)
//	{
//		c2.updatetime();
//		c2.showtime();
//	}
//	return 0;
//}


//class Point {
//public:
//	Point(int xx = 0, int yy = 0) {
//		x = xx;
//		y = yy;
//	}
//	Point(Point& p);
//	int getx() { return x; }
//	int gety() { return y; }
//	~Point() {};
//private:
//	int x, y;
//};
//Point::Point(Point& p)
//{
//	x = p.x;
//	y = p.y;
//	cout << "Calling the copy constructor" << endl;
//}
//void fun1(Point p) 
//{
//	cout << p.getx() << endl;
//}
//Point fun2()
//{
//	Point a(1, 2);
//	return a;
//}
//int main()
//{
//	Point a(4, 5);
//	Point b = a;//第一种情况，用a初始化b，第一次调用复制构造函数
//	cout << b.getx()<<endl;
//	fun1(b);    //第二种情况，对象b作为fun1的实参，第二次调用复制构造函数
//	b = fun2(); //第三种情况，函数的返回值是类对象，函数返回时，调用复制构造函数
//	cout << b.getx() << endl;
//	cout << b.gety() << endl;
//	return 0;
//}



//#define PI 3.141593
//#define fencevalue 35
//#define roadvalue 20
//class Circle
//{
//public:
//	Circle(float newoutrad) :outrad(newoutrad) {};
//	float calmidroad() { return PI * (outrad * outrad - (outrad-3)*(outrad-3)); };
//	float caloutlen() { return 2 * PI * outrad; };
//private:
//	float outrad;
//};
//int main()
//{
//	float outrad = 0;
//	cin >> outrad ;
//	Circle a(outrad);
//	cout << "The road value is " << roadvalue * a.calmidroad() << endl;
//	cout << "The fence value is " << fencevalue * a.caloutlen() << endl;
//	return 0;
//}



//class Point
//{
//public:
//	Point(int xx = 0, int yy = 0) { x = xx, y = yy; }
//	Point(Point& p) { x = p.x, y = p.y; cout << "Lirendada!" << endl; }
//	int getx() { return x; }
//	int gety() { return y; }
//private:
//	int x, y;
//};
//class Line
//{
//public:
//	Line(Point xp1, Point xp2);
//	Line(Line& l);
//	double getlen() { return len; }
//private:
//	Point p1, p2;
//	double len;
//};
//Line::Line(Point xp1, Point xp2) :p1(xp1), p2(xp2)
//{
//	cout << "liren!!" << endl;
//	double x = static_cast<double>(p1.getx() - p2.getx());
//	double y = static_cast<double>(p1.gety() - p2.gety());
//	len = sqrt(x * x + y * y);
//}
//Line::Line(Line& l) :p1(l.p1), p2(l.p2)
//{
//	cout << "liren" << endl;
//	len = l.len;
//}
//int main()
//{
//	Point myp1(1, 1), myp2(4, 5);
//	Line line(myp1, myp2);
//	Line line2(line);
//	cout << line.getlen() << endl;
//	cout << line2.getlen() << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Dog
//{
//public:
//	void set();
//	void showweight();
//	void showage();
//private:
//	int age, weight;
//};
//void Dog::set()
//{
//	int dage = 0, dweight = 0;
//	cout << "输入年龄与体重（用空格隔开）:";
//	cin >> dage >> dweight;
//	age = dage;
//	weight = dweight;
//}
//void Dog::showweight()
//{
//	cout << "体重：" << weight << endl;
//}
//void Dog::showage()
//{
//	cout << "年龄：" << age << endl;
//}
//int main()
//{
//	int n = 0;
//	Dog d;
//	d.set();
//	d.showweight();
//	d.showage();
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Rectangle
//{
//public:
//	void setpoint(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);
//	void calarea();
//private:
//	int xs1, ys1, xs2, ys2;
//};
//void Rectangle::setpoint(int x1, int y1, int x2, int y2)
//{
//	xs1 = x1, xs2 = x2, ys1 = y1, ys2 = y2;
//}
//void Rectangle::calarea()
//{
//	if ((ys2 > ys1 && xs2 > xs1) || (ys2 < ys1 && xs2 < xs1))
//		cout << "面积为：" << (xs2 - xs1) * (ys2 - ys1) << endl;
//	else if ((ys2 < ys1 && xs2>xs1) || (ys2 > ys1 && xs2 < xs1))
//		cout << "面积为：" << -((xs2 - xs1) * (ys2 - ys1)) << endl;
//	else if (ys1 == ys2 || xs1 == xs2)
//		cout << "为线段，无面积！";
//}
//int main()
//{
//	Rectangle r;
//	int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
//	cin >> x1 >> y1 >> x2 >> y2;
//	r.setpoint(x1,y1,x2,y2);
//	r.calarea();
//	return 0;
//}


//class Point
//{
//public:
//	Point(int x = 0, int y = 0) :x(x), y(y)
//	{
//		count++;
//	}
//	Point(Point& p)
//	{
//		x = p.x;
//		y = p.y;
//		count++;
//	}
//	~Point() { count--; }
//	int getx() { return x; }
//	int gety() { return y; }
//	static void showCount()
//	{
//		cout << "Object count = " << count << endl;
//	}
//private:
//	int x, y;
//	static int count;
//};
//int Point::count = 0;
//int main()
//{
//	Point::showCount();
//	Point a(4, 5);
//	cout << "Point A: " << a.getx() << "," << a.gety();
//	a.showCount();
//
//	Point b(a);
//	cout << "Point B: " << b.getx() << "," << b.gety();
//	Point::showCount();
//}


//class R {
//public:
//	R(int r1, int r2) :r1(r1), r2(r2) {};
//	/*void print();*/
//	void print() const;
//private:
//	int r1, r2;
//};
//void R::print()
//{
//	cout << r1 << ":" << r2 << endl;
//}
//void R::print() const
//{
//	cout << r1 << ":" << r2 << endl;
//}
//
//int main()
//{
//	R a(5, 4);
//	a.print();
//	const R b(20, 52);
//	b.print();
//	return 0;
//}

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
//int main()
//{
//	Cat orangecat(2);
//	Cat::getNumOfCats();
//
//	Cat browncat = orangecat;
//	Cat::getNumOfCats();
//	return 0;
//}



//class Point
//{
//public:
//	void initPoint(float x = 0, float y = 0) { this->x = x; this->y = y; }
//	void move(float offx, float offy) { x += offx; y += offy; }
//	float getx()const { return x; }
//	float gety()const { return y; }
//private:
//	float x, y;
//};
//class Rectangle:public Point
//{
//public:
//	void initRectangle(float x, float y, float w, float h) {
//		initPoint(x, y);
//		this->w = w;
//		this->h = h;
//	}
//	float geth() const{ return h; }
//	float getw() const { return w; }
//private:
//	float w, h;
//};
//int main()
//{
//	Rectangle r;
//	r.initRectangle(2, 3, 20, 10);
//	r.move(3, 2);
//	cout << r.getx() << endl;
//	cout << r.gety() << endl;
//	cout << r.getw() << endl;
//	cout << r.geth() << endl;
//	return 0;
//}




//class Shape
//{
//public:
//	Shape() {}
//	virtual ~Shape() {}
//	virtual float getArea() const { return 0; }
//};
//class Rectangle : public Shape
//{
//public:
//	Rectangle(float X=0, float Y=0) :x(X), y(Y) {}
//	float  getArea() const { return x * y; }
//	float getx() const { return x; }
//	float gety() const { return y; }
//private:
//	float x, y;
//};
//class Circle :public Shape
//{
//public:
//	Circle(float R=0) :radius(R) {}
//	float getArea() const { return 3.1415926 * radius * radius; }
//	float getradius() const { return radius; }
//private:
//	float radius;
//};
//class Square :public Rectangle
//{
//public:
//	Square(float A) :a(A) {}
//	float getArea() const { return a * a; }
//	float geta() const { return a; }
//private:
//	float a;
//};
//int main()
//{
//	Rectangle a(1.2, 3.4);
//	cout << a.getArea() << endl;
//
//	Circle c(2.1);
//	cout << c.getArea() << endl;
//	return 0;
//}



//class Complex
//{
//public:
//	Complex(double r = 0.0, double i = 0.0) :real(r), imag(i) {}
//	Complex operator + (const Complex& c2) const;
//	Complex operator - (const Complex& c2) const;
//	void display() const;
//private:
//	double real, imag;
//};
//Complex Complex::operator+(const Complex& c2) const
//{
//	return Complex(real + c2.real, imag + c2.imag);
//}
//Complex Complex::operator-(const Complex& c2)const
//{
//	return Complex(real - c2.real, imag - c2.imag);
//}
//void Complex::display() const 
//{
//	cout << "(" << real << "," << imag << ")" << endl;
//}
//int main()
//{
//	Complex c1(5, 4), c2(2, 10), c3;
//	cout << "c1="; c1.display();
//	cout << "c2="; c2.display();
//	c3 = c1 - c2;
//	cout << "c3=c1-c2="; c3.display();
//	c3 = c1 + c2;
//	cout << "c3=c1+c2="; c3.display();
//	return 0;
//}



//class Counter
//{
//public:
//	Counter(int t1 = 0) :t(t1) {}
//	int gettime() { return t; }
//	void settime(int t1) { t = t1; }
//	Counter operator+(Counter& r) { return Counter(t + r.gettime()); }
//private:
//	int t;
//};
//int main()
//{
//	Counter t1(3), t2(1), t3;
//	t3 = t1 + t2;
//	cout << t3.gettime() << endl;
//	return 0;
//}



//class  Complex
//{
//public:
//	Complex(double r = 0.0, double i = 0.0) :real(r), imag(i) {}
//	friend Complex operator+(const Complex& c1, const Complex& c2);
//	friend Complex operator-(const Complex& c1, const Complex& c2);
//	friend ostream& operator<<(ostream&out, const Complex& c);
//private:
//	double real, imag;
//};
//Complex operator+(const Complex& c1, const Complex& c2)
//{
//	return Complex(c1.real + c2.real, c1.imag + c2.imag);
//}
//Complex operator-(const Complex& c1, const Complex& c2)
//{
//	return Complex(c1.real - c2.real, c1.imag - c2.imag);
//}
//ostream& operator<<(ostream& out, const Complex& c)
//{
//	cout << "(" << c.real << "," << c.imag << ")";
//	return out;
//}
//int main()
//{
//	Complex c1(5, 4), c2(2, 10), c3;
//	cout << "c1=" << c1 << endl;
//	cout << "c2=" << c2 << endl;
//	c3 = c1 - c2;
//	cout << "c3=c1-c2=" << c3 << endl;
//	c3 = c1 + c2;
//	cout << "c3=c1+c2=" << c3 << endl;
//	return 0;
//}



//class Shape
//{
//public:
//	virtual void getPerim() const {}
//	virtual void getArea() const {}
//	virtual ~Shape() {}
//};
//class Rectangle :public Shape
//{
//private:
//	double w,h;
//public:
//	Rectangle(const double w1 = 0.0, const double h1 = 0.0) :w(w1), h(h1) {}
//	void getPerim() const { cout << "the Perim of Rectangle is " << 2 * (w + h) << endl; }
//	void getArea() const { cout << "the area of Rectangle is " << w * h << endl; }
//	~Rectangle() {}
//};
//class Circle :public Shape
//{
//private:
//	double r;
//public:
//	Circle(const double r1 = 0.0) :r(r1) {}
//	void getPerim() const { cout << "the Perim of Circle is " << 2 * 3.1415926 * r << endl; }
//	void getArea() const { cout << "the area of Circle is " << 3.1415926 * r * r << endl; }
//	~Circle() {}
//};
//int main()
//{
//	Rectangle r(2.5, 2.0);
//	r.getArea();
//	r.getPerim();
//
//	Circle c(3.1);
//	c.getArea();
//	c.getPerim();
//	return 0;
//}



//class Point
//{
//private:
//	int x, y;
//public:
//	Point(int x1=0,int y1=0) :x(x1), y(y1) {}
//	friend Point operator+(const Point& p1, const Point& p2);
//	void showpoint() const { cout << "("<<x << "," << y << ")" << endl; }
//	~Point() {}
//};
//Point operator+(const Point& p1, const Point& p2)
//{
//	return Point(p1.x + p2.x, p1.y + p2.y);
//}
//int main()
//{
//	Point p1(3, 4), p2(1, -2), p3;
//	p1.showpoint();
//	p2.showpoint();
//	p3 = p1 + p2;
//	p3.showpoint();
//	return 0;
//}


//#include "array.h"
//int main()
//{
//	
//	int n = 0;
//	float agrade = 0;
//	cout << "请输入人的个数：";
//	cin >> n;
//	Array<float> arr(n);
//	for (int i = 0; i < n; i++)
//	{
//		cout << "请输入第" << i + 1 << "个学生的成绩：";
//		cin >> arr[i];
//		agrade = agrade + arr[i];
//	}
//	cout << "the average grade is " << agrade / n << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//#define unitcost 10
//class Shape
//{
//public:
//	int setWidth(int w) { width = w; }
//	int setHeight(int h) { height = h; }
//private:
//	int width, height;
//};
//class PaintCost
//{
//public:
//	int getCost(int area) { return area * unitcost; }
//};
//class Rectangle :public Shape, public PaintCost
//{
//public:
//	int area;
//	Rectangle(const int x1, const int y1) :x(x1), y(y1) {}
//	void getarea() { cout << "the area of this Rectangle is " << x * y << endl; area = x * y; }
//private:
//	int x, y;
//};
//int main()
//{
//	Rectangle a(3, 4);
//	a.getarea();
//	cout << "the sum of the cost is " << a.PaintCost::getCost(a.area) << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//const double PI = 3.1415926;
//class Shape
//{
//public:
//	virtual double Area() = 0;
//};
//class Triangle :public Shape
//{
//public:
//	Triangle(double h, double w) :H(h), W(w) {}
//	double Area() { return 0.5 * H * W; }
//private:
//	double H, W;
//};
//class Circle :public Shape
//{
//public:
//	Circle(double r) :R(r) {}
//	double Area() { return PI* R* R; }
//private:
//	double R;
//};
//double Total(Shape* s[], int n)
//{
//	double sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		sum += s[i]->Area();
//	}
//	return sum;
//}
//int main()
//{
//	Shape* s[2];
//	s[0] = new Triangle(5.0, 4.0);
//	s[1] = new Circle(8.0);
//	double sum = Total(s,2);
//	cout << "sum=" << sum << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class Animal
//{
//public:
//	virtual void sound() const = 0;
//	void run() const { cout << "animal running!" << endl; }
//};
//class Tiger :public Animal
//{
//public:
//	Tiger(int w=0, int a=0) :weight(w), age(a) {}
//	void sound() const { cout << "roar!" << endl; }
//private:
//	int weight, age;
//};
//class Mouse :public Animal
//{
//public:
//	Mouse(int w=0, int a=0) :weight(w), age(a) {}
//	void sound() const { cout << "mouse call!" << endl; }
//private:
//	int weight, age;
//};
//int main()
//{
//	Tiger t;
//	t.sound();
//	t.run();
//
//	Mouse m;
//	m.sound();
//	m.run();
//	return 0;
//}


//#include<iostream>
//using namespace std;
//const double PI = 3.1415926;
//class Circle
//{
//public:
//	virtual void getarea() const = 0;
//private:
//	double rad;
//};
//class Globe :public Circle
//{
//public:
//	Globe(double r = 0) :rad(r) {}
//	void getarea() const { cout << "the volume of the globe is " << 4.0 / 3 * PI * rad * rad * rad << endl; }
//public:
//	double rad;
//};
//class Cylinder :public Circle
//{
//public:
//	Cylinder(double r = 0, int h1 = 0) :rad(r), h(h1) {}
//	void getarea() const { cout << "the volume of the cylinder is " << PI * rad * rad * h << endl; }
//public:
//	double rad;
//	int h;
//};
//class Cone :public Circle
//{
//public:
//	Cone(double r = 0, int h1 = 0) :rad(r),h(h1) {}
//	void getarea() const { cout << "the volume of the globe is " << 1.0 / 3 * PI * rad * rad * h<< endl; }
//public:
//	double rad;
//	int h;
//};
//int main()
//{
//	Globe g1(3.0);
//	g1.getarea();
//
//	Cylinder c1(3.8, 2);
//	c1.getarea();
//
//	Cone c2(3.8, 2);
//	c2.getarea();
//	return 0;
//}


#include<iostream>
using namespace std;
//class Box
//{
//public:
//	Box(int l1 = 0, int w1 = 0, int h1 = 0) :l(l1), w(w1), h(h1) {}
//	Box& operator+(const Box& b)
//	{
//		l += b.l;
//		w += b.w;
//		h += b.h;
//		return *this;
//	}
//	void print() { cout << "l=" << l << ",w=" << w << ",h=" << h << endl; }
//private:
//	int l; int w; int h;
//};
//int main()
//{
//	Box b1(1, 2, 3);
//	b1.print();
//	Box b2(4, 5, 6);
//	b2.print();
//	Box b3;
//	b3 = b1 + b2;
//	b3.print();
//	return 0;
//}

int& Add(int a, int b)
{
	int C = a + b;
	return C;
}
int main()
{
	int& ret = Add(1,2);
	Add(3,4);
	cout << "Add(1, 2) is :" << ret << endl;
	return 0;
}