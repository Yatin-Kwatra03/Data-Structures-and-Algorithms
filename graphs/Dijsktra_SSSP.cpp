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
template<typename T>
class graph
{

    unordered_map<T, list< pair<T,int> > >h;

        public:

            void addedge(T u , T v , int d)
            {
                h[u].pb(mp(v,d));
                h[v].pb(mp(u,d));
            }

            void Dijkstra_SSSP(T src)
            {
                 map<T,int>dist;

                for(auto x : h)
                {
                    dist[x.ff] = INT_MAX;
                }

                set<pair<int,T> >s; // set to get the nearest node at the front

                dist[src] = 0;
                s.insert(mp(0,src));

                while(!s.empty())
                {
                    // node we get at the front means its dist is finalised
                    // and can't be decreased further

                    auto node = *(s.begin());
                    s.erase(s.begin());

                    int nodeDist = node.ff;
                    auto curnode = node.ss;


                    // now we will update the distances of the nodes
                    // of its children/neighbours

                    for(auto x : h[node.ss])
                    {
                        if( (nodeDist + x.ss) < dist[x.ff]  ) // if u get smaller val then update it
                        {
                            auto oldnode_pos = s.find(mp(dist[x.ff],x.ff));
                            // if found erasse it from the set
                            if(oldnode_pos != s.end()) s.erase(mp(dist[x.ff],x.ff));

                            dist[x.ff] = nodeDist + x.ss;
                            s.insert(mp(dist[x.ff],x.ff)); // insert the updated distance

                        }
                    }
                }


                for(auto x : dist)
                {
                    if(x.ff == src) continue;
                    if(x.ss == INT_MAX) cout << "-1 ";
                    else cout << dist[x.ff] << " ";

                }
                cout << endl;



            }


};

void solve()
{ 
       
        graph<int>g;

        int n,m,x,y,d,src;
        cin >> n >> m;

        while(m--)
        {
            cin >> x >> y >> d;

            g.addedge(x,y,d);
        }
       src = 1;
        g.Dijkstra_SSSP(src); // considering 1 is the source node
       
       
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
