const ll ninf = -1e17; const ll inf = 1e17;
struct Segtree{ int left(int v){ return v+1;}
    int right(int v, int tl, int tr){ int mid = (tl + tr)/2; return v + 2*(mid - tl + 1);}
    vll node; int sz;
    Segtree(int n) { node.assign(2*n, inf); sz = n; }
    // return min value possible
    ll query(int l, int r, int v = 0, int tl = 0, int tr = -1){
        if(tr == -1) tr = sz-1;
        if(r < tl || l > tr) return inf;
        if(l <= tl && tr <= r) return node[v];
        int mid = (tl + tr)/2;
        return min(query(l,r,left(v), tl, mid), query(l,r,right(v,tl,tr), mid+1, tr)); }
    ll update(int x, ll val, int v = 0, int tl = 0, int tr = -1){
        if(tr == -1) tr = sz-1;
        if(x < tl || x > tr) return node[v];
        if(x == tl && x == tr) return node[v] = val;
        int mid = (tl + tr)/2;
        return node[v] = min(update(x,val,left(v), tl, mid), update(x,val,right(v,tl,tr), mid+1, tr)); } };
