#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class MyString
{
private:
	char* stringContent;
	int stringLength;
	int memoryCapacity;
public:
	MyString(char c);
	MyString(const char* str);
	MyString();
	MyString(const MyString& str);
	~MyString();

	int Length() const;
	void Print() const;
	void Println() const;

	MyString& Assign(const MyString& str);
	MyString& Assign(const char* str);

	int Capacity() const;
	void Reserve(int size);
	char At(int i) const;

	MyString& Insert(int loc, const MyString& str);
	MyString& Insert(int loc, const char* str);
	MyString& Insert(int loc, char c);

	MyString& Erase(int loc, int num);

	int Find(int findFrom, MyString& str) const;
	int Find(int findFrom, const char* str) const;
	int Find(int findFrom, char c) const;

	int Compare(const MyString& str) const;
};

