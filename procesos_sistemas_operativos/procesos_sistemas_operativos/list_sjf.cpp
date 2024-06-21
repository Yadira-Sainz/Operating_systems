//
//  list_sjf.cpp
//  procesos_sistemas_operativos
//
//  Created by Yadira Sainz on 18/03/23.
//

#include <iostream>
using namespace std;

class Node_sjf {
public:
    string process_id;
    int time;
    int priority;
    Node_sjf* next;

    Node_sjf(string pid, int t, int p) {
        process_id = pid;
        time = t;
        priority = p;
        next = NULL;
    }
};

class SJF {
public:
    Node_sjf* head;
    Node_sjf* tail;
    int tr;
    int size;
    SJF(){
        head = NULL;
        tail = NULL;
    }
    
    void insert(string process_id, int tiempo, int priority) {
        Node_sjf* new_process = new Node_sjf(process_id, tiempo, priority);
        if (head == NULL || head->time > new_process->time) {
            new_process->next = head;
            head = new_process;
        } else {
            Node_sjf* aux = head;
            while (aux->next != NULL && aux->next->time <= new_process->time) {
                aux = aux->next;
            }
            new_process->next = aux->next;
            aux->next = new_process;
            if (new_process->next == NULL) {
                tail = new_process;
            }
        }
    }
    
    Node_sjf* remove() {
        if (head == NULL) {
            return NULL;
        }
        Node_sjf* executed_process = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        return executed_process;
    }

    void print(){
        Node_sjf* aux = head;
        while (aux){
            cout<<aux->process_id<<"|"<<aux->time<<"|"<<aux->priority;
            if(aux->next){
                cout<<" <- ";
            }
            aux = aux->next;
        }
        cout<<endl;
    }

    void process(){
        Node_sjf* executed_process=head;
        int tr = 0, trsum = 0, cont = 0;
        while (executed_process){
            print();
            remove();
            tr += executed_process->time;
            trsum += tr;
            cont++;
            cout<<"Tr"<<executed_process->process_id<<" = "<<tr<<endl;
            cout<<endl;
            executed_process = executed_process->next;
        }
        cout<<"TrProm = "<<(float)trsum / cont<<endl<<endl;
    }
};
