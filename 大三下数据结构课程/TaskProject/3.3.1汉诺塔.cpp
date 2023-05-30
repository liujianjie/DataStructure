#include <iostream>
#include <cstdio>
using namespace std;

int cnt;

void move(int id, char from, char to) // 打印移动方式：编号，从哪个盘子移动到哪个盘子
{
    printf("step %d: move %d from %c->%c\n", ++cnt, id, from, to);
}

void hanoi(int n, char a, char b, char c)
{
    if (n == 0)
        return;
    hanoi(n - 1, a, c, b);
    move(n, a, c);
    hanoi(n - 1, b, a, c);
}

int main()
{
    int n;
    cnt = 0;
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}