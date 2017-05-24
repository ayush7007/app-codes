#include <iostream>

using namespace std;

int binaryhelper(int input[],int startindex,int endindex,int element)
{
    if(startindex>endindex)
    {
        return -1;
    }
    int mid=(startindex+endindex)/2;
    if(input[mid]==element)
    {
        return mid;
    }
    if(input[mid]>element)
    {
         return binaryhelper(input,startindex,mid-1,element);
    }

     if(input[mid]<element)
    {
         return binaryhelper(input,mid+1,endindex,element);
    }


}



int binarySearch(int input[], int size1, int element) {

        return binaryhelper(input,0,size1-1,element);
}


int main()
{
  int input[50],size1,element;
  cout<<"Enter the size of array"<<endl;
  cin>>size1;
  for(int i=0;i<size1;i++)
  {
      cin>>input[i];
  }
   cout<<"Enter the value to be searched:"<<endl;
   cin>>element;



   int index= binarySearch(input,size1,element);

   cout<<"element found at index"<<index<<endl;

    return 0;
}





