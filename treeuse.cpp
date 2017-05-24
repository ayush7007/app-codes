#include <iostream>
#include "treenode.h"
#include <stack>
#include<queue>
#include<climits>
using namespace std;

TreeNode<int>* takeInput() {
	cout << "Enter root data" << endl;
	int n;
	cin >> n;
	TreeNode<int> *root = new TreeNode<int>(n);
	int c;
	cout << "Enter child count"<< endl;
	cin >> c;
	for (int i = 0; i < c; i++) {
		root->addChild(takeInput());
	}
	return root;
}

void print( TreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	cout << root->getData() << ":";
	for (int i = 0; i < root->childrenCount(); i++) {
		cout << root->getChild(i)->getData() << ",";
	}
	cout << endl;
	for (int i = 0; i < root->childrenCount(); i++) {
		print(root->getChild(i));
	}

}

    TreeNode<int>* takeInputLevelWise()
    {
        queue<TreeNode<int>*> q;
            cout<<"Enter root data"<<endl;
            int n;
            cin>>n;
            TreeNode<int> *root = new TreeNode<int>(n);
             q.push(root);

             while(!q.empty())
             {
                 TreeNode<int>* element=q.front();
                 q.pop();
                 cout<<"enter no of children of "<<element->getData()<<endl;
                 int no;
                 cin>>no;
                for(int i=0;i<no;i++)
                {
                    cout<<"enter "<<i<<"th child of"<<element->getData()<<endl;
                    int child;
                    cin>>child;
                     TreeNode<int> *childp = new TreeNode<int>(child);
                     element->addChild(childp);
                     q.push(childp);
                }

             }

        return root;


        }

    void printLevelWise(TreeNode<int>* root)
    {
        if(root==NULL)
        {
            return ;
        }

        queue<TreeNode<int>*> q;
        q.push(root);
        int no=1;
         int children=0;
        while(!q.empty())
        {
                children=0;
                while(no)
                {
                    TreeNode<int>* element=q.front();
                    q.pop();
                    cout<<element->getData();
                     for(int i=0;i<element->childrenCount();i++)
                    {
                       children++;
                        q.push(element->getChild(i));
                    }
                    no--;
                }
                no=children;
                cout<<endl;

        }


    }

   void printLevelWiseulta(TreeNode<int>* root)
    {
        if(root==NULL)
        {
            return ;
        }

        queue<TreeNode<int>*> q;
        stack<TreeNode<int>*> s;
        q.push(root);
        int no=1;
         int children=0;
        while(!q.empty())
        {
                children=0;
                while(no)
                {
                    TreeNode<int>* element=q.front();
                    q.pop();
                    cout<<element->getData();
                     for(int i=0;i<element->childrenCount();i++)
                    {
                       children++;
                        q.push(element->getChild(i));
                    }
                    no--;
                }
                no=children;
                cout<<endl;

        }


    }

    int heightgeneric(TreeNode<int>* root)
    {
        if(root==NULL)
        {
            return 0;
        }

        int maxHeight=1;

        for(int i=0;i<root->childrenCount();i++)
        {
            int height=1+heightgeneric(root->getChild(i));
            maxHeight=max(height,maxHeight);
        }

        return maxHeight;
    }

    TreeNode<int>* maxNodereturn(TreeNode<int>* root)
    {
        if(root==NULL)
        {
            return NULL;
        }

        int maxi=root->getData();
        TreeNode<int>* maxNode=root;

        for(int i=0;i<root->childrenCount();i++)
        {
            TreeNode<int>* temp=maxNodereturn(root->getChild(i));
            if(temp->getData()>maxi)
            {
                maxi=temp->getData();
                maxNode=temp;
            }


        }

        return maxNode;

    }

    TreeNode<int>* nextLargerElement(TreeNode<int>* root, int n)
    {
        if(root==NULL)
        {
            return root;
        }


        TreeNode<int>* nextLarger=NULL;
        int maxi=INT_MAX;
        if(    root->getData() > n  &&   root->getData() <maxi   )
        {
            nextLarger=root;
            maxi=root->getData();
        }

        for(int i=0;i< root->childrenCount() ;i++)
        {
            TreeNode<int>* temp = nextLargerElement(root->getChild(i),n);
                if(temp!=NULL)
                {
                    if((temp->getData()> n) && (temp->getData() < maxi))
                    {
                        nextLarger=temp;
                        maxi=temp->getData();
                    }
                }


        }

        if(nextLarger)
        cout<<nextLarger->getData()<<endl;

        return nextLarger;

    }


    TreeNode <int>* secondLargest1(TreeNode<int> *root)
    {

        if(root==NULL)
        {
            return root;
        }

    int largest=root->getData();
    int secondlarge=INT_MIN;
    TreeNode<int>* maxNode=root;
    TreeNode<int>* secondmaxNode=NULL;

        for(int i=0;i<root->childrenCount();i++)
        {
            TreeNode<int>* temp=secondLargest1(root->getChild(i));
           if(temp)
           {
            if(temp->getData()>largest)
            {
                secondmaxNode=maxNode;
                secondlarge=largest;
                maxNode=temp;
                largest=temp->getData();
            }
            else if(temp->getData()<largest && temp->getData()>secondlarge)
            {
                secondmaxNode=temp;
                secondlarge=temp->getData();
            }
           }

        }

        return secondmaxNode;

    }


   void secondLargestHelper(TreeNode<int>* root,TreeNode<int>* &first,TreeNode<int>* &second )
   {
    if(root==NULL)
    {
        return;
    }

    if(first==NULL)
    {
        first=root;
    }
    if(first!=NULL && second ==NULL)
    {
        if(root->getData()>first->getData())
        {
            second=first;
            first=root;
        }
        else if(root->getData()<first->getData())
            {
             second=root;

            }
    }
    if(first && second)
    {
        if(root->getData()>first->getData())
        {
            second=first;
            first=root;
        }
        else if(root->getData()<first->getData() && root->getData()>second->getData())
            {
             second=root;

            }
    }

    for(int i=0;i<root->childrenCount();i++)
    {
        secondLargestHelper(root->getChild(i),first,second );
    }
        return;

   }

   TreeNode<int>* secondLargest(TreeNode<int>* root)
   {
       TreeNode<int>* largest=NULL;

       TreeNode<int>* second=NULL;

       secondLargestHelper(root,largest,second);

       return second;
   }



int main() {
    //TreeNode<int> * root = takeInput();
	TreeNode<int> * root = takeInputLevelWise();
	//1 3 2 3 4 0 2 5 6 1 7 0 0 2 8 9 0 0
        //print(root);
    //cout<<heightgeneric(root)<<endl;

    //TreeNode<int>* temp=maxNodereturn(root);

    TreeNode<int>* temp1=secondLargest(root);
    cout<<endl<<temp1->getData()<<endl<<endl;

	printLevelWise(root);

	//delete root;
}


