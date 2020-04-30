/************************************************
** Author: Andrea Hayes
** Date: April 30, 2020
** Purpose: Grade Test
** Input: Files - Corect Answers and Student Files
** Processing: Compare two char arrays to check answers
** Output: Student Answers vs Correct Answers and if student passed test
*************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int main() {
    const int RIGHT = 20.0, STUDENT = 20;
    ifstream correctAnswers, studentAnswers;
    char correct[RIGHT], answers[STUDENT];
    double percentCorrect, missed=0,correctlyAnswered;

    // Open files
    correctAnswers.open("C:/Users/Andrea Hayes/source/repos/Ch7Num11ExamGrader/CorrectAnswers.txt"); 
    studentAnswers.open("C:/Users/Andrea Hayes/source/repos/Ch7Num11ExamGrader/StudentAnswers.txt");

    // If files do not open
    if (!correctAnswers || !studentAnswers) 
    {
        cout << "Could not open file.";
        return 1;
    }

    // Puts data in file into the arrays
    for (int i = 0; i < RIGHT; i++) {   
        correctAnswers >> correct[i];
        }
    
    for (int i = 0; i < STUDENT; i++) {
        studentAnswers >> answers[i];
    }

    // Loop and ifs to check answers and display wrong answers
    for (int i = 0; i < RIGHT; i++) {
        bool equal = false;
        
        if (correct[i] != answers[i]) {
            equal = true;
            missed += 1;
        }
        
        if (equal) {
            cout << "You missed question number " << i + 1 << " ";
            cout << "The correct answer is " << correct[i] << " ";
            cout << "Your answer was " << answers[i] << " " << endl;
        }
    }
   // Figure how percentage and if passed
    correctlyAnswered = RIGHT - missed;
    cout << "You missed " << missed << " questions." << endl;
    percentCorrect = correctlyAnswered / RIGHT *100;
    cout << "Giving you a score of " << percentCorrect << "%"<< endl;

    if (percentCorrect >= 70) {
        cout << "You passed!";
    }
   else {
       cout << "You failed.";
    }
    return 0;
}
