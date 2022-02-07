#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <stdlib.h>
/*
Program Hangman Game
pemain bertugas menebak kata berbahasa indonesia dengan mengisi huruf-huruf penyusunnya,
jika tebakannya salah, gambar akan semakin lengkap dan huruf yang salah akan muncul sebagai referensi
jika gambar orang tergantung muncul secara penuh maka pemain kalah
jika kata yang di tebak berhasil sebelum gambar tercetak penuh maka pemain menang
*/
using namespace std;

class Game {
	private: 
		string kata[8] = {"perjuangan", "keadilan", "optimis", "merintih", "amandemen", "cakrawala", "moralitas", "susunan"};
		int jmlKata = sizeof(kata)/sizeof(kata[0]);
	public:
		int a, ke, i, j, jumlahSalah = 0, jumlahBenar = 0, same, yes;		
		char huruf;
		vector<int> benar;
		vector<char> hurufSalah, slice, hurufBenar, showAns;
		
		void tebak() {
			srand(time(0));  // Initialize random number generator.
			ke = (rand() % jmlKata);
			//cout<<kata[ke]<<endl;
			
			for(i = 0; i < kata[ke].length(); i++) {
				showAns.push_back('_');
			}
			
			checkLength();
			
			while(hurufBenar.size()<slice.size()) {

				if(jumlahSalah==0) {
					chance0();
				} else {
					wrong();
				}
				
				if(yes==2) {					//mengecek apakah player memasukkan huruf yang sama dengan yang telah dimasukkan sebelumnya
					cout<<"Anda telah memasukkan jawaban tersebut!"<<endl;
					yes=1;
				}
				
				for(i = 0; i < showAns.size(); i++) {	//mengeluarkan susunan huruf yang benar
					cout<<showAns[i]<<" ";
				}
				
				cout<<endl;
				cout<<"\nTebakanmu : "; 
				cin>>huruf;								//player memasukkan huruf yang harus ditebak dalam game
				checkIn();								//mengecek huruf yang telah dimasukkan player
				
				if(yes==0) {
					hurufSalah.push_back(huruf);
					jumlahSalah++;
					wrong();
				} 
				system("CLS");	
			}
			
			if(jumlahSalah!=6){
				hore();
				cout<<"Jawaban yang benar : "<<kata[ke]<<endl;
				cout<<"Selamat anda menang!"<<endl;
			}
		}		
		
		void wrong() {
			if(jumlahSalah==1) {
				chance1();
			} else if(jumlahSalah==2) {
				chance2();
			} else if(jumlahSalah==3) {
				chance3();
			} else if(jumlahSalah==4) {
				chance4();
			} else if(jumlahSalah==5) {
				chance5();
			} else if(jumlahSalah==6) {
				chance6();
			} else if(jumlahSalah>6) {
			//	chance7();
				andaKalah();
			} 
			
			cout<<"Hati-hati anda salah!"<<endl;
			cout<<"Huruf yang salah : ";
			for(i = 0; i < hurufSalah.size(); i++) {
				cout<<hurufSalah[i]<<" ";
			}
			cout<<endl;
		}
	
		void checkIn() {
			yes = 0;
			//checking if the character input is within the word
			for(i = 0; i < slice.size(); i++) {
				if(slice[i]==huruf) {
					yes = 1;
				} else {
					if(yes==1) {
						yes = 1;
					} else {
						yes = 0;
					}
				}
			}
			//checking if the character input has been inputted before or not
			for(i = 0; i < slice.size(); i++) {
				for(j = 0; j < hurufBenar.size(); j++) {
					if(hurufBenar[j]==huruf) {
						yes=2;		//if yes, player will receive a warning 
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
			
			if(yes==1) {						//if the character is correct, the character will inserted to hurufBenar array, and the character on showAns
				hurufBenar.push_back(huruf);	//will be replaced with the right character
				for(i = 0; i < kata[ke].length(); i++) {
					if(huruf==kata[ke][i]) {
						showAns[i]=huruf;
					}			
				}
		
				cout<<endl;
		
			
			} 
			
		}
		
		void checkLength() {
			for(int i = 0; i < kata[ke].length(); i++) {
				if(i<1) {
					slice.push_back(kata[ke][i]);
				} else {
					for(int j = i; j >= 0; j--) {
						if(kata[ke][i]==slice[j]) {
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
						slice.push_back(kata[ke][i]);
					}	
				}
				same = 0;
			}
		}
		void chance0() {
			cout<<"  _____  "<<endl;
			cout<<" |     |  "<<endl;
			cout<<" |   	"<<endl;
			cout<<" |   	"<<endl;
			cout<<" |   	"<<endl;
			cout<<" |  		"<<endl;
			cout<<" |   	"<<endl;
			cout<<" |_______"<<endl;
			cout<<" --------"<<endl;
		//	cout<<jmlKata<<endl;
		}
		void chance1() {
			cout<<"  _____  "<<endl;
			cout<<" |     |  "<<endl;
			cout<<" |    ( )"<<endl;
			cout<<" |   	"<<endl;
			cout<<" |   	"<<endl;
			cout<<" |  		"<<endl;
			cout<<" |   	"<<endl;
			cout<<" |_______"<<endl;
			cout<<" --------"<<endl;
		}
		
		void chance2() {
			cout<<"  _____  "<<endl;
			cout<<" |     |  "<<endl;
			cout<<" |    ( )"<<endl;
			cout<<" |     |	"<<endl;
			cout<<" |   	"<<endl;
			cout<<" |  		"<<endl;
			cout<<" |   	"<<endl;
			cout<<" |_______"<<endl;
			cout<<" --------"<<endl;
		}
		
		void chance3() {
			cout<<"  _____  "<<endl;
			cout<<" |     |  "<<endl;
			cout<<" |    ( )"<<endl;
			cout<<" |    /|	"<<endl;
			cout<<" |   	"<<endl;
			cout<<" |  		"<<endl;
			cout<<" |   	"<<endl;
			cout<<" |_______"<<endl;
			cout<<" --------"<<endl;
		}
		
		void chance4() {
			cout<<"  _____  "<<endl;
			cout<<" |     |  "<<endl;
			cout<<" |    ( )"<<endl;
			cout<<" |    /|\\	"<<endl;
			cout<<" |   	"<<endl;
			cout<<" |  		"<<endl;
			cout<<" |   	"<<endl;
			cout<<" |_______"<<endl;
			cout<<" --------"<<endl;
		}
		
		void chance5() {
			cout<<"  _____  "<<endl;
			cout<<" |     |  "<<endl;
			cout<<" |    ( )"<<endl;
			cout<<" |    /|\\	"<<endl;
			cout<<" |     |	"<<endl;
			cout<<" |  		"<<endl;
			cout<<" |   	"<<endl;
			cout<<" |_______"<<endl;
			cout<<" --------"<<endl;
		}
		
		void chance6() {
			cout<<"  _____  "<<endl;
			cout<<" |     |  "<<endl;
			cout<<" |    ( )"<<endl;
			cout<<" |    /|\\	"<<endl;
			cout<<" |     |	"<<endl;
			cout<<" |    /	"<<endl;
			cout<<" |   	"<<endl;
			cout<<" |_______"<<endl;
			cout<<" --------"<<endl;
		}
		
		void andaKalah() {
			system("CLS");
			cout<<"  _____  "<<endl;
			cout<<" |     |      I'm Dead..."<<endl;
			cout<<" |    ( )"<<endl;
			cout<<" |    /|\\	"<<endl;
			cout<<" |     |	"<<endl;
			cout<<" |    / \\	"<<endl;
			cout<<" |   	"<<endl;
			cout<<" |_______"<<endl;
			cout<<" --------"<<endl;
			cout<<"==========================="<<endl;
			cout<<"=======Anda kalah!========="<<endl;
			cout<<"==========================="<<endl;
			cout<<"\nKata yang benar adalah : "<<kata[ke]<<endl;
			cout<<endl;
			cout<<"Input anything to quit...";
			cin>>huruf;
			exit(3);
		}
		
		void hore() {
			cout<<"\n\n"<<endl;
			cout<<"     ( )		Thanks..."<<endl;
			cout<<"     /|\\	 For saving me...:)"<<endl;
			cout<<"      |	"<<endl;
			cout<<"     / \\	"<<endl;
			cout<<"\n\n"<<endl;
		}
};

void hangman() {
	cout<<"  _____   "<<endl;
	cout<<" |    |    H A N G M A N"<<endl;
	cout<<" |   ( )   G A M E"<<endl;
	cout<<" |   /|\\   ============="<<endl;
	cout<<" |    |    Tebak suatu kata dalam bahasa Indonesia. Semua kata berupa huruf kecil, satu kata, tanpa spasi."<<endl;
	cout<<" |   / \\   Dengan jumlah huruf berupa underscore yang diberikan."<<endl;
	cout<<" |         Setiap tebakan yang salah, bagian-bagian tubuh korban akan muncul."<<endl;
	cout<<" |_______  Jika tebakan anda benar sebelum anggota tubuh penuh, anda menang."<<endl;
	cout<<" --------  Jika anggota tubuh lengkap sebelum anda mampu menebak kata tersebut, anda kalah.\n"<<endl;
}


int main() {
	
	string siap = "y";
	int soal;
	hangman();
	cout<<"Anda siap? y/n\nJawaban anda : ";
	cin>>siap;
	
	if(siap!="y") {
		system("CLS");
		cout<<"Good Bye!!"<<endl;
		cout<<"Input anything to quit..."<<endl;
		cin>>soal;
		return 0;
	}
	
	system("CLS");
  	Game person1;
  	person1.tebak();
  	
  	
  	cout<<"\nInput anything to quit..."<<endl;
	cin>>soal;
	return 3;
}
