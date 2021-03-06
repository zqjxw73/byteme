#include<bits/stdc++.h>
using namespace std;

bool check(vi& sides) {
  int a, b, c, d;
  a = sides[0];
  b = sides[1];
  c = sides[2];
  d = sides[3];
  if (abs(d-c) < abs(b-a) && abs(b-a) < c+d && c == d) {
    return 1; 
  }
  // trace(a, b, c, d);
  return 0;
}

vi inp;
vvi sides;
vi path;
vi side;
int visit[4];

void build(vi& inp, int ix) {
  if (ix == 4) {
    sides.pb(path);
    return;
  }

  fori (i, 0, 4) {
    if (visit[i]) continue;
    visit[i] = 1;
    path[ix] = inp[i];
    build(inp, ix + 1);
    visit[i] = 0;
  }

}

// TODO: runs pretty slow, only works for small data.
int solve() {
  int n = sz(inp);
  int res = 0;
  fori (i, 0, n) {
    fori (j, i + 1, n) {
      fori (k, j + 1, n) {
        fori (h, k + 1, n) {
          side.clear();
          side.pb(inp[i]); 
          side.pb(inp[j]);
          side.pb(inp[k]);
          side.pb(inp[h]);
          
          // pvi(side); 
          sides.clear();
          path.resize(4, 0);
          mst(visit, 0);
          build(side, 0); 

          int ok = 0;
          fora (a, sides) {
            if (check(a)) { ok = 1; break; }
          }
          
          if (ok) ++res;
        }
      }
    } 
  }
  return res;
}

int main() {
 
  int t; cin >> t;
  fori (i, 1, t + 1) {
    inp.clear();
    int n; cin >> n;
    fori (i, 0, n) {
      int a; cin >> a;
      inp.pb(a);
    }
    int r = solve();
    output(i, r);
  }

  return 0;
}
