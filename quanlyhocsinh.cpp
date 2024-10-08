#include <iostream>
#include <vector>
#include <stdio.h>
#include <windows.h>
#include <unistd.h>
#include <sstream>
#include <string>
#include <stdexcept>
#include <algorithm>  
#include <iterator> // for std::begin, std::end

/**


	CODE BY NGUYEN PHUC NHAN HOA
	08/10/2024
	
	Note: moi hoc c++ duoc 2 tuan nen code hoi da, thong cam
	
	:>

**/


using namespace std;

struct student {
    string firstName;
    string lastName;
    int age;
    string location;
};

vector<student> students;



const string menus[5] = {
    "Them hoc sinh",
    "Xoa hoc sinh",
    "Chinh sua hoc sinh",
    "Xem danh sach hoc sinh",
    "Tim kiem hoc sinh"
};


const string menuSort[4] = {
	"Sap xep theo dia chi",
	"Sap xep theo ho",
	"Sap xep theo ten",
	"Sap xep theo tuoi"
};


int secSortFunction () {
	int sizeMenuSort = sizeof(menuSort) / sizeof(menuSort[0]);
	for (int i = 0; i < sizeMenuSort; i++) {
		cout << "[" << i << "] " << menuSort[i] << endl;
	}
	
	int indexChoice;
	cout << "Nhap so chuc nang muon sai: " << endl;
	
	cin >> indexChoice;
	return indexChoice;
	
	
}


vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    stringstream ss(s);
    string token;

    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

void outBar (int amount) {
	for(int i = 0; i < amount; i++) {
		cout << "=";
	}
	
	cout << endl;
}

int showBackMenu () {
	cout << "enter to back the menu" << endl;
	system("pause");
	return 0;
}

vector<student> sortStudents (bool sortFirstName = false,
	bool sortLastName = false, bool sortAge = false, bool sortLocation = false) {
	
	vector<string> listStr;
	vector<int> listInt;
	vector<student> sortStudentsList;
	for(int i = 0; i < students.size(); i++) {
		bool statusFind = false;
		
		if (sortAge == false) {
			
			// accept only string sort
			for(int y = 0; y < listStr.size(); y++) {
				if(sortFirstName) {
					if (students[i].firstName == listStr[y]) {
						statusFind = true;
						break;
					}
				}
				
				if(sortLastName) {
					if(students[i].lastName == listStr[y]) {
						statusFind = true;
						break;
					}
				}
				
				if(sortLocation) {
					if(students[i].location == listStr[y]) {
						statusFind = true;
						break;
					}
				}
			}
			
		} else {
			// process only int sort
			for(int y = 0; y < listInt.size(); y++) {
				if(sortAge) {
					if(students[i].age == listInt[y]) {
						statusFind = true;
						break;
					}
				}
			}
		}
		
		
		
		
		if (statusFind == false) {
			if (sortFirstName) {
				listStr.push_back(students[i].firstName);
			}
			
			if (sortLastName) {
				listStr.push_back(students[i].lastName);
			}
			
			if (sortLocation) {
				listStr.push_back(students[i].location);
			}
			
			if (sortAge) {
				listInt.push_back(students[i].age);
			}
		}
		
		
		
	}
	
	
	
	if (sortAge == false) {
		
		for (int i = 0; i < listStr.size(); i++) {
			string keywordToFind = listStr[i];
			
			for (int y = 0; y < students.size(); y++) {
				
				
				bool statusPush = false;
				// get only field..
				if (sortFirstName) {
					if (students[y].firstName == keywordToFind) {
						statusPush = true;
					}
					
				}	
				
				if (sortLastName) {
					if (students[y].lastName == keywordToFind) {
						statusPush = true;
					}
				}
				
				if (sortLocation) {
					if (students[y].location == keywordToFind) {
						statusPush = true;
					}
				}
				
				if(statusPush) {
					sortStudentsList.push_back(students[y]);
				}
				
				
				
				
			}
			
			
			
		}
		
	} else {
		for (int i = 0; i < listInt.size(); i++) {
			int keywordToFind = listInt[i];
			for (int y = 0; y < students.size(); y++) {
				bool statusPush = false;
				if (students[y].age == keywordToFind) {
					statusPush = true;
				}
				
				
				if(statusPush) {
					sortStudentsList.push_back(students[y]);
				}
			}
		}
	}
	
	
	return sortStudentsList;
}

vector<student> findFeature (string findContent) {
	vector<student> studentsFound;
	
	for(int i = 0; i < students.size(); i++) {
		student stu = students[i];
		
		if (students[i].firstName == findContent) {
			studentsFound.push_back(students[i]);
			continue;
		} 
		
		if (students[i].lastName == findContent) {
			studentsFound.push_back(students[i]);
			continue;
		}
		
		

		if (students[i].location == findContent) {
			studentsFound.push_back(students[i]);
			continue;
		}
		
		
	}
	
	return studentsFound;
}

int renderStudent (bool isBackMenu = false, bool sortFirstName = false,
	bool sortLastName = false, bool sortAge = false, bool sortLocation = false, bool findMode=false, string contentFind=""
) {
	
	cout <<  "[ ==== DANH SACH HOC SINH HIEN CO ==== ]" << endl;
	
	outBar(100);
	if (students.empty()) {
	
		cout << "HIEN TAI CHUA CO HOC SINH NAO DE HIEN THI CA!" << endl;
		outBar(100);
		
		return showBackMenu();
		
	}
	
	if (sortFirstName == false && sortLastName == false && sortAge == false && sortLocation == false && findMode == false) {
		for (int i = 0; i < students.size(); i++) {
			string fullName = students[i].firstName + " " + students[i].lastName;
			cout << "[" << i << "] Ho va ten: " << fullName << " || so tuoi: " << students[i].age << " || vi tri: " << students[i].location << endl;
		}
	} else {
		
		vector<student> cloneStudents;
		
		if(sortFirstName) {
			cloneStudents = sortStudents(true, false, false, false);
		}
		
		
		if(sortLastName) {
			cloneStudents = sortStudents(false, true, false, false);
		}
		
		if(sortAge) {
			cloneStudents = sortStudents(false, false, true, false);
		}
		
		if(sortLocation) {
			cloneStudents = sortStudents(false, false, false, true);
		}
		
		
		if(findMode) {
		
			cloneStudents = findFeature(contentFind);
		}
		
		
		for (int i = 0; i < cloneStudents.size(); i++) {
			string fullName = cloneStudents[i].firstName + " " + cloneStudents[i].lastName;
			cout << "[" << i << "] Ho va ten: " << fullName << " || so tuoi: " << cloneStudents[i].age << " || vi tri: " << cloneStudents[i].location << endl;
		}
		
	}
	
	
	
	outBar(100);
	
	if (isBackMenu) return showBackMenu();
	else return 0;
	
	
}




void addNewStudent () {
    string firstName, lastName, location;
    int age;
    
    outBar(50);
    cout << "THEM HOC SINH MOI" << endl;
    outBar(50);
    cout << "SO HOC SINH HIEN CO TRONG MANG: " << students.size() << endl;
    outBar(50);
    

	
    cout << "Nhap ho: ";
    cin >> ws;
    
	getline(cin, firstName);
	
	cout << "Nhap ten: ";
	getline(cin, lastName);
	
	cout << "Nhap dia chi: ";
	getline(cin, location);
	
	
	do {
		cout << "Nhap tuoi: ";
		cin >> age;
	} while (age <= 0);
	
	
	student newStu;
	newStu.firstName = firstName;
	newStu.lastName = lastName;
	newStu.location = location;
	newStu.age = age;
	students.push_back(newStu);
	
	cout << "THEM HOC SINH THANH CONG!!" << endl;
	sleep(1);
	
	
    
}

int stringToInt(const string& str) {
    int number;
    stringstream ss(str);
    ss >> number;
    if (ss.fail()) {
        throw invalid_argument("Invalid number");
    }
    return number;
}



vector<int> getMultiChoices (string userInput) {
	vector<string> choices = split(userInput, ',');
	vector<int> avabChoices;
	
	// check condition
	for(int i = 0; i < choices.size(); i++) {
		int num = stringToInt (choices[i]);
		
		if (num < students.size() && num >= 0) {
			avabChoices.push_back(num);
			
		}
	}
	return avabChoices;
}


void showInfomationStudent (int ichoice) {
	student curStudent = students[ichoice];
	outBar(100);
	cout << "THONG TIN HOC SINH BAN:" << endl;
	cout << "-HO: " << curStudent.firstName << endl;
	cout << "-TEN: " << curStudent.lastName << endl;
	cout << "-TUOI: " << curStudent.age << endl;
	cout << "-VI TRI: " << curStudent.location << endl;
	outBar(100);
}

void openEditStudentWarper(int ichoice) {
	system("cls");
	student currentStudentChoice = students[ichoice];
	string fullName = currentStudentChoice.firstName + " " + currentStudentChoice.lastName;
	cout << "[ DANG CHINH SUA HOC SINH " << fullName << ", CO VI TRI TRONG HE THONG LA " << ichoice << " ]" << endl;
	showInfomationStudent(ichoice);
	cout << "Ban co muon edit hoc sinh nay khong? (y/n - default is no): ";
	cin >> ws;
	string askEdit;
	getline(cin, askEdit);
	
	
	
	if (askEdit == "y" || askEdit == "Y") {
		cout << "Vui long nhap cac du lieu moi de sua hoc sinh nay..." << endl;

		// edit warp
		cout << "Ho [" << currentStudentChoice.firstName << "]: ";
	
		
		getline(cin, students[ichoice].firstName);
		
		if (students[ichoice].firstName.length() == 0) {
			students[ichoice].firstName = currentStudentChoice.firstName;
		}
		
		cout << "Ten [" << currentStudentChoice.lastName << "]: ";
		getline(cin, students[ichoice].lastName);
		
		if(students[ichoice].lastName.length() == 0) {
			students[ichoice].lastName = currentStudentChoice.lastName;
		}
		
		
		
		cout << "Tuoi [" << currentStudentChoice.age << "]: ";
		string ageInput;
		getline(cin, ageInput);
		
		if (ageInput.length() > 0) {
			int num = stringToInt(ageInput);
			students[ichoice].age = num;
		}
		
		
		
		cout << "Dia chi [" << currentStudentChoice.location << "]: ";
	
		
		getline(cin, students[ichoice].location);
		
		if (students[ichoice].location.length() == 0) {
			students[ichoice].location = currentStudentChoice.location;
		}
		
		cout << "Edit thong tin thanh cong hoc sinh co index " << ichoice << endl;
		
	} else {
		cout << "Da huy qua trinh edit hoc sinh nay!" << endl;
		
	}
	
	sleep(1);
	
	
	
	
	
}

int editStudent () {
	renderStudent();
	if(students.empty()) {
		return 0;
	}
	
	cout << "Nhap vi tri hoc sinh muon xoa (ex: 1,2,3,4): " << endl;
	cin >> ws;
	string userInput;
	getline(cin, userInput);
	
	vector<int> choices = getMultiChoices(userInput);
	
	for(int i = 0; i < choices.size(); i++) {
		int choice = choices[i];
		openEditStudentWarper(choice);
	}
	
	
	
	
}

int removeStudent () {
    renderStudent();
    if (students.empty()) {
   		return 0; 	
	}    
	
	cout << "Nhap vi tri hoc sinh muon xoa (ex: 1,2,3,4): " << endl;
	cin >> ws;
	string userInput;
	getline(cin, userInput);
	
	vector<int> choices = getMultiChoices(userInput);
	for (int i = 0; i < choices.size(); i++ ) {
		int iChoice = choices[i];
		string fullNameRemoveIt = students[iChoice].firstName + " " + students[iChoice].lastName;
		cout << "-- Da xoa hoc sinh co index " << iChoice << " [FULL_NAME: " << fullNameRemoveIt << "]" << endl;
		students.erase(students.begin() + iChoice);
		cout << "-- So hoc sinh con lai la " << students.size() << endl;
		
	}
	
	sleep(2);
	
}

int menu () {
    cout << "Danh sach chuc nang" << endl;
    int lenMenu = sizeof(menus) / sizeof(menus[0]);
    for (int i = 0; i < lenMenu; i++) {
        cout << "[" << (i+1) << "] " << menus[i] << endl;
    }
    
    int choice;
    cout << "Nhap so chuc nang ban muon chon: " << endl;
    cin >> choice;
    
    if (choice > lenMenu) {
        cout << "Chuc nang khong ton tai" << endl;
        return -1;
    }
    
    
    if (choice < 0) {
        cout << "Chuc nang khong ton tai" << endl;
        return -1;
    }
    
    return choice-1;
    
}

int findStudent () {
	system("cls");
	
	
	string findContent;
	
	renderStudent();
	cout << "Tim kiem...: ";
	cin >> ws;
	getline(cin, findContent);
	
	system("cls");
	return renderStudent(true, false, false, false, false, true, findContent);
	

	
}

int showListStudent () {
	int choice;
	do {
		system("cls");
		renderStudent();
		choice = secSortFunction();
	} while (choice < 0);
	
	
	system("cls");
	switch (choice) {
		case 0: {
			return renderStudent(true, false, false, false, true);
			break;
		}
		case 1: {
			return renderStudent(true, true, false, false, false);
			break;
		}
		
		case 2: {
			return renderStudent(true, false, true, false, false);
			break;
		}
		case 3: {
			return renderStudent(true, false, false, true, false);
			break;
		}
		
		default: {
			cout << "Not found function!" << endl;
			return 0;
			break;
		}
	}





	
	
}

void test () {
	student stu;
	stu.firstName = "trong";
	stu.lastName = "hoa";
	stu.age = 19;
	stu.location = "long hai";
	
	student stu2;
	stu2.firstName = "nhan";
	stu2.lastName = "hoa";
	stu2.age = 20;
	stu2.location = "dat do";
	
	student stu3;
	stu3.firstName = "bao";
	stu3.lastName = "nguyen";
	stu3.age = 20;
	stu3.location = "nam dinh";
	
	student stu4;
	stu4.firstName = "hung";
	stu4.lastName = "nguyen";
	stu4.age = 21;
	stu4.location = "ba ria";
	
	
	student stu5;
	stu5.firstName = "hung";
	stu5.lastName = "ba";
	stu5.age = 21;
	stu5.location = "lasvegas";
	
	student stu6;
	stu6.firstName = "hoa";
	stu6.lastName = "hoa";
	stu6.age = 21;
	stu6.location = "ba ria";
	
	student stu7;
	stu7.firstName = "nhan";
	stu7.lastName = "hoa";
	stu7.age = 22;
	stu7.location = "vung tau";
	
	
	students.push_back(stu);
	students.push_back(stu2);
	students.push_back(stu3);
	students.push_back(stu4);
	students.push_back(stu5);
	students.push_back(stu6);
	students.push_back(stu7);
	
	cout << "Data test loaded!" << endl;
}

int main () {
    
    
    int choice;
    char askExist[0];
    test();
    while (true) {
    	
    	
    	do {
	        choice = menu();
	    } while (choice < 0);
	    
	    
	    
	    
	    system("cls");
	    switch (choice) {
	        case 0: {
	            addNewStudent();
	            break;
	        }
	        case 1: {
	            removeStudent();
	            break;
	        }
	        case 2: {
	        	editStudent();
				break;
			}
			case 3: {
				showListStudent();
				break;
			}
			case 4: {
				findStudent();
				break;
			}
	        default: {
	            cout << "Khong ro la chuc nang nao!" << endl;
	            break;
	        }
	    }
	    
	    
	    system("cls");
		cout << "DO YOU WANT EXIT? (y/n): ";
		fflush(stdin);
		gets(askExist);
		if (askExist[0]== 'y' || askExist[0]== 'Y') {
			cout << "TIEN HANH THOAT CHUONG TRINH" << endl;
			break;
		}
		system("cls");
	}
    
    
    
    
    
    
    return 0;
    
}
