#include <stdio.h>

void send(int windowsize){
    printf("\n");
    for(int i = 0 ; i < windowsize ; i++){
        printf ("Sent Data : %d\n" , i);
    }
}

void recieved(int windowsize){
    int Ack[windowsize];
    int flag;
    for (int i = 0;i<windowsize;i++){
        printf("Acknowledgement %d : ",i);
        scanf("%d",&flag);
        Ack[i] = flag;
    }
    
    for (int i=0;i<windowsize;i++){
        if(Ack[i] != 1){
            send(windowsize);
            break;
        }
    }
}


int main()
{
    printf("Stop & Wait ARQ\n---------------\n\n");
    int windowsize;
    printf("Enter windowsize: ");
    scanf("%d", &windowsize);
    
    send(windowsize);
    
    printf("\nEnter Acknowledgements : (1 for recieved , 0 for lost)\n");
    recieved(windowsize);
    return 0;
}
