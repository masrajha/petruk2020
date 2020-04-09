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
        TNode *baru, *bantu;
        baru = new TNode;
        baru->data = databaru;
        baru->next=NULL;
        if (isEmpty()){
            head = baru;
        } else {
            bantu = head;
            while(bantu->next != NULL){
                bantu = bantu->next;
            }
            bantu->next = baru;
        }
        cout<<"Data "<<databaru<<" ditambahkan"<<endl;
    }
    void hapusDepan(){
        if (isEmpty()){
            cout<<"List kosong";
        }else if (head->next=NULL){
            cout<<"Data head "<<head->data<<" dihapus\n";
            head=NULL;
        } else {
            /*
            Buat variable bantu -> jawabnya TNode *bantu;
            Set bantu = head  -> ?? apa ?
            Head = bantu->next -> ??
            hapus bantu -> ??
            waktu 5 menit... tulis di komentar
            */
            TNode *bantu;
            bantu = new TNode;  // tambahan untuk kode membuat variabel bantu
            bantu = head;
            head = bantu->next;
            cout<<head->data;
            cout<<"Data "<<bantu->data<<" dihapus\n";
            delete bantu;
            
        }
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
    list.insertBelakang(70);
    list.hapusDepan();
    list.cetak();
    return 0;
}