//                   ********** YATIN KWATRA **********

// AC BAKSHI RABBA

#include <bits/stdc++.h>
#define ll                      long long 
#define ld                      long double
#define ull                     unsigned long long 
#define FIO                     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl                    "\n"
#define fo(i,a,b)               for(int i = a; i<=b ; i++)
#define rfo(i,a,b)              for(int i = a; i>=b ; i--)
#define vii                     vector<int>
#define vll                     vector<ll>
#define pq                      priority_queue
#define uom                     unordered_map                
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
#define MIN                     -1e9
#define pi                      3.1415926535897932384626433832795

using namespace std;

void INPUT() 
{  
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

/*
    
   -> Check For Overflows
   -> Out of Bounds
   -> Initialisations of global arrays and variables
   -> Its not Always Complex, Try to simplify
   -> write it down and try to solve
   -> Have Faith in urself and in ur approach
   -> If it seems totally out of reach, switch to next :)
   -> And Come Back later, if possible ..
*/


class node
{
  public:

      int data;
      node* left;
      node* right;

      node(int data)
      {
        this->data = data;
        left = right = NULL;
      }
};

  
 node* build_tree()
 {
    int d;
    cin >> d;

    if(d == -1) return NULL;

    node* root = new node(d);

    root->left = build_tree();
    root->right = build_tree();
    return root;
 }

 void preorder(node* root)
 {
    if(!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
 }

 void iterative_preorder(node *root)
 {
    if(!root) return;

    stack<node*>s;

    node* fnt;

    while(1)
    {
      while(root)
      {
        s.push(root);
        cout << root->data << " ";
        root = root->left;
      }

      if(s.empty()) break;

      root = s.top();
      s.pop();

      root = root->right;
    }

 }

 void inorder(node* root)
 {
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
 }

 void iterative_inorder(node *root)
 {
    if(!root) return;

    stack<node*>s;

    node* fnt;

    while(1)
    {
      while(root)
      {
        s.push(root);
        root = root->left;
      }

      if(s.empty()) break;

      root = s.top();
      s.pop();

      cout << root->data << ' ';
      root = root->right;
    }
 }

 void postorder(node *root)
 {
    if(!root) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
 }

 void iterative_postorder(node* root)
 {
    if(!root) return;

    stack<node*>s;

    while(1)
    {
      while(root)
      {
        if(root->right) s.push(root->right);
        s.push(root);

        root = root->left;
      }

      if(s.empty()) break;

      root = s.top();
      s.pop();

      if(root->right and s.top() == root->right)
      {
         s.pop();
         s.push(root);
         root = root->right;
      } 
      else
      {
        cout << root->data << " ";
        root = NULL;
      }
    }
 }
void solve()
{ 
    node* root = build_tree();

    preorder(root);
   // inorder(root);
   //   postorder(root);
      cout << endl;

    iterative_preorder(root);
   //     iterative_inorder(root);
    //  iterative_postorder(root);
      cout << endl;


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
