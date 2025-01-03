#include <iostream>
#include <iomanip>
#include "list.h"
using namespace std;

FlowList::FlowList() : head(nullptr) {}

FlowList::~FlowList() {
    clear();	
}



Node* FlowList::getHead() const {

    return head;
}


void FlowList::insert(const ListItem& newItem) {
	
    if (exists(newItem.year)) {
		
        cout << "Error: duplicate data." << endl;
		
        return;
    }

    Node* newNode = new Node{newItem, nullptr};
	
    if (!head || head->item.year > newItem.year) {
		
        newNode->next = head;
        head = newNode;
		
    } else {
		
        Node* current = head;
        while (current->next && current->next->item.year < newItem.year) {
            current = current->next;
        }
		
        newNode->next = current->next;
        current->next = newNode;
		
    }
	
    cout << "New record inserted successfully." << endl;
}

void FlowList::remove(int year) {
	
    if (!head || !exists(year)) {
		
        cout << "Error: No such data." << endl;
        return;
    }

    Node* doomed = nullptr;
    if (head->item.year == year) {
		
        doomed = head;
        head = head->next;
		
    } else {
		
        Node* current = head;
        while (current->next && current->next->item.year != year) {
			
            current = current->next;
			
        }
		
        doomed = current->next;
        current->next = doomed->next;
		
    }
	
	
    delete doomed;
    cout << "Record was successfully removed." << endl;
	
}

void FlowList::display() const {
	
	
    if (!head) {
		
        cout << "No data available." << endl;
        return;
		
    }

    cout << "Year     Flow (in billions of cubic meters)" << endl;
    cout << "-------------------------------------------" << endl;

    Node* current = head;
    while (current) {
		
        cout << current->item.year << "      " << fixed << setprecision(1) << current->item.flow << endl;
        current = current->next;
		
    }
	
    cout << "-------------------------------------------" << endl;
	
}

double FlowList::average() const {
	
    if (!head) return 0.0;

    double total = 0;
    int count = 0;
    Node* current = head;
	
	
    while (current) {
		
        total += current->item.flow;
        count++;
        current = current->next;
    }
	
	
    return total / count;
	
}

void FlowList::clear() {
	
	
    while (head) {
		
        Node* temp = head;
        head = head->next;
        delete temp;
		
		
    }
	
}

bool FlowList::exists(int year) const {
	
    Node* current = head;
    while (current) {
		
		
        if (current->item.year == year) return true;
        current = current->next;
		
    }
	
	
    return false;
	
	
}