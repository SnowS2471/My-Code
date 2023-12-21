// Problem: E. Number With The Given Amount Of Divisors
// Contest: Codeforces - Codeforces Beta Round 27 (Codeforces format, Div. 2)
// URL: https://codeforces.com/contest/27/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
int ans=1e18;
int n;
int primes[N], cnt;
bool vis[N];
inline void get_prime(){
	for(register int i=2;i<=60;i++) {
		if(!vis[i]) primes[++cnt] = i;
		for(register int j = 1;j<=cnt && i * primes[j]<=1e18;++j) {
			vis[i * primes[j]] = 1;
	        if(i % primes[j]==0) break;
	   	}
   	}
} 
int ct[N];
void dfs(int s,int now,int p,int pre){
	if(s>n || ct[p]>ct[p-1] || now > 1e18) return;
	else if(s==n) {
		ans=min(ans,now);
		return;
	}
	ct[p]++;
	dfs(s+pre,now*primes[p],p,pre);
	ct[p]--;
	dfs(s*2,now*primes[p+1],p+1,s);
}
void solve(){
	cin >> n;
	get_prime();
	ct[0]=10000;
	dfs(1,1,1,1);
	cout << ans;
    return;
}
signed main(){
    cios
    //cout << fixed << setprecision(6);
    init();
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
