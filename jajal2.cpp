#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main() {
	vector<char> huruf;
	char inp;
	int lim, n = 0, i, j, same, yes, y, size,size1;
	string kata = "abcdabcdabcd";
	vector<char> slice, rightAns, showAns;

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
		same = 0;
	}
	
	cout<<slice.size()<<endl;
	
	for(i = 0; i < slice.size(); i++) {
		cout<<slice[i]<<" ";
	}
	
	cout<<endl;
	
	for(i = 0; i < kata.length(); i++) {
		showAns.push_back('_');
	}
	
	for(i = 0; i < kata.length(); i++) {
		cout<<showAns[i]<<" ";
	}
	cout<<endl;
	//perulangan untuk memasukkan huruf yang mungkin ada dalam kalimat
	while(rightAns.size()<slice.size()){
		cin>>inp;
		//check if the character is within the words
		for(i = 0; i < slice.size(); i++) {
			if(slice[i]==inp) {
				yes = 1;
			} else {
				if(yes==1) {
					yes = 1;
				} else {
					yes = 0;
				}
			}
		}
		//loop for checking if user input has been inputed before or not, if yes the program will tell the user
		//if not, the right answer will insert in showAnswer array
		for(i = 0; i < slice.size(); i++) {
			for(j = 0; j < rightAns.size(); j++) {
				if(rightAns[j]==inp) {
					yes=2;
				} else {
					if(yes==2) {
						yes=2;
					} else if(yes==1) {
						yes=1;
					} else {
						yes=0;
					}
				}
			}
		}
		
		if(yes==1) {
			rightAns.push_back(inp);
			for(i = 0; i < kata.length(); i++) {
				if(inp==kata[i]) {
					showAns[i]=inp;
				}			
			}
		
			cout<<endl;
			//n++;
			
			for(i = 0; i < kata.length(); i++) {
				cout<<showAns[i]<<" ";
				
			}		
			
		} else if(yes==2) {
			cout<<"Anda teah memasukkan jawaban tersebut!"<<endl;
			yes=1;	
		} else {
			cout<<"Anda salah";
		}
		yes=0;
	//	cout<<rightAns.size()<<endl;
	//	cout<<endl;
	}
	return 0;
}
