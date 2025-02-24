#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int subject(int num){
    if(num <= 20){
        return 1;
    } else if(num <= 40){
        return 2;
    } else if (num <= 60){
        return 3;
    } else if (num <= 80){
        return 4;
    } else {
        return 5;
    }
}

void evalScore(vector<int> &uncorrect){
    int sub1=100, sub2=100, sub3=100, sub4=100, sub5=100;
    int totalScore=100;
    
    cout << "--------------------------------------------" << endl;
    for(auto s : uncorrect){
		int number = s-0;
    	
        int sub = subject(number);
        // 과목별 점수
        if (sub == 1){
            sub1 -=5;
            totalScore -=1;
        } else if (sub == 2){
            sub2 -=5;
            totalScore -=1;
        } else if (sub == 3){
            sub3 -=5;
            totalScore -=1;
        } else if (sub == 4){
            sub4 -=5;
            totalScore -=1;
        } else {
            sub5 -=5;
            totalScore -=1;
        }
    } // end of for loop
    cout << "1 Subject: "<< sub1 << endl << "2 Subject: "<< sub2 << endl << "3 Subject: "<< sub3 << endl;
    cout << "4 Subject: "<< sub4 << endl << "5 Subject: "<< sub5 << endl; 
    cout <<"--------------------------------------------" << endl << "Total Score: " << totalScore << endl;
}

int main() {
    vector<int> uncorrect; // 틀린 문제
    
    string scoreVal;
    
    string cor_line, user_line;
    queue<string> correctAnswer, userAnswer; // 
    
    int correct_score = 0, uncorrect_score = 0;

    // 사용자로부터 파일 이름 입력 받기
    string cor_file_name, user_file_name;
    cout << "Enter correct answer file name: ";
    cin >> cor_file_name;
    cout << "Enter user answer file name: ";
    cin >> user_file_name;
    
    ifstream cor_file(cor_file_name);
    ifstream user_file(user_file_name);
    
    if (cor_file.is_open()) {
        while (getline(cor_file, cor_line)) {
            correctAnswer.push(cor_line);
        }
        cor_file.close();
    } else {
        cout << "Unable to open " << cor_file_name << endl;
        return 1;
    }
    
    if (user_file.is_open()) {
        while (getline(user_file, user_line)) {
            userAnswer.push(user_line);
        }
        user_file.close();
    } else {
        cout << "Unable to open " << user_file_name << endl;
        return 1;
    }
    
    int index = 1; // 문제 번호 (1부터 시작)
    
    while (!correctAnswer.empty() && !userAnswer.empty()) {
        if (correctAnswer.front() == userAnswer.front()) {
            correct_score += 1;
        } else {
            uncorrect_score += 1;
            uncorrect.push_back(index);
        }
        
        correctAnswer.pop();
        userAnswer.pop();
        
        index++; // 문제 번호 증가
    }
    
    cout << "Correct answers: " << correct_score << endl;
    cout << "Incorrect answers: " << uncorrect_score << endl;
    cout << "------ Incorrect problem numbers ------" << endl;
    
    for (int num : uncorrect) {
        cout << num << endl;
    }
    
    cout << "Do you want to printing your score? (y/n): ";
    cin >> scoreVal;
    
    if(scoreVal == "y"){
        evalScore(uncorrect);
    }
    
    return 0;
}
