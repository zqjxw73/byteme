#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define pend cout << '\n'
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define output(v) cout << (v) << '\n'
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if(v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << '\n';
}

template <typename T, typename... Args>
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ',');
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...);
}

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

#define maxn 1010
char aa[maxn][maxn];

int main() {
  int n; cin >> n >> ws;
  fori (i, 0, n) 
    fori (j, 0, n) 
      aa[i][j] = '.';

  int ret = 0;
  fori (i, 0, n) {
    if (i % 2 == 0)
      for (int j = 0; j < n; j += 2) {
        aa[i][j] = 'C';
        ++ret;
      }
    else 
      for (int j = 1; j < n; j += 2) {
        aa[i][j] = 'C';
        ++ret;
      }
  }  
  
  output(ret); 
  fori (i, 0, n) {
    fori (j, 0, n)
      cout << aa[i][j];
    cout << '\n';
  } 

  return 0;
}

