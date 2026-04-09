#include <iostream>
#include <vector>
using namespace std;
class Course
{
public:
    int id;
    double grade;
    int creditHours;

    Course(int id, double grade, int creditHours) : id(id), grade(grade), creditHours(creditHours) {}
};
class System
{
    vector<Course> courses;
    vector<vector<Course>> semesters;

public:
    void addCourse(int no, double grades, int creditHours)
    {
        courses.push_back(Course(no, grades, creditHours));
        cout << "\n Course added Successfully!";
    }

    void showCourses()
    {
        if (courses.empty())
        {
            cout << "\n No Course Found!";
            return;
        }
        for (Course &c : courses)
        {
            cout << "\n Course No : " << c.id;
            cout << "\n Grade : " << c.grade;
            cout << "\n Credit Hours : " << c.creditHours;
            cout << "\n ------------------------";
        }
    }

    bool saveSemester()
    {
        if (courses.empty())
        {
            cout << "\n No Semester Courses Found!";
            return 0;
        }

        semesters.push_back(courses);
        courses.clear();
        return true;
    }
    void calculateCGPA()
    {
        int credits = 0;
        double gradePoints = 0;

        if (semesters.empty())
        {
            cout << "\n No semester data found!";
            return;
        }

        for (auto &s : semesters)
        {
            for (auto &c : s)
            {
                credits += c.creditHours;
                gradePoints += (c.grade * c.creditHours); // FIXED
            }
        }

        double CGPA = gradePoints / credits;
        cout << "\n CGPA = " << CGPA;
    }

    void GPA(int semester)
    {
        int credits = 0;
        double gradePoints = 0;

        if (semester <= 0 || semester > semesters.size())
        {
            cout << "\nInvalid semester!";
            return;
        }

        // Adjust index
        int index = semester - 1;

        for (Course &c : semesters[index])
        {
            credits += c.creditHours;
            gradePoints += (c.grade * c.creditHours); // FIXED
        }

        if (credits == 0)
        {
            cout << "\nNo data!";
            return;
        }

        double GPA = gradePoints / credits;
        cout << "\nGPA : " << GPA;
    }
};
int main()
{
    System s;
    int semester = 0;
    int courseNo = 0;
    double grades;
    int credithours;
    cout << "\n --------- CGPA CALCULATOR ----------";
    while (true)
    {
        int choice;
        cout << "\n 1. Add Course";
        cout << "\n 2. Show courses ";
        cout << "\n 3. Save Semester Courses";
        cout << "\n 4. Calculate GPA";
        cout << "\n 5. Calculate CGPA";
        cout << "\n 6. Exit!";
        cout << "\n Enter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\n Enter grades(0-4.0) : ";
            cin >> grades;
            cout << "\n Credit Hours : ";
            cin >> credithours;
            courseNo++;
            s.addCourse(courseNo, grades, credithours);
            break;
        case 2:
            s.showCourses();
            break;
        case 3:
            if (s.saveSemester())
            {
                semester++;
                cout << "\n Semster " << semester << " data added Successfully!";
                cout << "\n Now, Add next Semester Data.";
                courseNo = 0;
            }
            break;
        case 4:
            cout << " Enter Semester : ";
            cin >> semester;
            s.GPA(semester);
            break;
        case 5:
            s.calculateCGPA();
            break;
        case 6:
            cout << "\n Exited!";
            return 0;
        default:
            cout << "\n Invalid choice!";
            break;
        }
    }
    return 0;
}