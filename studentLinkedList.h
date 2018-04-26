#ifndef H_studentLinkedList
#define H_studentLinkedList

#include<iostream>
#include <cassert>
#include"courseLinkedList.h"

using namespace std;

struct studentNode{
	
	string id; 
	string firstname; 
	string lastname;
	string faculty; 
	string programme; 
	float cgpa;
	string grad_class; 
	courseLinkedList c_Linkedlist;
	
	studentNode *link;
};	

class studentLinkedList{
	
public:	
						   
	void initializeList();
						   
	bool isEmptyList() const;
	
	int length();
	
	void destroyList();
		
	void addStudent(studentNode *&);
	
	void updateStudent(string id);	
	
	void deleteStudent(string id);
	
	void searchAndPrintStudent(string identity);	
	
	void printAll();
	
	bool searchID(string id);
	
	string get_grad(float cgpa);
	
	void addCourse(courseNode *&);
	
	bool validateID(string id);
	
	studentNode* searchStudent(string id);
	
	bool validateCourseCode(string courseCode);
	
	bool searchCode(string coursecode);
	
	studentNode* getStudentHead();
	
	void copyList(studentLinkedList &);
	
	studentLinkedList();
	
	~studentLinkedList();
	

protected :
		int count;
		studentNode *first = NULL;
		studentNode *last;

};
	

void studentLinkedList::initializeList(){
	destroyList();
}	
		
bool studentLinkedList::isEmptyList() const{
	return (first == NULL);
}
	
int studentLinkedList::length(){
	return count;
}

void studentLinkedList::destroyList(){
	studentNode *temp;
	
	while(first!=NULL){
		temp = first;
		first = first->link;
		delete temp;	
	}
	
	last = NULL;
	
	count = 0;
}

void studentLinkedList::addStudent(studentNode *& newStudent){
	
	studentNode *student = new studentNode;
	assert(student != NULL);
	
	student->id = newStudent->id;
	student->firstname = newStudent->firstname;
	student->lastname = newStudent->lastname;
	student->faculty = newStudent->faculty;
	student->programme = newStudent->programme;
	//student->cgpa = student->c_Linkedlist.calculateCgpa(); // use to calculate the cgpa one
	//student->grad_class = get_grad(student->cgpa); // use to get the grade class
	
	student->link = NULL;
	
	
	bool found;
	studentNode *current;
	studentNode *trailcurrent;
	
	
	if(first == NULL){
		first = student;
		count++;
	}	
	else{
		current = first;
		found = false;
		
		while(current != NULL && !found)
			if(current->id >= student->id)
				found = true;
			else{
				trailcurrent = current;
				current = current->link;}
			
		if(current == first){
			student->link = first;
			first = student;
			count++;
		}
		else{
			trailcurrent->link = student;
			student->link = current;
			count++;
		}
	}
	
}

void studentLinkedList::updateStudent(string id){
	
	studentNode *current;
	
	string id_1; 
	string firstname_1; 
	string lastname_1;
	string faculty_1; 
	string programme_1; 
	float cgpa_1;
	int choice;

	if(searchID(id)){
		current = first;
		
		while(current != NULL)
			if(current->id == id)
				break;
		else
			current = current->link;
		
		do{
			cout << "1. Update student ID" << endl;
	
			cout << "2. Update first name"<< endl;
	
			cout << "3. Update last name"<< endl;

			cout << "4. Update faculty"<< endl;
	
			cout << "5. Update programme" << endl;
		
			cout << "6. Finish" << endl;

			cout << "Choice: " ;
			cin >> choice;
	
			switch(choice){
				case 1:
					cout << "Enter new student id: ";
					cin >> id_1;	
					current->id = id_1;
					cout << "ID Updated." << endl;
					break;
				case 2:
					cout << "Enter new first name: ";
					cin >> firstname_1;
					current->firstname = firstname_1;
					cout << "First Name Updated." << endl;
					break;
				case 3:
					cout << "Enter new last name: ";
					cin >> lastname_1;
					current->lastname = lastname_1;
					cout << "Last Name Updated." << endl;
					break;
				case 4:
					cout << "Enter new faculty (FSM, FPL, FKS, FPP, FKA): ";
					cin >> faculty_1;
					current->faculty = faculty_1;
					cout << "Faculty Updated." << endl;
					break;
				case 5:
					cout << "Enter new programme (HM00, HM07, HL64, HL32, HK04, HK08, HP05, HP07, HA06, HA09): "<< endl;
					cin >> programme_1;
					current->programme = programme_1;
					cout << "Programme Updated." << endl;
					break;
				case 6:
					break;
			}
			
		}while(choice != 6);
	
	}
	else
		cout << "The student is not in the list." << endl;	
	
	
}
	
void studentLinkedList::deleteStudent(string id){
	
	
	studentNode *current;
	studentNode *trailCurrent;
	bool found;
	
	if(first == NULL)
		cerr<<"Cannot delete from an empty list.\n";
	else{
		if(first->id == id){
			current = first;
			first = first->link;
			count --;
		
		    if(first == NULL)
			    last = NULL;
				delete current;
				
			cout << "Item has been deleted." << endl;
		}
		else{
			
			found = false;
			trailCurrent = first;
			
			current = first->link;
			
			
			while(current !=NULL && !found){
				
				if(current->id != id){
					trailCurrent = current;
					current = current ->link;
				}
				else
					found = true;
			}
			
			if(found){
				trailCurrent->link = current->link;
				count--;
				
				if(last == current)	
			 	   last = trailCurrent;
			 	   
			    delete current;   
			    cout << "Item has been deleted." << endl;
			}
		    else
			    cout<< "Item to be deleted is not in the list." <<endl;	
    	}
	}
		
}

void studentLinkedList::searchAndPrintStudent(string identity){
	
	studentNode *current;
	current = first;

	
	while(current != NULL){
		if(current->id == identity)
		{
			cout << "ID : " << current->id << endl;
			cout << "Name : " << current->firstname << " " << current->lastname << endl;
			cout << "Faculty : " << current->faculty << endl;
			cout << "Programme : " << current->programme << endl;
			cout << "CGPA : " << current->cgpa << endl;
			cout << "Class : " << current->grad_class << endl << endl;
			
			break;
		}
		else
			current = current ->link;
	}
	
	if(current == NULL)
		cout << "There is no such student in the list." << endl;
	
}
	
void studentLinkedList::printAll(){
	studentNode *current;
	current = first;
	while (current != NULL){
		cout << "ID : " << current->id << endl;
		cout << "Name : " << current->firstname << " " << current->lastname << endl;
		cout << "Faculty : " << current->faculty << endl;
		cout << "Programme : " << current->programme << endl;
		cout << "CGPA : " << current->cgpa << endl;
		cout << "Class : " << current->grad_class << endl << endl;
		
		current = current->link;
		cout << endl;
	}
	
}

bool studentLinkedList::searchID(string id){
	
	studentNode *current;
	bool found;
	
	current = first;
	found = false;
	
	while(current != NULL && !found)
		if(current->id == id)
			found = true;
		else
			current = current ->link;
	
	return found;
}
	
string studentLinkedList::get_grad(float cgpa){
	
	if(cgpa >=3.67)
		return "First";
	else if(cgpa <3.67 && cgpa > 2.99)
		return "Second Upper";
	else if(cgpa < 3.00 && cgpa > 1.99)
		return "Second Lower";
	else if(cgpa < 2.00)
		return "Failed";
}
	
void studentLinkedList::addCourse(courseNode *&newCourse){
	studentNode *current = first;

	bool found = false;
	
	while (current != NULL && !found) {
		if (current->id == newCourse->id) 
			found = true;
		else 
			current = current->link;
	}

	if(found)
		current->c_Linkedlist.Add_Course(newCourse);
	else 
		cout << "The student is not found." << endl;
	

}


bool studentLinkedList::validateID(string id){
	
	string faculty_id;
	string number_id;

	if (id.length() != 9) 
		return false;
	
	else
	{
		faculty_id = id.substr(0,3);
		if(faculty_id == "FSM" || faculty_id == "FPL" || faculty_id == "FKS" || faculty_id == "FPP" || faculty_id == "FKA")
		{
			string number_id = id.substr(3,9);
				if (!isdigit(number_id.at(0)) && !isdigit(number_id.at(1)) && !isdigit(number_id.at(2)) && 
				    !isdigit(number_id.at(3)) && !isdigit(number_id.at(4)) && !isdigit(number_id.at(5))) 
					return false;
			
			return true;
		}
		else return false;
	} 
}

bool studentLinkedList::validateCourseCode(string courseCode){
	
	string faculty;
	string year;
	string sem;
	string cc;

	if (courseCode.length() != 9) 
		return false;
	
	else
	{
		faculty = courseCode.substr(0,3);
		if(faculty== "FSM" || faculty == "FPL" || faculty== "FKS" || faculty== "FPP" || faculty== "FKA")
		{
			     year = courseCode.substr(3,5);
				if (!isdigit(year.at(0)) && !isdigit(year.at(1)))
				return false; 
				   
				sem = courseCode.substr(5,7);
				if (!isdigit(sem.at(0)) && !isdigit(sem.at(1)))
				return false; 
				
				cc = courseCode.substr(7,9);
				if (!isdigit(cc.at(0)) && !isdigit(cc.at(1)))
				return false; 
				 
				 	
			
			return true;
		}
		else return false;
	} 
}


bool studentLinkedList::searchCode(string coursecode){
	
	studentNode *current;
	bool found;
	
	current = first;
	found = false;
	
	while(current != NULL && !found)
		if(!current->c_Linkedlist.searchCourse(coursecode))
			found = true;
		else
			current = current ->link;
	
	return found;
	
	
}










studentNode* studentLinkedList::getStudentHead() {
	return first;
}





studentNode* studentLinkedList::searchStudent(string id){
	studentNode* current = first;
	while (current != NULL) 
	{
		if (current->id == id) 
			return current;
		else 
			current = current->link;
	}
}


void studentLinkedList::copyList(studentLinkedList &otherlist){
	studentNode *newNode;
	studentNode *current;
	studentNode *thiscurrent;
	
	if(first != NULL){
		initializeList();
	}
	
	if(otherlist.first == NULL){
		first = NULL;
		count = 0;
	}else{
		current = otherlist.first;
		count = otherlist.count;
		
		first = new studentNode;
		first->id = current->id;
		first->firstname = current->firstname;
		first->lastname = current->lastname;
		first->programme = current->programme;
		first->faculty = current->faculty;
		first->cgpa = current->cgpa;
		first->grad_class = current->grad_class;
		first->c_Linkedlist.copyList(current->c_Linkedlist);
		first->link = NULL;
		thiscurrent = first;
		current = current->link;
		
		while(current != NULL){
			newNode = new studentNode;
			newNode->id = current->id;
			newNode->firstname = current->firstname;
			newNode->lastname = current->lastname;
			newNode->programme = current->programme;
			newNode->faculty = current->faculty;
			newNode->cgpa = current->cgpa;
			newNode->grad_class = current->grad_class;
			newNode->c_Linkedlist.copyList(current->c_Linkedlist);
			newNode->link = NULL;
			thiscurrent->link = newNode;
			thiscurrent = thiscurrent->link;
			current = current->link;	
		}
	}
}








//constructor
studentLinkedList::studentLinkedList(){
	first = NULL;
	last = NULL;
	count = 0;
}

//destructor
studentLinkedList::~studentLinkedList(){
	destroyList();
}

	
#endif   

