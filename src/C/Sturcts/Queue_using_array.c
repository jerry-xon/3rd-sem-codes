#include <stdio.h>
#define MAX_SIZE 10

int Queue[MAX_SIZE];
int front=0,raer=-1;
int main()
{
    int choice;
    while (choice!=4)
    {
        printf("\n-------------Queue Operations--------------\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("-------------Enter you Choice-------------\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                if(raer==MAX_SIZE-1)
                    printf("\nQueue is full");
                else
                {
                    int ele;
                    printf("\nEnter element to Insert: ");
                    scanf("%d",&ele);
                    Queue[++raer]=ele;
                }
                break;
            case 2:
                if(front>raer)
                    printf("\nQueue is empty\n");
                else
                    printf("\nElement deleted: %d\n",Queue[front++]);
                break;
            case 3:
                if(front>raer)
                    printf("\nQueue is empty\n");
                else
                {
                    printf("\nQueue elements are: \n");
                    for(int i=raer;i>=front;i--)
                        printf("%d ",Queue[i]);
                }
                break;
            case 4:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid choice");
        }
    
    }
    
        
    
    return 0;
}
