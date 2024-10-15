#include<stdio.h>


int main() {
	int windowsize,sent=0,ack,i,received;
	printf("enter window size\n");
	scanf("%d",&windowsize);
	while(1) {
		printf("\n");
		for(i=0;i<=windowsize;i++) {
			printf("Sent Frame %d\n",sent+1);
			sent++;
			if(sent == windowsize){
				if(received >= windowsize) {
					received = ack;
				}
				break;
			}
		}
		printf("\n");
		for(i=0;(i<windowsize) && (!(received>=sent));i++) {
			printf("%d frame received \n",received+1);
			received++;
		}
		printf("\nEnter the last Acknowledgement received: \n");
			scanf("%d",&ack);
		if (ack == windowsize) {
			break;
		}
		else{
			sent = ack;
			
		}
	}
	
	
	return 0;
}
