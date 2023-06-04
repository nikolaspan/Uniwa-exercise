#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "Lesson.h"
using namespace std;

class Student {
 private:
 char *AM;
 string name;
 unsigned int currentSemester;
 vector<Lesson*> declaredCourses; 
 vector<pair<Lesson*, double>> completedCourses;
public:
 Student(char *AM, string name);
 Student(char *AM, string name, unsigned int currentSemester);
 Student(const Student &other);

 char *getAM() const;
 string getName() const;
 unsigned int getCurrentSemester() const;

 void setAM(char *AM);
 void setName(string name);
 void setCurrentSemester(unsigned int currentSemester);
 double getAverageGrade() const;
const vector<Lesson*>& getDeclaredCourses() const;
const vector<pair<Lesson*,double>>& getCompletedCourses() const;
 Student &operator++();
 Student operator++(int);
 Student &operator+=(int n);
 Student &operator-=(int n);
 Student &operator+=(const Lesson &lesson);
 Student &operator=(const Student &other);

 bool operator==(const Student &other) const;
 bool operator!=(const Student &other) const;
 bool operator<(const Student &other) const;
 bool operator<=(const Student &other) const;
 bool operator>(const Student &other) const;
 bool operator>=(const Student &other) const;

 void addCompletedCourse(const Lesson& lesson, double score);



 virtual ~Student();
};
 ostream& operator<<(ostream& os, const Student& student);
#endif
