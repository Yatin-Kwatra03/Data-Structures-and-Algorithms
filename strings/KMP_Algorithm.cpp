//                      YATIN KWATRA

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

void build_suffix_array(string &pat, vii &v, int m)
{
    int i = 1, j = 0;

    v[0] = 0; // if a mismatch occurs at zero index, obviously comparison
            // has to be from 0 index only next time


    while(i<m)
    {
        if(pat[i] == pat[j])
        {
            v[i] = j+1;
            i++;
            j++;
        }
        else
        {
            // we go to index by checking at prev j

            if(j==0) v[i++]=0;
            else j = v[j-1];
        }
    }

}

int KMP_matching(string &s, string &pat, vii &v, int n, int m)
{
    int i = 0, j = 0;
    bool ok = 0;

    while(i<n and j<m)
    {
        if(s[i] == pat[j])
        {
            i++;
            j++;
        }
        else
        {
            // look for a suffix array length at index at j-1

           if(j!=0) j = v[j-1];
           else i++;
        }


        if(j == m) 
        {
            
           ok = 1;
           cout << i-m+1 << endl;
           if(j != 0) j = v[j-1]; 

           // j-1 is the last index of the pat
           // string we check for suffix which could act as prefix
           // for more occurances of the same string
        }
    }

   if(!ok) return -1;
   return 0;
}

void solve()
{   
     
        string pat,s;
    
        cin >> s >> pat;

        int n = s.length();
        int m = pat.length();

        // we will build a suffix array which will give us the
        // index from where we need to start the comparison whenever we 
        // get a mismatch, its not like we have to start again and
        // again from the start everytime we get a mismatch
        // e.g. abcdabx we matched with abcdaby but x != y
        // but we can see ab is the prefix of the patt, so we can skip
        // it and straightaway look for c from current index


        // this prefix information could be stored in a suffix array

        vii suffix(m,0);

        build_suffix_array(pat,suffix,m);
        
       //fo(i,0,m-1) cout << suffix[i] << ' ';
      //  cout << endl;

       int idx = KMP_matching(s,pat,suffix,n,m);

       if(idx == -1) cout <<  "Not Found !\n";
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
