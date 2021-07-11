#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>

struct Student {
  std::string id;
  float grade;
  friend std::ostream& operator<<(std::ostream& os, const Student& student){
    return (os << student.id << ":" << student.grade);
  }
};


int main(){
  
  Student students[] = {
    {"1001", 80},
    {"1002", 90},
    {"1003", 90},
    {"1004", 89},
  };

  //grade desc, id asc
  std::sort(std::begin(students), std::end(students), 
    [](const Student& a, const Student& b){
      if(a.grade != b.grade)
	return a.grade > b.grade;
      else
	return a.id < b.id;
  });
  
  std::copy(std::begin(students), std::end(students), std::ostream_iterator<Student>(std::cout, "   "));
  return 0;
}
