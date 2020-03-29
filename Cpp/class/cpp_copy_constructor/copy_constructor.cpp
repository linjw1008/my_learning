//拷贝构造函数

#include <iostream>

using namespace std;

class Line
{
public:
	int getLength(void);
	Line(int len);  //构造函数
	Line(const Line &obj);  //拷贝构造函数
	~Line();

private:
	int *ptr;
};

// 构造函数
Line::Line(int len)
{
	cout << "调用构造函数，为指针ptr分配内存" << endl;
	ptr = new int;
	*ptr = len;
	cout << "*ptr = " << *ptr << endl;
}

// 拷贝构造函数
Line::Line(const Line &obj)
{
	cout << "调用拷贝构造函数，为指针ptr分配内存" << endl;
	ptr = new int;
	*ptr = *obj.ptr;
	cout << "拷贝值 *ptr = " << *ptr << endl;
}

Line::~Line(void)
{
	cout << "释放内存" << endl;
	delete ptr;
}

int Line::getLength(void)
{
	return *ptr;
}

void display(Line obj)
{
	cout << "Line 长度" << obj.getLength() << endl;
}

int main()
{
	Line line(10);

	display(line);

	system("pause");

	return 0;
}