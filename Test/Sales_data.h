#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <vector>


//----------------------------------------------------------------------------------------------
class Sales_data
{
	friend std::istream & read(std::istream &is, Sales_data &item);
	friend std::ostream & print(std::ostream &os, const Sales_data & item);
	friend Sales_data & add(const Sales_data &a, const Sales_data &b);

public:
	/*normal constructor
	//constructor
	Sales_data() = default;
	//Sales_data(std::istream &is = std::cin) { read(is, *this); }
	Sales_data(const std::string &s) : bookNo(s) {} //use constructor initialize list
	Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n*p) {} //输入 ISBN编号，销售数量，书籍单价，对成员变量初始化
	Sales_data::Sales_data(std::istream &is);
	*/

	// delegating constructor
	Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n*p) {}
	Sales_data() :Sales_data(" ", 0, 0.0f) {}
	explicit Sales_data(const std::string &s) : Sales_data(s, 0, 0.0f) {}
	explicit Sales_data(std::istream &is);  //explicit constructor doesn't allow class type conversation, and only can be initialized directly


	// member function
	std::string isbn() const { return bookNo; } //const用于修改隐式this指针类型
	Sales_data& combine(const Sales_data& rhs);


private:
	inline double avg_price() const;

private:
	std::string bookNo;       //书籍ISBN编号
	unsigned units_sold = 0;  //销售数量
	double revenue = 0.0;     //总销售收入（总动计算 书籍数量*书记单价）
};

//private member function
inline
double Sales_data::avg_price() const
{
	return units_sold ? revenue / units_sold : 0;
}


// declarations for nonmember parts of the Sales_data interface.
std::istream & read(std::istream &is, Sales_data &item);
std::ostream & print(std::ostream &os, const Sales_data & item);
Sales_data & add(const Sales_data &a, const Sales_data &b);

//end-of-class-Sales_data







//----------------------------------------------------------------------------------------------
class Screen;

class Window_mgr {
public:
	// typedef std::vector<Screen>::size_type ScreenIndex
	using ScreenIndex = std::vector<Screen>::size_type;   //screenIndex 表示第几屏
	void clear(ScreenIndex);
private:
	std::vector<Screen> screens;  //这里不能 使用{row,col,'x'}构造初始化，vs编译不过
};


//----------------------------------------------------------------------------------------------
class Screen {
	//friend class Window_mgr;                    //定义 Window_mgr为 Screen类的友元类
	friend void Window_mgr::clear(ScreenIndex i); //定义 Window_mgr的函数clear为 Screen的友元函数，可以访问包括非公有成员在内的所有成员
public:
	//typedef std::string::size_type pos;
	using pos = std::string::size_type;
	//constructor
	Screen() = default;
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht*wd, ' ') {}
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c) {}   //使用字符c，填充height x width 大小的空间

	//member function
	char get() const { return contents[cursor]; }      //cursor处的字符
	char get(pos r, pos c) const { return contents[r*width + c]; } // 返回第r行(row)第c列(column)的字符

	inline Screen &curmove(pos r, pos c);
	inline Screen &set(char);  //设置光标处的char
	inline Screen &set(pos, pos, char);  //设置第row行，第column列的字符
		
	const Screen &display(std::ostream &os) const { do_display(os); return *this; }
	Screen& display(std::ostream &os)  { do_display(os); return *this; }

private:
	void do_display(std::ostream &os) const { os << contents; }

private:
	pos cursor = 0;             //the postion of cursor of the screen , 类内初始值为0
	pos height = 0, width = 0;  //the height and width of the screen，类内初始值为0
	std::string contents;       //screen's contents，in-class initializer is empty string
};

//It's mandatory for clear function to put under the definition of Screen class, because the Vs compiler take the class Screen  declaration as the empty class definition.
inline void Window_mgr::clear(ScreenIndex i)   //it is mandatory to define inline out of class definition
{
	if (i >= screens.size()) return;    //judge for out_of_range
	Screen &s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}



//member function definition
inline Screen & Screen::curmove(pos r, pos c)
{
	cursor = r*width + c;
	return *this;
}

inline Screen & Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}
inline Screen & Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;
	return *this;
}


//--------------------------------------------------------
//class Example
//{
//public:
//	static constexpr double rate = 6.5;
//	static const int vecSize = 20;
//	static vector<double> vec(vecSize);
//
//private:
//
//};





#endif // !SALES_DATA_H