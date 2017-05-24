#include <iostream>
#include<algorithm>
#include<math.h>
#include<string>
using namespace std;
#include "BTNode2.h"
#include <queue>
#include<stack>
#include<climits>
#include "node.h"


    BinaryTreeNode<int>* takeInput()
    {
        int data;
        cout<<"Enter root data"<<endl;
        cin>>data;
        if(data==-1)
        {
            return NULL ;
        }
        BinaryTreeNode<int>* root=new BinaryTreeNode<int>(data);
        root->left=takeInput();
        root->right=takeInput();
        return root;
        //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

    }

    BinaryTreeNode<int>* takeInputLevelWise()
    {

        queue<BinaryTreeNode<int>*> q;
        int rootData;
        cout<<"Enter root data"<<endl;
        cin>>rootData;
         BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
        q.push(root);
        while(!q.empty())
        {
             BinaryTreeNode<int>* temp=q.front();
             q.pop();
             cout<<"Enter left child of "<<temp->data<<endl;
             int leftchild;
             cin>>leftchild;
             if(leftchild!=-1)
             {
                 BinaryTreeNode<int>* lefttemp=new BinaryTreeNode<int>(leftchild);
                 temp->left=lefttemp;
                 q.push(lefttemp);

             }

             cout<<"Enter right child of "<<temp->data<<endl;
             int rightchild;
             cin>>rightchild;
             if(rightchild!=-1)
             {
                 BinaryTreeNode<int>* righttemp=new BinaryTreeNode<int>(rightchild);
                 temp->right=righttemp;
                 q.push(righttemp);
             }

        }

        return root;


    }

     void printLevelWise(BinaryTreeNode<int>* root)
    {
        if(root==NULL)
        {
            return;
        }
        queue<BinaryTreeNode<int>*> q;
        q.push(root);
        int no=1;
        while(!q.empty())
        {
            int children=0;
            while(no)
            {
                BinaryTreeNode<int>* temp=q.front();
                q.pop();
                cout<<temp->data;
                if(temp->left)
                {
                    q.push(temp->left);
                    children++;
                }
                if(temp->right)
                {
                    q.push(temp->right);
                    children++;
                }
                no--;

            }
            no=children;
            cout<<endl;
        }
    }

    void print(BinaryTreeNode<int>* root)
    {
        if(root==NULL)
        {
            return;
        }


        cout<<root->data<<":";
        if(root->left!=NULL)
        {
            cout<<root->left->data<<",";
        }
        if(root->right!=NULL)
        {
            cout<<root->right->data<<",";
        }
        cout<<endl;
        print(root->left);
        print(root->right);
        return;

    }

    int height(BinaryTreeNode<int>* root)
    {
        if(root==NULL)
        {
            return 0;
        }

        return 1+max(height(root->left),height(root->right));

    }

    int diameter1 (BinaryTreeNode<int>* root)
    {

        if(root==NULL)
        {
            return 0;
        }


        int lh=height(root->left);
        int rh=height(root->right);
        int ld=diameter1(root->left);
        int rd=diameter1(root->right);
        return max(lh+rh,max(ld,rd));

    }

    class Diameter{
                    public:
                int height;
                int diameter;
    };


    Diameter findDiameter(BinaryTreeNode<int>* root)
    {
        if(root==NULL)
        {
            Diameter ans;
            ans.height=0;
            ans.diameter=0;
            return ans;
        }

        Diameter left=findDiameter(root->left);
        Diameter right=findDiameter(root->right);

        Diameter ans;

        ans.height=1+max(left.height,right.height);
        ans.diameter= max(left.height+right.height,max(left.diameter,right.diameter));
        return ans;

    }

/*The structure of node is as follows
struct node{
	string data;
	node *left;
	node *right;
};
*/

/*You are required to complete below method */


int value(string calculate)
{
    int no=0;
    int length=calculate.size();
    for(int i=0;i<length;i++)
    {
        no=no*10+(calculate[i]-'0');
    }
    return no ;

}





/*int evalTree(node* root)
{
    //Your code here
    if(root->left==NULL && root->right==NULL)
    {
        int no=value(root->data);
        return no;
    }


    int first=evalTree(root->left);
    int second=evalTree(root->right);
    if(root->data[0]=='+')
    {
        return first+second;
    }
    else if(root->data[0]=='-')
    {
        return first-second;
    }
    else if(root->data[0]=='/')
    {
        return first/second;
    }
    else if(root->data[0]=='*')
    {
        return first*second;
    }

}
*/

    vector<int>* getAncestors(BinaryTreeNode<int>* root,int element)
    {
        if(root==NULL)
        {
            return NULL;
        }

        if(root->data==element)
        {
            vector<int>* vec=new vector<int>;;
            vec->push_back(element);
            return vec;
        }

        vector<int>* loutput=getAncestors(root->left,element);
        if(loutput!=NULL)
        {
            loutput->push_back(root->data);
            return loutput;
        }

        else
        {
              vector<int>* routput=getAncestors(root->right,element);
              if(routput!=NULL)
              {
                   routput->push_back(root->data);
                }
                    return routput;
        }


    }

    int lca(BinaryTreeNode<int>* root,int x,int y)
    {
        vector<int>* first=getAncestors(root,x);
        vector<int>* second=getAncestors(root,y);

        int li1=first->size()-1;
        int li2=second->size()-1;
        int temp;
        while(li1>=0 && li2>=0)
        {
            if((*first)[li1]==(*second)[li2])
            {
                temp=(*first)[li1];
                li1--;
                li2--;
            }
            else{
                break;
            }
        }
        return temp;


    }


    BinaryTreeNode<int>* nextLargerElement(BinaryTreeNode<int>* root,int x)
    {
        if(root==NULL)
        {
            return NULL;
        }

        BinaryTreeNode<int>* nextLarger=NULL;
        int maxi=INT_MAX;
        if(root->data>x && root->data<maxi)
        {
            nextLarger=root;
            maxi=root->data;
        }
        BinaryTreeNode<int>* left1=nextLargerElement(root->left,x);
        if(left1 &&left1->data>x && left1->data<maxi)
        {
            nextLarger=left1;
            maxi=left1->data;
        }
        BinaryTreeNode<int>* right1=nextLargerElement(root->right,x);
        if(right1 && right1->data>x && right1->data<maxi)
        {
            nextLarger=right1;
            maxi=right1->data;
        }
        return nextLarger;

    }


    bool isBalanced(BinaryTreeNode<int>* root)
    {
        if(root==NULL)
        {
            return 1;
        }

        int lh=height(root->left);
        int rh=height(root->right);

        if(   abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right) )
        {
            return 1;
        }
        return 0;

    }

    void zigZagOrder(BinaryTreeNode<int>* root)
    {
        if(root==NULL)
        {
            return;
        }
        stack<BinaryTreeNode<int>*> s1;
        stack<BinaryTreeNode<int>*> s2;
        s1.push(root);

        int flag=0;
        while(  !s1.empty()  ||  !s2.empty()  )
        {
            if(flag==0)
            {
                while(!s1.empty())
                {
                    BinaryTreeNode<int>* temp=s1.top();
                    s1.pop();
                    cout<<temp->data;
                    if(temp->left){
                    s2.push(temp->left);
                    }
                    if(temp->right){
                    s2.push(temp->right);
                    }
                }
                flag=1;
            }

        else if(flag==1)
        {
            while(!s2.empty())
            {
                 BinaryTreeNode<int>* temp1=s2.top();
                    s2.pop();
                    cout<<temp1->data;
                    if(temp1->right){
                    s1.push(temp1->right);
                    }
                    if(temp1->left){
                    s1.push(temp1->left);
                    }
            }
            flag=0;
        }

          cout<<endl;
        }

    }


    BinaryTreeNode<int>* buildTree(int *preorder, int preLenght, int *inorder, int inLength)
     {
            if(preLenght!=inLength || preLenght==0 || inLength==0)
            {
                return NULL;
            }
            BinaryTreeNode<int>* root=new BinaryTreeNode<int>(preorder[0]);
            int i;
            for(i=0;i<inLength;i++)
            {
                if(inorder[i]==root->data)
                {
                    break;
                }
            }
            int leftsize=i;
            int rightsize=inLength-1-i;
            root->left=buildTree(preorder+1,i,inorder,i);
            root->right=buildTree(preorder+i+1,preLenght-1-i,inorder+i+1,inLength-1-i);
            return root;
    }


    BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength)
     {
             if(postLength!=inLength || postLength==0 || inLength==0)
            {
                return NULL;
            }
            BinaryTreeNode<int>* root=new BinaryTreeNode<int>(postorder[postLength-1]);
            int i;
            for(i=0;i<inLength;i++)
            {
                if(inorder[i]==root->data)
                {
                    break;
                }
            }

            root->left=getTreeFromPostorderAndInorder(postorder,i,inorder,i);
            root->right=getTreeFromPostorderAndInorder(postorder+i,postLength-1-i,inorder+i+1,inLength-1-i);
            return root;

    }


    vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL)
    {
        vector<node<int>*> v;
        return v;
    }
        queue<BinaryTreeNode<int>*> q;
        vector<node<int>*> vec;
        q.push(root);
        int no=1;
        while(!q.empty())
        {
            int children=0;

            vec.push_back(NULL);
            while(no)
            {
                BinaryTreeNode<int>* temp=q.front();
                q.pop();
                // something
                if(vec[vec.size()-1]==NULL)
                {
                    node<int>* newNode=new node<int>(temp->data);
                    vec[vec.size()-1]=newNode;

                }
                else{
                         node<int>* head=vec[vec.size()-1];
                     node<int>* newNode=new node<int>(temp->data);
                   newNode->next=head;
                    vec[vec.size()-1]=newNode;
                }
                if(temp->right)
                {
                    q.push(temp->right);
                    children++;
                }
                if(temp->left)
                {
                    q.push(temp->left);
                    children++;
                }

                no--;
            }

            no=children;
        }



    return vec;


     }

int main()
{
    //BinaryTreeNode<int>* root=takeInput();
     //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

   // BinaryTreeNode<int>* root=takeInputLevelWise();
    //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

    //cout<<endl<<diameter1(root)<<endl;
    //print (root);
    //Diameter result=findDiameter(root);
    //cout<<endl<<result.diameter<<endl;
    //    vector<int>* ancestor=getAncestors(root,5);
//    vector<int>::iterator it=ancestor->begin();
//    while(it!=ancestor->end())
//    {
//        cout<<*it<<" ";
//        it++;
//    }

    //cout<<lca(root,4,5)<<endl;
   // BinaryTreeNode<int>* temp=nextLargerElement(root,4);
    //cout<<temp->data<<endl;
    //cout<<endl;
    //printLevelWise(root);

    //zigZagOrder(root);


//    int preorder[7]={1,2,4,5,6,3,7};
//    int inorder[7]={4,2,6,5,1,3,7};
//    BinaryTreeNode<int>* temp=buildTree(preorder,7,inorder,7);
//     cout<<endl;
    int postorder[7]={4,6,5,2,7,3,1};
    int inorder[7]={4,2,6,5,1,3,7};
    BinaryTreeNode<int>* temp=getTreeFromPostorderAndInorder(postorder,7,inorder,7);
     cout<<endl;

    printLevelWise(temp);
    cout<<endl;
    return 0;

}


