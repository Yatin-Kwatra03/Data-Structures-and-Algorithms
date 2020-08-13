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

            if(front_node->left->data != -1)  q.push(front_node->left);
            if(front_node->right->data != -1) q.push(front_node->right);

        }
    }



node* buildTree_from_level_traversal()
{  
     queue<node*>q;
     node* root = NULL;
     int d;

    while(scanf("%d",&d) != EOF)
    {
        
    node* newnode = new node(d);
    if(root == NULL)
    {
        root = newnode;
    }
    else if(q.front()->left == NULL) q.front()->left = newnode;
    else
    {
        q.front()->right = newnode; 
       // cout << newnode->data <<" ";
        q.pop();    // we are using the right node it means left node 
                    // is already use and this node can't accomodate any
                    // more children
    }


   if(newnode->data != -1) q.push(newnode);
}

return root;

}

void right_view(node* root)
{
    vector<int>v;

    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* f = q.front();
        q.pop();

        if(f == NULL)
        {
            v.pb(-1);
            if(!q.empty()) q.push(NULL);

            continue;
        }

       //  cout << f->data << " ";
         v.pb(f->data);
       
        if(f->left->data != -1)  q.push(f->left);
        if(f->right->data != -1) q.push(f->right);
    }

    fo(i,0,v.size()-2)
    {
        if( v[i+1] == -1 ) cout << v[i] << " ";
    }
    
}


#define inf 1e9
vii v1,v2;
int maxlevel = -inf , minlevel = inf;

void dfs(node* root, int level)
{
    if(root->data == -1) return;
    
    if(level > maxlevel) 
    {
        maxlevel = level;
        v1.pb(root->data);
    }
    else if(level < minlevel)
    {
        minlevel = level;
        v2.pb(root->data);
    }


    dfs(root->left,level-1);
    dfs(root->right,level+1);
    
}
void right_view_dfs(node* root)
{

    dfs(root,0);
}






void top_view_dfs(node* root)
{
    dfs(root,0);
}
void pre(node* root)
{
   // cout << 'y';
    if((root->data) == -1) return;
   // cout << "yeah\n";
   cout << root->data << " ";

    pre(root->left);
    pre(root->right);

}


void solve()
{ 
       
        node* root = buildTree_from_level_traversal();
     
      //  right_view(root);
       //right_view_dfs(root);
        top_view_dfs(root);

      rfo(i,v2.size()-1,0) cout << v2[i] << " ";
      fo(i,0,v1.size()-1) cout << v1[i] << " ";
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