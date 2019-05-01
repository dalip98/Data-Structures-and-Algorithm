    #include <bits/stdc++.h>
    #include <vector>
    #include <algorithm>
    #define ll long long int
    #define mod 1000000007

    using namespace std;

    vector<ll> initializeDiffArray(vector<ll>& A)
    {
        ll n = A.size();

        // We use one extra space because
        // update(l, r, x) updates D[r+1]
        vector<ll> D(n + 1);

        D[0] = A[0], D[n] = 0;
        for (ll i = 1; i < n; i++)
            D[i] = A[i] - A[i - 1];
        return D;
    }

    // Does range update
    void update(vector<ll>& D, ll l, ll r, ll x)
    {
        D[l] += x;
        D[r + 1] -= x;
    }

    // Prints updated Array
    vector<ll> printArray(vector<ll>& A, vector<ll>& D)
    {
        for (ll i = 0; i < A.size(); i++) {
            if (i == 0)
                A[i] = D[i];

            // Note that A[0] or D[0] decides
            // values of rest of the elements.
            else
                A[i] = D[i] + A[i - 1];

            //cout << A[i] << " ";
        }
        return A;
    }

    // Driver Code
    int main()
    {

        ll t; cin>>t;
        ll z = t;
        while(t--)
        {
            ll p,q; cin>>p>>q;
            vector<ll>x(q+1);
            vector<ll>y(q+1);
            vector<pair<ll,ll> >cor(p);
            vector<char>dir(p);


            vector<ll> ans1 = initializeDiffArray(x);
            vector<ll> ans2 = initializeDiffArray(y);
            for(ll i=0 ; i<p;i++)
            {
                cin>>cor[i].first>>cor[i].second>>dir[i];
                if(dir[i]=='N')
                {
                    update(ans2 , cor[i].second +1,q , 1);
                }
                else if(dir[i]=='S')
                {
                    update(ans2 , 0,cor[i].second -1 , 1);
                }
                else if(dir[i]=='E')
                {
                    update(ans1 , cor[i].first +1,q , 1);
                }
                else
                    update(ans1 ,  0 ,cor[i].first-1, 1);

            }
             x = printArray(x , ans1);
             y = printArray(y , ans2);
            ll mx = x[0] , m=0,n=0;
            for(ll i=0;i<=q;i++)
            {
                //cout<<x[i]<<" ";
                if(x[i]>mx)
                {
                    mx = x[i];
                    m=i;
                }
            }
            //cout<<endl;
            mx = y[0];
            for(ll i=0;i<=q;i++)
            {
                //cout<<y[i]<<" ";
                if(y[i]>mx)
                {
                    mx = y[i];
                    n=i;
                }
            }
            cout<<"Case #"<<z-t<<": ";
            cout<<m<<" "<<n<<endl;
        }

        return 0;
    }

