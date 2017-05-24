
#include "BTnode2.h"


class BST{

        BinaryTreeNode<int>* root;
        int countN=0;


        public:
            BST()
            {
                countN=0;
                root=NULL;
            }


            int Size()
            {
                return countN;
            }


            bool findElement(int element)
            {
                return findElement(root,element);
            }


        private:

            static bool findElement(BinaryTreeNode<int>* root1, int element)
            {

            }



};
