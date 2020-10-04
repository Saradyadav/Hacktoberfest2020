#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int n;
    cin >> n;
    ll a[n];
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    ll p[32][n];
    for( ll i = 0; i < 32; i++){
        for( ll j = 1; j <= n; j++){
            if(a[j] & (1LL << i))
                p[i][j] = 1;
        }
    }

     for( ll i = 0; i < 32; i++){
        for( ll j = 1; j <= n; j++){
            p[i][j] += p[i][j - 1];
        }
    }

    int q;
    cin >> q;
    while(q--){
        ll l, r;
        cin >> l >> r;
        ll ans = 1e18;
        for( ll i = 0; i < 32; i++){
            ll set = (p[i][r] - p[i][l - 1]);
            ans = min( ans, (1LL << i) * (r - l + 1 - set) );
        }
        cout << ans << endl;
    }
}
