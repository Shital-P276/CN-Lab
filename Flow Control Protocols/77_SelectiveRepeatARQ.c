#include <stdio.h>

int main()
{
    printf("Selective Repeat ARQ \n---------------------------\n\n");
    
    int windowSize ;
    printf("Enter windowSize : ");
    scanf("%d" , &windowSize);
    int Ack[windowSize];
    
    for (int i = 0; i < windowSize; i++ ){
        printf("Sent Data: %d\n",i);
    }
    
    printf("\nAcknowledgement : 1 for Recvieved , 0 for not Recvieved\n\n");
    for (int i = 0 ; i < windowSize; i++){
        printf("Enter Acknowledgement %d : ",i);
        scanf("%d" , &Ack[i]);
    }
    
    printf("\n\n");
    for (int i = 0 ; i < windowSize; i++){
        if (Ack[i] != 1){
            printf("Sent Data : %d\n" , i);
            
        }
        
    }

    return 0;
}
