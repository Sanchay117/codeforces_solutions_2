//
// Created by bravefart69 on 23/1/25.
//
#include <bits/stdc++.h>
#include <climits>
#include <fstream>
#include <future>
#include <numeric>

using namespace std;

#define ll long long
#define lli long long int
#define ld long double
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define mii map<int,int>
#define mci map<char,int>
#define mic map<int,char>
#define msi map<string,int>
#define mis map<int,string>
#define fr(i,a,b) for(int i = a; i<b;i++)
#define bug(...) __f (#__VA_ARGS__, __VA_ARGS__)
#define MOD 1000000007
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

// ordered set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;


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

void dfs(int u, vector<int> G[], vector<bool> &visited, vector<int> &reachable) {
    visited[u] = true;
    reachable.push_back(u);

    for (int neighbor : G[u]) {
        if (!visited[neighbor]) {
            dfs(neighbor, G, visited, reachable);
        }
    }
}

vector<int> getReachableVertices(int u, vector<int> G[], int m1) {
    vector<bool> visited(m1 + 1, false);
    vector<int> reachable;
    dfs(u, G, visited, reachable);
    return reachable;
}

void solve(int tt) {

    lli n,l,r;cin >> n >> l >> r;

    lli arr[n];ArrInput(arr,n);

    lli len = r-l+1;

    vector<pii> list;
    fr(i,0,n) {
        list.emplace_back(arr[i],i);
    }

    sort(list.begin(),list.end(),[](pii a,pii b) {
        return a.F<b.F;
    });

    lli leftSum = 0,rightSum = 0;
    lli leftLen=0,rightLen = 0;

    int cnt = 0;
    fr(i,0,n) {
        if(cnt == len) break;
        if(list[i].S<=r-1) {
            cnt++;
            leftSum+=list[i].F;
        }
    }
    leftLen = cnt;

    cnt = 0;
    fr(i,0,n) {
        if(cnt == len) break;
        if(list[i].S>=l-1) {
            cnt++;
            rightSum+=list[i].F;
        }
    }
    rightLen = cnt;

    vector<lli> seg;
    for(int i = l-1;i<r;i++) {
        seg.push_back(arr[i]);
    }

    sort(seg.begin(),seg.end());

    if(leftLen<len) {
        for(int i = 0;i<len-leftLen;i++) {
            leftSum+=seg[i];
        }
    }

    if(rightLen<len) {
        for(int i = 0;i<len-rightLen;i++) {
            rightSum+=seg[i];
        }
    }

    out(min(leftSum,rightSum));
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