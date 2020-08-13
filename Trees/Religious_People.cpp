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

vll v(100001);

ll n,m,temple_cost, road_cost;


ll sp(ll x,ll* parent)
{
    if(parent[x] == x) return x;
    else return parent[x] = sp(parent[x],parent);
}


void addedge(ll x, ll y, ll &components, ll* parent)
{
 
    ll s_p_x = sp(x,parent);
    ll s_p_y = sp(y,parent);

    if(s_p_y != s_p_x)
    {
        parent[s_p_x] = s_p_y;
       components--;
    }
}


void bfs()
{

}
ll min_cost(ll components)
{
    if(temple_cost < road_cost )
    {
        ll ans = n*temple_cost;
        return ans;
    }

    queue<int>q;

    ll temples = components;

    ll total_cost = (temples*temple_cost) + ((n-temples)*road_cost);

    return total_cost;   

}

void solve()
{ 
        
        cin >> n >> m >> temple_cost >> road_cost;

        ll* parent = new ll[n+1];

        fo(i,1,n) parent[i] = i;


        ll components = n;

        fo(i,0,m-1) 
        {
            ll x,y;
            cin >> x >> y;

            addedge(x,y,components,parent);
        }
     // cout << "components : " << components << endl;
       cout << min_cost(components) << endl;
       
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
