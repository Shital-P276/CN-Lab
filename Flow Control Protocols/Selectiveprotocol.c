#include<stdio.h>
#include<unistd.h>
void main(){
    int i,num;
    printf("Selective Protocols:  \n\n");
    printf("Enter the frame number to be lost:");

    scanf("%d",&num);
    printf("\nSender \t\t\t\tReciever\n");
    for(i=1;i<=5;i++){
        
        printf("\nFrame %d sent",i);
        if(i==num){
            printf("\t\tACK Frame %d not recieved \n ",i);
        }
        else{
            printf("\t\tACK Frame %d Recieved\n",i);
        }
        
    }
    sleep(1.5);
    printf("\n resending....");
    printf("\nFrame %d Sent\t\tACK Frame %d recieved\n",num,num);
}
