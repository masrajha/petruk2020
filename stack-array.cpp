#include <iostream>
#include <cmath>
#define MAX_STACK_SIZE 10

using namespace std;
struct Lingkaran{
    double radius;
};

struct MyStack {
    int top;
    Lingkaran element[MAX_STACK_SIZE];

    MyStack create(){
        top=-1;
    }
    bool isEmpty(){
        return top==-1;
    }
    bool isFull(){
        return top == MAX_STACK_SIZE-1;
    }
    void push(double r){
        if (!isFull()){
            element[++top].radius=r;
            cout << r << " added"<<endl;
        } else {
            cout<<"Stack full"<<endl;
        }
    }
    Lingkaran pop(){
        if (isEmpty()){
            cout<<"Stack kosong"<<endl;
            Lingkaran tmp;
            return tmp;
        } else {
            return element[top--];    
        }    
    } 
    void printTop(){
        if (!isEmpty()){
            cout<<element[top].radius;
        } else {
            cout<<"Stack kosong"<<endl;
        }
    }
};

int main(){
    MyStack ms;
    ms.create();
    for (int i=0;i<11;i++)
        ms.push(i);
    cout<<ms.pop().radius<<" pop"<<endl;
    cout<<ms.pop().radius<<" pop"<<endl;
    ms.printTop();
    // cout<<ms.top;
    // cout<<ms.isEmpty();
    return 0;
}