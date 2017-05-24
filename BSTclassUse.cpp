
#include <iostream>
#include<algorithm>
#include<math.h>
#include<string>
using namespace std;
#include "BTNode2.h"
#include <queue>
#include<stack>
#include<unordered_map>
#include<climits>
#include "node.h"

void printBetK1K2(BinaryTreeNode<int>* root, int k1, int k2)
{
    if(root==NULL)
    {
        return ;
    }

    if(root->data>=k1  && root->data<=k2)
    {
        cout<<root->data<<endl;
    }

    if(root->data >k1)
    {
        printBetK1K2(root->left,k1,k2);
    }

    if(root->data<k2)
    {
        printBetK1K2(root->right,k1,k2);
    }

}


int minimum(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return INT_MAX;
    }

    return min(root->data,min(minimum(root->left),minimum(root->right)));
}


int maximum(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return INT_MIN;
    }
      return max(root->data,max(maximum(root->left),maximum(root->right)));
}


    bool isBST1(BinaryTreeNode<int>* root)
    {
        if(root==NULL)
        {
            return true;
        }
        if(maximum(root->left)>root->data  ||  minimum(root->right)<=root->data)
        {
            return false;
        }

        return isBST1(root->left) && isBST1(root->right);

    }


    bool isBST2(BinaryTreeNode<int>* root)
    {
         if(root==NULL)
        {
            return true;
        }
        if(maximum(root->left)<=root->data &&  minimum(root->right)>root->data)
        {
            return true && isBST2(root->left) && isBST2(root->right);
        }

        return false;

    }

    class BSTReturn{

    public:
    bool isbst;
    int maxValue;
    int minValue;

    };


    BSTReturn isBST3(BinaryTreeNode<int>* root)
    {
        if(root==NULL)
        {
            BSTReturn output;
            output.isbst =true;
            output.maxValue=INT_MIN;
            output.minValue=INT_MAX;
            return output;
        }

        BSTReturn leftO=isBST3(root->left);
        BSTReturn rightO=isBST3(root->right);

        BSTReturn output;

        output.isbst= leftO.isbst && rightO.isbst && (leftO.maxValue<=root->data && rightO.minValue>root->data);
        output.maxValue= max(root->data,max(leftO.maxValue,rightO.maxValue));
        output.minValue =min(root->data,min(leftO.minValue,rightO.minValue));
        return output;

    }

    bool isBST4(BinaryTreeNode<int>* root,int minimum, int maximum)
    {
        if(root==NULL)
        {
            return true;
        }

        if(root->data < minimum || root->data >maximum)
        {
            return false;
        }

        bool isleft= isBST4(root->left,minimum,root->data);
        bool isright=isBST4(root->right,root->data +1,maximum);
        return isleft && isright ;
    }

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



    void inorderIterative(BinaryTreeNode<int>* root)
    {
        if(root==NULL)
        {
            return;
        }
        stack<BinaryTreeNode<int>* > s;
        s.push(root);
        root=root->left;
        while(!s.empty()|| root)
        {


            if(root)
            {
                s.push(root);
                 root=root->left;
            }
            else if(!root){
                BinaryTreeNode<int>* temp=s.top();
                s.pop();
                cout<<temp->data<<" ";
            root=temp->right;

            }

        }
        return;

    }


     void inorderIterativeReverse(BinaryTreeNode<int>* root)
    {
        if(root==NULL)
        {
            return;
        }
        stack<BinaryTreeNode<int>* > s;
        s.push(root);
        root=root->right;
        while(!s.empty()|| root)
        {


            if(root)
            {
                s.push(root);
                 root=root->right;
            }
            else if(!root){
                BinaryTreeNode<int>* temp=s.top();
                s.pop();
                cout<<temp->data<<" ";
            root=temp->left;

            }

        }
        return;

    }

    void printNodesSumToS(BinaryTreeNode<int> *root, int s)
    {
    // Write your code here
        if(root==NULL)
        {
            return;
        }
        stack<BinaryTreeNode<int>* > s1;
        stack<BinaryTreeNode<int>* > s2;

         BinaryTreeNode<int>* current1=root;
         BinaryTreeNode<int>* current2=root;

         int x=0,y=0;
         bool done1=0,done2=0;

    while(1)
    {

          while(done1==0)
         {

                if(current1!=NULL)
                {
                    s1.push(current1);;
                    current1=current1->left;
                }
            else{
                    if(s1.empty())
                    {
                        done1=1;
                    }
                    else
                    {current1=s1.top();
                    s1.pop();
                    x=current1->data;
                    current1=current1->right;
                    done1=1;
                    }
                }


            }


        while(done2==0)
        {

            if(current2!=NULL)
            {
                s2.push(current2);;
                current2=current2->right;
            }

            else{
                    if(s2.empty())
                    {
                        done2=1;
                    }
                    else{
                 current2=s2.top();
                 s2.pop();
                 y=current2->data;
                 current2=current2->left;
                 done2=1;
                    }

            }

        }

             if(x>=y)
            {
                return;
            }
            else if(x+y==s)
            {
                cout<<x<<","<<y<<endl;
                done1=0;
                done2=0;
            }

            else if(x+y > s)
            {
                done2=0;
            }

            else if(x+y < s)
            {
                done1=0;
            }



         }

    }


    class largestBST{
        public:
        bool isbst;
        int maximum;
        int minimum;
        int height;
    };

    largestBST  helperBST(BinaryTreeNode<int> *root)
    {
        if(root==NULL)
        {
            largestBST output;
            output.isbst=true;
            output.maximum=INT_MIN;
            output.minimum=INT_MAX;
            output.height=0;
            return output;
        }

        largestBST leftoutput=helperBST(root->left);
        largestBST rightoutput=helperBST(root->right);

        largestBST temp;

        if( !leftoutput.isbst  ||  !rightoutput.isbst)
        {
                temp.isbst=false;
                temp.height=max(leftoutput.height,rightoutput.height);
                temp.maximum=0;
                temp.minimum=0;
        }

        if(  leftoutput.isbst  &&  rightoutput.isbst  )
        {
            if(root->data >= leftoutput.maximum  &&  root->data < rightoutput.minimum)
            {
                temp.isbst=true;
                temp.height=1+max(leftoutput.height,rightoutput.height);
                temp.maximum=max(root->data,rightoutput.maximum);
                temp.minimum=min(root->data,leftoutput.minimum);
            }

            else{
                    temp.isbst=false;
                    temp.height=max(leftoutput.height,rightoutput.height);
                    temp.maximum=0;
                    temp.minimum=0;

            }

        }

        return temp;

    }


            int largestBSTSubtree(BinaryTreeNode<int> *root) {
                        // Write your code here
                if(root==NULL)
                {
                    return -1;
                }
                largestBST result=helperBST(root);
                return result.height;
            }



    void nodesSumToSHelper(BinaryTreeNode<int>* root,vector<int> &result)
        {
            if(root==NULL)
            {
                return;
            }

            result.push_back(root->data);
            nodesSumToSHelper(root->left,result);
            nodesSumToSHelper(root->right,result);
        }

    void nodesSumToS(BinaryTreeNode<int> *root, int sum)
     {
            // Write your code here
            if(root==NULL)
            {
                return;
            }

            vector<int> result;
            nodesSumToSHelper(root,result);

            unordered_map<int,bool> mymap;
            for(int i=0;i<result.size();i++)
            {
                if(mymap.find(sum-result[i])!=mymap.end())
                {
                  cout << min(result[i],sum -1*result[i]) << " " << max(result[i],sum -1*result[i]) << endl;
                }

                mymap[result[i]]=true;
            }


    }

int main()
{
    //BinaryTreeNode<int>* root=takeInput();
     //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

   BinaryTreeNode<int>* root=takeInputLevelWise();
    //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    //8 5 10 2 6 9 11 1 -1 -1 7 -1 -1 -1 -1 -1 -1 -1 -1
    //25 18 50 19 20 35 60 -1 15 18 25 20 40 55 70 -1 -1 -1 -1 -1 -1 -1 25 -1 -1 -1 -1 -1 -1 -1 -1
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
  //  int postorder[7]={4,6,5,2,7,3,1};
  //  int inorder[7]={4,2,6,5,1,3,7};
  //  BinaryTreeNode<int>* temp=getTreeFromPostorderAndInorder(postorder,7,inorder,7);
  //   cout<<endl;

//    printLevelWise(root);
//    cout<<endl;
//    inorderIterative(root);
//    cout<<endl;
//    inorderIterativeReverse(root);
//    cout<<endl<<endl;
//
//    printNodesSumToS(root,10);

//    cout<<endl;
//    cout<<  largestBSTSubtree(root)<<endl;
//    cout<<endl;

        nodesSumToS(root,6);

        cout<<endl;
    printLevelWise(root);

    return 0;

}


