#include <iostream>

using namespace std;

int main(){
    int data[]={3,9,1,7};       //4 bytes
    int *pInt;
    pInt = data;
    for (int i=0;i<4;i++)
        cout<<*(data+i)<<endl;

    for (int i=0;i<4;i++)
        cout<<data[i]<<endl;

    return 0;
}