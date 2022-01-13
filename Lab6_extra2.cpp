//조규현 20191669 Lab6-3

#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>

using namespace std;

struct num {
    char name;
    int id;
    string major;
    char grade;
};

class Node {
private:
    char name;
    int id;
    string major;
    char grade;
    Node *next;
    friend class student;
};

class student {
private:
    Node *head;
public:
    student() {head = NULL;}
    void insertNode(struct num);
    void displayList();
    void searchGrade(char grade);
    void searchMajor(string major);
    bool isEmpty();
};

int main() {
    FILE *f;
    f = fopen("data1.txt", "r");		//“Data1” 파일을 불러온다.

    struct num name[10];	//구조체 Node의 성질을 가진 name 10개를 생성한다.

    student st;
    student st2;

    for (int i = 0; i < 8; ++i) {
        char buf[10];			//major를 입력받을 buf 선언
        int n = 0;
        fscanf(f, "%s %d %s %s", &name[i].name, &name[i].id, buf, &name[i].grade);		//파일로부터 name,id,major,grade를 입력받는다.
        while (buf[n] != NULL)
        {
            name[i].major += buf[n];		//major에 방금 받은 buf 삽입
            ++n;
        }
        st.insertNode(name[i]);		//구조체 넣는다.
    }

    st.displayList();		//1번 문제 출력

    st.searchGrade('A');		//2번 문제 출력

    FILE *f1;
    f1 = fopen("data2.txt", "r");

    for (int i = 0; i < 8; i++) {
        st2.insertNode(name[i]);
    }

    struct num name1[10];

    for (int j = 0; j < 3; ++j) {
        char buf[10];			//major를 입력받을 buf 선언
        int n = 0;
        fscanf(f1, "%s %d %s %s", &name1[j].name, &name1[j].id, buf, &name1[j].grade);		//파일로부터 name,id,major,grade를 입력받는다.
        while (buf[n] != NULL)
        {
            name1[j].major += buf[n];		//major에 방금 받은 buf 삽입
            ++n;
        }
        st2.insertNode(name1[j]);		//구조체 넣는다.
    }

    st2.searchMajor("CS");		//3번 문제 출력


}
void student::insertNode(struct num num) {
    Node *temp = new Node();
    temp->name = num.name;
    temp->id = num.id;
    temp->major = num.major;
    temp->grade = num.grade;

    Node *p = NULL, *q = NULL;

    if(head == NULL) head = temp;
    else if(temp->name < head->name) {
        temp->next = head;
        head = temp;
    }
    else{
        p = head;
        while((p != NULL) && (p->name < temp->name)) {
            q = p;
            p = p->next;
        }
        if(p != NULL) {
            temp->next = p;
            q->next = temp;
        }
        else {
            q->next = temp;
        }
    }
}

void student::displayList() {
    Node *p = NULL;

    if(!isEmpty()) {
        p = head;
        cout << "NAME ID  MAJOR GRADE" << endl;
        while(p) {
            cout << p->name << "    " << p->id << " ";
            cout << p->major << "    " << p->grade << endl;
            p = p->next;
        }
        cout << endl;
    }
    else cout << "List empty" << endl;

}
void student::searchGrade(char grade) {
    Node *p = NULL;

    if(head != NULL) {
        p = head;
        cout << "NAME ID  MAJOR GRADE" << endl;
        while(p != NULL){
            if(p->grade == grade) {
                cout << p->name << "    " << p->id << " ";
                cout << p->major << "    " << p->grade << endl;
            }
            p = p->next;
        }
        cout << endl;
    }
    else cout << "List empty" << endl;
}
void student::searchMajor(string major) {
    Node *p = NULL;

    if(head != NULL) {
        p = head;
        cout << "NAME ID  MAJOR GRADE" << endl;
        while(p != NULL) {
            if(p->major == major) {
                cout << p->name << "    " << p->id << " ";
                cout << p->major << "    " << p->grade << endl;
            }
            p = p->next;
        }
        cout << endl;
    }
    else cout << "List empty" << endl;
}
bool student::isEmpty() {
    if(head == NULL) return true;
    else return false;
}