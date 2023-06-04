#ifndef LESSON_H
#define LESSON_H

#include <string>

enum class Semester {
    Fall,
    Spring
};

class Lesson {
public:
    Lesson(const char* code, const char* vocabulary, unsigned int hoursPerWeek, Semester semester);
   //get
    std::string getCode() const;
    std::string getVocabulary() const;
    unsigned int getHoursPerWeek() const;
    Semester getSemester() const;
   //set
    void setCode(std::string code);
    void setVocabulary(std::string vocabulary);
    void setHoursPerWeek(unsigned int hoursPerWeek);
    void setSemester(Semester semester);
	 

private:
    std::string code;
    std::string vocabulary;
    unsigned int hoursPerWeek;
    Semester semester;
};

#endif // LESSON_H
