#include <bits/stdc++.h>
using namespace std;

const int MOD = 1'000'000'007;
const int MAXN = 40000;

bool is_pal(int x) {
  string s = to_string(x);
  string t = s;
  reverse(t.begin(), t.end());
  return s == t;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  vector<int> ns(t);
  int maxN = 0;
  for (int i = 0; i < t; i++) {
    cin >> ns[i];
    maxN = max(maxN, ns[i]);
  }

  vector<int> pals;
  for (int i = 1; i <= maxN; i++) {
    if (is_pal(i)) pals.push_back(i);
  }

  vector<int> dp(maxN + 1);
  dp[0] = 1;

  for (int p : pals) {
    for (int s = p; s <= maxN; s++) {
      dp[s] += dp[s - p];
      if (dp[s] >= MOD) dp[s] -= MOD;
    }
  }

  for (int i = 0; i < t; i++) {
    cout << dp[ns[i]] << '\n';
  }

  return 0;
}
