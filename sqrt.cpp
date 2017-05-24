#include <iostream>
#include<cmath>
#include<map>
#include<iomanip>

using namespace std;

int main(){
	// Write your code here
	long n;
	cin>>n;
	long k;
	cin>>k;
	long x,y;
	map<double,long> mymap;

	for(long i=0;i<n;i++)
	{
	    cin>>x;
	    cin>>y;
	    double d=sqrt(x*x + y*y);

	    mymap[d]++;
	}

	map<double,long>::iterator it=mymap.begin();

	long count=0;
	double d=0;
	while(it!=mymap.end())
	{
	    count=count+it->second;
	    if(count>=k)
	    {
	        d=it->first;
	        break;
	    }
	    it++;
	}


	cout<<fixed<<setprecision(6)<<d;

	return 0;
}
