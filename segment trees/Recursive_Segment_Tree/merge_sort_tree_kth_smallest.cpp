//                        YATIN KWATRA

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll                      long long
#define ar                      array
#define sz(v)                   (int)(v.size())
#define inf                     1e18
#define int                     ll
#define FIO                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld                      long double
#define ull                     unsigned long long
#define endl                    "\n"
#define fo(i,a,b)               for(int i = a; i<=b ; i++)
#define rfo(i,a,b)              for(int i = a; i>=b ; i--)
#define vii                     vector<int>
#define pq                      priority_queue
#define uomii                   unordered_map<int,int>
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
#define MIN                     -1e9
#define pi                      3.1415926535897932384626433832795
#define cz(x)                   63 - __builtin_clzll(x)

using namespace std;
using namespace __gnu_pbds;
template<class T> using oset =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

/*
----------------------------------------------------------------
   -> Check For Overflows
   -> Out of Bounds
   -> Initialisations of global arrays and variables
----------------------------------------------------------------
*/


// 	MERGE SORT TREE
// TO FIND THE KTH SMALLEST ELEMENT IN A RANGE (WIHTOUT UPDATES)
// IN (LOG(N))^2 PER QUERY
// SEGMENT TREE MADE WITH INDICES

const int N = 1e5 + 5;

vector<int>v[4 * N];
ar<int, 2>a[N];
int c[N];
int x, y, z;

void build(int id, int cx, int cy) {
	if (cx == cy) {
		v[id].pb(a[cx][1]);
		return;
	}
	int mid = (cx + cy) / 2;
	build(2 * id, cx, mid);
	build(2 * id + 1, mid + 1, cy);
	merge(all(v[2 * id]), all(v[2 * id + 1]), back_inserter(v[id]));
}

int qry(int id, int cx, int cy, int k) {
	if (cx == cy) return v[id][0];
	int mid = (cx + cy) / 2;

	// Now we will check if we have at least k elements in left subtree,
	// which lie in our given range, if yes our kth smallest will be in left
	// subtree,because array is sorted on the basis of given value

	int right_bound_plus_one = upper_bound(all(v[2 * id]), y) - v[2 * id].begin();
	int left_bound = lower_bound(all(v[2 * id]), x) - v[2 * id].begin();
	int count = right_bound_plus_one - left_bound;
	if (count >= k) return qry(2 * id, cx, mid, k);
	return qry(2 * id + 1, mid + 1, cy, k - count);
}

void solve()
{
	int n, q;
	cin >> n >> q;
	fo(i, 0, n - 1) cin >> c[i], a[i] = {c[i], i};
	sort(a, a + n);
	build(1, 0, n - 1);
	int ans = 0;
	while (q--) {
		int k;
		cin >> x >> y >> k;
		x--, y--;
		ans = c[qry(1, 0, n - 1, k)];
		cout << ans << endl;
	}
}

signed main() {

	FIO
	INPUT();

	int t;
	t = 1;
//	cin >> t;
	fo(i, 0, t - 1) {
		solve();
	}
	return 0;
}
