
#include <stdio.h>
#include <stdlib.h>

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


void main()
{

}
