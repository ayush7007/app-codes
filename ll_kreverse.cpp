

#include<iostream>
#include"Node.h"
using namespace std;


 int lengthR(Node<int>* head)
 {
	if (head == NULL)
		return 0;

	return 1 + lengthR(head->next);
}
Node<int> *takeInputR()
{
    int element;
    cin>>element;
    if(element==-1)
    {
        return NULL;
    }
    Node<int>* node=new Node<int>(element);
    node->next=takeInputR();
    return node;
}
void print(Node<int>* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"-->";
        head=head->next;

    }
    cout<<endl;
}
Node<int>* insertion(Node<int>* head, int position,int element)
{
      if(position==0)
    {
        Node<int>* node=new Node<int>(element);
        node->next=head;
        head=node;
        return head;

    }
    else{
    Node<int>* temp=head;
    position--;
    while(position!=0)
    {
        temp=temp->next;
        position--;
    }
    Node<int>* temp1=temp->next;;
    Node<int>* node=new Node<int>(element);
    temp->next=node;
    node->next=temp1;
    return head;
    }
}
Node<int> *deletion(Node<int>* head, int position)
{
    Node<int>* temp=head;
    if(position==0)
    {
        temp=head->next;
        delete head;
        return temp;

    }
    else{
            position--;
    while(position!=0)
    {
        temp=temp->next;
        position--;
    }
    Node<int>* temp1=temp->next;
    temp->next=temp->next->next;
    delete temp1;
    return head;
    }
}
Node<int>* insertre(Node<int>* head, int position,int element)
{
    if(position==0)
    {
        Node<int>* node=new Node<int>(element);
        node->next=head;
        head=node;
        return head;

    }
    else{
    head->next=insertre(head->next,position-1,element);
    return head;
    }

}

Node<int> *deletere(Node<int>* head, int position)
{

    if(position==0)
    {
        Node<int>* temp=head;
        temp=head->next;
        delete head;
        return temp;

    }
    else{
    head->next=deletere(head->next,position-1);
    return head;
    }
}

Node<int>* selectpart(Node<int>*head)
{
    Node<int>* temp=head;
    int min=head->data;
    while(temp!=NULL)
    {
        if  (temp->data<min)
        {
            min=temp->data;
        }

        temp=temp->next;
    }
    Node<int>*prev=NULL;
    temp=head;
    while(temp->data!=min)
    {
        prev=temp;
        temp=temp->next;
    }
    if(prev!=NULL)
    {
    Node<int>* temp1=temp->next;
    prev->next=head;
    temp->next=head->next;
    head->next=temp1;
    }
    return temp;
}

Node<int>* insertionSortRec(Node<int>* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }

    Node<int>* smallOutput=insertionSortRec(head->next);
    Node<int>* prev=NULL;
    Node<int>* current=smallOutput;

    while(current!=NULL)
    {
        if(current->data>=head->data)
        {
            break;
        }
        else{
            prev=current;
            current=current->next;
        }

    }
    head->next=current;
    if(prev==NULL)
    {
        return head;
    }
    else{
        prev->next=head;
        return smallOutput;
    }
}
Node<int>* insertAtRightPosition(Node<int>* head,Node<int>* node)
    {
        Node<int>* current=head;
        Node<int>* prev=NULL;

        while(current!=NULL)
        {
            if(current->data>=node->data)
            {
                break;
            }
            else{
                prev=current;
                current=current->next;
            }

        }


        node->next=current;
        if(prev==NULL)
        {
            return node;
        }

        else{
            prev->next=node;
            return head;
        }
    }
Node<int>* insertAtRightPosition2(Node<int>* head,Node<int>* node)
    {
        if(head->data>=node->data)
        {
            node->next=head;
            return node;
        }

        Node<int>* current=head;
        while(head->next && head->next->data<node->data)
        {
            head=head->next;
        }


        node->next=head->next;
        head->next=node;

        return current;
    }

Node<int>* insertionSortIter(Node<int>* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }

    Node<int>* sorted=head;
    Node<int>* unsorted=head->next;
    head->next=NULL;

    while(unsorted!=NULL)
    {
        Node<int>* temp=unsorted->next;
        sorted=insertAtRightPosition2(sorted,unsorted);
        unsorted=temp;
    }
    return sorted;
}

Node<int>* mergeLL(Node<int>* head1,Node<int>* head2)
{
    if(head1==NULL&&head2!=NULL)
    {
        return head2;
    }
    if(head2==NULL&&head1!=NULL)
    {
        return head1;
    }
    if(head2==NULL&&head1==NULL)
    {
        return head1;
    }

    Node<int>* first=head1;
    Node<int>* second=head2;
    Node<int>* merged;

    if(first->data>=second->data)
    {
        merged=second;
        second=second->next;
        merged->next=NULL;
    }
    else{
        merged=first;
        first=first->next;
        merged->next=NULL;
    }
    Node<int>* head=merged;

    while(first!=NULL && second!=NULL)
    {

        if(first->data>=second->data)
        {
            merged->next=second;
            second=second->next;
            merged=merged->next;
            merged->next=NULL;
        }
        else{
            merged->next=first;
            first=first->next;
            merged=merged->next;
            merged->next=NULL;
        }
    }

    if(first!=NULL)
    {
        merged->next=first;
    }

    if(second!=NULL)
    {
        merged->next=second;
    }

    return head;

}
Node<int>* getMid(Node<int>* head)
{
    Node<int>* slow=head;
    Node<int>* fast=head->next;
    while(fast!=NULL&& fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node<int>* mergeSort(Node<int>* head)
{

    if(head==NULL||head->next==NULL)
    {
        return head;
    }

    Node<int>* mid= getMid(head);
    Node<int>* part2=mid->next;
    mid->next=NULL;
    print(head);
    print(part2);
    Node<int>* head1=mergeSort(head);

    Node<int>* head2=mergeSort(part2);

    head=mergeLL(head1,head2);
    return head;
}

Node<int>* bubbleSorti(Node<int>* head)
{
    int n=lengthR(head);
    int i=0;
    while(i<n)
    {
        Node<int>* current=head;
        Node<int>* prev=NULL;

     while(current!=NULL&&current->next!=NULL)
     {

      if(current->data>current->next->data)
      {
          if(prev!=NULL)
          {
              Node<int>* nextNode=current->next;
              prev->next=nextNode;
              current->next=nextNode->next;
              nextNode->next=current;
              prev=nextNode;
          }
          else{

             Node<int>* nextNode=current->next;
             current->next=nextNode->next;
              nextNode->next=current;
              head=nextNode;
              prev=nextNode;
          }

      }

      else{
        prev=current;
        current=current->next;
      }
     }
     i++;
    }
    return head;
}

Node<int>* oneIteration(Node<int>* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }

    if(head->data>head->next->data)
    {
             Node<int>* nextNode=head->next;
             head->next=nextNode->next;
             nextNode->next=head;
             nextNode->next=oneIteration(head);
             return nextNode;
    }
    else{
        head->next=oneIteration(head->next);
        return head;
    }
}

Node<int>* bubbleSortRec(Node<int>* head)
{
     int n=lengthR(head);
    int i=0;
    while(i<n)
    {
        Node<int>* current=head;
       head= oneIteration(current);
     i++;
    }
    return head;

}

Node<int>* EvenAfterOdd(Node<int>* head)
{
        Node<int>* current=head;
        Node<int>* evenend=NULL;
        Node<int>* oddend=NULL;

        Node<int>* evenhead=NULL;
        Node<int>* oddhead=NULL;



   while(current!=NULL)
   {

   if(current->data%2==0)
   {
       if(evenhead==NULL)
       {
         evenhead=current;
        evenend=current;
        current=current->next;
        evenend->next=NULL;

       }
       else{
       evenend->next =current;
       current=current->next;
       evenend=evenend->next;
       evenend->next=NULL;
       }
   }
   else{
        if(oddhead==NULL)
        {
            oddhead=current;
            oddend=current;
            current=current->next;
            oddend->next=NULL;

        }
        else{
        oddend->next =current;
       current=current->next;
       oddend=oddend->next;
       oddend->next=NULL;
        }
   }

   }

   if(oddhead==NULL)
   {
       return evenhead;
   }
   else{
   oddend->next=evenhead;
   return oddhead;
   }
}

Node<int>* kReverse(Node<int>*head,int n)
{
    //write your code here




}




int main()
{
    /*Node<int>* head=takeInputR();
    print(head);
    print(head);
    head=insertre(head,0,7);
    print(head);
    head=insertre(head,3,8);
    print(head);
    head=deletere(head,4);
    print(head);
    head=bubblesort(head);
    print(head);*/
    Node<int>* head=takeInputR();

    print(head);
    //Node<int>* temp=insertionSortIter(head);
    //Node<int>* temp=bubbleSortRec(head);
    Node<int>* temp=EvenAfterOdd(head);
    print(temp);
    //head=selectpart(head);
    //print(head);
    return 0;

}






