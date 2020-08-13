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
class edge
{
public:
    int src;
    int dest;
    int wt;
};
class graph
{
    public:

    int v;
    int e;
    edge* a;

    graph(int v , int e)
    {
        this->v = v;
        this->e = e;

        a = new edge[v];
    }
    void addedge(int u , int v , int wtt , int cnt)
    {
        a[cnt].src = u;
        a[cnt].dest = v;
        a[cnt].wt = wtt;
    }

    void Bellman_ford(int s)
    {
       // cout << "Yeah\n";
        int* dist = new int[v];
        fo(i,0,v-1) dist[i] = INF;

        dist[s] = 0;

        fo(i,1,v-1)
        {
            fo(j,0,e-1)
            {
                int source = a[j].src;
                int destination = a[j].dest;
                int weight = a[j].wt;

                if(dist[source] != INF and (dist[source] + weight) < dist[destination])
                {
                    dist[destination] = weight + dist[source];
                }
            }
        }

         // Lets check for Negative cycle
         fo(j,0,e-1)
            {
                int source = a[j].src;
                int destination = a[j].dest;
                int weight = a[j].wt;

                if((dist[source] + weight) < dist[destination])
                {
                    cout << "Negative Cycle\n";
                    return;
                }
            }

        // else print the distances

            fo(i,1,v-1)
            {
                cout << s <<" --- " << i << " : " << dist[i] << endl;
            }

    }
    void print()
    {
        fo(i,0,e-1)
        {
            cout << a[i].src << " " << a[i].dest << " " << a[i].wt << endl;
        }
    }
   
};


void solve()
{ 
        int n,e;
        cin >> n >> e;

        graph g(n,e);

        int x,y,z;
        fo(i,0,e-1)
        {
            cin >> x >> y >> z;
            g.addedge(x,y,z,i);
        }
       // g.print();

         g.Bellman_ford(0);  
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
