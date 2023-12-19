// Problem: B. Swap and Delete
// Contest: Codeforces - Educational Codeforces Round 160 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1913/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms

// #pragma GCC optimize(3,"Ofast","inline")
// #pragma GCC optimize(2)
#include <bits/stdc++.h>
/*#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <queue>*/
#define cios ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
#define i128 __int128_t
#define endl '\n'
#define ls (p<<1)
#define rs (p<<1|1)
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 200005, M = 200005, INF = 0x3f3f3f3f, LINF = 0x3f3f3f3f3f3f3f3f;
const ll P = /*1e9 + 7*/ 998244353;
ll pow(ll a, ll b, ll mod){ll res=1;while(b>0){a=a%mod;if(b&1)res=res*a%mod;b=b>>1;a=a*a%mod;}return res;}
ll pow(ll a, ll b){ll res=1;while(b>0){if(b&1)res=res*a;b=b>>1;a=a*a;}return res;}
ll inv(ll x){return pow(x,P-2,P);}
ll gcd(ll x,ll y){if(!y)return 0;while(y^=x^=y^=x%=y);return x;}
ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
void init(){
	
}
void solve(){
	string s;
	cin >> s;
	int l=s.size();
	int ans=l;
	int p=0;
	int a[2]={0};
	for(int i=0;i<l;i++){
		a[s[i]-'0']++;
	}
	for(int i=0;i<l;i++){
		if (a[1-(s[i]-'0')]>0){
            ans--;
            a[1-(s[i]-'0')]--;
        }else {
            break;
        }
	}
	cout << ans <<endl;
    return;
}
signed main(){
    cios
    //cout << fixed << setprecision(6);
    init();
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    while (t--)
        solve();
    return 0;
}