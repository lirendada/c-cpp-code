#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//typedef struct a
//{
//	int data;
//	struct b* next;
//}b;
//int main()
//{
//	return 0;
// }


//struct S1
//{
//	double d;
//	char c1;
//	int i;
//};
//struct S2
//{
//	char c1;
//	struct S1 s;
//	double d;
//};
//int main()
//{
//	struct S2 sb = { 0 };
//	printf("%d\n", sizeof(sb));
//	return 0;
//}

//#pragma pack(2)
//struct S
//{
//	char c1;
//	int i;
//	char c2;
//	double d;
//};
//#pragma pack()
//
//int main()
//{
//	printf("%d\n", sizeof(struct S));
//	return 0;
//}


//#include<stddef.h>
//struct S
//{
//	char c1;
//	int i;
//	char c2; 
//	double d;
//};
//int main()
//{
//	printf("%d\n", offsetof(struct S, c1));
//	printf("%d\n", offsetof(struct S, i));
//	printf("%d\n", offsetof(struct S, c2));
//	printf("%d\n", offsetof(struct S, d));
//	return 0;
//}


//struct S
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//int main()
//{
//	struct S s = { 0 };
//	s.a = 10;
//	s.b = 12;
//	s.c = 3;
//	s.d = 4;
//	return 0;
//}


//enum color
//{
//	red,
//	green=3,
//	blue
//};
//int main()
//{
//	printf("%d\n", red);
//	printf("%d\n", blue);
//	printf("%d\n", green);
//	return 0;
//}


//#include<string.h>
//struct student
//{
//	long id;
//	char name[16];
//	char sex;
//	int age;
//	char addr[30];
//}wang={201110101,"wangjun",'M',25,"street peace no.253"};
//int main()
//{
//	struct student li = { 201110102,"lihong",'f',23,"green house no.523" },
//	zhang = { 201110103,"zhanghua",'M' };
//	struct student zhao = li;
//	zhao.id = 201110104;
//	strcpy(zhao.name, "zhaolin");
//	printf("  id       name     sex       age      addr\n");
//	printf("------------------------------------------------------------------------\n");
//	printf("%-10d%-10s%-4c%-14d%s\n", wang.id, wang.name, wang.sex, wang.age, wang.addr);
//	printf("%-10d%-10s%-4c%-14d%s\n", li.id, li.name, li.sex, li.age, li.addr);
//	printf("%-10d%-10s%-4c%-14d%s\n", zhang.id, zhang.name, zhang.sex, zhang.age, zhang.addr);
//	printf("%-10d%-10s%-4c%-14d%s\n", zhao.id, zhao.name, zhao.sex, zhao.age,zhao.addr);
//	return 0;
//}



//#include<string.h>
//struct stu_age
//{
//	int year;
//	int month;
//	int day;
//};
//struct student
//{
//	long id;
//	char name[16];
//	char sex;
//	struct stu_age birthday;
//	char addr[30];
//};
//int main()
//{
//	struct student zhao;
//	printf("input:");
//	scanf("%ld %s %c %d %d %d %s", &zhao.id, zhao.name, &zhao.sex, &zhao.birthday.year, &zhao.birthday.month, &zhao.birthday.day, zhao.addr);
//	printf("%ld,%s,%c,%d-%d-%d,%s\n", zhao.id, zhao.name, zhao.sex, zhao.birthday.year, zhao.birthday.month, zhao.birthday.day, zhao.addr);
//	return 0;
//}


//struct student
//{
//	long id;
//	char name[16];
//	char sex;
//	int age;
//	char addr[30];
//}cs_stu[3] = { {201110101,"wangjun",'M',25,"street peace no.253"} ,{201110102,"lihong",'f',23,"green house no.523"} ,{201110103,"zhanghua",'M'} };
//int main()
//{
//	struct student stu[]={ {201110101,"wangjun",'M',25,"street peace no.253"} ,{201110102,"lihong",'f',23,"green house no.523"} };
//	return 0;
//}


//struct student
//{
//	long id;
//	char name[16];
//	char sex;
//	int age;
//	char addr[30];
//}wang= {201110101, "wangjun", 'M', 25, "street peace no.253"};
//int main()
//{
//	struct student* p;
//	p = &wang;
//	printf("%ld,%s,%c,%d,%s\n", wang.id,wang.name,wang.sex,wang.age,wang.addr);
//	printf("%ld,%s,%c,%d,%s\n", p->id, p->name, p->sex, p->age, p->addr);
//	return 0;
//}


//struct student
//{
//	long id;
//	char name[16];
//	char sex;
//	int age;
//	char addr[30];
//}stu[3]={ { 202010101, "wangjun", 'M', 25, "street peace no.253" } ,{202010102,"lihong",'f',23,"green house no.523"} ,{202010103,"zhanghua",'M'} };
//结构类型变量的成员当作函数参数
//void println(long id, char* name, char sex, int age, char* addr) 
//{
//	printf("	id:%ld\n", id);
//	printf("	name:%s\n", name);
//	printf("	sex:%c\n", sex);
//	printf("	age:%d\n", age);
//	printf("	addr:%s\n",addr);
//}
//int main()
//{
//	struct student wang = { 201110101, "wangjun", 'M', 25, "street peace no.253" };
//	println(wang.id, wang.name, wang.sex, wang.age, wang.addr);
//	return 0;
//}

//完整的结构类型变量当作函数参数（不推荐，因为可能会栈溢出）
//void println(struct student s)
//{
//	printf("	id:%ld\n", s.id);
//	printf("	name:%s\n", s.name);
//	printf("	sex:%c\n", s.sex);
//	printf("	age:%d\n", s.age);
//	printf("	addr:%s\n",s.addr);
//}
//int main()
//{
//	struct student wang = { 201110101, "wangjun", 'M', 25, "street peace no.253" };
//	println(wang);
//	return 0;
//}

//使用结构类型指针作为函数参数（推荐）
//void println(struct student* s)
//{
//	printf("	id:%ld\n", s->id);
//	printf("	name:%s\n", s->name);
//	printf("	sex:%c\n", s->sex);
//	printf("	age:%d\n", s->age);
//	printf("	addr:%s\n",s->addr);
//}
//int main()
//{
//	struct student wang = { 201110101, "wangjun", 'M', 25, "street peace no.253" };
//	println(&wang);
//	return 0;
//}

//结构体型函数，即函数的返回值为结构类型(也不推荐，也容易栈溢出)
//struct student fan()
//{
//	struct student s = { 201110101, "wangjun", 'M', 25, "street peace no.253" };
//	return s;
//}
//int main()
//{
//	struct student wang;
//	wang = fan();
//	printf("	id:%ld\n", wang.id);
//	printf("	name:%s\n", wang.name);
//	printf("	sex:%c\n", wang.sex);
//	printf("	age:%d\n", wang.age);
//	printf("	addr:%s\n",wang.addr);
//	return 0;
//}

//结构体指针型函数，即函数的返回值为结构体指针类型(推荐)
//struct student* find(long id)
//{
//	int i;
//	for (i = 0; i < 3; i++)
//		if (stu[i].id == id)
//			return &stu[i];
//	return NULL;
//}
//int main()
//{
//	struct student *wang;
//	long id;
//	printf("please input id:");
//	scanf("%ld", &id);
//	wang = find(id);
//	if (wang != NULL)
//	{
//		printf("	id:%ld\n", wang->id);
//		printf("	name:%s\n", wang->name);
//		printf("	sex:%c\n", wang->sex);
//		printf("	age:%d\n", wang->age);
//		printf("	addr:%s\n", wang->addr);
//	}
//	else
//		printf("找不到\n");
//	return 0;
//}


//动态内存分配
//#include<string.h>
//#include<stdlib.h>
//struct student
//{
//	long id;
//	char name[16];
//	char sex;
//	int age;
//	char addr[30];
//};
//int main()
//{
//	struct student* ps;
//	ps = (struct student*)malloc(sizeof(struct student));
//	ps->id = 202010101;
//	strcpy(ps->name, "wangjun");
//	ps->sex = 'M';
//	ps->age = 25;
//	strcpy(ps->addr, "street peace no.253");
//	printf("%ld,%s,%c,%d,%s\n", ps->id, ps->name, ps->sex, ps->age, ps->addr);
//	free(ps);
//	return 0;
//}


//创建链表与查找
//#include<string.h>
//#include<stdlib.h>
//struct student
//{
//	long id;
//	char name[16];
//	char sex;
//	int age;
//	char addr[30];
//	struct student* next;//指向后续结点的指针
//};
//struct student* head = NULL;//全局变量，链表的头指针
//void DeleteAll()
//{
//	struct student* p = head;
//	while (head != NULL)
//	{
//		head = head->next;
//		free(p);
//		p = head;
//	}
//}
//void InputData(struct student* ptr)
//{
//	printf("enter id:");
//	scanf("%ld", &(ptr->id));//输入学号
//	getchar();
//	if (ptr->id <= 0)
//		return;//若学号小于等于0，则表示该结点不用加入链表
//	printf("enter name:");
//	gets(ptr->name);//输入名字
//	printf("enter sex:");
//	ptr->sex = getchar();//输入性别
//	printf("enter age:");
//	scanf("%d" ,& (ptr->age));//输入年龄
//	getchar();
//	printf("enter address:");
//	gets(ptr->addr);//输入地址
//	ptr->next = NULL;//将指针域置为空
//}
//void OutputAll()
//{
//	struct student* ptr = head;
//	printf("\n");
//	printf("************************************************STUDENT********************************************\n");
//	printf("|id               |name                 |sex |age    |address                                      |\n");
//	printf("|-----------------|---------------------|----|-------|---------------------------------------------|\n");
//	while (ptr != NULL)
//	{
//		printf("|%-17ld|%-21s|%c   |%-6d |%-44s|\n",ptr->id,ptr->name,ptr->sex,ptr->age,ptr->addr);
//		ptr = ptr->next;
//	}
//	printf("**************************************************END**********************************************\n");
//}
//void OutputNode(struct student* ptr)
//{
//	int i = 0; 
//	printf("\n");
//	printf("************************************************STUDENT********************************************\n");
//	printf("|id               |name                 |sex |age    |address                                      |\n");
//	printf("|-----------------|---------------------|----|-------|---------------------------------------------|\n");
//	if(ptr!=NULL)
//		printf("|%-17ld|%-21s|%c   |%-6d |%-44s|\n", ptr->id, ptr->name, ptr->sex, ptr->age, ptr->addr);
//	printf("**************************************************END**********************************************\n");
//}
//struct student* Create()
//{
//	struct student* currP, * lastP = NULL;
//	//申请第一个结点的空间
//	head = lastP = (struct student*)malloc(sizeof(struct student));
//	InputData(head);         //输入第一个结点的数据
//	if (head->id <= 0)
//	{
//		free(head);
//		head = NULL;
//	}
//	else
//	{
//		do {
//			currP = (struct student*)malloc(sizeof(struct student));
//			InputData(currP);
//			if (currP->id <= 0)
//			{
//				free(currP);
//				currP = NULL;
//			}
//			else
//			{
//				lastP->next = currP;
//				lastP = currP;
//			}
//		} while (currP != NULL);
//	}
//	return head;
//}
//struct student* Find(int id)
//{
//	struct student* p = head;
//	while (p != NULL && p->id != id)
//		p = p->next;
//	return p;
//}
//int main()
//{
//	head = Create();
//	OutputAll();
//	OutputNode(Find(202010102));
//	DeleteAll();
//}


//union u
//{
//	char a;
//	int b;
//};
//int main()
//{
//	union u un;
//	printf("%d\n", sizeof(un));
//	printf("%p\n", &un);
//	printf("%p\n", &un.a);
//	printf("%p\n", &un.b);
//	return 0;
//}


union U
{
	char a[5];
	int b;
};
int main()
{
	union U u;
	printf("%d\n", sizeof(u));
	return 0;
}