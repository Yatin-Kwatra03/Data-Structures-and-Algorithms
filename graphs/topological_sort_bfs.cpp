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

        void dfs_helper(int node , unordered_map<int,bool>&visited , list<int>&ordering)
        {

            visited[node] = true;

            for(auto x : h[node])
            {
               if(visited[x] == false) dfs_helper(x,visited,ordering);
            }
            ordering.push_front(node);
        }

        
        void DAG_bfs()
        {
             unordered_map<int,int>indegree;

             for(auto x : h) 
             {
                indegree[x.first] = 0; 
             }
             queue<int>q;

             for(auto x : h)
             {
                int edge = x.first;

                for(auto i  : h[edge])
                {
                    indegree[i] += 1;
                }
             }
             for(auto x : h) 
             {
                cout << x.first << " " <<  indegree[x.first] << endl;
             }


             for(auto x : h)
            {
                if(indegree[x.first] == 0) q.push(x.first);
            }

            while(!q.empty())
            {
                
                int node = q.front();
                
                cout << node << " ";
                q.pop();

                for(auto x : h[node])
                {
                    indegree[x]--;
                    if(indegree[x] == 0) q.push(x);
                }
            }
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
        
        graph g(n);

        fo(i,0,n-1)
        {
            int x,y;
            cin >> x >> y;

            g.addedge(x,y);
        }

       // g.printgraph();
        g.DAG_bfs();

       
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
