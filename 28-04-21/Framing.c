//Design a C program in which sender module should count the size of frame and receiver module should display each frame receievd
#include<stdio.h>
#include<string.h>
int main()
{
	int n,i;
	printf("Enter the no. of frames\n");
	scanf("%d",&n);
	char str[n][20];
	printf("Enter %d frames\n",n);

	for(i=0;i<n;i++){
		scanf("%s[^\n]",str[i]);
	}
	printf("fram size:\n");
	for(i=0;i<n;i++)
		printf("length of frame %d = %ld\n",i+1,strlen(str[i]));
	
	printf("\nEntered frames are\n");
	for(i=0;i<n;i++)
		printf("%s",str[i]);
	
	return 0;
}
	
