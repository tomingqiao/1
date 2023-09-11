#include <stdio.h>

double GP(int n) // 计算单个课程的绩点
{
    if (n >= 50) // n<50时，为负数
    {
        return (n - 50) / 10.0;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n, grade;
    double credit_hour = 0;
    printf("请输入课程数：>\n");
    scanf("%d", &n);

    int i = 0;
    double sum = 0.00;
    double count = 0.00;

    for (i = 1; i <= n; i++)
    {
        printf("请输入学分和成绩：> (空格隔开)\n");
        scanf("%lf %d", &credit_hour, &grade);
        sum += credit_hour * GP(grade); // 学分绩点乘积总和
        count += credit_hour;           // 学分总和
    }
    printf("您输入的学分总数为：%.2f\n", count);
    printf("您的平均学分绩点为：%.2f", sum / count * 1.0);
    return 0;
}