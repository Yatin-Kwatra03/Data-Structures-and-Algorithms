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


int n, m;
ll sum;

void kadane(vll &v)
{
  ll cursum = 0;
  ll mx = 0;
  ll ok = -1e18;


  fo(i, 0, n - 1)
  {
    ok = max(ok, v[i]);

    cursum += v[i];
    if (cursum < 0) cursum = 0;

    mx = max(mx, cursum);
  }

  if (ok >= 0) sum = max(sum, mx);
  else sum = max(sum, ok);
}


void solve()
{
  cin >> n >> m;

  vvll v(n, vll(m));

  fo(i, 0, n - 1)
  {
    fo(j, 0, m - 1) cin >> v[i][j];
  }

  fo(i, 0, n - 1)
  {
    fo(j, 1, m - 1) v[i][j] += v[i][j - 1];
  }



  // we are maintaining prefix sums for each row, so that we can
  // get sum of elements between a particular column pairs
  // in const time for a specific row

  // we will be generating all column pairs and applying kadane's
  // algorithm, say c1 , c2 are columns, so we check all submatrices
  // whose length is from c1 to c2, so in this way we take a global
  // maxima

  sum = -1e18;

  vll temp(n);

  fo(c1, 0, m - 1)
  {
    fo(c2, c1, m - 1)
    {
      fo(i, 0, n - 1)
      {
        temp[i] = v[i][c2];

        if (c1) temp[i] -= v[i][c1 - 1];
      }

      kadane(temp);
    }
  }

  cout << sum << endl;

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
