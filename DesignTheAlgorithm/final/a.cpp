#include <bits/stdc++.h>
using namespace std;
int n, answer;
char MP[100][100];

bool check(int x, int y)
{
  for (int i = y - 1; i >= 0; i--)
  {
    if (MP[x][i] == 'X')
    {
      break;
    }

    if (MP[x][i] == '*')
    {
      return 0;
    }
  }
  for (int i = x - 1; i >= 0; i--)
  {
    if (MP[i][y] == 'X')
    {
      break;
    }
    if (MP[i][y] == '*')
    {
      return 0;
    }
  }
  return 1;
}

void dfs(int m, int tmp)
{
  if (m >= n * n)
  {
    answer = max(answer, tmp);
    return;
  }
  else
  {
    int x = m / n;
    int y = m % n;
    if (MP[x][y] == '.' && check(x, y))
    {
      MP[x][y] = '*';
      dfs(m + 1, tmp + 1);
      MP[x][y] = '.';
    }
    dfs(m + 1, tmp);
  }
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> MP[i][j];
    }
  }

  dfs(0, 0);
  cout << answer;
  return 0;
}
