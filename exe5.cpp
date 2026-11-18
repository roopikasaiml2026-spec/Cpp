
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <iomanip>
using namespace std;

class Student
{
public:
    string name;
    int mark;
    char grade;
};

int main()
{
    int count;

    cout << "Enter the number of students: ";
    cin >> count;

    if (count <= 0)
    {
        cout << "The number of students must be greater than 0." << endl;
        return 1;
    }

    vector<Student> students(count);

    for (int i = 0; i < count; i++)
    {
        cout << "Enter student " << i + 1 << " name and mark: ";
        cin >> students[i].name >> students[i].mark;

        if (students[i].mark < 0 || students[i].mark > 100)
        {
            cout << "Marks must be between 0 and 100." << endl;
            return 1;
        }
    }

    // Sort students by marks, highest first
    sort(students.begin(), students.end(),
         [](const Student& a, const Student& b)
         {
             return a.mark > b.mark;
         });

    // Assign grades
    transform(students.begin(), students.end(), students.begin(),
              [](Student s)
              {
                  if (s.mark >= 90)
                      s.grade = 'A';
                  else if (s.mark >= 75)
                      s.grade = 'B';
                  else if (s.mark >= 50)
                      s.grade = 'C';
                  else
                      s.grade = 'F';

                  return s;
              });

    // Find the first student scoring above 80
    auto it = find_if(students.begin(), students.end(),
                      [](const Student& s)
                      {
                          return s.mark > 80;
                      });

    // Calculate total and average marks
    int total = accumulate(students.begin(), students.end(), 0,
                           [](int sum, const Student& s)
                           {
                               return sum + s.mark;
                           });

    double average = static_cast<double>(total) / students.size();

    // Display results
    cout << "\nStudent Grade Analyzer\n";
    cout << "---------------------\n";
    cout << "Name\tMark\tGrade\n";

    for (const Student& s : students)
    {
        cout << s.name << "\t"
             << s.mark << "\t"
             << s.grade << endl;
    }

    if (it != students.end())
    {
        cout << "\nFirst student scoring above 80: "
             << it->name << endl;
    }

    cout << "Total Marks: " << total << endl;
    cout << fixed << setprecision(2);
    cout << "Average Mark: " << average << endl;

    return 0;
}