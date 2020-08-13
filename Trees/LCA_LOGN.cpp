

//                   ********** YATIN KWATRA **********

// AC BAKSHI RABBA

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
#define pll                     pair<long,long>
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
   -> Its not Always Complex, Try to simplify
   -> write it down and try to solve
   -> Have Faith in urself and in ur approach
   -> If it seems totally out of reach, switch to next :)
   -> And Come Back later, if possible ..
*/


const int N = 200005;
const int mx = 22;


int par[N][mx];
ll val[N][mx];
int depth[N];


ll f(int x, int y)
{
  if(depth[x] < depth[y]) swap(x,y); // we consider x to be deeper

  // First level the heights using binary lifting

  int dif = depth[x] - depth[y];

  ll ans = 0;

  rfo(i,mx-1,0)
  {
    if(dif&(1<<i))
    {
      ans += val[x][i];
      x = par[x][i];
    } 
  }

  if(x==y) return ans;

  // Now using binary lifting and careful observation, we lift them together
  // we make them jump only when their parents are non equal

  rfo(i,mx-1,0)
  {
    if(par[x][i] != par[y][i]) // jump
    {
      ans += val[x][i];
      ans += val[y][i];

      x = par[x][i];
      y = par[y][i];
    }
  }

  // we will always end at one position less than lca
  // so we need to add the two edge weights seperately

  ans += (val[x][0] + val[y][0]);
  return ans;

}

void solve()
{ 
      fo(i,0,N-1)
      {
        depth[i] = 0;

        fo(j,0,mx-1)
        {
          par[i][j] = i;
          val[i][j] = 0;
        } 
      }

      int q,x,y,z,w,u,v;
      cin >> q;

//  So we have two type of queries , earlier we used to have all the edges
// before and then we used to find each level parent for each node
// Now we will get to know about the edges in between the queries , so we
// everytime we have to add an edge , we just update the parents and value
// value for it, without worrying about others, become rest information
// is already stored, when they were added

      while(q--)
      {
        cin >> z;

        if(z == 1)
        {
          cin >> u >> v >> w;
          u--;
          v--;

          par[v][0] = u;
          val[v][0] = w;
          depth[v] = depth[u]+1;

          fo(i,1,mx-1)
          {
            par[v][i] = par[par[v][i-1]][i-1];
            val[v][i] = val[v][i-1] + val[par[v][i-1]][i-1];
          }

        }
        else
        {
          cin >> x >> y;
          x--;
          y--;

          cout << f(x,y) << endl;
        }
      }
}
int main() {
    
    FIO
    INPUT();
    
    int t;
    t = 1;
    //cin >> t;
    
    while(t--)
    {
       solve();
    }
    return 0;
}