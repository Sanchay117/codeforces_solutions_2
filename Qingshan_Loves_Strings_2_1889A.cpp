#include <bits/stdc++.h>
#include <climits>
#include <cmath>
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

struct mint {
    long long v;
    mint(long long _v=0){ v = (_v%MOD+MOD)%MOD; }
    mint operator+(const mint& o) const { return mint((v+o.v)%MOD); }
    mint operator-(const mint& o) const { return mint((v-o.v+MOD)%MOD); }
    mint operator*(const mint& o) const { return mint((v*o.v)%MOD); }
    mint pow(long long e) const {
        mint a = *this, r = 1;
        while(e){ if(e&1) r = r*a; a = a*a; e >>= 1; }
        return r;
    }
    mint inv() const { return pow(MOD-2); }
};

struct Fenwick {
    int n; vector<lli> bit;
    Fenwick(int n=0){ init(n); }
    void init(int n_){ n = n_; bit.assign(n+1,0); }
    void add(int idx, lli val){
        for(; idx<=n; idx+=idx&-idx) bit[idx]+=val;
    }
    lli sum(int idx){
        lli r=0;
        for(; idx>0; idx-=idx&-idx) r+=bit[idx];
        return r;
    }
    lli rangeSum(int l,int r){ return sum(r)-sum(l-1); }
};

struct SegTree {
    int n; vector<lli> st;
    SegTree(int _n=0){ init(_n); }
    void init(int _n){
        n = 1; while(n < _n) n <<= 1;
        st.assign(2*n, 0);
    }
    void setPoint(int p, lli val){ // set index p (0-based)
        p += n; st[p] = val;
        for(p/=2; p; p/=2) st[p] = st[2*p] + st[2*p+1];
    }
    lli query(int l, int r){ // inclusive [l,r], 0-based
        l += n; r += n;
        lli res = 0;
        while(l <= r){
            if(l&1) res += st[l++];
            if(!(r&1)) res += st[r--];
            l/=2; r/=2;
        }
        return res;
    }
};

struct LCA {
    int n, LOG;
    vector<int> depth;
    vector<vector<int>> up;
    LCA(int n=0){ init(n); }
    void init(int _n){
        n = _n; LOG = 1;
        while((1<<LOG) <= n) ++LOG;
        up.assign(LOG, vector<int>(n, -1));
        depth.assign(n, 0);
    }
    void dfs(int u, int p, const vector<vector<int>>& g){
        up[0][u] = p;
        for(int k=1;k<LOG;++k) up[k][u] = up[k-1][u] == -1 ? -1 : up[k-1][ up[k-1][u] ];
        for(int v: g[u]) if(v!=p){
            depth[v] = depth[u]+1;
            dfs(v,u,g);
        }
    }
    int lca(int a, int b){
        if(depth[a] < depth[b]) swap(a,b);
        int diff = depth[a]-depth[b];
        for(int k=0;k<LOG;++k) if(diff & (1<<k)) a = up[k][a];
        if(a==b) return a;
        for(int k=LOG-1;k>=0;--k) if(up[k][a] != up[k][b]) { a = up[k][a]; b = up[k][b]; }
        return up[0][a];
    }
};

vector<lli> dijkstra(int n, int src, const vector<vector<pair<int,int>>>& g){
    const lli INF = (1LL<<62);
    vector<lli> dist(n, INF);
    priority_queue<pair<lli,int>, vector<pair<lli,int>>, greater<>> pq;
    dist[src] = 0; pq.push({0, src});
    while(!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();
        if(d != dist[u]) continue;
        for(auto [v,w] : g[u]){
            if(dist[v] > d + w){
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

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

template<typename T>
T binexp(T a, long long e){
    T res = 1;
    while(e){
        if(e&1) res = res * a;
        a = a * a;
        e >>= 1;
    }
    return res;
}

// 50,847,534 primes upto 1 billion
// 5,761,455 primes upto 100 million
// 664,579 primes upto 10 million
// 78,498 primes upto 1 million
const int MAXN = 10'000'000;  // Set the maximum value of n as 10 million
std::vector<bool> primes(MAXN + 1, true);  // Create a bool vector of size 10,000,001

void SieveOfEratosthenes() {
    for (int p = 2; p * p <= MAXN; p++) {  // Iterate up to sqrt(MAXN)
        if (primes[p]) {  // Check if p is a prime number
            for (int i = p * p; i <= MAXN; i += p)  // Mark all multiples of p as false
                primes[i] = false;
        }
    }
}

bool isInt(double x) {
    return isfinite(x) && floor(x) == x;
}

lli factorial_modular(lli x, lli mod) {
    lli res = 1;

    for (int i = 1; i <= x; i++) {
        res = (res * i) % mod;
    }

    return res;
}

void solve(int tt) {
    int n; string s;
    cin >> n >> s;

    int ones = 0, zeros = 0;
    for (char c : s) (c == '1' ? ones : zeros)++;
    if (ones != zeros) {
        out(-1);
        return;
    }

    vi ops;
    int l = 0;
    while (l < s.size() - 1 - l) {
        int r = s.size() - 1 - l;
        if (s[l] != s[r]) {
            l++;
            continue;
        }

        if (s[l] == '0') {
            s.insert(s.begin() + (r + 1), {'0','1'});
            ops.push_back(r + 1);
            l++;
        } else {
            s.insert(s.begin() + l, {'0','1'});
            ops.push_back(l);
        }
        if (ops.size() > 300) break;
    }

    if (ops.size() > 300) {
        out(-1);
    } else {
        out(ops.size());
        printV(ops);
    }
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