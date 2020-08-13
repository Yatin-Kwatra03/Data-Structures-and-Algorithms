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

        void addedge(int u , int v ,bool bi = true)
        {
            h[u].pb(v);

            if(bi)
            {
                h[v].pb(u);
            }
        }

        bool is_tree()
        {
            bool* visited = new bool[v];
            int* parent  = new int [v];

            

             for(auto x : h)
            {
                cout << x.first << " --> ";

                for(auto i : x.second)
                {
                    cout << i << ", ";
                }
                cout << endl;
            }
            fo(i,0,v)
            {
                visited[i] = false;
                parent[i] = i;
            }

        //    fo(i,0,v-1) cout << visited[i] << "  " << parent[i] << endl;
            queue<int>q;

            q.push(0);
            visited[0] = true;

            while(!q.empty())
            {
                int node = q.front();
                q.pop();

               for(auto i : h[node])
             {
                     if(visited[i] == true and parent[node] != i)
                    {
                       return false;
                    }
                    else if(!visited[i])
                    {
                        visited[i] = true;
                        parent[i]  = node;
                        q.push(i);
                    }
                
            }

            }
          
            return true;

        }


};



void solve()
{ 
        int n;
        cin >> n;
        
        graph g(n+1);

        fo(i,0,n)
        {
            int x,y;
            cin >> x >> y;
            
            g.addedge(x,y);
        }

       if(g.is_tree()) cout << "Is a Tree\n";
       else cout << "Not a Tree\n";

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
