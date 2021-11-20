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

class FenwickTree{
private:
	int size;
	vector<int> arr;
public:
	FenwickTree(int size){
		//precomputation:
		this->size = size+1;
		for(int i = 0; i < size+1; i++){
			arr.push_back(0);
		}
		for(int i = 1; i <size; i++){
			update(i,1);
		}
	}

	void printTree(){
		for(auto i: arr){
			cout<<i<<" ";
		}
	}
	//update the index i given delta
	void update(int i, int delta){
		while(i < size+1){
			arr[i] += delta;
			i += (i&(-i));
		}
	}
	//compute the prefix sum value [1 to i]
	int sumUpto(int i){
		int s = 0;
		while(i > 0){
			s += arr[i];
			i -= i&(-i);
		}
		return s;
	}
	//compute the preffix sum value [i+1 to j]
	int rangeSum(int i, int j){
		return sumUpto(j)-sumUpto(i);
	}
};


//TO-DO
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin>>T;
	while(T--){
		int m,r;
		cin>>m>>r;
		FenwickTree fw(m+1);
		for(int i = 0; i < r; i++){
			int q;
			cin>>q;
			int value = fw.sumUpto(q-1);
			//value - 1 books were above it
			//so the range has a change from 1 to value-1 after q gets updated
			cout<<value-1<<" ";
			fw.update(1,1);
			
		}
		cout<<"\n";
	}
	return 0;
}