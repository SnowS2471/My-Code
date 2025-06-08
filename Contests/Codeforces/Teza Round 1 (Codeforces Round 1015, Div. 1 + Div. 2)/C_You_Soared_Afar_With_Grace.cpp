#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
#define dbug() cout << "========================" << endl;
using namespace std;
const int N = 200005, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;

void init() {

}

int a[N],b[N];
void solve() {
    // dbug()
    int n;
    cin >> n;
    vector<int> ma(n+1),mb(n+1);
    for(int i=1;i<=n;i++) cin >> a[i],ma[a[i]]=i;
    for(int i=1;i<=n;i++) cin >> b[i],mb[b[i]]=i;
    vector<pair<int,int>> ans;
    for(int i=1,f=0;i<=n/2;i++) {
        if(a[i]==b[i]) {
            if(n%2==0 || f){
                cout << -1 << endl;
                return;
            }else{
                f=1;
                ans.push_back({i,n/2+1});
                swap(a[i],a[n/2+1]);
                swap(b[i],b[n/2+1]);
                i--;
                continue;
            }
        }
        if(mb[a[i]] == ma[b[i]]) {
            if(mb[a[i]] == n-i+1) continue;
            // cout << n-i+1 << ' ' << ma[b[i]] << endl;
            ans.push_back({n-i+1,ma[b[i]]});
            ma[a[n-i+1]] = ma[b[i]];
            mb[b[n-i+1]] = mb[a[i]];
            swap(a[n-i+1],a[ma[b[i]]]);
            swap(b[n-i+1],b[ma[b[i]]]);
        }else {
            cout << -1 << endl;
            return;
        }
    }
    cout << ans.size() << endl;
    for(auto [x,y]: ans) {
        cout << x << ' ' << y << endl;
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