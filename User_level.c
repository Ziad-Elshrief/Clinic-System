#include<stdio.h>
#include<stdlib.h>
#include"std_types.h"
#include"patient_list.h"
#define USER 1
#define ADMIN 0
void main(void){
	u32 option;
	u32 pass;
	patient * Start=NULL;
	reservation slot[5]={"2pm to 2:30pm",0 , "2:30pm to 3pm",0 , "3pm to 3:30pm",0 , "4pm to 4:30pm",0 ,"4:30pm to 5pm",0 };
	for(;;){
	u8 tries=0;
	printf("\nWelcome to Clinic Management System \n");
	printf("Please Enter 0 for admin mode \n1 for patient mode \nDesired mode: ");
	scanf("%d",&option);
	switch(option){
		case ADMIN:
		printf ("Please enter your password: ");
			scanf("%d" , &pass );
		while((tries<2)&&pass!=1234){
			printf("Try again: ");
			scanf("%d" , &pass );
			tries++;
		}
		if((tries==2)&&(pass!=1234)){
			printf("You're out of tries");
			break;
		}
		else{
			printf("Welcome Admin \n");
			printf("1: Add new patient record \n");
			printf("2: Edit patient record \n");
			printf("3: Reserve a slot with the doctor \n");
			printf("4: Cancel reservation \n");
			printf("Please choose your action: ");
			scanf("%d",&option);
			switch(option){
				case 1:
				Start=AddNewPatient(Start);
				break;
				case 2:
				EditPatient(Start);
				break;
				case 3:
				ReserveSlot(&slot[0]);
				break;
				case 4:
				CancelReserve(&slot[0]);
			}
		}
		break;
		
		case USER:
		printf("Welcome\n");
			printf("1: View patient record \n");
			printf("2: View today's reservations \n");
			printf("Please choose your action: ");
			scanf("%d",&option);
		switch(option){
		case 1:
		ViewPatient(Start);
		break;
		case 2:
		ViewReserve(&slot[0]);	
	}
	}
	}	
}