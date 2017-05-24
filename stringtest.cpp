#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;


void print(int pos,int open,int close,int n,string s1)
{
    if(close==n)
    {
        cout<<s1<<endl;
        return;
    }

    else
  {
    if(open > close) {
        s1[pos] = ')';
        print(pos, open, close+1,n,s1);
    }
    if(open < n) {
       s1[pos] = '(';
       print(pos+1, open+1, close,n,s1);
    }
  }
}



void printWellFormedParanthesis(int n){
    // Write your code here
        if(n<=0)
        return ;
        string s1;
        print(0,0,0,n,s1);
}


int main()
{
    printWellFormedParanthesis(4);
    return 0;
}




