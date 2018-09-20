#include <iostream>
#include <string>

using namespace std;

int main(){
	// all numbers in the given sequence should appear an equal number of times
	// but they do not. Remove one, add one, or remove one and add one,
	// in order to make all numbers appear an equal number of times

	// N = number of numbers
	// K = range of numbers (numbers will range from 1-K)
	int N,K;
	cin >>K>>N;
	int occupancy[K+1];

// initialize matrix to 0
	for (int i = 0; i<= K; i++){
		occupancy[i] = 0;
	}
		// determine how many of each type of number there are
	for (int i = 0; i< N; i++){
		int currNum;
 		cin>>currNum;
		occupancy[currNum]++;
	}

// determine the expected number of times each number should appear
	int expected = N%K<2? N/K:N/K +1;
	int found = 0;
	int foundMore = 0;
	int foundLess = 0;
	if (N%K == 1){
	// ONE TOO MANY
		for (int i = 1; i<=K; i++){
			if(occupancy[i]!=expected){
					if(found||occupancy[i]!=expected +1){
						cout<<'*'<<'\n';
						return 0;
					}
					found = i;
				}
		}
		if (found){
			cout<<'-'<<found<<'\n';
		}
		else{
		cout<<'*'<<'\n';
		}
	}
	else if (N%K == K - 1){
	// ONE TOO FEW
		for (int i = 1; i<=K; i++){
			if(occupancy[i]!=expected){
					if(found||occupancy[i]!=expected -1){
						cout<<'*'<<'\n';
						return 0;
					}
					found = i;
				}
		}
		if (found){
			cout<<'+'<<found<<'\n';
		}
		else{
		cout<<'*'<<'\n';
		}
	}

	else if (N%K == 0){
	// REPLACE SOMETHING
		for (int i = 1; i<=K; i++){
			if(occupancy[i]!=expected){
					if(occupancy[i] == expected+1){
						if(foundMore){
							cout<<'*'<<'\n';
							return 0;
							}
						foundMore = i;
					}
					else if (occupancy[i] == expected -1){
						if(foundLess){
							cout<<'*'<<'\n';
							return 0;
							}
						foundLess = i;
					}
					else{
						cout<<'*'<<'\n';
						return 0;
					}
				}
		}
		if (foundMore && foundLess){
			cout<<'-'<<foundMore<<' '<<'+'<<foundLess<<'\n';
		}
		else{
		cout<<'*'<<'\n';
		}
	}
	else{
	// NO SOLUTION
	cout<< '*'<<'\n';

	}
	return 0;
}
