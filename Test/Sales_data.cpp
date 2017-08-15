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
// Sales_data �ӿڵķǳ�Ա��ɲ��ֵ�����
std::istream & read(std::istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;    //����ĳ�Ա�������޸ģ��������βζ���ǰû�м���const
	return is;
}

std::ostream & print(std::ostream &os, const Sales_data & item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " ";  //�����û�ж������ݽ����޸ģ��ɶ���const
	return os;
}

Sales_data & add(const Sales_data &a, const Sales_data &b)
{
	Sales_data sum = a;
	sum.combine(b);
	return sum;
}