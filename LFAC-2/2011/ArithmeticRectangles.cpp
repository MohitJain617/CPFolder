/*
	Score: 40/100
	TODO: Handle MLE somehow.
*/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<long long>> vvll;
typedef vector<vector<bool>> vvb;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

#define F first
#define S second
#define PB push_back
#define sz(x) (int)(x).size()

const int M = 1e9 + 7;
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}

ll largestSquare(vll& arr, int start, int end){
    // calculate next lesser element and previous lesser element.
    stack<int> st;
    int len = end-start+1;
    vector<int> plr(len), nlr(len);
    for(int i = start; i <= end; i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            int idx = st.top(); st.pop();
            nlr[idx-start] = i;
        }
        st.push(i);
    }
    while(!st.empty()){
        nlr[st.top()-start] = end+1; st.pop();
    }
    for(int i = end; i >= start; i--){
        while(!st.empty() && arr[st.top()] > arr[i]){
            int idx = st.top(); st.pop();
            plr[idx-start] = i;
        }
        st.push(i);
    }
    while(!st.empty()){
        plr[st.top()-start] = start-1; st.pop();
    }
    
    int bestsq = 0;
    for(int i = start; i <= end; i++){
        bestsq = max(bestsq, (int)(arr[i] * (nlr[i-start] - plr[i-start] - 1)));
    }
    return bestsq;
}

void solve(){
    int n, m; cin>>n>>m;
    vvll grid(n, vll(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>grid[i][j];
        }
    }
    vvll diff(n, vll(m, INT_MAX));
    vvll rlen(n, vll(m, 1));
    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j < m; j++){
            diff[i][j] = grid[i+1][j] - grid[i][j];
            if(diff[i+1][j] == diff[i][j]){
                rlen[i][j] = rlen[i+1][j] + 1;
            } else {
                rlen[i][j] = 2;
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        // width = 1
        for(int j = 0; j < m; j++){
            ans = max(ans, rlen[i][j]);
        }
        
        // width > 1
        int l = 0;
        while(l < m-1){
            int r = l+1;
            int d = grid[i][r] - grid[i][l];
            int d2 = diff[i][r] - diff[i][l];
            while(r < m){
                if((grid[i][r] - grid[i][r-1] == d) and (diff[i][r] - diff[i][r-1] == d2)){
                    r++;
                } else {
                    break;
                }
            }
            // l to r-1 is a valid ap sequence
            ans = max(ans, largestSquare(rlen[i], l, r-1));
            l = r-1;
        }
        l = 0;
        while(l < m-1){
            int r = l+1;
            int d = grid[i][r] - grid[i][l];
            while(r < m){
                if(grid[i][r] - grid[i][r-1] == d){
                    r++;
                } else {
                    break;
                }
            }
            // l to r-1 is a valid ap sequence
            ans = max(ans, (ll) (r-l));
            l = r-1;
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
