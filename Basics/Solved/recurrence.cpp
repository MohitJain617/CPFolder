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


typedef vector<vector<int>> vector2;
vector2 matrixMultiply(vector2& a, vector2& b, int M){
	int ar = a.size();
	int ac = a[0].size();
	//a is ar X ac
	int br = b.size();
	int bc = b[0].size();
	//b is br X bc

	vector2 c(ar,vector<int>(bc));
	//for each row in a, for each column in b iterate through them
	for(int i = 0; i < ar; i++){
		for(int j = 0; j < bc; j++){
			int total = 0;
			for(int x = 0; x < ac; x++){
				total += ((ll)(a[i][x]%M)*(ll)(b[x][j]%M))%M;
			}
			c[i][j] = total;
		}
	}
	return c;
}
vector2 matrixPower(vector2& a, int n, int M){
	if(n == 1) return a;
	vector2 x = matrixPower(a,n/2, M);
	x = matrixMultiply(x,x,M);
	if(n&1){
		x = matrixMultiply(x,a,M);
	}
	return x;
}

void printMatrix(vector2& a){
	int ar = a.size();
	int ac = a[0].size();
	for(int i = 0; i < ar; i++){
		for(int j = 0; j < ac; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

void findFib(int n, int& fn, int& fn1, int p){
	vector2 M = {
		{1,1},
		{1,0}
	};
	vector2 base = {
		{1},
		{0}
	};
	//f(1),f(0)
	M = matrixPower(M,n-1,p);
	vector2 ans = matrixMultiply(M,base,p);
	fn = ans[0][0];
	fn1 = ans[1][0];
}
int exp(int a, int b, int m){
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

//f(n) = f(n-1)+f(n-2)+f(n-1)*f(n-1)
//f(0) and f(1) given
//find f(n) as fast as you can
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; //find nth 
	cin>>n;
	//base
	int f0,f1;
	cin>>f0;
	cin>>f1;
	int a = f0+1;
	int b = f1+1;

	const int p = 1000000007;
	int fibn, fibn1;//fib(n) and fib(n-1)
	findFib(n,fibn,fibn1,p-1);
	a = exp(a,fibn1,p);
	b = exp(b,fibn,p);
	int gn = ((ll)a*(ll)b)%p;
	cout<<gn-1;
	return 0;
}