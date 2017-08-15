#include "Sales_data.h"

//public constructor function definition
/*normal constructor
Sales_data::Sales_data(std::istream &is)
{
	read(is, *this);
}*/

//delegting constructor
Sales_data::Sales_data(std::istream &is) : Sales_data()
{
	read(is, *this);
}

//public member function
Sales_data & Sales_data::combine(const Sales_data & rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue * rhs.units_sold;
	return *this;
}


// friend function definition
// Sales_data 接口的非成员组成部分的声明
std::istream & read(std::istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;    //对类的成员进行了修改，所以在形参定义前没有加上const
	return is;
}

std::ostream & print(std::ostream &os, const Sales_data & item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " ";  //输出并没有对类内容进行修改，可定义const
	return os;
}

Sales_data & add(const Sales_data &a, const Sales_data &b)
{
	Sales_data sum = a;
	sum.combine(b);
	return sum;
}