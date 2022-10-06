/*
 * Employee.h
 *
 *  Created on: Dec 12, 2018
 *      Author: Merav And Yiftach
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

class Employee {
private:
	char *firstName;
	int id;
	double salary;
public:
	Employee();
	~Employee();
	Employee(char* newFirstName, int newId, double newSalary);
	Employee (const Employee& other);
	char* getFirstName ()const;
	int getId();
	double getSalary ();
	int getEmployeesCounter();
	bool setFirstName(char* newFirstName);
	bool setId(int newId);
	bool setSalary(double newSalary);
	bool setEmployeesCounter(int newEmployeesCounter);
	int planOfficeParty();
	static int employeesCounter;
	void print()const;
	bool operator==(const Employee& other)const;
	bool operator>(const Employee& other)const;
	Employee& operator=(const Employee& other);
	Employee& operator+(const Employee& other);//######
	Employee& operator++();
	Employee operator++(int x);
	Employee& operator+=(const Employee& other);
	friend std::ostream& operator<< (std::ostream& out, const Employee& toPrint);


};

#endif /* EMPLOYEE_H_ */
