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
#define inf 10000000
ll maxsum = -inf;

int max_sum_path(node* root)
{
    if(root == NULL) return -inf;      /// BASE CASE

    // taken best sum from left and subtree and and check if current 
    // root can increase it further

    int leftsum  = max_sum_path(root->left);
    int rightsum = max_sum_path(root->right);


// CASE 1 : maxsum is in leftsubtree
// CASE 2 : maxsum is in rightsubtree
// CASE 3 : maxsum is formed by adding leftsum + rightsum + root->data but only max(leftsum,rightsum)
// + root->data will be returned because the values can't be included in the longestpath
// CASE 4 : it might be possible current node makes the best sum
    
      
   ll op1 = leftsum + root->data + rightsum;
   ll op2 = leftsum + root->data;
   ll op3 = rightsum + root->data;
   ll op4 = root->data;
   
   maxsum = max(maxsum,max(op1,max(op2,max(op3,op4))));
   
   return max(op2,max(op3,op4));

}

void solve()
{ 
       node* root = buildTree();
     //  preorder_print(root);

       cout << endl;

        max_sum_path(root);
        cout << maxsum  << endl;
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
