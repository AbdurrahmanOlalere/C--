#ifndef COURSE_H
#define COURSE_H

class Course
{
    private:
        int id;
        std::string title;
        int credit;

    public:
        Course();
        Course(int id, std::string title, int credit);
        Course(std::string title);
        int getID() const;
        void setID(int id);
        std::string getTitle() const;
        void setTitle(std::string title);
        int getCredit() const;
        void setCredit(int credit);
}