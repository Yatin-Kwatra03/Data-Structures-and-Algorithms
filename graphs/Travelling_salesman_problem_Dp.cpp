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
#define ss                      secondo
#define mod 1000000007

using namespace std;

void INPUT() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

}
int n;

ll Travelling_Salesman_Problem(int mask , int pos, vector<vii>&a , vector<vii>&dp)
{
    // Base Case 

    if(mask == ((1<<n)-1)) return a[pos][0]; // we have reached the last node
    // now return to the starting node which is 0.

    // LOOK UP  

        if(dp[mask][pos] != -1) return dp[mask][pos];


    //Recursive Case
    ll ans = LLONG_MAX;

    // now we explore all the unvisited cities that connect current city
    // and we choose the path which give min answer/cost
    for(int city = 0; city < n ; city++)
    {
        ll temp_mask = (1<<city);

        if((mask & temp_mask) == 0) // means city_th bit is not set
        {
            ll cur_ans = a[pos][city] + Travelling_Salesman_Problem((mask|temp_mask),city,a,dp);
            ans = min(ans,cur_ans);
        }
    }
    return ans; 

}

void solve()
{ 
        
        cin >> n;
        
        vector<vii> a(n,vii(n));

        fo(i,0,n-1)
        {
            fo(j,0,n-1)
            { 
                cin >> a[i][j];
            }
        }

         vector<vii>dp((1<<n),vii(n,-1));

      

        // initial mask will be 000.....(n-1)times...001  means 0th city is visited
        // and its 0 shows the cur city that is 0

       
        cout << Travelling_Salesman_Problem(1,0,a,dp) << endl;




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
