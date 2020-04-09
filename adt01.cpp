#include <iostream>
#include <cmath>

using namespace std;

/*
    struct class
    ada 3 jenis hak akses di dalam struct dan class
    1. private
        member dengan ahak akses private, hanya dapat diakses dari
        dalam struct/class atau member lain dari struct/class yg sama
    2. protected
        ~private + dapat diakses dari turunan class/struct 
        atau oleh friend struct/class
    3. public
        member dengan hak akses public ini dapat diakses dari mana saja.
    
    pada struct, hak akses default adalah public, sedangkan 
    pada class, hak akses defaultnya adalah private.
 */

struct Lingkaran{
    double radius;
    double luas(){
        return M_PI * radius * radius;
    }
    double keliling(){
        return 2*M_PI * radius;
    }
};

int main(){
    Lingkaran* l;
    l = new Lingkaran;
    (*l).radius=10;
    l->radius=10;
    return 0;
}