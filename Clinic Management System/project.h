#ifndef _PROJECT_H
#define _PROJECT_H


void Main_Menu(void);
void Check_Pass(void);
void Add_Record(void);
void Edit_Record(void);
void Reserve_Slot(void);
void Cancel_Reservation(void);

// create a structure carries patient's information  



typedef struct {
	
	u8 name[10] ;                         // carries string 
	u8 gender[10] ;                      // carries string 
	u32 slot_num ;                      // carries reserved slot number 
	u32 age ;                          // carries number 
	u32 ID ;                          // carries number (uniqe for every record)
	u8 slot[1][11] ;                 // carries string  (5 available slots)

	
}patient ;	


	


#endif