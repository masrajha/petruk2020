#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
int main(){
    list <int> v1;
   
    v1.assign(3,5);
    v1.push_back(2);
    v1.push_back(11);
    v1.push_back(10);
    v1.push_back(1);
    v1.push_back(4);
    v1.push_back(8);
    
    //vector -> random access 
    //list -> sequential access -> doubly linked list
    sort(v1.begin(),v1.end());
    // v2.push_back('c');
    // vector<int>::iterator itr;          //sama dengan mendefinisikan pointer. 
    // auto itr = v1.begin();
    // for(;itr!=v1.end();itr++){
    //     cout<<*itr<<endl;
    // }
    // cout<<v1[5];
    for (auto itr:v1){
        cout<<itr<<endl;
    }

    // cout<<v1.front()<<' '<<v1.back()<<' '<<v1.size()<<endl;
    return 0;
}