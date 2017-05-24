#include<iostream>
using namespace std;
// Change in the given string itself. So no need to return or print the changed string.

    void pairStarHelper(char input[],int si)
    {
        if(input[si]=='\0')
        {
            return;
        }

        if(input[si]==input[si+1])
        {
               int size1=0;
               while(input[size1]!='\0')
               {
                   size1++;
               }

               for(int i=size1;i>si;i--)
               {
                   input[i+1]=input[i];
               }

            input[si+1]='*';
            pairStarHelper(input,si+2);
        }

        else{
            pairStarHelper(input,si+1);
        }
    }

void pairStar(char input[]) {
    // Write your code here
    pairStarHelper(input,0);
}


int main()
{

    char input[]="helloojjfryy";
    pairStar(input);

    cout<<input<<endl;
}
