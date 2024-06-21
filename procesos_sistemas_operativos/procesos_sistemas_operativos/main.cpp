//
//  main.cpp
//  procesos_sistemas_operativos
//
//  Created by Yadira Sainz on 17/03/23.
//

#include <iostream>
#include "list_fifo.cpp"
#include "list_sjf.cpp"
#include "list_priority.cpp"
#include "list_robin.cpp"

int main() {

  FIFO fifo;
  SJF sjf;
  PRIORITY pr;
  round_robin rr;

  fifo.insert("A", 7, 4);
  fifo.insert("B", 6, 1);
  fifo.insert("C", 3, 5);
  fifo.insert("D", 9, 2);
  fifo.insert("E", 10, 3);

  sjf.insert("A", 7, 4);
  sjf.insert("B", 6, 1);
  sjf.insert("C", 3, 5);
  sjf.insert("D", 9, 2);
  sjf.insert("E", 10, 3);

  rr.insert("A", 7, 4);
  rr.insert("B", 6, 1);
  rr.insert("C", 3, 5);
  rr.insert("D", 9, 2);
  rr.insert("E", 10, 3);
  
  pr.insert("A", 7, 4);
  pr.insert("B", 6, 1);
  pr.insert("C", 3, 5);
  pr.insert("D", 9, 2);
  pr.insert("E", 10, 3);
  
  int op;
  bool op2;
  
  do{
      cout << "[1] Add a process \n";
      cout << "[2] FIFO \n";
      cout << "[3] SJF \n";
      cout << "[4] Round Robin \n";
      cout << "[5] Priority \n";
      cout << "[6] Exit \n";
      cin >> op;

      cout << "\n";

  switch(op){
    case 1:
      
      do{
        string pid;
        int time;
        int priority;
        
        cout << "ADD A PROCESS\n";
        cout << "Process ID: ";
        cin >> pid;
        cout << "Time: ";
        cin >> time;
        cout << "Priority: ";
        cin >> priority;
        fifo.insert(pid, time, priority);
        pr.insert(pid, time, priority);

        cout << "Do you want to add another process?";
        cout << "\n[1] Yes           [0] No  ";
        cin >> op2;

        cout << "\n";
        
      } while(op2 != 0);
    
    break;
    
    case 2:
      cout << "FIFO \n";
      fifo.process();
    break;
    
    case 3:
      cout << "SJF \n";
      sjf.process();
    break;
    
    case 4:
      cout << "ROUND ROBIN \n";
      rr.process();
    break;
    
    case 5:
      cout << "PRIORITY \n";
      pr.process();
      cout << "\n";
    break;
  }
    
  } while(op!=6);

  return 0;
}
