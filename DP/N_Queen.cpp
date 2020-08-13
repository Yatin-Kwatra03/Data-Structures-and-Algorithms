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
    
bool is_safe(vector<string>&v , int i , int j)
{
    // check in the same row and column and also on the diagonals

    // row check

    fo(k,0,i-1) if(v[k][j] == 'Q') return false;

    // column check

    fo(k,0,j-1) if(v[i][k] == 'Q') return false;

    // left Diagonal check

    int m = i-1 , n = j-1;

    while(m >=0 and n>=0)
    {
        if(v[m][n] == 'Q') return false;
        m--;
        n--;
    }

    // right Diagonal check

    m = i-1;
    n = j+1;

    while(m>=0 and n<=v.size())
    {
        if(v[m][n] == 'Q') return false;
        m--;
        n++;

    }

    // we reached here!

    // It means position is safe
    return true;
}


bool place_Queen(vector<string>&v , int n, int i,vector<vector<string>>&ans)
{
        if(i == n) 
            {
                ans.pb(v);
    }
    fo(j,0,n-1)
    {
        // Try by placing queen at current position

     if(is_safe(v,i,j)) // we can place the queen only if it is a safe position
     {
        v[i][j] = 'Q';

        bool ok = place_Queen(v,n,i+1,ans);
    

        v[i][j] = '_'; // Backtrack and look for other options
        // else print all the possible paths
   

     }   
    }
    return false;
}

void solve()
{ 
    int n;
    cin >> n;

    // N- QUEEN Problem

    vector<string>v;

    fo(i,0,n-1)
    {
        string s(n,'_');
        v.pb(s);
    }

 /*   fo(i,0,n-1)
    {
        fo(j,0,n-1) cout << v[i][j] << " ";
        cout << endl;
    }
*/
   vector<vector<string>>ans;
       

    place_Queen(v,n,0,ans);

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
