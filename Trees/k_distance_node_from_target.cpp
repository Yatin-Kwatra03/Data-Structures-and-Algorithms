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

vii result;

void percolate_down(node* root , int k)
{
    if(root == NULL) return;

    if(k == 0) result.pb(root->data);

    percolate_down(root->left,k-1);
    percolate_down(root->right,k-1);
}




int k_distant(node* root , int target,int k)
{
    // first we look for  our target in the subtrees

    if(root == NULL) return -1; // target node not found

    if(root->data == target)
    {
        percolate_down(root,k);
        return 0;
    }


    // L and R are the distances of current node from target node
    int L = k_distant(root->left,k,target);
    int R = k_distant(root->right,k,target);

    if(L != -1) // -> Target node found in left subtree
    {
        // if current root node is at distance k then there is no
        // chance of any answer in right subtree

        // L = distance of Target node from root->left so from cur node
        // dist = 1+L;

        if(k == (1+L))
        {
            result.pb(root->data);
        }
        else
        {
            // else we look in the right subtrees for nodes at a distance
            // of k - (1+L) from root->node
            // --> distance of k - (1+L) - 1 from root->right
            
            percolate_down(root->right,k-L-2);
        }

        return (1+L);
    }
    else if(R != -1) // -> Target node found in right subtree
    {
        // if current root node is at distance k then there is no
        // chance of any answer in left subtree

        // L = distance of Target node from root->right so from cur node
        // dist = 1+R;

        if(k == (1+R))
        {
            result.pb(root->data);
        }
        else
        {
            // else we look in the left subtrees for nodes at a distance
            // of k - (1+R) from root->node
            // --> distance of k - (1+R) - 1 from root->left
            
           percolate_down(root->left,k-R-2);
        }

        return (1+R);
    }
    else return -1;

}


void solve()
{ 
       node* root = buildTree();
       preorder_print(root);

        int target,k;
        cin >> target >> k;
      
       k_distant(root,target,k);

       fo(i,0,result.size()-1) cout << result[i] << " ";
       
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
