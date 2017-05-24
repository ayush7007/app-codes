#ifndef BTNODE_H
#define BTNODE_H

using namespace std;
template <typename T>
class BTNode {
	T data;
	TreeNode* left;
    TreeNode* right;

	public:

	TreeNode(T data) {
	this->data = data;
	left=NULL;
	right=NULL;

	}


	void addLeftChild(int n) {

		if(n==-1)
        { return;
            }
        TreeNode* child=new TreeNode(n);
		left=child;
	}

    void addRightChild(TreeNode* child) {
        if(n==-1)
        { return;
            }
        TreeNode* child=new TreeNode(n);
		right=child;
	}

	void setChild(int i, TreeNode* child) {
		if(i==0)
        {
            left=child;
        }
		if(i==1)
        {
            right=child;
        }
        else{
            throw" u have to enter only 0 and 1";
        }
	}

	TreeNode<int>* getLeftChild() {

		return left;
	}

	TreeNode<int>* getRightChild() {

		return right;
	}

	T getData() {
		return data;
	}


	void setData(T data) {
		this->data = data;
	}


	~TreeNode() {
            delete left;
            delete right;
		}
	}
};
#endif


