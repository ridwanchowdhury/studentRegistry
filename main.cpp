#include <iostream>
#include<fstream>
#include<string>
using namespace std;

class Student{
private:
    string fName,mName,lName,faName,moName;
    string id,dob,fileName;
    int age;
    double cgpa;
public:
    Student(){
    this->id = "-1";

    }
   void iniStudent(string id){

    this->id = id;
    }

    void iniStudent(string fName,string mName,string lName,string faName,string moName,string id,string dob,double cgpa){
    this->fName = fName;
    this->mName = mName;
    this->lName = lName;
    this->faName = faName;
    this->moName = moName;
    this->id = id;
    this->cgpa = cgpa;
    this->dob = dob;
    }

void ShowData(){

        int x = this->dob[6]-48;
        int y = this->dob[7]-48;
        int z= this->dob[8]-48;
        int p= this->dob[9]-48;
        age = 2018- (x*1000+y*100+z*10+p);

        cout << "ID: " << this->id << endl;
        cout << "Name : " << this->fName << " " << this->mName << " " <<  this->lName << endl;
        cout <<"Fathers Name: " << this->faName << endl;
        cout <<"Mothers Name: " << this->moName << endl;
        cout <<"CGPA: " << cgpa << endl;
        cout <<"Date Of Birth: " << this->dob << endl;
        cout <<"Age: " << this->age << " Years Old"<< endl;

    }
void ShowName(){
cout << "Name : " << this->fName << " " << this->mName << " " <<  this->lName << endl;
}

void ShowFatherName(){
cout <<"Fathers Name: " << this->faName << endl;


}

void ShowMotherName(){
cout <<"Mothers Name: " << this->moName << endl;

}

void ShowAge(){
int x = this->dob[6]-48;
        int y = this->dob[7]-48;
        int z= this->dob[8]-48;
        int p= this->dob[9]-48;
        age = 2018- (x*1000+y*100+z*10+p);

    cout <<"Age: " << this->age << " Years Old"<< endl;
}

void ShowCgpa(){

cout <<"CGPA: " << cgpa << endl;
}
int saveStudent(){

        if(this->id=="-1"){
            cout <<"Nothing To Store" << endl;
        }
        else{
        this->fileName = id+".txt";
        ofstream fout,afout;
        afout.open("list.txt",ios::app);
        afout << fileName;
        afout << "\n";
        fout.open(this->fileName,ios::app);
        fout.write((char*)this,sizeof(*this));
        fout.close();
        afout.close();
        }


    }
bool getStudentData(){

                this->fileName = id+".txt";
                ifstream fin;
                fin.open(this->fileName,ios::in);
            if(!fin)
            {
                cout <<"File Not Found";

                return false;
            }
           else
           {
               fin.read((char*)this,sizeof(*this));
               return true;
           }


        }



};


void createStudentFile(Student *temp){
    system("cls");
    string fName,mName,lName,faName,moName;
    string id,dob;
    double cgpa;
    cout <<"Enter Student ID: " ; cin >> id;
    cout <<"Enter Student First Name: " ; cin>> fName;
    cout <<"Enter Student Middle Name: " ; cin>> mName;
    cout <<"Enter Student Last Name: " ; cin>> lName;
    cout <<"Enter Student Fathers Name: " ;
    cin >> faName;
    cout <<"Enter Student Mothers Name: " ;
    cin >> moName;
    cout <<"Enter Student CGPA: "; cin >>cgpa;
    cout <<"Enter Date of Birth(DD/MM/YYYY Format): " ;cin >> dob;
    temp->iniStudent(fName,mName,lName,faName,moName,id,dob,cgpa);
    temp->saveStudent();

}

void showStudentInfo(Student* temp)
{

    string id;
    cout <<"Enter Student ID: " ; cin>> id;system("cls");
    temp->iniStudent(id);
    bool f= temp->getStudentData();
    if(f!=0)
    {
        cout << "Entered " << id << ".txt" << endl;
        int s=1;

        while(s){
                 cout <<"\n1: To Show Name"<< endl;
                 cout <<"2: To Show Fathers Name"<< endl;
                 cout <<"3: To Show Mothers Name"<< endl;
                 cout <<"4: To Show CGPA"<< endl;
                 cout <<"5: To Show Age"<< endl;
                 cout <<"6: To Show All Data"<< endl;
                cout <<"Enter 0 To Exit:   " << endl;
        cin>> s;
            switch(s){
                case 1: temp->ShowName();break;
                case 2: temp->ShowFatherName();break;
                case 3: temp->ShowMotherName();break;
                case 4: temp->ShowCgpa();break;
                case 5: temp->ShowAge();break;
                case 6: temp->ShowData();break;
            }
    }

}}

void showList(){
        system("cls");
        ifstream fout;
        fout.open("list.txt",ios::in);
        if(!fout)
        {
            cout <<"No List Created" << endl;
        }
        else
        {
         cout <<"File List: " << endl;
           string n;
           while(fout >> n)
           {
               cout << n << "\n";
           }


        }
    fout.close();
}


int main()
{
    cout <<"\nEnter Your Choice-------------------------------------------------------\n\n" ;
    Student std1;
    int z;
    while(1){
            cout <<"\n1: To Create a New Student File" <<endl;
            cout <<"2: To Open a Student File" <<endl;
            cout <<"3: To Show Student List" << endl;
            cout <<"4: To Exit" << endl;
            cin >> z;

        switch(z)
        {
            case 1: createStudentFile(&std1);break;
            case 2: showStudentInfo(&std1);break;
            case 3: showList();break;
            case 4: return 0;
        }

    }

}
