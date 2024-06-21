//
//  list_robin.cpp
//  procesos_sistemas_operativos
//
//  Created by Yadira Sainz on 28/03/23.
//

#include <iostream>
using namespace std;

class node_robin{
public:
  string process_id;
  int _time;
  int _priority;
  node_robin *_next;
  
  node_robin(string pid, int time, int priority) {
    process_id = pid;
    _time = time;
    _priority = priority;
    _next = nullptr;
    }

 node_robin *get_next() const { return _next; }
 node_robin *set_next(node_robin *p) { return _next = p; }
};

class round_robin{
  node_robin *start = nullptr;
  node_robin *tail = nullptr;
  int s = 0;
  
public:
  void insert(string process_id, int time, int priority){
    node_robin* new_process = new node_robin(process_id, time, priority);
        if (tail == nullptr) {
            start = new_process;
            tail = new_process;
        } else {
            tail->_next = new_process;
            tail = new_process;
        }
    }

node_robin* quitar(){
  node_robin *remove;
  if(s == 0){
    remove = nullptr;
  } else {
    remove = start;
    start = start ->_next;
    s--;
  }
  remove ->_next = nullptr;
  return remove;
}

  void print(){
   node_robin *aux = start;
        while (aux){
            cout<<aux->process_id<<"|"<<aux->_time<<"|"<<aux->_priority;
            if(aux->get_next()){
                cout<<" <- ";
            }
            aux = aux->get_next();
        }
        cout<<endl;
  }

  float quantum(){
    float sum = 0;
    int i = 0;
    node_robin *current = start;
    while (current) {
      sum += current->_time;
      current = current->get_next();
      i++;
    }
    return i > 0 ?  (sum/i) : 0;
  }

  void process(){
    node_robin* executed_process=start;
        int tr = 0, trsum = 0, i=0;
        float q= quantum();
        while (executed_process){
          //process can finish in 1 quantum
        if(executed_process ->_time <= q){
           print();
           tr += executed_process->_time;
            trsum += tr;
            cout<<"Tr"<<executed_process->process_id<<"="<<tr<<endl<<endl;
            executed_process = executed_process->_next;
          quitar();
          i++;

          //porcess needs more quantums
        } else{
         print();
        executed_process ->_time -=q;
        tr += q;
        cout << "Time left for " << executed_process->process_id << ": " << executed_process->_time << endl << endl;
        insert(executed_process->process_id, executed_process->_time, executed_process->_priority);
        
        executed_process = executed_process->_next ;
          quitar();
      }
    }
    cout << "TrProm = " << (float)trsum/i << endl << endl;
    
  }

  int size() const { return s; }
  bool empty() const { return s == 0; }
};
