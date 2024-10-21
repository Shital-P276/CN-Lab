#include<stdio.h>

void main(){
    int i,num;
    printf("\t\tStop and wait ARQ\n\n");
    printf("Enter the frame number to be lost:");

    scanf("%d",&num);
    printf("\nSender \t\t\t\tReciever\n");
    for(i=1;i<=5;i++){
        
        printf("\nFrame %d sent",i);
        if(i==num){
            printf("\t\tACK Frame %d not recieved. \nResending ....",i);
            printf("\nFrame %d Sent\n\t\t\tACK Frame %d recieved\n",i,i);
        }
        else{
            printf("\t\tACK Frame %d Recieved\n",i);
        }
    }
}
