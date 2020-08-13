//                          **********  YATIN KWATRA  ********** 

//AC bakshi Rabha

#include <bits/stdc++.h>
#define ll                      long long 
#define ull                     unsigned long long 
#define FIO                     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl                    "\n"
#define fo(i,a,b)               for(int i = a; i<=b ; i++)
#define rfo(i,a,b)              for(int i = a; i>=b ; i--)
#define vii                      vector<int>
#define vll                     vector<ll>
#define pq                      priority_queue
#define uom                      unordered_map                
#define all(v)                  v.begin(),v.end()
#define mp                      make_pair
#define pb                      push_back
#define pob                     pop_back
#define ff                      first
#define ss                      second
#define pii                     pair<int,int> 
#define pll                     pair<long,long>
#define mll                     map<long,long>
#define mii                     map<int,int>
#define vvii                    vector<vii>
#define mod                     1000000007
// #define node                    Node

using namespace std;

void INPUT() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

}

vector<vll> f(vvii v , int n)
{
    vector<vector<ll>> dp(n,vll(n,0));

    fo(i,0,n-1)
    {
        fo(j,0,n-1)
        {
            if(i == j) continue;

            dp[i][j] = v[i][j];
        }
    }
    // we are prepared for the kth phase before it

    // Now lets travel through k phases

    
       // kth phase means we are checking the whole matrix if we can 
        // decrease the distances between any two vertexes using
        // an intermediate vertex v for all v belongs to [0,k]

        fo(k,0,n-1)
        {
            fo(i,0,n-1)
            {
                fo(j,0,n-1)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
                }
            }
        }

      
    return dp;

}
void solve()
{ 
        int n;
        cin >> n;
        
        vvii v(n,vii(n));
        
        string s;

        fo(i,0,n-1)
        {
            fo(j,0,n-1)
            {
                cin >> s;
                if(s == "INF") v[i][j] = INT_MAX;
                else v[i][j] = stoi(s);
            }
        }

        vector<vll> dist = f(v,n);

         fo(i,0,n-1)
        {
            fo(j,0,n-1)
            {
               if(dist[i][j] >= 10000000) cout << "INF ";
               else  cout << dist[i][j] << " ";
            }
            cout << endl;
        }


       
}
int main() {
    
    FIO
    INPUT();
    
    int t;
    t = 1;
    cin >> t;
    
    while(t--)
    {
       solve();
    }
    return 0;
}
