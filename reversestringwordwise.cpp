
#include<iostream>

#include<string>

using namespace std;

void reverseWord2(char* start,char* last)
{
    while(start<last)
    {
        char temp=*start;
        *start=*last;
        *last=temp;
        start++;
        last--;
    }

}

void reverseStringWordWise2(char input[]) {
    // Write your code here
    char* start=input;
    char*last=input;

    while(*last)
    {
        last++;
        if(*last=='\0')
        {
         reverseWord2(start,last-1);
        }
        else if(*last==' ')
        {
            reverseWord2(start,last-1);
            start=last+1;
        }
    }
    reverseWord2(input,last-1);

}







void reverseWord(char* start,char* last)
{
    while(start<last)
    {
        char temp=*start;
        *start=*last;
        *last=temp;
        start++;
        last--;
    }

}

void reverseWord(char input[],int si, int li)
{
    while(si<li)
    {
        char temp=input[si];
        input[si]=input[li];
        input[li]=temp;
        si++;
        li--;
    }

}

void reverseStringWordWise(char input[]) {
    // Write your code here
    int si=0;
    int li=0;
    while(input[li])
    {
        li++;
        if(input[li]=='\0')
        {
            reverseWord(input,si,li-1);
        }
        if(input[li]==' ')
        {
            reverseWord(input,si,li-1);
            si=li+1;
        }

    }
    reverseWord(input,0,li-1);
}



int main()
{
    char input[]="ayush is handsome";

    cout<<input;
    cout<<endl;
    reverseStringWordWise(input);

    cout<<input<<endl;
    return 0;




}
