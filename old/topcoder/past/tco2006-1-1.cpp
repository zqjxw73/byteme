#include<bits/stdc++.h>
using namespace std;

class SeparateConnections {
public:
  int dp[1<<18];
  int howMany(vs mat) {
    int n = sz(mat);
    int n2 = 1 << n;
    mst(dp, 0);
    dp[0] = 0;
    fori (i, 1, n2) {
      vi rm = rmo(i);
      int lowest = rm[0], idx = rm[1];
      // cout << lowest << " " << idx << "\n";
      // Case 1: The lowest node is not communicate at all
      dp[i] = dp[i ^ lowest];
      // Case 2: The lowest node is communicating with some nodes
      fori (k, idx + 1, n) {
        if ((i & (1 << k)) && mat[idx][k] == 'Y' )
          dp[i] = max(dp[i], dp[i ^ lowest ^ (1 << k)] + 2);
      }
    }
    return dp[n2 - 1];
  }
};

void test(vs aa) {
  SeparateConnections go;
  auto r = go.howMany(aa);
  output(r);
}

int main() {
  test({"NYYYY", "YNNNN", "YNNNN", "YNNNN", "YNNNN"});
  return 0;
}
