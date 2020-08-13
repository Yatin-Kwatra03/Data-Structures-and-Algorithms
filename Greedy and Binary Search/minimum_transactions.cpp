//                   ********** YATIN KWATRA **********

// AC BAKSHI RABBA

#include <bits/stdc++.h>
#define ll                      long long 
#define ld                      long double
#define ull                     unsigned long long 
#define FIO                     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl                    "\n"
#define fo(i,a,b)               for(int i = a; i<=b ; i++)
#define rfo(i,a,b)              for(int i = a; i>=b ; i--)
#define vii                     vector<int>
#define vll                     vector<ll>
#define pq                      priority_queue
#define uom                     unordered_map                
#define all(v)                  v.begin(),v.end()
#define mp                      make_pair
#define pb                      push_back
#define pob                     pop_back
#define ff                      first
#define ss                      second
#define pii                     pair<int,int> 
#define pll                     pair<long,long>
#define mll                     map<ll,ll>
#define mii                     map<int,int>
#define vvii                    vector<vii>
#define vvll                    vector<vll>
#define mod                     1000000007
#define pi                      3.1415926535897932384626433832795

using namespace std;

void INPUT() 
{  
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

/*
    
   -> Check For Overflows
   -> Out of Bounds
   -> Initialisations of global arrays and variables
   -> Its not Always Complex, Try to simplify
   -> write it down and try to solve
   -> Have Faith in urself and in ur approach
   -> If it seems totally out of reach, switch to next :)
   -> And Come Back later, if possible..
*/



void solve()
{ 
    ll n,t,x,y,z;
    cin >> n >> t;

    vll v(n,0LL);

    while(t--)
    {
      cin >> x >> y >> z;
      x--,y--;

      v[x] -= z;
      v[y] += z;

    }

    multiset<pll>s;

    fo(i,0,n-1)
    {
      if(v[i] != 0) s.insert(mp(v[i],i));
    }

    ll settle;

    ll ans = 0LL;

    while(!s.empty())
    {
      auto garib = *(s.begin());
      auto ameer = *(s.rbegin());

      s.erase(garib);
      s.erase(ameer);

      settle = min(-garib.ff,ameer.ff);

    //  cout << garib.ss+1 << " -> " << ameer.ss+1 << " : " << settle << endl;

      garib.ff += settle;
      ameer.ff -= settle;

      if(garib.ff != 0) s.insert(garib);
      if(ameer.ff != 0) s.insert(ameer);

      ans += settle;
    }

    cout << ans << endl;


       
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