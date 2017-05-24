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
#include<vector>
#include "node.h"

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

    BinaryTreeNode<int>* getTreeFromInAndLevel(int * inorder ,int * level ,int length)
    {
        if(length==0)
        {
            return NULL;
        }

        BinaryTreeNode<int>* root=new BinaryTreeNode<int>(level[0]);
        int i;
        for(i=0;i<length;i++)
        {
            if(inorder[i]==root->data)
            {
                break;
            }
        }

        int leftL=i;
        int rightL=length-1-i;

        int* leftLevel= new int[leftL];
        int* rightLevel=new int[rightL];

        unordered_map<int,bool> leftTree;
        for(int k=0;k<leftL;k++)
        {
            leftTree[inorder[k]]=1;
        }
        unordered_map<int,bool> rightTree;
        for(int k=i+1;k<length;k++)
        {
            rightTree[inorder[k]]=1;
        }
         int l=0,r=0;
        for(int k=1;k<length;k++)
        {
            if(leftTree[level[k]])
            {
                leftLevel[l]=level[k];
                l++;
            }
            if(rightTree[level[k]])
            {
                rightLevel[r]=level[k];
                r++;
            }

        }

        root->left =getTreeFromInAndLevel(inorder,leftLevel,leftL);
        root->right=getTreeFromInAndLevel(inorder+i+1,rightLevel,rightL);
        delete [] leftLevel;
        delete [] rightLevel;

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


    void verticalSumHelper(BinaryTreeNode<int>* root,int level,unordered_map<int,int>& allSum)
    {
        if(root==NULL)
        {
            return;
        }

        allSum[level]+=root->data;
        verticalSumHelper(root->left,level-1,allSum);
        verticalSumHelper(root->right,level+1,allSum);
    }



    void verticalSum(BinaryTreeNode<int>* root)
    {

        if(root==NULL)
        {
            return;
        }

        unordered_map<int,int> allSum;

        verticalSumHelper(root,0,allSum);

        unordered_map<int,int> :: iterator it=allSum.begin();
        while(it!=allSum.end())
        {
            cout<<"Level:"<<(*it).first<<"-->"<<(*it).second<<endl;
            it++;
        }
        cout<<endl;

    }


    BinaryTreeNode<int>* preToBSt(int* preorder ,int length)
    {
        if(length==0)
        {
            return NULL;
        }

        BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[0]);

        int i=1;
        for( i=1;i<length;i++)
        {
            if(preorder[i]>root->data)
                break;
        }

        int leftL=i-1;
        int rightL=length-i;
        root->left=preToBSt(preorder+1,leftL);
        root->right=preToBSt(preorder+i,rightL);
        return root;
    }


    BinaryTreeNode<int>* pretobst(int* preorder,int length,int &preindex,int minValue,int maxValue)
    {
        if(preindex>=length)
        {
            return NULL;
        }

            if(  preorder[preindex]>minValue   &&   preorder[preindex]<maxValue  )
            {

                BinaryTreeNode<int>* newNode=new BinaryTreeNode<int>(preorder[preindex]);
                preindex=preindex+1;
                newNode->left= pretobst(preorder,length,preindex,minValue,newNode->data);
                newNode->right=pretobst(preorder,length,preindex,newNode->data,maxValue);
                return newNode;
            }

            return NULL;
    }


    class path{
        public:
        int maxPath;
        int leafPath;
    };

    path leaftoleaf(BinaryTreeNode<int>* root)
    {
        if(root==NULL)
        {
                path p;
                p.maxPath=INT_MIN;
                p.leafPath=0;
                return p;
        }

        if(root->left==NULL && root->right==NULL)
        {
            path p;
            p.maxPath=root->data;
            p.leafPath=root->data;
            return p;
        }

        path p;
        path l=leaftoleaf(root->left);
        path r=leaftoleaf(root->right);
        p.maxPath=max(l.maxPath,max(r.maxPath,root->data+l.leafPath+r.leafPath));
        p.leafPath=root->data+max(l.leafPath,r.leafPath);
        return p;
    }

    void parentArrayHelper(BinaryTreeNode<int>* root,unordered_map<int,vector<int>*> & mymap)
    {

        if(mymap[root->data]==NULL)
        {
            root->left=NULL;
            root->right=NULL;
            return;
        }


        vector<int>* vec=mymap[root->data];
        if(vec->size()==1)
        {
            root->left=new BinaryTreeNode<int>(vec->at(0));
            parentArrayHelper(root->left,mymap);
            return;
        }

        if(vec->size()==2)
        {

            root->left=new BinaryTreeNode<int>(vec->at(0));
            parentArrayHelper(root->left,mymap);
            root->right= new BinaryTreeNode<int>(vec->at(1));
            parentArrayHelper(root->right,mymap);
            return;
        }

    }

    BinaryTreeNode<int>* parentArray(int* arr,int Size)
    {

        unordered_map<int,vector<int>*> mymap;
        int rootValue;
        for(int i=0;i<Size;i++)
        {
            mymap[i]=NULL;
            if(arr[i]!=-1)
            mymap[arr[i]]=NULL;
        }

        for(int i=0;i<Size;i++)
        {
            if(arr[i]==-1)
            {
                rootValue=i;
                continue;
            }
            if(mymap[arr[i]]!=NULL)
            {
                (mymap[arr[i]])->push_back(i);
            }
            if(mymap[arr[i]]==NULL)
            {
                vector<int>* vec=new vector<int>();
                mymap[arr[i]]=vec;
                vec->push_back(i);
            }
        }


        BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootValue);

        parentArrayHelper(root,mymap);

        for(int i=0;i<Size;i++)
        {
            if(mymap[arr[i]])
            {
                delete mymap[arr[i]];
            }
        }
        return root;
    }


    int main()
    {
        /*
        int level[7]={20,8,22,4,12,10,14};
        int inorder[7]={4,8,10,12,14,20,22};
        BinaryTreeNode<int>* temp=getTreeFromInAndLevel(inorder,level,7);
        cout<<endl;
        */




       /* BinaryTreeNode<int>* root=takeInputLevelWise();
        //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
        printLevelWise(root);
        cout<<endl;

        verticalSum(root);
        cout<<endl;
        */


        /*
        int preorder[] = {10, 5, 1, 7, 40, 50};
        BinaryTreeNode<int>* temp=preToBSt(preorder,6);
        printLevelWise(temp);
        cout<<endl;
        */

        /*
         int preorder[] = {10, 5, 1, 7, 40, 50};
         int preindex=0;
        BinaryTreeNode<int>* temp=pretobst(preorder,6,preindex,INT_MIN,INT_MAX);
        printLevelWise(temp);
        cout<<endl;
        */

        /*
        BinaryTreeNode<int>* root=takeInputLevelWise();
        //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
        printLevelWise(root);
        cout<<endl;
        path result=leaftoleaf(root);
        cout<<result.maxPath;
        cout<<endl;
        */

        /*
        int arr[]={1,5,5,2,2,-1,3};
        BinaryTreeNode<int>* temp=parentArray(arr,7);
        printLevelWise(temp);
        cout<<endl;
        */





        return 0;

    }






