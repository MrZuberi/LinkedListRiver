#include <iostream>
#include <fstream>
#include <string>
#include "hydro.h"
using namespace std;

void displayHeader() {
	
    cout << "Program: River Flow Data Linked List, Fall 2024" << endl;
    cout << "Version: 1.0" << endl;
    cout << "Lab Section: L01" << endl;
    cout << "Produced by: Taha Zuberi" << endl;
    pressEnter();
	
}

int readData(FlowList& list) {
	
	
    ifstream file("flow.txt");
	
    if (!file) {
		
        cerr << "Error: Cannot open file." << endl;
        exit(1);
		
    }

    int count = 0;
    ListItem temp;
	
	
    while (file >> temp.year >> temp.flow) {
		
		
        list.insert(temp);
        count++;
		
    }
	
    file.close();
    return count;
	
}

void display(const FlowList& list) {
	
	
    list.display();
    cout << "The annual average of the flow is: " << list.average() << " billions of cubic meters." << endl;
    pressEnter();
	
}

void addData(FlowList& list) {
	
	
    ListItem newItem;
    cout << "Please enter a year: ";
    cin >> newItem.year;
    cout << "Please enter the flow: ";
    cin >> newItem.flow;
    list.insert(newItem);
    pressEnter();
	
	
}

void removeData(FlowList& list) {
	
	
    int year;
    cout << "Please enter the year that you want to remove: ";
    cin >> year;
    list.remove(year);
    pressEnter();
	
	
}


void saveData(const FlowList& list) {
	
	
    ofstream file("flow.txt");
	
	
    if (!file) {
		
        cerr << "Error: Cannot open file." << endl;
        return;
		
    }

    Node* current = list.getHead();
	
	
    while (current) {
		
        file << current->item.year << " " << current->item.flow << endl;
        current = current->next;
		
    }
	
    file.close();
	
	
    cout << "Data are saved into the file." << endl;
	
    pressEnter();
	
	
}

int menu() {
	

    cout << "Please select one of the following operations:" << endl;
    cout << "1. Display flow list, and the average" << endl;
    cout << "2. Add data" << endl;
    cout << "3. Save data into the file" << endl;
    cout << "4. Remove data" << endl;
    cout << "5. Quit" << endl;
    cout << "Enter your choice (1, 2, 3, 4, or 5): ";
	
	
    int choice;
	
    cin >> choice;
	
    return choice;
	
}

void pressEnter() {
	
    cout << "\n<<< Press Enter to Continue >>>>" << endl;
	
	
    cin.ignore();
    cin.get();
}

int main() {
	
	
    FlowList list;
    int numRecords;

    displayHeader();
	
    numRecords = readData(list);
	
    bool quit = false;

    while (!quit) {
		
        switch (menu()) {
			
            case 1:
                display(list);
                break;
				
            case 2:
                addData(list);
                break;
				
            case 3:
                saveData(list);
                break;
				
            case 4:
                removeData(list);
                break;
				
            case 5:
                cout << "Program terminated successfully.\n";
                quit = true;
                break;
				
            default:
                cout << "Invalid input. Please try again.\n";
				
        }
		
    }

    return 0;
}