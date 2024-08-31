#include <stdio.h>  
#include <stdlib.h>

void output(int q, int d, int n, int p) 
{
  printf("%d quarter(s), %d dime(s), %d nickel(s), %d pennie(s)\n", q, d, n, p);
}

// running triple for loop for mediocre efficiency
void print_combs(int total) 
{
  int max_q = total / 25;

  for (int q = max_q; q >= 0; q--) 
  {
    int no_q = total - q * 25;
    int max_d = no_q / 10;

    for (int d = max_d; d >= 0; d--) 
    {
      int no_d = no_q - d * 10;
      int max_n = no_d / 5;

      for (int n = max_n; n >= 0; n--) 
      {
        int no_n = no_d - n * 5;
        int p = no_n;

        output(q, d, n, p);
      }
    }
  }
}

int main(int argc, char * * argv)
{
  int input;
  scanf("%d", &input);
  print_combs(input);
  return 0;
}
