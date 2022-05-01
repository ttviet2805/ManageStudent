#include "SystemProcess.h"

#define accountFileName "Data/AllAccount.txt"
#define studentFileName "Data/AllStudent.txt"
#define courseFileName "Data/AllCourse.txt"
#define courseScoreFileName "Data/CourseScore/"
#define classFileName "Data/AllClass.txt"

void systemProcess() {
//    Account* curAccount = loginProcess();
//
    Student* allStudent = nullptr;

    loadAllStudentData(allStudent, studentFileName);
//
//    showAllStudentInfo(allStudent);
//
//    saveAllStudentData(allStudent, studentFileName);

    Course* allCourse = nullptr;
    loadAllCourseData(allCourse, courseFileName, allStudent);

    showAllCourseData(allCourse);

//    Student* tmp = allStudent;
//    StudentScore* cc = tmp->Score;
//    while(cc) {
//        cout << cc->courseInfo->courseID << ' ' << cc->studentScore->Final << endl;
//        cc = cc->Next;
//    }

    saveAllCourseData(allCourse, courseFileName);

//    Class* allClass = nullptr;
//    loadAllClassData(allClass, classFileName);
//
//    showAllClassData(allClass);
//
//    saveAllClassData(allClass, classFileName);
}
