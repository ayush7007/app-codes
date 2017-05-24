
#include<iostream>
using namespace std;

bool searchin2D(int mat[][4],int n,int element)
{
        int i=0,j=n-1;

        while(i<n&&j>=0)
        {

        if(mat[i][j]==element)
        {
            return true;
        }
         if(mat[i][j]>element)
        {
            j--;
        }
        else
        {
            i++;
        }

        }
        return false;

}

int main()
{

    int mat[4][4] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50},
                  };
  bool result = searchin2D(mat, 4,51);

  cout<<result<<endl;
  return 0;


  }
