#include <vector>
#include <iostream>
#include <string>
#include "course.h"

int Course::getID() const {
    return id;
}

void Course::setID(int id) {
    this->id = id;
}

std::string Course::getTitle() const {
    return title;
}

void Course::setTitle(std::string title) {
    this->title = title;
}

int Course::getCredit() const {
    return credit;
}

void Course::setCredit(int credit) {
    this->credit = credit;
}
