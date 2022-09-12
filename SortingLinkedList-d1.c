#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include <time.h>
#pragma warning (disable:4996)

typedef struct ItemNum {
    int num;
    struct ItemNum* next;
    struct ItemNum* prev;
}t_item;
struct ItemNum* head = NULL;
struct ItemNum* tail = NULL;

void buildList(int);
void printTheList();
void releaseTheList();
void ReplaceItem(t_item*);
void sort();

int main()
{
    int userNum=0;
    srand(time(NULL));
    buildList(30);
    buildList(10);
    buildList(9);
    buildList(20);
    buildList(40);
    buildList(25);
    sort();
    //sort();
    

    printTheList();
    releaseTheList();
}
void buildList(int num) {
    struct ItemNum* curr = (struct ItemNum*)malloc(sizeof(struct ItemNum));
    curr->num = num;
    if (head == NULL) {
        head = curr;
        tail = curr;
        curr->next = NULL;
        curr->prev = NULL;
    }
    else {

        curr->prev = tail;
        curr->next = NULL;
        tail->next = curr;
        tail = curr;
    }
}
void printTheList() {
    struct ItemNum* curr = head;
    while (curr) {
        printf("%d\n", curr->num);
        curr = curr->next;
    }
    return 0;
}
void releaseTheList() {
    struct item* freeTheList;
    while (head) {
        freeTheList = head;
        head = head->next;
        free(freeTheList);
    }
}

void ReplaceItem(t_item* item) {
    if (item == NULL)
    {
      return 0;
    }
      else if (!item->next) 
          {
             return 0;
          }
          else if (item == head && item->next == tail)
          {
             item->next = NULL;
             item->prev = tail;
             tail->prev = NULL;
             tail->next = item;
             tail = item;
             head = item->prev;
          }
          else if(item==head)
          {
              item->next = item->next->next;
              item->next->prev->next = item;
              item->next->prev->prev = NULL;
              item->prev = item->next->prev;
              item->next->prev = item;
              head = item->prev;
          }
          else if(item->next==tail)
          {
              item->prev->next = item->next;
              item->next->prev = item->prev;
              item->next->next = item;
              item->prev = item->next;
              item->next = NULL;
              tail = item; 
          }
          else
          {
              item->prev->next = item->next;
              item->next->prev = item->prev;
              item->next->next->prev = item;
              item->prev = item->next;
              item->next = item->next->next;
              item->prev->next = item;
          }
    
}
void sort()
{
    t_item* curr = head;
    char change = 1;
    if (!curr) {
        return 0;
    }
    while (change!=0)
    {
        change = 0;
        while (curr)
        {
            if(curr->next!=NULL &&curr->num > curr->next->num)
            {
              ReplaceItem(curr);
              change++;
            }
        curr = curr->next;
        }
    curr = head;
    }


}