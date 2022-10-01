const int maxn = 2e5 + 5;
vecl a(maxn);
vecl t[4*maxn];
 
void merge(vecl& temp1, vecl& temp2, vecl& final){
    int i = 0, j = 0;
 
    while(i < sz(temp1) && j < sz(temp2)){
        if(temp1[i] <= temp2[j]) {
            final.pb(temp1[i]);
            i++;
        } else {
            final.pb(temp2[j]);
            j++;
        }
    }
    while(i < sz(temp1)){
        final.pb(temp1[i]);
        i++;
    }
    while(j < sz(temp2)){
        final.pb(temp2[j]);
        j++;
    }
}

void build(int ind, int tl, int tr){
    if(tl == tr){
        t[ind].pb(a[tl]);
        return;
    }
 
    int tm = (tl + tr) / 2;
    build(2 * ind, tl, tm);
    build(2 * ind + 1, tm + 1, tr);
 
    merge(t[2 * ind], t[2 * ind + 1], t[ind]);
}

int query(int ind, int tl, int tr, int l, int r, int valuetoCompare){    // query for elements strictly greater than k
    if(l > r){
        return 0;
    }
    if(l == tl && r == tr){
        return t[ind].end() - upper_bound(all(t[ind]), valuetoCompare);
    }
    int tm = (tl + tr) / 2;
    return (query(2 * ind, tl, tm, l, min(r, tm), valuetoCompare) +
            query(2 * ind + 1, tm + 1, tr, max(l, tm + 1), r, valuetoCompare));
}