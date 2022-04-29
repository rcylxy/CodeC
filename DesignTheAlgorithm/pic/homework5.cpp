#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[])
{
  int winC = 0;
  int loseC = 0;
  int aid = 0;
  srand((unsigned int)time(0));
  int first = rand() % 6 + 1;
  int second = rand() % 6 + 1;
  // printf("(%d,%d)", first, second);
  aid = first + second;
  if (aid == 7 || aid == 11)
  {
    printf("you win it\n");
    return 0;
  }
  else
  {
    if (aid == 2 || aid == 3 || aid == 12)
    {
      printf("you lose it\n");
      return 0;
    }
    else
    {
      while (1)
      {
        first = rand() % 6 + 1;
        second = rand() % 6 + 1;
        if (aid == first + second)
        {
          printf("you win it\n");
          break;
        }
        else if (first + second == 7)
        {
          printf("you lose it\n");
          break;
        }
      }
    }
  }
  return 0;
}