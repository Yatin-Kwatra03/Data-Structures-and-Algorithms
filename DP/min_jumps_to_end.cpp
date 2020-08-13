
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


int f(vii &v , int n)
{
  if(n <=1) return 0;

  if(v[0] == 0) return -1;

  int maxreach = v[0];
  int jumps = 1;

  int steps = v[0];

  // from current point i will check all  acccessible regions
  // from where i can reach n-1 , if i found no option that could
  // take me to the end then i have to take a jump , 
  // i will choose one from the accessible regions which took me most closer to 
  // n-1, obviously , we have checked all positions from current positions
  // accessible to us , none could take us to the end,but we should
  // choose the one which can help us explore maximum options next time

  fo(i,1,n-1)
  {
    if(i == n-1) return jumps;

    maxreach = max(maxreach,i+v[i]);
    steps--;

    if(steps == 0)
    {
       // so now we need a jump
      jumps++;

      // so jump to the position which gave us the maxreach
      // so maxreach-i will give me the v[req_position]

      if(maxreach<=i) return -1;

      steps = maxreach-i;
    }
  }
  cout << "YES|N";
   
}

void solve()
{ 
       int n;
        cin >> n;
        
        vii v(n);
        
        fo(i,0,n-1) cin >> v[i];

        cout << f(v,n) << endl;
       
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
