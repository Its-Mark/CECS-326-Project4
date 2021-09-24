/**
 * Round-robin scheduling
 */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#include "task.h"
#include "list.h"
#include "cpu.h"


/*
 * Your code and design here:
 */

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

void schedule() {
    //while head exists
    while (head) {
        //start @head
        struct node *current = head;
        //go through the list
        while (current){
            if(current->task->burst > QUANTUM){
                run(current->task, QUANTUM);
                //need to decrease the burst time by quantum time
                current->task->burst -= QUANTUM;

                current = current->next;
            }
            else {
                // if the burst time is less than quantum time then we run and delete the task
                run(current->task, current->task->burst);
                struct node *previous = current;
                current = current->next;

                delete(&head, previous);
            }
        }
    }
}
