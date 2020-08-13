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
#define vll                     vector<long long>
#define pq                      priority_queue
#define uo                      unordered_map                
#define all(v)                  v.begin(),v.end()
#define mp                      make_pair
#define pb                      push_back
#define pob                     pop_back
#define ff                      first
#define ss                      second
#define pii                     pair<int,int> 
#define pll                     pair<long long>
#define mll                     map<long,long>
#define mii                     map<int,int>
#define vvii                    vector<vii>
#define mod                     1000000007

using namespace std;

void INPUT() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

}
#define prime 119
int n,m;
vii v;
 string s,pat;

ll power(ll n, ll p)
{
    if(p == 0) return 1LL;

    ll res = 1;

    while(p)
    {
        if(p&1) res *= n;

        p>>=1;
        n *= n;
    }

    return res;
}
#define p 119

ll createHash(string pat)
{
    ll Hash = 0;

// our hash will be made by taking each ascii val of each character and 
// with product of prime raised to position of that character

    fo(i,0,m-1)
    {
        ll no = pat[i] * power(prime,i);
        Hash += no;
    }

    return Hash;
}

bool are_equal(int i )
{
    string str = s.substr(i,m);

    if(str == pat) return true;
    return false;
}

void solve()
{ 
      

       cin >> s >> pat;

       n = s.length();
       m = pat.length();


       if(n<m)
       {
            cout << "No substring Found\n";
            return;
       }

       ll Hash_pat = createHash(pat);
       //cout << Hash << endl;

       ll Hash_str = createHash(s);



       // now we will check every window of size m in the string s
       // and if its Hash value matches then we compare the strings
       // if they are equal or not

       fo(i,0,n-m)
       {
          if(Hash_str == Hash_pat)
          {
             if(are_equal(i)) 
             {
                v.pb(i);
             }
          }

          if(i == (n-m)) break;

          // Update the Hash for the next window

          Hash_str -= s[i]; // don't worry for the prime power as first 
          // characters power is always 0 so no effect of it

          Hash_str /= prime;

          //  NOW add the new charcter with the power of m-1

          Hash_str += s[i+m]*power(prime,m-1);
       }

       if(v.empty())
       {
            cout << " No substring Found\n";
            return;
       }

       for(auto x : v){

            cout << " Pattern Found at Position : " << x << endl; 
       }
       



       
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
