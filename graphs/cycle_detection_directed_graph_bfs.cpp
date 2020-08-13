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

       
        bool is_cyclic()
        {
            bool* visited = new bool[v];
            queue<int>q;

            fo(i,0,v-1) visited[i] = false;

            int* indegree = new int[v];

            fo(i,0,v-1) indegree[i] = 0;

            for(auto x : h)
            {
                for(auto i : x.second)
                {
                    indegree[i]++;
                }
            }

            fo(i,0,v-1)
            {
                if(indegree[i] == 0) q.push(i);
            }
           
            int cnt = 0;

            while(!q.empty())
            {
                int node = q.front();
               
                q.pop();
                visited[node] = true;
                cnt++;

                for(auto x : h[node])
                {
                    indegree[x]--;
                    if(indegree[x] == 0) q.push(x);
                }
            }

            if(cnt == v) return false;
            return true;

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
