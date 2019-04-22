#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#define ll long long int
#define mod 1000000007


using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    vector<ll>arr(3);

    cin>>arr[0]>>arr[1]>>arr[2];

    ll mn = min(arr[0]/3 , arr[1]/2);
    mn = min(arr[2]/2 , mn);

    arr[0] -= mn*3;
    arr[1] -= mn*2;
    arr[2] -= mn*2;

    vector<ll>week={ 1, 2 , 3 , 1 , 3 , 2 ,1};
    ll temp ,mx =0;
    for(ll i=0;i<7;i++)
    {
        ll a = arr[0] , b =arr[1] ,c = arr[2] ,flag=0;

        for(ll j=i;j<7;j++)
        {
            if(week[j]==1)
            {
                a--;
            }
            else if(week[j]==2)
                b--;
            else
                c--;
            if(a<0||b<0||c<0)
            {
                temp = j-i ;
                flag=1;
                break;
            }
            if(j==6)
            {
                temp = j-i+1;
            }
        }
        //cout<<temp<<endl;
        if(flag==0)
        {
            for(ll j=0;j<i-1;j++)
            {
            if(week[j]==1)
            {
                a--;
            }
            else if(week[j]==2)
                b--;
            else
                c--;
            if(a<0||b<0||c<0)
            {
                break;
            }
            temp++;
            }
        }
        mx = max(mx ,temp);
        //cout<<mn<<" "<<mx<<endl;
    }
    cout<< 7*mn + mx<<endl;
    return 0;
}
