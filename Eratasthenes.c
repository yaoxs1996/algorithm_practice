//求素数经典算法Eratasthenes（埃拉托塞尼）筛选法
/*算法思路：
（1）取最小的数2，声明其为素数，同时筛去它及其所有的倍数；
（2）取未筛去的数中的最小值，声明其为素数，同时筛去它及其所有倍数
（3）重复步骤（2），得到所有的素数*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int prime[201] = {0};       //求解200以内的所有素数
    int d;      //正因子
    int k;      //要筛去的数

    //合数n必有一个小于√n的正因子。若一个数没有小√n的正因子，则为素数
    //由n->√n，优化，提高筛选效率
    for(d=2; d<=sqrt(200); d++)
    {
        if(prime[d] == 0)
        {
            //筛去d所有的倍数
            for(k=2*d; k<=200; k=k+d)
            {
                prime[k] = 1;       //将合数置1
            }
        }
    }

    //输出
    k = 0;
    for(int i=2; i<=200; i++)
    {
        if(prime[i] == 0)
        {
            printf("%d\t", i);
            k++;
            if(k%5 == 0)
            {
                printf("\n");
            }
        }
    }
    printf("\n");

    system("pause");
    return 0;
}
