
// AC BAKSHI RABBA

#include <bits/stdc++.h>
#define ll                      long long
#define ld                      long double
#define ull                     unsigned long long
#define FIO                     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl                    "\n"
#define fo(i,a,b)               for(int i = a; i<=b ; i++)
#define rfo(i,a,b)              for(int i = a; i>=b ; i--)
#define vii                      vector<int>
#define vll                     vector<ll>
#define pq                      priority_queue
#define uom                     unordered_map
#define all(v)                  v.begin(),v.end()
#define mp                      make_pair
#define pb                      push_back
#define pob                     pop_back
#define ff                      first
#define ss                      second
#define pii                     pair<int,int>
#define pll                     pair<long,long>
#define mll                     map<ll,ll>
#define mii                     map<int,int>
#define vvii                    vector<vii>
#define vvll                    vector<vll>
#define mod                     1000000007
#define pi                      3.1415926535897932384626433832795
// #define node                    Node

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

    char data;
    int cnt;
    node *left;
    node *right;

    node(char d, int fr)
    {
        data = d;
        cnt = fr;
        left = right = NULL;
    }

};

void pre(node *root, string cur, vector<string> &ans)
{
    if (!root) return;

    if (root->data != '$')
    {
        ans.pb(cur);
    }

    pre(root->left, cur + '0', ans);
    pre(root->right, cur + '1', ans);

}

class cmp
{
public:

    bool operator() (node *a , node *b)
    {
        return a->cnt > b->cnt;
    }
};

void solve()
{
    string s;
    cin >> s;

    int n = s.length();

    vii freq(n);
    fo(i, 0, n - 1) cin >> freq[i];

    pq<node*, vector<node*>, cmp>q;

    fo(i, 0, n - 1)
    {
        node *add = new node(s[i], freq[i]);
        q.push(add);
    }

    node *root = NULL;

    while (q.size() > 1)
    {
        node *cur1 = q.top();
        q.pop();
        node *cur2 = q.top();
        q.pop();

        node *dad = new node('$', cur1->cnt + cur2->cnt);
        q.push(dad);

        dad->left = cur1;
        dad->right = cur2;

        if (q.size() == 1) root = dad;
    }

    vector<string>ans;

    pre(root, "", ans);

    for (auto &i : ans) cout << i << " ";
    cout << endl;
}
int main() {

    FIO
    INPUT();

    int t;
    t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}