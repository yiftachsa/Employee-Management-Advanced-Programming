/*
 * DataBase.h
 *
 *  Created on: Dec 12, 2018
 *      Author: ise
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Employee.h"

using namespace std;

class DataBase {
	Employee** employees;
	int sizeOfEmployees;
	int numberOfEmployees;
public:
	DataBase();
	~DataBase();
	DataBase(Employee** newEmployees,int newSizeOfEmployees, int newNumberOfEmployees);
	DataBase (const DataBase& other);
	Employee** getEmployees ();
	int getNumberOfEmployees();
	//bool setEmployees(Employee** newEmployees);
	bool setNumberOfEmployees(int newNumberOfEmployees);
	Employee* getEmployee (int searchId);
	int getEmployeesLength ();
	void addEmployee (Employee *employeeToAdd);
	void removeEmployee(int employeeId);
	void print()const;
};

#endif /* DATABASE_H_ */
