/*
 * Employee.cpp
 *
 *  Created on: Dec 12, 2018
 *      Author: ise
 */

#include "Employee.h"

int Employee::employeesCounter=0;

Employee::Employee() {
	// TODO Auto-generated constructor stub

	firstName = new char[5];
	firstName = (char*)"Name";
	id = 0;
	salary = 0;
	Employee::employeesCounter++;

}

Employee::~Employee() {
	// TODO Auto-generated destructor stub
	Employee::employeesCounter--;
	delete[] firstName;
}


Employee::Employee(char* newFirstName, int newId, double newSalary){
	this->firstName=new char[strlen(newFirstName)];
	strcpy(this->firstName,newFirstName);
	this->id=newId;
	this->salary=newSalary;
	Employee::employeesCounter++;
}
Employee::Employee (const Employee& other){
	this->firstName=new char[strlen(other.firstName)];
	strcpy(this->firstName,other.firstName);
	this->id=other.id;
	this->salary=other.salary;
	//Employee::employeesCounter++;
}
char* Employee::getFirstName ()const{ //###Maybe there is no need for a copy of the name - if remains likely that the user possibly (probably) should free the copy
	//char* tempFirstName = new char[sizeof(firstName)];
	//strcpy (tempFirstName,firstName);
	return firstName;
}
int Employee::getId(){
	return id;
}
double Employee::getSalary (){
	return salary;
}

int getEmployeesCounter()
{
	return Employee::employeesCounter;
}

bool Employee::setFirstName(char* newFirstName){
	//char* tempFirstName = new char[sizeof(newFirstName)];//###Maybe not required
	//if (tempFirstName == NULL){//###
	//	return false;//###
	//}//###
	delete[]firstName;
	//strcpy (newFirstName,newFirstName);
	this->firstName=new char[strlen(newFirstName)*sizeof(char)];
	strcpy(this->firstName,newFirstName);
	return true;
}
bool Employee::setId(int newId){
	id=newId;
	return true;

}
bool Employee::setSalary(double newSalary){
	salary = newSalary;
	return true;
}

bool setEmployeesCounter(int newEmployeesCounter)
{
	setEmployeesCounter(newEmployeesCounter);
	return true;
}

int Employee::planOfficeParty()
{
	return (Employee::employeesCounter)*10;
}

void Employee::print() const
{
	cout << "Name:" << this->firstName << "\nID:" << id << "\nSalary:" << salary << "\n";
}

bool Employee::operator==(const Employee& other)const
				{
	return id==other.id;
				}

bool Employee::operator>(const Employee& other)const
{
	return salary>other.salary;
}

Employee& Employee::operator=(const Employee& other)
{
	this->setFirstName(other.firstName);
	return *this;
}
Employee& Employee::operator+(const Employee& other)
{
	this->setSalary(other.salary+this->getSalary());
	return *this;
}

Employee& Employee::operator++()
				{
	this->setSalary(this->getSalary()+100);
	return *this;
				}

Employee Employee::operator++(int x)
				{
	Employee temp(*this);
	++(*this);
	return temp;
				}

Employee& Employee::operator+=(const Employee& other)
{
//	char* newFirstName = new char[sizeof(this->getFirstName()) + (sizeof(char)*strlen(other.firstName))];
	char* newFirstName = new char[strlen(this->firstName) + strlen(other.firstName)];
	strcpy(newFirstName,this->getFirstName());
	//strcat(newFirstName, other.firstName);
	int i;
	for(i=0; i<(int)(strlen(other.firstName));i++){
		char charToCat = other.getFirstName()[i];
		int index = i + (int)(strlen(this->getFirstName()));
		newFirstName[index] = charToCat;
	}
	newFirstName[i + (int)(strlen(this->getFirstName()))] = '\0';
	this->setFirstName(newFirstName);//###
	return *this;
}

ostream& operator<< (ostream& out, const Employee& toPrint)
{
	toPrint.print();
	return out;
}
