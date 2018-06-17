#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <string>
#include <cstdio>
#include <random>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)
#define fora(e, c) for (auto &e : c)
#define all(x) (x).begin(), (x).end()
#define len(x) strlen(x)
#define vi vector<int>
#define vs vector<string>
#define sz(x) ((int)(x).size())
#define pii pair<int, int>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf pop_front
#define ppb pop_back
#define pvi(x) fora(r, x) cout << r << ' '; cout << '\n'
#define cerr(x) cerr << #x " is " << (x) << endl
#define prt(x, n) fori(i, 0, n) cout << x[i] << " "; cout << "\n"
#define prt2(x, n, m) fori(i, 0, n) {fori(j, 0, m) cout << x[i][j] << " "; \
        cout << "\n"; } cout << "\n"
#define mst(x, n, v) fori(i, 0, n) x[i] = v
#define mst2(x, n, m, v) fori(i, 0, n) fori(j, 0, m) x[i][j] = v
#define mst3(x, n, m, c, v) \ fori(i, 0, n) \
          fori(j, 0, m) \
            fori(k, 0, c) \
              x[i][j][k] = v
const double eps = 1e-9;
int cmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

// Denotes number of different formations of the first i dice, with the last 
// dice equal to j. 

// Note: number type.
// int dp[40][40];
ll dp[40][40];

class DiceGames
{
public:
  ll countFormations(vi sides) {
    int n = sz(sides);
    memset(dp, 0, sizeof(dp));

    sort(all(sides));

    fori(i, 0, sides[0])
      dp[0][i] = 1;

    fori(i, 1, n) {
      fori(j, 0, sides[i]) {
        fori(k, 0, j+1)
          dp[i][j] += dp[i-1][k];
      }
    }

    ll ret = 0;
    fori(i, 0, sides[n-1])
      ret += dp[n-1][i];
    return ret;
  } 
};

// Expected:
// 916312070471295267

// Received:
// -3626491613

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  DiceGames go;
  cout << go.countFormations({4}) << "\n";
  cout << go.countFormations({2, 2}) << "\n";
  cout << go.countFormations({4, 4}) << "\n";
  cout << go.countFormations({3, 4}) << "\n";
  cout << go.countFormations({4, 5, 6}) << "\n";
  vi a = {32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 
          32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32};
  cout << go.countFormations(a) << "\n";
  return 0;
}
