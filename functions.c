#include<stdio.h>
#include<stdlib.h>
#include"std_types.h"
#include"patient_list.h"

void ViewPatient(patient * Start){
	if(Start != NULL){
		patient * ptr = Start;
		u32 p_id;
		printf("Please Enter id: ");
		scanf("%d",&p_id);
	while(ptr != NULL ){
		if(ptr->id==p_id){
		printf("Patient's name: %s \n",ptr->name);
		printf("Patient's age: %d \n ",ptr->age);
		printf("Patient's gender: %s \n",ptr->gender);
		break;
		}
		else{
		ptr=ptr->Next;	
		}
	}
	}
	else{
		printf("Empty patient list");
	}
}
	
void ViewReserve(reservation * res_slot){
	u32 counter;
	for(counter=0;counter<5;counter++){
		if(res_slot[counter].id !=0){
		printf("%s reservation : %d \n",res_slot[counter].time ,res_slot[counter].id);
	}
	else{
		printf("%s reservation : Vacant \n",res_slot[counter].time);
	}
	}
}

patient* AddNewPatient( patient * Start){
		patient* temp= (patient*)malloc(sizeof(patient));
		if(temp!=NULL){
			printf("Patient's id: ");
			scanf("%d",&temp->id);
			printf("Patient's name: ");
			scanf("%s",&temp->name);
			printf("Patient's age: ");
			scanf("%d",&temp->age);
			printf("Patient's gender: ");	
			scanf("%s",&temp->gender);
			temp->Next=NULL;
		if(Start==NULL){
			Start=temp;
		}
		else{
			patient * place=Start;
			while(place->Next!= NULL){
				place=place->Next;
			}
			place->Next=temp;
		}
		return Start;
	}
	}
	
void EditPatient(patient * Start){
	u32 p_id;
	printf("Please Enter id: ");
	scanf("%d",&p_id);
	if(Start != NULL){
		patient * ptr = Start;
	while(ptr != NULL ){
		if(ptr->id==p_id){
			printf("Patient's name: ");
			scanf("%s",&ptr->name);
			printf("Patient's age: ");
			scanf("%d",&ptr->age);
			printf("Patient's gender: ");	
			scanf("%s",&ptr->gender);
			break;
		}
		else{
		ptr=ptr->Next;	
		}
	}
	if(ptr==NULL){
		printf("Incorrect ID");
	}
	}	
}

void ReserveSlot(reservation * res_slot){
	u32 counter;
	u32 p_id;
	u32 des_slot;
	printf("Available slots \n");
	for(counter=0;counter<5;counter++){
		if(res_slot[counter].id ==0){
			printf("slot %d : %s reservation : Vacant \n", counter+1 ,res_slot[counter].time);
	}
	}
	printf("Please Enter id: ");
	scanf("%d",&p_id);
	printf("Please Enter desired slot: ");
	scanf("%d",&des_slot);
	res_slot[des_slot-1].id=p_id;
}

void CancelReserve(reservation * res_slot){
	u32 p_id;
	u32 counter;
	printf("Please Enter id: ");
	scanf("%d",&p_id);
	
	for(counter=0;counter<5;counter++){
	if(res_slot[counter].id == p_id){
		res_slot[counter].id=0;
	}
	}
	
}