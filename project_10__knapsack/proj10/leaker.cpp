
#include <iostream>
using std::cout;
using std::endl;
#include "proj10_package.h"
#include "proj10_knapsack.h"

void fn(Knapsack k){
  while(k.add({10,10}) );
}

int main ()
{
  Knapsack k(1000);

  for(long i=0; i<1000; ++i)
    fn(k);
}

