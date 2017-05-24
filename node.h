
#include<iostream>
using namespace std;
template <typename T>

 class node
 {
     public:
     T data;
     node<T>* next;

     node(T data)
     {

         this->data=data;
         this->next=NULL;
     }

     ~node()
     {
         if(next!=NULL){
            delete next;
        }
     }
 };

