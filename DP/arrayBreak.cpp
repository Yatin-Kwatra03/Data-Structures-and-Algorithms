//                        YATIN KWATRA

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize ("Ofast")
//#pragma GCC optimize "trapv" // to detect overflow

#define ll                      long long
#define ar                      array
#define int                     ll
#define sz(v)                   (int)(v.size())
#define FIO                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld                      long double
#define ull                     unsigned long long
#define endl                    "\n"
#define fo(i,a,b)               for(int i = a; i<=b ; i++)
#define rfo(i,a,b)              for(int i = a; i>=b ; i--)
#define vii                     vector<int>
#define pq                      priority_queue
#define uomii                   unordered_map<int,int,best_hash>
#define all(v)                  v.begin(),v.end()
#define mp                      make_pair
#define pb                      push_back
#define pob                     pop_back
#define ff                      first
#define ss                      second
#define pii                     pair<int,int>
#define mii                     map<int,int>
#define vvii                    vector<vii>
#define mod                     1000000007
#define inf                     5e18
#define pi                      3.1415926535897932384626433832795
#define cz(x)                   63 - __builtin_clzll(x)



using namespace std;
using namespace __gnu_pbds;
template<class T> using oset =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


// https://codeforces.com/blog/entry/68809

void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i : x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define pr(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define pr(x...)
#endif

// https://codeforces.com/blog/entry/62393

struct best_hash {
	static uint64_t splitmix64(uint64_t x) {

		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

ll power(ll n, ll p) {
	if (n >= mod) n %= mod;
	ll r = 1;
	while (p) {
		if (p & 1) r = (r * n) % mod;
		n = (n * n) % mod;
		p /= 2LL;
	}
	return r;
}


ll addmod(ll a, ll b) {
	if (a >= mod) a %= mod;
	if (b >= mod) b %= mod;
	if (a < 0) a += mod;
	if (b < 0) b += mod;

	ll ans = a + b;
	if (ans >= mod) ans %= mod;
	return ans;
}

ll mulmod(ll a, ll b) {
	if (a >= mod) a %= mod;
	if (b >= mod) b %= mod;
	if (a < 0) a += mod;
	if (b < 0) b += mod;

	ll ans = a * b;
	if (ans >= mod) ans %= mod;
	return ans;
}

ll submod(ll a, ll b) {
	if (a >= mod) a %= mod;
	if (b >= mod) b %= mod;
	if (a < 0) a += mod;
	if (b < 0) b += mod;

	ll ans = a - b;
	if (ans >= mod) ans %= mod;
	if (ans < 0) ans += mod;
	return ans;
}

ll divmod(ll a, ll b) {
	if (a >= mod) a %= mod;
	if (b >= mod) b %= mod;
	if (a < 0) a += mod;
	if (b < 0) b += mod;

	ll ans = a * power(b, mod - 2);
	if (ans >= mod) ans %= mod;
	return ans;
}

const int N = 3002;
int a[N];
int n;

int rangeSum(int l, int r, vii &v) {
	if (l > r) return 0;
	if (l) return submod(v[r], v[l - 1]);
	return v[r];
}

void solve()
{
	cin >> n;
	fo(i, 0, n - 1) cin >> a[i];

	vii dp(3002);

	fo(i, 0, a[0]) {
		dp[i] = 1;
	}

	fo(i, 1, 3000) dp[i] = addmod(dp[i], dp[i - 1]);

	fo(i, 1, n - 1) {
		vii cur(3002, 0);

		fo(bcur, 0, a[i - 1]) {
			int L = 0;
			int R = bcur - max(0LL, a[i - 1] - a[i]);
			cur[bcur] = rangeSum(L, R, dp);
		}
		dp = cur;
	}
	int ans = 0;
	fo(i, 0, 3000) ans = addmod(ans, dp[i]);
	cout << ans;
}
signed main() {

	FIO
	int t;
	t = 1;
	// cin >> t;
	fo(i, 0, t - 1) {
		solve();
	}
	return 0;
}


