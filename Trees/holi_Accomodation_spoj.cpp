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

    map< int,list<pair<int,int> > >h;

    public:

        void addedge(int u , int v , int wt)
        {
            h[u].pb(mp(v,wt));
            h[v].pb(mp(u,wt));
        }

      

        ll dfs(int node , int a[] , int n , bool visited[])
        {
            visited[node] = true;

            for(auto x : h[node])
            {
                if(visited[x.ff] == false) a[node] += dfs(x.ff,a,n,visited);
            }

            return a[node];
        }

        ll MaxTravel(int n)
        {
            int* a = new int[n+1];


            bool* visited = new bool[n+1];

            fo(i,0,n)
            {
                 visited[i] = false;
                 a[i] = 1;
            }

            a[0] = 0; 


            for(auto x : h)
            {
               if(visited[x.ff] == false) dfs(x.ff,a,n,visited);
            }

             ll contribution;
            int left = 0, right = 0;
            int pathlength = 0;
            ll ans = 0;
            for(auto x : h)

            {
                for(auto i : x.ss)
                {
                    left = min(a[x.ff],a[i.ff]);
                    right = n - left;

                    ans += min(left,right)*i.ss;
                }
            }

            return ans;   
        }



};


ll solve()
{ 
        int n;
        cin >> n;
        
        graph g;

       
        fo(i,0,n-2)
        {
            int x,y,wt;
            cin >> x >> y >> wt;

            g.addedge(x,y,wt);
        }
       // g.printedge(); 

        return g.MaxTravel(n);
       
}
int main() {
    
    FIO
    //INPUT();
    
    int t;
    t = 1;
    cin >> t;
    int m = 1;
    
    while(m<=t)
    {
       cout << "Case #" << m << ": " << solve() << endl;
       m++;
    }
    return 0;
}
