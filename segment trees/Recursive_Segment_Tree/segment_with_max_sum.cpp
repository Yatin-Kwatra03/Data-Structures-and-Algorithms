/*

                         YATIN KWATRA                   _03_08_14


Let's Hoop..



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
#define ll                      long long
#define ld                      long double
#define ull                     unsigned long long
#define FIO                     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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

// Maximum sum segment (answer could also be empty segment (i.e 0))

class ob
{
public:

  ll seg;
  ll pref;
  ll suf;
  ll sum;

  ob()
  {
    seg = pref = suf = sum = 0;
  }
};

const int N = 100005;

vector<ob> v(4 * N);
ll val[N];
ll x, y;

void build(int id, int cx, int cy)
{
  if (cx == cy)
  {
    v[id].seg  = v[id].pref = v[id].suf = v[id].sum  = val[cx];
    return;
  }

  int mid = (cx + cy) / 2;

  build(2 * id, cx, mid);
  build(2 * id + 1, mid + 1, cy);

  v[id].seg  = max(v[2 * id].suf + v[2 * id + 1].pref , max(v[2 * id].seg , v[2 * id + 1].seg));
  v[id].pref = max(v[2 * id].pref, v[2 * id].sum + v[2 * id + 1].pref);
  v[id].suf  = max(v[2 * id + 1].suf, v[2 * id].suf + v[2 * id + 1].sum);
  v[id].sum = v[2 * id].sum + v[2 * id + 1].sum;
}

void update(int id, int cx , int cy)
{
  if (x < cx or cy < x) return;

  if (cx == cy and cx == x)
  {
    val[x] = y;
    v[id].seg  = v[id].pref = v[id].suf = v[id].sum  = y;
    return;

  }

  int mid = (cx + cy) / 2;
  update(2 * id, cx, mid);
  update(2 * id + 1, mid + 1, cy);

  v[id].seg  = max(v[2 * id].suf + v[2 * id + 1].pref , max(v[2 * id].seg , v[2 * id + 1].seg));
  v[id].pref = max(v[2 * id].pref, v[2 * id].sum + v[2 * id + 1].pref);
  v[id].suf  = max(v[2 * id + 1].suf, v[2 * id].suf + v[2 * id + 1].sum);
  v[id].sum = v[2 * id].sum + v[2 * id + 1].sum;

}

void solve()
{

  int n, q;
  cin >> n >> q;

  fo(i, 0, n - 1) cin >> val[i];

  build(1, 0, n - 1);

  cout << max(0LL, v[1].seg) << endl;

  while (q--)
  {
    cin >> x >> y;

    update(1, 0, n - 1);
    cout << max(0LL, v[1].seg) << endl;
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