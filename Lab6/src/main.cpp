#include "../headers/solve.h"

int main()
{
  while(Restart())
  {
    int task = Choose(1,3);
    Laba(task);
  }
  return 0;
}