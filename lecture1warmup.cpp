#include<iostream>
using namespace std;

void pattern1(int n)
{
    int k=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<k;
            k++;
        }
        cout<<endl;
    }

}

void pattern2(int n)
{

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            cout<<" ";
        }
        for(int k=i;k<=2*i-1;k++)
        {
            cout<<k;
        }
           for(int l=2*i-2;l>=i;l--)
        {
            cout<<l;
        }
        cout<<endl;
    }


}

int sumofdigits(int n)
{
    int sum=0;
    while(n)
        {
            sum=sum+(n%10);
            n=n/10;
        }
        return sum;

}

int decimaltobinary(int n)
{
    int m=1;
    while(n)
    {
        m=m*10+(n%2);
        n=n/2;
    }

    int k=0;
    while(m)
    {

        k=k*10+m%10;
        m=m/10;
    }

    return k/10;

}


int main()
{

    pattern1(4);
    cout<<endl<<endl;

    pattern2(5);
    cout<<endl;

    int n;
    cout<<"enter to find sum of digits"<<endl;
    cin>>n;
    cout<<"sum of digits is"<<endl;
    cout<<sumofdigits(n);
    cout<<endl;


    int k;
    cout<<"enter to convert from decimal to binary"<<endl;
    cin>>k;
    cout<<"binary conversion is"<<endl;
    cout<<decimaltobinary(k);
    cout<<endl;





    return 0;
}
