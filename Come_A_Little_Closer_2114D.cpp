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

bool in(int a,initializer_list<int> arr) {
    for(int x : arr) if(x==a) return true;
    return false;
}

void solve(int tt) {

    int n;cin >> n;
    map<pii,int> mp;

    vector<pii> points;

    fr(i,0,n) {
        int x,y;cin >> x >> y;
        mp[{x,y}] = 1;
        points.pb({x,y});
    }

    if (n<3) {
        out(n);return;
    }

    sort(all(points));

    pii upper_left = points[0];
    pii bottom_right = points.back();

    pii LEFT = {INT_MAX,INT_MAX}, RIGHT ={INT_MIN,INT_MIN};
    fr(i,1,n) {
        pii p = points[i];
        if (p.S < LEFT.S) LEFT = p;
        if (p.S > RIGHT.S) RIGHT = p;
    }

    lli ans = LLONG_MAX;

    // moving upper_left
    mp[upper_left] = 0;

    int up = INT_MAX, left = INT_MAX;
    int down = INT_MIN, right = INT_MIN;
    bool emptySpace = false;
    fr(i,1,n) {
        up = min(up,points[i].F);
        left = min(left,points[i].S);
        right = max(right,points[i].S);
        down = max(down,points[i].F);
    }

    fr(j,left,right+1) {
        fr(i,up,down+1) {
            if (mp[{i,j}]==0) {
                emptySpace = true;
                break;
            }
        }
        if (emptySpace) break;
    }

    if (emptySpace) ans = min(ans,(lli)(right-left+1)*(down-up+1));
    else {
        ans = min(ans,(lli)(right+1-left)*(down+2-up));
        ans = min(ans,(lli)(right+2-left)*(down+1-up));
    }
    mp[upper_left] = 1;

    // cout << "--------------UPPER_LEFT_MOVE-----------------" << endl;
    // bug(up,down,left,right);
    // bug(emptySpace,ans);

    // moving LEFT
    mp[LEFT] = 0;
    up = INT_MAX, left = INT_MAX, down = INT_MIN, right = INT_MIN;
    emptySpace = false;
    fr(i,0,n) {
        if (points[i] == LEFT) continue;
        up = min(up,points[i].F);
        left = min(left,points[i].S);
        right = max(right,points[i].S);
        down = max(down,points[i].F);
    }

    fr(j,left,right+1) {
        fr(i,up,down+1) {
            if (mp[{i,j}]==0) {
                emptySpace = true;
                break;
            }
        }
        if (emptySpace) break;
    }

    if (emptySpace) ans = min(ans,(lli)(right-left+1)*(down-up+1));
    else {
        ans = min(ans,(lli)(right+1-left)*(down+2-up));
        ans = min(ans,(lli)(right+2-left)*(down+1-up));
    }
    mp[LEFT] = 1;
    // cout << "--------------LEFT_MOVE-----------------" << endl;
    // bug(up,down,left,right);
    // bug(emptySpace,ans);
    // bug(LEFT.F,LEFT.S);

    //moving right
    mp[RIGHT] = 0;
    up = INT_MAX, left = INT_MAX, down = INT_MIN, right = INT_MIN;
    emptySpace = false;
    fr(i,0,n) {
        if (points[i] == RIGHT) continue;
        up = min(up,points[i].F);
        left = min(left,points[i].S);
        right = max(right,points[i].S);
        down = max(down,points[i].F);
    }

    fr(j,left,right+1) {
        fr(i,up,down+1) {
            if (mp[{i,j}]==0) {
                emptySpace = true;
                break;
            }
        }
        if (emptySpace) break;
    }

    if (emptySpace) ans = min(ans,(lli)(right-left+1)*(down-up+1));
    else {
        ans = min(ans,(lli)(right+1-left)*(down+2-up));
        ans = min(ans,(lli)(right+2-left)*(down+1-up));
    }
    mp[RIGHT] = 1;
    // cout << "--------------RIGHT_MOVE-----------------" << endl;
    // bug(up,down,left,right);
    // bug(emptySpace,ans);

    // moving bottom_right
    mp[bottom_right] = 0;
    up = INT_MAX, left = INT_MAX, down = INT_MIN, right = INT_MIN;
    emptySpace = false;
    fr(i,0,n-1) {
        up = min(up,points[i].F);
        left = min(left,points[i].S);
        right = max(right,points[i].S);
        down = max(down,points[i].F);
    }

    fr(j,left,right+1) {
        fr(i,up,down+1) {
            if (mp[{i,j}]==0) {
                emptySpace = true;
                break;
            }
        }
        if (emptySpace) break;
    }

    if (emptySpace) ans = min(ans,(lli)(right-left+1)*(down-up+1));
    else {
        ans = min(ans,(lli)(right+1-left)*(down+2-up));
        ans = min(ans,(lli)(right+2-left)*(down+1-up));
    }
    mp[bottom_right] = 1;
    // cout << "--------------DOWN_MOVE-----------------" << endl;
    // bug(up,down,left,right);
    // bug(emptySpace,ans);

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