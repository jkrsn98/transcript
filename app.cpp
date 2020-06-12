#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "student.h"
#include "course.h"
using namespace std;

bool compareStudent(Student, Student);

int main(){

  ifstream datFileStream{ "students.dat" };

  if(!datFileStream.good()){
    throw runtime_error("file not found!!");
    exit(1);
  }

  vector<Student> students(istream_iterator<Student>(datFileStream), {});
  sort(students.begin(), students.end(), compareStudent );

  for(const Student s : students)
    cout<<s;

  cout<<endl<<Student::getNumProcessed()<< " records processed"<<endl;

  return 0;
}
