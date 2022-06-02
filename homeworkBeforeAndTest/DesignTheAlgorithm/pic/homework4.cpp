#include <stdio.h>
void printResult(int ret[3][3], int nonsense)
{
  printf("A Teacher:%d Student:%d Worker:%d\n", ret[0][0], ret[0][1], ret[0][2]);
  printf("B Teacher:%d Student:%d Worker:%d\n", ret[1][0], ret[1][1], ret[1][2]);
  printf("C Teacher:%d Student:%d Worker:%d\n", ret[2][0], ret[2][1], ret[2][2]);
  printf("废票：%d\n", nonsense);
}
int main()
{
  int ret[3][3] = {0};
  char ch;
  int In = 0;
  int nonsense = 0;
  while (1)
  {
    scanf("%c", &ch);
    scanf("%d", &In);
    if (In > 3 || In <= 0)
    {
      nonsense++;
    }
    else if (In <= 3)
    {
      switch (ch)
      {
      case 'A':
        ret[0][In - 1]++;
        break;
      case 'B':
        ret[1][In - 1]++;
        break;
      case 'C':
        ret[2][In - 1]++;
        break;
      default:
        nonsense++;
        break;
      }
    }
    printResult(ret, nonsense);
    getchar();
  }
}