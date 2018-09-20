#include <iostream>
#include <string>

using namespace std;

int main(){
	int C,B,P,CR,BR,PR;
	cin >> C>>B>>P>>CR>>BR>>PR;
	int chickenDef =  CR - C > 0 ? CR - C : 0;
	int beefDef = BR - B > 0 ? BR - B : 0;
	int pastaDef = PR - P > 0 ? PR - P : 0;

	cout<<chickenDef + beefDef + pastaDef<<'\n';
	
	return 0;
}
