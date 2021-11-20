//coders have 2 ratings x and y
//coder1 is rated more than coder2 if atleast one of x,y is strictly greater and the other is greater
//i.e x1 > x2 and y1 >= y2  or  x1 >= x2 and y1 > y2

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <utility>
#include <climits>
using namespace std;
typedef long long ll;

class Coder{
	public:
	int x; int y; int index; int ans;
	Coder(int x, int y, int r):x(x),y(y),index(r),ans(0){}
	Coder():x(0),y(0),index(0),ans(0){}
	// Coder(Coder &c){
	// 	x = c.x;
	// 	y = c.y;
	// 	index = c.index;
	// 	ans = c.ans;
	// }
};

bool comparator(Coder c1, Coder c2){
	if(c1.x == c2.x){
		return c1.y < c2.y;
	}
	return c1.x < c2.x;
}

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i < b; i++)
vector<Coder> Merge(vector<Coder>& left, vector<Coder>& right){
	int ls = left.size();
	int rs = right.size();
	vector<Coder> vec(ls+rs);
	int i = 0,j = 0;  //left and right indexes respectively
	int k = 0;  //vec index
	while((i < ls) && (j < rs)){
		if(left[i].y < right[i].y){
			vec[k++] = left[i++];
		} else if((left[i].y == right[i].y) && (left[i].x < right[i].x)){
			vec[k++] = left[i++];
		} else {
			right[j].ans += i;
			vec[k++] = right[j++];
		}
	}
	while(i < ls){
		vec[k++] = left[i++];
	}
	while(j < rs){
		right[j].ans += i;
		vec[k++] = right[j++];
	}
	return vec;
}


//divide and conquer
vector<Coder> mergeSort(vector<Coder>& vec){
	int len = vec.size();
	if(len == 1) return vec;
	int lsize = len/2;
	int rsize = len - lsize;
	vector<Coder> left(lsize);
	vector<Coder> right(rsize);
	int k = 0;
	for(int i = 0; i < lsize; i++){
		left[i] = vec[k++];
	}
	for(int i = 0; i < rsize; i++){
		right[i] = vec[k++];
	}
	left = mergeSort(left);
	right = mergeSort(right);
	return Merge(left,right);
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<Coder> vec(0);
	for(int i = 0; i < n; i++){
		int x; int y; 
		cin>>x>>y;
		Coder c(x,y,i);
		vec.PB(c);
	}
	sort(vec.begin(),vec.end(),comparator);
	//sorted on the basis of x
	
	//now for each index we have to find how many behind it have y <= current.y
	vector<Coder> v = mergeSort(vec);
	vector<int> ans(n,0);
	for(int i = 0; i < n; i++){
		ans[v[i].index] = v[i].ans;
	}
	for(int i = 0; i < n; i++){
		cout<<ans[i]<<" ";
	}

	return 0;
}

/*
Algorithm:
sort on the basis of x first, if x is equal then y greater will have greater preference
then mergesort to find the number of elements before a given element that have their y <= current y

or you can use fenwick tree to count this if y ranges from 1 to 100001
8
1798 1832
862 700
1075 1089
1568 1557
2575 1984
1033 950
1656 1649
1014 1473

ans: 6 0 2 4 7 1 5 1
*/