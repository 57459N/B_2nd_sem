#include <cmath>
#include <cstdint>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

#include "Functions.h"

using namespace std;

int dig_num(uint64_t num, int pos)
{
	return uint64_t(num / uint64_t(pow(10, pos - 1))) % 10;
}


int len(int num)
{
	int len = 0;

	while (num)
	{
		num /= 10;
		len++;
	}
	return len;
}

bool isPrime(int num)
{
	for (int i = 2, end = sqrt(num); i <= end; i++)
	{
		if (num % i == 0)
			return false;
	}		
	return num > 1;
}

int sum_of_digits(int num)
{
	int sum = 0;

	for (int i = 1; i <= len(num); i++)
	{
		sum += dig_num(num, i);
	}
	return sum;
}

unsigned long long factorial(unsigned long long num) 
{
	if (num == 1)
	{
		return 1;
	}
	else 
	{
		return num * factorial(num - 1);	
	}
}

void load(string* names, string* surnames, string* patronymics, string sex)
{
	setlocale(LC_ALL, "Russian");
	string line;

	ifstream Names("..\\" + sex + "_names.txt");

	if (Names.is_open())
	{	
		int i = 0;
		while (getline(Names, line))
		{
			names[i] = line;
			i++;
		}

	}
	Names.close();

	
	ifstream Surnames("..\\" + sex + "_surnames.txt");

	if (Surnames.is_open())
	{
		
		int i = 0;
		while (getline(Surnames, line))
		{
			surnames[i] = line;
			i++;
		}

	}
	Surnames.close();

	ifstream Patronymics("..\\" + sex + "_patronymics.txt");

	if (Patronymics.is_open())
	{

		int i = 0;
		while (getline(Patronymics, line))
		{
			patronymics[i] = line;
			i++;
		}

	}
	Patronymics.close();

}
