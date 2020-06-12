#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include "course.h"

class Student{
  public:
//------------------------------------------------------------------------------
//constructors
    Student(int studentID, std::string studentName);
    Student(){}
//------------------------------------------------------------------------------
//getters and setters
    int getStudentID() const{return studentID;}
    std::string getStudentName() const{return studentName;}
    static int getNumProcessed(){return numProcessed;}
    void setStudentID(int i){this->studentID=i;}
    void setStudentName(std::string s){this->studentName=s;}
//------------------------------------------------------------------------------
//adds a course to vector of courses
    void addCourse(Course c){courses.push_back(c);}
//------------------------------------------------------------------------------
//calculates and returns GPA
    double getGPA() const;
//------------------------------------------------------------------------------
//print function
    void print(std::ostream &os) const;
//------------------------------------------------------------------------------
//clears course vector before using it for the next run
    void clearVec(){courses.clear();}
//------------------------------------------------------------------------------
//increments counter of records processed
    static void incrementNumProcessed(){numProcessed++;}
//------------------------------------------------------------------------------

  private:
    std::vector<Course> courses;
    int studentID;
    std::string studentName;
    static int numProcessed;
};

//------------------------------------------------------------------------------
//output operator overload
inline std::ostream &operator <<(std::ostream &os, const Student &student){
  student.print(os);
  return os;
}

//------------------------------------------------------------------------------
//input operator overload
inline std::istream& operator >> (std::istream& is, Student& s) {
  std::string line;
  int id; std::string name;

  while (std::getline(is, line) && line == "");
  if (is) {
    std::istringstream iss(line);
    iss >> id >> name;
    Student::incrementNumProcessed();
    s.setStudentID(id);s.setStudentName(name);
    s.clearVec();
    while (std::getline(is, line) && line != "-1") {
      std::istringstream iss2(line);
      Course cTemp;
      iss2 >> cTemp;
      s.addCourse(cTemp);
    }
  }
  return is;
}


#endif
