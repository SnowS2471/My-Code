#include <bits/stdc++.h>
#define cios ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
#define endl '\n'
using namespace std;
int dp[101][2];
void solve(){
	int n,k;
	cin >> n >> k;
	for(int i=0;i<=100;i++) dp[i][1]=-1000000;
	for(int i=1,x;i<=n;i++){
		cin >> x;
		for(int j=k;j>=0;j--){
			if(j) dp[j][0]=max(dp[j][0],dp[j-1][1]+x);
			dp[j][1]=max(dp[j][1],dp[j][0]-x); 
			// cout << j << ' ' << dp[j][0] << ' ' << dp[j][1] << endl;
		}
		// cout << endl;
	}
	cout << dp[k][0] << endl;
    return;
}
signed main(){
    cios
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}