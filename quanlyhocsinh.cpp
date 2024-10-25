#include <iostream>
#include <vector>
#include <stdio.h>
#include <windows.h>
#include <unistd.h>
#include <sstream>
#include <string>
#include <stdexcept>
#include <algorithm>  
#include <iterator>
#include <time.h>
#include <cstdio>  
#include <ctime>  
#include <fstream>
#include <map>


using namespace std;

struct student {
    string firstName;
    string lastName;
    int age;
    string location;
};

struct log {
	string dateTime;
	string content;
};


struct tableData {
	string name;
	string value;
};


struct titleSize {
	string name;
	int size;
};

vector<log> logs;

vector<student> students;
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

void addNewLog (string content) {
	log newLog;
	newLog.dateTime = currentDateTime();
	newLog.content = content;
	logs.push_back(newLog);
	
}

void outBar (int amount) {
	for(int i = 0; i < amount; i++) {
		cout << "=";
	}
	
	cout << endl;
}

void makeSpace(int amount) {
	for(int i = 0; i < amount; i++) {
		cout << " ";
	}
}

class viewMode {
	public:
		vector<string> title;
		vector<tableData> data;
		vector<titleSize> titleSizes;
		void setData(vector<tableData> itemDataList);
		void setTitleTable(vector<string> title);
		void outTitleTable();
		void outDataTable();
		vector<tableData> getRowsData(string name);
		int getLengthTitle(string name);
		int getMaxLengthField(string fieldName);
	
		
	
		
};


vector<tableData> viewMode::getRowsData(string name) {
	vector<tableData> dataFilter;
	for(int i = 0; i < this->data.size(); i++) {
		if(this->data[i].name == name) {
			dataFilter.push_back(this->data[i]);
		}
	}
	
	return dataFilter;
}

void viewMode::outDataTable() {
	for(int i = 0; i < this->title.size(); i++) {
		vector<tableData> dataFilter = this->getRowsData(this->title[i]);
		
	}
}


int viewMode::getMaxLengthField(string fieldName) {
	int maxLength = 0;
	for(int i = 0; i < this->data.size(); i++) {
		
		if (this->data[i].name == fieldName) {
			string dataValue = this->data[i].value;
			if (dataValue.length() > maxLength) {
				maxLength = dataValue.length();
			}
		}
		
	}
	
	return maxLength;
}

void viewMode::setData (vector<tableData> itemDataList) {
	
	this->data = itemDataList;
}

void viewMode::setTitleTable (vector<string> title) {
	this->title = title;
}

int viewMode::getLengthTitle (string name) {
	for(int i = 0; i < this->titleSizes.size(); i++) {
		if(this->titleSizes[i].name == name) {
			return this->titleSizes[i].size;
		}
	}
	
	return 0;
}




void viewMode::outTitleTable () {
	int amountBar = 2;
	
	for (int i = 0; i < this->title.size(); i++) {
		int lengthField = this->getMaxLengthField(this->title[i]);
		
		if (lengthField == 0) {
			int titleLen = this->title[i].length() + 8;
			amountBar += titleLen;
			titleSize objTitle;
			objTitle.name = this->title[i];
			objTitle.size = titleLen;
			this->titleSizes.push_back(objTitle);
		} else {
			//amountBar += lengthField+8;
		
			int realLengthField = lengthField+8;
			
			// fill until %2 = 0
			while (realLengthField % 2 != 0) {
				realLengthField++;
			}
			
			
			// append length title
			realLengthField += this->title[i].length();
			titleSize objTitle;
			objTitle.name = this->title[i];
			objTitle.size = realLengthField;
			this->titleSizes.push_back(objTitle);
			amountBar += realLengthField;
			
		}
		
	}
	amountBar -= 4;
	
	outBar(amountBar);
	cout << "||";
	for (int i = 0; i < this->title.size(); i++) {
		int lenField = this->getMaxLengthField(this->title[i]);
		
		if(lenField == 0) {
			cout << "   " << this->title[i] << "   " << "||";
		} else {
			int spaceCount = (lenField/2)+3;
			makeSpace(spaceCount);
			cout << this->title[i];
			makeSpace(spaceCount);
			cout << "||";
			
			
			
		}
		
	}
	cout << endl;
	outBar(amountBar);
}




class helper {
	public:
		string menuHelper[1] = {
			"Load du lieu hoc sinh thu nghiem"
		};
		int userChoice;
		
		void loadStudentTest();
		int getLengthMenuHelper();
		void renderMenuHelper();
		bool askToActionFeature();
		bool actionFeature();
};

int helper::getLengthMenuHelper() {
	return sizeof(this->menuHelper) / sizeof(this->menuHelper[0]);
}

void helper::loadStudentTest() {
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
	addNewLog("Du lieu hoc sinh test da duoc them vao...");
	cout << "Data test loaded!" << endl;
}

bool helper::actionFeature() {
	this->renderMenuHelper();
	outBar(60);
	if(this->askToActionFeature() == false) {
		return false;
	}
	
	outBar(60);
	
	switch (this->userChoice) {
		case 0: {
			this->loadStudentTest();
			break;
		}
		default: {
			cout << "BAN NHAP KHONG HOP LE!!!";
			break;
		}
	}
	
	
	return true;
	
	
}


bool helper::askToActionFeature() {
	cout << "NHAP SO CHUC NANG MA BAN MUON SU DUNG: ";
	int choice;
	cin >> choice;
	
	if (choice > this->getLengthMenuHelper()-1) {
		cout << "CHUC NANG KHONG HOP LE!!";
		return false;
	}
	
	this->userChoice = choice;
	addNewLog("Da su dung chuc nang ho tro");
	return true;
	
}

void helper::renderMenuHelper() {
	outBar(60);
	cout << "DANH SACH CAC CHUC NANG HO TRO HIEN CO" << endl;
	int length = this->getLengthMenuHelper();
	outBar(60);
	for(int i = 0; i < length; i++) {
		cout << "[" << i << "] " << this->menuHelper[i] << endl;
	}
}







const string menus[10] = {
    "Them hoc sinh",
    "Xoa hoc sinh",
    "Chinh sua hoc sinh",
    "Xem danh sach hoc sinh",
    "Tim kiem hoc sinh",
    "Xuat du lieu hoc sinh ra file txt",
    "Xem lich su hoat dong",
    "Tai du lieu hoc sinh tu file txt",
    "Cong cu ho tro debug",
    "View mode"
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


string intToString (int number) {
	stringstream ss;
	ss << number;
	string str = ss.str();
	return str;
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
	
	
	addNewLog("Dang thuc hien chinh sua hoc �nh co ten: " + fullName);
	
	
	
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
		addNewLog("Da thuc hien xoa hoc sinh co ten: " + fullNameRemoveIt);
		
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
	
	addNewLog("Da thuc hien viec tim kiem hoc sinh voi noi dung: " + findContent);
	
	system("cls");
	return renderStudent(true, false, false, false, false, true, findContent);
	

	
}


string getContentStudents () {
	string result = "";
	
	for(int i = 0; i < students.size(); i++) {
		string studentContent = intToString(i) + "|" + students[i].firstName + " " + students[i].lastName + "|" + intToString(students[i].age) + "|" + students[i].location;
		result += studentContent + "\n";
	}
	
	return result;
}



void showActivityList () {
	system("cls");
	outBar(100);
	cout << "NHAT KY HOAT DONG (TAM THOI)" << endl;
	outBar(100);
	for(int i = 0; i < logs.size(); i++) {
		log currentLog = logs[i];
		cout << "[" << i << "] Date: " << currentLog.dateTime << " || Content: " << currentLog.content << endl;
	}
	outBar(100);
	cout << "Ban co muon xoa nhat ky hoat dong khong? (y/n): ";
	char askRemove[1];
	fflush(stdin);
	gets(askRemove);
	
	if(askRemove[1] == 'y' || askRemove[1] == 'Y') {
		logs.clear();
		cout << "DA XOA TOAN BO NHAT KY HOAT DONG THANH CONG!";
	}
	
	system("pause");

	
	
	
	
}

void saveContentExport (string content) {
	fstream output;
	output.open("dshs.txt", ios::out);
	output << content;
}

void exportStudentsList () {
	string result = getContentStudents();
	string content = "Format: id|fullName|age|location\n";
	content += result;
	content += "Ngay xuat: " + currentDateTime() + " || tong so hoc sinh: " + intToString(students.size()) + "\n";
	saveContentExport(content);
	outBar(100);
	cout << "Xuat du lieu hoc sinh thanh cong!!!" << endl;
	outBar(100);
	addNewLog("Xuat du lieu hoc sinh thanh cong");
	system("pause");
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


vector<string> split_str(const string &s, const string &delimiter) {
    vector<string> tokens;
    size_t start = 0;
    size_t end = s.find(delimiter);

    while (end != string::npos) {
        tokens.push_back(s.substr(start, end - start));
        start = end + delimiter.length();
        end = s.find(delimiter, start);
    }

    tokens.push_back(s.substr(start, end)); // Add the last token
    return tokens;
}



bool loadDataStudentFromTxtFile () {
	
	
	try {
		
		char fileNameInput[100];
		
		fflush(stdin);
		cout << "NHAP VAO TEN FILE: ";
		gets(fileNameInput);
		
		
		ifstream StudentDataFile(fileNameInput);
		string myContent;
		
		
		
		
		
		
				
		while (getline(StudentDataFile, myContent)) {
			if (myContent != "Format: id|fullName|age|location" && myContent.find("Ngay xuat") == string::npos) {
				vector<string> result = split_str(myContent, "|");
				string fullName = result[1];
				string location = result[3];
				vector<string> firstAndLastName = split_str(fullName, " ");
				
				
				student stu;
				stu.firstName = firstAndLastName[0];
				stu.lastName = firstAndLastName[1];
				stu.location = location;
				
				int age;

			    std::istringstream iss(result[2]);
			    iss >> age;
			    
			    stu.age = age;
			    
			    students.push_back(stu);
			    cout << "Da tai hoc sinh co ten: " << fullName << ", vao o nho hoc sinh!" << endl;
			    addNewLog("Them du lieu hoc sinh co ten " + fullName + " tu chuc nang load file");
			    
			    
							
				
				
				
			}
			
		}
		
		
		cout << "THEM DU LIEU HOC SINH TU FILE: " << fileNameInput << " THNH CONG!!!" << endl;
		system("pause");
		return true;
		
	} catch (bool res) {
		cout << "FILE HANDLE ERROR!!!" << endl;
		
		return res;
	
	} 

	
	return true;
}


void testRenderTable () {
	helper objhelper;
	objhelper.loadStudentTest();
	viewMode obj;
	
	vector<string> testTitle;
   	testTitle.push_back("STT");
   	testTitle.push_back("Ho");
   	testTitle.push_back("Ten");
   	testTitle.push_back("Tuoi");
   	testTitle.push_back("Dia chi");
   	
   	obj.setTitleTable(testTitle);
   	
   	
	vector<tableData> testData;
	for(int i = 0; i < students.size(); i++) {
	
		// create data obj stt
		tableData dataSTT;
		dataSTT.name = "STT";
		stringstream ss;
		ss << i;
		string valueIndex = ss.str();
		dataSTT.value = valueIndex;
		
		
		// create data obj firstName
		tableData dataHo;
		dataHo.name = "Ho";
		dataHo.value = students[i].firstName;
		
		
		// create data obj lastName
		tableData dataTen;
		dataTen.name = "Ten";
		dataTen.value = students[i].lastName;
		
		
		// create data obj age
		tableData dataAge;
		dataAge.name = "Tuoi";
		stringstream ssage;
		ssage << students[i].age;
		string valueAge = ssage.str();
		dataAge.value = valueAge;
		
		
		// create data obj location
		tableData dataDiaChi;
		dataDiaChi.name = "Dia chi";
		dataDiaChi.value = students[i].location;
		
		// push
		testData.push_back(dataSTT);
		testData.push_back(dataHo);
		testData.push_back(dataTen);
		testData.push_back(dataAge);
		testData.push_back(dataDiaChi);
	
		
	}
	
	

	
	obj.setData(testData);
	obj.outTitleTable();
	obj.outDataTable();
//	vector<tableData> dataHos = obj.getRowsData("Ho");
//	for(int i = 0; i < dataHos.size(); i++) {
//		cout << dataHos[i].value << endl;
//	}
}



int main () {
    
    
    int choice;
    char askExist[0];
    testRenderTable();
    
//    viewMode obj;
//   	
//   	vector<string> testTitle;
//   	testTitle.push_back("STT");
//   	testTitle.push_back("Ho");
//   	testTitle.push_back("Ten");
//   	testTitle.push_back("Tuoi");
//   	testTitle.push_back("Dia chi");
//   	
//   	vector<tableData> testData;
//   	tableData test1;
//   	test1.name = "Ho";
//   	test1.value = "Nhan";
//   	
//   	tableData test2;
//   	test2.name = "Ho";
//   	test2.value = "tran huu kieu dung nguyen ha huu";
//  
//   	testData.push_back(test1);
//   	testData.push_back(test2);
//   	
//   	obj.setData(testData);
// 
//   	
//   	
//   	obj.setTitleTable(testTitle);
//   	obj.outTitleTable();
//   	
//   	
//   	
   	
   	
    system("pause");

	

    while (true) {
    	
    	
    	
    	
    	do {
	        choice = menu();
	    } while (choice < 0);
	    
	    
	    
	    
	    system("cls");
	    switch (choice) {
	        case 0: {
	            addNewStudent();
	            addNewLog("Ban da an vao chuc nang them hoc sinh");
	            break;
	        }
	        case 1: {
	            removeStudent();
	            addNewLog("Ban da an vao chuc nang xoa hoc sinh");
	            break;
	        }
	        case 2: {
	        	editStudent();
	        	addNewLog("Ban da an vao chuc nang chinh sua hoc sinh");
				break;
			}
			case 3: {
				showListStudent();
				addNewLog("Ban da an vao chuc nang xem danh sach hoc sinh");
				break;
			}
			case 4: {
				findStudent();
				addNewLog("Ban da an vao chuc nang tim hoc sinh");
				break;
			}
			case 5: {
				exportStudentsList();
				addNewLog("Ban da an vao chuc nang xuat danh sach hoc sinh ra file txt");
				break;
			}
			case 6: {
				showActivityList();
				addNewLog("Ban da vao chuc nang xem lich su!");
				break;
			}
			case 7: {
				loadDataStudentFromTxtFile();
				addNewLog("Ban da vao chcu nang load student tu file");
				break;
			}
			case 8: {
				helper obj;
				obj.actionFeature();
				break;
			}
			case 9: {
				
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
