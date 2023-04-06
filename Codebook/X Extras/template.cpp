#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define MOD2 1000000009 #define MOD3 1000000021
#define MOD4 1000000033 #define MOD5 1000000087
#define MOD6 1000000093 #define MOD7 1000000097
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
gp_hash_table<ll, ll, chash> dp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}
