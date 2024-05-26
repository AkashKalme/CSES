#include <bits/stdc++.h>

#define int         long long int 
#define pb          push_back
#define si          set<int>
#define vi          vector<int>
#define pii         pair<int, int>
#define vpi         vector<pii>
#define mii         map<int, int>
#define all(p)      p.begin(),p.end()
#define print(a)    for(auto x: a) cout << x << " "; cout << endl;
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

vector<int> delrow = {0, 1, 0, -1};
vector<int> delcol = {1, 0, -1, 0};

bool isValid(int i, int j, int n, int m)
{
	if(i>=0 && j>=0 && i<n && j<m)
	{
		return true;
	}
	return false;
}

void dfs(int i, int j, vector<vector<char>>&  gr, vector<vector<bool>>& vis, int n, int m)
{
	vis[i][j] = 1;
	for(int k=0; k<4; k++)
	{
		int nr = i + delrow[k];
		int nc = j + delcol[k];
		if(isValid(nr, nc, n, m) && gr[nr][nc]=='.' && !vis[nr][nc])
			dfs(nr, nc, gr, vis, n, m);
	}
}

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<char>> mat(n, vector<char>(m, '*'));
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin >> mat[i][j];
		}
	}
	int res = 0;
	vector<vector<bool>> vis(n, vector<bool>(m, 0));
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{	
			if(mat[i][j]=='.' && !vis[i][j])
			{
				res++;
				dfs(i, j, mat, vis, n, m);
			}
		}
	}
	cout << res << "\n";
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