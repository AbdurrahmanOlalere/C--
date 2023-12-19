#ifndef SECTION_H
#define SECTION_H
#include "course.h"
#include "student.h"


class Section
{
private:
    int id;
    std::string name;
    std::string days;
    std::string location;
    Course course;
    studentList collection;

public:
    Section();
    Section(std::string name, int id, std::string days,std::string location,Course course);
    Section(std::string title);
    int getID() const;
    void setID(int id);
    std::string getName() const;
    void setName(std::string title);
    int getDays() const;
    void setDays(int credit);
    std::string getLocation() const;
    std::string getLocation() const;
};
