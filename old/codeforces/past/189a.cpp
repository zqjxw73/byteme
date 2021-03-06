#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define output(val) cout << (val) << endl
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define pvi(x) fora(a, x) cout << a << " "; cout << endl
#define par(x, n) fori(a, 0, n) cout << x[a] << " "; cout << endl
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (val) << endl

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
}

template <typename T, typename... Args>
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ',');
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...);
}

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int maxn = 5000;
int n, a, b, c;
int dp[maxn];
int solve(int inp) {
  if (inp == 0) return 0;
  if (inp < 0) return -maxn;
  if (dp[inp] != -1) return dp[inp];
  int x = solve(inp - a) + 1;
  int y = solve(inp - b) + 1;
  int z = solve(inp - c) + 1;
  // trace(inp, x, y, z);
  dp[inp] = max(x, max(y, z));
  return dp[inp];
}

int main() {
  cin >> n >> a >> b >> c;
  mst(dp, -1);
  int ret = solve(n);
  output(ret);

  return 0;
}
