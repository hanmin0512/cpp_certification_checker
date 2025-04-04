# 정답 비교 프로그램

## 개요
> 정보처리기사 필기 공부를 하는 중, 공부가 너무 하기 싫어서 개발을 하기로 했습니다. 개발 언어 코딩 테스트 공부 했었던 언어인 C++을 사용했습니다.
> 컴파일된 프로그램 chekcer의 경우 MacOS 전용이라 윈도우 사용시 별도로 컴파일 필요


## 사용자 요구 사항
> 사용자는 바로 "저" 입니다. 먼저 시나공 기출문제 교제를 이용했습니다.
- 100문제 분량의 정답과, 사용자 정답지를 비교하여 체점을 진행하는 기능
- 각 과목당 개별 체점하는 기능
- 각 과목 합산한 최종 점수
- 틀린 문제 번호 출력

## 컴파일 방법
cmd 콘솔에 checker.cpp가 위치한 경로로 이동 후 아래 명령어 입력
```
g++ checker.cpp -o checker.exe
```

### 실행
```
checker
```


## 사용 방법
- 각 문항의 정답을 .txt 확장자로 하여 파일을 만듭니다.

ex) correct_answer.txt
```
4
3
3
2
1
```

- 100문제의 정답을 기록한 후 사용자가 입력할 .txt 확장자 파일을 만듭니다.
- 이후 문제를 보고 정답을 적어 나갑니다.
- 모든 문제에 대한 답을 기록하였다면 저장 후 프로그램을 실행시킵니다.

ex) user_answer.txt
```
4
3
2
1
1
```

### 프로그램 실행

cmd 입력 값 ex)
```
checker
correct_answer.txt
user_answer.txt
```


