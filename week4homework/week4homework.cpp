#include  <iostream>
#include<iomanip>
#include  <cmath>
using  namespace  std;

const  double  PI = 3.1415926;
//请在此处完善类的设计
class cylinder
{
public:
	double getvolumn();
	double getarea();
	cylinder ( double x,double y );
	~cylinder();
private:
	double a, b;
};

double cylinder::getvolumn()
{
	return (PI * b * b * a);
}
double cylinder::getarea()
{
	return (2 * PI * b * b + 2 * PI * b * a);
}
cylinder::cylinder(double x, double y)
{
	a = x;
	b = y;
	cout << "构造函数被调用" << endl;
}
cylinder::~cylinder()
{
	cout << "析构函数被调用" << endl;
}

int main()

{

	double d, h;

	cin >> d >> h;

	cylinder can(h, d / 2);

	cout << fixed << setprecision(6);

	cout << "油桶的容积是" << can.getvolumn() << " " << endl;

	cout << "铁皮的面积是" << can.getarea() << endl;

}