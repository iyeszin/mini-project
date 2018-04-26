#ifndef courseLinkedList_H
#define courseLinkedList_H

#include<iostream>
#include<cassert>
#include<string>

using namespace std;

struct courseNode{
      	string id;
		string course_code;
		string course_name;
		int credit_hour;
		string grade;
		int marks;
		string status;
	  	courseNode* nextCourse;
		  	
};

class courseLinkedList{
	public:
		void initializeList();
		void destroyList();
		void Add_Course(courseNode *& Course);
		void Update_Results(string id);
		float calculateCgpa();
		void Delete_Course(string id);
		void Search_Display(string course_code);
		courseNode* searchCourse(string course);
		courseNode* getCourseHead();
		bool searchCourseCode(string coursecode);
		void copyList(courseLinkedList &);
		
		
	private:	
	   	string update_course_code;
		string update_course_name;
		int update_credit_hour;	
	  	string update_grade;
	   	int update_marks;
	   	string update_status;
	   	string student_update;
	   	string student_delete;
	   	string delete_course;
	   	string search;
	   	string matric;
	   	string change_course_code;
		courseNode *begin=NULL;
		courseNode *new_nextCourse;
		courseNode *last;
		courseNode *nextcurrent;
		int count;
		int option;

};

void courseLinkedList:: Add_Course(courseNode *& Course){
          
	    new_nextCourse=new courseNode;
	    new_nextCourse->id= Course->id;
     	new_nextCourse->course_code=Course->course_code;
     	new_nextCourse->course_name=Course->course_name;
     	new_nextCourse->credit_hour=Course->credit_hour;
     	new_nextCourse->marks=Course->marks;;
        new_nextCourse->grade=Course->grade;;
        new_nextCourse->status=Course->status;;
        
             
    bool found;
	courseNode *current;
	courseNode *trailcurrent;
	
	
	if(begin == NULL){
		begin = new_nextCourse;
		new_nextCourse->nextCourse = NULL;
		count++;
	}	
	else{
		current = begin;
		found = false;
		
		while(current != NULL && !found)
			if(current->id >= new_nextCourse->id)
				found = true;
			else{
				trailcurrent = current;
				current = current->nextCourse;}
			
		if(current == begin){
			new_nextCourse->nextCourse = begin;
			begin = new_nextCourse;
			count++;
		}
		else{
			trailcurrent->nextCourse = new_nextCourse;
			new_nextCourse->nextCourse = current;
			count++;
		}
	}     
             
}
    
     

void courseLinkedList::Update_Results(string id){

	courseNode *current;	        
	current=begin;
	
	 cout<<"Enter course code to be change"<<endl;
	cin>>change_course_code;
	     
	
	while (current!=NULL){
		 	
		 if(id==current->id && change_course_code==current->course_code){
	     	 
			     do{
			     	cout<<"1. Update Course Code"<<endl;
			     	cout<<"2. Update Course Name"<<endl;
			     	cout<<"3. Update Credit Hours" << endl;
			     	cout<<"4. Update Marks" <<endl;
			     	cout<<"5. Exit"<<endl;
			        cout<<"Enter an option to update" <<endl;
			        cin>>option;
			        
			        switch (option){
			            case 1:
						      cout<<"Enter course code to be update"<<endl;
						      cin>>update_course_code;
						      current->course_code=update_course_code;
						      break;
						case 2:
						      cout<<"Enter course name to be update"<<endl;
						      cin>>update_course_name;
						      current->course_name=update_course_name;
						      break;
						case 3:
							  cout<<"Enter credit hours to be update"<<endl;
						      cin>>update_credit_hour;
						      current->credit_hour=update_credit_hour;
						      break;
						case 4:
				              cout<<"Enter marks given:"<<endl;
		            		  cin>>update_marks;
			             			do{
			                			if(update_marks>=80 && update_marks<=100)
				                			update_grade="A";
				                		else if(update_marks>=75 && update_marks<=79)
				                			update_grade="A-";
										else if(update_marks>=70 && update_marks<=74)
											update_grade="B+";
										else if (update_marks>=65 && update_marks<=69)
											update_grade="B";
										else if(update_marks>=60 && update_marks<=64)
											update_grade="B-";
										else if(update_marks>=55 && update_marks<=59)
											update_grade="C+";
										else if(update_marks>=50 && update_marks<=54)
											update_grade="C";
										else if(update_marks>=45 && update_marks<=49)
											update_grade="C-";
										else if(update_marks>=40 && update_marks<=44)
											update_grade="D+";
										else if (update_marks>=35 && update_marks<=39)
											update_grade="D";
										else if( update_marks>=0 && update_marks <=34)
											update_grade="E";
										else
										cout<<"Value not in range of 0-100.Please enter again"<<endl;
								   	  }while(update_marks<0 || update_marks>100);
							   	  
								   current->marks=update_marks;
					               current->grade=update_grade;
					              	  
								   if(update_grade=="E"){
					               update_status="Failed";
					               }
					               else if(update_grade=="C-" | update_grade=="D+" | update_grade=="D"){
					               update_status="Partially Failed";
					               }
					               else{
					               update_status="Pass";
					               }
					               current->status=update_status;
					               break;
					    case 5:
					    	cout<<"Thank you for using this function"<<endl;
					    	break;
					    default:
						     cout<<"Please enter the option correctly"<<endl;	
				    	
	     
	                }
	             }while(option!=5);
	          
	             
	            
         }
              		
	     else{   
	     	if(current==NULL)
		    cout<<"Invalid identification"<<endl;
	     }
	     
	current=current->nextCourse;
    }
}

void courseLinkedList::Delete_Course(string id){
	
	
	courseNode *current;
	current=begin;
	
	while (current!=NULL){
		
		if(student_delete==current->id){
	
		cout<<"Enter the course code to be deleted"<<endl;
		cin>>delete_course;
		
			if(begin==NULL){
			cout<<"Cannot delete from an empty list"<<endl;
			}
			
			else{
			    current=begin;
				if(delete_course==current->course_code){
					if(current==begin){
					begin=current->nextCourse;
					delete current;
					current=NULL;			
				    }
			    }
			    else{
			    	current=begin;
			    	nextcurrent=current->nextCourse;
			    	while(nextcurrent!=NULL){
			    	   if(delete_course==nextcurrent->course_code){
			    	   	current->nextCourse=nextcurrent->nextCourse;
			    	   	delete nextcurrent;
			    	   	nextcurrent=NULL;;
			    	   }
					 current=current->nextCourse;
					 nextcurrent=nextcurrent->nextCourse;  	
			    	}
				}
		    }
	    }
	    
	    else{
	    	if(current==NULL)
		    cout<<"Invalid identification"<<endl;
	    }
	current=current->nextCourse;
	}
}

void courseLinkedList::Search_Display(string course_code){
	
	courseNode *current;
	current=begin;
	if(current == NULL)
		cout << "This course could not be found" << endl;
	else{
		current = searchCourse(course_code);
		if(current!=NULL){
			    cout<<"Student ID:"<<current->id<<endl;
			    cout<<"Course Code:"<<current->course_code<<endl;
			    cout<<"Course Name:"<<current->course_name<<endl;
			    cout<<"Credit Hour of Course:"<<current->credit_hour<<endl;
			    cout<<"Marks of Course:"<<current->marks<<endl;
			    cout<<"Grade of Course:"<<current->grade<<endl;
			    cout<<"Status:"<<current->status<<endl<<endl;	 	   
		}
	 
    }
}



float courseLinkedList::calculateCgpa() 
{
	courseNode* current = begin;
	float gradepts, numerator, sumCreditHour; 
	
	while(current!=NULL)
	{
									if(current->marks>=80 && current->marks<=100)
			                			gradepts=4.00;
			                		else if(current->marks>=75 && current->marks<=79)
			                			gradepts=3.67;
									else if(current->marks>=70 && current->marks<=74)
									    gradepts=3.33;
									else if (current->marks>=65 && current->marks<=69)
										gradepts=3.00;
									else if(current->marks>=60 && current->marks<=64)
										gradepts=2.67;
									else if(current->marks>=55 && current->marks<=59)
										gradepts=2.33;
									else if(current->marks>=50 && current->marks<=54)
										gradepts=2.00;
									else if(current->marks>=45 && current->marks<=49)
										gradepts=1.67;
									else if(current->marks>=40 && current->marks<=44)
										gradepts=1.33;
									else if (current->marks>=35 && current->marks<=39)
										gradepts=1.00;
									else if( current->marks>=0 && current->marks <=34)
										gradepts=0;

		numerator = numerator + (gradepts*current->credit_hour);
		sumCreditHour = sumCreditHour + current->credit_hour;
		current = current->nextCourse;
	}
	
	return numerator/sumCreditHour;
}

courseNode* courseLinkedList::searchCourse(string course)
{	
	courseNode* current = begin;
	while (current != NULL) 
	{
		if (current->course_code == course) 
			return current;
		else 
			current = current->nextCourse;
	}
}

courseNode* courseLinkedList::getCourseHead(){
	return begin;
}


void courseLinkedList::copyList(courseLinkedList &otherlist){
	courseNode *newNode;
	courseNode *current;
	courseNode *thiscurrent;
	
	if(begin != NULL){
		initializeList();
	}
	
	if(otherlist.begin == NULL){
		begin = NULL;
		count = 0;
	}else{
		current = otherlist.begin;
		count = otherlist.count;
		
		begin = new courseNode;
		begin->id= current->id;
     	begin->course_code=current->course_code;
     	begin->course_name=current->course_name;
     	begin->credit_hour=current->credit_hour;
     	begin->marks= current->marks;
        begin->grade=current->grade;
        begin->status=current->status;

		begin->nextCourse = NULL;
		thiscurrent = begin;
		current = current->nextCourse;
		
		while(current != NULL){
			newNode = new courseNode;
			newNode->id = current->id;
			newNode->course_code = current->course_code;
			newNode->course_name = current->course_name;
			newNode->credit_hour = current->credit_hour;
			newNode->marks = current->marks;
			newNode->grade = current->grade;
			newNode->status = current->status;
			//there is a line to nextCourse course of copylist
			newNode->nextCourse = NULL;
			thiscurrent->nextCourse = newNode;
			thiscurrent = thiscurrent->nextCourse;
			current = current->nextCourse;	
		}
	}
}




void courseLinkedList::initializeList(){
	destroyList();
}	



void courseLinkedList::destroyList(){
	courseNode *temp;
	
	while(begin!=NULL){
		temp = begin;
		begin = begin->nextCourse;
		delete temp;	
	}
	
	last = NULL;
	
	count = 0;
}


bool courseLinkedList::searchCourseCode(string coursecode){
	
	
	courseNode *current;
	bool found;
	
	current = begin;
	found = false;
	
	while(current != NULL && !found)
		if(current->course_code == coursecode)
			found = true;
		else
			current = current ->nextCourse;
	
	return found;
	
}







#endif

