// Example program
#include <iostream>
#include <string>
#include <math.h>

using namespace std;
unsigned long long int pangkat(long int x, long int n) {
    if (n==0) return 1;
    if (n==1) return x % 1000000;
    if (n>1){
        if (n%2==0)
            return pangkat(x,n/2) % 1000000 * pangkat(x,n/2) % 1000000;
        else 
            return pangkat(x,n/2) % 1000000 * pangkat(x,n/2 + 1) % 1000000;
    } else {
        return 1/pangkat (x,-n);
    }
}

int main()
{
  long a,b;
  cin>>a>>b;
  if  (b > 6*(log(2) + log(5))/log(a)) {
      printf("%06ld",pangkat(a,b));
  } else {
      printf("%d",pangkat(a,b));
  }
}
