//                      YATIN KWATRA

// AC BAKSHI RABBA

#include <bits/stdc++.h>
#define ll                      long long 
#define ld                      long double
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
#define mll                     map<ll,ll>
#define mii                     map<int,int>
#define vvii                    vector<vii>
#define vvll                    vector<vll>
#define mod                     1000000007
#define pi                      3.1415926535897932384626433832795
// #define node                    Node

using namespace std;

void INPUT() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

const int N = 1e5;
ll n;

vll v(2*N);

// If we have to get the complete updated array
// then  instead of performing n queries in NlogN time
// we can push all values from parent to children in O(N) time
// in the similar way we build the tree

void get_comp_array()
{
  fo(i,1,n-1)
  {
    v[2*i]   += v[i];
    v[2*i+1] += v[i];
    v[i] = 0;
  }
}

ll query(ll x)
{

  ll i = n+x,res = 0;

  while(i>0)
  {
    res += v[i];
    i /= 2;
  }
  return res;
}

void modify(ll l, ll r, ll w)
{

  l += n;
  r += n;

  while(l<=r)
  {
    if(l&1)    v[l++] += w;
    if(!(r&1)) v[r--] += w;

    l /= 2LL;
    r /= 2LL;
  }

}

void solve()
{ 
        ll q,x,y,w;
        char z;

        cin >> n >> q;
        
        fo(i,0,n-1) cin >> v[n+i];

        fo(i,1,n-1) v[i] = 0;
        
        while(q--)
        {
          cin >> z >> x;

          if(z == 'q') // modify
          {
            x--;
           ll ans = query(x);
           cout << ans << endl;
          }
          else
          {
            cin >> y >> w;

            x--;
            y--;

           modify(x,y,w);

          }
        }

}
int main() {
    
    FIO
    INPUT();
    
    int t;
    t = 1;
 //   cin >> t;
    
    while(t--)
    {
       solve();
    }
    return 0;
}
