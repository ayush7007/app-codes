#include<iostream>
using namespace std;

bool checkReverseHelper(char input1[],int si,char input2[],int ei)

{

    if(input1[si]=='\0')
    {
        return true;
    }

    if(input1[si]==input2[ei])
    {
        return checkReverseHelper(input1,si+1,input2,ei-1);
    }

        return false;

}





bool checkReverse(char input1[], char input2[]) {
    // Write your code here
    int size1=0;
    int size2=0;
    while(input1[size1]!='\0')
    {
        size1++;
    }

    while(input2[size2]!='\0')
    {
        size2++;
    }

    if(size1==size2)
    {
        return checkReverseHelper(input1,0,input2,size2-1);
    }


        return false;

}

int main()
{

    char input1[]="hello";
    char input2[]="olleh";
    cout<<checkReverse(input1,input2);
    return 0;

}
