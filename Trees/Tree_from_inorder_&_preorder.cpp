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
void post(node* root)
{
    if(root == NULL) return;

    pre(root->left);
    pre(root->right);
    cout << root->data << " ";
}
    int n;
    int root_idx = 0;

    node* buildTree_in_pre(vii P , vii I ,int j, int k)
    {
        if(j>k) return NULL;


        int cur = P[root_idx], idx = -1;

        fo(i,j,k)
        {
            if(cur == I[i])
            {
                idx = i;
                break;
            }
        }

        root_idx++;
        node* newnode = new node(cur);
        newnode->left = buildTree_in_pre(P,I,j,idx-1);
        newnode->right = buildTree_in_pre(P,I,idx+1,k);

        return newnode;
    }


void solve()
{     
    cin >> n;

    vii P(n),I(n);

    fo(i,0,n-1) cin >> P[i];
    fo(i,0,n-1) cin >> I[i]; 

    node* root = buildTree_in_pre(P,I,0,n-1);
    post(root);
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
