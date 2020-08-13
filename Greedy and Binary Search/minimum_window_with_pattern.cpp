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


void solve()
{ 
        string s1,s2;
        cin >> s1 >> s2;

        if(s2.length() > s1.length())
        {
            cout << -1 << endl;
            return;
        }
        vector<int>h1(257,0),h2(257,0);


        fo(i,0,s2.length()-1) h2[s2[i]]++;

        int cs = -1,c;
        int bs = -1, be = -1, n = s2.length(), cnt = 0;

        fo(i,0,s1.length()-1)
        {
           if(h1[s1[i]] < h2[s1[i]]) cnt++;

           h1[s1[i]]++;

           if(cnt == n and cs == -1)
           {
             // we got our window
             bs = 0;
             be = i;
             cs = 0;
           }

           if(cnt==n)
           {

              int j = cs;

              while(j<=i and h1[s1[j]] > h2[s1[j]])
              {
                h1[s1[j]]--;
                j++;                
              }
              // check if we got better window

              int len1 = be - bs + 1 ;
              int len2 = i - j + 1;

              if(len2<len1)
              {
                bs = j;
                be = i;
              }

              cs = j;
           }

        }



        if(bs == -1) cout << -1 << endl;
        else 
            {
                string ans = s1.substr(bs,be-bs+1);
                cout << ans << endl;
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
