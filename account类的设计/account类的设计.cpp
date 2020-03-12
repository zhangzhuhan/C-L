#include  <iostream>
#include  <iomanip>

using namespace  std;
//请在此处补充Account类的定义

int detection(double a)
{
    int b;
    b = a * 100;
    if (b - a * 100 == 0)//2位
        return 0;
    else
        return 1;//>2位
}
class Account
{
public:
    void init(const char a[], const char b[], const char c[], int d, double e);
    void printmoney();
    double deposit(double a);
    double withdraw(double a);
private :
    char id[20] = { 0 }, name[20] = { 0 }, sex[2] = { 0 };
    int age;
    double dp;
};
void Account:: init(const char a[], const char b[], const char c[], int d, double e)
{
    int i;
    for (i = 0; a[i] != '\0'; i++)
        id[i] = a[i];
    for (i = 0; b[i] != '\0'; i++)
        name[i] = b[i];
    for (i = 0; c[i] != '\0'; i++)
        sex[i] = c[i];
    age = d;
    if (detection(e))
    {
        dp = 0;
        cout << "您输入的金额不合法" << endl;
    }
    else
        dp = e;
}

void Account::printmoney()
{
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << name<< "的存款为"<<dp << endl;
}

double Account::deposit(double a)
{
    if (detection(a))
    {
        cout << "您输入的金额不合法" << endl;
        return dp;
    }
    else 
    {
        dp = dp + a;
        return dp;

    }
       

}
double Account::withdraw(double a)
{
    if (detection(a))
    {
        cout << "您输入的金额不合法" << endl;
        return dp;
    }
    else if (a > dp)
    {
        cout << "您的存款金额不足" << endl;
        return dp;
    }
    else
    {
        dp = dp - a;
        return dp;
    }
        
}

int  main()
{
    Account  tom;
    tom.init("32020320011001876X", "Tom  Black", "男", 19, 2000.89);
    tom.printmoney();//输出：Tom  Black的存款为2000.89
    tom.deposit(89.471);//输出：您输入的金额不合法
    tom.printmoney();//输出：Tom  Black的存款为2000.89
    tom.deposit(10000);
    tom.printmoney();//输出：Tom  Black的存款为12000.89
    tom.withdraw(10001);
    tom.printmoney();//输出：Tom  Black的存款为1999.89
    tom.withdraw(10000.123);//输出：您输入的金额不合法
    tom.printmoney();//输出：Tom  Black的存款为1999.89
    tom.withdraw(10000.9);//输出：您的存款金额不足
    tom.printmoney();//输出：Tom  Black的存款为1999.89
    Account  jerry;
    jerry.init("320203200910116569", "Jerry  Black", "女", 11, 100.956);//输出：您输入的金额不合法
    jerry.printmoney();//输出：Jerry  Black的存款为0.00
}

