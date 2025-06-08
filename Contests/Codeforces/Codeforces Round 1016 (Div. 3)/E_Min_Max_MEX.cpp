#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 200005, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;
void init() {

}
int a[N];
int n,k;
bool check(int x) {
    int res=0;
    set<int> s;
    for(int i=1;i<=n;i++) {
        if(a[i]<x) s.insert(a[i]);
        if(s.size()==x){
            s.clear();
            res++;
        } 
    }
    return res>=k;
}
void solve() {
    cin >> n >> k;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    int l=1,r=2e5+10;
    while(l<=r) {
        int m=l+r>>1;
        if(check(m)) l=m+1;
        else r=m-1;
    }
    cout << r << endl;
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