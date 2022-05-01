#pragma once

#include <string.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>

using namespace std;

#include "Course.h";
#include "Score.h"

struct StudentInfo {
    string ID, firstName, lastName, Gender, Dob, SocialID, Class;
};

struct StudentScore {
    CourseInfo* courseInfo = new CourseInfo;
    Score* studentScore = new Score;

    StudentScore* Next = nullptr;
};

struct Student {
    StudentInfo* Info = new StudentInfo;
    StudentScore* Score = nullptr;

    Student* Next = nullptr;

    void addStudentScore(StudentScore* newScore);
};

void loadAllStudentData(Student* &allStudent, string fileName);

void saveAllStudentData(Student* allStudent, string FileName);

void showAllStudentInfo(Student* allStudent);

Student* findStudentByID(Student* allStudent, string ID);
