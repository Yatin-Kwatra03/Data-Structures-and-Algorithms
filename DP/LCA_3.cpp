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
        root -> left = buildTree();
        root -> right = buildTree();

        return root;
    }

    void preorder_print(node* root)
    {
        if(root == NULL) return;

         cout << root->data << " ";

        preorder_print(root->left);
        preorder_print(root->right);
    }



 int p,q;

int LCS_3(node* root)
{
    if(root == NULL) return -1;

// if we encounter any value out of p and q then it would be answer because
// other value we be somewhere definitely but it is in subtrees of our root
// so current root is the answer


    if(root->data == p || root->data == q) return root->data;

    int leftans = LCS_3(root->left);
    int rightans = LCS_3(root->right);

    if(leftans != -1 and rightans != -1) return root->data;

// one value will definitely be non null because answer is definitely there somewhere

    return leftans != -1 ? leftans : rightans;
}
bool get(node* root,int p)
{
    if(root == NULL) return false;

    if(root->data == p) return true;

    else return get(root->left,p)|get(root->right,p);
}

void solve()
{ 
        node* root = buildTree();
       
        cin >> p >> q;

       // preorder_print(root);
        if(!get(root,p) || !get(root,q)) cout << -1;

        else cout << LCS_3(root);
     //   cout << endl;

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
/*
8 10 1 4 5 12 13 -1 -1 -1 -1 -1 -1 6 9
 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
 */