#include <stdio.h>
#include <string.h>
#define MAX_STUDENT 4

typedef struct
{
    int door_no;
    char street_name[50];
    char city[50];
    char state[50];
} Address;

typedef struct
{
    char name[50];
    int roll_Number;
    int age;
    float marks[3];
    float Total;
    char grade;
    Address address;
} Student;

void Calculate_total_and_grade(Student *student)
{
    student->Total = student->marks[0] + student->marks[1] + student->marks[2];
    float average = student->Total / 3.0;
    if (average >= 90)
    {
        student->grade = 'A';
    }
    else if (average >= 80)
    {
        student->grade = 'B';
    }
    else if (average >= 70)
    {
        student->grade = 'C';
    }
    else if (average >= 60)
    {
        student->grade = 'D';
    }
    else if (average >= 40)
    {
        student->grade = 'E';
    }
    else
    {
        student->grade = 'F';
    }
}

void print_student_details(Student *student)
{
    printf("Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->roll_Number);
    printf("Age: %d\n", student->age);
    printf("Marks: %.2f, %.2f, %.2f\n", student->marks[0], student->marks[1], student->marks[2]);
    printf("Total: %.2f\n", student->Total);
    printf("Grade: %c\n", student->grade);
    printf("Address: %d, %s, %s, %s\n", student->address.door_no, student->address.street_name, student->address.city, student->address.state);
}

int main()
{
    Student students[MAX_STUDENT];

    for (int i = 0; i < MAX_STUDENT; i++)
    {
        printf("Enter details for student %d:\n", i + 1);
        
        printf("Name: ");
        scanf(" %c", students[i].name);  

        printf("Roll Number: ");
        scanf("%d", &students[i].roll_Number);

        printf("Age: ");
        scanf("%d", &students[i].age);

        printf("Enter 3 marks: ");
        for (int j = 0; j < 3; j++)
        {
            scanf("%f", &students[i].marks[j]);
        }

        printf("Address Door Number: ");
        scanf("%d", &students[i].address.door_no);

        printf("Street Name: ");
        scanf(" %c", students[i].address.street_name);  

        printf("City: ");
        scanf(" %c", students[i].address.city);  

        printf("State: ");
        scanf(" %c", students[i].address.state);  

        printf("\n");
    }

    for (int i = 0; i < MAX_STUDENT; i++)
    {
        Calculate_total_and_grade(&students[i]);
    }

    for (int i = 0; i < MAX_STUDENT; i++)
    {
        print_student_details(&students[i]);
    }

    return 0;
}

/*Implement the Nested structure in C, to store the address of the employee, and the address of the employee into a separate structure(like Door no, street name, city, and State) and nest the structure address into the structure employee and print it.

Note:
use pointers for structure
*/