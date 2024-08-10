#include <stdio.h>
#define MAX_SIZE 10
int Stack[MAX_SIZE],top = -1;

void Push(){
    if(top==MAX_SIZE-1){
        printf("\nStack overflow.");
    }
    else{
            int n;
            printf("Enter the element to push: ");
            scanf("%d",&n);
            top++;
            Stack[top] = n;
            
        }
    
}

void Pop(){
    if(top==-1){
        printf("\nStack is empty.\n\n\n");
    }else{
        printf("\nElement popped is: %d",Stack[top]);
        top--;
        }
    
}

void Display(){
    if(top==-1){
        printf("\nStack is empty.");
    }else{
        printf("\nStack elements are:\n");
        for(int i=top;i>=0;i--){
            printf("%d\n",Stack[i]);
        }
    }
}
int main()
{
    int choice;
    do
    {
        printf("\n-------------Stack Operations-------------\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("-------------Enter you Choice-------------\n");
        scanf("%d",&choice);
        switch (choice)
    {
    case 1: Push();
        break;
    case 2: Pop();
        break;
    case 3: Display();
        break;
    case 4: 
        break;
    
    default:printf("Invalid choice.");
        break;
    }
    } while (choice!=4);

    
    return 0;
}