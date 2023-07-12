#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

/*
     字符串匹配算法
     1、BF算法(效率低）×
     2、KMP算法 ✔

str: 代表主串
sub：代表子串
要求：返回匹配位置的下标，若不匹配则返回-1
*/

int BF(const string& str, const string& sub)
{
    //若有一个为空，则不用比 
    if (str.empty() || sub.empty())
    {
        return -1;
    }

    size_t strn = str.size();
    size_t subn = sub.size();
    
    int i = 0;//主串的下标
    int j = 0;//子串的下标
    while (i < strn && j < subn)
    {
        if (str[i] == sub[j])
        {
            i++;
            j++;
        }
        else
        {
            //i向后移动j个偏移量相当于回到原来位置，然后再加一向后移动一位
            i = i - j + 1;
            j = 0;
        }
    }
    if (j >= subn)//说明子串已经遍历完了
    {
        i = i - j;
        return i;
    }
    return -1;

}

void GetNext(const string& s, int* next, int n)
{
    //先把两个固定的值赋上
    next[0] = -1;

    // 判断一下防止越界，但是next[0]就不用了，因为在KMP中我们已经判断不为0了
    if (n >= 2)
        next[1] = 0;

    int i = 1;
    int k = 0;
    while (i < n - 1)
    {
        // 记得加入 k == -1 的情况（回退到出界了）
        if (k == -1 || s[i] == s[k])
        {
            next[i + 1] = k + 1;
            ++i;
            ++k;
        }
        else
        {
            k = next[k];
        }
    }
}

int KMP(const string& str, const string& sub)
{
    // 特殊情况处理
    if (str.empty() || sub.empty())
        return -1;

    int strn = str.size(); // 注意这里两个大小不能是size_t不然后面的i、j也会转化为size_t
    int subn = sub.size();

    // 创建一个next数组,并都初始化为0
    int* next = new int[sub.size()] { 0 };
    GetNext(sub, next, subn);

    int i = 0; //遍历主串
    int j = 0; //遍历子串
    while (i < strn && j < subn)
    {
        //记得加入 j == -1 的情况（回退到出界了）
        if (j == -1 || str[i] == sub[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }

    if (j >= subn)
        return i - j;

    return -1;
}

int main()
{
    /*string str = "liren love yt and money!";
    string sub = "yt";
    cout << BF(str, sub) << endl;*/

    string str = "abcababcabc";
    cout << KMP(str, string("abcabc")) << endl;
    cout << KMP(str, string("abc")) << endl;
    cout << KMP(str, string("abcd")) << endl;
    cout << KMP(str, string("--")) << endl;
    return 0;
}

int main()
{
    /*string str = "liren love yt and money!";
    string sub = "yt";
    cout << BF(str, sub) << endl;*/

    /*string str = "abcababcabc";
    cout << KMP(str, string("abcabc")) << endl;
    cout << KMP(str, string("abc")) << endl;
    cout << KMP(str, string("abcd")) << endl;
    cout << KMP(str, string("--")) << endl;*/

    /*string str = "leetcode";
    cout << KMP(str, string("leeto")) << endl;*/

    string str = "a";
    cout << KMP(str, string("a")) << endl;
    return 0;
}