#include <bits/stdc++.h>
 
#define int         long long int
#define si          set<int>
 
using namespace std;
 
void solve()
{
    int n;
    cin >> n;
    si s;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << endl;  
}
 
int32_t main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int tt = 1;
// 	cin >> tt;
	while(tt--)
	{
	    solve();
	}
	return 0;
}
