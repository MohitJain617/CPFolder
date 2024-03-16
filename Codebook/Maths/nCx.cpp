// import modinv
const int maxn = 1000001;
int fact[maxn];
int invfact[maxn];
void precomp(){
	invfact[0] = fact[0] = 1;
	for(int i = 1; i < maxn; i++){
		fact[i] = mod_mul(fact[i-1], i, M);
		invfact[i] = modinv(fact[i], M);
	}
}
inline ll ncx(ll n, ll x){
	if(x > n) return 0;
	return mod_mul(fact[n], mod_mul(invfact[n-x], invfact[x], M), M);
}
