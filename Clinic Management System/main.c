#include <stdio.h>
#include "STD_Types.h"
#include <string.h>
#include "project.h"

	u32 admin_desire ; 
	u32 user_desire ;
	u32 desired_slot_index;
	u8 i ; 
	u8 n =0 ;         
	u8 pos ;
	u32 mode ; 
	u32 pass ;
	u32 id ; 
	patient record[11] ;    //  array of structures of type patient 
	u8 size = 5 ; 
	u8 slots [][11]= {"2:2.30 PM","2.30:3 PM","3:3.30 PM","3.30:4 PM","4:4.30 PM"}; 


void main(void){
	
	Main_Menu();

	switch (mode){              //user or admin 
		case 1 :               // user mode 
		printf("\n  Please Enter Password : ") ;
		scanf("%d",&pass);
		Check_Pass();                    //check password 
		
		switch(admin_desire){
			
			case 1 :  // Add new patient record:
			
			Add_Record();
			
			main();
			
			break;

			
			case 2 :  // Edit patient record
			
			Edit_Record();
			
			main();
			
			break;


			case 3 : // Reserve a slot with the doctor
			
			Reserve_Slot() ;
			
			main();
			
			break;

			
			
			case 4 :  //Cancel reservation
			
			Cancel_Reservation();
			
			main();
			
			break;

			
		}
		
		Main_Menu();
		
		case 2 :   // admin mode 
		printf("\n **********  Welcome ********** \n\n ");
		printf(" To View patient record press : 1  \n ");
		printf(" To View today's reservations press : 2  \n ");
		scanf("%d",&user_desire) ;
		
		switch (user_desire) {
			
			case 1 :   //View patient record
			
			printf("Please Enter your ID : ");
			scanf("%d",&id);
			
			for(i=0;i<n;i++) {
				
				if(record[i].ID == id) {
				
				printf("Patient_Name : %s \n ",record[i].name) ;
				printf("Patient_Gender : %s \n ",record[i].gender) ;
				printf("Patient_Age : %d \n ",record[i].age) ;
				printf("Patient_slot : %s \n ",record[i].slot) ;
	
					break ; 
				}
				
				else {
					printf("Sorry , Invalid ID ");
				}
			
			}
			
			main();
			
			break;

			
		
		
		case 2 :    // View today’s reservations
		
		for(i=0;i<n;i++) {
				
				printf("ID number %d : %d \t ",(i+1),record[i].ID) ;
				printf("Reserved_Slot : %s \n ",record[i].slot) ;
		}	
	

			main();
			
			break;

		
		default :
			printf(" Wrong chooise ! \n ");
	
	
	}
	
	}
}