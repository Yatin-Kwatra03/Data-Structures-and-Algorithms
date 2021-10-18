
#include<bits/stdc++.h>
using namespace std;

const int N = 0; // Declare the size

class segmentTree {
public:
  int sum, mn, mx, lazy;
};

segmentTree v[4 * N];
int a[N], x, y, z;


void apply(int par, int child, int cx, int cy, int val) {
  v[child].mn += val;
  v[child].mx += val;
  v[child].sum += (cy - cx + 1) * val;
  v[child].lazy += val;
}

void propagate(int id, int cx, int cy) {
  if (v[id].lazy == 0 or cx == cy) return;
  int mid = (cx + cy) / 2;
  apply(id, 2 * id, cx, mid, v[id].lazy);
  apply(id, 2 * id + 1, mid + 1, cy, v[id].lazy);
  v[id].lazy = 0;

}

void build(int id, int cx, int cy) {
  if (cx == cy) {
    v[id].sum = v[id].mn = v[id].mx = a[cx]; // assign the required value
    v[id].lazy = 0;
    return;
  }
  int mid = (cx + cy) / 2;
  build(2 * id, cx, mid);
  build(2 * id + 1, mid + 1, cy);

  // recalculate the segments results

  v[id].mn = min(v[2 * id].mn, v[2 * id + 1].mn);
  v[id].mx = max(v[2 * id].mx, v[2 * id + 1].mx);
  v[id].sum = v[2 * id].sum + v[2 * id + 1].sum;
  v[id].lazy = 0;
}

void upd(int id, int cx, int cy) {
  if (y < cx or x > cy) return;

  propagate(id, cx, cy);

  if (x <= cx and cy <= y) {
    v[id].mn += z;
    v[id].mx += z;
    v[id].sum += (cy - cx + 1) * z;
    v[id].lazy += z;
    return;
  }
  int mid = (cx + cy) / 2;
  upd(2 * id, cx, mid);
  upd(2 * id + 1, mid + 1, cy);

  v[id].mn = min(v[2 * id].mn, v[2 * id + 1].mn);
  v[id].mx = max(v[2 * id].mx, v[2 * id + 1].mx);
  v[id].sum = v[2 * id].sum + v[2 * id + 1].sum;
}

int qry(int id, int cx, int cy) {
  if (y < cx or x > cy) return 0; // return the needed

  propagate(id, cx, cy);

  if (x <= cx and cy <= y) return v[id].mx; // change it
  int mid = (cx + cy) / 2;
  auto L = qry(2 * id, cx, mid);
  auto R = qry(2 * id + 1, mid + 1, cy);

  // merge the results
  int ans = max(L, R);
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}
