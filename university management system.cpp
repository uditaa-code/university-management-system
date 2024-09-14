#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;

class University{
	private:

        string Name, Subject,RollNo, Semester;

public:
	University():RollNo(""),Name(""),Subject(""),Semester(""){}
//setter
 setROLLNo(string rollNo ){
    RollNo=rollNo;
}	
setSemester(string semester ){
    Semester=semester;
}
setName(string name ){
    Name=name;
}	
 setSubject(string subject ){
    Subject=subject;
}	
//getter
string getRollNo(){
    return RollNo;
}
string getSemester(){
    return Semester;
}
string getName(){
    return Name;
}
string getSubject(){
    return Subject;
}
};//end of class
//start of main 
add(University student){
    string name,subject,semester,rollNo;

    cout<<"\tENTER ROLLNO OF STUDENT: ";
    cin>>rollNo;
    student.setROLLNo(rollNo);

     cout<<"\tENTER SEMESTER OF STUDENT: ";
    cin>>semester;
    student.setSemester(semester);

     cout<<"\tENTER NAME OF STUDENT: ";
    cin>>name;
    student.setName(name);

     cout<<"\tENTER SUBJECT OF STUDENT: ";
    cin>>subject;
    student.setSubject(subject);

    ofstream out("D:/university.txt", ios::app);
    if(!out){
      cout<<"\tError: File Can't Open!"<<endl;  
    }

    else{
       out<<"\t"<<student.getName()<<":"<<student.getRollNo()<<":"<<student.getSemester()<<":"<<student.getSubject()<<endl<<endl; 
    }
    out.close();
    cout<<"\tStudent Added Successfully!"<<endl;
}
search(){
	string rollNo;
	cout<<"\tENTER ROLLNO OF THE STUDENT : ";
	cin>>rollNo;
	ifstream in("D:/university.txt");
	if(!in){
		cout<<"\tError : File Can't Open!"<<endl;
	}
	string line;
	bool found=false;
	while(getline(in,line)){
		int data = line.find(rollNo);
		if(data != string::npos){
			cout<<"\t"<<line<<endl;
			found=true;
	}
	if(!found){
		cout<<"\tSTUDENT NOT FOUND : "<<endl;
	}
	}
	in.close();
}

update(University student){
	string rollNo;
	cout<<"\tENTER ROLLNO OF STUDENT :"<<endl;
	cin>>rollNo;
	
	ifstream infile("D:/university.txt");
	ofstream outfile("D:/university temp.txt");
	if(!infile || !outfile){
		cout<<"\tERROR : FILE  CAN'T OPEN "<<endl;
	}
	string line;
	bool found=false;
	while (getline(infile , line)){
		int pos = line.find(rollNo);
		if(pos!=string::npos){
			string semester;
			cout<<"\tENTER CORRECT SEMESTER :"<<endl;
			cin>>semester;
			student.setSemester(semester);
			
			int newPos= line.find_last_of(':');
			line.replace(newPos + 2, string::npos,student.getSemester());
		}
		outfile<<line<<endl;//temp file
		found=true;
	}
	if(!found){
		cout<<"\tSTUDENT NOT EXIST :"<<endl;
	}
	outfile.close();
	infile.close();
	remove("D:/university.txt");
	rename("D:/university temp.txt", "D:/university.txt");
	cout<<"\tDATA UPDATED SUCCESSFULLY! "<<endl;
}

int main(){
    University student;//object 
    bool exit=false;
    while(!exit){
    	system("cls");
        int val;
        cout<<"\tWELCOME TO BANASTHALI VIDHYAPITH RESULT PORTAL"<<endl;
        cout<<"\t_____________________________________________"<<endl;
        cout<<"\t1.ADD STUDENT-"<<endl;
        cout<<"\t2.SEARCH STUDENT-"<<endl;
        cout<<"\t3.UPDATE DATA OF STUDENT-"<<endl;
        cout<<"\t4.EXIT-"<<endl;
        cout<<"\tENTER YOUR CHOICE: ";
        cin>>val;

        if(val==1){
         system("cls"); 
          add(student);
          Sleep(6000);

        }
        else if(val==2){
        	system("cls");
        	search();
        	Sleep(6000);
		}
		else if(val==3){
			system("cls");
			update(student);
			Sleep(6000);
		}
		else if(val==4){
			system("cls");
			exit=true;
			cout<<"\tGOOD LUCK!"<<endl;
			Sleep(3000);
		}
    }
}
