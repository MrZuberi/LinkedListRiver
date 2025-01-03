#ifndef HYDRO_H
#define HYDRO_H
#include "list.h"

void displayHeader();

int readData(FlowList& list);

void display(const FlowList& list);

void addData(FlowList& list);

void removeData(FlowList& list);

void saveData(const FlowList& list);

int menu();

void pressEnter();

#endif