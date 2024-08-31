#include <stdio.h>  
#include <stdlib.h>

// I'm putting the recursion function in the main file because I don't feel like making a second file
// Cry about it
void recur(int q, int d, int n, int p)
{

  printf("%d quarter(s), %d dime(s), %d nickel(s), %d pennie(s)\n",q,d,n,p);

  if(n)
  {
    recur(q,d,n-1,p+5);
  }
  else if(d)
  {
    recur(q,d-1,n+2,p);
  }
  else if(q)
  {
    recur(q-1,d+2,n+1,p);
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

  // determine optimal distribution 
  // put in variables because I don't feel like using array in recursion
  int q = 0;
  int d = 0;
  int n = 0;
  int p = 0;

  while(input >= 25) // dumb implementation because I'm lazy
  {
    input -= 25;
    q += 1;
  }
  while(input >= 10)
  {
    input -= 10;
    d += 1;
  }
  while(input >= 5)
  {
    input -= 5;
    n += 1;
  }
  while(input >= 1)
  {
    input -= 1;
    n += 1;
  }

  recur(q,d,n,p);

  return 0;
}
