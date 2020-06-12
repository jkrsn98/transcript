#ifndef COURSE_H
#define COURSE_H
#include <sstream>

class Course{
  public:
//------------------------------------------------------------------------------
//constructor
    Course(int courseID, int courseCredits, char courseGrade):
      courseID(courseID),
      courseCredits(courseCredits),
      courseGrade(courseGrade){}
    Course(){}
//------------------------------------------------------------------------------
//getters and setters
    int getCourseID()const{return courseID;}
    int getCourseCredits()const{return courseCredits;}
    char getCourseGrade()const{return courseGrade;}
    int setCourseID(int i){this->courseID=i;}
    int setCourseCredits(int i){this->courseCredits=i;}
    char setCourseGrade(char c){this->courseGrade=c;}
//------------------------------------------------------------------------------
//print function
    void print(std::ostream &os) const{
      os<<"        "<< courseID << " (" <<courseCredits <<
        " credits): " << courseGrade;
     }
//------------------------------------------------------------------------------

  private:
    int courseID, courseCredits;
    char courseGrade;
};

//------------------------------------------------------------------------------
//output operator overload
inline std::ostream &operator <<(std::ostream &os, const Course &course){
  course.print(os); return os;
}
//------------------------------------------------------------------------------
//input operator overload
inline std::istream& operator >> (std::istream& is, Course& c) {
  std::string line;
  int id, credits; char grade;
    if (std::getline(is, line)) {
      std::istringstream iss(line);
      iss >> id >> credits >> grade ;
      c.setCourseID(id);c.setCourseCredits(credits);c.setCourseGrade(grade);
    }
  return is;
}


#endif
