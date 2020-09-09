#include <bits/stdc++.h>
using namespace std;

int coins[2000001];
int w[2000001];
 

int main() {

	int t,n,k,c,n1,j=0;

	cin>>t;

	while(t--)
	{
		c=0;
		n1=0;
		j=0;
		long int sum=0;
		//j=0;
		cin>>n>>k;

		for(int i=0;i<n;i++)
			cin>>coins[i];
		sort(coins, coins+n);
		for(int i=0;i<k;i++)
		{
			cin>>w[i];
			//n1+=w[i];
			if(w[i]==1)
				c++;
		}

		sort(w,w+k);
		int j1=k-1;
		while(j1>=0 && w[j1]>1)
		{
			sum+=coins[j];
			j+=w[j1];
			j1--;
		}
		 
		
		//long int sum=0;
		 
		int i=n-1;
		int c1=c;

		while(c1>0)
		{
			sum+=2*coins[i];
			i--;
			c1--;
		}
		c=k-c;
		c1=c;
		while(c1>0)
		{
			sum+=coins[i];
			i--;
			c1--;
		}
 

		cout<<sum<<endl;


 

	}
 
	return 0;
}