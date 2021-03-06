#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>
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
#define pvi(x, v) if (v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if (v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

// #define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
// template <typename T>
// void _f(const char* name, T&& arg) {
//   cout << fixed << name << ": " << arg << '\n';
// }

// template <typename T, typename... Args>
// void _f(const char* names, T&& arg, Args&&... args) {
//   const char* split = strchr(names + 1, ',');
//   cout.write(names, split - names) << ": " << arg << " |";
//   _f(split, args...);
// }

// double tick() {
//   static clock_t old;
//   clock_t now = clock();
//   double diff = 1.0 * (now - old);
//   diff /= CLOCKS_PER_SEC;
//   old = now;
//   return diff;
// }

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int maxn = 1004;
const int inf = 0x3f3f3f3f;
int edges[maxn][maxn];
int n, m, x;
int dist[maxn], distx[maxn];

void dijkstra(int src) {

  priority_queue<pii, vpii, greater<pii> > dq;

  mst(dist, 0x3f);
  dq.push({0, src});
  dist[src] = 0;

  while (sz(dq)) {
    int u = dq.top().second; dq.pop();
    fori (i, 1, n + 1) {
      int w = edges[u][i];
      if (w != inf && dist[i] > dist[u] + w) {
        dist[i] = dist[u] + w;
        dq.push({dist[i], i});
      }
    }
  }

}

void solve() {
  mst(edges, 0x3f);
  cin >> n >> m >> x;
  fori (i, 1, m + 1) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u][v] = min(edges[u][v], w);
  }

  // fori (i, 1, n + 1) {
  //   par(edges[i], n + 1, 1);
  // }

  // Shortest distance from x to all others nodes.
  dijkstra(x);

  fori (i, 1, n + 1) {
    distx[i] = dist[i];
  }

  // par(distx, n + 1, 1);

  fori (i, 1, n + 1) {
    fori (j, i + 1, n + 1) {
      swap(edges[i][j], edges[j][i]);
    }
  }

  dijkstra(x);

  // par(dist, n + 1, 1);

  int ret = 0;
  fori (i, 1, n + 1) {
    if (i != x) {
      ret = max(dist[i] + distx[i], ret);
    }
  }

  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  solve();
  return 0;
}
