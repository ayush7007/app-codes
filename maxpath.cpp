#include<iostream>
#include<algorithm>
using namespace std;



int path(int a[],int size1,int b[],int size2)
{
    int i=0;
    int j=0;
    int sum1=0,sum2=0;
    int maxsum=0;

    while(i<size1&&j<size2)
    {

      if(a[i]<a[j])
      {
          sum1=sum2+a[i];
          i++;

      }
        else if(a[i]>a[j])
      {
          sum2=sum2+a[j];
          j++;
      }
      else if(a[i]==a[j])
        {
                maxsum=maxsum+max(sum1,sum2);
             i++;
             j++;
        }
    }



    return maxsum;



}




int main()
{

    int a[]={1,3,5,7,9,11,13,15};
    int b[]={2,5,6,8,9,10,13,16,};

    path(a,8,b,8);

    return 0;
}
