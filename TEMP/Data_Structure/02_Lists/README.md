# 리스트 List

## 리스트 추상 자료형

- `createList()` : 리스트 생성

  - 입력 : 최대 원소 개수 n
  - 출력 : 리스트 I
  - 최대 n 개의 원소를 가지는 공백(Empty) 리스트 I을 생성

- `deleteList()` : 리스트 삭제

  - 입력 : 리스트 I
  - 출력 : N/A
  - 리스트의 모든 원소를 제거

- `isFull()` : 원소 추가 가능 여부 판단

  - 입력 : 리스트 I
  - 출력 : True/False
  - 리스트의 원소 개수가 최대 원소 개수와 같은지를 반환, 배열 리스트인 경우에만 의미 있음

- `addElement()` : 원소 추가

  - 입력 : 리스트 I, 원소 위치 p, 원소 e
  - 출력 : 성공/실패 여부
  - 원소 e를 리스트의 특정 위치 p에 추가

- `removeElement()` : 원소 제거

  - 입력 : 리스트 I, 원소 위치 p
  - 출력 : 성공/실패 여부
  - 리스트의 위치 p에 있는 원소를 제거

- `clearList()` : 리스트 초기화

  - 입력 : 리스트 I
  - 출력 : N/A
  - 리스트의 모든 원소를 제거

- `getListLength()` : 원소 개수

  - 입력 : 리스트 I
  - 출력 : 원소의 개수
  - 리스트의 원소 개수를 반환

- `getElement()` : 원소 반환
  - 입력 : 리스트 I, 원소 위치 p
  - 출력 : 원소
  - 리스트의 위치 p에 있는 원소를 반환
    ㄷ
