#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//function signatures 
void add(char value[20]);
void savetofile();
//types 
typedef struct tasks{
    int id;
    char task[20];
    char day[10];
}toDo;

//global variables
int counter=0;
char duties[20];
toDo duty[8];
bool interruptFlag=false; //program will be immediately closed if this flag is true
char day[10];
char overflowPreventer[30]="input length cannot exceed 20"; 

void add(char value[20]){   //adds new tasks day by day
    if(strlen(value)>20){
        printf("%s",overflowPreventer);
        interruptFlag=true;
    }
    else{
        switch (counter)
        {
        case 0:
            sprintf(duty[counter].day,"monday");
            sprintf(duty[counter].task,"%s",value);
            duty[counter].id=counter+1;
            break;
        case 1:
            sprintf(duty[counter].day,"tuesday");
            sprintf(duty[counter].task,"%s",value);
            duty[counter].id=counter+1;            
            break;
        case 2:
            sprintf(duty[counter].day,"wednesday");
            sprintf(duty[counter].task,"%s",value);
            duty[counter].id=counter+1;
            break;
        case 3:
            sprintf(duty[counter].day,"thursday");
            sprintf(duty[counter].task,"%s",value);
            duty[counter].id=counter+1;
            break;
        case 4:
            sprintf(duty[counter].day,"friday");
            sprintf(duty[counter].task,"%s",value);
            duty[counter].id=counter+1;
            break;
        case 5:
            sprintf(duty[counter].day,"saturday");
            sprintf(duty[counter].task,"%s",value);
            duty[counter].id=counter+1;
            break;
        case 6:
            sprintf(duty[counter].day,"sunday");
            sprintf(duty[counter].task,"%s",value);
            duty[counter].id=counter+1;
            break;
    }
}}


void savetofile(){ //creates tasks.txt if it does not already exists and overrides the tasks into that txt file
    FILE *fp;
    fp= fopen("tasks.txt","w");
    for(counter=0;counter<7;counter++){
        fprintf(fp,"\ntask id : %d \n day : %s \n task:%s\n",duty[counter].id,duty[counter].day,duty[counter].task);
    } 
    fclose(fp);
}

int main(void){
    for(;counter<7;counter++){
        if(interruptFlag==true){
            exit(1);
        }
        printf("Task list %d \n",counter);
        scanf("%s",duties);
        add(duties);
    }
    savetofile();
    return 0;
}