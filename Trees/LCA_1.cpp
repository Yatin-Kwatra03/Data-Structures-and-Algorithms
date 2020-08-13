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

 unordered_map<node*,node*>parent;


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

    void preorder_print(node* root,pair<node*,node*>&P, int p , int q)
    {
        if(root == NULL) return;

        if(root->data == p) P.ff = root;
        if(root->data == q) P.ss = root;
      //  cout << root->data << " ";

     if(root->left != NULL)   parent[root->left] = root;
     if(root->right != NULL)  parent[root->right] = root;

        preorder_print(root->left,P,p,q);
        preorder_print(root->right,P,p,q);
    }



node* LCA_1(node* root , pair<node*,node*>P)
{
    list<node*>L1,L2;

    node* temp = P.ff;

    while(temp != root)
    {
        L1.push_front(temp);
        temp = parent[temp];
    }
    L1.push_front(temp);

    temp = P.ss;

    while(temp != root)
    {
        L2.push_front(temp);
        temp = parent[temp];
    }

    L2.push_front(temp);

    node* prev = root;
    node* L2_front;
    for(auto x : L1)
    {
        L2_front = L2.front();

        if(L2_front == x) prev = x;
        else break;

        L2.pop_front();

        if(L2.empty()) return prev;
    }
    return prev;
}

void solve()
{ 
        node* root = buildTree();
        int p,q;
        cin >> p >> q;
     pair<node*,node*>P;
     preorder_print(root,P,p,q);


     cout << " val : " << P.ff->data << " " << P.ss->data << endl;
        parent[root] = root;

        
/*
        for(auto x : parent)
        {
            cout << " Parent " << x.ff->data << " : " << x.ss->data << endl; 
        }
*/
        cout << "Lowest Common Ancestor of " << p << " and " << q << " is " << LCA_1(root,P)->data << endl;
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