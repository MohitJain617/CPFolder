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

class Triplet{
public:
	int gcd;
	int x; 
	int y;
	//given a, b: gives x, y such that ax+by=gcd(a,b) 
	Triplet(int gcd, int x, int y):gcd(gcd),x(x),y(y){}
};

int gcd(int a, int b){
	while(b != 0){
		int temp = a;
		a = b;
		b = temp%b;
	}
	return a;
	//Recursive solution
	//if(b == 0) return a; return gcd(b,a%b);
}
Triplet gcdExtended(int a, int b){
	if(b == 0){
		return Triplet(a,1,0);
	}
	Triplet prev = gcdExtended(b,a%b);
	Triplet curr(prev.gcd,prev.y,prev.x-(a/b)*prev.y);
	return curr;
}
//ax+by = gcd(a,b) = gcd(b,a%b) = bx1 + (a%b) y1
//bx1 + (a-(a/b)*b)y1 = a(y1) + b(x1-(a/b)y1)
//x = y1, y = x1-(a/b)y1

int moduloinverse(int a, int m){
	Triplet t = gcdExtended(a,m);
	if(t.gcd != 1) return INT_MIN;
	else{
		return ((t.x)%m+m)%m; //x = b 
	}
}
//positive modulo inverse of a wrt m = (ab)%m = 1
//ab-1 = mq, ab+mQ = 1
//by euclids algorithms gcd(a,m) = 1 and x = b = mod inverse value

int modulodivide(int a, int b, int m){
	int inv = moduloinverse(b,m);  //see if inverse of modulo exist
	if(inv < 0){
		return INT_MIN;
	} else {
		return ((a%m)*(inv)+m)%m;
	}
}
//calculates (a/b)%m if it exists
//equal to c where (bc)%m = a%m
//c = (a*inv(b))%m

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a,b,d;
	cin>>a>>b>>d;
	//special cases:
	if(d == 0) cout<<1;
	else {
		int y1 = modulodivide(d,b,a);

		if((y1 < 0) || ((d-b*y1)%a!=0)) cout<<0;
		else {
			int n = ((d/b) - y1)/a;
			cout<<n+1;
		}
	}
		
	return 0;
}

