#include <iostream>
#include <string>

using namespace std;

int main(){
	
	int N,K;
	cin >>K>>N;
	int occupancy[K+1];
	for (int i = 0; i<= K; i++){
		occupancy[i] = 0;
	}
	for (int i = 1; i<= K; i++){
		//cout<<i<<'-'<<occupancy[i]<<'\n';
	}
	for (int i = 0; i< N; i++){
		int currNum;
 		cin>>currNum;
		occupancy[currNum]++;
	}
	//cout<<"See occupancies\n";

	for (int i = 1; i<= K; i++){
		//cout<<i<<'-'<<occupancy[i]<<'\n';
	}
	int expected = N%K<2? N/K:N/K +1;
	int found = 0;
	int foundMore = 0;
	int foundLess = 0;
	if (N%K == 1){
	// ONE TOO MANY
		for (int i = 1; i<=K; i++){
			if(occupancy[i]!=expected){
					if(found||occupancy[i]!=expected +1){
						//cout<<__LINE__<<'\n';
						cout<<'*'<<'\n';
						return 0;
					}
					found = i;
				} 
		}
		if (found){
			cout<<'-'<<found<<'\n';
						//cout<<__LINE__<<'\n';
		}
		else{
		cout<<'*'<<'\n';
						//cout<<__LINE__<<'\n';
		}
	}
	else if (N%K == K - 1){
	// ONE TOO FEW
		for (int i = 1; i<=K; i++){
			if(occupancy[i]!=expected){
					if(found||occupancy[i]!=expected -1){
						cout<<'*'<<'\n';
						//cout<<__LINE__<<'\n';
						//cout<<i<<'\n';
						return 0;
					}
					found = i;
				} 
		}
		if (found){
			cout<<'+'<<found<<'\n';
						//cout<<__LINE__<<'\n';
		}
		else{
		cout<<'*'<<'\n';
						//cout<<__LINE__<<'\n';
		}
	}

	else if (N%K == 0){
	// REPLACE SOMETHING
		for (int i = 1; i<=K; i++){
			if(occupancy[i]!=expected){
					if(occupancy[i] == expected+1){
						if(foundMore){
							cout<<'*'<<'\n';
						//cout<<__LINE__<<'\n';
							return 0;
							}
						foundMore = i;
					}
					else if (occupancy[i] == expected -1){	
						if(foundLess){
							cout<<'*'<<'\n';
						//cout<<__LINE__<<'\n';
							return 0;
							}
						foundLess = i;
					}
					else{
						cout<<'*'<<'\n';
						//cout<<__LINE__<<'\n';
						return 0;
					}
				} 
		}
		if (foundMore && foundLess){
			cout<<'-'<<foundMore<<' '<<'+'<<foundLess<<'\n';
		}
		else{
		cout<<'*'<<'\n';
						//cout<<__LINE__<<'\n';
		}
	}
	else{
	// NO SOLUTION
	cout<< '*'<<'\n';

	}
	return 0;
} 
