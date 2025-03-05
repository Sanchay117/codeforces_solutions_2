//
// Created by bravefart69 on 5/3/25.
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
#define all(arr) arr.begin(), arr.end()
#define all(arr,n) arr, arr+n
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

void solve(int tt) {

    int n;cin >> n;
    string s;cin >> s;

    vi ans (n,0);
    stack<pair<char,int>> stacky_boi;


    string t = s;
    stack<char> ss;
    int cnt = 0;

    fr(i,0,n) {
        if(s[i]=='(') {
            if(ss.empty()) continue;
            ss.pop();
            cnt++;
        }
        else {
            ss.push(')');
            cnt++;
        }
    }

    if(!ss.empty()) cnt = -1;

    if(cnt == n) {
        out(1);
        fr(i,0,n) {
            cout << 1 << " ";
        }
        cout << endl;
        return;
    }

    bool diff = false;

    fr(i,0,n) {
        if(s[i]==')' && stacky_boi.empty()) continue;
        if(s[i]==')') {
            stacky_boi.pop();
            // bug("POP");
            ans[i] = 1;
            s[i]='-';
            diff = true;
        }
        else {
            stacky_boi.push({'(',i});
            // bug("PUSH");
            ans[i] = 1;
            s[i] = '-';
        }
    }

    while(!stacky_boi.empty()) {
        auto [c,i] = stacky_boi.top();
        stacky_boi.pop();
        s[i] = c;
        ans[i] = 0;
    }

    bool valid = true;

    fr(i,0,n) {
        if(s[i]=='-') continue;
        if(s[i]=='(') {
            if(stacky_boi.empty()) {
                valid = false;
                break;
            }
            stacky_boi.pop();
            ans[i] = 2;
            s[i]='-';
        }
        else {
            stacky_boi.push({')',i});
            ans[i] = 2;
            s[i] = '-';
        }
    }

    if(!valid) {
        out(-1);
        return;
    }

    if(!stacky_boi.empty()) {
        out(-1);
        return;
    }

    if(!diff) {
        for(auto &x:ans) {
            if(x==2) x = 1;
        }
    }

    bool two = false;
    for(int x:ans) {
        if (x==2) two = true;
    }

    if(two) {
        out(2);
    }else out(1);

    printV(ans);

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