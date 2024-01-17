#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
struct StudentInfo{
    char name[20];
    int id;
    char email[30];
};
struct StudentInfo Students[50];

//Global variables
bool isExecute = true;
int totalStudents = 0;


FILE *AllStudents;
//Declare Function
void addStudent(void);
void showAllStudents(void);
//Main Menu
void showMenu(void){
    printf("\t\t\tMAIN MENU\n");
    printf("\t\t=======================\n");
    printf("\t\t[1] Add A New student.\n");
    printf("\t\t[2] Show All students.\n");
    printf("\t\t[3] Search A student.\n");
    printf("\t\t[4] Edit A student.\n");
    printf("\t\t[5] Delete A student.\n");
    printf("\t\t[0] Exit the Program.\n");
    printf("\t\t=======================\n");
    printf("\t\tEnter The Choice: ");
}

//Add Student
void addStudent(void){
    int StudentID[100];
    char StudentName[100];
    char StudentEmail[100];
    printf("Enter Student ID: ");
    scanf("%d",&StudentID);
    printf("Enter Student Name: ");
    scanf(" %[^\n]s",&StudentName);
    printf("Enter Student Email: ");
    scanf(" %[^\n]s",&StudentEmail);
    //Saved to Existing Record
    Students[totalStudents].id = StudentID;
    strcpy(Students[totalStudents].name,StudentName);
    strcpy(Students[totalStudents].email, StudentEmail);
    printf("New Student Added\n");
    
}
//Show all Students
void showAllStudents(void){
    printf("|==========|====================|==============================|\n");
    printf("|    ID    |        Name        |            Email             |\n");
    printf("|==========|====================|==============================|\n");
    for(int i=0; i<totalStudents;i++){
        printf("|");
        printf("%d",Students[i].id);
        for(int j=0; j<(10-(1 + (int)log10(Students[i].id))); j++)
        {
            printf(" ");
        }
        printf("|");
        
        printf("%s",Students[i].name);
        for(int j=0; j<(20-strlen(Students[i].name)); j++)
        {
            printf(" ");
        }
        printf("|");
        
        printf("%s", Students[i].email);
        printf("\n|----------|--------------------|------------------------------|\n");
    }
}
//Dummy Data
void DataSeed(void){
    Students[0].id = 10;
    strcpy(Students[0].name,"John Doe");
    strcpy(Students[0].email, "johndoe@gmail.com");
    
    Students[1].id = 23;
    strcpy(Students[1].name,"Jane Doe");
    strcpy(Students[1].email, "janedoe@gmail.com");
    
    Students[2].id = 18;
    strcpy(Students[2].name,"Blackacre");
    strcpy(Students[2].email, "blackacre@gmail.com");
    
    Students[3].id = 1;
    strcpy(Students[3].name,"John Smith");
    strcpy(Students[3].email, "johnsmith@gmail.com");
    
    Students[4].id = 89;
    strcpy(Students[4].name,"Tommy Atkins");
    strcpy(Students[4].email, "tommyatkins@gmail.com");
    
    totalStudents = 4;
}
int main(int argc, const char * argv[]) {
    DataSeed();
    //Show option
    showMenu();
    int option;
    while(isExecute){
        scanf("%d",&option);
        switch(option){
            case 0:
                printf("Program Exit Successfully");
                isExecute = false;
                break;
            case 1:
                addStudent();
                break;
            case 2:
                showAllStudents();
        }
    }
    
    return 0;
}
