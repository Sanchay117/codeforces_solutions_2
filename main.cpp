#include <bits/stdc++.h>
#include <climits>
#include <fstream>
#include <future>
#include <numeric>

using namespace std;

#define ll long long
#define lli long long int
#define ulli unsigned long long int
#define ld long double
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vll vector<long long>
#define vlli vector<long long int>
#define pii pair<int,int>
#define plli pair<long long int,long long int>
#define mii map<int,int>
#define mci map<char,int>
#define mic map<int,char>
#define msi map<string,int>
#define mis map<int,string>
#define all(arr) arr.begin(), arr.end()
#define all(arr,n) arr, arr+n
#define fr(i,a,b) for(int i = a; i<b;i++)
#define bug(...) __f (#__VA_ARGS__, __VA_ARGS__)
#define MOD 1000000007LL
#define haan cout << "YES" << endl
#define nahi cout << "NO" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define out(x) cout << x << endl
#define tupiii tuple<int,int,int>
#define billion 10e9
#define printMatrix(arr,n,m) for(int i = 0;i<n;i++){\
        for(int j = 0;j<m;j++){\
            cout << arr[i][j] << " ";\
        }\
        cout << endl;\
    }
#define sort_dec(arr,n) sort(arr,arr+n,greater<>());
#define sort_asc(arr,n) sort(arr,arr+n);
#define printV(vec) for(int i = 0;i<vec.size();i++) cout << vec[i] << " ";\
	cout << endl;
#define MatrixInput(arr,n,m) for(int i = 0;i<n;i++){\
                                for(int j = 0;j<m;j++){\
                                    cin >> arr[i][j] ;\
                                }\
                             }
#define ArrInput(arr,n) for(int i = 0;i<n;i++) cin >> arr[i];

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) ((lli)(x).size())
#define eb emplace_back
#define X first
#define Y second

using u128 = __uint128_t;

// ordered set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

struct DSU {
    vector<int> p, r;
    DSU(int n): p(n), r(n,0) { iota(p.begin(), p.end(), 0); }
    int find(int x){ return p[x]==x? x: p[x]=find(p[x]); }
    bool unite(int a, int b){
        a = find(a); b = find(b);
        if (a==b) return false;
        if (r[a] < r[b]) swap(a,b);
        p[b]=a; if (r[a]==r[b]) r[a]++;
        return true;
    }
};

ulli mul_mod(ulli a, ulli b, ulli mod){
    return (u128) a * b % mod;
}
ulli pow_mod(ulli a, ulli d, ulli mod){
    ulli r = 1;
    while(d){
        if(d & 1) r = mul_mod(r, a, mod);
        a = mul_mod(a, a, mod);
        d >>= 1;
    }
    return r;
}

bool isPrime64(ulli n){
    if(n < 2) return false;
    for(ulli p : {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL}){
        if(n % p == 0) return n == p;
    }
    ulli d = n - 1, s = 0;
    while((d & 1) == 0){ d >>= 1; ++s; }
    ulli bases[] = {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL};
    for(ulli a : bases){
        if(a % n == 0) continue;
        ulli x = pow_mod(a % n, d, n);
        if(x == 1 || x == n-1) continue;
        bool comp = true;
        for(ulli r = 1; r < s; ++r){
            x = mul_mod(x, x, n);
            if(x == n-1){ comp = false; break; }
        }
        if(comp) return false;
    }
    return true;
}

lli modinv(lli x){
    lli a = x, m = MOD;
    lli res = 1, pw = m-2;
    lli base = (a % m + m) % m;
    while(pw){
        if(pw & 1) res = (res * base) % m;
        base = (base * base) % m;
        pw >>= 1;
    }
    return res;
}

const int MAXN = 10000000;  // Set the maximum value of n as 10 million
std::vector<bool> primes(MAXN + 1, true);  // Create a bool vector of size 10,000,001

void SieveOfEratosthenes() {
    for (int p = 2; p * p <= MAXN; p++) {  // Iterate up to sqrt(MAXN)
        if (primes[p]) {  // Check if p is a prime number
            for (int i = p * p; i <= MAXN; i += p)  // Mark all multiples of p as false
                primes[i] = false;
        }
    }
}

void solve(int tt) {

    int n,m;cin >> n >> m;
    vi swords(n);ArrInput(swords,n);
    vector<pii> monsters; // <m_i, c_i>

    fr(i,0,m) {
        int x; cin >> x;
        monsters.push_back({x,0});
    }

    fr(i,0,m) {
        int c;cin >> c;
        monsters[i].S = c;
    }

    int sword = *max_element(all(swords));
    sort(all(swords));

    sort(monsters.begin(), monsters.end(), [](pii a,pii b) {
        if (a.F < b.F) return true;
        else return false;
    });

    int ans = 0;
    vector<pii> remaining_monsters;
    for (auto x:monsters) {
        if (x.F<=sword && x.S>0) {
            ans++;
            sword = max(sword,x.S);
        } else if (x.S==0 && x.F<=sword) {remaining_monsters.push_back(x);}
    }

    if (remaining_monsters.size()==0) {
        out(ans);
        return;
    }

    // bug(ans);

    int l = 0, r = max((size_t)0,remaining_monsters.size() - 1);

    ans++;
    r--;
    // bug(ans,1);

    for (int i = n-2;i>=0;i--) {
        int sword = swords[i];

        int lo = l, hi = r;
        if (lo == hi) {
            if (sword>=remaining_monsters[lo].F) {
                ans++;
                break;
            }else {
                break;
            }
        }
        int mid = -1;
        while (lo <= hi) {
            int m = (lo + hi) / 2;
            if (remaining_monsters[m].F>sword) {
                hi = m-1;
            }else {
                mid = m;
                lo = m+1;
            }
        }
        if (mid==-1)break;

        ans ++;
        // bug(ans,i,mid,lo,hi);
        r=mid-1;

    }

    out(ans);

}

int32_t main() {

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    cin >> t;
    int i = 1;

    while (t--) {
        solve(i);
        i++;
    }

    return 0;
}