#include <iostream>
#include <cmath>

using namespace std;

double LuasLingkaran(double r){
    return r * r * M_PI;
}
int main(){
    double (*FPtr) (double);
    FPtr=LuasLingkaran;

    cout<<FPtr(10);
    return 0;
}