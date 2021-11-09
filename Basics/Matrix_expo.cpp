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
vector2 matrixMultiply(vector2& a, vector2& b){
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
				total += a[i][x]*b[x][j];
			}
			c[i][j] = total;
		}
	}
	return c;
}
vector2 matrixPower(vector2& a, int n){
	if(n == 1) return a;
	vector2 x = matrixPower(a,n/2);
	x = matrixMultiply(x,x);
	if(n&1){
		x = matrixMultiply(x,a);
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

int findFib(int n){
	vector2 M = {
		{1,1},
		{1,0}
	};
	vector2 base = {
		{1},
		{0}
	};
	//f(1),f(0)
	M = matrixPower(M,n-1);
	vector2 ans = matrixMultiply(M,base);
	return ans[0][0];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	cout<<findFib(n);

	return 0;
}