#include <bits/stdc++.h>
using namespace std;

long long arr[100000];
//long long sum[100000];

//int arr[100000];

 
long long sum=0;
int main() {
	int t;
	int n;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			//sum[i]=0;
		}
		 
		unordered_map<long long, long long> m;
 		bool flag=true;
		for(int i=0;i<n;i++)
		{
			sum=arr[i];
			if(m.find(sum)!=m.end())
			{
				flag=false;
				break;
			}
			else
				m[sum]++;
			for(int j=i+1;j<n;j++)
			{
				sum|=arr[j];
				if(m.find(sum)!=m.end())
				{
					flag=false;
					break;
				}
				else
					m[sum]++;
			}
			if(!flag)
				break;
		}

		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;



	}

 
 
	return 0;
}