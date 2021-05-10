/**
 * FCFS scheduling
 */
 
#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "cpu.h"

//Your code and design here
struct node* head = NULL;
int id = 1;

void add(char *n, int p, int b){
    //create new task to add
    Task *task = malloc(sizeof(Task));
    task->name = n;
    task->priority = p;
    task->burst = b;
    task->tid = id++;

    //insert task @ head
    insert(&head, task);

}

void schedule(){
    //while head exists
    while(head){

        struct node* current = head;

        //while there is a next node we want to traverse the list till we are at the end
        while(current->next){
            current = current->next;
        }
        //get tasks and burst
        Task *currentTask = current->task;
        int currentBurst = currentTask->burst;

        //run the task
        run(currentTask, currentBurst);

        //delete task from list
        delete(&head, current->task);

    }
}
