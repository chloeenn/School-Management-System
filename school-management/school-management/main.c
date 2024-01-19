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

//Declare Function
void addStudent(void);
void showAllStudents(void);
int searchStudent(int studentID);
void displayStudent(int index);
void editStudent(int index);
//Main Menu
void showMenu(void){
    printf("\n\tMAIN MENU\n");
    printf("=======================\n");
    printf("[1] Add A New student.\n");
    printf("[2] Show All students.\n");
    printf("[3] Search A student.\n");
    printf("[4] Edit A student.\n");
    printf("[5] Delete A student.\n");
    printf("[0] Exit the Program.\n");
    printf("=======================\n");
    printf("Enter The Choice: ");
}

//Add Student
void addStudent(void){
    int StudentID = 0;
    char StudentName[100];
    char StudentEmail[100];
    bool isValid = false;
    while (!isValid) {
        printf("Enter Student ID (1-100): ");
        if (scanf("%d", &StudentID) == 1 && StudentID > 0 && StudentID <= 100) {
            if(searchStudent(StudentID)>0){
                printf("This student ID is already existed! ");
            } else {
                isValid = true;
            }
        }
        else {
            printf("Invalid Student ID! ");
            // Clear the input buffer to prevent an infinite loop
            while (getchar() != '\n');
        }
    }
    isValid = false;
    while(!isValid){
        printf("Enter Student Name: ");
        if(scanf(" %[^\n]s",StudentName) == 1 && !atoi(StudentName)){
            isValid = true;
        } else {
            printf("Invalid Name! ");
        }
    }
    isValid = false;
    while(!isValid){
        printf("Enter Student Email: ");
        if(scanf(" %[^\n]s",StudentEmail)==1 && strchr(StudentEmail, '@') != NULL){
            isValid = true;
        } else {
            printf("Invalid email! ");
        }
    }
    //Saved to Existing Record
    Students[totalStudents].id = StudentID;
    strcpy(Students[totalStudents].name,StudentName);
    strcpy(Students[totalStudents].email, StudentEmail);
    totalStudents++;
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
//Search a Student
int searchStudent(int studentID){
    int index = -1;
    for(int i=0;i<totalStudents; i++){
        if(Students[i].id == studentID){
            index = i;
        }
    }
    return index;
}
void displayStudent(int index) {
    if (index > 0) {
        printf("\nStudent Informations\n");
        printf("-------------------------\n");
        printf("Student ID: %d\n", Students[index].id);
        printf("Student Name: %s\n", Students[index].name);
        printf("Student Email: %s\n", Students[index].email);
    } else {
        printf("Student not found\n");
    }
}
//Delete a Student
void deleteStudent(int index){
    for(int i=index; i<totalStudents; i++){
        Students[i] = Students[i+1];
    }
    totalStudents--;
    printf("Student deleted successfully!\n");
}
//Edit Info Student
void editStudent(int index){
    char StudentName[100];
    char StudentEmail[100];
    bool isValid = false;
    while(!isValid){
        printf("Enter Student Name: ");
        if(scanf(" %[^\n]s",StudentName) == 1 && !atoi(StudentName)){
            isValid = true;
        } else {
            printf("Invalid Name! ");
        }
    }
    isValid = false;
    while(!isValid){
        printf("Enter Student Email: ");
        if(scanf(" %[^\n]s",StudentEmail)==1 && strchr(StudentEmail, '@') != NULL){
            isValid = true;
        } else {
            printf("Invalid email! ");
        }
    }
    //Saved to Existing Record
    strcpy(Students[index].name,StudentName);
    strcpy(Students[index].email, StudentEmail);
    printf("Information changed successfully!\n");
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
    
    Students[3].id = 13;
    strcpy(Students[3].name,"John Smith");
    strcpy(Students[3].email, "johnsmith@gmail.com");
    
    Students[4].id = 89;
    strcpy(Students[4].name,"Tommy Atkins");
    strcpy(Students[4].email, "tommyatkins@gmail.com");
    
    totalStudents = 5;
}
int main(int argc, const char * argv[]) {
    DataSeed();
    int option;
    while(1){
        showMenu();
        scanf("%d",&option);
        printf("\n");
        switch(option){
            case 0:
                printf("Program Exit Successfully!");
                exit(0);
                break;
            case 1:
                addStudent();
                break;
            case 2:
                showAllStudents();
                break;
            case 3:
            {
                int tempID = 0;
                printf("Enter the Student ID: ");
                scanf("%d",&tempID);
                int index = searchStudent(tempID);
                displayStudent(index);
                break;
            }
            case 4:
            {
                int tempID = 0;
                printf("Enter the Student ID: ");
                scanf("%d",&tempID);
                if(searchStudent(tempID)<1){
                    printf("Student ID %d is not found!",tempID);
                } else {
                    editStudent(searchStudent(tempID));
                }
                break;
            }
                
            case 5:
            {
                int tempID = 0;
                printf("Enter the Student ID: ");
                scanf("%d",&tempID);
                if(searchStudent(tempID)<1){
                    printf("Student ID %d is not found!",tempID);
                } else {
                    deleteStudent(searchStudent(tempID));
                }
                break;
            }
        }
    }
    return 0;
}
