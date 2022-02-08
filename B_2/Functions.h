#pragma once
using namespace std;

#include <cstdint>
#include <string>

int dig_num(uint64_t num, int pos);

int len(int num);

bool isPrime(int num);

int sum_of_digits(int num);

unsigned long long factorial(unsigned long long num);

void load(string* names, string* surnames, string* patronymics, string sex = "male");



