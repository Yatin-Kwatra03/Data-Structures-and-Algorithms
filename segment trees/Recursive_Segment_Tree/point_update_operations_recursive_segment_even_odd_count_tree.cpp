/*

                         YATIN KWATRA        _03_08_14


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

const int N = 1e5 + 5;

vll v(4 * N);
int val[N];

void build(int id, int x , int y)
{

  if (x == y)
  {
    if (val[x] & 1) v[id] = 0;
    else v[id] = 1;
    return;
  }

  int mid = (x + y) / 2;

  build(2 * id, x, mid);
  build(2 * id + 1, mid + 1, y);

  v[id] = v[2 * id] + v[2 * id + 1];
}

int x, y;

int query(int id, int curx, int cury)
{
  if ( (x > cury) or (y < curx)) return 0;
  if ( (x <= curx) and (y >= cury)) return v[id];

  int mid = (curx + cury) / 2;

  int left = query(2 * id, curx, mid);
  int right = query(2 * id + 1, mid + 1, cury);

  return (left + right);

}

void update(int id, int curx, int cury)
{
  if ((x < curx) or (x > cury)) return;
  if (x == curx)
  {
    val[x] = y;
    if (val[x] & 1) v[id] = 0;
    else v[id] = 1;
  }

  int mid = (curx + cury) / 2;

  update(2 * id, curx, mid);
  update(2 * id + 1, mid + 1, cury);

  v[id] = v[2 * id] + v[2 * id + 1];
}

void solve()
{
  int n;
  cin >> n;

  fo(i, 0, n - 1) cin >> val[i];

  fo(i, 0, 4 * N - 1) v[i] = 0;

  build(1, 0, n - 1);

  int q;
  cin >> q;

  int z;

  while (q--)
  {
    cin >> z >> x >> y;

    cout << z << " " << x << " " << y << endl;

    /* if (!z) x--, update(1, 0, n - 1);
     else
     {
       x--, y--;
       int ans = query(1, 0, n - 1);

       if (z == 1) cout << ans << endl;
       else cout << (y - x + 1 - ans) << endl;
     }
     */
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