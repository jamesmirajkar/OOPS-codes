/*Suppose you want to model a school system in C++. You have a School class that contains various 
classes like Student and Teacher as nested classes. Each student and teacher has specific attributes
 and behaviors.*/

#include <iostream>
#include <string>

class School {
public:
    class Student {
    public:
        Student(const std::string& name, int age) : name(name), age(age) {}

        void introduce() {
            std::cout << "Student: " << name << ", Age: " << age << std::endl;
        }

    private:
        std::string name;
        int age;
    };

    class Teacher {
    public:
        Teacher(const std::string& name, const std::string& subject) : name(name), subject(subject) {}

        void introduce() {
            std::cout << "Teacher: " << name << ", Subject: " << subject << std::endl;
        }

    private:
        std::string name;
        std::string subject;
    };
};

int main() {
    // Create a student and a teacher
    School::Student student("Alice", 16);
    School::Teacher teacher("Mr. Smith", "Mathematics");

    // Introduce them
    student.introduce();
    teacher.introduce();

    return 0;
}
