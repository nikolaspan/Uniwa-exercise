#include "Lesson.h"

Lesson::Lesson(const char* code, const char* vocabulary, unsigned int hoursPerWeek, Semester semester)
    : code(code), vocabulary(vocabulary), hoursPerWeek(hoursPerWeek), semester(semester) {}

std::string Lesson::getCode() const {
    return code;
}

std::string Lesson::getVocabulary() const {
    return vocabulary;
}

unsigned int Lesson::getHoursPerWeek() const {
    return hoursPerWeek;
}

Semester Lesson::getSemester() const {
    return semester;
}

void Lesson::setCode(std::string code) {
    this->code = code;
}

void Lesson::setVocabulary(std::string vocabulary) {
    this->vocabulary = vocabulary;
}

void Lesson::setHoursPerWeek(unsigned int hoursPerWeek) {
    this->hoursPerWeek = hoursPerWeek;
}

void Lesson::setSemester(Semester semester) {
    this->semester = semester;
}
