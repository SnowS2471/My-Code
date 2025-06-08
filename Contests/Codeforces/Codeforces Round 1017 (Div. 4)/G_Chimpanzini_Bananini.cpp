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
    deque<int> q;
    int sum=0,ans=0,rs=0,ra=0;
    bool re=0;
    while(n--) {
        int op,x;
        cin >> op;
        if(op==3) {
            cin >> x;
            if(!re) {
                q.push_back(x);
                ans+=x*q.size();
                ra+=sum+x;
                sum+=x;
                cout << ans << endl;
            }else{
                q.push_front(x);
                ra+=x*q.size();
                ans+=sum+x;
                sum+=x;
                cout << ra << endl;
            }
        }else if(op==1) {
            if(!re) {
                x=q.back();
                q.pop_back();
                q.push_front(x);
                ans+=sum-x-x*(q.size()-1);
                ra+=x*(q.size()-1)-sum+x;
                cout << ans << endl;
            }else{
                x=q.front();
                q.pop_front();
                q.push_back(x);
                ra+=sum-x-x*(q.size()-1);
                ans+=x*(q.size()-1)-sum+x;
                cout << ra << endl;
            }
        }else {
            re=!re;
            if(re) cout << ra << endl;
            else cout << ans << endl;
        }
        // cout << "ra: " << ra << endl;
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