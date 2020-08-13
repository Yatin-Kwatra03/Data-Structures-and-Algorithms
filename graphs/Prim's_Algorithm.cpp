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
#define INF 1e9

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
    list<pair<int, int>>*adj;

public:

    graph(int v)
    {
        this->v = v;
        adj = new list<pair<int, int>>[v + 1];
    }

    void addedge(int u , int v , int w)
    {
        adj[u].pb(mp(v, w));
        adj[v].pb(mp(u, w));
    }

    int findvertex(bool* visited , int* weight , int v)
    {
        int minvertex = -1;

        fo(i, 1, v)
        {
            if (!visited[i] and ((minvertex == -1) or (weight[i] < weight[minvertex])) )
            {
                minvertex = i;
            }
        }
        return minvertex;
    }

    void prims(int src)
    {
        bool* visited = new bool[v + 1];
        int* parent = new int[v + 1];
        int* weight = new int[v + 1];

        //Initialisations

        fo(i, 0, v)
        {
            weight[i] = INF;
            visited[i] = false;
        }

        parent[src] = -1;
        ll total = 0;

        fo(i, 1, v)
        {
            //Everytime we look for an unvisited min weighted vertex

            int minvertex = findvertex(visited, weight, v);

            visited[minvertex] = true;
            // update distances of the children of the minvertex

            for (auto x : adj[minvertex])
            {
                if (weight[x.ff] > x.ss and !visited[x.ff])
                {
                    parent[x.ff] = minvertex;
                    weight[x.ff] = x.ss;
                }
            }
        }

        fo(i, 2, v)
        {
            total += weight[i];
        }

        cout << total << endl;

    }
    /*  g.print()
      {
          fo(i,1,v-1)
          {
              cout << i << " --> ";

              for(auto x : )
          }

      }*/
};
void solve()
{
    int n, e;
    cin >> n >> e;

    graph g(n);

    fo(i, 0, e - 1)
    {
        int x, y, w;
        cin >> x >> y >> w;

        g.addedge(x, y, w);
    }
    int startnode;
    cin >> startnode;
    //   g.print();

    g.prims(startnode);

}
int main() {

    FIO
    INPUT();

    int t;
    t = 1;
    //cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
