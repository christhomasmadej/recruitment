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
// For example, if the input number is �2 3 5 4 5�, the output should be �2 3 6 3 2�.
// If the input number is �9 9 9�, the output should be �1 0 0 1�.

bool isPalindrome(string& number)
{
	auto result = true;
	auto size = number.size();

	auto begin = number.begin();
	auto end = number.end() - 1;

	while (result && begin <= end)
	{
		result = *begin == *end ? true : false;
		begin++;
		end--;
	}

	return result;
}

string sliceInHalf(string& number)
{
	auto size = number.size();
	auto middle = size / 2;

	number = number.substr(0, middle);

	return number;
}

string appendReversed(string& number)
{
	auto size = number.size();

	for (int i = 0; i < size; i++)
	{
		auto digit = number.at(size - 1 - i);
		number.push_back(digit);
	}

	return number;
}

void makePalindrome(string& number)
{
	sliceInHalf(number);
	appendReversed(number);
}

void makePalindromeWithIncrement(string& number)
{
	sliceInHalf(number);
	number = to_string(stoi(number)+1);
	appendReversed(number);
}

bool greaterThanInitialValue(const string& initialValue, const string& newValue)
{
	auto initialV = stoi(initialValue);
	auto newV = stoi(newValue);
	return newV > initialV;
}


void nextSmallestPalindrome(string& number)
{
	auto initialValue = number;
	while (!isPalindrome(number) && !greaterThanInitialValue(initialValue, number))
	{
		makePalindrome(number);

		if (!greaterThanInitialValue(initialValue, number))
		{
			makePalindromeWithIncrement(number);
		}
	}

	cout << number << endl;
}

// 3. Dynamic 2-D array in C & C++
void twoDimensionalArrayInC()
{
	int rows = 5, columns = 10;
	int** a = (int**)malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++) 
	{
		a[i] = (int*)malloc(columns * sizeof(int));
	}
}

void twoDimensionalArrayInCpp()
{
	int rows = 5, columns = 10;
	int** a = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		a[i] = new int[columns];
	}
}

int main()
{
	string number = to_string(12345);
	nextSmallestPalindrome(number);
	system("pause");
    return 0;
}

