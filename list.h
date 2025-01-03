#ifndef LIST_H
#define LIST_H

struct ListItem {
	
    int year;
    double flow;
	
};

struct Node {
	
    ListItem item;
    Node* next;
	
};

class FlowList {
	
private:

    Node* head;

public:

	Node* getHead() const;
    FlowList();
    ~FlowList();
    void insert(const ListItem& newItem);
    void remove(int year);
    void display() const;
    double average() const;
    void clear();
    bool exists(int year) const;
	
};

#endif