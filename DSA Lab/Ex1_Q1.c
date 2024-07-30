#include <stdio.h>
#include <string.h>
#define MAX_STUDENT 4

typedef struct
{
    char name[50];
    int roll_Number;
    int age;
    float marks[3];
 
} Student;


void print_student_details(Student student)
{
    printf("Name: %s\n", student.name);
    printf("Roll Number: %d\n", student.roll_Number);
    printf("Age: %d\n", student.age);
    printf("Marks: %.2f, %.2f, %.2f\n", student.marks[0], student.marks[1], student.marks[2]);
   
}

int main()
{
    Student students[MAX_STUDENT];

    for (int i = 0; i < MAX_STUDENT; i++)
    {
        printf("Enter details for student %d:\n", i + 1);
        
        printf("Name: ");
        scanf("%s", students[i].name);  

        printf("Roll Number: ");
        scanf("%d", &students[i].roll_Number);

        printf("Age: ");
        scanf("%d", &students[i].age);

        printf("Enter 3 marks: ");
        for (int j = 0; j < 3; j++)
        {
            scanf("%f", &students[i].marks[j]);
        }


        printf("\n");
    }

    for (int i = 0; i < MAX_STUDENT; i++)
    {
        print_student_details(students[i]);
    }

    return 0;
}