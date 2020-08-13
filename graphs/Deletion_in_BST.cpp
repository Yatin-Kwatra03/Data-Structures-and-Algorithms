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
    cin >> d;

    node* root = NULL;

    while(d != -1)
    {
       // if(d == -1) break;
        root = BuildBST(root,d);
        cin >> d;
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

node* deleteNode(node* root , int d)
{
    if(root == NULL) return NULL;

    if(d < root->data) root->left =  deleteNode(root->left,d);
    else if(d > root->data) root->right =  deleteNode(root->right,d);
    else
    {
        // we found the node

        // Case 1 -> Node is a leaf node

        if(root->left == NULL and root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // Case 2 -> Node has one child

        if(root->left != NULL and root->right == NULL)
        {
            node* store = root->left;
            delete root;

            return store;
        }
        if(root->left == NULL and root->right != NULL)
        {
            node* store = root->right;
            delete root;

            return store;
        }


        // Case 3 -> Node has 2 children
        // In this Case current node has to be replaced by immediate predessor
        // or successor 
        // we replace it by succesor


        node* replace = root->right;

        while(replace->left != NULL) // if replace->left is NULL that means we got the 
        {                               // req node

            replace=replace->left;
        }
        root->data = replace->data;

        // now root val is at the end , just delete it using first 2 cases
        // as it is the smallest element so it will definitely have 0 or 1 children


        root->right = deleteNode(root->right,replace->data);
    }
    return root;
}

void solve()
{ 
       node* root = BST();
       preorder(root);

         int d;
        cin >> d;
      //  d = 8;
        cout << endl << d << endl;
       root = deleteNode(root,d);
       cout << endl;
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
