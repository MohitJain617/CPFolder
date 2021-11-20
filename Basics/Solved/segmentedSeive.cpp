#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <utility>
#include <climits>
using namespace std;
typedef long long ll;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i < b; i++)


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//generate prime numbers from 1 to 31623
	bool isPrime[31624];
	for(int i = 0; i < 31624; i++){
		isPrime[i] = true;
	}
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i < 31624; i++){
		if(isPrime[i] == true){
			for(int j = i*i; j < 31624; j += i){
				isPrime[j] = false;
			}
		}
	}
	vector<int> primes(0);
	for(int i = 2; i < 31624; i++){
		if(isPrime[i] == true) primes.PB(i);
	}
	int T;
	cin>>T;
	while(T--){
		int m,n;
		cin>>m>>n;
		vector<bool> nums(n-m+1,true);
		//index + m gives the number
		for(int i = 0; i < primes.size(); i++){
			if(primes[i] * primes[i] > n) break;
			int j = m/primes[i];
			if(j*primes[i] < m) j++;
			for(;j*(ll)primes[i] <= n ; j++){
				int value = j * primes[i];
				nums[value-m] = false;
			}
		}
		for(int i = 0; i < primes.size(); i++){
			if(primes[i] > n) break;
			if(primes[i] >= m) nums[primes[i] - m] = true;
		}
		if(m == 1) nums[0] = false;
		for(int i = 0; i < nums.size(); i++){
			if(nums[i] == true) cout<<i+m<<"\n";
		}
		cout<<"\n";
	}

	return 0;
}