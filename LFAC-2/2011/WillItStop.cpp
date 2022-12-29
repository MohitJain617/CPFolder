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


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    while((n%2) == 0) n /= 2ll;
    if(n == 1){
        cout<<"TAK\n";
    } else {
        cout<<"NIE\n";
    }
    
    return 0;
}
