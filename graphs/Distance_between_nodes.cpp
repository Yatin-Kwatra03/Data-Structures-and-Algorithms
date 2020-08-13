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

custom* LCS_2(node* root)
{
    if(root == NULL) return NULL; // BASE CASE

    // Lets Start .... vroom vroom

    //check in left and right subtree

    custom* leftans  = LCS_2(root->left);
    custom* rightans = LCS_2(root->right);


    // CASE-->

    if((leftans != NULL) and (leftans->v != NULL)) return leftans; 
    // means we got our ans in left subtree

    if(rightans != NULL and rightans->v != NULL) return rightans;
    // means we got our ans in right subtree

    // if we got one element in one subtree and one in other subtree
    
     custom* ans = new custom();

    if( leftans != NULL and rightans != NULL)
    {

            ans->contains_p = true;
            ans->contains_q = true;
            ans->v = root;

            return ans;
    }


// Avoid checking by if(leftcontains p and current is root or vice versa)
// because then if it is not true then we have to check one more case
// if current is one of p and q and we didn't other one from any side
    // then seperate answer is to be returned
    // if current root is one of the p or q

    if(root->data == p)
    {
        ans->contains_p = true;

        ans->contains_q = (leftans?leftans->contains_q:false) or (rightans?rightans->contains_q:false);
        if(ans->contains_q)
        {
            ans->v = root;
        }
        return ans;
    }
    if(root->data == q)
    {
        ans->contains_q = true;

        ans->contains_p = (leftans?leftans->contains_p:false) or (rightans?rightans->contains_p:false);
        if(ans->contains_p)
        {
            ans->v = root;
        }
        return ans;
    }

    // if leftans has one element

    if(leftans != NULL)  return leftans;
    if(rightans != NULL) return rightans;

    return NULL;


}
int dlca,p1,q1;

void distance_between_nodes(node* root , int lca , int p , int q,int level)
{
    if(root == NULL) return;

    if(root->data == lca) dlca = level;
    if(root->data == p) p1 = level;
    if(root->data == q) q1 = level;

    distance_between_nodes(root->left,lca,p,q,level+1);
    distance_between_nodes(root->right,lca,p,q,level+1); 
}

void solve()
{ 
        node* root = buildTree();
       
        cin >> p >> q;

        
        preorder_print(root);
        cout << endl;


        custom* ans =  LCS_2(root);

        int lca = ans->v->data;
        cout << lca << endl;
        distance_between_nodes(root,lca,p,q,0) ;

        int dist = p1+q1-2*(dlca);
        cout << dist << endl;
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