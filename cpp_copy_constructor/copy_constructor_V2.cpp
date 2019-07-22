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
    void setLength(int len);

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

void Line::setLength(int len)
{
    *ptr = len;
}

//对象以值传递方式传入函数体
void display(Line obj)
{
	cout << "Line 长度" << obj.getLength() << endl;
}

Line createLine(int len)
{
	cout << "调用createLine函数返回一个Line对象" << endl;
	Line ret(len);
	return ret;
}

int main()
{
    cout << "初始化line1" << endl;
	Line line1(10);
    cout << "用line1初始化line2" << endl;
    Line line2 = line1;
    
    cout << "更改line1的*ptr" << endl;
    line1.setLength(20);
	cout << "line1 *ptr = " << line1.getLength() << endl;
	cout << "line2 *ptr = " << line2.getLength() << endl;

	//display(line1);
    cout << "line2以值传递的方式传入函数体" << endl;
    display(line2);

	Line line3 = createLine(15);
	cout << "返回的line对象line3的*ptr = " << line3.getLength() << endl;

	system("pause");

	return 0;

    
}