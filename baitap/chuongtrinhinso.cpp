#include <iostream>
using namespace std;



int main () {
	
	int n, amExceptNum;
	cout << "NHAP VAO N = ";
	cin >> n;
	
	cout << "NHAP SO LUONG SO BAN MUON BO QUA: ";
	cin >> amExceptNum;
	
	int numSkip[amExceptNum];
	for(int i = 1; i <= amExceptNum; i++) {
		cout << "[" << i << "] Nhap vao so muon bo qua: ";
		cin >> numSkip[i];
	}
	
	bool isIn = false;
	for (int i = 1; i < n; i++) {
	
		isIn = false;
		for(int y = 1; y <= amExceptNum; y++) {
			if (i == numSkip[y]) {
				isIn = true;
				break;
			}
		}
		
		if (isIn) continue;
		else cout << i << "\t";
	}
	
	
	
	return 0;
	
	
}
