#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll long long int
#define mod 1000000007

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	ll n,k; cin>>n>>k;
	cout<<3*n+min(k-1 ,n-k)<<endl;
	return 0;
}
