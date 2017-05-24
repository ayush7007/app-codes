#include<iostream>
using namespace std;

void stringcompression(char a[],int si)
{
    if(a[si]=='\0')
    {
        return ;
    }

    char p=a[si];
    int no=1;

    for(int i=si+1;a[i]!='\0';i++)
    {
        if(a[i]==p)
        {
            no++;
        }
        else{
            break;
        }
    }
    if(no==1)
    {
        stringcompression( a, si+1);
    }
    if(no>1&&no<10)
    {
        a[si+1]='0'+no;
        int i;
        for( i=si+no;a[i]!='\0';i++)
        {
            a[i-no+2]=a[i];
        }
        a[i-no+2]='\0';
         stringcompression( a, si+2);
    }
    if(no>=10&&no<100)
    {
        a[si+2]='0'+(no%10);
        a[si+1]='0'+(no/10)%10;
        int i;
        for(i=si+no;a[i]!='\0';i++)
        {
            a[i-no+3]=a[i];
        }
        a[i-no+3]='\0';
         stringcompression( a, si+3);
    }


}



int main()
{

    char a[]="abbbbbbbbbbbccccefgggghhhhhhhhhh";

    stringcompression(a,0);


    cout<<a;
    return 0;

}
