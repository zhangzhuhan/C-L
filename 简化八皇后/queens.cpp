//2020.2.27 c++��һ����ҵ �򻯰�˻ʺ�����





#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    char a[9] = { 0 };
    int i, j=420, k, flag=0;//��420����1~8��ASC��ֵ��ӣ�flag��״̬��ʾ�Ƿ����������ڶԽ����ϣ�
    for (i = 0; i < 8; i++)
        cin >> a[i];����������//�����ַ����飻
    for (i = 0; i < 8; i++)
    {
        if (a[i] == '*')
            k = i;            //��k��ס*�ŵ�λ�ã�
    }

    for(i=0;i<k;i++)
        j = j - int (a[i]);
    for (i = k + 1; i < 8; i++)
        j = j - int(a[i]); 
     a[k] = j;                //420��ȥ*�������7������asc���룬�õ�*�������������asc����

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (i != j && abs(i - j) == abs(a[i] - a[j])) //�Ƚ����������Ƿ��ڶԽ����ϣ�
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



