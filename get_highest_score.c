#include<stdio.h>
#include<stdlib.h>

int main()
{
    int score[10] = {99, 101, 99, 100, 98, 100, 21, 98, 99, 100};
    int max_score = 0;
    int stu_num = 0;

    for(int i=0; i<10; i++)
    {
        if(score[i] > max_score)
        {
            max_score = score[i];
            stu_num = 1;
        }
        else if(score[i] == max_score)
        {
            stu_num++;
        }
    }
    printf("There are %d students get highest score\n", stu_num);

    system("pause");
    return 0;
}
