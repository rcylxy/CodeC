#include <iostream>
using namespace std;
int full_ERROR(int n)
{
  if (n == 1)
    return 0;
  if (n == 2)
    return 1;
  return (n - 1) * (full_ERROR(n - 1) + full_ERROR(n - 2));
}
int main()
{
  int n, res;
  cin >> n;
  res = full_ERROR(n);
  cout << res;
  return 0;
}
