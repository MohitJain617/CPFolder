#include <iostream>
#include <utility>
#include <climits>
using namespace std;
typedef long long ll;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i < b; i++)

const int M = 1000000007;
int recExp(int a, int b, int m){
	//recursive code:
	//base case
	if(b==0) return 1;
	if(b==1) return a;
	
	int x = recExp(a,b/2,m);
	x = ((ll)x*(ll)x)%m;
	if(b%2 == 1) x = ((ll)x*(ll)a)%m;
	return x;
}
/*
a^b = a*a*....*a b times 
O(b)
to do better i.e O(log b)
say 2^13: 2^(6+6+1) = 2^6.2^6.2^1 
*/

int iterExp(int a, int b, int m){
	//we shall do a bit of bit manipulation
	int multiplier = a;
	int ans = 1;
	while(b != 0){
		if(b&1) ans = ((ll)ans * (ll)multiplier)%m;
		b=b>>1;
		multiplier = ((ll)multiplier*(ll)multiplier)%m;
	}
	return ans;
}
//take a^13: 13=(1101)2
//a^(8+4+0+1)
//so first we calculate a, then a^4 then a^8 inside the loop
//we keep on mul

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a,b;
	cin>>a>>b;
	cout<<recExp(a,b,M)<<endl;
	cout<<iterExp(a,b,M);
	return 0;
}