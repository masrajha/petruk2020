#include <iostream>

using namespace std;

int main(){
    int A[2][4]={{10,11,12,13},
                  {20,21,22,23}
                };
    int (*p) [4];
    p = A;
    cout << *(*(p+1)+1)<<endl;
    return 0;
}