#include <stdio.h>
#include <string.h>
#define MAX_STUDENT 4



typedef struct
{
    char name[50];
    int roll_Number;
    int age;
    float marks[3];
    float Total;
    char grade;
    
} Student;

Student Calculate_total_and_grade(Student student)
{
    student.Total = student.marks[0] + student.marks[1] + student.marks[2];
    float average = student.Total / 3.0;
    if (average >= 90)
    {
        student.grade = 'A';
    }
    else if (average >= 80)
    {
        student.grade = 'B';
    }
    else if (average >= 70)
    {
        student.grade = 'C';
    }
    else if (average >= 60)
    {
        student.grade = 'D';
    }
    else if (average >= 40)
    {
        student.grade = 'E';
    }
    else
    {
        student.grade = 'F';
    }
    return student;
}

void print_student_details(Student student)
{
    printf("Name: %s\n", student.name);
    printf("Roll Number: %d\n", student.roll_Number);
    printf("Age: %d\n", student.age);
    printf("Marks: %.2f, %.2f, %.2f\n", student.marks[0], student.marks[1], student.marks[2]);
    printf("Total: %.2f\n", student.Total);
    printf("Grade: %c\n", student.grade);
    printf("\n");
   
}

int main()
{
    Student students[MAX_STUDENT];

    for (int i = 0; i < MAX_STUDENT; i++)
    {
        printf("Enter details for student %d:\n", i + 1);
        
        printf("Name: ");
        scanf(" %s", students[i].name);  

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
        students[i] = Calculate_total_and_grade(students[i]);
    }

    for (int i = 0; i < MAX_STUDENT; i++)
    {
        print_student_details(students[i]);
    }

    return 0;
}

/*2. Implement the Nested structure in C using an array, 
Modify the above program with multiple student details, 
and also calculate the total and grade of the students and display it.
Don't use pointers for structure creation.*/