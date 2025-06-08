#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 100005, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;

void init() {

}
int a[N];
void solve() {
    int n,q;
    cin >> n >> q;
    map<int, vector<int>> p;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        p[a[i]].push_back(i);
    }
    while(q--) {
        int k,l,r;
        cin >> k >> l >> r;
        vector<int> yz;
        yz.push_back(k);
        for(int i=2;i<=sqrt(k);i++) {
            if(k%i==0) {
                yz.push_back(i);
                if(i*i!=k) yz.push_back(k/i);
            }
        }
        vector<int> pos;
        for(int x:yz){
            if(p[x].size()) {
                int i=lower_bound(p[x].begin(), p[x].end(), l) - p[x].begin();
                if(i<p[x].size()&&p[x][i]<=r){
                    pos.push_back(p[x][i]);
                }
            }
        }
        int ans=0;
        sort(pos.begin(), pos.end());
        int pre=l;
        for(int x:pos) {
            ans+=k*(x-pre);
            pre=x;
            while(k%a[x]==0) k/=a[x];
        }
        ans+=k*(r-pre+1);
        cout << ans << endl;
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