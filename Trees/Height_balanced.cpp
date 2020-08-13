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

void pre(node* root)
{
    if(root == NULL) return;

    cout << root->data << " ";
    pre(root->left);
    pre(root->right);
}

pair<int,bool> is_height_balanced(node* root)
{
    if(root == NULL) return mp(0,true);

    pair<int,bool>p1,p2,p;

    p1 = is_height_balanced(root->left);
    p2 = is_height_balanced(root->right);

    int h1 = p1.ff;
    int h2 = p2.ff;

    if(abs(h1-h2)<=1 and p1.ss and p2.ss) p.ss = true;
    else p.ss = false;

    p.ff = max(h1,h2)+1;

    return p;

}

node* buildTree_from_array(int i , int j , vii a)
{
    if(i>j) return NULL;


    int mid = (i+j)/2;

    node* newnode = new node(a[mid]);

    newnode->left = buildTree_from_array(i,mid-1,a);
    newnode->right = buildTree_from_array(mid+1,j,a);

    return newnode;
}

void solve()
{ 
     /*  node* root = buildTree();
       //pre(root);

   pair<int,bool> ans = is_height_balanced(root);

     if(ans.ss) cout << "Height_Balanced_Tree\n";
     else cout << "Not_Balanced\n";
    */

    int n;
    cin >> n;

    vii a(n);

    fo(i,0,n-1) cin >> a[i];

    node* root = buildTree_from_array(0,n-1,a);
    pre(root);
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
