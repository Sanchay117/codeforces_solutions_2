#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define INF(t) numeric_limits<t>::max()

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tc; cin >> tc;
  while(tc--) {
    int n; cin >> n;
    vector<int> d(n);
    for(auto &x : d) cin >> x;
    vector<pair<int, int>> rng(n), valid_rng(n);
    for(auto &[x, y] : rng) cin >> x >> y;

    int l = 0, r = 0;
    bool pos = true;
    for(int i = 0; i < n; i++) {
      if(d[i] == 1) { l++; r++; }
      if(d[i] == -1) { r++; }

      int nl = max(l, rng[i].first);
      int nr = min(r, rng[i].second);

      if(nl > nr) {
        pos = false; break;
      }
      l = nl, r = nr;
      valid_rng[i] = {l, r};
    }

    if(!pos) {
      cout << "-1\n";
      continue;
    }

    deque<int> ans;
    int poss = valid_rng[n-1].second;
    for(int i = n-1; i > 0; i--) {
      if(d[i] != -1) {
        ans.push_front(d[i]);
        if(d[i]) poss--;
        continue;
      }

      if(poss <= valid_rng[i-1].second) ans.push_front(0);
      else {ans.push_front(1); poss--;}
    }
    if(d[0] != -1) {
      ans.push_front(d[0]);
    }
    else {
      if(poss <= 0) ans.push_front(0);
      else ans.push_front(1);
    }

    for(auto &x : ans) cout << x << " ";
    cout << "\n";

  }

  return 0;
}