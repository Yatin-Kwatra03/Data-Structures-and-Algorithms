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
    vector<int>super_parent;
    vector<int>siz;
    int total_connected_components;

public:

    graph(int n)
    {
        super_parent.resize(n);
        siz.resize(n);

        fo(i,0,n-1) 
        {
            siz[i] = 1;
            super_parent[i] = i;
        }
        total_connected_components = n;
    }
   

    int get_super_parent(int x)
    {
        if(super_parent[x] == x) return x;
        else return super_parent[x] = get_super_parent(super_parent[x]);
    }

    void unite(int x , int y)
    {
        int s_p_x = get_super_parent(x);
        int s_p_y = get_super_parent(y);

        if(s_p_x != s_p_y)
        {
            super_parent[s_p_x] = s_p_y;
            total_connected_components--;

            siz[s_p_y] += siz[s_p_x];
            siz[s_p_x] = 0; 

        }
    }

    ll final()
    {
        return total_connected_components;
    }


};


void solve()
{ 
        int n,e;
        cin >> n >> e;

        graph g(n);

        int x,y;

        fo(i,0,e-1)
        {
            cin >> x >> y;

            g.unite(x,y);
        }

        cout << g.final();
  
       
}
int main() {
    
    FIO
   // INPUT();
    
    int t;
    t = 1;
    //cin >> t;
    
    while(t--)
    {
       solve();
    }
	return 0;
}
