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

class edge
{
public:

    int src;
    int dest;
    int weight;

};



bool cmp(edge e1 , edge e2)
{
    return e1.weight < e2.weight;
}


int super_parent(int x , vii parent)
{
    if(x == parent[x]) return x;
    else return parent[x] = super_parent(parent[x],parent);
}

ll MST(vector<edge>v ,vii rank , vii parent , int n)
{
    vector<edge>ans;

    int cnt = 0,i = 0;
    ll final_ans = 0;
    edge curedge;

    while(cnt < n-1)
    {
        curedge = v[i];

        int s_p_x = super_parent(curedge.src,parent);
        int s_p_y = super_parent(curedge.dest,parent);

    if(s_p_y != s_p_x)
    {
         if(rank[s_p_x] < rank[s_p_y])
        {
            parent[s_p_x] = s_p_y;
            rank[s_p_y]++;
        }
        else
        {
             parent[s_p_y] = s_p_x;
             rank[s_p_x]++;
        }
        final_ans += curedge.weight;
        ans.pb(curedge);
        cnt++;
    }

        i++; 
    }
    //cout << "Yes\n";
   // fo(i,0,n-2) cout << ans[i].src << "---" << ans[i].dest << " " << ans[i].weight << endl;
    return final_ans;

}

void solve()
{ 
    int n,m,x,y,z;
    cin >> n >> m;

    vector<edge>v(m);
    vii parent(n+1),rank(n+1,0);
    fo(i,0,n) parent[i] = i;


    fo(i,0,m-1)
    {
        cin >> v[i].src >> v[i].dest >> v[i].weight;        
    }   
    sort(all(v),cmp);

  /*  fo(i,0,m-1)
    {
       cout <<  v[i].src << " " << v[i].dest << " " <<  v[i].weight << endl;        
    }   
*/
 //   vector<edge>ans(n-1);
//cout << "YES\n";
    cout <<  MST(v,rank,parent,n);
  
       
}
int main() {
    
    FIO
    INPUT();
    
    int t;
    t = 1;
    //cin >> t;
   // cout << "YES\n";
    while(t--)
    {
       solve();
    }
	return 0;
}
