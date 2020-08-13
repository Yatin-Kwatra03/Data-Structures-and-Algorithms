//                      YATIN KWATRA

// AC BAKSHI RABBA

#include <bits/stdc++.h>
#define ll                      long long 
#define ld                      long double
#define ull                     unsigned long long 
#define FIO                     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl                    "\n"
#define fo(i,a,b)               for(int i = a; i<=b ; i++)
#define rfo(i,a,b)              for(int i = a; i>=b ; i--)
#define vii                      vector<int>
#define vll                     vector<ll>
#define pq                      priority_queue
#define uom                      unordered_map                
#define all(v)                  v.begin(),v.end()
#define mp                      make_pair
#define pb                      push_back
#define pob                     pop_back
#define ff                      first
#define ss                      second
#define pii                     pair<int,int> 
#define pll                     pair<long,long>
#define mll                     map<ll,ll>
#define mii                     map<int,int>
#define vvii                    vector<vii>
#define vvll                    vector<vll>
#define mod                     1000000007
#define pi                      3.1415926535897932384626433832795
// #define node                    Node

using namespace std;

void INPUT() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int B = 1;

pii f(int x, int y)
{

  if(x<y) swap(x,y);

  // Find the level of y

  ll i = 1, j = 2, level = 0;

  while(i < y)
  {
    level++;
    i += j;
    j *= 2LL;

  }

  ll cur = 1;

  if(level&1) cur = 0;

  // Now we reach upto same level as y from x

  j = x;

  int nodes = 0;

  while(j > i)
  {
    nodes++;
    j /= 2LL;
  }

  ll blacks = 0;

  if(cur)
  {
    if((nodes+1)&1) blacks = (nodes+1)/2;
    else blacks = (nodes+1)/2 - 1;
  }
  else blacks = (nodes+1)/2;

  level = 1;

  if(cur == 1) level = 0;

 ll tot = 0;

  x = j;

  while(x != y)
  {
    if(!(level&1)) blacks += 2LL;

    tot += 2LL;

    x /= 2;
    y /= 2; 

    level++;
 }

 if(!(level&1)) blacks++;
 tot++;
 
 return mp(blacks,tot+nodes);
}



void solve()
{ 

        int n,x,y;
        string s;
        cin >> n;
        B = 1;
        
        while(n--)
        {
          cin >> s;

          if(s == "Qi") B ^= 1;
          else if(s == "Qb")
          {
            cin >> x >> y;

            pii ans = f(x,y);

            if(B == 1) cout << ans.ff << " ";
            else cout << ans.ss-ans.ff << " ";
          }
          else
          {
            cin >> x >> y;
            pii ans = f(x,y);

            if(B == 1) cout << ans.ss - ans.ff << " ";
            else cout << ans.ff << " ";
          }
        }

        cout << endl;
    
       
}
int main() {
    
    FIO
    INPUT();
    
    int t;
    t = 1;
 //   cin >> t;
    
    while(t--)
    {
       solve();
    }
    return 0;
}
