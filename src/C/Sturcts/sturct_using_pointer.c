#include <stdio.h>

typedef struct 
{
    int empID;
    char empNME[50];
    float Grosspay;
    /* data */

} Employee;

void calculateNetPay(Employee *emp){
    float TA = emp->Grosspay * 0.08;
    float DA = emp->Grosspay * 0.12;
    float netpay = emp->Grosspay + TA + DA;

    printf("Employee ID: %d\n", emp->empID);
    printf("Employee name: %s\n", emp->empNME);
    printf("Employee Grosspay: %.2f\n", emp->Grosspay);
    printf("Travel Assurance: %.2f\n", TA);
    printf("Dearness Assurance: %.2f\n", DA);
    printf("Net Pay: %.2f\n", &netpay);
}

int main(){
    Employee emp;
    printf("Enter Employee ID: ");
    scanf("%[^\n]", &emp.empID);
    printf("Enter Employee name: ");
    scanf("%s", &emp.empNME);
    printf("Enter Grosspay: ");
    scanf("%f", &emp.Grosspay);

    calculateNetPay(&emp);
    return 0;
}

