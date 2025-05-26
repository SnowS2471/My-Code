#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 200005, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;

void init() {

}

int a[N<<1];
void solve() {
    int n;
    cin >> n;
    int sum=0;
    for(int i=1;i<=2*n;i++) {
        cin >> a[i];
        sum+=a[i];
    }
    priority_queue<int> q;
    int resum=0;
    for(int i=1;i<=2*n;i++) {
        if(q.size()<i/2) {
            q.push(a[i]);
            resum+=a[i];
        } else {
            if(q.size() && q.top()>a[i]) {
                resum+=a[i]-q.top();
                q.pop();
                q.push(a[i]);
            }
        }
    }
    // cout << sum << endl << resum << endl;
    cout << sum - resum << endl;
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