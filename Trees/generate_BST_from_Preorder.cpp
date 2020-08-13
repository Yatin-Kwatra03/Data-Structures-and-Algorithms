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
     void order_print(node* root)
    {
        if(root == NULL) return;

        cout << root->data << " ";
        preorder_print(root->left);
        preorder_print(root->right);
    }
     void bfs_Level_order_print(node* root)
    {
        if(root == NULL) return;

        queue<node*>q;
    
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            node* front_node = q.front();
            q.pop();

            if(front_node == NULL)
            {
                cout << endl;
                if(!q.empty()) q.push(NULL);
                continue;
            }

            cout << front_node->data << " ";

            if(front_node->left != NULL)  q.push(front_node->left);
            if(front_node->right != NULL) q.push(front_node->right);

        }
    }

int i = 0;
vii v;
#define inf 1e9

node* generate_tree_from_preorder(int MAX, int MIN)
{

    // stop when u reach the end of the vector else u'll get a RUNTIME ERROR
    if(i == v.size()) return NULL;
    
    if(!( v[i] > MAX and v[i] < MIN)) return NULL;


    node* root = new node(v[i]);

    // create left and right subtree here only

    i++;
    root->left = generate_tree_from_preorder(MAX,root->data);
    root->right = generate_tree_from_preorder(root->data,MIN);

    return root;
}
void solve()
{ 
    int x;
 
    while(cin >> x)
    {
        v.pb(x);
    }

  node* root = generate_tree_from_preorder(-inf,inf);

   bfs_Level_order_print(root);
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
