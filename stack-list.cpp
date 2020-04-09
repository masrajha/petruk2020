#include <iostream>

#define MAX_STACK_SIZE 10

using namespace std;
struct Lingkaran{
    double radius;
    Lingkaran *next;
};

struct MyStack {
    Lingkaran *top;
    
    void create(){
        top=NULL;
        cout<<"Stack create"<<endl;
    }
    bool isEmpty(){
        //kode untuk memeriksa apakah stack kosong
        return top==NULL;
    }
    bool isFull(Lingkaran *tmp){
        tmp = new (nothrow) Lingkaran;
        return (tmp==NULL);
    }
    void push(double r){
        Lingkaran *baru;
        baru = new Lingkaran;
        baru->radius=r;
        baru->next=NULL;
        if (isEmpty()){
            top=baru;
        } else {
            baru->next=top;
            top=baru;
        }
        cout<<"Data "<<r<<" Added\n";
    }
    Lingkaran* pop(){
        if (isEmpty()) {
            return NULL;
        } else {
            Lingkaran *tmp;
            tmp = top;
            top = top->next;
            return tmp;
        }    
    } 
    void printTop(){
        //tambaha kode untuk cetak data paling atas 3 menit
        cout<<top->radius;
    }
};

int main(){
    MyStack *ms;
    ms->create();
    ms->push(5);
    return 0;
}