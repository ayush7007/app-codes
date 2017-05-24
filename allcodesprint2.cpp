

#include<iostream>
#include<string>

using namespace std;



void allCodesH(char input[],int size1,char output[],int size2)
{
    if(size1==0)
    {
        cout<<output<<endl;
        return;
    }

            int k=input[0]-'0';
         char first='a'-1+k;
         output[size2]=first;
         output[size2+1]='\0';
         allCodesH(input+1,size1-1, output,size2+1);
         output[size2]='\0';


     if(size1>1)
     {

         int num=10*(input[0]-'0')+(input[1]-'0');
         if(num<=26)
         {
         char second='a'-1+num;
        output[size2]=second;
         output[size2+1]='\0';
         allCodesH(input+2,size1-2, output,size2+1);
         output[size2]='\0';
         }

     }

}



void printAllPossibleCodes(char input[]) {
    // Write your code here

    char output[20]="";
    int i=0;
    while(input[i]!='\0')
    {
        i++;
    }
    allCodesH( input,i,output,0);


}


int main()
{
        char input[]= "1123";
     printAllPossibleCodes(input);


    return 0;
}
















