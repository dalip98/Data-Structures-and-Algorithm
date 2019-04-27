#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll long long int
#define mod 1000000007

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	string a ,b ; cin>>a>>b;
	ll x = (a[0]-'0')*10 + (a[1]-'0') , y = (a[3]-'0')*10 + (a[4]-'0');
	ll m = (b[0]-'0')*10 + (b[1]-'0') , n = (b[3]-'0')*10 + (b[4]-'0');

	ll c ,d;
	if((m+x)%2!=0)
    {

        c= (m+x-1)/2;
        y+=60;
    }
    else
        {
        c= (m+x)/2;}
    d=(y+n)/2;

    if(d>=60)
    {
        d-=60;
        c++;
    }
    if(c<10)
    {
        cout<<0;
    }
    cout<<c<<":";
    if(d<10)
    {
        cout<<0;
    }
    cout<<d<<endl;
	return 0;
}
