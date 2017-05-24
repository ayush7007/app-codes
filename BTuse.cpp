#include <iostream>
#include "BTuse.h"
#include <stack>
#include<queue>
using namespace std;

TreeNode<int>* takeInput() {
	cout << "Enter root data" << endl;
	int n;
	cin >> n;
	TreeNode<int> *root = new TreeNode<int>(n)

	cout<<"Enter left child"<<endl;
	cin
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







int main() {
	TreeNode<int> * root = takeInputLevelWise();
	print(root);
	delete root;
}



