#include <stdio.h>
#include "STD_Types.h"
#include "project.h"
#include <string.h>


	extern u32 admin_desire ; 
	extern u32 user_desire ;
	extern u32 desired_slot_index;
	extern u8 i ; 
	extern u8 n ;         
	extern u8 pos ;
	extern u32 mode ; 
	extern u32 pass ;
	extern u32 id ; 
	extern patient record [10] ;   
	extern u8 size ; 
	extern u8 slots [][11];



void Main_Menu(void) {
	
	printf("\n **********  Welcome ********** \n\n ");
	printf("Please choose your Mode : \n ");
	printf("For Admin mode press : 1  \n ");
	printf(" For User mode press : 2  \n ");
	printf("your Mode :  ");
	scanf("%d",&mode);
	
	
}


void Check_Pass(void ){
	
		switch (pass){
		
			case 1234 :
			printf("\n\n**************** Main_Menu **************** \n\n");			
			printf("To Add new patient record , press : 1 \n");
			printf("To Edit patient record , press : 2 \n");
			printf("To Reserve a slot with the doctor , press : 3 \n");
			printf("To Cancel reservation , press : 4 \n");
			printf("__________________________________________________ ");
			printf("\n your chooice :  ");
			scanf("%d",&admin_desire) ;
			break ;
		
		
		default :
		for(i=1;i<3;i++){
			printf("\n Wrong password , try again : \n");
			scanf ("%d",&pass);
			
			if (pass==1234){
			printf("**************** Main_Menu **************** \n\n");		
			printf("To Add new patient record , press : 1 \n");
			printf("To Edit patient record , press : 2 \n");
			printf("To Reserve a slot with the doctor , press : 3 \n");
			printf("To Cancel reservation , press : 4 \n");
			printf("__________________________________________________ ");
			printf("\n your chooice :  ");
			scanf("%d",&admin_desire) ;
			break ;
			}
			
			if (i==2){
			printf("\n Sorry , No more tries  \n");
			}
			
		}
	}
		
	}
	

void Add_Record(void){
	
		printf("\n Please Enter your ID  : ");      
		scanf("%d",&id);
			

			for(i=0;i<n;i++) {                   //  check ID existance
			if(record[i].ID == id) {
				printf("sorry , this ID is already reserved .") ; 
			break; 
			}
			else {
				record[n].ID = id ;       // save id in struct 
			}
		  } 

			// Fill new record info 
			
			printf("\n Please Enter your name : ");
			scanf("%s",record[n].name);
			
			printf("\n Please Enter your gender : ");
			scanf("%s", record[n].gender);
			
			printf("\n Please Enter your age : ");
			scanf("%d",&record[n].age);
			
			   strcpy(record[n].slot[0], "empty");     // initialize empty reserved slot 
			   
			 printf("\n New Record is added successfully . \n");  

			n++ ;       // increase number of records 
	
}



void Edit_Record(void){
	
	printf("Please Enter your ID : ");
			scanf("%d",&id);
			
				for(i=0;i<n;i++) {                // check valid ID 
			
			if(record[i].ID == id) {               // Edit record info 
				
			printf("\n Please Enter your edited name : ");
			scanf("%s", record[i].name);
			
			printf("\n Please Enter your edited gender : ");
			scanf("%s", record[i].gender);
			
			printf("\n Please Enter your edited age : ");
			scanf("%d",&record[i].age);
			
			break; 
			}
			else {
			printf("\n Sorry , Incorrect ID ");
			}
		  } 
	
	printf("\n Record is Edited Successfully .  ");
	
}



void Reserve_Slot(void){
	u8 j;
			printf("\n Please Enter your ID : ");
			scanf("%d",&id);
			
			for(i=0;i<n;i++) {
				
				if(record[i].ID == id) {
				
					for (j=0;j<size;j++){                  // Display Available slots 
					printf("\n Avialable Slots : \n ");
					printf("Slot %d : %s \n ",j,slots[j]);
					}
					
					printf("\n Choose your desired slot index  : \n ");
					scanf ("%d",&desired_slot_index) ; 	
				
				    printf("\n desired_slot_index  : %d\n ",desired_slot_index);
				
					
			       strcpy(record[i].slot[0],slots[desired_slot_index]);
					
					record[i].slot_num = desired_slot_index ; 
					
					if(desired_slot_index < 0 || desired_slot_index > size){
						
							printf("Invalid slot ! Please enter position between 1 to %d", size);
						}
					else	{				
					
					for(i=desired_slot_index; i<(size-1); i++){
						for(j=0;j<11;j++){
						slots[i][j] = slots[(i+1)][j];
						}
					}
					
					 printf("\n Slot is reserved successfully . \n");  
						size--;
					}
					break ; 
					
				}
				
				else {
					printf("Sorry , Invalid ID ");
				}
			}
			
}



void Cancel_Reservation(void){
	u8 j ;
	
	printf("Please Enter your ID : ");  //check valid id 
			scanf("%d",&id);
			
			for(i=0;i<n;i++) {
				
				if(record[i].ID == id) {
				                              // work on array to insert element 
					for(j=size; j>=(record[j].slot_num); j--) {
							slots[j][11] = slots[j-1][11];
						}
						// Insert new element at given position and increment size 
						
						slots[pos-1][11]=record[i].slot[0][11];
						
						size++;
		
				  strcpy(record[i].slot[0], "empty");  // empty reserved slot after cancelling 
				  
				   printf("\n Reservation is cancelled successfully . \n");  

				break ;
				}
				
				else {
					printf("Sorry , Invalid ID ");
				}
			}
			
			
		
			
		
	
}
