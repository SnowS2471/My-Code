#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
#define i128 __int128_t
#define endl '\n'
using namespace std;
const int N = 55, M = 200005;
const int P = /*1e9 + 7*/ 998244353;
void init(){
	
}
int g[N][N];
bool f[N][N];
void solve(){
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin >> g[i][j];
	}
	queue<pair<int,int> > q;
	int ans1=0,ans2=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!f[i][j]){
				ans1++;
				int res=0;
				q.push({i,j});
				f[i][j]=1;
				while(q.size()){
					res++;
					auto [a,b]=q.front();
					q.pop();
					if(!((g[a][b])&1) && !f[a][b-1] && b-1>0) q.push({a,b-1}),f[a][b-1]=1;
					if(!((g[a][b]>>1)&1) && !f[a-1][b] && a-1>0) q.push({a-1,b}),f[a-1][b]=1;
					if(!((g[a][b]>>2)&1) && !f[a][b+1] && b+1<=m) q.push({a,b+1}),f[a][b+1]=1;
					if(!((g[a][b]>>3)&1) && !f[a+1][b] && a+1<=n) q.push({a+1,b}),f[a+1][b]=1;
				}
				ans2=max(ans2,res);
			}
		}
	}
	cout << ans1 << endl << ans2 << endl;
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