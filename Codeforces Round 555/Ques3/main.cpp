#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll long long int
#define mod 1000000007

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	ll n; cin>>n;
	vector<ll>arr(n);
	for(ll i=0;i<n;i++)
        cin>>arr[i];
    queue<ll>brr;
    ll l=0,r=n-1;
    queue<char>q;
    if(arr[l]<arr[r])
    {

        brr.push(arr[l]);
        q.push('L');
        l++;

    }
    else
    {

        brr.push(arr[r]);
        q.push('R');
        r--;
    }
    //cout<<brr.size()<<endl;
    while(l<=r)
    {

        if(arr[l]<brr.back()&&arr[r]<brr.back())
            break;
        else
        {
             if(arr[l]<arr[r])
               {
                   if(arr[l]>brr.back())
                   {

                   brr.push(arr[l]);
                   q.push('L');
                   l++;
                   }
                   else
                   {

                     brr.push(arr[r]);
                     q.push('R');
                     r--;
                   }

               }
             else if(arr[l]>arr[r])
                 {
                     if(arr[r]>brr.back())
                     {

                     brr.push(arr[r]);
                     q.push('R');
                     r--;
                     }
                     else
                     {

                   brr.push(arr[l]);
                   q.push('L');
                   l++;
                     }
                 }
             else
                break;
        }
    }

    if(arr[l]>brr.back())
    {
        q.push('L');
        brr.push(arr[l]);
    }
    else if(arr[r]>brr.back())
    {
        q.push('R');
        brr.push(arr[r]);
    }
    cout<<brr.size()<<endl;

    while(!q.empty())
    {
        cout<<q.front();
        q.pop();
    }
	return 0;
}
