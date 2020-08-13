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

const int N = 2005;

int n,m,x,y;
vii v[N];

bool ok;

void dfs(int node,vii &col, int assign, int parent)
{

    col[node] = assign;

   // cout << " node : " << node << " col : " << col[node] << endl;

    for(auto &i : v[node])
    {   
       if(i == parent) continue;

        if(col[i] == -1) dfs(i,col,3-col[node],node);
        else if(col[i] == col[node]) ok = 0;

        if(!ok) return;
    }
}

void is_Bipartite()
{
    vii col(n+1,-1);

    fo(i,1,n)
    {
       if(col[i] == -1)
       {
        dfs(i,col,1,-1);
        
        if(!ok) return;
       } 
    }
}

void solve()
{ 
        cin >> n >> m;

        while(m--)
        {
            cin >> x >> y;

            v[x].pb(y);
            v[y].pb(x);
        }

        ok = 1;

       is_Bipartite();

       if(ok) cout << " Bipartite Graph\n";
       else cout << " Not a Bipartite Graph !\n";

        fo(i,0,n) v[i].clear();
       
}
int main() {
    
   FIO
   INPUT();
    
    int t;
    t = 1;
   // cin >> t;
    
    while(t--)
    {
       solve();
    }
    return 0;
}

// keep in mind don't just return if u get a visited valid node
// return only when u encounter a invalid node

/*if(col[i]==-1)
{
  if(col[i] == col[node]) ok = 0;

  return; // <---- this step is incorrect because it is a bipartite graph
  // but u will get a NO
}

E.G.

6 6
1 2
2 3
3 4
4 5
5 2
5 6

// In the above example dfs starts from 1->2->3->4->5->1
after 5 u encounter a valid visited node u returned then we missed other nos
of our current node i.e 6 now again dfs will start from 6 assigning it a
value of 1 and its only child 5 is also 1
If we hadn't returned then it would had automatically got value 2
and answer would had been YES for this case
-------------------------------------------------------------------------------- */