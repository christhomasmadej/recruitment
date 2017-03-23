// Questions I was asked at interview

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

// 1. Implement singleton
class Singleton
{
public:
	static Singleton& getInstance()
	{
		static Singleton instance;
		return instance;
	}

private:
	Singleton() {}

public:
	Singleton(Singleton const& s) = delete;
	void operator=(Singleton const& s) = delete;
};

// 2. Find nextClosestPalindrome
// Given a number, find the next smallest palindrome larger than this number. 
// For example, if the input number is “2 3 5 4 5”, the output should be “2 3 6 3 2”.
// If the input number is “9 9 9”, the output should be “1 0 0 1”.

bool isPalindrome(int n)
{
	auto result = true;
	auto number = to_string(n);
	auto size = number.size();

	for (auto begin = number.begin(), end = number.end()-1; begin <= end; begin++, end--)
	{
		result = *begin == *end ? true : false;
	}

	return result;
}

int makeReflectionViaMiddle(int arg)
{
	auto number = to_string(arg);
	auto size = number.size();
	auto middle = size / 2;

	number = number.substr(0, middle);

	for (int i = 0; i < middle; i++)
	{
		auto digit = number.at(middle - 1 - i);
		number.push_back(digit);
	}

	return stoi(number);
}

void nextSmallestPalindrome(int arg)
{
	bool condition = true;
	auto initialArg = arg;
	while (condition)
	{
		arg = makeReflectionViaMiddle(arg);
		if (isPalindrome(arg) && arg > initialArg)
		{
			condition = false;
		}
		else
		{
			//TODO case 999
			auto number = to_string(arg);
			auto size = number.size();
			auto middle = size / 2;
			number = number.substr(0, middle);
			arg = stoi(number);
			arg++;
			number = to_string(arg);
			for (int i = 0; i < middle; i++)
			{
				number.push_back('0');
			}
			arg = stoi(number);
		}
	}
	cout << arg << endl;
}

int main()
{
	nextSmallestPalindrome(999);
	system("pause");
    return 0;
}

