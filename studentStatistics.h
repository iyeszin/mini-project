#ifndef H_studentSt
#define H_studentSt

#include<iostream>
#include"faculty.h"
#include"studentLinkedList.h"

using namespace std;

class studentStatistics{

	public:
		void initializeStudentCount();
		void calculateStudent();
		void incrementStudent(studentNode *&, faculty, string, string);
		int totalStudent(faculty &);
		void printStudentMenu1();
		void printStudentMenu2(string, string);
		void printStudentMenu3(string, string);
		
		studentStatistics(studentLinkedList &);
		~studentStatistics();
		
	private:
		studentLinkedList studList;
		faculty fsm;
		faculty fpl;
		faculty fks;
		faculty fpp;
		faculty fka;
};

void studentStatistics::initializeStudentCount(){
	fsm.hm00 = 0;
	fsm.hm07 = 0;
	fpl.hl32 = 0;
	fpl.hl64 = 0;
	fks.hk04 = 0;
	fks.hk08 = 0;
	fpp.hp05 = 0;
	fpp.hp07 = 0;
	fka.ha06 = 0;
	fka.ha09 = 0;	
}


void studentStatistics::calculateStudent(){
	 studentNode* current = studList.getStudentHead();
	  
	 
	 while(current != NULL){
	 	if(current->faculty== "fsm" || "FSM"){
	 		incrementStudent(current, fsm, "hm00", "hm07");
	 	}
	 	else if(current->faculty == "fpl" || "FPL"){
	 		incrementStudent(current, fpl, "hl32", "hl64");
	 	}
	 	else if(current->faculty == "fks" || "FKS"){
	 		incrementStudent(current, fpl, "hk04", "hk08");
	 	}
		else if(current->faculty == "fpp" || "FPP"){
	 		incrementStudent(current, fpl, "hp05", "hp07");
	 	}
	 	else if(current->faculty == "fka" || "FKA"){
	 		incrementStudent(current, fpl, "ha06", "ha09");
	 	}
	 	
	 	current = current->link;
	 }

}

void studentStatistics::incrementStudent
(studentNode *&current, faculty fac, string p1, string p2){
	if(current->faculty == "fsm" || "FSM"){
		if(current->programme == "hm00" || "HM00")
			fsm.hm00++;
		else if(current->programme == "hm07" || "HM07")
			fsm.hm07++;
	}else if(current->faculty== "fpl" || "FPL"){	
		if(current->programme == "hl32" || "HL32")
			fpl.hl32++;
		else if(current->programme == "hl64" || "HL64")
			fpl.hl64++;
	}else if(current->faculty== "fks" || "FKS"){
		if(current->programme == "hk04" || "HK04")
			fks.hk04++;
		else if(current->programme== "hk08" || "HK08")
			fks.hk08++;
	}else if(current->faculty == "fpp" || "FPP"){
		if(current->programme== "hp05" || "HP05")
			fpp.hp05++;
		else if(current->programme == "hp07" || "HP07")
			fpp.hp07++;
	}else if(current->faculty == "fka" || "FKA"){
		if(current->programme == "ha06" || "HA06")
			fka.ha06++;
		else if(current->programme  == "ha09" || "HA09")
			fka.ha09++;
	}
}
	

void studentStatistics::printStudentMenu1(){
	studentNode* current = studList.getStudentHead();	
	
	cout << "No.\tFaculty\t\tProgramme\tTotal Students"<<endl;
	cout << "---------------------------------------------------------------"<<endl;
	cout << "1\tFSM\t\tHM00\t\t\t"<<fsm.hm00<<endl;
	cout << "2\tFSM\t\tHM07\t\t\t"<<fsm.hm07<<endl;
	cout << "3\tFPL\t\tHL32\t\t\t"<<fpl.hl32<<endl;
	cout << "4\tFPL\t\tHL64\t\t\t"<<fpl.hl64<<endl;
	cout << "5\tFKS\t\tHK04\t\t\t"<<fks.hk04<<endl;
	cout << "6\tFKS\t\tHK08\t\t\t"<<fks.hk08<<endl;
	cout << "7\tFPP\t\tHP05\t\t\t"<<fpp.hp05<<endl;
	cout << "8\tFPP\t\tHP07\t\t\t"<<fpp.hp07<<endl;
	cout << "9\tFKA\t\tHA06\t\t\t"<<fka.ha06<<endl;
	cout << "10\tFKA\t\tHA09\t\t\t"<<fka.ha09<<endl;
	cout << "---------------------------------------------------------------"<<endl;
	
	int total = fsm.hm00 + fsm.hm07 + fpl.hl32 + fpl.hl64 + fks.hk04 +
	fks.hk08 + fpp.hp05 + fpp.hp07 + fka.ha06 + fka.ha09;
	
	cout << "Total\t\t\t\t\t\t" <<total<<endl;
	cout << "---------------------------------------------------------------"<<endl;
	cout <<endl;
}

void studentStatistics::printStudentMenu2(string fac, string grad){
	int firstclass = 0;
	int secondupper = 0;
	int secondlower = 0;
	int failed = 0;
	string prog;
	 
	studentNode* current = studList.getStudentHead();
	
	while(current!=NULL){
			fac = current->faculty;
			prog = current->programme;
			grad = current->grad_class;
			
			if(prog == "HM00"){
				if(grad == "first class")
					firstclass++;
				else if(grad == "second upper")
					secondupper++;
				else if(grad == "second lower")
					secondlower++;
				else if(grad == "failed")
					failed++;
			}else if(prog == "HM07"){
				if(grad == "first class")
					firstclass++;
				else if(grad == "second upper")
					secondupper++;
				else if(grad == "second lower")
					secondlower++;
				else if(grad == "failed")
					failed++;
			}else if(prog == "HL32"){
				if(grad == "first class")
					firstclass++;
				else if(grad == "second upper")
					secondupper++;
				else if(grad == "second lower")
					secondlower++;
				else if(grad == "failed")
					failed++;
			}else if(prog == "HL64"){
				if(grad == "first class")
					firstclass++;
				else if(grad == "second upper")
					secondupper++;
				else if(grad == "second lower")
					secondlower++;
				else if(grad == "failed")
					failed++;
			}else if(prog == "HK04"){
				if(grad == "first class")
					firstclass++;
				else if(grad == "second upper")
					secondupper++;
				else if(grad == "second lower")
					secondlower++;
				else if(grad == "failed")
					failed++;
			}else if(prog == "HK08"){
				if(grad == "first class")
					firstclass++;
				else if(grad == "second upper")
					secondupper++;
				else if(grad == "second lower")
					secondlower++;
				else if(grad == "failed")
					failed++;
			}else if(prog == "HP05"){
				if(grad == "first class")
					firstclass++;
				else if(grad == "second upper")
					secondupper++;
				else if(grad == "second lower")
					secondlower++;
				else if(grad == "failed")
					failed++;
			}else if(prog == "HP07"){
				if(grad == "first class")
					firstclass++;
				else if(grad == "second upper")
					secondupper++;
				else if(grad == "second lower")
					secondlower++;
				else if(grad == "failed")
					failed++;
			}else if(prog == "HA06"){
				if(grad == "first class")
					firstclass++;
				else if(grad == "second upper")
					secondupper++;
				else if(grad == "second lower")
					secondlower++;
				else if(grad == "failed")
					failed++;
			}else if(prog == "HA09"){
				if(grad == "first class")
					firstclass++;
				else if(grad == "second upper")
					secondupper++;
				else if(grad == "second lower")
					secondlower++;
				else if(grad == "failed")
					failed++;
			}
			
		current = current->link;		
				
	}
	
	cout<<"Faculty: " <<fac<<", ";
	cout<<"Graduating class: "<<grad<<endl;
	cout<<endl;
	
	cout<<"No.\tProgramme\tTotal Students"<<endl;
	cout<<"-----------------------------------------------"<<endl;
	
	int total = 0;
	
	if(fac == "FSM"){
		if(grad == "first class"){
		cout<<"1\tHM00\t\t\t"<<firstclass<<endl;
		cout<<"2\tHM07\t\t\t"<<firstclass<<endl;
		total = firstclass + firstclass;
		}else if(grad == "second upper"){
		cout<<"1\tHM00\t\t\t"<<secondupper<<endl;
		cout<<"2\tHM07\t\t\t"<<secondupper<<endl;
		total = secondupper + secondupper;
		}else if(grad == "second lower"){
		cout<<"1\tHM00\t\t\t"<<secondlower<<endl;
		cout<<"2\tHM07\t\t\t"<<secondlower<<endl;
		total = secondlower + secondlower;
		}else if(grad == "failed"){
		cout<<"1\tHM00\t\t\t"<<failed<<endl;
		cout<<"2\tHM07\t\t\t"<<failed<<endl;
		total = failed + failed;
		}
	}else if(fac == "FPL"){
		if(grad == "first class"){
		cout<<"1\tHL32\t\t\t"<<firstclass<<endl;
		cout<<"2\tHL64\t\t\t"<<firstclass<<endl;
		total = firstclass + firstclass;
		}else if(grad == "second upper"){
		cout<<"1\tHL32\t\t\t"<<secondupper<<endl;
		cout<<"2\tHL64\t\t\t"<<secondupper<<endl;
		total = secondupper + secondupper;
		}else if(grad == "second lower"){
		cout<<"1\tHL32\t\t\t"<<secondlower<<endl;
		cout<<"2\tHL64\t\t\t"<<secondlower<<endl;
		total = secondlower + secondlower;
		}else if(grad == "failed"){
		cout<<"1\tHL32\t\t\t"<<failed<<endl;
		cout<<"2\tHL64\t\t\t"<<failed<<endl;
		total = failed + failed;
		}
	}else if(fac == "FKS"){
		if(grad == "first class"){
		cout<<"1\tHK04\t\t\t"<<firstclass<<endl;
		cout<<"2\tHK08\t\t\t"<<firstclass<<endl;
		total = firstclass + firstclass;
		}else if(grad == "second upper"){
		cout<<"1\tHK04\t\t\t"<<secondupper<<endl;
		cout<<"2\tHK08\t\t\t"<<secondupper<<endl;
		total = secondupper + secondupper;
		}else if(grad == "second lower"){
		cout<<"1\tHK04\t\t\t"<<secondlower<<endl;
		cout<<"2\tHK08\t\t\t"<<secondlower<<endl;
		total = secondlower + secondlower;
		}else if(grad == "failed"){
		cout<<"1\tHK04\t\t\t"<<failed<<endl;
		cout<<"2\tHK08\t\t\t"<<failed<<endl;
		total = failed + failed;
		}
	}else if(fac == "FPL"){
		if(grad == "first class"){
		cout<<"1\tHL32\t\t\t"<<firstclass<<endl;
		cout<<"2\tHL64\t\t\t"<<firstclass<<endl;
		total = firstclass + firstclass;
		}else if(grad == "second upper"){
		cout<<"1\tHL32\t\t\t"<<secondupper<<endl;
		cout<<"2\tHL64\t\t\t"<<secondupper<<endl;
		total = secondupper + secondupper;
		}else if(grad == "second lower"){
		cout<<"1\tHL32\t\t\t"<<secondlower<<endl;
		cout<<"2\tHL64\t\t\t"<<secondlower<<endl;
		total = secondlower + secondlower;
		}else if(grad == "failed"){
		cout<<"1\tHL32\t\t\t"<<failed<<endl;
		cout<<"2\tHL64\t\t\t"<<failed<<endl;
		total = failed + failed;
		}
	}else if(fac == "FPP"){
		if(grad == "first class"){
		cout<<"1\tHP05\t\t\t"<<firstclass<<endl;
		cout<<"2\tHP07\t\t\t"<<firstclass<<endl;
		total = firstclass + firstclass;
		}else if(grad == "second upper"){
		cout<<"1\tHP05\t\t\t"<<secondupper<<endl;
		cout<<"2\tHP07\t\t\t"<<secondupper<<endl;
		total = secondupper + secondupper;
		}else if(grad == "second lower"){
		cout<<"1\tHP05\t\t\t"<<secondlower<<endl;
		cout<<"2\tHP07\t\t\t"<<secondlower<<endl;
		total = secondlower + secondlower;
		}else if(grad == "failed"){
		cout<<"1\tHP05\t\t\t"<<failed<<endl;
		cout<<"2\tHP07\t\t\t"<<failed<<endl;
		total = failed + failed;
		}
	}else if(fac == "FKA"){
		if(grad == "first class"){
		cout<<"1\tHA06\t\t\t"<<firstclass<<endl;
		cout<<"2\tHA09\t\t\t"<<firstclass<<endl;
		total = firstclass + firstclass;
		}else if(grad == "second upper"){
		cout<<"1\tHA06\t\t\t"<<secondupper<<endl;
		cout<<"2\tHA09\t\t\t"<<secondupper<<endl;
		total = secondupper + secondupper;
		}else if(grad == "second lower"){
		cout<<"1\tHA06\t\t\t"<<secondlower<<endl;
		cout<<"2\tHA09\t\t\t"<<secondlower<<endl;
		total = secondlower + secondlower;
		}else if(grad == "failed"){
		cout<<"1\tHA06\t\t\t"<<failed<<endl;
		cout<<"2\tHA09\t\t\t"<<failed<<endl;
		total = failed + failed;
		}
	}
	
	cout<<"-----------------------------------------------"<<endl;
	cout<<"Total\t\t\t\t"<<total<<endl;
	cout<<"-----------------------------------------------"<<endl;
	
	
}


void studentStatistics::printStudentMenu3(string fac, string prog){
	studentNode* current = studList.getStudentHead();
	

	
}

studentStatistics::studentStatistics(studentLinkedList &otherlist){
	initializeStudentCount();
	
	studList.copyList(otherlist);
	
}

studentStatistics::~studentStatistics(){
	studList.initializeList();
}

#endif
