#include "MyString.hpp"
using namespace std;

MyString::MyString(char c)
{
	this->stringContent = new char[1];
	this->stringContent[0] = c;
	this->stringLength = 1;
	this->memoryCapacity = 1;
}

MyString::MyString(const char* str)
{
	this->stringLength = strlen(str);
	this->stringContent = new char[this->stringLength];
	for (int i = 0; i != this->stringLength; i++)
	{
		this->stringContent[i] = str[i];
	}
	this->memoryCapacity = this->stringLength;
}

MyString::MyString(const MyString& str)
{
	this->stringLength = str.stringLength;
	for (int i = 0; i != this->stringLength; i++)
	{
		this->stringContent[i] = str.stringContent[i];
	}
	this->memoryCapacity = str.stringLength;
}

MyString::~MyString()
{
	delete[] this->stringContent;
}

int MyString::Length() const
{
	return this->stringLength;
}

void MyString::Print() const
{
	for (int i = 0; i != this->stringLength; i++)
	{
		std::cout << this->stringContent[i];
	}
}

void MyString::Println() const
{
	for (int i = 0; i != this->stringLength; i++)
	{
		std::cout << this->stringContent[i];
	}

	std::cout << std::endl;
}

MyString& MyString::Assign(const MyString& str)
{
	if (str.stringLength > this->memoryCapacity)
	{
		delete[] this->stringContent;
		this->stringContent = new char[str.stringLength];
		this->memoryCapacity = str.stringLength;
	}
	for (int i = 0; i != str.stringLength; i++)
	{
		this->stringContent[i] = str.stringContent[i];
	}
	this->stringLength = str.stringLength;
	return *this;
}

MyString& MyString::Assign(const char* str)
{
	int strLength = strlen(str);
	if (strLength > this->memoryCapacity)
	{
		delete[] this->stringContent;
		this->stringContent = new char[strLength];
		this->memoryCapacity = strLength;
	}
	for (int i = 0; i != strLength; i++)
	{
		this->stringContent[i] = str[i];
	}
	this->stringLength = strLength;
	return (*this);
}

int MyString::Capacity() const
{
	return this->memoryCapacity;
}

void MyString::Reserve(int size)
{
	if (size > this->memoryCapacity)
	{
		char* prevStringContent = this->stringContent;
		this->stringContent = new char[size];
		this->memoryCapacity = size;
		for (int i = 0; i != this->stringLength; i++)
			this->stringContent[i] = prevStringContent[i];
		delete[] prevStringContent;
	}
}

char MyString::At(int i) const
{
	if (i >= this->stringLength || i < 0)
		return NULL;
	else
		return this->stringContent[i];
}

MyString& MyString::Insert(int loc, const MyString& str)
{
	if (loc < 0 || loc > this->stringLength) return *this;
	if (this->stringLength + str.stringLength > this->memoryCapacity)
	{
		this->memoryCapacity = this->stringLength + str.stringLength;
		char* prevStringContent = this->stringContent;
		this->stringContent = new char[this->memoryCapacity];
		int i;
		for (i = 0; i < loc; i++)
		{
			this->stringContent[i] = prevStringContent[i];
		}

		for (int j = 0; j != str.stringLength; j++)
		{
			this->stringContent[i + j] = str.stringContent[j];
		}

		for (; i < this->stringLength; i++)
		{
			this->stringContent[str.stringLength + i] = prevStringContent[i];
		}

		delete[] prevStringContent;

		this->stringLength = this->stringLength + str.stringLength;
		return *this;
	}

	for (int i = this->stringLength - 1; i >= loc; i--)
	{
		this->stringContent[i + str.stringLength] = this->stringContent[i];
	}

	for (int i = 0; i < str.stringLength; i++)
	{
		this->stringContent[i + loc] = str.stringContent[i];
	}
	this->stringLength = this->stringLength + str.stringLength;
	return *this;
}

MyString& MyString::Erase(int loc, int num)
{
	if (num < 0 || loc < 0 || loc > this->stringLength) return *this;
	
	for (int i = loc + num; i < this->stringLength; i++)
	{
		this->stringContent[i - num] = this->stringContent[i];
	}
	this->stringLength -= num;
	return *this;
}

int MyString::Find(int findFrom, MyString& str) const
{
	int i, j;
	if (str.stringLength == 0) return -1;
	for (i = findFrom; i <= this->stringLength - str.stringLength; i++)
	{
		for (j = 0; j < str.stringLength; j++)
		{
			if (this->stringContent[i + j] != str.stringContent[j]) break;
		}

		if (j == str.stringLength) return i;
	}
	return -1;
}

int MyString::Find(int findFrom, const char* str) const
{
	MyString temp(str);
	return Find(findFrom, temp);
}

int MyString::Find(int findFrom, char c) const
{
	MyString temp(c);
	return Find(findFrom, temp);
}

int MyString::Compare(const MyString& str) const
{
	for (int i = 0; i < std::min(this->stringLength, str.stringLength); i++)
	{
		if (this->stringContent[i] > str.stringContent[i])
		{
			return 1;
		}
		else if (this->stringContent[i] < str.stringContent[i])
		{
			return -1;
		}
	}
	if (this->stringLength == str.stringLength) return 0;
	else if (this->stringLength > str.stringLength) return 1;
	return -1;
}

MyString::MyString()
{
	const char* defaultString = "Default Name";
	this->stringLength = strlen(defaultString);
	this->stringContent = new char[stringLength+1];
	this->stringContent = const_cast<char*>(defaultString);
	this->memoryCapacity = strlen(this->stringContent);
	this->stringLength = this->memoryCapacity;
}


int main()
{
	MyString myString;
	MyString myString2{ "AhnYeonghoo" };
	
	cout << myString.Length() << endl;
	myString.Println();
	
	return 0;
}