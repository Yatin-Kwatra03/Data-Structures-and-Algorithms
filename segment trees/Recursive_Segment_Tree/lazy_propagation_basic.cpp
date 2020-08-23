/*

                         YATIN KWATRA                   _03_08_14


Let's Hoop..

------------------------------------------------

           o
 /|   o         o
 \|=--            o
    ##
                    \\
                 /   \O
                O_/   T
                T    /|
                |\  | |
 _______________|_|________

------------------------------------------------

o- - -  \o          __|
   o/   /|          vv`\
  /|     |              |
   |    / \_            |
  / \   |               |
 /  |                   |


------------------------------------------------

HOOPER_4_LYF..

*/

// AC BAKSHI RABBA

// #pragma GCC optimize "trapv"

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define FIO                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pbds                    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ll                      long long
#define ld                      long double
#define ull                     unsigned long long
#define endl                    "\n"
#define fo(i,a,b)               for(int i = a; i<=b ; i++)
#define rfo(i,a,b)              for(int i = a; i>=b ; i--)
#define vii                     vector<int>
#define vll                     vector<ll>
#define pq                      priority_queue
#define uom                     unordered_map
#define all(v)                  v.begin(),v.end()
#define mp                      make_pair
#define pb                      push_back
#define pob                     pop_back
#define ff                      first
#define ss                      second
#define pii                     pair<int,int>
#define pll                     pair<ll,ll>
#define mll                     map<ll,ll>
#define mii                     map<int,int>
#define vvii                    vector<vii>
#define vvll                    vector<vll>
#define mod                     1000000007
#define MIN                     -1e9
#define pi                      3.1415926535897932384626433832795

using namespace std;
using namespace __gnu_pbds;

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
   -> Read the Question and the sample test cases carefully
   -> Its not Always Complex, Try to simplify
   -> write it down and try to solve
   -> Have Faith in urself and in ur approach
   -> If it seems totally out of reach, switch to next :)
   -> And Come Back later, if possible ..

----------------------------------------------------------------*/

const int N = 1e5 + 5;

ll lazy[4 * N];
ll x, y, z, w;


void apply(ll par, ll child)
{
  // if cur val is LLONG_MAX, it means child remains same

  if (lazy[par] == LLONG_MAX) return;
  lazy[child] = lazy[par];
}

void propagate(ll id, ll cx, ll cy)
{

//we are already at the leaf node ,
// so we can apply the operation here only, no need to further push
  // the operation

  if (cx == cy) return;

// apply the operation to its children

  apply(id, 2 * id);
  apply(id, 2 * id + 1);

  lazy[id] = LLONG_MAX; // now operations has been propagated to children
  // so remove from this position now
}

void update(ll id, ll cx, ll cy)
{
  if (y < cx or x > cy) return;

  propagate(id, cx, cy); // propagate works in const time (depending upon operation, '=' works in constant time)

  if (x <= cx and cy <= y)
  {
    lazy[id] = w;
    return;
  }

  int mid = (cx + cy) / 2;

  update(2 * id, cx, mid);
  update(2 * id + 1, mid + 1, cy);
}

ll query(ll id, ll cx, ll cy)
{
  if (x < cx or x > cy) return LLONG_MAX;

  propagate(id, cx, cy);

  // to get the answer for a position for an answer we can just use the
  // simple recursion and get the value by applying the operations
  // on coming back, because the operation top level are newest
  // and the ones at the bottom are oldest, so they need to
  // applied first followed by newest thats what happens when call
  // returns from recursion

  if (cx == cy) return lazy[id];

  int mid = (cx + cy) / 2;

  ll left = query(2 * id, cx, mid);
  ll right = query(2 * id + 1, mid + 1, cy);

  return (left == LLONG_MAX) ? right : left;
}


void solve()
{
  int n, q;
  cin >> n >> q;

  fo(i, 0, 4 * N - 1) lazy[i] = LLONG_MAX;

  while (q--)
  {
    cin >> z;

    if (z == 1)
    {
      cin >> x >> y >> w;
      y--;
      update(1, 0, n - 1);
    }
    else
    {
      cin >> x;
      ll ans = query(1, 0, n - 1);

      cout << (ans == LLONG_MAX ? 0 : ans) << endl;
    }
  }

}

int main() {

  FIO
  INPUT();

  int t;
  t = 1;
// cin >> t;

  fo(i, 0, t - 1)
  {
    solve();
  }
  return 0;
}