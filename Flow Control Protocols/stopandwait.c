#include<stdio.h>
#include<unistd.h>

void stopnwait(int frame,int windowsize) {
	int i;
	printf("SENDER \t\t RECEIVER \n ");
	for(i=1;i<=windowsize;i++) {
		if (i == frame ) {
			printf("frame %d sent \t frame %d not received \n",i,i);
		}
		else {
			printf("frame %d sent \t frame %d received \n",i,i);
		}
	}
	printf("Resending...\n");
	sleep(1.5);
	for (i=1;i<=windowsize;i++) {
		sleep(1);
		printf("frame %d sent \t frame %d received \n",i,i);
	}
}

int main() {
	int windowsize,frame;
	printf("enter windowsize :  ");
	scanf("%d",&windowsize);
	
	printf("enter frame to be lost : ");
	scanf("%d",&frame);
	
	stopnwait(frame,windowsize);
	
	return 0;
}
