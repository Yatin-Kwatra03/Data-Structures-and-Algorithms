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

class graph
{
    int v;
    map<int,list<int>>h;

    public:

        graph(int v)
        {
            this->v = v;
        }

        void addedge(int u , int v )
        {
            h[u].pb(v);
            h[v].pb(u);
        }

        bool dfs_helper(int node , bool* visited , int* parent)
        {
            visited[node] = true;

            bool ans = false;

            for(auto x : h[node])
            {
                parent[x] = node;

                if(visited[x] == false)
                {
                    ans = dfs_helper(x,visited,parent);
                    if(ans == true) return true;
                }
                else if(visited[x] == true and parent[node] != x) return true;
            }

            return false;
            
        }


        bool is_cyclic()
        {
            bool* visited = new bool[v];
            int * parent = new int[v];
            fo(i,0,v-1) visited[i] = false;
            fo(i,0,v-1) parent[i] = i;

            bool ans = false;

            for(auto x : h)
            {
                if(visited[x.first] == false)
                {
                    ans = dfs_helper(x.first,visited,parent);
                    if(ans == true) return true;
                }
            }
            return false;
        }






        void printgraph()
        {
            for(auto i : h)
            {
                cout << i.ff << " --> ";

                for(auto x : i.ss)
                {
                    cout <<  x << ",";
                }
                cout << "\n";
            } 
        }
};



void solve()
{ 
        int n;
        cin >> n;
        
        graph g(5);

        fo(i,0,n-1)
        {
            int x,y;
            cin >> x >> y;

            g.addedge(x,y);
        }

        g.printgraph();

        if(g.is_cyclic()) cout << "Cyclic\n";
        else cout << "Non-Cyclic\n";
        cout << "Yes\n";
       
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
