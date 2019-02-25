
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Cornacchia algorithm solves Diophantine equation:
//    x² + dy² = m
//    where 1 <= d < m and d and m are coprime

//https://en.wikipedia.org/wiki/Cornacchia's_algorithm

/*

  1. solution for r_0² = -d (mod m)     *(must exist)
  2. euclidean algorithm to r_1 = m (mod r_0) ...
    r_2=r_0 (mod r_1) and so soon stop when r_k < sqr(m)
  2.1. If s= sqr((m-r_k²)/d) is int. solution is x = r_k || y = s
*/

#define MAX 1000

int cornacchia(d, m);

void main()
{

}

int cornacchia(d, m){
  int r0 = 1;
  int r1;

  while( (r0 * r0 + d) %m != 0)
  {
    r0++;
    if(r0 = m)
      return 1;
  }

  r1 = m % r0;
  while( r1*r1 >= m)
  {
    r0 = r1;
    r1 = r0 % r1;
  }

  //2.1
  s = sqrt( (m-r1*r1) / d )

  //if(s is int)
  //  return r_k && s
  //else
    return 1;
}
