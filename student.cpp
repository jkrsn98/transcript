#include "student.h"

//------------------------------------------------------------------------------
//constructor
Student::Student(int studentID, std::string studentName):
  studentID(studentID),
  studentName(studentName){}

//------------------------------------------------------------------------------
//static numProcessed initialisation
int Student::numProcessed = 0;

//------------------------------------------------------------------------------
//calculates and returns GPA
double Student::getGPA() const{
  std::map<char,float> grades;
  grades['A']=4.0;grades['B']=3.00;grades['C']=2.00;
  grades['D']=1.00;grades['F']=0.00;

  int totalCreditsAttempted=0;
  double totalGradePoints=0;

  for (const Course c : courses){
    double gradePoints= grades[ c.getCourseGrade() ] * c.getCourseCredits();
    totalGradePoints+=gradePoints;
    totalCreditsAttempted+=c.getCourseCredits();
  }

  return totalGradePoints/(float)totalCreditsAttempted;
}

//------------------------------------------------------------------------------
//print function
void Student::print(std::ostream &os) const{
  os<<studentID << " "<<studentName<< ": "<< getGPA() << std::endl;
  for(int i = 0; i<courses.size();i++)
    os<<courses.at(i)<<std::endl;
}

//------------------------------------------------------------------------------
//compareStudent function for stl sort
bool compareStudent(Student s1, Student s2){
  return(s1.getGPA()>s2.getGPA());
}
