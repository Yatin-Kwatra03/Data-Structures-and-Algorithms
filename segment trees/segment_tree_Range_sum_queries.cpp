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

void build_tree() // (2*i) and (2*i + 1) are the children of i
{ 
  
  rfo(i,n-1,1)
  {
    v[i] = v[2*i] + v[2*i+1];
  } 
  

}

void modify(ll x, ll y)
{
  // we change the value directly at the required positions and then 
  // update the parent values in O(log N)

  v[n+x] = y;

  ll i = n+x,par;

  while(i>1LL)
  {
    par = i/2;

    v[par] = v[2*par] + v[2*par + 1];

    i /= 2;
  }
}

ll query(ll l, ll r)
{
  // if l is odd then we include cur v[l]
  // else we include value of parent because it contains value of parent
  // also and we directly store it because otherwise we have to go
  // to childs also

  // similarly for the right boundary but in reverse fashion if even then
  // only current element else take parent contribution directly

  // so basically we take contributions only when left boundary
  // is odd and for even boundary only when it is even

  ll res = 0;

  l += n;
  r += n;

  while(l<=r)
  {
    if(l&1)    res += v[l++];
    if(!(r&1)) res += v[r--];

    l /= 2LL;
    r /= 2LL;
  }

  return res;

}

void solve()
{ 
        ll q,z,x,y;
        cin >> n >> q;
        
        fo(i,0,n-1) cin >> v[n+i];

        build_tree();
        
        while(q--)
        {
          cin >> z >> x >> y;

          if(z == 1) // modify
          {
            x--;

            modify(x,y);
          }
          else
          {
            x--;
            y--;

            ll ans = query(x,y);

            cout << ans << endl;
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
