#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <utility>
#include "Lesson.h"
#include "Student.h"
using namespace std;

int main(){
 // Create some Lesson objects
 Lesson* c1 = new Lesson("123777789", "Math1", 4, Semester::Fall);
 Lesson* c2 = new Lesson("123335679", "Math2", 5, Semester::Spring);
 Lesson* c3 = new Lesson("123236789", "C", 4, Semester::Fall);
 Lesson* c4 = new Lesson("122345989", "C++", 5, Semester::Spring);
 Lesson* c5 = new Lesson("103456089", "Python", 6, Semester::Spring);
 Lesson* c6 = new Lesson("003456780", "Java", 5, Semester::Spring);
 Lesson* c7 = new Lesson("120411789", "C#", 4, Semester::Fall);

 // Create a vector of Lesson pointers
 vector<Lesson*> lessons = {c1, c2, c3, c4, c5, c6, c7};

 // Create some Student objects
 char am[] =  "23795";
 char am1[] = "12341";
 char am2[] = "12333";
 char am3[] = "12091";
 Student* s1 = new Student(am, "Dimitra Galani ", 1);
 Student* s2 = new Student(am1, "Efthimios Giagos ", 2);
 Student* s3 = new Student(am2, "Dionysios Germanos ", 3);
 Student* s4 = new Student(am3, "Zacharias Limeras ", 1);

 // Create a vector of Student pointers
 vector<Student*> students = {s1, s2, s3, s4};

 // Test some operations
 *students[0] += *c5;
 *students[0] += *c4;
 students[0]->addCompletedCourse(*c1, 8.5);
 students[0]->addCompletedCourse(*c2, 9.0);
 students[0]->addCompletedCourse(*c3, 5.5);
 students[0]->addCompletedCourse(*c4, 7.0);
 students[0]->addCompletedCourse(*c6, 6.5); 
 students[0]->addCompletedCourse(*c7, 30); 
 students[0]->addCompletedCourse(*c1, 10); 
 *students[0] += *c6;
 *students[1] += *c1;
 *students[1] += *c2;
 *students[1] += *c3;
 *students[1] += *c4;
 students[1]->addCompletedCourse(*c5, 8.5);
 students[1]->addCompletedCourse(*c6, 9.0);
 students[1]->addCompletedCourse(*c7, 5.5);
 *students[2] += *c1;
 *students[2] += *c2;
 students[2]->addCompletedCourse(*c3, 7.0);
 students[2]->addCompletedCourse(*c4, 8.5);
 students[2]->addCompletedCourse(*c6, 9.0);
 students[2]->addCompletedCourse(*c7, 5.5);
 *students[3] += *c1;
 *students[3] += *c2;
 *students[3] += *c3;
 students[3]->addCompletedCourse(*c4, 8.5);
 students[3]->addCompletedCourse(*c6, 9.0);
 students[3]->addCompletedCourse(*c7, 5.5);

 cout <<*students[0];
 // file output
 for (const auto& student : students) {
 string filename = student->getName() + ".csv";
 ofstream file(filename);
 if (file.is_open()) {
 file << "ID" << "," << "Name" << "," << "Current Semester" << "," << "Declared Courses" << "," << "Completed Courses" << endl;
 file << student->getAM() << "," << student->getName() << "," << student->getCurrentSemester();
 file << ",";
 for (const auto& course : student->getDeclaredCourses()) {
 file << course->getVocabulary() << ";";
 }
 file << ",";
for (const auto& course : student->getCompletedCourses()) {
 file << course.first->getVocabulary() << ":" << course.second << ";";
 }
 file << endl;
 file.close();
 } else {
 cerr << "Failed to open file for writing\n";
 }
 }
// Output lessons to file
 ofstream file("lessons.csv");
 if (file.is_open()) {
 file << "Code" << "," << "Vocabulary" << "," << "HoursPerWeek" << "," << "Semester" << endl;
 for (const auto& lesson : lessons) {
 file << lesson->getCode() << "," << lesson->getVocabulary() << "," << lesson->getHoursPerWeek() << ",";
 switch (lesson->getSemester()) {
 case Semester::Fall:
 file << "Fall";
 break;
 case Semester::Spring:
 file << "Spring";
 break;
 }
 file << endl;
 }
 file.close();
 } else {
 cerr << "Failed to open file for writing\n";
 }

 // Using the overloaded equality operator (==)
 // True case
 if (*s1 == *s2) {
 cout << "Οι μαθητές έχουν το ίδιο εξάμηνο." << endl;
 }

 // False case
 if (*s1 == *s4) {
 cout << "Οι μαθητές έχουν το ίδιο εξάμηνο." << endl;
 }

 // Using the inequality operator (!=)
 if (*s1 != *s2) {
 cout << "Οι μαθητές δεν έχουν το ίδιο εξάμηνο." << endl;
 }

 // operator (<)
 if (*s1 < *s3) {
 cout << s1->getName() << " βρίσκεται σε χαμηλότερο εξάμηνο από τον " << s3->getName() <<"."<< endl;
 }

 // operator (<=)
 if (*s1 <= *s2) {
 cout << s1->getName() << " βρίσκεται στο ίδιο ή σε χαμηλότερο εξάμηνο από τον " << s2->getName() <<"."<< endl;
 }

 // operator (>)
 if (*s3 > *s1) {
 cout << s1->getName() << "βρίσκεται σε υψηλότερο εξάμηνο από τον " << s2->getName() <<"."<< endl;
 }

 // operator (>=)
 if (*s3 >= *s1) {
 cout << s1->getName() << "βρίσκεται στο ίδιο ή σε ανώτερο εξάμηνο από τον " << s2->getName() <<"."<< endl;
 }

 // Deallocate memory
 for (auto lesson : lessons) {
 delete lesson;
 }
 for (auto student : students) {
 delete student;
 }

 return 0;
}
