#include<iostream>
#include<vector>
#include<windows.h>
using namespace std;
vector<string> homeWorks;
void outBar(int amount) {
	for(int i = 0; i < amount; i++) {
		cout << "=";
	}
	cout << endl;
}
void bai6dot4() {
	int n;
	cout << "N = ";
	cin >> n;
	float s = 0.0;
	for(int i = 1; i <= n; i++) {
		s += 1.0 / float(3*i);
	}
	cout << "S = " << s << endl;
	system("pause");
}
void bai6dot3() {
	int n;
	cout << "N = ";
	cin >> n;	
	float s = 0.0;
	for(int i = 1; i <= n; i++) {
		s += 1.0 / float(i);
	}
	cout << "S = " << s << endl;
	system("pause");
}
void bai6dot2() {
	int n, s;
	cout << "N = ";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		s += 3*i - 1;
	}
	cout << "S = " << s << endl;
	system("pause");
}
void bai6dot1() {
	int n, s;
	cout << "N = ";
	cin >> n;
	for(int i = 1; i <= n; i++) {
		s += i;
	}
	cout << "S = " << s << endl;
	system("pause");
}
void loadHomeWorks() {
	homeWorks.push_back("6.1");
	homeWorks.push_back("6.2");
	homeWorks.push_back("6.3");
	homeWorks.push_back("6.4");
}
bool checkExistHomeWork (string title) {
	for (string homeWorkTitle: homeWorks) {
		if (homeWorkTitle == title) {
			return true;
		}
	}
	return false;
}
void renderListHomeWork () {
	for (int i = 0; i < homeWorks.size(); i++) {
		cout << "[" << i << "] " << homeWorks[i] << endl;
	}
	
}
void runHomeWork (string title) {
	outBar(50);
	cout << "DANG THUC HIEN CHAY BAI " << title << endl;
	if (title == "6.1") {
		bai6dot1();
	} else if(title == "6.2") {
		bai6dot2();
	} else if(title == "6.3") {
		bai6dot3();
	} else if(title == "6.4") {
		bai6dot4();
	} else {
		cout << "Lua chon cua ban khong hop le!" << endl;
	}
	outBar(50);
}
int main () {	
	loadHomeWorks();
	bool isExit = false;
	do {
		string homeWorkName;
		renderListHomeWork();
		cout << "Nhap vao ten bai tap ban muon chay (ex: 6.1, ...): ";
		cin >> ws;	
		getline(cin, homeWorkName);
		if (checkExistHomeWork(homeWorkName) == false) {
			cout << "HomeWork khong ton tai, vui long nhap lai!" << endl;
			sleep(1);
			continue;
		}
		runHomeWork(homeWorkName);
		cout << "Ban co muon thoat khong? (y/n): ";
		char askExit;
		cin >> askExit;
		if (askExit == 'y' || askExit == 'Y') {
			isExit = true;
		} else {
			isExit = false;
		}
	} while (!isExit);	
}
  
