#include <bits/stdc++.h>

#define int         long long int 
#define pb          push_back
#define si          set<int>
#define vi          vector<int>
#define pii         pair<int, int>
#define vpi         vector<pii>
#define mii         map<int, int>
#define all(p)      p.begin(),p.end()
#define print(a)    for(auto x: a) cout << x << "\n";
#define nmod        1000000007
#define loop0(n)        for(int i=0; i<n; i++)
#define mvinp(a, n, mp) for(int paris=0; paris<n; paris++) { cin >> a[paris]; mp[a[paris]]++;}
#define vinp(a, n)      for(int london=0; london<n; london++) cin>>a[london];
int m_expo(int x, int y) { int res = 1; while (y) {if (y % 2) res = (res * x % nmod) % nmod; x = (x * x) % nmod; y /= 2; } return res;}
int m_inv(int x)         {return m_expo(x, nmod - 2);}
int m_add(int a, int b)  {a = a % nmod; b = b % nmod; return (((a + b) % nmod) + nmod) % nmod;}
int m_sub(int a, int b)  {a = a % nmod; b = b % nmod; return (((a - b) % nmod) + nmod) % nmod;}
int m_mul(int a, int b)  {a = a % nmod; b = b % nmod; return (((a * b) % nmod) + nmod) % nmod;}
int m_div(int a, int b)  {a = a % nmod; b = b % nmod; return (m_mul(a, m_inv(b)) + nmod) % nmod;}
int fact(int n)          {int res = 1; for(int i=1; i<=n; i++) { res = m_mul(res, i); } return res; }
int nCr(int n, int r)    {int res = 1; for(int i=0; i<r; i++) { res = m_mul(res, (n-i)); res = m_div(res, (i+1)); } return res;}
int nPr(int n, int r)    { return fact(n)/fact(n-r); }

using namespace std;

vector<string> help(int n) {
	if(n==1) {
		return {"0", "1"};
	}
	vector<string> res;
	vector<string> temp = help(n-1);
	int s = temp.size();
	for(int i=0; i<s; i++) {
		res.push_back('0'+temp[i]);
	}
	for(int i=s-1; i>=0; i--) {
		res.push_back('1'+temp[i]);
	}
	return res;
}

void solve()
{
	int n;
	cin >> n;
	vector<string> res = help(n);
	print(res);
}

int32_t main() {
	// your code goes here
	#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int tt = 1;
	// cin >> tt;
	while(tt--)
	{
	    solve();
	}
	return 0;
}