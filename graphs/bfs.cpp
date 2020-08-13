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
    map<int,list<pair<int,int>>>h;

    public:

        graph(int v)
        {
            this->v = v;
        }

        void addedge(int u , int v , int wt = 0 , bool bi = true)
        {
            h[u].pb(mp(v,wt));

            if(bi)
            {
                h[v].pb(mp(u,wt));
            }
        }
        void printgraph()
        {
            for(auto i : h)
            {
                cout << i.ff << " --> ";

                for(auto x : i.ss)
                {
                    cout << "(" <<  x.ff << ", " << x.ss << ") , ";
                }
                cout << "\n";
            }
        }


        void bfs(int src)
        {
            // we will be using a queue

            queue<int>q;
            map<int,bool>visited;
            map<int,int>parent;
            map<int,int>dist;

            q.push(src);
            dist[src] = 0;

            visited[src] = true;
            while(!q.empty())
            {
                int node = q.front();
                cout << node << " ";

                q.pop();

                for(auto x : h[node])
                {
                   if(!visited[x.ff]) 
                    {
                        dist[x.ff] = dist[node] + 1;
                        q.push(x.ff);
                        visited[x.ff] = true;

                        // lets store the parent also
                        parent[x.ff] = node;
                    }
                }
            }
            cout << endl;

            for(auto x : dist)
            {
                cout << "Distance of node " << src << " from " << x.ff << " is " << x.ss << endl;
            }

            cout << "\n\n\n";
            cout << " Path from node 5 to the source node 0  :" << endl;

            int temp = 5;

            while(temp!= 0)
            {
                cout << temp <<  " <-- ";
                temp = parent[temp];
            }
            cout << "0\n";
        }

};



void solve()
{ 
        int n;
        cin >> n;
        
        graph g(n);

        fo(i,0,n-1)
        {
            int x,y,wt;
            cin >> x >> y;// >> wt;

            g.addedge(x,y);
        }

        //g.printgraph();
        g.bfs(0);

       
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
