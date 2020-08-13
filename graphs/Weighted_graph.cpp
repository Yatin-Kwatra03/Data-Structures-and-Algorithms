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
    freopen("output1.txt", "w", stdout);
    #endif

}

const int N = 200005;

vector<vll>v(N);
ll inf = 1e12;
int n,m,a,b,c;

void addedge(ll x , ll y )
{
    v[x].pb(y);
    v[y].pb(x);

}

ll bfs(int a , int b, unordered_map<int,int>&parent)
{
    ll* dist = new ll[n+1];
    bool* visited = new bool[n+1];

    fo(i,0,n) 
    {
        visited[i] = false;
        dist[i] = 0;
    }

    queue<ll>q;

    parent[a] = a;

    q.push(a);
    visited[a] = true;

    while(!q.empty())
    {
        ll node = q.front();
        q.pop();

    fo(i,0,v[node].size()-1)
    {
        if(visited[ v[node][i] ] == false)
        {
            dist[v[node][i]] = dist[node]+1LL;
            parent[v[node][i]] = node;

            if(v[node][i] == (ll)b) return dist[v[node][i]];
            visited[v[node][i]] = true;

            

            q.push(v[node][i]);
        }
    }

}
    fo(i,1,n)
    {
        cout << i << " --> " << dist[i] << endl;
    }

}

void solve()
{ 
     /*  
       cin >> n >> m >> a >> b >> c;

       vll price(m);

       fo(i,0,m-1) cin >> price[i];
       sort(all(price));

       ll x,y;

       fo(i,0,m-1) 
       {
            cin >> x >> y;
            addedge(x,y);
       }

       

       unordered_map<int,int>parent1,parent2;

       ll s1 =  bfs(a,b,parent1);
       ll s2 =  bfs(b,c,parent2);



       cout << s1 << " " << s2 << endl;

       int temp = b;

       while(temp!=a)
       {
         cout << temp << " <-- ";
         temp = parent1[temp];
       }
       cout << temp << endl;

        temp = c;
       while(temp!=b)
       {
         cout << temp << " <-- ";
         temp = parent2[temp];
       }
       cout << temp << endl;

       ll total = s1 + s2;
       ll finalans = 0;

       fo(i,0,total-1)
       {
        finalans += price[i];
       }
       cout << finalans << endl;
*/ cout << "NO";
       
}
int main() {
    
    FIO
    INPUT();
    
    int t;
    t = 1;
  //  cin >> t;
    
    while(t--)
    {
       solve();
    }
    return 0;
}
