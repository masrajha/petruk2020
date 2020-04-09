#include <iostream>
#include <cmath>

using namespace std;
struct TNode{
    int data;
    TNode *next;
};

struct MyList{
    TNode *head;

    void init(){
        head=NULL;
    }
    bool isEmpty(){
        return head==NULL;
    }
    void insertDepan(int databaru){
        TNode *baru;
        baru=new TNode;
        baru->data=databaru;
        if (isEmpty()){
            head=baru;
            head->next=NULL;
        } else {
            baru->next=head;
            head=baru;
        }

    }
    void insertBelakang(int databaru){

    }
    void cetak(){
        /*
            menelusuri sampai ketemu node yg nextnya NULL
         */
        
        if (isEmpty()){
            cout<<"List masih kosong";
        } else {
            TNode *bantu;
            bantu=new TNode;
            bantu = head;
            while (bantu!=NULL){
                cout<<bantu->data<<endl;
                bantu = bantu->next;
            }
        }
    }
};

int main(){
    MyList list;
    list.init();
    list.insertDepan(5);
    list.insertDepan(30);
    list.cetak();
    return 0;
}