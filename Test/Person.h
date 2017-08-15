#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>

//class person
class Person
{
	friend std::istream & per_read(std::istream, Person &);
	friend std::istream & per_print(std::istream, Person &);
public:
	//constructor 
	Person() = default;
	Person(const std::string &sname, const std::string saddr) :name(sname), address(saddr) {}
	Person(std::istream &is) { per_read(is, *this); }

	//member function
	std::string get_name() const { return name; }
	std::string get_address() const { return address; }

private:
	std::string name;    //人员的名字
	std::string address; //人员的地址

};

//class person friend functions definition
std::istream & per_read(std::istream is, Person & a)
{
	is >> a.name >> a.address;
	return is;
}

std::ostream & per_print(std::ostream os, const Person & a)
{
	os << a.get_name() << " " << a.get_address();
	return os;
}

//declaraion  of the nonmember functions
std::istream & per_read(std::istream, Person &);
std::istream & per_read(std::istream, Person &);


#endif // !SALES_DATA_H