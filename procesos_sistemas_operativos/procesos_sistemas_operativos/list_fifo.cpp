//
//  list_fifo.cpp
//  procesos_sistemas_operativos
//
//  Created by Yadira Sainz on 18/03/23.
//

#include <iostream>
using namespace std;



class Node_fifo{
public:
    string process_id;
    int time;
    int priority;
    Node_fifo* next;

    Node_fifo(string pid, int t, int p) {
        process_id = pid;
        time = t;
        priority = p;
        next = NULL;
    }
};


class FIFO {
public:
    Node_fifo* head;
    Node_fifo* tail;
    int tr;
    int size;
    FIFO(){
        head = NULL;
        tail = NULL;
        
    }
    
    void insert(string process_id, int tiempo, int priority) {
        Node_fifo* new_process = new Node_fifo(process_id, tiempo, priority);
        if (tail == NULL) {
            head = new_process;
            tail = new_process;
        } else {
            tail->next = new_process;
            tail = new_process;
        }
    }
    
    Node_fifo* remove() {
        if (head == NULL) {
            return NULL;
        }
        Node_fifo* executed_process = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        return executed_process;
    };
    void print(){
        Node_fifo* aux = head;
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
        Node_fifo* executed_process=head;
        int tr = 0, trsum = 0, cont = 0;
        while (executed_process){
            print();
            remove();
            tr += executed_process->time;
            trsum += tr;
            cont++;
            cout<<"Tr"<<executed_process->process_id<<"="<<tr<<endl;
            cout<<endl;
            executed_process = executed_process->next;
        }
        cout<<"TrProm= "<<(float)trsum / cont<<endl<<endl;
    }
    
};
