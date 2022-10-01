vector<vector<int>> indentity(int n) {
    vector<vector<int>> i(n, vector<int>(n, 0));
    for(int j = 0; j < n; j++) {
        i[j][j] = 1;
    }
    return i;
}
ll mod_mul(ll a, ll b){
    a = a%M; b = b%M;
    return ((a*b)%M + M)%M;
}
vector<vector<int>> mul(vector<vector<int>>& a, vector<vector<int>>& b, int mod) {
    int n = sz(a);
    vector<vector<int>> toreturn(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int ans = 0;
            for(int k = 0; k < n; k++) {
                ans += mod_mul(a[i][k] , b[k][j]);
                ans = ans%mod;
            }
            toreturn[i][j] = ans;
        }
    }
    return toreturn;
}
vector<vector<int>> expo(vector<vector<int>> &mat, int pow, int mod) {
    int n = mat.size();
    if(pow == 0) return indentity(n);
    vector<vector<int>> temp = indentity(n);
    auto Exp = expo(mat, pow/2, mod);
    if(pow % 2) {
        temp = mul(temp, mat, mod);
        vector<vector<int>> result = Exp;
        result = mul(result, result, mod);
        temp = mul(temp, result, mod);
    } else {
        vector<vector<int>> result = Exp;
        result = mul(result, result, mod);
        temp = mul(temp, result, mod);
    }
    return temp;
}