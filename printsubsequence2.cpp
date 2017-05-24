#include<iostream>
using namespace std;

    void printsubs(char input[],char osofar[],int oi)
    {
        if(input[0]=='\0')
        {
            osofar[oi]='\0';
            cout<<osofar<<endl;
            return;
        }

        printsubs(input+1,osofar,oi);
        osofar[oi]=input[0];
        printsubs(input+1,osofar,oi+1);

    }
    void printSubSequences(char input[])
    {
        // Write your code here
        char osofar[100];
        printsubs(input, osofar,0);

    }

    int main()
    {
        char input[500];
        cout<<"enter the string"<<endl;
        cin>>input;
        cout<<endl;
        printSubSequences(input);
        return 0;

    }
