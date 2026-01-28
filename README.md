Chapter 06. Queue (큐)

## 📘 교재 정보

도서명: C로 배우는 쉬운 자료구조 (4판)

출판사: 한빛아카데미

학습 범위: Chapter 6 – Queue

사용 언어: C

## 📌 Chapter 6 학습 목표

큐(Queue)의 기본 개념과 FIFO 구조 이해

배열 기반 큐의 한계 이해

원형 큐(Circular Queue)의 구조와 동작 방식 학습

데크(Deque)의 구조와 큐와의 차이점 이해

큐와 데크를 활용한 응용 문제 구현

---

## 📚 큐(Queue) 개요

큐는 먼저 들어온 데이터가 먼저 나가는(FIFO: First In First Out)
선형 자료구조이다.

✔ 큐의 기본 연산

삽입(enqueue): rear에서 삽입

삭제(dequeue): front에서 삭제

✔ 큐의 활용 예

프린터 대기열

운영체제의 프로세스 스케줄링

BFS(너비 우선 탐색)

---

## 📁 디렉터리 구조
Chapter06_Queue
- circular_queue.c
- printer_queue.c
- deque_palindrome.c
- README.md

---

## ✅ 문제 1. 원형 큐(Circular Queue) 구현
📄 문제 설명

배열을 이용하여 원형 큐를 구현한다.
배열의 끝과 처음을 연결하여 공간 낭비를 줄인다.

---

## 📌 구현 연산

- initQueue
- isEmpty
- isFull
- enqueue
- dequeue
- printQueue

## 📌 핵심 아이디어

배열의 한 칸을 비워 공백 상태와 포화 상태를 구분한다.

(front == rear)               // 공백 상태

(rear + 1) % MAX == front     // 포화 상태

## 📌 실행 예

enqueue: 10

enqueue: 20

enqueue: 30

dequeue: 10

enqueue: 40

큐 상태: 20 30 40

---

## ✅ 문제 2. 프린터 출력 대기열 시뮬레이션
📄 문제 설명

프린터의 출력 대기열을 큐로 구현한다.
문서는 요청된 순서대로 출력된다.

## 📌 자료구조 정의

    typedef struct 
    {
       int id;
       int pages;
    } PrintJob;

## 📌 기능 설명

출력 요청 추가(enqueue)

출력 작업 처리(dequeue)

현재 출력 중인 문서 정보 출력

## 📌 실행 예
문서 1번 (5페이지) 출력 요청

문서 2번 (10페이지) 출력 요청

문서 1번 출력 완료

문서 2번 출력 완료


---

## ✅ 문제 3. 데크(Deque)를 이용한 회문 검사
📄 문제 설명

데크(Deque)를 이용하여 문자열이 회문인지 검사한다.
문자열의 앞과 뒤에서 문자를 하나씩 제거하며 비교한다.

## 📌 데크 특징

front와 rear 양쪽에서 삽입/삭제 가능

큐보다 유연한 구조

## 📌 처리 과정

문자열의 각 문자를 데크의 rear에 삽입

front와 rear에서 하나씩 삭제하여 비교

모든 문자가 같으면 회문

## 📌 실행 예
입력: racecar

출력: 회문입니다

입력: hello

출력: 회문이 아닙니다

---

## 🧠 Chapter 6 핵심 개념 정리
구분 - 큐(Queue)	원형 큐	데크(Deque)

구조 - FIFO	FIFO	양방향

삽입 - rear	rear	front / rear

삭제 - front	front	front / rear

장점 - 단순함	공간 효율	유연한 연산

---

## ⚠ 주의 사항

원형 큐에서 인덱스 계산 시 반드시 % MAX 사용

공백 상태와 포화 상태를 명확히 구분해야 오류 발생 방지

데크 구현 시 front/rear 이동 방향 주의

---

## ✍ 느낀 점

이번 장을 통해 큐의 기본 개념뿐만 아니라
원형 큐와 데크를 구현하며 배열 인덱스 관리의 중요성을 이해할 수 있었다.
특히 데크를 활용한 회문 검사는 큐의 응용 가능성을 잘 보여주는 예제였다.

---

🔗 참고 자료

『C로 배우는 쉬운 자료구조 (4판)』 Chapter 6

한빛아카데미 자료구조 강의 자료
