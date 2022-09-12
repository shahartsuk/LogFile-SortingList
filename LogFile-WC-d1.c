#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include <time.h>
#pragma warning (disable:4996)

#ifdef TARGIL 
void Log(char[100]);
void LogError(char[100]);
void LogEvent(char[100]);
int main_1_2()
{
	
	char strStart[1000];
	char strEnd[1000];
	char fileopen[100];
	char userResponse[100];
	char strNum[100];
	int write=0, userNum = 0;

	strcpy(strStart, "System is starting");
	LogEvent(strStart);

	printf("please enter a number:");
	scanf(" %s", userResponse);
	
	strcpy(strNum, "The number the user entered is:");
	strcat(strNum, userResponse);
	LogEvent(strNum);
	userNum = atoi(userResponse);
	

	FILE* f = fopen("newFile.log", "w");
	if (!f) {
		strcpy(strStart, "File is not opening");
		LogError(strStart);
		fileopen[0] = NULL;
	}
	else {
		strcpy(fileopen, "File open succeed");
		Log(fileopen);
		fileopen[0] = NULL;
		for (int i = 1; i <= userNum; i++)
		{
			write = fwrite(&i, sizeof(int), 1, f);

		}
	}

	fclose(f);

	strcpy(strEnd, "System is ending");
	LogEvent(strEnd);
}
void Log(char message[1000]) 
{
	char date[100];

	time_t t;
	time(&t);

	struct tm* timeinfo;

	timeinfo = localtime(&t);

	FILE* f = fopen("myFirstLogFile.log", "a");
	if (!f) {
		printf("error1");
		exit(1);
	}
	sprintf(date, "sec%d.min%d.hour%d.day%d.mounth%d.year%d-%s", timeinfo->tm_sec, timeinfo->tm_min, timeinfo->tm_hour, timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year % 100,message);
	fputs(date, f);
	fputs("\n", f);

	fclose(f);
	return 0;

}
void LogError(char message[1000]) 
{
	char error[100];
	strcpy(error, "Error-");
	strcat(error, message);
	Log(error);
}
void LogEvent(char message[100])
{
	char event[100];
	strcpy(event, "Event-");
	strcat(event, message);
	Log(event);
}
#endif TARGIL