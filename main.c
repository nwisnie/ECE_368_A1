#include <stdio.h>  
#include <stdlib.h>

void print_combination(int q, int d, int n, int p) 
{
  printf("%d quarter(s), %d dime(s), %d nickel(s), %d pennie(s)\n", q, d, n, p);
}

void print_combs(int cents) 
{
  int i, j;
  int max_q = cents / 25;

  for (i = max_q; i >= 0; i--) 
  {
    int no_q = cents - i * 25;
    int max_d = no_q / 10;

    for (j = max_d; j >= 0; j--) 
    {
      int no_d = no_q - j * 10;
      int max_n = no_d / 5;

      for (int k = max_n; k >= 0; k--) 
      {
        int no_n = no_d - k * 5;
        int p = no_n;

        print_combination(i, j, k, p);
      }
    }
  }
}

int main(int argc, char * * argv)
{
  // if (argc != 2) // check if exactly one input
  // {
  //   printf("incorrect input.");
  //   return 1;
  // }

  // int input = atoi(argv[1]); // converts input to int

  int input;

  scanf("%d", &input);

  print_combs(input);

  return 0;

  // determine optimal distribution 
  // put in variables because I don't feel like using array in recursion
  // int q = 0;
  // int d = 0;
  // int n = 0;
  // int p = 0;

  // while(input >= 25) // dumb implementation because I'm lazy
  // {
  //   input -= 25;
  //   q += 1;
  // }
  // while(input >= 10)
  // {
  //   input -= 10;
  //   d += 1;
  // }
  // while(input >= 5)
  // {
  //   input -= 5;
  //   n += 1;
  // }
  // while(input >= 1)
  // {
  //   input -= 1;
  //   n += 1;
  // }

  // // recur(q,d,n,p);
  // // essentially just a downcounter
  // printf("%d quarter(s), %d dime(s), %d nickel(s), %d pennie(s)\n",q,d,n,p);
  // while(q > 0 || d > 0 || n > 0)
  // {
  //   if(n) // count nickles
  //   {
  //     n -= 1;
  //     p += 5;
  //     printf("%d quarter(s), %d dime(s), %d nickel(s), %d pennie(s)\n",q,d,n,p);
  //     if(n == 0 && d > 0)
  //     {
  //       d -= 1;
  //       n += 2;
  //       while(p >= 5)
  //       {
  //         p -= 5;
  //         n += 1;
  //       }
  //       printf("%d quarter(s), %d dime(s), %d nickel(s), %d pennie(s)\n",q,d,n,p);
  //     }
  //   }
  //   else if(d)
  //   {
  //     d -= 1;
  //     n += 2;
  //     printf("%d quarter(s), %d dime(s), %d nickel(s), %d pennie(s)\n",q,d,n,p);
  //     if(d == 0 && q > 0)
  //     {
  //       q -= 1;
  //       d += 2;
  //       n += 1;
  //       while(p >= 5)
  //       {
  //         p -= 5;
  //         n += 1;
  //       }
  //       while(n >= 2)
  //       {
  //         n -= 2;
  //         d += 1;
  //       }
  //       printf("%d quarter(s), %d dime(s), %d nickel(s), %d pennie(s)\n",q,d,n,p);
  //     }
  //   }
  //   else if(q)
  //   {
  //     q -= 1;
  //     d += 2;
  //     n += 1;
  //     while(p >= 5)
  //     {
  //       p -= 5;
  //       n += 1;
  //     }
  //     while(n >= 2)
  //     {
  //       n -= 2;
  //       d += 1;
  //     }
  //     printf("%d quarter(s), %d dime(s), %d nickel(s), %d pennie(s)\n",q,d,n,p);
  //   }
  // }

  // return 0;
}
