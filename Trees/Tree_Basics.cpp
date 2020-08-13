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
    void postorder_print(node* root)
    {
        if(root == NULL) return;

        postorder_print(root->left);
        postorder_print(root->right);
         cout << root->data << " ";
    }
    void inorder_print(node* root)
    {
        if(root == NULL) return;

     
        inorder_print(root->left);
          cout << root->data << " ";
        inorder_print(root->right);
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

    int Height_of_Tree(node* root)
    {
        if(root == NULL) return 0;

        int left_h = Height_of_Tree(root->left);
        int right_h = Height_of_Tree(root->right);

        return 1+max(left_h,right_h);

    }
    void level_print(node* root, int k)
    {
        if(root == NULL) return;
        if(k == 1)
        {
            cout << root->data << ' ';
            return;
        }
        
        level_print(root->left,k-1);
        level_print(root->right,k-1);
    }
int cnt = 0;

ll sum_of_nodes(node* root)
{
    if(root == NULL) return 0;
    ll sum = 0;
    cnt++;
    sum = root->data + sum_of_nodes(root->left) + sum_of_nodes(root->right);
    return sum;
}

pair<int,int> Diameter_of_Tree(node* root)
{
   if(root == NULL) return mp(0,0);

   pair<int,int>op1,op2,op3;

   op1 = Diameter_of_Tree(root->left);
   op2 = Diameter_of_Tree(root->right);

    op3.ss = max(max(op1.ss,op2.ss),op1.ff+op2.ff);
    op3.ff = 1+max(op1.ff,op2.ff);

    return op3;
}




void solve()
{ 
        node* root = buildTree();

 /*      preorder_print(root);
        cout << endl;
         postorder_print(root);
        cout << endl;
        inorder_print(root);
        cout << endl << endl;

        bfs_Level_order_print(root);
        cout << endl;

        int H = Height_of_Tree(root);
        fo(i,1,H)
        {
            level_print(root,i);
            cout << endl;

        ll sum = sum_of_nodes(root);
        cout << "Count : " << cnt << " Sum : "  << sum << endl;
    */
   
    pair<int,int> Diameter = Diameter_of_Tree(root);   
    cout << Diameter.ss << endl;
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