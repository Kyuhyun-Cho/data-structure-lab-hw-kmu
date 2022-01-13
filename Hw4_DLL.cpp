/***********************************************************************************************************************
* Name: 조규현
* Student ID: 20191669
* Program: Hw#4

* Description: Doubly Linked List의 적용할 수 있는 여러 함수들을 테스트하는 것을 목표로 한다.

* Algorithm: 1. insertAfter - current 노드 뒤에 데이터 삽입
             2. insertBefore - current 노드 앞에 데이터 삽입
             3. insertFirst - Doubly Linked List의 맨 앞에 데이터 삽입
             4. insertLast - Doubly Linked List의 맨 뒤에 데이터 삽입
             5. deleteCurrent - current 노드 삭제
             6. locateCurrent - current 노드 위치 변환
             7. updateCurrent - current 노드의 데이터 교체
             8. displayCurrent - current 노드 출력
             9. displayList - Doubly Linked List 전체 출력

* Variables:
 int data: 노드에 들어갈 데이터 값
 Node *next: 다음 위치에 있는 노드를 가리키기 위한 포인터 변수
 Node *prev: 이전 위치에 있는 노드를 가리키기 위한 포인터 변수
 Node *head: 맨 앞에 위치하는 노드를 가리키기 위한 포인터 변수
 Node *current: 현재 위치에 있는 노드를 가리키기 위한 포인터 변수
 int size: Doubly Linked List의 크기에 해당하는 변수
***********************************************************************************************************************/

#include <iostream>

using namespace std;

class Node {
private:
    int data;
    Node *next;
    Node *prev;
    Node(int num) {data = num; prev = 0; next = 0;}
    friend class List;
};

class List {
private :
    Node *head;
    Node *current;
public:
    List() {head = 0, current = 0;};
    ~List();
    void insertAfter(int);
    void insertBefore(int);
    void insertFirst(int);
    void insertLast(int);
    void deleteCurrent();
    void locateCurrent(int);
    void updateCurrent(int);
    void displayCurrent();
    void displayList();
    int listLength();
    bool isEmpty();
    int size = 0;
};

List::~List() {
    Node *p;
    while (head != 0) {
        p = head;
        head = head->next;
        delete p;
    }
}

/***********************************************************************************************************************
* fucntion: void List::insertAfter(int data)
* description: temp 노드를 생성한 후, 리스트가 비어있는 경우에는 temp 노드를 head 노드로 지정해준다. 리스트가 비어있지 않을 때는, current 노드가
               마지막이 아닌 경우와 마지막인 경우로 나누어 current 노드 다음에 temp 노드가 오도록 각각의 prev, next 값을 조정해주고 입력한 데이터가
               current 노드가 되도록 지정해준 뒤 리스트의 크기를 1 늘려준다.
* variables:
 Node *temp: 입력할 데이터 값을 가지고 있는 노드
***********************************************************************************************************************/

void List::insertAfter(int data) {
    Node *temp = new Node(data);
    if (isEmpty()) {
        head = temp;
    }
    else if (current->next != NULL) { //current가 마지막이 아닌 경우
        temp->prev = current;
        temp->next = current->next;
        current->next->prev=temp;
        current->next = temp;
    }
    else { //current가 마지막인 경우
        current->next = temp;
        temp->prev = current;
    }
    current = temp;
    size++;
}

/***********************************************************************************************************************
* fucntion: void List::insertBefore(int data)
* description: temp 노드를 생성한 후, 리스트가 비어있는 경우에는 temp 노드를 head 노드로 지정해준다. 리스트가 비어있지 않을 때는, current 노드가
               head인 경우와 head가 아닌 경우로 나누어 current 노드 이전 temp 노드가 오도록 각각의 prev, next 값을 조정해주고 입력한 데이터가
               current 노드가 되도록 지정해준 뒤 리스트의 크기를 1 늘려준다.
* variables:
 Node *temp: 입력할 데이터 값을 가지고 있는 노드
***********************************************************************************************************************/

void List::insertBefore(int data) {
    Node *temp = new Node(data);
    if (isEmpty()) {
        head = temp;
    }
    else if (current == head) { //current가 head인 경우
        temp->next = current;
        current->prev = temp;
        head = temp;
    }
    else {
        temp->prev = current->prev; //current가 head가 아닌 경우
        temp->next = current;
        current->prev->next = temp;
        current->prev = temp;
    }
    current = temp;
    size++;
}

/***********************************************************************************************************************
* fucntion: void List::insertFirst(int data)
* description: temp 노드를 생성한 후, 리스트가 비어있는 경우에는 temp 노드를 head 노드로 지정해준다. 리스트가 비어있지 않을 때는, 리스트의 맨 앞에
               temp 노드가 오도록 head 노드와 temp 노드 각각의 prev, next 값을 조정해주고 입력한 데이터가 current 노드가 되도록 지정해준 뒤
               리스트의 크기를 1 늘려준다.
* variables:
 Node *temp: 입력할 데이터 값을 가지고 있는 노드
***********************************************************************************************************************/


void List::insertFirst(int data) {
    Node *temp = new Node(data);
    if (isEmpty()) {
        head = temp;
    }
    else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    current = temp;
    size++;
}

/***********************************************************************************************************************
* fucntion: void List::insertLast(int data)
* description: temp 노드를 생성한 후, 리스트가 비어있는 경우에는 temp 노드를 head 노드로 지정해준다. 리스트가 비어있지 않을 때는, 리스트의 맨 뒤에
               temp 노드가 오도록 마지막 노드를 찾아준 뒤 해당 노드와 temp 노드 각각의  prev, next 값을 조정해주고 입력한 데이터가 current 노드가
               되도록 지정해준 뒤 리스트의 크기를 1 늘려준다.
* variables:
 Node *temp: 입력할 데이터 값을 가지고 있는 노드
 Node *p: 마지막 노드를 찾기 위해 임시로 선언한 노드
***********************************************************************************************************************/

void List::insertLast(int data) {
    Node *temp = new Node(data);
    Node *p;
    if (isEmpty()) {
        head = temp;
    }
    else {
        p = head;
        while(p->next != NULL) {
            p = p->next;
        }
        temp->prev = p;
        p->next = temp;
    }
    current = temp;
    size++;
}

/***********************************************************************************************************************
* fucntion: void List::deleteCurrent()
* description: current 노드가 head 노드인 경우, 마지막 노드인 경우, 중간에 위치한 경우 총 3가지의 경우로 나누어 임시로 선언한 p 노드를 이용하여
               각각의 경우마다 current 노드를 삭제해주고 current 노드 옆에 있던 노드들의 prev, next 값을 조정해준 뒤, 리스트의 사이즈를 1 줄여준다.
* variables:
 Node *p: head 노드, 마지막 노드, 중간에 위치한 노드를 지정하여 각각의 노드를 리스트의 데이터 손상 없이 삭제할 수 있도록 임시로 선언한 노드
***********************************************************************************************************************/

void List::deleteCurrent() {
    Node *p;
    if (isEmpty()) {
        cout << "List is Empty" << endl;
    }
    else if (current == head) { //current가 head인 경우
        p = head;
        head = head->next;
        delete p;
        size--;
    }
    else if (current->next == NULL) { //current가 마지막일 경우
        p = head;
        while(p->next != NULL) {
            p = p->next;
        }
        current->prev->next = NULL;
        current = head;
        delete p;
        size--;
    }
    else { //current가 중간에 위치한 경우
        p = current;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        current = current->next;
        delete p;
        size--;
    }
}

/***********************************************************************************************************************
* fucntion: void List::locateCurrent(int Nth)
* description: p 노드를 임시로 선언하여 도달하고자 하는 위치의 노드까지 이동해준 뒤 해당 노드를 current 노드로 지정해주고 그 값을 출력한다.
               만약 도달하고자 하는 위치가 리스트의 전체 길이를 초과할 시에는 오류 메세지를 출력한다.
* variables:
 Node *p: current 노드로 변환하고자 하는 노드까지 도달하고자 임시로 선언한 노드
 int Nth: current 노드로 변환하고자 하는 노드의 위치 값
 int count: 임시로 선언한 p 노드가 변환하고자 하는 위치의 노드를 지정하고 있는지 확인해주기 위해 선언한 변수
***********************************************************************************************************************/

void List::locateCurrent(int Nth) {
    Node *p;
    int count = 1;
    if (head == NULL) {
        cout << "List is Empty" << endl;
    }
    else if (listLength() >= Nth) {
        p = head;
        while(p->next != NULL) {
            p = p->next;
            count++;
            if (count == Nth) {
                break;
            }
        }
        cout << Nth << " * " << p->data << endl;
        current = p;
    }
    else {
        cout << "No such a line" << endl;
    }
}

/***********************************************************************************************************************
* fucntion: void List::updateCurrent(int data)
* description: current 노드의 데이터 값을 입력 받은 값으로 변환해준다.
* variables: x
***********************************************************************************************************************/

void List::updateCurrent(int data) {
    if (isEmpty()) {
        cout << "List is Empty" << endl;
    }
    else {
        current->data = data;
    }
}

/***********************************************************************************************************************
* fucntion: void List::displayCurrent()
* description: current 노드의 데이터 값을 출력한다.
* variables: x
***********************************************************************************************************************/

void List::displayCurrent() {
    if (isEmpty()) {
        cout << "List is Empty" << endl;
    }
    else {
        cout << current->data << endl;
    }
}

/***********************************************************************************************************************
* fucntion: void List::displayList()
* description: 임시로 선언한 p 노드를 통해 리스트 각각의 값으로 이동하여 리스트 전체 값을 출력해준다. 이 때 current 노드는 '*' 을 통해 표시해준다.
* variables:
 Node *p: 리스트에 있는 모든 값에 접근하기 위해 임시로 선언한 노드
***********************************************************************************************************************/

void List::displayList() {
    Node *p;
    p = head;
    if (isEmpty()) {
        cout << "List is Empty" << endl;
    }
    else {
        cout << "---List---" << endl;
        for (int i = 1; i <= listLength(); i++) {
            if (p == current) {
                cout << "  " << i << " * " << p->data << endl;
            }
            else {
                cout << "  " << i << " : " << p->data << endl;
            }
            p = p->next;
        }
    }
}

/***********************************************************************************************************************
* fucntion: int List::listLength()
* description: 리스트에 전체 크기를 반환해준다.
* variables: x
***********************************************************************************************************************/

int List::listLength() {
    return size;
}

/***********************************************************************************************************************
* fucntion: bool List::isEmpty()
* description: 리스트가 비어있는지 확인해준다.
* variables: x
***********************************************************************************************************************/

bool List::isEmpty() {
    if (head == NULL) {
        return true;
    }
    else {
        return false;
    }
}

/***********************************************************************************************************************
* fucntion: int main()
* description: (1) ~ (10)까지 각각의 함수를 switch 문을 통해 메뉴로 만들어 실행할 수 있도록 해준다.
* variables:
 List dll: Doubly Linked List 객체
 int n: 몇 번 함수를 실행할지 정해주는 변수
***********************************************************************************************************************/

int main() {
    List dll;
    int n;
    while (true) {
        cout << "Command: (1)insertAfter (2)insertBefore (3)insertFirst (4)insertLast (5)deleteCurrent" << endl;
        cout << "         (6)locateCurrent (7)updateCurrent (8)displayCurrent (9)displayList (10)Quit: ";
        cin >> n;
        switch (n) {
            case 1: {
                int data;
                cout << "Enter a data to insert: ";
                cin >> data;
                dll.insertAfter(data);
                dll.displayList();
                break;
            }
            case 2: {
                int data;
                cout << "Enter a data to insert: ";
                cin >> data;
                dll.insertBefore(data);
                dll.displayList();
                break;
            }
            case 3: {
                int data;
                cout << "Enter a data to insert: ";
                cin >> data;
                dll.insertFirst(data);
                dll.displayList();
                break;
            }
            case 4: {
                int data;
                cout << "Enter a data to insert: ";
                cin >> data;
                dll.insertLast(data);
                dll.displayList();
                break;
            }
            case 5: {
                dll.deleteCurrent();
                dll.displayList();
                break;
            }
            case 6: {
                int Nth;
                cout << "Enter a position to locate: ";
                cin >> Nth;
                dll.locateCurrent(Nth);
                break;
            }
            case 7: {
                int data;
                cout << "Enter a data to update: ";
                cin >> data;
                dll.updateCurrent(data);
                dll.displayList();
                break;
            }
            case 8: {
                cout << "Current data: ";
                dll.displayCurrent();
                break;
            }
            case 9: {
                dll.displayList();
                break;
            }
            case 10: {
                return 0;
            }
        }
    }
}