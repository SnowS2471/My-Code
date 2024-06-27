#include <bits/stdc++.h>
using namespace std;
signed main()
{
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(' || s[i] == ')' || s[i] == ',' || s[i] == '-' || s[i] >= '0' && s[i] <= '9')
			cout << s[i];
	}
	cout << endl;
	return 0;
}