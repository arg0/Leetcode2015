#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> twoSum(vector<int> &numbers, int target);

int main(){
	vector<int> numbers={2, 7, 11, 15};
	int target=9;
	vector<int> result=twoSum(numbers,target);
	cout<<result[0]<<" "<<result[1]<<endl;
	return 0;
}

vector<int> twoSum(vector<int> &numbers, int target) {
	unordered_map<int,int> hash;
	vector<int> res;
	for(int i=0;i<numbers.size();i++){
		int numberToFind=target-numbers[i];
		if(hash.find(numberToFind)!=hash.end()){
			res.push_back(hash[numberToFind]+1);
			res.push_back(i+1);
			return res;
		}
		hash[numbers[i]]=i;
	}
	return res;
		
}

