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
    
void path(vector<string>&v , int n, vector<vector<string>>&ans , int i , int j)
{   
  /*  if((i == n and j!=n) || (i != n and j == n))
    {
        cout << "Yahan bhi\n";
        return;
    } 

 //   cout << "Aur yahan\n";
*/
    if(i == n-1 and j == n-1)
    {
       // cout << "Aa Gya\n";
        v[i][j] = '1';
        ans.pb(v);
        return;
    } 
   // cout << " i :" << i << " and  j : " << j << " "  << v[i][j] << endl;
    // Try to occupy current place if possible
    char temp = v[i][j];

    if(v[i][j] == 'X') return;
    
        v[i][j] = '1';

      if(i<(n-1))  path(v,n,ans,i+1,j);
      if(j<(n-1))  path(v,n,ans,i,j+1);

    
    v[i][j] = temp;
    return;


}
void solve()
{ 
    int n;
    cin >> n;

    // N- QUEEN Problem

    vector<string>v(n,string(n,'_'));

    fo(i,0,n-1)
    {
        
        fo(j,0,n-1) cin >> v[i][j];
    }
    
    //fo(i,0,n-1) cout << v[i] << endl;
    

   vector<vector<string>>ans;
    if(v[n-1][n-1] == 'X' || v[0][0] == 'X') cout << "NO Way Bro!\n";   

    path(v,n,ans,0,0);

   if(ans.size() == 0) 
    {
        cout <<"NO Way Bro!\n" << endl;
        return;
    }

    fo(i,0,ans.size()-1)
    {
        fo(j,0,ans[i].size()-1)
        {
            cout << ans[i][j] << "\n";
        }
        cout << endl;
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
