// 钢条切割的递归方案
// 钢条的长度价格对应表:
// 长度i	1	2	3	4	5	6	7	8	9	10
// 价格pi	1	5	8	9	10	17	17	20	24	30
// 使用公式rn = max(pi + r(n-i)),1<=i<=n进行求解

#include <stdio.h>
#include <stdlib.h>

int cutRod(int p[], int n, int s[]);

int max(int a, int b)
{
    return (a > b ? a : b);
}
int main(void)
{
    int p[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int r = 0;
    int s[11];

    for (int i = 1; i <= 10; i++) {
        r = cutRod(p, i, s);
        printf("i: %d, r: %d=%d+%d\n", i, r, s[i], i - s[i]);
    }

    return 0;
}

int cutRod(int p[], int n, int s[])
{
    int *r = (int *)malloc(sizeof(int) * n);
    int q = 0;
    r[0] = 0;
    int i, j;

    for (j = 1; j <= n; j++) {
        q = -1;
        for (i = 1; i <= j; i++) {
            if (q < p[i] + r[j - i]) {
                q = p[i] + r[j - i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
    return r[n];
}
