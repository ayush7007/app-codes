

#include<iostream>
#include<algorithm>

using namespace std;

    void mergeintoone(int in[],int out[],int n,int m)
    {
        int i=m+n-1;
        int j=m+n-1;

        while(i>=0)
        {
            if(out[i]!=0)
            {
                swap(out[i],out[j]);
                i--;
                j--;
            }
            else{
                i--;
            }

        }

        int first=0;
        int second=n;
        int k=0;

        while(first<n&&second<n+m)
        {

        if(in[first]>out[second])
        {
            out[k]=out[second];
            second++;
            k++;
        }
        else if(in[first]< out[second])
        {
            out[k]=in[first];
            first++;
            k++;
        }

        }




        while(first<n&&k<n+m)
        {
            out[k]=in[first];
            k++;
            first++;

        }
        while(second<n+m&&k<n+m)
        {
            out[k]=out[second];
            k++;
            second++;
            }

    }


int main()
{
    int in[]={2,3,4,7,9};

    int out[9]={1,0,0,5,0,6,0,8,0};


    mergeintoone(in ,out,5,4);

    for(int i=0;i<9;i++){
        cout<<out[i]<<" ";
    }
    cout<<endl;
    return 0;
}









