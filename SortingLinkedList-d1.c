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
void logFile(char[100]);
void logEvent(char[100]);
void logError(char[100]);

int main()
{
    char strStart[100];
    char strEnd[100];
    char strList[100];
    char strSortList[100];
    int userNum=0;
    srand(time(NULL));

    strcpy(strStart, "System is starting");
    logEvent(strStart);
    
    for (int i = 0; i < 100000; i++)
    {
        buildList(rand());
    }
    strcpy(strList, "Build the list starting");
    logEvent(strList);

    sort();

    strcpy(strSortList, "Sorting the list starting");
    logEvent(strSortList);

    printTheList();
    releaseTheList();
    strcpy(strEnd, "System is ending");
    logEvent(strEnd);
}
void buildList(int num) {
    char addItem[100];
    struct ItemNum* curr = (struct ItemNum*)malloc(sizeof(struct ItemNum));
    if (!curr)
    {
        strcpy(addItem, "Cant add a item");
        logError(addItem);
        exit(1);
    }

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
        printf("%d,", curr->num);
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
            if(curr->next!=NULL && curr->num > curr->next->num)
            {
              ReplaceItem(curr);
              change++;
            }
        curr = curr->next;
        }
    curr = head;
    }
}

void logFile(char message[1000])
{
    char date[100];

    time_t t;
    time(&t);

    struct tm* timeinfo;

    timeinfo = localtime(&t);

    FILE* f = fopen("sortingListLogFile.log", "a");
    if (!f) {
        printf("error1");
        exit(1);
    }
    sprintf(date, "sec-%d-%s", timeinfo->tm_sec,message);
    fputs(date, f);
    fputs("\n", f);

    fclose(f);
    return 0;

}
void logError(char message[1000])
{
    char error[100];
    strcpy(error, "Error-");
    strcat(error, message);
    logFile(error);
}
void logEvent(char message[100])
{
    char event[100];
    strcpy(event, "Event-");
    strcat(event, message);
    logFile(event);
}