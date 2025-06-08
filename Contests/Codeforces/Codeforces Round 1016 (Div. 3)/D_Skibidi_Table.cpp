#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 200005, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;

void init() {

}

void solve() {
    int n;
    cin >> n;
    int q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        if(s=="->") {
            int x,y;
            cin >> x >> y;
            int al=1ll<<n;
            int ans=0;
            while(al>>=1) {
                if(x<=al) {
                    if(y<=al) ans=ans<<2;
                    else ans=ans<<2|3;
                }else{
                    if(y<=al) ans=ans<<2|2;
                    else ans=ans<<2|1;
                }
                x=(x-1)%al+1;
                y=(y-1)%al+1;
            }
            cout << ans+1 << endl;
        }else{
            int nu;
            cin >> nu;
            int x=1,y=1;
            for(int i=0;i<n;i++) {
                int t=nu-1>>2*i&3;
                if(t==1) x+=1<<i,y+=1<<i;
                else if(t==2) x+=1<<i;
                else if(t==3) y+=1<<i;
            }
            cout << x << ' ' << y << endl;
        }
    }
}
signed main() {
    cios
    init();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}