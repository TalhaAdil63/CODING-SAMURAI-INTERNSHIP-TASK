#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Define a struct to store student information
struct Student
{
    string name;
    int studentID;
    double assignmentScore;
    double quizScore;
    double examScore;
    double overallGrade;
    char letterGrade;
    string comments;
};

// Function to input student details and scores
Student inputStudentInfo()
{
    Student student;
    cout << endl;

    cout << "Enter student name: ";
    cin >> student.name;
    /*cout << endl;*/

    cout << "Enter student ID: ";
    cin >> student.studentID;

    cout << "Enter assignment score (0-100): ";
    cin >> student.assignmentScore;

    cout << "Enter quiz score (0-100): ";
    cin >> student.quizScore;

    cout << "Enter exam score (0-100): ";
    cin >> student.examScore;

    return student;
}

// Function to calculate the overall grade
void calculateOverallGrade(Student &student, double assignmentWeight, double quizWeight, double examWeight)
{
    // Calculate the weighted average
    student.overallGrade = (student.assignmentScore * assignmentWeight +
                            student.quizScore * quizWeight +
                            student.examScore * examWeight);
}

// Function to map the numerical grade to a letter grade
char maptoLetterGrade(double overallGrade)
{
    if(overallGrade >= 90)
    {
        return 'A';
    }
    else if(overallGrade >= 80)
    {
        return 'B';
    }
    else if(overallGrade >= 70)
    {
        return 'C';
    }
    else if(overallGrade >= 60)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}

// Function to provide comments based on the final grade
string getComments(char letterGrade)
{
    string comments;

    switch(letterGrade)
    {
    case 'A':
        comments = "Congratulations! Excellent Performance!";
        break;
    case 'B':
        comments = "Good Job! Keep Up the Good Work.";
        break;
    case 'C':
        comments = "You Passed. Consider Improving Your Scores.";
        break;
    case 'D':
        comments = "You Barely Passed. Focus on Improvement.";
        break;
    default:
        comments = "You Failed. Seek Help and Work Harder.";
        break;
    }

    return comments;
}

int main(void)
{
    vector<Student> students;

    double assignmentWeight, quizWeight, examWeight;
    int numStudents;

    // Input weights for assignments, quizzes, and exams
    cout << "Enter Weight for Assignments (0-1): ";
    cin >> assignmentWeight;

    cout << "Enter Weight for Quizzes (0-1): ";
    cin >> quizWeight;

    cout << "Enter Weight for Exams (0-1): ";
    cin >> examWeight;

    // Enter the number of students
    cout << "Enter the Number of Students: ";
    cin >> numStudents;

    // Input student information and calculate grades
    for(int i = 0; i < numStudents; i++)
    {
        cin.ignore(); //Consume the inline character
        Student student = inputStudentInfo();
        calculateOverallGrade(student, assignmentWeight, quizWeight, examWeight);
        student.letterGrade = maptoLetterGrade(student.overallGrade);
        student.comments = getComments(student.letterGrade);
        students.push_back(student);
    }

    cout << endl;
    // Display the results for each student
    cout << "Student Grades and Comments: " << endl;
    cout << "----------------------------------------" << endl;

    for(const Student &student : students)
    {
        cout << "Name: " << student.name << endl;
        cout << "Student ID: " << student.studentID << endl;
        cout << "Overall Grade: " << fixed << setprecision(2) << student.overallGrade << endl;
        cout << "Letter Grade: " << student.letterGrade << endl;
        cout << "Comments: " << student.comments << endl;
        cout << "----------------------------------------" << endl;
    }

    return 0;
}
