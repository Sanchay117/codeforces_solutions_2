#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define no "No\n"
#define yes "Yes\n"
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define allin(s, n, vec) for (ll i = s; i < n; i++) cin >> vec[i]
ll const MOD = 1e9 + 7;
ll const INF = 1e18;
using namespace std;

void solve()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m), c(m);
    allin(0, n, a);
    allin(0, m, b);
    allin(0, m, c);

    multiset<ll> st(all(a));
    vector<pair<ll, ll>> good;
    vector<ll> normal;

    for (int i = 0; i < m; i++)
    {
        if (c[i] > 0)
            good.push_back({b[i], c[i]});
        else
            normal.push_back(b[i]);
    }

    sort(all(good));
    sort(all(normal));
    ll cnt = 0;

    auto work = [&](ll need, ll upgrade)
    {
        auto it = st.lower_bound(need);
        if (it == st.end())
            return false;

        ll cur = *it;
        st.erase(it);

        if (upgrade > 0)
            st.insert(max(cur, upgrade));

        return true;
    };

    for (auto &[health, bonus] : good)
        if (work(health, bonus))
            cnt++;

    for (auto &ele : normal)
        if (work(ele, 0))
            cnt++;

    cout << cnt << nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ll tc = 1;
    cin >> tc;

    while(tc--)
        solve();

    return 0;
}