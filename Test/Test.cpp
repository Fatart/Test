#include "Sales_data.h"
#include "account.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;



class Account 
{
public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double);
private:
	std::string owner;          //每一个对象拥有一个
	double amount;              //每一个对象拥有一个
	static double interestRate; //一个类拥有一个
	//static double initRate();
};

void Account::rate(double newRate)
{
	interestRate = newRate;
}

double Account::interestRate = 1.0;

istream &func(istream &is)
{
	std::string buf;
	while (is >> buf)
	{
		std::cout << buf << std::endl;
	}
	is.clear();
	return is;
}


int main()
{
	istream &is = func(std::cin);
	std::cout << is.rdstate() << std::endl;
	return 0;
}