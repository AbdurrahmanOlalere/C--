// TODO: Implement this header file
# ifndef _MY_STRING
# define _MY_STRING
# include <iostream>

class MyString
{
private:
    size_t cap;
    size_t len;
    char* mstring{};
public:
    static const size_t npos = -1;
    MyString();
    MyString(const char* val);
    MyString(const MyString& src);
    ~MyString();
    char at(size_t index) const;
    bool empty() const;
    void clear();
    const char* data() const;
    void resize(size_t n); 
    size_t capacity() const;
    size_t size() const;
    size_t length() const;
    size_t find(const MyString& substring, size_t pos = 0) const;
    char front() const;
    MyString& operator+=(const MyString& rhs);
    MyString& operator=(const MyString& other);
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
};
# endif