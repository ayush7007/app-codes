
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

bool checkpermu(string s1,string s2)
{
    int n=s1.size();
    int m=s2.size();
    unordered_map<char,int> mymap;
    if(n!=m)
    {
        return false;
    }
    else
    {

        for(int i=0;i<n;i++)
        {
            mymap[s1[i]]=mymap[s1[i]]+1;
        }
         for(int i=0;i<m;i++)
        {
            if(mymap.find(s2[i])!=mymap.end())
            {
                mymap[s2[i]]--;
            }
            else{
                return false;
            }

        }
    }
     unordered_map<char,int>::iterator it=mymap.begin();

     while(it!=mymap.end())
     {
         if(it->second==0)
         {
             it++;
         }
         else
         {
             return false;
         }

     }

}


int main()
{

    string s1="abc";

    string s2="abc";


    bool i= checkpermu(s1,s2);

    cout<<i<<endl;


    return 0;


}





