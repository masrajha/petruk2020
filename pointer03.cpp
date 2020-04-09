#include <iostream>

using namespace std;

int main(){
    int A[]={10,11,12,13};
    int B[]={20,21,22,23};
    int* pA, *pB;
    int* pAB [] = {A,B};
    pA = A;
    pB = B;

    cout<<*(*(pAB+1)+2)<<endl;
    cout<<A<<endl;
    cout<<(pAB+1)<<endl;

    return 0;
}