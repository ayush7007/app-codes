//
//#include <iostream>
//#include<unordered_map>
//using namespace std;
//
//int main(){
//
// int k;
// cin>>k;
// char t[1001];
// char g[1001];
// cin>>t;
// cin>>g;
//    int m=k;
//    unordered_map<char,int> mymap;
//    for(int i=0;t[i]!='\0';i++)
//    {
//        mymap[t[i]]=mymap[t[i]]+1;
//    }
//    for(int i=0;g[i]!='\0';i++)
//    {
//        if(mymap.find(g[i])!=mymap.end())
//        {
//            if(mymap[g[i]]>0)
//            {
//                 mymap[g[i]]=mymap[g[i]]-1;
//                 m--;
//            }
//        }
//    }
//
//    if(m<=0)
//    {
//        cout<<"YES";
//    }
//    else{
//        cout<<"NO";
//    }
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main(){
//
//    int n,q;
//
//
//    cin>>n;
//    cin>>q;
//
//	int* arr=new int[n];
//	for(int i=0;i<n;i++)
//    {
//        cin>>arr[i];
//    }
//
//	int m=q;
//
//    int *ans=new int[q+5];
//    int Size=0;
//	int which=0;
//
//	while(m--)
//    {
//
//        cin>>which;
//        if(which==1)
//        {
//            int x,y;
//            cin>>x;
//            cin>>y;
//            int sum=0;
//            for(int i=x;i<=y;i++)
//            {
//                sum=sum+arr[i-1];
//            }
//              ans[Size]=sum;
//
//                Size++;
//
//        }
//
//        else if(which==2)
//        {
//            int x,y,z;
//            cin>>x>>y>>z;
//
//            for(int i=x;i<=y;i++)
//            {
//                arr[i-1]=arr[i-1]%z;
//            }
//
//        }
//
//
//
//    }
//
//
//
//    for(int i=0;i<Size;i++)
//    {
//        cout<<ans[i]<<endl;
//    }
//
//    delete [] arr;
//    delete [] ans;
//
//	return 0;
//}
//
//



























