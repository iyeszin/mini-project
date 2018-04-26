#include<iostream>
#include"studentLinkedList.h"
#include"studentStatistics.h"
#include"ResultStatistic.h"
using namespace std;

int main(void){
	
	studentLinkedList student_list;
	courseLinkedList course_list;
	
	int choice,choice2;
	char option,option2;
	string id2;
	string course_code2;
	string course_name2;
	int credit_hour2;
	int marks2;
	string grade2;
	string status2;
	
	do{	
	
		cout << "====== STUDENT DATABASE MANAGEMENT SYSTEM ======" << endl;
		cout << "Select a choice:" 	<< endl;
		cout << "1. Manage student" << endl;
		cout << "2. Manage results" << endl; 
		cout << "3. View statistics of students menu" << endl;
		cout << "4. View statistics of result menu" << endl;
		cout << "5. Exit program" << endl;
		cout << "Choice: ";
		cin >> choice;
		switch(choice){
	
			case 1:
				do{
					cout << endl;
					cout << "====== STUDENT PROFILE MENU ======"<< endl;
					cout << "1. Add new student"<<endl;
					cout << "2. Update student data"<<endl;
					cout << "3. Delete student"<<endl;
					cout << "4. Search and display a student’s details"<<endl;
					cout << "5. Exit to main menu."<<endl;
					cout << "Choice: ";
					cin >> choice2;
					cout << endl;
					switch(choice2){
					
						case 1:
							do{
								string id_1; 
								string firstname_1; 
								string lastname_1;
								string faculty_1; 
								string programme_1; 
								float cgpa_1;
								
								do{
									cout << "Enter student ID (FFFxxxxxx): ";
									cin  >> id_1;
									faculty_1 = id_1.substr(0,3);
									
									if(student_list.searchID(id_1))
										cout << "ID existed on the system." << endl;
									
								}while(!student_list.validateID(id_1) || student_list.searchID(id_1));
							
								cout << "Enter first name : ";
								cin  >> firstname_1;
							
								cout << "Enter last name : ";
								cin  >> lastname_1;
								
								
								
								if(faculty_1 == "FSM"){
									do{
										cout << "Enter programme (HM00 or HM07) :" << endl;
										cin >> programme_1;
									}while(programme_1 != "HM00" && programme_1 != "HM07");
								}
								else if(faculty_1 == "FPL"){
									do{
										cout << "Enter programme (HL64 or HL32) :" << endl;
										cin >> programme_1;
									}while(programme_1 != "HL64" && programme_1 != "HL32");
								}
								else if(faculty_1 == "FKS"){
									do{
										cout << "Enter programme (HK04 or HK08) :" << endl;
										cin >> programme_1;
									}while(programme_1 != "HK04" && programme_1 != "HK08");
								}
								else if(faculty_1 == "FPP"){
									do{
										cout << "Enter programme (HP05 or HP07) :" << endl;
										cin >> programme_1;
									}while(programme_1 != "HP05" && programme_1 != "HP07");
								}
								else if(faculty_1 == "FKA"){
									do{
										cout << "Enter programme (HA06 or HA09) :" << endl;
										cin >> programme_1;
									}while(programme_1 != "HA06" && programme_1 != "HA09");
								}
	
								
								studentNode *new_node = new studentNode;
								new_node->id = id_1;
								new_node->firstname = firstname_1;
								new_node->lastname = lastname_1;
								new_node->faculty = faculty_1;
								new_node->programme = programme_1;
								cout << endl;

								student_list.addStudent(new_node);
								cout << endl;
								cout << "Do you want to add more student? (Y / N) : ";
								cin >> option;
								
							}while(option == 'Y' || option == 'y');
					
							break;
							
						case 2:
							cout << endl;
							cout << "Enter the student id that want to be update: ";
							cin >> id2;
							student_list.updateStudent(id2);
					
					
					
							break;
							
						case 3:
							cout << endl;
							cout << "Enter the student id that want to be delete: ";
							cin >> id2;
							student_list.searchAndPrintStudent(id2);
							
							if(student_list.searchID(id2))
							{	
								cout << "Are you sure you want to delete? (Y/N)";
								cin >> option;
								
								if(option == 'Y'|| option == 'y')
								
									student_list.deleteStudent(id2);
							}
							
							
							break;
											
						case 4:
							cout << endl;
							cout << "Enter the student id that want to be display: ";
							cin >> id2;
							student_list.searchAndPrintStudent(id2);
						
							break;
						
						
						case 5:
							cout << endl;
							break;	
					}
				}while(choice2 != 5);
				break;	
				
			case 2:
                do{ cout << endl;
                    cout << "====== RESULT PROFILE MENU ======"<< endl;
					cout<<"Please choose one of the option"<<endl;
					cout<<"1. Add new course"<<endl;
					cout<<"2. Update result"<<endl;
					cout<<"3. Delete course"<<endl;
					cout<<"4. Search and display student results"<<endl;
					cout<<"5. Exit to main menu"<<endl;
					cout<<"Option:";
					cin>>choice2;
					cout << endl;
	   				switch(choice2){
						case 1:
							
						 	do{
								cout << "Enter student ID (FFFxxxxxx): ";
								cin  >> id2;
								
								if(!student_list.searchID(id2))
									cout << "ID is not existed in the system." << endl;
		
							}while(!student_list.validateID(id2) || !student_list.searchID(id2));
									   
					
					
						    do{
						    cout<<"Enter the course code: ";
						    cin>> course_code2;
						    
						    if(!student_list.validateCourseCode(course_code2))
						    cout<<"Please re enter"<<endl;
						    				    
						   }while(!student_list.validateCourseCode(course_code2) || !student_list.searchCode(course_code2));
						
						    cout<<"Enter the course name: ";
						    cin>>course_name2;
						   
						
						    cout<<"Enter credit hour given: ";
						    cin>>credit_hour2;	
						    
						    courseNode *new_node;
							new_node = new courseNode;
							new_node->id = id2;
							new_node->course_code = course_code2;
							new_node->course_name = course_name2;
							new_node->credit_hour = credit_hour2;
						    
						    cout<<"Enter marks given:";
						    cin>>marks2;
						    
			             	do{
			                	if(marks2>=80 && marks2<=100)
				                	grade2="A";
				                else if(marks2>=75 && marks2<=79)
				                	grade2="A-";
								else if(marks2>=70 && marks2<=74)
									grade2="B+";
								else if (marks2>=65 && marks2<=69)
									grade2="B";
								else if(marks2>=60 && marks2<=64)
									grade2="B-";
								else if(marks2>=55 && marks2<=59)
									grade2="C+";
								else if(marks2>=50 && marks2<=54)
									grade2="C";
								else if(marks2>=45 && marks2<=49)
									grade2="C-";
								else if(marks2>=40 && marks2<=44)
									grade2="D+";
								else if (marks2>=35 && marks2<=39)
									grade2="D";
								else if( marks2>=0 && marks2 <=34)
									grade2="E";
								else
									cout<<"Value not in range of 0-100.Please enter again"<<endl;
								}while(marks2<0 || marks2>100);
							   	  
								new_node->marks=marks2;
					            new_node->grade=grade2;
					              	  
								if(grade2=="E")
					               status2="Failed";
					            
					            else if(grade2=="C-" | grade2=="D+" | grade2=="D")
					               status2="Partially Failed";
					            else
					            	status2="Pass";
					             
					               new_node->status=status2;
							
			        		student_list.addCourse(new_node);
			        		
			        
			        	break;
		            	
						case 2:
							cout<<"Enter student id to update: ";
							cin>>id2;
							
							studentNode *current;
							current = student_list.searchStudent(id2);
		                	current->c_Linkedlist.Update_Results(id2);
		                	break;
	               		
						case 3:
							cout<<"Enter student id to delete a course: ";
							cin>>id2;
							current = student_list.searchStudent(id2);
		                	current->c_Linkedlist.Delete_Course(id2);
		                break;
	              	
					  	case 4:
					  		
					  	/*	cout<<"Enter student id view results"<<endl;
							cin>>id2;
							if(!student_list.searchID(id2))
								cout << "Student is not in the list." << endl;
							else{
								current = student_list.searchStudent(id2);
								cout<<"Enter course ID to show result: ";
								cin >> coursecode;
								current->c_Linkedlist.Search_Display(coursecode);
							}
						*/		
					  		cout<<"Please enter the course code to be display: ";
							cin>>course_code2;
					  		
					  		current = student_list.getStudentHead();
					  		while(current!= NULL){
		              			current->c_Linkedlist.Search_Display(course_code2);
		              			current = current->link;
		              		}
		              		
		            		break;
		            		
		            	case 5:
							cout << endl;
							break;		
		               }
		        	}while(choice2!=5);	
					break;
			case 3:	
				do{
					studentStatistics st(student_list);
					st.initializeStudentCount();
					cout<<endl;
					cout<<"====== STUDENT STATISTICS======"<< endl;
					cout<<"Please choose one of the option"<<endl;
					cout<<"1. According to respective programme from all faculties"<<endl;
					cout<<"2. According to graduating class in the faculty"<<endl;
					cout<<"3. According to CGPA and graduating class in a programme"<<endl;
					cout<<"4. Exit to main menu"<<endl;
					cout<<"Option:";
					cin>>choice2;
					cout << endl;
	   				switch(choice2){
	   					
	   					//according to all programmes
	   					case 1:	
						   	st.calculateStudent();
	   						st.printStudentMenu1();
	   						break;
	   						
	   					//according to grad class
	   					case 2: {	   		
	   						cout<<"Enter the faculty: <FSM, FPL, FKS, FPP, FKA> "<<endl;
						   	
						   	string fac, grad;
						   	cin>>fac;
						   	
						   	cout<<"Enter the graduating class: <first class, second upper, second lower, failed>"<<endl;
						   	cin.ignore();
						   	getline(cin, grad);
						   	cout<<endl;
						
	   						st.printStudentMenu2(fac,grad);
	   						break;
	   					}
	   						
	   					//according to cgpa and grad class
	   					case 3:{
	   						cout<<"Enter the faculty: <FSM, FPL, FKS, FPP, FKA> "<<endl;
						   	
						   	string fac, prog;
						   	cin>>fac;
						   	
						   	cout<<"Enter the programme: "<<endl;
						   	cin>>prog;
						   	cout<<endl;
						   	
	   						st.printStudentMenu3(fac, prog);
	   						break;
	
	   					}
	   						
	   					
	   					//exit to main menu
	   					case 4:
	   						break;
	   					
	   					}
	   					
				}while(choice2!=4);
				break;
			case 4:	
				
				do{	studentStatistics st(student_list);
					ResultStatistic rs(student_list);
					cout << endl;
					cout << "====== RESULT STATISTIC MENU ======"<< endl;
					cout << "1. Search and display the students for a particular course"<<endl;
					cout << "2. Display total number of students for course and grade"<<endl;
					cout << "3. Exit to main menu"<<endl;
					cout << "Choice: ";
					cin >> choice2;
					cout << endl;
					switch(choice2){
			
						case 1:
							cout << "Enter course code:";
							cin >> course_code2;
							rs.printResultCourse(course_code2);
							break;
							
						case 2:
							cout << "Enter course code:";
							cin >> course_code2;
							
							rs.resultsMenu2(course_code2);
							break;
						
						case 3:
							break;
				
						}
				}while(choice2 != 3);
				break;
					
			case 5:
				cout << "Thank you for using student database management system :)" << endl;
				break;
		}
		
	}while(choice != 5);
		
		
return 0;
}

