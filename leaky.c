#include<stdio.h>
#include<stdlib.h>
int main(){
	int bsize,out,n,bucket=0,in;
	printf("enter the bucket size:");
	scanf("%d",&bsize);
	printf("enter the leaky rate:");
	scanf("%d",&out);
	printf("enter the total no of packets:");
	scanf("%d",&n);
	while(n!=0){
		printf("enter the incoming packet:");
		scanf("%d",&in);
		if(in<=bsize-bucket)
		{
			bucket+=in;
			printf("bucket status:%d out of %d\n",bucket,bsize);
		}
		else
		{
			printf("Dropped packets:%d\n",in-(bsize-bucket));
			printf("bucket status:%d out of %d\n",bucket,bsize);
			bucket=bsize;
		}
		bucket=bucket-out;
		printf("After outgoing,bucket status:%d packets out of %d\n",bucket,bsize);
		n--;
	}

	return 0;
}
