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


bool check(vii v , int n , int thres, int cows)
{
    cows--; // first cow placed at position v[0];

    int last_placed = v[0];

    fo(i,1,n-1)
    {
        if((v[i] - last_placed) >= thres)
        {
          cows--;
          last_placed = v[i];
          if(cows == 0) break;
        }
    }

    if(cows == 0) return true;
    return false;
}

  
void solve()
{ 
    int n , c;
    cin >> n >> c ;// n stalls and c cows

    vii v(n);

    fo(i,0,n-1) cin >> v[i];

    sort(all(v));

    int mindiff = 0, maxdiff = v[n-1] - v[0];

    // we will apply binary serach to find the max distance that we can maintain
    // to place cows such that min distance between each cow is maximised

    int s = mindiff , e = maxdiff;

    int maxans = -1;
    while(s<=e)
    {
       int mid = (s+e)/2;

       //we will check if we can place all the cows at a distance of mid
       // if yes we will look for greater answers
       // else we try for smaller values

       if(check(v,n,mid,c))
       {
          maxans = mid;
          s = mid+1;
       } 
       else {
              e = mid-1;
       }
    }

    cout << maxans << endl;

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
/*1
5 3
1
2
8
4
9
ans = 3
*/