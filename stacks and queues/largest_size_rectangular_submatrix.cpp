/*

                         YATIN KWATRA                       _03_08_14


Let's Hoop..



                             __oooo
       //  /    o
     / /  |      o
    | /  |__     o
   | |   __/    o
   | |  /  oooo
  | /  |  _______________________
 | |   | |_______________________|
||    |___ \__/\_/\_/\/\/\/\/\/\/
||    |    \ \/\/\/\/\/\/\/\/\/
||    \     \ \/\/\/\/\/\/\/\/
| |    |    |  \/\/\/\/\/\/\/
 | |    |   |   \/\/\/\/\/\/
  | |    \_/    |\/\/\/\/\/|
   \ \     \__  |/\/\/\/\/\|
    |         \
   |           |
   |           |
   |           |
   |           |
    |          |
    |         |
     |________|
     |________|
    ||         |
   | |          |
  |  /          |
 |  /          /
 /\|__________|
|   /       /
|  |       /
| |       |
 \ |      \
  \ \      \
    \ \     |
      \ \    |
        \ \  |_
          \\_/ \
           |    |
           |   /
           |  |
           |_/



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

   -> Check For Overflows
   -> Out of Bounds
   -> Initialisations of global arrays and variables
   -> Read the Question and the sample test cases carefully
   -> Its not Always Complex, Try to simplify
   -> write it down and try to solve
   -> Have Faith in urself and in ur approach
   -> If it seems totally out of reach, switch to next :)
   -> And Come Back later, if possible ..



o- - -  \o          __|
   o/   /|          vv`\
  /|     |              |
   |    / \_            |
  / \   |               |
 /  |                   |


   Thats what I call a Tappu / Blocked_shot / Rejection...


   Time to Code Now.....
*/


const int N = 1005;

int v[N][N];
int n, m, ans;

int f( vii &a)
{
  stack<int>s;
  vii left(m, -1), right(m, m);

  fo(i, 0, m - 1)
  {
    if (s.empty() or (a[s.top()] <= a[i])) s.push(i);
    else
    {
      while (!s.empty() and (a[s.top()] > a[i]))
      {
        right[s.top()] = i;
        s.pop();
      }
      s.push(i);
    }
  }

  while (!s.empty()) s.pop();

  rfo(i, m - 1, 0)
  {
    if (s.empty() or (a[s.top()] <= a[i])) s.push(i);
    else
    {
      while (!s.empty() and (a[s.top()] > a[i]))
      {
        left[s.top()] = i;
        s.pop();
      }
      s.push(i);
    }
  }

  int area = 0, cur, x, y;

  fo(i, 0, m - 1)
  {
    x = left[i] + 1;
    y = right[i] - 1;

    cur = a[i] * (y - x + 1);
    area = max(area, cur);
  }

  return area;

}

void solve()
{

  cin >> n >> m;

  fo(i, 0, n - 1)
  {
    fo(j, 0, m - 1) cin >> v[i][j];
  }

  int mx = 0;
  int px, py;
  int got;
  int ok;

  fo(i, 1, n - 1)
  {
    fo(j, 0, m - 1) if (v[i][j])  v[i][j] += v[i - 1][j];
  }

  ans = 0;

  vii a(m);

  fo(i, 0, n - 1)
  {
    fo(j, 0, m - 1) a[j] = v[i][j];
    ans = max(ans, f(a));
  }

  cout << ans << endl;
}

int main() {

  FIO
  INPUT();

  int t;
  t = 1;
  cin >> t;

  fo(i, 0, t - 1)
  {
    solve();
  }
  return 0;
}
