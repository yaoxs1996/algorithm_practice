```c
/*求解最小公倍数 辗转相除*/
int least_common_multiple(int m, int n)
{
    int temp = 0;
    int num_1, num_2;
    
    //确保大小关系
    if(m > n)
    {
        temp = m;
        m = n;
        n = temp;
    }
    num_1 = m;
    num_2 = n;

    //辗转相除
    while(num_2 != 0)
    {
        temp = num_1 % num_2;
        num_1 = num_2;
        num_2 = temp;
    }
    return m*n/num_1;
}
```

```c
/*4.2 开灯关灯问题*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n = 10;
    int lamp[11] = {0};     //11 = n+1
    int d = 1;      //倍数

    for(int i=1; i<=10; i++)        //lamp[0]舍弃不用，方便计算
    {
        d = 1;
        while(i*d <= 10)        //处理倍数
        {
            lamp[i*d] = !lamp[i*d];
            ++d;
        }
    }

    for(int j=1; j<=10; j++)
    {
        printf("%d ", lamp[j]);
    }

    system("pause");
    return 0;
}
```

```c
/*6.7 判断完备数*/
int k[20];

void find(int m)
{
    int sum = 0;
    int n = 0;
    for(int i=1; i<m; i++)
    {
        if(m % i == 0)
        {
            sum = sum+i;        //教材使用的是sum=sum-i，最后判断sum==0
            k[n++] = i;
        }
    }
    if(sum == m)
    {
        printf("%d is perfect number: ", m);
        for(int i=0; i<n; i++)
        {
            printf("%d, ", k[i]);
        }
        printf("\n");
    }
}
```

```c
/*求互满数*/
#include<stdio.h>
#include<stdlib.h>

int factor(int m)
{
    int sum = 0;
    for(int i=1; i<m; i++)
    {
        if(m % i == 0)
        {
            sum = sum+i;
        }
    }
    return sum;
}

int main()
{
    int i, j;
    //原算法双层嵌套，效率极低
    for(i=1; i<30000; i++)
    {
        j = factor(i);
        if(j>i && factor(j) == i)
        {
            printf("%d and %d is friend number\n", i, j);
        }
    }

    system("pause");
    return 0;
}
```

```c
/*求解最大公约数与最小公倍数*/
void solution(int m, int n)
{
    int lcm, gcd;       //least common mutliple, greatest common divisor
    int temp = m % n;
    
    //辗转相除法求最大公约数
    while(temp != 0)
    {
        m = n;
        n = temp;
        temp = m % n;
    }
    gcd = n;
    lcm = (m*n)/gcd;        //最小公倍数等于两数之积除最大公约数

    printf("%d is gcd, %d is lcm\n", gcd, lcm);
}
```

