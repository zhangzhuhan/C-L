

#include  <iostream>
#include  <cmath>
using  namespace  std;


int  isPrime(long  num)
{
    int i, flag=1;
    for (i = 2; i * i < num; i++)
    {
        if (num % i == 0)
        {
            flag = 0; break;
        }
    }
    return flag;
}
void  factorization(long  n,long factor[], int & numofFactor)//long *factor也行
{
    int i,j=0;
    
    
    for (i = 2; i <= n; i++)
    {
        if (n % i == 0 && isPrime(i))
        {
            n = n / i; 
            numofFactor++; 
            factor[j] = i; 
            j++;
            i--;
                
        }
    }
    
    return;
}
int  main()
{
    long  n;
    long  factor[100];
    int  numofFactor = 0;
    cin >> n;
    factorization(n, factor, numofFactor);
    for (int i = 0; i < numofFactor; i++)
    {
        cout << factor[i] << "  ";
    }
    cout << endl;
    return  0;
}