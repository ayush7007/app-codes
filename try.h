
#include<iostream>
#include<string>
#include"Node.h"

using namespace std;

template<typename V>


class hashmap
{

    Node<pair<string,V>*>** buckets;

    int bucketSize;

    int Size;

    public:

    hashmap()
    {
        bucketSize=3;
        Size=0;
        buckets=new Node<pair<string,V>*>*[bucketSize];
        for(int i=0;i<bucketSize;i++)
        {
            buckets[i]=NULL;
        }
    }

    ~hashmap()
    {
        for(int i=0;i<bucketSize;i++)
        {
            if(buckets[i]!=NULL)
            {
                    delete buckets[i];
            }
        }
        delete[] buckets;
    }



    bool isEmpty()
    {
        return Size==0;
    }

    int Count()
    {
        return Size;
    }


    bool containsKey(string key)
    {

        int bucketIndex=getBucketIndex(key);

        Node<pair<string,V>*>* head=buckets[bucketIndex];

        while(head!=NULL)
        {
            if(head->data->first==key)
            {
                return true;
            }
            head=head->next;
        }

        return false;

    }

    V Find(string key)
    {

         int bucketIndex=getBucketIndex(key);

        Node<pair<string,V>*>* head=buckets[bucketIndex];

        while(head!=NULL)
        {
            if(head->data->first==key)
            {
                return head->data->second;
            }
            head=head->next;
        }

               throw "key not found" ;

    }

    void deleteKey(string key)
    {

        int bucketIndex=getBucketIndex(key);
        Node<pair<string,V>*>* head=buckets[bucketIndex];
         Node<pair<string,V>*>* prev=NULL;
          while(head!=NULL)
        {

            if(head->data->first==key)
            {
                if(prev=NULL)
                {
                    buckets[bucketIndex]=head->next;
                }
                else{
                    prev->next=head->next;
                }
                head->next=NULL;
                delete head->data;
                delete head;
                Size--;
                return;
            }
            prev=head;
            head=head->next;
        }

    }


    void insertKey(string key,V value)
    {
         int bucketIndex=getBucketIndex(key);
        Node<pair<string,V>*>* head=buckets[bucketIndex];
        while(head!=NULL)
        {
            if(head->data->first==key)
            {
                head->data->second=value;
                return ;
            }
            head=head->next;
        }

          head=buckets[bucketIndex];

          pair<string,V>* p=new pair<string,V>(key,value);

          Node<pair<string,V>*>* newNode=new  Node<pair<string,V>*>(p);

          newNode->next=head;

         buckets[bucketIndex]=newNode;

        if((1.0*Size)/bucketSize>0.75)
        {
        rehash();
        }
    }

    private:

        void rehash()
        {

                bucketSize=bucketSize*2;
                Size=0;
                Node<pair<string,V>*>* temp=buckets;
                buckets=new Node<pair<string,V>*>*[bucketSize];

                for(int i=0;i<bucketSize;i++)
                {
                    buckets[i]=NULL;
                }

                for(int i=0;i<bucketSize/2;i++)
                {
                    Node<pair<string,V>*>* head=temp[i];
                    while(head!=NULL)
                    {
                        insertKey(head->data->first,head->data->second);
                        Node<pair<string,V>*>* tempNode=head;
                        head=head->next;

                        tempNode->next=NULL:

                            delete head->data;
                            delete tempNode;

                    }
                }
        }


        int getBucketIndex(string key)
        {
            int sum=0;

            for(int i=0;i<key.size();i++)
            {
                sum=sum+key[i];
            }

            return sum%bucketSize;

        }



};
