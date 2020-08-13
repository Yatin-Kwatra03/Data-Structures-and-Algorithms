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



void solve()
{ 
    int n;
    cin >> n;

    vll v(n),a(n);

    fo(i,0,n-1)
    {
      cin >> v[i];
    }

    stack<int>s,S;
    vll right (n,n);


    s.push(0);

   fo(i,1,n-1) // finding the next smaller element
   {
      if(v[i] < v[s.top()])
      {
        while(!s.empty() and (v[s.top()] > v[i]))
        {
           right[s.top()] = i;
           s.pop();
        }
      
      }
       s.push(i);
   }

  vll left(n,-1);

  S.push(n-1);
 
  rfo(i,n-2,0)
  {
   
    if(v[i] < v[S.top()])
    {

      while(!S.empty() and v[S.top()] > v[i])
      {

        left[S.top()] = i;
        S.pop();
      }
    }
     S.push(i);
  }
/*
  fo(i,0,n-1) cout << left[i] << " ";
  cout << endl;

  fo(i,0,n-1) cout << right[i] << " ";
  cout << endl;
*/
  ll cur = 0 , maxans = 0 , L , R;

  fo(i,0,n-1)
  {
    L = left[i];
    R = right[i];

    cur = (R - (L+1))*v[i];
    maxans = max(maxans,cur);

   // cout << cur << " ";

  }
  cout << maxans << endl;

}
int main() {
    
    FIO
    INPUT();
    
    int t;
    t = 1;
  //  cin >> t;
    
    while(t--)
    {
       solve();
    }
    return 0;
}
