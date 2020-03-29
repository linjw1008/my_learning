class test
{
private:
    /* data */
public:
    test(/* args */);
    ~test();
    static int sint;
    
    //静态函数可以在类内部定义
    static int staticfunc()
    {

    }
};

test::test(/* args */)
{
}

test::~test()
{
}

//静态变量只能在类外面初始化
int test::sint = 0;


