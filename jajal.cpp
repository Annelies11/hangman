#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<char> slice;
	string kata = "poporroporppropro";
	int same;
	cout<<kata.length()<<endl;
	cout<<kata<<endl;
	for(int i = 0; i < kata.length(); i++) {
		if(i<1) {
			slice.push_back(kata[i]);
		} else {
			for(int j = i; j >= 0; j--) {
				if(kata[i]==slice[j]) {
					same = 1;
				} else {
					if(same==1) {
						same = 1;
					} else {
						same = 0;
					}
				}
			}
			if(same==0) {
				slice.push_back(kata[i]);
			}	
		}
		//same = 0;
	}
	for(int i = 0; i < slice.size(); i++) {
		cout<<slice[i]<<" ";
	}
	cout<<endl;
	cout<<slice.size()<<endl;
	return 0;
}
