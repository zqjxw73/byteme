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
typedef unsigned int uint;


uint hash_str(string& ss) {
  uint h = 1315423911;
  fori (i, 0, sz(ss)) {
    h ^= ((h << 5) + ss[i] + (h >> 2));
  }
  return (h & 0x7FFFFFFF);
}

unordered_map<uint, uint> mp;


int main() {
  int n; cin >> n >> ws;
  fori (i, 1, n + 1) {
    string a; cin >> a;
    uint hs = hash_str(a);
    if (!mp.count(hs)) {
      output("OK"); 
      mp[hs] = 0;
    } else {
      int cnt = mp[hs] + 1;
      mp[hs] = cnt;
      string na = a + to_string(cnt);
      output(na);
    }
  } 

  return 0;
}
