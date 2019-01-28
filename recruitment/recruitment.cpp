#include <iostream>
#include <string>

using namespace std;

// Questions I was asked at interview
// Well maybe I will also post here some questions I regret I was never asked.

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
// For example, if the input number is "2 3 5 4 5", the output should be "2 3 6 3 2".
// If the input number is "9 9 9", the output should be "1 0 0 1".

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
	int middle;
	if (size % 2 != 0)
	{
		middle = size / 2 + 1;
	}
	else
	{
		middle = size / 2;
	}

	number = number.substr(0, middle);

	return number;
}

string appendReversed(string& number)
{
	auto size = number.size();

	for (int i = 0; i < size; i++)
	{
		auto digit = number.at(size - i);
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

void threeDimensionalArrayInCpp()
{
    int dimX = 100; int dimY = 100; int dimZ = 100;
    int*** array;    // 3D array definition;
    // begin memory allocation
    array = new int**[dimX];
    for(int x = 0; x < dimX; ++x)
    {
        array[x] = new int*[dimY];
        for(int y = 0; y < dimY; ++y)
        {
            array[x][y] = new int[dimZ];
            for(int z = 0; z < dimZ; ++z)
            {
                // initialize the values to whatever you want the default to be
                array[x][y][z] = 0;
            }
        }
    }
}

int main()
{
	// TODO
	// Edge case like "9999" and some more testing.
	// Beside that could be good to integrate those interview questions with some testing plugin to visual studio.
	string number = to_string(123);
	nextSmallestPalindrome(number);
	system("pause");
    return 0;
}

