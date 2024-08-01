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
void print_student_details(Student student)
{
    printf("Name: %s\n", student.name);
    printf("Roll Number: %d\n", student.roll_Number);
    printf("Marks: %.2f\n,%.2f\n,%.2f\n", student.marks[0], student.marks[1], student.marks[2]);
    printf("Total: %.2f\n", student.Total);
    printf("Grade: %c\n", student.grade);
    printf("Address: %d, %s, %s, %s\n", student.address.door_no, student.address.street_name, student.address.city, student.address.state);
}
int main()
{
    Student students[MAX_STUDENT];

    strcpy(students[0].name, "Jerry");
    students[0].roll_Number = 1;
    students[0].age = 19;
    students[0].marks[0] = 90;
    students[0].marks[1] = 80;
    students[0].marks[2] = 70;
    strcpy(students[0].address.street_name, "Main St");
    strcpy(students[0].address.city, "CityA");
    strcpy(students[0].address.state, "StateA");

    strcpy(students[1].name, "prathu");
    students[1].roll_Number = 4;
    students[1].age = 19;
    students[1].marks[0] = 50;
    students[1].marks[1] = 83;
    students[1].marks[2] = 12;
    strcpy(students[1].address.street_name, "Second St");
    strcpy(students[1].address.city, "CityB");
    strcpy(students[1].address.state, "StateB");

    strcpy(students[2].name, "harsh");
    students[2].roll_Number = 3;
    students[2].age = 19;
    students[2].marks[0] = 45;
    students[2].marks[1] = 92;
    students[2].marks[2] = 67;
    strcpy(students[2].address.street_name, "Third St");
    strcpy(students[2].address.city, "CityC");
    strcpy(students[2].address.state, "StateC");

    strcpy(students[3].name, "nimitt");
    students[3].roll_Number = 2;
    students[3].age = 19;
    students[3].marks[0] = 99;
    students[3].marks[1] = 40;
    students[3].marks[2] = 45;
    strcpy(students[3].address.street_name, "Fourth St");
    strcpy(students[3].address.city, "CityD");
    strcpy(students[3].address.state, "StateD");

    for (int i = 0; i < MAX_STUDENT; i++)
    {
        Calculate_total_and_grade(&students[i]);
    }
    for (int i = 0; i < MAX_STUDENT; i++)
    {
        print_student_details(students[i]);
    }

    return 0;
}