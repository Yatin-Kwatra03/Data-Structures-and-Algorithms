//                      YATIN KWATRA

#include <bits/stdc++.h>
#define ll                      long long 
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

void dfs(vii v[], int node, vector<bool>&vis, vii &order)
{
  vis[node] = true;

  for(auto &i : v[node])
  {
    if(!vis[i]) dfs(v,i,vis,order);
  }

  // while going back push the current vertex into the order 
  // vector it means which means all the nodes which were in reach
  // of current node are already pushed into the order vector
  // so we can say at any index i in the order vector 
  // each index at i could be reached from i if possible

  // it just arranges the nodes in the way of seniority kind of thing

  order.pb(node);
  return;
}

int Kosarajus_Algorithm(vii v[], int n, vii &ans)
{
  // Make the order vector 

    vii order;

    vector<bool>vis(n,false);

    fo(i,0,n-1)
    {
      if(!vis[i]) dfs(v,i,vis,order);
    }

    // Now reversing the links 
    // doing so won't affect SCC because if a cycle is reversed it
    // stills remains a cycle

    vii rev[n];

    fo(i,0,n-1)
    {
        for(auto &j : v[i])
        {
          rev[j].pb(i);
        }
    }

    fo(i,0,n-1) vis[i] = false;

    // No of times we have to apply to visit all the nodes in the order
    // vector gives us the no of SCC's

    int siz = n;
    int cnt = 0;

    rfo(i,siz-1,0)
    {

      if(!vis[order[i]])
      {
        cnt++; 

        vii cur;

        dfs(rev,order[i],vis,cur); 

        sort(all(cur));

        for(auto &j : cur)
        {
          ans[j] = cur[0];
        }
        cur.clear();
      } 
    }
    return cnt;
}

void solve()
{ 
        int n,m,x,y;
        cin >> n >> m;
        
        vii v[n];
        
        while(m--)
        {
           cin >> x >> y;

           v[x].pb(y);
        }

        vii ans(n);

      int SCC = Kosarajus_Algorithm(v,n,ans);

      // we can also use a different col to show
      // each edge

      cout << "Total SCC's : " << SCC << endl;
        
        fo(i,0,n-1) cout << ans[i] << endl;
      // we r outputting the smallest edge in each SCC

      
       
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
