#include<iostream>

using namespace std;


void swap1(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


int permutationsHelper(char input[],int si,char output[][50])
{
        if(input[si+1]=='\0')
        {
            output[0][0]=input[si];
            output[0][1]='\0';
            return 1;
        }

     int i;
     int Size=0;
       for(i=si;input[i]!='\0';i++)
        {
           swap1((input+si),(input+i));
           char smalloutput[50][50];
           int k= permutationsHelper(input,si+1,smalloutput);


           for(int j=0;j<k;j++)
           {
               output[j+Size][0]=input[si];
               int l=0;
               for(;smalloutput[j][l]!='\0';l++)
               {
                   output[j+Size][l+1]=smalloutput[j][l];
               }
               output[j+Size][l+1]='\0';

           }
                 Size=Size+k;
           swap1((input+si),(input+i));
        }

        return Size;
}



int permutations(char input[], char output[][50]) {
	// Write your code here

    return permutationsHelper(input,0,output);


}


int main()
{

    char output[50][50];
    char input[]="abcd";

    int k= permutations(input,output);

    for(int i=0;i<k;i++)
    {
            cout<<output[i]<<endl;
    }
    return 0;
}







