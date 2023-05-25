#include <iostream>

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
        cout<<"Push "<<r<<"\n";
    }
    Lingkaran* pop(){
        if (isEmpty()) {
            cout<<"Stack kosong\n";
            return top;
        } else {
            Lingkaran *tmp;
            tmp = top;
            top = top->next;
            cout<<tmp->radius<<" poped\n";
            return tmp;
        }    
    } 
    void printTop(){
        //tambaha kode untuk cetak data paling atas 3 menit
        cout<<top->radius;
    }
};
void hanoi(int discs, MyStack *fromPole, MyStack *toPole, MyStack *aux){
    Lingkaran *l = new Lingkaran;
    if (discs>=1){
        hanoi(discs-1,fromPole,aux,toPole);
        l = fromPole->pop();
        toPole->push(l->radius);
        hanoi(discs-1,aux,toPole,fromPole);
    }
}
int main(){
    MyStack *fromPole, *toPole, *aux;
    MyStack ms;

    ms.push(10);

    fromPole=new MyStack;
    toPole=new MyStack;
    aux=new MyStack;

    fromPole.push(3);
    fromPole->push(2);
    fromPole->push(1);
    // fromPole.printTop();
    hanoi(3,fromPole,toPole,aux);
    cout<<"Hasil :\n";
    cout<<"Top dari toPole: ";
    toPole->printTop();
    cout<<"\nTop dari fromPole: ";
    fromPole->printTop();
    return 0;
}