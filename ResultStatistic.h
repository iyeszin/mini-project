#ifndef ResultStatistic_H
#define ResultStatsitic_H

#include<iostream>
#include "studentLinkedList.h"

using namespace std;

class ResultStatistic{
	public:
	    void printResultCourse(string &);
	    void resultsMenu2(string&);	
	    
	    ResultStatistic (studentLinkedList &);
	    
	    
	    
	private:
		int total;
		studentLinkedList student;	
	    courseNode* coursenode;
	   
	    
};

void ResultStatistic::printResultCourse(string& course_code){
         studentNode* current = student.getStudentHead();
         
                 if(current->c_Linkedlist.searchCourse(course_code)){

	       	        cout<<"\nCourse Code: "<<course_code<<endl<<endl;
					cout<<"No\tID\t\tName\t\t\tProgramme\tMarks\tGrade"<<endl;
					cout<<"------------------------------------------------------------------------------"<<endl;
					int i;
					for(i=0; current!=NULL; current=current->link)
					{
						coursenode = current->c_Linkedlist.searchCourse(course_code);
						if(coursenode!=NULL)
						{
							 i++;
							 cout<<i<<"\t"<<current->id<<"\t"<<current->firstname<<" "<<current->lastname<<"\t\t"<<current->programme<<"\t\t"<<coursenode->marks<<"\t"<<coursenode->grade<<endl;
						}
					}
					cout<<"------------------------------------------------------------------------------"<<endl;
					cout<<"Total students: "<<i<<endl;
					cout<<"------------------------------------------------------------------------------"<<endl;
																		
			     }
			     
			     else{
			     	cout<<"Course cannot be found"<<endl;
			     }

		  }

 
 
 
 void ResultStatistic::resultsMenu2(string& course_code){
		
	int grad_A=0;
	int grad_Am=0;
	int grad_Bp=0;
	int grad_B=0; 
	int grad_Bm=0;
	int grad_Cp=0; 
	int grad_C=0;
	int grad_Cm=0; 
	int grad_Dp=0;
	int grad_D=0; 
	int grad_E=0;
	string course_name;
	int total_student;
	
	
	
	studentNode *current = student.getStudentHead();;
		              		
for(int i=0; current!=NULL; current=current->link)
			{
				coursenode = current->c_Linkedlist.searchCourse(course_code);
			if(coursenode!=NULL){
	
		
				if(coursenode->grade=="A")
					grad_A++;
				else if(coursenode->grade=="A-")
					grad_Am++;
				else if(coursenode->grade=="B+")
					grad_Bp++;
				else if(coursenode->grade=="B")
					grad_B++;
				else if(coursenode->grade=="B-")
					grad_Bm++;
				else if(coursenode->grade=="C+")
					grad_Cp++;
				else if(coursenode->grade=="C")
					grad_C++;
				else if(coursenode->grade=="C-")
					grad_Cm++;
				else if(coursenode->grade=="D+")
					grad_Dp++;
				else if(coursenode->grade=="D")
					grad_D++;
				else if(coursenode->grade=="E")
					grad_E++;
			}
						
				
	}
		
	
	
	cout << "Course Code: "<< course_code << ", ";
	cout << "Course Name: " << course_name << endl;
	
	
	cout<<
	"No\tGrade\tTotal Students"<<endl<<
	"------------------------------------"<<endl<<
	"1\t"<<"A\t"<<grad_A<<endl<<
	"2\t"<<"A-\t"<<grad_Am<<endl<<
	"3\t"<<"B+\t"<<grad_Bp<<endl<<
	"4\t"<<"B\t"<<grad_B<<endl<<
	"5\t"<<"B-\t"<<grad_Bm<<endl<<
	"6\t"<<"C+\t"<<grad_Cp<<endl<<
	"7\t"<<"C\t"<<grad_C<<endl<<
	"8\t"<<"C-\t"<<grad_Cm<<endl<<
	"9\t"<<"D+\t"<<grad_Dp<<endl<<
	"10\t"<<"D\t"<<grad_D<<endl<<
	"11\t"<<"E\t"<<grad_E<<endl<<
	"------------------------------------"<<endl<<
	"Total\t\t"<<grad_A+grad_Am+grad_Bp+grad_B+grad_Bm+grad_Cp+grad_C+grad_Cm+grad_D+grad_E<<endl<<
	"------------------------------------"<<endl<<endl;


	
}
 
 
 
 
 
 
 
 
 

	ResultStatistic::ResultStatistic(studentLinkedList &Copy){
		student.copyList(Copy);
	}
	





#endif
