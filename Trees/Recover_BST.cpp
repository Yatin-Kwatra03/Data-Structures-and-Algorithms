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

class node
{
    public:

      int data;
      node* left = NULL;
      node* right = NULL;

      node(int d)
      {
        data = d;
        left = NULL;
        right = NULL;
      }
};

node* buildTree()
{
    int d;
    cin >> d;

    if(d == -1) return NULL;

    node* root = new node(d);

    root->left  = buildTree();
    root->right = buildTree();

    return root;
}
set<int>s;
#define inf 1e9

void pre(node* root)
{
  if(root == NULL) return;

  cout << root->data << ' ';
  pre(root->left);
  pre(root->right);
}

vii v;

void inorder(node* root)
{
   if(root == NULL) return;

   inorder(root->left);
    v.pb(root->data);   
   inorder(root->right);
}

void solve()
{ 
    node* root = buildTree();
    inorder(root);

    int ok = 0 , s1 = -1;

    fo(i,0,v.size()-2)
    {
       if(v[i] > v[i+1])
       {

         
          fo(j,i+1,v.size()-1)
          {
            
            if(v[i] < v[j])
            {
            
              cout << v[j-1] << " " << v[i] << endl;
              ok = 1;
              break;
            }

            if(j == v.size()-1)
            {
              cout << v[j] << " " << v[i] << "\n";
              ok = 1;
              break;
            }

          }

       }
       if(ok) break;
    }
}
int main() {
    
    FIO
    INPUT();
    
    int t;
    t = 1;
   // cin >> t;
    
    while(t--)
    {
       solve();
    }
    return 0;
}
