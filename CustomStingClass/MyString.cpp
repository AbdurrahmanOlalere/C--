// TODO: Implement this source file
# include "MyString.h"

MyString::MyString() : cap(1), len(0), mstring{ nullptr }
{
    mstring = new char[1];
    mstring[0] = '\0';
}

MyString::MyString(const char* val) : cap(1),len(0),mstring(nullptr){
     if (val != nullptr) {
        // Calc the size/length
        while (val[len] != '\0') {
            ++len;
            ++cap;
        }

        mstring = new char[len + 1];
        for (size_t i = 0; i < len; ++i) {
            mstring[i] = val[i];
        }
        mstring[len] = '\0';
     }else {
        //for nullptr 
        mstring = new char[1];
        mstring[0] = '\0';
     }

}

MyString::MyString(const MyString& src) : cap(src.cap),len(src.len), mstring(new char[src.len + 1]) {
    //copying each char manaully
    for (size_t i = 0; i < len; ++i) {
        mstring[i] = src.mstring[i];
    }
    mstring[len] = '\0';

}

MyString::~MyString()
{
    delete[] mstring;
    mstring = nullptr;
}


char MyString::at(std::size_t index) const {
    if (index >= this->len) {
        throw std::out_of_range("Index out of range");
    }
    return mstring[index];
}

bool MyString::empty() const {
    return this->len == 0;
}

void MyString::clear() {
    delete[] mstring;
    len = 0;
    cap = 1;
    mstring = new char[1];
    mstring[0] = '\0';
}
const char* MyString::data() const {
    return mstring;
}
void MyString::resize( size_t n){
    if (n < len) {
        char* newString = new char[n+1];
        size_t i = 0;

        while (i < n) {
            newString[i] = mstring[i];
            ++i;
        }
        newString[n] = '\0'; 
        delete[] mstring;
        mstring = newString;
        len = n;
        cap = n + 1; 
    } else {
        if (n > cap) {
            cap = n;
            char* newString = new char[cap];
            for (size_t i = 0; i < len; ++i) {
                newString[i] = mstring[i];
            }
            newString[len] = '\0'; 
            delete[] mstring;
            mstring = newString;
        }
        len = n;    
    }
    mstring[len] = '\0';
}
size_t MyString::capacity() const {
    return cap;
}
size_t MyString::size() const {
    return len;
}

size_t MyString::length() const {
    return len;
}

size_t MyString::find(const MyString& substring, size_t pos) const {
    size_t substringSize = substring.size();
    size_t startPos = pos;

    if (substringSize > this->length() || startPos >= this->length()) {
        // It's longer than the orig string or startPos is our of rnage.
        return npos;
    }
    for (size_t i = static_cast<size_t>(startPos); i <= this->length() - substringSize; ++i) {
        // Checks if substrng matches starting at pos i
        bool found = true;
        for (size_t j = 0; j < substringSize; ++j) {
            if (mstring[i + j] != substring.mstring[j]) {
                found = false;
                break;// break once false
            }
        }
        if (found) {
            // Found at position i
            return i;
        }
    }

    return npos;
}
char MyString::front() const {
    if (this->len > 0) {
        return mstring[0];
    } else {
        return '\0';
    }

}

MyString& MyString::operator+=(const MyString& rhs) {
    char* newString = new char[len + rhs.len + 1];
    size_t i = 0;

    // Cpy the current string
    while (mstring[i] != '\0') {
        newString[i] = mstring[i];
        ++i;
    }

    // Concatenate the rhs str
    size_t j = 0;
    while (rhs.mstring[j] != '\0') {
        newString[i + j] = rhs.mstring[j];
        ++j;
    }

    // Null the new strng
    newString[i + j] = '\0';

    // Release the old memry and update to the new strng
    delete[] mstring;
    mstring = newString;
    len += rhs.len;

    return *this;
}
MyString& MyString::operator=(const MyString& otherStr) {
    if (this != &otherStr) {
        delete[] mstring; //for when mstring is a dynamic character array

        len = otherStr.len;
        mstring = new char[len + 1];

        // copy the content from 'otherStr' to 'this'
        for (std::size_t i = 0; i < len; i++) {
            mstring[i] = otherStr.mstring[i];
        }
        mstring[len] = '\0';
    }
    return *this;
}
std::ostream& operator<<(std::ostream& os, const MyString& strng) {
    //do every char other null char in for loop of string
    for (size_t i = 0; i < strng.size(); ++i) {
        os << strng.at(i);
    }
    return os;
}
