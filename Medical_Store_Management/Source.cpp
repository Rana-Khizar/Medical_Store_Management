#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

class Node {
private:
	int qty;
	float price;
	string name;
	string exp;
	Node* link;
public:
	void setQty(int qty) {
		this->qty = qty;
	}
	int getQty() {
		return qty;
	}
	void setPrice(float price) {
		this->price = price;
	}
	float getPrice() {
		return price;
	}
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
	void setExp(string exp) {
		this->exp = exp;
	}
	string getExp() {
		return exp;
	}
	void setLink(Node* link) {
		this->link = link;
	}
	Node* getLink() {
		return link;
	}
};

class Medicine {
private:
	Node* start;
	Node* current;
	Node* next;
	Node* temp;
public:
	Medicine() {
		start = current = next = temp = NULL;
	}
																		//////////insert/////////////
	void insert() {
		string name, exp;
		float price;
		int qty;

		if (start == NULL) {
			next = new Node;

			cout << "Name of Medicine: ";
			cin >> name;
			cout << "Price: ";
			cin >> price;
			cout << "Quantity  Available: ";
			cin >> qty;
			cout << "Expiration Date[dd/mm/yy]: ";
			cin >> exp;

			next->setName(name);
			next->setPrice(price);
			next->setQty(qty);
			next->setExp(exp);
			next->setLink(NULL);

			current = next;
			start = next;
			
		}
		else {
			next = new Node;

			cout << "Name of Medicine: ";
			cin >> name;
			cout << "Price: ";
			cin >> price;
			cout << "Quantity  Available: ";
			cin >> qty;
			cout << "Expiration Date[dd/mm/yy]: ";
			cin >> exp;

			next->setName(name);
			next->setPrice(price);
			next->setQty(qty);
			next->setExp(exp);
			next->setLink(NULL);
			current->setLink(next);

			current = next;
		}
		
		ofstream stockFile;
		stockFile.open("Stocks.csv",ios::app);

		stockFile << name << "," << price << "," << qty << "," << exp << "\n";
		stockFile.close();

	}
																		//////////display/////////////
	void display() {
		string temp;

		string name, exp;
		int qty;
		float price;
		
		ifstream stockFile;
		stockFile.open("Stocks.csv",ios::app);

		while (stockFile.good()) {
			getline(stockFile, temp);

		}

			
	}
																		////////// delete///////////
	void dell() {
		string deleteline;
		string line;

		ifstream fin;
		fin.open("Medicine.csv");
		ofstream temp;
		temp.open("temp.csv");
		cout << "Which line do you want to remove? ";
		cin >> deleteline;



		while (getline(fin, line))
		{
			line.replace(line.find(deleteline), deleteline.length(), "");
			temp << line << endl;

		}

		temp.close();
		fin.close();
		remove("Medicine.csv");
		rename("temp1.csv", "Medicine1.csv");


	}
																		///////// search///////////
	void search() {
		string name;
		int count = 0;
		string line= " ";
		fstream file;
		string t, q, filename;

		// filename of the file
		filename = "Stocks.csv",ios::app;

		// opening file
		file.open(filename.c_str());
		cout << "Medicine Name: " << endl;
		cin>>name;
		if (file.is_open()) {
			// extracting words from the file
			while (isalnum(file.peek()))
			{
				// displaying content
				getline(file, line);
				if (count == line.find(name,0)) {
					cout << "Found"<<"->" << name << endl;
					break;

				}
				current = next;
			}
			file.close();

		}


	}
																		//////////update///////////
	void update() {
		string name;
		int count = 0;
		string line = " ";
		fstream file;
		string t, q, filename;

		filename = "Medicine.csv", ios::app;
		file.open(filename.c_str());
		cout << "Search Name of medicine: " << endl;
		cin >> name;
		if (file.is_open()) {
			while (isalnum(file.peek()))
			{
				getline(file, line);
				if (count == line.find(name, 0)) {
					cout << "Found" << "->" << name << endl;
					cout << "Enter the updation Name: " << endl;
					string name1;
					cin >> name1;
					name = name1;
					break;

				}
				current = next;
			}
			file.close();
		}
		else {
			cout << "Not Found" << endl;
		}
	}
};

// class Login {
//	private:
//		int id;
//		string password;
//		string title;
//		
//	public:
//		Login() {
//			id = NULL;
//			password = title = "";
//		}
//
//		string takePass() {
//			string pass;
//			char ch;
//
//			ch = _getch();
//			while (ch != 13) {
//				pass.push_back(ch);
//				cout << "*";
//				ch = _getch();
//			}
//
//			return pass;
//		}
//
//		bool create_account() {
//			int tempId, checkId;
//			string tempPass;
//			string tempTitle;
//			string temp, word;
//
//			ifstream accountsFile;
//			accountsFile.open("Accounts.csv");
//
//			cout << "Enter ID: ";
//			cin >> tempId;
//
//			while (accountsFile.good()) {
//				getline(accountsFile, temp);
//
//				for (auto a : temp) {
//					if (a == ',') {
//						break;
//					}
//					else {
//						word = word + a;
//					}
//				}
//
//				checkId = stoi(word);
//
//				if (tempId == checkId) {
//					cout << "Account already exists!\nTry Logging In" << endl;
//					return 0;
//				}
//			}
//			accountsFile.close();
//
//			cout << "Enter the password: ";
//			password = takePass();
//			cout << endl;
//
//			do {
//				cout << "Title [buyer/seller]: ";
//				cin >> title;
//
//				if (title == "buyer" || title == "seller") {
//					ofstream accountsWrite;
//					accountsWrite.open("Accounts.csv", ios_base::app);
//
//					accountsWrite << tempId << "," << password << "," << title << "\n";
//					accountsWrite.close();
//
//					return 0;
//				}
//				else {
//					cout << "Invalid Title!" << endl;
//				}
//			} while (title != "exit");
//
//			return 0;
//		}
//
//		bool login() {
//			int id, tempId;
//			int count = 0, tries = 0;
//			string password, tempPass;
//			string title;
//			string temp, word;
//			bool found = false;
//
//			do {
//				cout << "Enter ID: ";
//				cin >> id;
//				cout << "Enter Password: ";
//				password = takePass();
//				cout << endl;
//
//				ifstream accountsFile;
//				accountsFile.open("Accounts.csv");
//
//				while (accountsFile.good()) {
//					getline(accountsFile, temp);
//
//					for (auto a : temp) {
//						if (a == ',') {
//							if (count == 0) {
//								tempId = stoi(word);
//							}
//							else if (count == 1) {
//								tempPass = word;
//							}
//							word = "";
//							count++;
//						}
//						else {
//							word = word + a;
//						}
//					}
//					title = word;
//					word = "";
//					count = 0;
//
//					time_t t = time(0);
//					tm* timenow = localtime(&t);
//
//					if (id == tempId) {
//						if (password == tempPass) {
//							found = true;
//							cout << title << " login!" << endl;
//
//							string timestr = to_string(timenow->tm_hour) + ':' + to_string(timenow->tm_min) + ':' + to_string(timenow->tm_sec);
//
//							ofstream logins;
//							logins.open("LoginHistory.csv");
//
//							logins << id << "," << title << "," << timestr << "\n";
//							logins.close();
//							return true;
//							break;
//						}
//					}
//				}
//				accountsFile.close();
//
//				if (!found) {
//					cout << "Wrong Id or Password!" << endl;
//				}
//
//				tries++;
//			} while (tries < 3);
//
//			cout << "Try Again Later!" << endl;
//
//			return false;
//		}
//	};

class Order {

	// placeOrder (also reciept)
	// edit order
	// update
	// cancel
};

																	///////// main class///////////////

int main() {
	Medicine med;
	med.insert();
	med.update();
	//med.search();
	
	
	



}
