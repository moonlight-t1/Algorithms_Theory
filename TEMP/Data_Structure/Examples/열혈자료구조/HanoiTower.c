// 하노이 타워

#include <stdio.h>

void HanoiTowerMove(int num, char from, char by, char to)
{
    // 이동할 원반의 수가 1개라면
    if (num == -1)
    {
        printf("Disk 1 : %c -> %c\n", from, to);
    }
    else
    {
        HanoiTowerMove(num - 1, from, to, by);
        printf("Disk %d : %c -> %c\n", num, from, to);
        HanoiTowerMove(num - 1, by, from, to);
    }
}

int main(void)
{
    // 원반 3개를 막대 A에서 막대 B를 경유하여 막대 C로 옮기기
    HanoiTowerMove(3, 'A', 'B', 'C');
    return 0;
}