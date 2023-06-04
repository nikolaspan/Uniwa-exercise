#include "Student.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <utility>
//cunstractor
Student::Student(char *AM, string name) : AM(AM), name(name), currentSemester(1) {}
Student::Student(char *AM, string name, unsigned int currentSemester) : AM(AM), name(name), currentSemester(currentSemester) {}

Student::Student(const Student &other) : AM(other.AM), name(other.name), currentSemester(other.currentSemester),
 declaredCourses(other.declaredCourses), completedCourses(other.completedCourses) {}

//getters
char *Student::getAM() const { return AM; }
string Student::getName() const { return name; }
unsigned int Student::getCurrentSemester() const { return currentSemester; }
double Student::getAverageGrade() const {
 double sum = 0;
 for (auto& course : completedCourses) {
 sum += course.second;
 }
 return completedCourses.size() == 0 ? 0 : sum / completedCourses.size();
}
const vector<Lesson*>& Student::getDeclaredCourses() const {
    return declaredCourses;
}
const vector<pair<Lesson*,double>>& Student::getCompletedCourses() const {
    return completedCourses;
}
//setters
void Student::setAM(char *AM) { this->AM = AM; }
void Student::setName(string name) { this->name = name; }
void Student::setCurrentSemester(unsigned int currentSemester) { this->currentSemester = currentSemester; }
//opperations
Student &Student::operator++() {
 ++currentSemester;
 return *this;
}

Student Student::operator++(int) {
 Student temp(*this);
 ++currentSemester;
 return temp;
}

Student &Student::operator+=(int n) {
 currentSemester += n;
 return *this;
}

Student &Student::operator-=(int n) {
 currentSemester -= n;
 return *this;
}

Student &Student::operator+=(const Lesson &lesson) {
 // Check if the lesson has already been completed
 for (int i = 0; i < completedCourses.size(); i++) {
 if (completedCourses[i].first->getVocabulary() == lesson.getVocabulary()) {
 cerr << "Error: Course " << lesson.getVocabulary() << " έχει ολοκληρωθεί ίδη" << endl;
 return *this;
 }
 }
 declaredCourses.push_back(new Lesson(lesson));
 return *this;
}

    

Student &Student::operator=(const Student &other) {
 if (this != &other) {
 AM = other.AM;
 name = other.name;
 currentSemester = other.currentSemester;
 declaredCourses = other.declaredCourses;
 completedCourses = other.completedCourses;
 }
 return *this;
}


bool Student::operator==(const Student &other) const { return currentSemester == other.currentSemester; }
bool Student::operator!=(const Student &other) const { return currentSemester != other.currentSemester; }
bool Student::operator<(const Student &other) const { return currentSemester < other.currentSemester; }
bool Student::operator<=(const Student &other)const { return currentSemester <= other.currentSemester; }
bool Student::operator>=(const Student &other)const { return currentSemester >= other.currentSemester; }
bool Student::operator>(const Student &other)const { return currentSemester > other.currentSemester; }
void Student::addCompletedCourse(const Lesson& lesson, double score) {
 // Check if the lesson has been declared
 bool isDeclared = true;
for (const Lesson* declaredLesson : declaredCourses) {
 if (declaredLesson->getVocabulary() == lesson.getVocabulary()) {
 isDeclared = false;
 break;
 }
 }

 if (isDeclared) {
 // Check if the lesson has already been completed
 for (int i = 0; i < completedCourses.size(); i++) {
 if (completedCourses[i].first->getVocabulary() == lesson.getVocabulary()) {
 cerr << "Error: Course " << lesson.getVocabulary() << " έχει δηλώσει ίδη  " << endl;
 return;
 }
 }

 if (score >= 0.0 && score <= 10.0) {
completedCourses.push_back(std::make_pair(const_cast<Lesson*>(&lesson), score));
 cout << "Course " << lesson.getVocabulary() << " έχει ολοκληρωθεί με βαθμό " << score << endl;
 } else {
 cerr << "Error: λάθος βαθμός " << lesson.getVocabulary() << endl;
 }
 } else {
 cerr << "Error: Course " << lesson.getVocabulary() << " Δέν έχει δηλωθεί" << endl;
 }
}


//print operation
ostream& operator<<(ostream& os, const Student& student) {
    os << "Student " << student.getName() << " with ID " << student.getAM() << " has completed the following courses:" << endl;
    for (const auto& course : student.getCompletedCourses()) {
        os << "\t" << course.first->getVocabulary() << " with grade " << course.second << endl;
    }
    os << "Average grade: " << student.getAverageGrade() << endl;
    return os;
}



Student::~Student() {
    delete[] AM;
}
