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

class custom
{
    public:

        bool contains_p;
        bool contains_q;
        node* v;   
};


 int p,q;

custom* LCS_3(node* root)
{
    

}


void solve()
{ 
        node* root = buildTree();
       
        cin >> p >> q;

        preorder_print(root);
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