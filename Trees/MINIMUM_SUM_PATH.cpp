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
#define pll                     pair<long,long>
#define mll                     map<long,long>
#define mii                     map<int,int>
#define vvii                    vector<vii>
#define mapii                   map<pii,int>
#define mod                     1000000007

using namespace std;

void INPUT() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

}

int n;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

class custom
{
public:
    int x;
    int y;
    ll d;

  
    bool operator < (const custom &ob1) const
    {

     if(ob1.d != this->d) return this->d < ob1.d;
     else if(ob1.x != this->x) return this->x < ob1.x;
     else return  this->y <  ob1.y;
    }  
};
  

ll dijkstra(vvii v)
{
    vector<vector<bool>>vis(n,vector<bool>(n,false));
    vector<vector<ll>>dist(n,vll(n,LLONG_MAX));

    set<custom>s;

    custom ob;

    ob.x = 0;
    ob.y = 0;
    ob.d = v[0][0];

    dist[0][0] = v[0][0];

    s.insert(ob);

    while(!s.empty())
    {
        custom f = *(s.begin());
        s.erase(f);
    //    cout << "GOT : " << f.x << " " << f.y << " " << f.d << endl;

        vis[f.x][f.y] = true;

        // Now Dealing with its children ... its 4 unfinalized neighbours

        fo(i,0,3)
        {
            int x1 = f.x + dx[i];
            int y1 = f.y + dy[i];



            if(x1<0 or x1>=n or y1<0 or y1>=n or vis[x1][y1]) continue;

            ll temp = f.d + v[x1][y1];

               

            if(temp < dist[x1][y1])
            {
                // find in the set
                ob.x = x1;
                ob.y = y1;
                ob.d = dist[x1][y1];

                auto ok = s.find(ob);
                if(ok != s.end()) s.erase(ob);

                dist[x1][y1] = temp;
                
                ob.x = x1;
                ob.y = y1;
                ob.d = temp;

                s.insert(ob);
             }
        }
    }

   return dist[n-1][n-1];
}
void solve()
{ 
        cin >> n;
        vvii v(n,vii(n));
            
        int x,y;
            
        fo(i,0,n-1)
        {
            fo(j,0,n-1)
            {
                 cin >> v[i][j];
            }
        }
 
        cout << dijkstra(v) << endl;

        
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