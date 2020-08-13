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
        }

        bool dfs_helper(int node , bool* visited, int* a)
        {
            visited[node] = true;
            a[node] = 1; // added to our current path

            bool ans = false;
            for(auto x : h[node])
            {
                if(visited[x] == false) ans = dfs_helper(x,visited,a);
                else if(visited[x] == true and a[x] == 1) return true;

                if(ans == true) return true;
            }

            a[node] = 0;
            return false;
        }


        bool is_cyclic()
        {
            bool* visited = new bool[v];

            fo(i,0,v-1) visited[i] = false;

            // array to keep a track of nodes in our current path 

            int* a = new int[v];
            fo(i,0,v-1) a[i] = 0;

            bool ans = false;

            for(auto x : h)
            {
                int node = x.first;

                
                if(visited[node] == false) ans =  dfs_helper(node,visited,a);

                if(ans == true) return true;
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
        
        graph g(7);

        fo(i,0,n-1)
        {
            int x,y;
            cin >> x >> y;

            g.addedge(x,y);
        }

        g.printgraph();

        if(g.is_cyclic()) cout << "Cyclic\n";
        else cout << "Non-Cyclic\n";

       
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
