/*Program to convert a maximum 9 digit positive number to its words equivalent using stack data structure
*Author: Mrunal Sawant
*/

#include<stdio.h>
#include<string.h>

struct stack{
	char *data[10];	//to store the string
	int rem[10];	//to store the remainders
	int data_top;
};

void into_words();	
void push_str(char *c);

typedef struct stack STACK;

STACK s;

int count=0;
int num;

int main(){
	
	s.data_top=-1;

	int temp,remain;
	do{
		printf("Please Enter A Number (Max. 9 digits) : ");
		scanf("%d",&num);
		if (num <= 0 || num >=1000000000){
			printf("Please enter a valid number\n");
		}	
	}while(num <= 0 || num >=1000000000);
	

	temp=num;

	while(temp!=0){
		remain=temp%10;
		temp=temp/10;
		s.rem[count++]=remain; //storing remainders in the remainder array in the structure
		
	}
	into_words();//calling a function to convert number to its equivalent words
}

void into_words(){
	char units[10][7]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
	char tens[11][8]={"","Ten","Twenty","Thirty","Fourty","Fifty","Sixty","Seventy","Eighty","Ninety"};
	char ten_twenty[10][10]={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};

	char num_str[50];
	int i;
	for(i=0;i<count;i++){
		switch(i){
			case 0: strcpy(num_str,units[s.rem[i]]);
					break;

			case 2: if(s.rem[2]!=0){
					strcpy(num_str,units[s.rem[2]]);
					strcat(num_str," Hundred");
					}
					else{
						s.data_top--;
					}
					break;

			case 3:
			case 5:
			case 7: strcpy(num_str,units[s.rem[i]]);
					
					break;
			case 1:
			case 4:
			case 6:
			case 8: 
					s.data_top--;
					
					if(s.rem[i]!=1){
						
						strcpy(num_str,tens[s.rem[i]]);
						strcat(num_str," ");
						strcat(num_str,units[s.rem[i-1]]);
			
					}else{
						
						strcpy(num_str,ten_twenty[s.rem[i-1]]);
						
					}
					break;
			}//end of switch
			/*following coditions will check which char string is to be concatenate with num_str */ 
				if(i==3 || i==4){
						strcat(num_str," Thousand");
					}else if(i==5 || i==6){
						strcat(num_str," Lakh");
					}else if(i==7 || i==8){
						strcat(num_str," Crore");
					}
				
				push_str(num_str);//function to put string in d stack
		}
		printf("\n\nNUMBER -> %d \nNumber in Words Equivalent -> ",num);

		for(i=s.data_top;i>=0;i--){
		printf("%s ",s.data[i]);
	}
	printf("\n\n");
}

void push_str(char *c){
	if(c!=NULL){
		s.data_top++;
		s.data[s.data_top]=strdup(c);
	}
}
