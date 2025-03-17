//
// Created by bravefart69 on 17/3/25.
//
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--){
		int n, m;
		scanf("%d%d", &n, &m);
		vector<int> a(m);
		forn(i, m){
			scanf("%d", &a[i]);
			--a[i];
		}
		vector<int> cnt(n);
		forn(i, m) ++cnt[a[i]];
		auto check = [&](int t){
			long long fr = 0, need = 0;
			forn(i, n){
				if (t >= cnt[i])
					fr += (t - cnt[i]) / 2;
				else
					need += cnt[i] - t;
			}
			return need <= fr;
		};
		int l = 0, r = 2 * m;
		int res = -1;
		while (l <= r){
			int m = (l + r) / 2;
			if (check(m)){
				res = m;
				r = m - 1;
			}
			else{
				l = m + 1;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}