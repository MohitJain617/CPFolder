const int maxn = 100000;
int lp[maxn+1], mobius[maxn+1];
int twopow[maxn+1];
vector<int> primes(0);
void lsieve(){
	lp[1] = 1;
	mobius[1] = 1;
	for(int i = 2; i <= maxn; i++){
		if(lp[i] == 0){
		 lp[i] = i;
		 primes.push_back(i);
		}
		for(int j = 0; (j<primes.size()) && primes[j]<=lp[i] && i*primes[j] <= maxn; j++){
		 lp[i*primes[j]] = primes[j];
		}
		if(lp[i] == i) mobius[i] = -1;
		else {
		 int x = i/lp[i];
		 if(x%lp[i] == 0) mobius[i] = 0;
		 else mobius[i] = mobius[x]*mobius[lp[i]];
		}
	}}