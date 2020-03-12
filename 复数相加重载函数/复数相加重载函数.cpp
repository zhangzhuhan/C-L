﻿#include  <iostream>
#include  <iomanip>
using  namespace  std;

struct  complex
{
    double  r;
    double  i;
};
struct complex add(struct complex a, struct complex b)
{
    struct complex c;
    c.r = a.r + b.r;
    c.i = a.i + b.i;
    return c;

}
struct complex add(struct complex a, double num)
{
    struct complex c;
    c.r = a.r + num;
    c.i = a.i;
    return c;

}
struct complex  add( double num,struct complex b)
{
    struct complex c;
    c.r = b.r + num;
    c.i = b.i;
    return c;
}



int  main()
{
    double  num;
    complex  a, b, c;
    cin >> a.r >> a.i;
    cin >> b.r >> b.i;
    cin >> num;
    c = add(a, b);
    cout << c.r << "+" << c.i << "i" << endl;
    c = add(a, num);
    cout << c.r << "+" << c.i << "i" << endl;
    c = add(num, b);
    cout << c.r << "+" << c.i << "i" << endl;
}