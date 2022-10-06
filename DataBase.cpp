/*
 * DataBase.cpp
 *
 *  Created on: Dec 12, 2018
 *      Author: ise
 */

#include "DataBase.h"

DataBase::DataBase() {
	// TODO Auto-generated constructor stub
	employees = new Employee*[sizeof(Employee)*3];
	sizeOfEmployees = 3;
	numberOfEmployees = 0;
}

DataBase::~DataBase() {
	// TODO Auto-generated destructor stub
	int i;
	for (i=0; i<numberOfEmployees; i++){
		delete employees[i];
	}
	delete[]employees;
}

DataBase::DataBase(Employee** newEmployees,int newSizeOfEmployees, int newNumberOfEmployees){
	this->employees=new Employee*[newSizeOfEmployees*sizeof(Employee*)];
	int i=0;
	for (i=0; i<newNumberOfEmployees; i++){
		this->employees[i] = new Employee(*newEmployees[i]);
	}
	this->numberOfEmployees=newNumberOfEmployees;
	sizeOfEmployees = newSizeOfEmployees;
}
DataBase::DataBase (const DataBase& other){
	this->employees=new Employee*[sizeof(other.sizeOfEmployees)*sizeof(Employee*)];
	int i=0;
	for (i=0; i<other.numberOfEmployees; i++){
		this->employees[i] = new Employee(*other.employees[i]);
	}
	this->numberOfEmployees=other.numberOfEmployees;
	sizeOfEmployees = other.sizeOfEmployees;
}
Employee** DataBase::getEmployees (){
	return employees;
}
int DataBase::getNumberOfEmployees(){
	return numberOfEmployees;
}

/*
bool DataBase::setEmployees(Employee** newEmployees){
	delete[]employees;
	Employee** tempEmploeyees = new Employee*[sizeof(newEmployees)];
	int i=0;
	for (i=0; i<(int)((sizeof(newEmployees)/sizeof(Employee*))); i++){
		tempEmploeyees[i] = new Employee(*newEmployees[i]);
	}
	employees = tempEmploeyees;
	return true;
}
 */

bool DataBase::setNumberOfEmployees(int newNumberOfEmployees){
	numberOfEmployees = newNumberOfEmployees;
	return true;
}

int DataBase::getEmployeesLength (){
	return sizeOfEmployees;
}

Employee* DataBase::getEmployee (int searchId){
	int i;
	for (i=0; i<getEmployeesLength(); i++){
		if (employees[i]->getId() == searchId){
			return employees[i];
		}
	}
	return NULL;
}

void DataBase::addEmployee (Employee *employeeToAdd){
	bool employeeExists=false;
	int i;
	for (i=0; i<numberOfEmployees;i++){
		if(employees[i]->getId() == employeeToAdd->getId()){
			cout << "This employee is already in the database\n"<<endl;
			employeeExists=true;
			delete employeeToAdd;
		}
	}
	if (numberOfEmployees == getEmployeesLength() && employeeExists== false){
		Employee** tempEmploeyees = new Employee*[(sizeof(Employee)*numberOfEmployees)*2];
		sizeOfEmployees = sizeOfEmployees*2;
		int j;
		for (j=0; j<numberOfEmployees;j++){
			Employee* copyEmployee = new Employee(*employees[j]);
			tempEmploeyees[j] = copyEmployee;
		}
		delete[] employees;
		employees=tempEmploeyees;
	}
	if(employeeExists == false){
		employees[numberOfEmployees]= new Employee (*employeeToAdd);
		numberOfEmployees++;
	}
}
void DataBase::removeEmployee(int employeeId)
{
	bool found=false;
	int i;
	int index=-1;
	for (i=0; i<numberOfEmployees && found == false;i++){
		if(employees[i]->getId() == employeeId){
			found=true;
			index=i;
		}
	}
	if(found == false)
	{
		cout << "This employee isn't in the database\n\n";
	}
	else
	{
		delete employees[index];
		int j;
		for(j=index+1;j<numberOfEmployees;j++)
		{
			employees[j-1]=employees[j];
		}
		numberOfEmployees--;
		if (numberOfEmployees <= getEmployeesLength()/2 && sizeOfEmployees>3)
		{
			int newSize = (sizeOfEmployees*sizeof(Employee))/2;
			Employee** tempEmploeyees = new Employee*[newSize];
			int k;
			sizeOfEmployees = sizeOfEmployees/2;
			for (k=0; k<numberOfEmployees;k++)
			{
				//Employee* copyEmployee = new Employee(*employees[k]);
				tempEmploeyees[k] = new Employee(*employees[k]);
			}
			int l;
			for (l=0; l<numberOfEmployees; l++){
				delete employees[l];
			}
			//delete employees;
			Employee::employeesCounter = Employee::employeesCounter + k;
			employees=tempEmploeyees;
		}
	}
}

void DataBase::print()const
{
	cout << "Employees database:\n\n";
	int i;
	for (i=0; i<numberOfEmployees;i++){
		cout <<(*employees[i])<<endl; //###Last Operator to overlap
	}
}

