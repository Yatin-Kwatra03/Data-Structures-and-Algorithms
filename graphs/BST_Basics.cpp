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
    node* left;
    node* right;

    node(int d)
    {
        this->data = d;
        left = NULL;
        right = NULL;
    }
};

node* BuildBST(node* root, int d)
{
    if(root == NULL) return new node(d);

    if(d == -1) return NULL;

    if(root->data >=  d) root->left = BuildBST(root->left,d);
    if(root->data < d) root->right  = BuildBST(root->right,d);

    return root;
}


node* BST()
{
    int d;

    node* root = NULL;

    while(scanf("%d",&d) != -1)
    {
        if(d == -1) break;
        root = BuildBST(root,d);
    }
    return root;
}

bool search(node* root , int d)
{
    if(root == NULL) return false;

    if(root->data == d) return true;

    if(d < root->data) return search(root->left,d);
    else return search(root->right,d);
}


void preorder(node* root)
{
    if(root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}



void solve()
{ 
       node* root = BST();
       preorder(root);
       
       
       
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
