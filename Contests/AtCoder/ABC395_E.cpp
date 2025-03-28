// Problem: E - Flip Edge
// Contest: AtCoder - AtCoder Beginner Contest 395
// URL: https://atcoder.jp/contests/abc395/tasks/abc395_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms


#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
#define i128 __int128_t
#define endl '\n'
using namespace std;
const int N = 200005, M = 200005;
const int P = /*1e9 + 7*/ 998244353;
void init(){
	
}
vector<int> g[2][N];
int dis[2][N],f[2][N];
void solve(){
	int n,m,x;
	cin >> n >> m >> x;
	for(int i=1,u,v;i<=m;i++){
		cin >> u >> v;
		g[0][u].push_back(v);
		g[1][v].push_back(u);
	}
	memset(dis,63,sizeof dis);
	priority_queue<array<int,3>,vector<array<int,3> >,greater<> > q;
	q.push({0,0,1});
	dis[0][1]=0;
	f[0][1]=1;
	while(q.size()){
		auto [a,b,c]=q.top();
		q.pop();
		if(f[b][c]) continue;
		for(int t:g[b][c]){
			if(!f[b][t]){
				dis[b][t]=min(dis[b][t],a+1);
				q.push({a+1,b,t});
			}
		}
		if(!f[b^1][c]){
			dis[b^1][c]=min(dis[b^1][c],a+x);
			q.push({a+x,b^1,c});
		}
	}
	cout << min(dis[0][n],dis[1][n]);
    return;
}
signed main(){
    cios
    init();
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}