//
//  list_priority.cpp
//  procesos_sistemas_operativos
//
//  Created by Yadira Sainz on 18/03/23.
//

#include <iostream>
using namespace std;

class node {

  node *_next;

public:
  string process_id;
  float _time;
  int _priority;
  node(string pid, int time, int priority) {
    process_id = pid;
    _time = time;
    _priority = priority;

    _next = nullptr;
  }

  node *next() const { return _next; }
  node *next(node *p) { return _next = p; }
};

class PRIORITY {
  node *start = nullptr;
  int s = 0;
  int size() const { return s; }
  bool empty() const { return s == 0; }

public:
  void insert(string process_id, int time, int priority) {

    node *p = start;
    node *q = nullptr;

    if (empty())
      start = new node(process_id, time, priority);

    else {
      while (p != nullptr and p->_priority >= priority) {
        q = p;
        p = p->next();
      }

      node *aux = new node(process_id, time, priority);

      // insertion by the end
      if (p == nullptr) {
        q->next(aux);
      }
      // insertion by the front
      else if (p == start) {
        aux->next(start);
        start = aux;
      }
      // insertion by the middle
      else {
        aux->next(p);
        q->next(aux);
      }
    }

    s++;
  }

  float quantum() {
    float sum = 0;
    float i = 0;

    node *current = start;
    while (current) {
      sum += current->_time;
      current = current->next();
      i++;
    }

    return i > 0 ?  (sum/i) : 0;
  }

  void print() {
    node *aux = start;
    while (aux) {
      cout << aux->process_id << "|" << aux->_time << "|" << aux->_priority;
      if (aux->next()) {
        cout << " <- ";
      }
      aux = aux->next();
    }
    cout << endl;
  }

  void process() {
    float qtime = quantum();
    int tr = 0, trsum = 0, i = 0;

    node *current = start;
    node *prev = nullptr;
    while (current) {

      // process can finish in 1 quantum
      if (current->_time <= qtime) {
        print();
        tr += current->_time;
        cout << "Tr" << current->process_id << ": " << tr << endl << endl;
        node *temp = current;
        if (current == start) {
          start = current->next();
        } else {
          prev->next(current->next());
        }
        current = current->next();
        delete temp;
        s--;
      }

      // process needs more quantums
      else {
        print();
        current->_time -= qtime;
        tr += qtime;
        cout << "Time left for " << current->process_id << ": "
             << current->_time << endl
             << endl;

        current->_priority -= 1;
        insert(current->process_id, current->_time, current->_priority);
        if (current == start) {
          start = current->next();
        } else {
          prev->next(current->next());
        }
        node *temp = current;
        current = current->next();
        delete temp;
        s--;
      }
      prev = current;
      i++;
      trsum += tr;
    }
    cout << "TrProm = " << (float)trsum / i << endl << endl;
  }
};
