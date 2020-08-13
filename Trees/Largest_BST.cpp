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
    public : 

    int data;
    node* left;
    node* right;

    node(int d)
    {
        this->data = d;
        left = NULL;
        right = NULL;
    }
};

node*  buildTree()
{
    int d;
    cin >> d;
    if(d == -1) return NULL;

        node* newnode = new node(d);

        newnode -> left = buildTree();
        newnode -> right  = buildTree();

        return newnode;
}


void inorder(node* root)
{
    if(root == NULL) return;

    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
  int n;
    int root_idx = 0;
    node* buildTree_in_pre(vii P , vii I ,int j, int k)
    {
        if(j>k) return NULL;


        int cur = P[root_idx], idx = -1;

        fo(i,j,k)
        {
            if(cur == I[i])
            {
                idx = i;
                break;
            }
        }

        root_idx++;
        node* newnode = new node(cur);
        newnode->left = buildTree_in_pre(P,I,j,idx-1);
        newnode->right = buildTree_in_pre(P,I,idx+1,k);

        return newnode;
    }

int maxans = 1;
#define inf 1e9

class custom
{

public:

   int nodes;
   bool isBst;
   int MIN;
   int MAX;

    custom()
    {
      nodes = 0;
      isBst = true;
      MIN = inf;
      MAX = -inf;
    }
};

custom find_Biggest_Bst(node* root)
{
  if(root == NULL) {

    custom p;
    return p;
  }

  custom p1 = find_Biggest_Bst(root->left);
  custom p2 = find_Biggest_Bst(root->right);

  custom p;
  if(p1.isBst and p2.isBst)
  {
      

     if( root->data < p1.MAX || root->data > p2.MIN) p.isBst = false;

     if(p.isBst)
     {
        p.nodes = p1.nodes + p2.nodes + 1;
        p.MIN   = min(p1.MIN,root->data);
        p.MAX   = max(p2.MAX,root->data); 

        maxans = max(maxans,p.nodes);
     }
     return p;

  }
  p.isBst = false;
  return p;

}



void solve()
{ 
   
    cin >> n;

    vii P(n),I(n);

    fo(i,0,n-1) cin >> P[i];
    fo(i,0,n-1) cin >> I[i]; 

    node* root = buildTree_in_pre(P,I,0,n-1);
    find_Biggest_Bst(root);

    cout << maxans << endl;

    
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
