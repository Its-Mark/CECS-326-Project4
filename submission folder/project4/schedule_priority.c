/*
 * Priority scheduling
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
        //start @ head
        struct node *current = head;
        struct node *next = head;
        while (current){
            if (current->task->priority > next->task->priority){
                //switch positions in list
                next = current;
            }
            current = current->next;
        }
        //run then delete task from list
        run(next->task, next->task->burst);
        delete(&head, next->task);
    }
}
