#pragma once
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//class GamePlayer
//{
//private:
//	static const double num;
//};

//class GamePlayer
//{
//private:
//	enum { num = 5 };
//	int scores[num];
//};

//class TextBlock
//{
//public:
//	TextBlock(const char* str)
//		:text(str)
//	{}
//
//	char& operator[](size_t pos)
//	{
//		return text[pos];
//	}
//
//	const char& operator[](size_t pos) const
//	{
//		return text[pos];
//	}
//private:
//	string text;
//};
//
//void print(const TextBlock& ctb)
//{
//	cout << ctb[0];
//}

//class CTextBlock
//{
//public:
//	CTextBlock(const char* str)
//	{
//		text = (char*)malloc(sizeof(char) * (strlen(str) + 1));
//		strcpy(text, str);
//	}
//
//	size_t length() const
//	{
//		if (!lengthIsValid)
//		{
//			textLength = strlen(text);
//			lengthIsValid = true;
//		}
//		return textLength;
//	}
//private:
//	char* text;
//	mutable size_t textLength;
//	mutable bool lengthIsValid;
//};
//

//class Test
//{
//public:
//	// ...
//	const char& operator[](size_t position) const
//	{
//		// ...
//		return text[position];
//	}
//	char& operator[](size_t position)
//	{
//		return const_cast<char&>(
//			static_cast<const Test&>(*this)
//			[position]
//		);
//	}
//private:
//	string text;
//};

class FileSystem
{
public:
	size_t numDisks() const;
	// ......
};

class Directory
{
public:
	Directory();
};

Directory& tmpDir();

FileSystem& tfs();