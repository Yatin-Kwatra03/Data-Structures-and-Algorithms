//                          **********  YATIN KWATRA  ********** 


#include <bits/stdc++.h>
#define ll                      long long 
#define ull                     unsigned long long 
#define FIO                     ios_base::sync_with_stdio(false);   cin.tie(NULL);   cout.tie(NULL);
#define endl                    "\n"
#define fo(i,a,b)               for(int i = a; i<=b ; i++)
#define rfo(i,a,b)              for(int i = a; i>=b ; i--)
#define vii                      vector<int>
#define vll                     vector<long long >
#define all(v)                  v.begin(),v.end()
#define mp                      make_pair
#define pb                      push_back
#define pob                     pop_back
#define ff                      first
#define ss                      second
#define mod 1000000007

using namespace std;

void INPUT() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

}

const int N = 200005;

vector<vll>v(N);
ll inf = 1e12;
ll n,m,a,b,c;

void addedge(ll x , ll y )
{
    v[x].pb(y);
    v[y].pb(x);

}

void bfs(ll a , ll* dist)
{
    
    bool* visited = new bool[n+1];

    fo(i,0,n) 
    {
        visited[i] = false;
        dist[i] = 0;
    }

    queue<ll>q;

    q.push(a);
    visited[a] = true;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

    fo(i,0,v[node].size()-1)
    {
        if(visited[ v[node][i] ] == false)
        {
            dist[v[node][i]] = dist[node]+1LL;
            visited[v[node][i]] = true;
            q.push(v[node][i]);
        }
    }

}
   /* fo(i,1,n)
    {
        cout << i << " --> " << dist[i] << endl;
    }
    cout << "\n\n";
*/
}

void solve()
{ 


       
       cin >> n >> m >> a >> b >> c;

       fo(i,0,n+1) v[i].clear();
       vll price(m);

       fo(i,0,m-1) cin >> price[i];
       sort(all(price));

       ll x,y;

       fo(i,0,m-1) 
       {
            cin >> x >> y;
            addedge(x,y);
       }

       

      ll* dist1 = new ll[n+1];
      ll* dist2 = new ll[n+1];
      ll* dist3 = new ll[n+1];

      bfs(a,dist1);
      bfs(b,dist2);
      bfs(c,dist3);

      vll pref(m+1,0);

      fo(i,1,m)
      {
        pref[i] = pref[i-1] + price[i-1];
      }

      ll ans = LLONG_MAX;
      ll dist,cur;

      fo(i,1,n) // we will check for each node for a-->x , x-->b , b-->x , x-->c 
      {         // and try to minimise the cost by optimally distrubuting road prices

        dist = dist1[i] + dist2[i] + dist3[i]; // dist = total distinct nodes
        // in all three paths but dist2 path has to be repeated so we assign
        // smallest path to it

       
        if(dist>m) continue;

        cur = pref[dist] + pref[dist2[i]];

        if(ans>cur) ans = cur;
        
      }
      cout << ans << endl;



}
int main() {
    
    FIO
    INPUT();
    
    int t;
    t = 1;
    cin >> t;
    
    while(t--)
    {
       solve();
    }
    return 0;
}
