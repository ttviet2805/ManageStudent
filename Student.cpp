#include "Student.h"

#define studentFileName "Data/AllStudent.txt"

void loadAllStudentData(Student* &allStudent, string fileName) {
    ifstream fin;
    fin.open(fileName);

    if(!fin) {
        cout << "Can not open student file";
        system("pause");
        return;
    }

    Student* Dummy = new Student;
    Student* curStudent = Dummy;

    string stuID;
    while(!fin.eof() && getline(fin, stuID)) {
        curStudent->Next = new Student;
        curStudent->Next->Info->ID = stuID;
        getline(fin, curStudent->Next->Info->firstName);
        getline(fin, curStudent->Next->Info->lastName);
        getline(fin, curStudent->Next->Info->Gender);
        getline(fin, curStudent->Next->Info->Dob);
        getline(fin, curStudent->Next->Info->SocialID);
        getline(fin, curStudent->Next->Info->Class);

        curStudent = curStudent->Next;
    }

    allStudent = Dummy->Next;
    Student* Del = Dummy;
    Dummy = Dummy->Next;
    delete Del;

    fin.close();
}

void saveAllStudentData(Student* allStudent, string filename) {
    ofstream fout;
    fout.open(filename);

    if(!fout) {
        cout << "Can not open student file";
        system("pause");
        return;
    }

    Student* curStudent = allStudent;

    while(curStudent) {
        fout << curStudent->Info->ID << '\n' << curStudent->Info->firstName << '\n' << curStudent->Info->lastName << '\n';
        fout << curStudent->Info->Gender << '\n' << curStudent->Info->Dob << '\n';
        fout << curStudent->Info->SocialID << '\n' << curStudent->Info->Class << '\n';
        curStudent = curStudent->Next;
    }

    fout.close();
}

void Student::addStudentScore(StudentScore* newScore) {
    if(!Score) {
        Score = newScore;
        return;
    }

    StudentScore* cur = Score;
    while(cur->Next) cur = cur->Next;
    cur->Next = newScore;
}

void showAllStudentInfo(Student* allStudent) {
    Student* tmpStudent = allStudent;

    while(tmpStudent) {
        cout << tmpStudent->Info->ID << '\n';
        cout << tmpStudent->Info->firstName << '\n' << tmpStudent->Info->lastName << '\n';
        cout << tmpStudent->Info->Gender << '\n' << tmpStudent->Info->Dob << '\n';
        cout << tmpStudent->Info->SocialID << '\n' << tmpStudent->Info->Class << '\n';
        cout << '\n';
        tmpStudent = tmpStudent->Next;
    }
}

Student* findStudentByID(Student* allStudent, string ID) {
    Student* curStudent = allStudent;

    while(curStudent) {
        if(curStudent->Info->ID == ID) return curStudent;
        curStudent = curStudent->Next;
    }

    return nullptr;
}
