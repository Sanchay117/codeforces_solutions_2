//
// Created by bravefart69 on 12/11/24.
//
#include <bits/stdc++.h>
#include <climits>
#include <fstream>
#include <future>
#include <numeric>

using namespace std;

#define ll long long int
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
#define billion 10e9
#define printMatrix(arr,n,m) for(int i = 0;i<n;i++){\
        for(int j = 0;j<m;j++){\
            cout << arr[i][j] << " ";\
        }\
        cout << endl;\
    }
#define sort_dec(arr,n) sort(arr,arr+n,greater<>());
#define sort_asc(arr,n) sort(arr,arr+n);
#define MatrixInput(arr,n,m) for(int i = 0;i<n;i++){\
                                for(int j = 0;j<m;j++){\
                                    cin >> arr[i][j] ;\
                                }\
                             }

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

// ordered set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

string alphabet = "abcdefghijklmnopqrstuvwxyz";

void print(int arr[],const int len){
	fr(i,0,len){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void print(vi x){
	fr(i,0,x.size()){
		cout << x[i] << " ";
	}
	cout << "\n";
}

void print(vector<ll> x){
    fr(i,0,x.size()){
        cout << x[i] << " ";
    }
    cout << "\n";
}

void print(set<int>x) {
    for(auto xx:x) {
        cout << xx << " ";
    }
    cout << endl;
}

void ArrInput(int arr[],const int len){
	fr(i,0,len){
		cin >> arr[i];
		// bug(arr[i]);
	}
}

void ArrInput(ll arr[],const ll len){
	fr(i,0,len){
		cin >> arr[i];
	}
}

void ArrInput(ll arr[],const int len){
	fr(i,0,len){
		cin >> arr[i];
	}
}

void ArrInput(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

// kadane's algorithm
int maxSubArraySum(const std::vector<int>& nums) {
    if (nums.empty()) return 0; // handle empty array

    int max_current = nums[0];
    int max_global = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        max_current = std::max(nums[i], max_current + nums[i]);
        if (max_current > max_global) {
            max_global = max_current;
        }
    }

    return max_global;
}

bool hasIntersectingIntervals(vector<pair<int, int>>& intervals) {
    // Step 1: Sort the intervals based on the starting point
    sort(intervals.begin(), intervals.end());

    // Step 2: Check for overlaps
    for (size_t i = 1; i < intervals.size(); ++i) {
        if (intervals[i].first <= intervals[i - 1].second) {
            return true; // Overlapping interval found
        }
    }

    return false; // No overlapping intervals
}

bool sortbysec(const pair<int,int> &a,
               const pair<int,int> &b)
{
    if(a.F==b.F) return a.S < b.S;
    return a.F < b.F;
}

bool sortbysec(const pair<int,char> &a,
               const pair<int,char> &b)
{
    if(a.F==b.F) return a.S < b.S;
    return a.F > b.F;
}

int max(const vi x) {
    int max = -1;
    fr(i,0,x.size()) {
        if(x[i]>max) max = x[i];
    }
    return max;
}

ll max(ll a,ll b) {
    if(a>=b) return a;
    else return b;
}

int min(const vi x) {
    int min = INT_MAX;
    fr(i,0,x.size()) {
        if(x[i]<min) min = x[i];
    }
    return min;
}

int ind_max_arr(const int arr[],const int size){
	int max = -1;
	int ind = -1;

	fr(i,0,size){
		if(arr[i]>max){
			max = arr[i];
			ind = i;
		}
	}

	return ind;
}

void bfs(const int start, vector<bool>& visited, vector<vector<int>>& adjList) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    // Process nodes in the queue
    while (!q.empty()) {
        const int node = q.front();
        q.pop();
        cout << node << " ";

        // Enqueue unvisited neighbors
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

void dfs(const int node, vector<bool>& visited, vector<vector<int>>& adjList) {
    // Mark the current node as visited
    visited[node] = true;

    // Process the current node (print or do other operations)
    cout << node << " ";

    // Explore all unvisited neighbors
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, adjList);
        }
    }
}

// Function to initialize DFS and handle disconnected components
void dfsHandler(const int numNodes, vector<vector<int>>& adjList) {
    vector<bool> visited(numNodes + 1, false);

    // Iterate through all nodes to handle disconnected components
    for (int i = 1; i <= numNodes; ++i) {
        if (!visited[i]) {
            dfs(i, visited, adjList);
        }
    }
}

void CopyArray(const int arr[],int brr[],int len){
    fr(i,0,len){
        brr[i] = arr[i];
    }
}

unsigned unsigned_flip(unsigned n, unsigned bits = 31) {
    unsigned mask = (1 << bits) - 1;
    return ~n & mask;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll findlcm(int arr[], int n)
{
    // Initialize result
    ll ans = arr[0];

    // ans contains LCM of arr[0], ..arr[i]
    // after i'th iteration,
    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
                (gcd(arr[i], ans)));

    return ans;
}

bool isInteger(double N){
    // Convert float value
    // of N to integer
    int X = N;

    double temp2 = N - X;

    // If N is not equivalent
    // to any integer
    if (temp2 > 0) {
        return false;
    }
    return true;
}

int nCr(int n, int r) {
    // bug(n,r);
    // If r is greater than n, return 0
    if (r > n) return 0;
    // If r is 0 or equal to n, return 1
    if (r == 0 || n == r) return 1;
    // Initialize the logarithmic sum to 0
    double res = 0;
    // Calculate the logarithmic sum of the numerator and denominator using loop
    for (int i = 0; i < r; i++) {
        // Add the logarithm of (n-i) and subtract the logarithm of (i+1)
        res += log(n-i) - log(i+1);
    }
    // Convert logarithmic sum back to a normal number
    return (int)round(exp(res));
}

ll nCr(ll n, ll r) {
    // bug(n,r);
    // If r is greater than n, return 0
    if (r > n) return 0;
    // If r is 0 or equal to n, return 1
    if (r == 0 || n == r) return 1;
    // Initialize the logarithmic sum to 0
    double res = 0;
    // Calculate the logarithmic sum of the numerator and denominator using loop
    for (ll i = 0; i < r; i++) {
        // Add the logarithm of (n-i) and subtract the logarithm of (i+1)
        res += log(n-i) - log(i+1);
    }
    // Convert logarithmic sum back to a normal number
    return (ll)round(exp(res));
}

int sumOfN_naturals(int n) {
    return (n*(n+1))/2;
}

int findNsetBitFromLeft(ll num,int n) {
    int pow = 0;
    vector<int> setBits;
    while(num>0) {
        if(num & 1) {
            setBits.pb(pow);
        }
        num >>= 1;
        pow++;
    }

    if(setBits.size()==1) return -1; // we be assuming n>1

    return setBits[setBits.size()-n];
}

int query(int x,int y) {
    printf("? %d %d\n",x,y);
    fflush(stdout);

    int ans;
    cin >> ans;
    return ans;
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


long long int pairs(long long int n)
{
    return (n * (n - 1)) / 2;
}

bool isSet(int x, int i) {
    return (x & (1 << i)) != 0;
}

// Function to compute modular inverse using Extended Euclidean Algorithm
long long mod_inv(long long a, long long mod) {
    long long m0 = mod, x0 = 0, x1 = 1;
    if (mod == 1) return 0;
    while (a > 1) {
        long long q = a / mod;
        long long t = mod;
        mod = a % mod;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

void print(int x) {
    cout << x << endl;
}

void print(ll x) {
    cout << x << endl;
}


void print(char x) {
    cout << x << endl;
}

void print(string x) {
    cout << x << endl;
}

bool compareHashMap(unordered_map<char,int>m1,unordered_map<char,int>m2) {
    bool ans = true;
    for(auto x:alphabet) {
        if(m1[x]!=m2[x]) {
            ans = false;
            break;
        }
    }
    return ans;
}

int pow(int n,int x) {
    int res = 1;
    fr(i,0,x) {
        res*=n;
    }
    return res;
}

bool intervalIntersect(int a1,int b1,int a2,int b2) {
    if((a1<=b2 && a1>=a2) || (b1<=b2 && b1>=a2)) {
        return true;
    }
    return false;
}

long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;  // Handle base larger than mod
    while (exp > 0) {
        if (exp % 2 == 1)  // If exp is odd, multiply base with result
            result = (result * base) % mod;
        exp = exp >> 1;  // Divide exp by 2
        base = (base * base) % mod;  // Square the base
    }
    return result;
}

ll largestDivisor(ll n) {
    if (n % 2 == 0) return n / 2;
    for (ll i = sqrt(n); i > 1; i--) {
        if (n % i == 0) return n / i;
    }
    return 1;
}

ll simulateBattles(ll health) {
    int count = 0;
    while (health > 1) {
        health = largestDivisor(health);
        count++;
    }
    return count;
}

void solve(int tt) {

    string s;cin >> s;
    int n = s.length();

    int a = 0,b = 0;

    for(auto x:s) {
        if(x=='A') a++;
        else b++;
    }

    int ans = 0;
    if(s[0]=='B') {
        ans = a;
    }else {
        if(s[n-1]=='B') {
            ans = a;
        }else {
            int firstA = 0,lastA = 0;
            int l = 0;
            int smallestGrp = 10e6;
            int crntLen = 0;
            while(l<n) {
                if(s[l]=='A') {
                    crntLen++;
                }else {

                    if(crntLen!=0){
                        smallestGrp = min(smallestGrp,crntLen);
                        crntLen=0;
                    }
                }
                l++;
            }

            smallestGrp=min(smallestGrp,crntLen);

            ans = a-smallestGrp;

            if(b==0) ans = 0;

            bool B = false;
            l = 0;
            while(l<n-1) {
                if(s[l]=='B' && s[l+1]=='B') {
                    B = true;
                    break;
                }
                l++;
            }

            if(B) ans = a;
        }
    }

    out(ans);

}

int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int t = 1;
	cin >> t;
	int i =1;
    // bug(t);

    // SieveOfEratosthenes();

	while(t--){
		solve(i);
		i++;
	}

	return 0;
}