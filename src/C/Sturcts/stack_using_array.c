#include <stdio.h>
#define MAX_SIZE 10

int Stack[MAX_SIZE],top=-1;
int main()
{
    int choice;
    while (choice!=4)
    {
        printf("\n-------------Stack Operations-------------\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("-------------Enter you Choice-------------\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                if(top==MAX_SIZE-1)
                    printf("\nStack is full");
                else
                {
                    int ele;
                    printf("\nEnter element to push: ");
                    scanf("%d",&ele);
                    Stack[++top]=ele;
                }
                break;
            case 2:
                if(top==-1)
                    printf("\nStack is empty\n");
                else
                    printf("\nElement popped: %d\n",Stack[top--]);
                break;
            case 3:
                if(top==-1)
                    printf("\nStack is empty\n");
                else
                {
                    printf("\nStack elements are: \n");
                    for(int i=top;i>=0;i--)
                        printf("%d ",Stack[i]);
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
