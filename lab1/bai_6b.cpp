#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Struct representing a student.
 * 
 * Contains name, scores for math, literature, and English, average score, and rating.
 */
struct Student {
    string name;
    float math, literature, english;
    float average;
    string rating;
};

/**
 * @brief Validates the student's name.
 * 
 * Ensures that the name does not contain any numbers.
 * 
 * @param name The name to validate.
 * @return True if the name is valid, false otherwise.
 */
bool isValidName(const string& name) {
    for (char c : name) {
        if ((c >= '0' && c <= '9')) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Validates the student's score.
 * 
 * Ensures that the score is between 0 and 10.
 * 
 * @param score The score to validate.
 * @return True if the score is valid, false otherwise.
 */
bool isValidScore(float score) {
    return score >= 0.0f && score <= 10.0f;
}

/**
 * @brief Inputs student information.
 * 
 * Prompts the user to enter the student's name and scores, validating the inputs.
 * Computes the average score and assigns a rating based on the average.
 * 
 * @param student The student struct to fill with information.
 */
void inputStudentInfo(Student& student) {
    do {
        cout << "Enter student's name: ";
        getline(cin, student.name);
        if (!isValidName(student.name)) {
            cout << "Invalid name! Name must not contain numbers. Please enter again.\n";
        }
    } while (!isValidName(student.name));

    do {
        cout << "Enter Math score (0-10): ";
        cin >> student.math;
        if (!isValidScore(student.math)) {
            cout << "Invalid score! Please enter again.\n";
        }
    } while (!isValidScore(student.math));

    do {
        cout << "Enter Literature score (0-10): ";
        cin >> student.literature;
        if (!isValidScore(student.literature)) {
            cout << "Invalid score! Please enter again.\n";
        }
    } while (!isValidScore(student.literature));

    do {
        cout << "Enter English score (0-10): ";
        cin >> student.english;
        if (!isValidScore(student.english)) {
            cout << "Invalid score! Please enter again.\n";
        }
    } while (!isValidScore(student.english));

    cin.ignore();
    student.average = (2 * student.math + student.literature + student.english) / 4;

    if (student.average >= 9.0f) {
        student.rating = "Excellent";
    } else if (student.average >= 8.0f) {
        student.rating = "Good";
    } else if (student.average >= 6.5f) {
        student.rating = "Fair";
    } else if (student.average >= 5.0f) {
        student.rating = "Average";
    } else {
        student.rating = "Poor";
    }
}

/**
 * @brief Outputs student information.
 * 
 * Prints the student's name, scores, average, and rating.
 * 
 * @param student The student whose information is to be printed.
 */
void outputStudentInfo(const Student& student) {
    cout << fixed << setprecision(2);
    cout << "Name: " << student.name << "\n";
    cout << "Math: " << student.math << ", Literature: " << student.literature << ", English: " << student.english << "\n";
    cout << "Average: " << student.average << "\n";
    cout << "Rating: " << student.rating << "\n\n";
}

/**
 * @brief Finds and outputs the student with the highest average score.
 * 
 * Uses std::max_element to find the student with the highest average.
 * 
 * @param students The list of students.
 */
void findHighestAverageStudent(const vector<Student>& students) {
    auto highest = max_element(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.average < b.average;
    });
    cout << "Student with highest average score:\n";
    outputStudentInfo(*highest);
}

/**
 * @brief Searches for students by name.
 * 
 * Finds and outputs students whose names contain the given keyword (case-insensitive).
 * 
 * @param students The list of students.
 * @param keyword The keyword to search for.
 */
void searchStudentByName(const vector<Student>& students, const string& keyword) {
    cout << "Search results for \"" << keyword << "\":\n";
    for (const auto& student : students) {
        string studentName = student.name;
        string searchKeyword = keyword;
        transform(studentName.begin(), studentName.end(), studentName.begin(), ::tolower);
        transform(searchKeyword.begin(), searchKeyword.end(), searchKeyword.begin(), ::tolower);
        if (studentName.find(searchKeyword) != string::npos) {
            outputStudentInfo(student);
        }
    }
}

/**
 * @brief Lists students with the lowest Math score.
 * 
 * Finds and outputs all students with the lowest Math score.
 * 
 * @param students The list of students.
 */
void listLowestMathScoreStudents(const vector<Student>& students) {
    float minMathScore = min_element(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.math < b.math;
    })->math;

    cout << "Students with the lowest Math score (" << minMathScore << "):\n";
    for (const auto& student : students) {
        if (student.math == minMathScore) {
            outputStudentInfo(student);
        }
    }
}

/**
 * @brief Main function to manage student information.
 * 
 * Prompts the user to enter the number of students, inputs their information, and displays various details such as
 * student information, the student with the highest average score, search results, and students with the lowest Math score.
 */
int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore();

    vector<Student> students(n);
    for (int i = 0; i < n; ++i) {
        cout << "\nEntering information for student " << i + 1 << ":\n";
        inputStudentInfo(students[i]);
    }

    cout << "\n=== Student Information ===\n";
    for (const auto& student : students) {
        outputStudentInfo(student);
    }

    findHighestAverageStudent(students);

    string searchName;
    cout << "\nEnter name to search: ";
    getline(cin, searchName);
    searchStudentByName(students, searchName);

    listLowestMathScoreStudents(students);

    return 0;
}
