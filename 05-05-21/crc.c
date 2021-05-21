#include <stdio.h>
#include <string.h>
int main() 
{
    	int i,j,keylen,msglen,reclen,flag=0;
    	char input[100],output[100],key[30],temp[30],quot[100],rem[30],key1[30],key2[30],temp1[30],quot1[100],rem1[30];
    	
    	printf("Enter Data Block(sender's side): ");
    	scanf("%s",input);
    	printf("Enter co-efficients of Polynomial: ");
    	scanf("%s",key);
    	printf("Enter Data Block(receiver's side): ");
    	scanf("%s",output);
    	reclen=strlen(output);
    	keylen=strlen(key);
    	msglen=strlen(input);
    	strcpy(key1,key);
    	for (i=0;i<keylen-1;i++) {
    		input[msglen+i]='0';
    	}

    	for (i=0;i<keylen;i++)
    	 temp[i]=input[i];

    	for (i=0;i<msglen;i++) 
	{
    		quot[i]=temp[0];
    		if(quot[i]=='0')
    			for (j=0;j<keylen;j++)
  	  			 key[j]='0'; 
		else
	    		 for (j=0;j<keylen;j++)
		    		 key[j]=key1[j];

    		for (j=keylen-1;j>0;j--) 
		{
    			if(temp[j]==key[j])
	   			 rem[j-1]='0'; 
			else
	    			 rem[j-1]='1';
    		}
    		rem[keylen-1]=input[i+keylen];
    		strcpy(temp,rem);
    	}
    	strcpy(rem,temp);
    	
    	printf("\nCRC is ");
    	for (i=0;i<keylen-1;i++)
	    	 printf("%c",rem[i]);
    	
    	 printf("\n");
    	 strcpy(key2,rem);
    	for (i=0;i<keylen-1;i++) {
    		output[reclen+i]=key2[i];
    	}
    	printf("Code word sent :\n");
    	for(i=0;i<reclen+keylen-1;i++)
	    	printf("%c",output[i]);
    	for (i=0;i<keylen;i++)
	    	 temp1[i]=output[i];
    	for (i=0;i<reclen;i++) 
	{
    		quot1[i]=temp1[0];
    		if(quot1[i]=='0')
    		 for (j=0;j<keylen;j++)
    		 key[j]='0'; else
    		 for (j=0;j<keylen;j++)
    		 key[j]=key1[j];
    		for (j=keylen-1;j>0;j--) 
		{
    			if(temp1[j]==key[j])
	    			 rem1[j-1]='0'; 
			else
	    			 rem1[j-1]='1';
    		}
    		rem1[keylen-1]=output[i+keylen];
    		strcpy(temp1,rem1);
    	}
    	
    	strcpy(rem1,temp1);
    	
    	
    	for(i=0;i<keylen-1;i++){
	    	if(rem1[i]!='0')
		{
	    		printf("\nData at the receiver's side has error\n");
    			flag=1;
  		}
    		}
	    	if(flag==0){
		    	printf("\nData at the receiver's side is  error free\n");
    	
    	}
    	
    	return 0;
}
