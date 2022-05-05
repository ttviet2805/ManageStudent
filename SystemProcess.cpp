#include "SystemProcess.h"

#define accountFileName "Data/AllAccount.txt"
#define studentFileName "Data/AllStudent.txt"
#define courseFileName "Data/AllCourse.txt"
#define courseScoreFileName "Data/CourseScore/"
#define classFileName "Data/AllClass.txt"
#define studentScoreFileName "Data/StudentScore/"
#define staffFileName "Data/AllStaff.txt"
#define studentInClassFileName "Data/Class/"
#define studentCSVFileName "Data/StudentCSV.csv"

void systemProcess() {
    Student* allStudent = nullptr;
    loadAllStudentData(allStudent, studentFileName);

    system("pause");

    Course* allCourse = nullptr;
    loadAllCourseData(allCourse, courseFileName, allStudent);


}
