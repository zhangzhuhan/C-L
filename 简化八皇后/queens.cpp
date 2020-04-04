//2020.2.27 c++第一次作业 简化版八皇后问题





#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    char a[9] = { 0 };
    int i, j=420, k, flag=0;//“420”是1~8的ASC码值相加；flag的状态表示是否有两个棋在对角线上；
    for (i = 0; i < 8; i++)
        cin >> a[i];　　　　　//输入字符数组；
    for (i = 0; i < 8; i++)
    {
        if (a[i] == '*')
            k = i;            //用k记住*号的位置；
    }

    for(i=0;i<k;i++)
        j = j - int (a[i]);
    for (i = k + 1; i < 8; i++)
        j = j - int(a[i]); 
     a[k] = j;                //420减去*号以外的7个数的ascⅡ码，得到*号所代表的数的ascⅡ码

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (i != j && abs(i - j) == abs(a[i] - a[j])) //比较任意两棋是否在对角线上；
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 1)
        cout << "No Answer" << endl;
    if (flag == 0)
        cout << a[k];
}



