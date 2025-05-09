#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <memory>
#include <ctime>
#include <iomanip>
#include <chrono>
using namespace std;

class Course;
class Professor;
class Student;
class Classroom;
class Department;

// Base exception class
class UniversitySystemException {
protected:
    string errorMessage;
    string errorDetails;
public:
    UniversitySystemException(const string& message, const string& details = "") 
        : errorMessage(message), errorDetails(details) {}
    
    virtual string getMessage() const { return errorMessage; }
    virtual string getDetails() const { return errorDetails; }
    
    virtual void log() {
        ofstream logFile("university_errors.log", ios::app);
        if(logFile.is_open()) {
            auto now = chrono::system_clock::now();
            time_t current_time = chrono::system_clock::to_time_t(now);
            tm* timeinfo = localtime(&current_time);
            
            logFile << "Error: " << errorMessage << endl;
            logFile << "Details: " << errorDetails << endl;
            logFile << "Timestamp: " << put_time(timeinfo, "%Y-%m-%d %H:%M:%S") << endl;
            logFile << "------------------------" << endl;
            logFile.close();
        }
    }
};

// Derived exception classes
class EnrollmentException : public UniversitySystemException {
public:
    EnrollmentException(const string& message, const string& details = "") 
        : UniversitySystemException(message, details) {}
};

class GradeException : public UniversitySystemException {
public:
    GradeException(const string& message, const string& details = "") 
        : UniversitySystemException(message, details) {}
};

class PaymentException : public UniversitySystemException {
public:
    PaymentException(const string& message, const string& details = "") 
        : UniversitySystemException(message, details) {}
};

class ValidationException : public UniversitySystemException {
public:
    ValidationException(const string& message, const string& details = "") 
        : UniversitySystemException(message, details) {}
};

// Base Person class
class Person {
private:
    string fullName;
    int age;
    string identificationNumber;
    long long phoneNumber;
protected:
    double paymentAmount;
public:
    Person(const string& name, int age, const string& id, long long phone) {
        validatePersonData(name, age, id, phone);
        
        fullName = name;
        this->age = age;
        identificationNumber = id;
        phoneNumber = phone;
        paymentAmount = 0.0;
    }
    
    virtual ~Person() = default;
    
    string getName() const { return fullName; }
    int getAge() const { return age; }
    string getId() const { return identificationNumber; }
    long long getPhone() const { return phoneNumber; }
    
    void setName(const string& name) { 
        validateName(name);
        fullName = name; 
    }
    
    void setAge(int newAge) { 
        validateAge(newAge);
        age = newAge; 
    }
    
    void setId(const string& id) { 
        validateId(id);
        identificationNumber = id; 
    }
    
    void setPhone(long long phone) { 
        validatePhone(phone);
        phoneNumber = phone; 
    }
    
    virtual void display() const {
        cout << "Name: " << fullName << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << identificationNumber << endl;
        cout << "Phone: " << phoneNumber << endl;
    }
    
    virtual double calculatePayment() const {
        return paymentAmount;
    }

private:
    void validatePersonData(const string& name, int age, const string& id, long long phone) {
        validateName(name);
        validateAge(age);
        validateId(id);
        validatePhone(phone);
    }
    
    void validateName(const string& name) {
        if(name.empty()) {
            throw ValidationException("Invalid name", "Name cannot be empty");
        }
    }
    
    void validateAge(int age) {
        if(age < 0 || age > 120) {
            throw ValidationException("Invalid age", "Age must be between 0 and 120");
        }
    }
    
    void validateId(const string& id) {
        if(id.empty()) {
            throw ValidationException("Invalid ID", "ID cannot be empty");
        }
    }
    
    void validatePhone(long long phone) {
        if(phone < 1000000000) {
            throw ValidationException("Invalid phone", "Phone number must be valid");
        }
    }
};

// Classroom class
class Classroom {
private:
    string roomNumber;
    int capacity;
    bool hasProjector;
    bool isOccupied;
public:
    Classroom(const string& room, int capacity, bool projector) {
        validateClassroomData(room, capacity);
        
        roomNumber = room;
        this->capacity = capacity;
        hasProjector = projector;
        isOccupied = false;
    }
    
    string getRoomNumber() const { return roomNumber; }
    int getCapacity() const { return capacity; }
    bool hasProjectorAvailable() const { return hasProjector; }
    bool isRoomOccupied() const { return isOccupied; }
    
    void setOccupied(bool occupied) { isOccupied = occupied; }

private:
    void validateClassroomData(const string& room, int capacity) {
        if(room.empty()) {
            throw ValidationException("Invalid room", "Room number cannot be empty");
        }
        if(capacity <= 0) {
            throw ValidationException("Invalid capacity", "Capacity must be positive");
        }
    }
};

// Department class
class Department {
private:
    string name;
    string location;
    double budget;
    vector<Professor*> professors;
    vector<Course*> courses;
public:
    Department(const string& name, const string& loc, double budget) {
        if(name.empty()) throw ValidationException("Invalid name", "Department name cannot be empty");
        if(loc.empty()) throw ValidationException("Invalid location", "Location cannot be empty");
        if(budget < 0) throw ValidationException("Invalid budget", "Budget cannot be negative");
        
        this->name = name;
        location = loc;
        this->budget = budget;
    }
    
    void addProfessor(Professor* prof) {
        professors.push_back(prof);
    }
    
    void addCourse(Course* course) {
        courses.push_back(course);
    }
    
    void display() const {
        cout << "Department: " << name << endl;
        cout << "Location: " << location << endl;
        cout << "Budget: ₹" << budget << endl;
        cout << "Professors: " << professors.size() << endl;
        cout << "Courses: " << courses.size() << endl;
    }
};

class Professor : public Person {
protected:
    string department;
    string specialization;
    string hireDate;
    double salary;
    int yearsOfService;
    vector<Course*> taughtCourses;
public:
    Professor(const string& name, int age, const string& id, long long phone, const string& dept, const string& spec, const string& hire) 
        : Person(name, age, id, phone) {
        if(dept.empty()) throw ValidationException("Invalid department", "Department cannot be empty");
        if(spec.empty()) throw ValidationException("Invalid specialization", "Specialization cannot be empty");
        if(hire.empty()) throw ValidationException("Invalid hire date", "Hire date cannot be empty");
        
        department = dept;
        specialization = spec;
        hireDate = hire;
        salary = 0.0;
        yearsOfService = 0;
    }
    
    virtual void display() const override {
        Person::display();
        cout << "Department: " << department << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "Hire Date: " << hireDate << endl;
        cout << "Years of Service: " << yearsOfService << endl;
        cout << "Salary: ₹" << salary << endl;
        cout << "Taught Courses: " << taughtCourses.size() << endl;
    }
    
    void addCourse(Course* course);  // Declaration only
    
    virtual double calculatePayment() const override {
        try {
            if(salary < 0) throw PaymentException("Invalid salary", "Salary cannot be negative");
            return salary + (yearsOfService * 50000);
        }
        catch(PaymentException& e) {
            e.log();
            throw;
        }
    }
};

class Student : public Person {
protected:
    string enrollmentDate;
    string program;
    float gradePointAverage;
    vector<Course*> enrolledCourses;
    map<Course*, float> courseGrades;
public:
    Student(const string& name, int age, const string& id, long long phone, const string& enroll, const string& prog, float gpa) 
        : Person(name, age, id, phone) {
        if(enroll.empty()) throw ValidationException("Invalid enrollment date", "Enrollment date cannot be empty");
        if(prog.empty()) throw ValidationException("Invalid program", "Program cannot be empty");
        if(gpa < 0 || gpa > 4.0) throw ValidationException("Invalid GPA", "GPA must be between 0 and 4.0");
        
        enrollmentDate = enroll;
        program = prog;
        gradePointAverage = gpa;
    }
    
    virtual void display() const override {
        Person::display();
        cout << "Enrollment Date: " << enrollmentDate << endl;
        cout << "Program: " << program << endl;
        cout << "GPA: " << gradePointAverage << endl;
        cout << "Enrolled Courses: " << enrolledCourses.size() << endl;
    }
    
    void addCourse(Course* course);  // Declaration only
    
    virtual double calculatePayment() const override {
        try {
            if(paymentAmount < 0) throw PaymentException("Invalid payment", "Payment cannot be negative");
            return paymentAmount - (enrolledCourses.size() * 50000);
        }
        catch(PaymentException& e) {
            e.log();
            throw;
        }
    }
    
    void setGrade(Course* course, float grade) {
        if(grade < 0 || grade > 4.0) {
            throw GradeException("Invalid grade", "Grade must be between 0 and 4.0");
        }
        courseGrades[course] = grade;
    }
    
    float getGrade(Course* course) {
        if(courseGrades.find(course) == courseGrades.end()) {
            throw GradeException("Course not found", "Student is not enrolled in this course");
        }
        return courseGrades[course];
    }
    
    float calculateGPA() {
        if(enrolledCourses.empty()) return 0.0;
        float sum = 0.0;
        for(const auto& grade : courseGrades) {
            sum += grade.second;
        }
        return sum / courseGrades.size();
    }
    
    int getNumCourses() const { return enrolledCourses.size(); }
    Course* getCourse(int index) const { 
        if(index < 0 || index >= enrolledCourses.size()) return nullptr;
        return enrolledCourses[index]; 
    }
    
    const vector<Course*>& getCourses() const { return enrolledCourses; }
};

// Course class implementation
class Course {
private:
    string courseCode;
    string courseTitle;
    int creditHours;
    string description;
    Professor* instructor;
    Classroom* assignedRoom;
    vector<Student*> enrolledStudents;
    bool isEnrollmentOpen;
    vector<string> prerequisiteCourses;
    string currentSemester;

    void validateCourseData(const string& code, const string& title, int credits) {
        if(code.empty()) {
            throw ValidationException("Invalid code", "Course code cannot be empty");
        }
        if(title.empty()) {
            throw ValidationException("Invalid title", "Course title cannot be empty");
        }
        if(credits <= 0) {
            throw ValidationException("Invalid credits", "Credits must be positive");
        }
    }

    void validatePrerequisites(Student* student) {
        for(const auto& prereq : prerequisiteCourses) {
            bool hasPrereq = false;
            for(const auto& enrolledCourse : student->getCourses()) {
                if(enrolledCourse && enrolledCourse->getTitle() == prereq) {
                    hasPrereq = true;
                    break;
                }
            }
            if(!hasPrereq) {
                throw EnrollmentException("Prerequisites not met", 
                    "Student has not completed required prerequisites");
            }
        }
    }

public:
    Course(const string& code, const string& title, int credits, const string& desc) {
        validateCourseData(code, title, credits);
        
        courseCode = code;
        courseTitle = title;
        creditHours = credits;
        description = desc;
        instructor = nullptr;
        assignedRoom = nullptr;
        isEnrollmentOpen = true;
        currentSemester = "";
    }
    
    string getTitle() const { return courseTitle; }
    void setInstructor(Professor* prof) { instructor = prof; }
    void setRoom(Classroom* room) { assignedRoom = room; }
    
    void enrollStudent(Student* student) {
        try {
            if(!isEnrollmentOpen) {
                throw EnrollmentException("Enrollment closed", "Course enrollment is not open");
            }
            
            validatePrerequisites(student);
            enrolledStudents.push_back(student);
        }
        catch(EnrollmentException& e) {
            e.log();
            throw;
        }
    }
    
    void display() const {
        cout << "Course Code: " << courseCode << endl;
        cout << "Title: " << courseTitle << endl;
        cout << "Credits: " << creditHours << endl;
        cout << "Description: " << description << endl;
        if(instructor) cout << "Instructor: " << instructor->getName() << endl;
        if(assignedRoom) cout << "Room: " << assignedRoom->getRoomNumber() << endl;
        cout << "Enrolled Students: " << enrolledStudents.size() << endl;
        cout << "Enrollment Status: " << (isEnrollmentOpen ? "Open" : "Closed") << endl;
        cout << "Semester: " << currentSemester << endl;
        if(!prerequisiteCourses.empty()) {
            cout << "Prerequisites: ";
            for(const auto& prereq : prerequisiteCourses) {
                cout << prereq << " ";
            }
            cout << endl;
        }
    }
    
    void closeEnrollment() { isEnrollmentOpen = false; }
    void openEnrollment() { isEnrollmentOpen = true; }
    bool isEnrollmentAvailable() const { return isEnrollmentOpen; }
    
    void addPrerequisite(const string& prereq) {
        prerequisiteCourses.push_back(prereq);
    }
    
    void setSemester(const string& semester) { currentSemester = semester; }
    string getSemester() const { return currentSemester; }
    
    bool hasPrerequisite(const string& prereq) const {
        return find(prerequisiteCourses.begin(), prerequisiteCourses.end(), prereq) != prerequisiteCourses.end();
    }
};

// Implementation of methods that use Course class
void Professor::addCourse(Course* course) {
    try {
        taughtCourses.push_back(course);
        course->setInstructor(this);
    }
    catch(EnrollmentException& e) {
        e.log();
        throw;
    }
}

void Student::addCourse(Course* course) {
    try {
        if(!course->isEnrollmentAvailable()) {
            throw EnrollmentException("Enrollment closed", "Course enrollment is not open");
        }
        enrolledCourses.push_back(course);
        course->enrollStudent(this);
    }
    catch(EnrollmentException& e) {
        e.log();
        throw;
    }
}

class University {
private:
    string name;
    vector<Department*> departments;
    vector<Classroom*> rooms;
    string currentSemester;
public:
    University(const string& name) : name(name) {
        if(name.empty()) throw ValidationException("Invalid name", "University name cannot be empty");
        currentSemester = "";
    }
    
    void addDepartment(Department* dept) {
        departments.push_back(dept);
    }
    
    void addRoom(Classroom* room) {
        rooms.push_back(room);
    }
    
    void setSemester(const string& semester) {
        if(semester.empty()) throw ValidationException("Invalid semester", "Semester cannot be empty");
        currentSemester = semester;
    }
    
    string getSemester() const { return currentSemester; }
    
    void display() const {
        cout << "University: " << name << endl;
        cout << "Departments: " << departments.size() << endl;
        cout << "Rooms: " << rooms.size() << endl;
        cout << "Current Semester: " << currentSemester << endl;
    }
};

void showMenu() {
    cout << "\n**" << endl;
    cout << "**            UNIVERSITY SYSTEM MENU           **" << endl;
    cout << "" << endl;
    cout << "** 1.  Display University Information         **" << endl;
    cout << "** 2.  Display Department Information         **" << endl;
    cout << "** 3.  Display Professor Information          **" << endl;
    cout << "** 4.  Display Student Information            **" << endl;
    cout << "** 5.  Display Course Information             **" << endl;
    cout << "** 6.  Enroll Student in Course               **" << endl;
    cout << "** 7.  Assign Professor to Course             **" << endl;
    cout << "** 8.  Close Course Enrollment                **" << endl;
    cout << "** 9.  Open Course Enrollment                 **" << endl;
    cout << "** 10. Set Current Semester                   **" << endl;
    cout << "** 11. Add Course Prerequisite                **" << endl;
    cout << "** 12. Enter Student Grade                    **" << endl;
    cout << "** 13. Calculate Student GPA                  **" << endl;
    cout << "** 14. Exit System                            **" << endl;
    cout << "" << endl;
    cout << "** Enter your choice (1-14): ";
}

void displayHeader(const string& title) {
    cout << "\n**" << endl;
    cout << "** " << title << string(46 - title.length(), ' ') << "" << endl;
    cout << "" << endl;
}

int main() {
    try {
        displayHeader("WELCOME TO UNIVERSITY MANAGEMENT SYSTEM");
        University uni("My University");
        
        Classroom r1("101", 30, true);
        Classroom r2("102", 25, false);
        uni.addRoom(&r1);
        uni.addRoom(&r2);
        
        Department d1("Computer Science", "Building A", 75000000);
        Department d2("Engineering", "Building B", 100000000);
        uni.addDepartment(&d1);
        uni.addDepartment(&d2);
        
        Professor p1("Dr. RAO", 45, "PR001", 7303420333LL, "CS", "Artificial Intelligence", "2010-04-15");
        Professor p2("Dr. Lakshay", 50, "PR002", 9910625639LL, "Engineering", "Robotics", "2008-03-20");
        d1.addProfessor(&p1);
        d2.addProfessor(&p2);
        
        Student s1("Meet Yadav", 19, "S001", 9953747875LL, "2025-05-05", "Computer Science", 3.8);
        Student s2("Mehul Batra", 22, "S002", 9996312013LL, "2025-05-05", "Data Science", 3.5);
        
        Course c1("CS101", "Introduction to Programming", 3, "Basic Programming Concepts");
        Course c2("ENG201", "Advanced Engineering", 4, "Advanced Engineering Principles");
        d1.addCourse(&c1);
        d2.addCourse(&c2);
        
        c1.setInstructor(&p1);
        c2.setInstructor(&p2);
        c1.setRoom(&r1);
        c2.setRoom(&r2);
        
        s1.addCourse(&c1);
        s2.addCourse(&c2);
        
        int choice;
        while(true) {
            showMenu();
            cin >> choice;
            
            try {
                if(choice == 1) {
                    displayHeader("UNIVERSITY INFORMATION");
                    uni.display();
                }
                else if(choice == 2) {
                    displayHeader("DEPARTMENT INFORMATION");
                    d1.display();
                    cout << "\n";
                    d2.display();
                }
                else if(choice == 3) {
                    displayHeader("PROFESSOR INFORMATION");
                    p1.display();
                    cout << "\n";
                    p2.display();
                }
                else if(choice == 4) {
                    displayHeader("STUDENT INFORMATION");
                    s1.display();
                    cout << "\n";
                    s2.display();
                }
                else if(choice == 5) {
                    displayHeader("COURSE INFORMATION");
                    c1.display();
                    cout << "\n";
                    c2.display();
                }
                else if(choice == 6) {
                    displayHeader("ENROLLING STUDENT IN COURSE");
                    cout << "** Enrolling " << s1.getName() << " in " << c2.getTitle() << " **" << endl;
                    s1.addCourse(&c2);
                    cout << "** Enrollment successful! **" << endl;
                }
                else if(choice == 7) {
                    displayHeader("ASSIGNING PROFESSOR TO COURSE");
                    cout << "** Assigning " << p2.getName() << " to " << c1.getTitle() << " **" << endl;
                    c1.setInstructor(&p2);
                    cout << "** Assignment successful! **" << endl;
                }
                else if(choice == 8) {
                    displayHeader("CLOSING COURSE ENROLLMENT");
                    cout << "** Closing enrollment for " << c1.getTitle() << " **" << endl;
                    c1.closeEnrollment();
                    cout << "** Enrollment closed successfully! **" << endl;
                }
                else if(choice == 9) {
                    displayHeader("OPENING COURSE ENROLLMENT");
                    cout << "** Opening enrollment for " << c1.getTitle() << " **" << endl;
                    c1.openEnrollment();
                    cout << "** Enrollment opened successfully! **" << endl;
                }
                else if(choice == 10) {
                    displayHeader("SETTING SEMESTER");
                    cout << "** Enter semester (e.g., Fall 2024): ";
                    string semester;
                    cin.ignore();
                    getline(cin, semester);
                    uni.setSemester(semester);
                    c1.setSemester(semester);
                    c2.setSemester(semester);
                    cout << "** Semester set successfully! **" << endl;
                }
                else if(choice == 11) {
                    displayHeader("ADDING COURSE PREREQUISITE");
                    cout << "** Adding prerequisite to " << c2.getTitle() << " **" << endl;
                    c2.addPrerequisite("CS101");
                    cout << "** Prerequisite added successfully! **" << endl;
                }
                else if(choice == 12) {
                    displayHeader("ENTERING STUDENT GRADE");
                    cout << "** Enter course index (0-" << s1.getNumCourses()-1 << "): ";
                    int courseIndex;
                    cin >> courseIndex;
                    cout << "** Enter grade (0-4.0): ";
                    float grade;
                    cin >> grade;
                    s1.setGrade(s1.getCourse(courseIndex), grade);
                    cout << "** Grade entered successfully! **" << endl;
                }
                else if(choice == 13) {
                    displayHeader("CALCULATING STUDENT GPA");
                    cout << "** Calculating GPA for " << s1.getName() << " **" << endl;
                    cout << "** Current GPA: " << s1.calculateGPA() << " **" << endl;
                }
                else if(choice == 14) {
                    displayHeader("THANK YOU FOR USING THE SYSTEM");
                    cout << "** Exiting... Goodbye! **" << endl;
                    return 0;
                }
                else {
                    cout << "\n**" << endl;
                    cout << "** Error: Invalid choice! Please try again.    **" << endl;
                    cout << "" << endl;
                }
            }
            catch(UniversitySystemException& e) {
                cout << "\n**" << endl;
                cout << "** Error: " << e.getMessage() << string(46 - e.getMessage().length(), ' ') << "" << endl;
                cout << "** Details: " << e.getDetails() << string(44 - e.getDetails().length(), ' ') << "" << endl;
                cout << "" << endl;
                e.log();
            }
        }
    }
    catch(UniversitySystemException& e) {
        cout << "\n**" << endl;
        cout << "** Error: " << e.getMessage() << string(46 - e.getMessage().length(), ' ') << "" << endl;
        cout << "** Details: " << e.getDetails() << string(44 - e.getDetails().length(), ' ') << "" << endl;
        cout << "" << endl;
        e.log();
    }
    
    return 0;
}