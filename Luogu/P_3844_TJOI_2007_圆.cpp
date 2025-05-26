#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
const int N = 105, M = 100005;
const int mod = /* 1e9 + 7 */ 998244353;
const double PI = acos(-1);

void init() {

}

struct yyy {
    int x, y, r;
    bool operator < (const yyy &b) const {
        return r > b.r;
    }
} a[N];

double dis(int x1, int y1, int x2, int y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void solve() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> a[i].x >> a[i].y >> a[i].r;
    }
    sort(a+1,a+1+n);
    double ans=0;
    for(int i=1;i<=n;i++) {
        int cnt = 0;
        for(int j=1;j<i;j++) {
            if(dis(a[i].x,a[i].y,a[j].x,a[j].y) < a[j].r) {
                cnt++;
            }
        }
        if(cnt&1) {
            ans -= PI * a[i].r * a[i].r;
        } else {
            ans += PI * a[i].r * a[i].r;
        }
    }
    cout << fixed << setprecision(2) << ans << endl;
}
signed main() {
    cios
    init();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}