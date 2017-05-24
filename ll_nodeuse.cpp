#include <iostream>
#include "ll_Node.h"
using namespace std;



Node* llinput() {
	int n;
	cout << "Enter first element" << endl;
	cin >> n;
	Node* head = NULL;
	Node* tail = NULL;
	while (n != -1) {
		Node* newNode = new Node(n);
		if (head == NULL) {
			head = newNode;
			tail = head;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
		cin >> n;
	}
	return head;
}

void printLL(Node* head) {
	while (head != NULL) {
		cout << head->getData() << " ";
		head = head->next;
	}
	cout << endl;
}

int lengthR(Node* head)
 {
	if (head == NULL)
		return 0;

	return 1 + lengthR(head->next);
}

Node* rearrange(Node* head)
{
    int length=lengthR(head);

    int k=(length/2)-1;

    Node* temp=head;


    while(k)
    {
        temp=temp->next;
        k--;
    }

    Node* part1=head;
    Node* part2=temp->next;
    temp->next=NULL;
    Node* result=NULL;
    while(part1&&part2)
    {
        if(result==NULL)
        {
            result=part1;
            part1=part1->next;



             result->next=part2;
             part2=part2->next;
             result=result->next;
             result->next=NULL;
        }
        else{
                result->next=part1;
                part1=part1->next;
                result=result->next;

                result->next=part2;
                part2=part2->next;
                result=result->next;
                result->next=NULL;

             }


    }
    return head;


}

Node* swap_nodes(Node *head,int i,int j)
{
    if(i==j)
    {
        return head;
    }

    Node*prev1=NULL,*prev2=NULL;
    Node*current1=head,*current2=head;
    Node*nn1=current1->next,*nn2=current2->next;
    int n=i,m=j;
    while(n!=0)
    {
        prev1=current1;
        current1=nn1;
        nn1=nn1->next;
        n--;
    }
    while(m!=0)
    {
        prev2=current2;
        current2=nn2;
        nn2=nn2->next;
        m--;
    }
    if(i==0||j==0)
    {
        if(j==i+1||i==j+1)
        {
         current1->next=current2->next;
         current2->next=current1;
         head=current2;


        }
        else{prev2->next=current1;
        current1->next=nn2;
        current2->next=nn1;
        head=current2;
        }
    }

   else if(j==i+1||i==j+1)
    {
     prev1->next=nn1;
     nn1->next=current1;
     current1->next=nn2;
    }
    else{prev1->next=current2;
    current2->next=nn1;
    prev2->next=current1;
    current1->next=nn2;
    }
    return head;
}



Node* selectionSort(Node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }

    Node* temp=head;

    Node* prev=NULL;
    while(temp!=NULL)
    {

        Node* temp2=temp->next;
        int position=0;
        int traverse=0;
        int Min=temp2->data;
        while(temp2!=NULL)
        {
             if(Min>temp2->data)
             {
                 position=traverse;
                 Min=temp2->data;
             }
             traverse++;
             temp2=temp2->next;
        }
        Node* temp3=temp;

        if(prev==NULL)
        {

         temp=swap_nodes(temp2,0,traverse);


         head=temp;

        }

        else{

            temp->next=swap_nodes(temp2,0,traverse);
        }

        prev=temp;
        temp=temp->next;
    }






    return head;

}






int main() {
	Node* head = llinput();
	printLL(head);
	cout<<endl;
	Node* temp=rearrange(head);
	printLL(head);


	delete head;

}


