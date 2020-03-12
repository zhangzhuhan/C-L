#include  <iostream>
#include<iomanip>
#include  <cmath>
using  namespace  std;

const  double  PI = 3.1415926;
//请在此处完善类的设计
class barrel
{
public:
	double getvolumn();
	double getarea();
	void init(double x, double y);
private:
	double a, b;
};
void barrel :: init(double x, double y)
{
	a = x;
	b = y;

}
double barrel::getvolumn()
{
	return (PI * b * b * a);
}
double barrel::getarea()
{
	return (2 * PI * b * b + 2 * PI * b * a);
}


int  main()
{
	double  d, h;
	cin >> d >> h;
	barrel can;



	can.init(h, d / 2);
	cout << fixed << setprecision(6);
	cout << "油桶的容积是" << can.getvolumn() << "  " << endl;
	cout << "铁皮的面积是" << can.getarea() << endl;
}
