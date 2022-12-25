#include <stdlib.h>
#include<string.h>

 /* Add Node type Struct Patient_Recored */ 
typedef struct Patient_Recored 
{ 
	int ID ; 
	char gender ; 
	int age ;
	int slot ; 		
	char *Name;
	char Name_val[100] ; 
	struct Patient_Recored *Next ;

}Patient_Recored;


 /* Add list type Struct list */ 
typedef struct list
{
	Patient_Recored *Head ;
	int size ;
}list ;

 /* to create empty list for first time */
void creat_LinkedList(list *L)
{
	L->Head = NULL ; 
	L->size = 0;
}




/* Add new Patient_Recored  At beginning of the list */ 
void Add_New(list*L, int ID_new, char gender_new, int age_new ,char *Name_new)
{
	Patient_Recored *New_DATA = (Patient_Recored*)malloc(sizeof(Patient_Recored)); 

	
	New_DATA -> ID 		= ID_new ; 			// Put new ID in new node 
	New_DATA -> gender 	= gender_new ; 		// Put new gender in new node 
	New_DATA -> age 	= age_new ; 		// Put new age in new node
	New_DATA -> slot 	= 0 ; 				// Put initial value of reservation 0 
	//New_DATA -> Name	= Name_new; 		//
	
	New_DATA->Name = malloc(strlen(Name_new)+1);	// 
	strcpy(New_DATA->Name,Name_new);
	
	New_DATA ->Next = L -> Head ;
	L -> Head = New_DATA ; 
	L-> size ++ ; 

}
int check_ID(list *L,int ID)
{
	
	Patient_Recored *curr ;	 // Creat new pointer point to node 
	curr =L->Head ; 		// make first pointer point to the head 
	while( curr != NULL)
	{
		if(curr->ID == ID)
		{
			printf("This ID is used for another Patient \n");
			return 1 ;
		}

	curr = curr-> Next ;
	}
}


/*
	Print all Patients Data 
*/
void Print_ALL(list *L)
{
	 
	

	if(L->Head == NULL)
	{
		printf("There is no patients Yet in the list You can add one in Admin Mode mnue \n ");
	}
	else 
	{
		int counter = 1 ;		  // count the patient number in list 
		Patient_Recored *curr ;  // Creat new pointer point to node 
		curr =L->Head ; 		// make first pointer point to the head 
		while( curr != NULL)
		{
			printf("Patient Recored for patient (%d) \n", counter);
			printf("patient ID:	 %d \n", curr->ID);
			printf("patient Name:	 %s \n", curr->Name);
			printf("patient Age:	 %d \n", curr->age);
			printf("patient Gender:	 %c \n \n", curr->gender);
			if(curr->slot == 0)
			{
				printf("This Patient doesnot have any reservation slots \n");
			}
			else
			{
			printf("This Patient is has a reservation at slot number %d \n", curr->slot);
			}
			printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= \n \n ");
			curr = curr-> Next ;
			counter ++ ; 			
		}
			
	}
	
}

/*
Function to edit an exsisting patient recored from ID 
*/
void Edit_Record(list *L, int Edit_ID) 
{
	/* Varible decleration */
	int Admin_choice ; 
	char new_name[100] ; 
	int new_age = 0 ; 
	char new_gender = 0 ;
	
	Patient_Recored *curr ;  // Creat new pointer point to node 
	curr =L->Head ; 		// make first pointer point to the head 

	while(curr != NULL)
	{
		if (curr->ID == Edit_ID)
		{
			printf("What Do you want to edit in Patient ID Number %d \n \n", Edit_ID);
			printf("IF you want to Edit: \n");
			printf("Name		 	Press '1' \n");
			printf("Age 	 		Press '2' \n");
			printf("Gender  		Press '3' \n");
			printf("If you want to exsit 	press '4' \n -->");
			scanf(" %d", &Admin_choice); 
		
			/*
			If condition to chose what to edit
			*/	
			/* If admin choice 1 then chagne name  */
			if (Admin_choice == 1)
			{
			printf("Enter the New Name \n ->");
			scanf(" %s", &new_name);
			 //curr->Name = new_name ;
				curr->Name =  malloc(strlen(new_name+1));	//allocate new memory for new name 
				strcpy(curr->Name,new_name) ;				// copy the new name to new address 
			
			printf("\n Patient Recored Edited successfully.... :) \n \n");
			
			printf("\nDo you still want to edit\n");
			printf("IF you want to Edit: \n");
			printf("Age 	 		Press '2' \n");
			printf("Gender  		Press '3' \n");
			printf("If you want to exsit 	press '4' \n -->");
			scanf(" %d", &Admin_choice); 		
			
			}
			
			/* If admin choice 2 then chagne age  */
			if (Admin_choice == 2)
			{
			printf("Enter the New Age \n ->");
			scanf(" %d", &new_age);
			curr->age = new_age ; 
			
			printf("\n Patient Recored Edited successfully.... :) \n \n");
			
			printf("\nDo you still want to edit\n");
			printf("IF you want to Edit: \n");
			printf("Gender:  		Press '3' \n");
			printf("If you want to exsit 	press '4' \n -->");
			scanf(" %d", &Admin_choice); 	
			}
			/* If admin choice 3 then chagne gender  */
			if (Admin_choice == 3)
			{
			printf("Enter the new Gender \n ->");
			scanf(" %c", &new_gender);
			curr->gender = new_gender ;
			
			printf("\n Patient Recored Edited successfully.... :) \n \n");
			break; 
			}
			
			if (Admin_choice == 4)
			{
				
				break; 
			}
		}	
		curr = curr-> Next ;
	}
	
	/* 
	If the ID is not exsits will display incorrect ID message
	*/
	if (curr == NULL)
	{
	printf("incorrect ID, This ID is not exisit\n \n ");	
	}
	
}

/* 

Shows all avilable slots 	RESERVE / DELETE

*/
void Avilable_Slot(list *L,int flag,int *All_slot)
{
int Patient_ID; // the desired ID to delete or reserve 
int Slot_No ;	// the desire Slot to delete or reserve 
 
/* Slot[0] Mean its avilable while Slot[1] is not avilable */
/* 				Show the  available slots 				  */
if (All_slot[0] == 0)
{
	printf("-Slot 1 is available fom 2:00 PM - 2:30 PM \n\n");
}
if (All_slot[1] == 0)
{
	printf("-Slot 2 is available fom 2:30 PM - 3:00 PM \n\n");
}
if (All_slot[2] == 0)
{
	printf("-Slot 3 is available fom 3:00 PM - 3:30 PM \n\n");
}
if (All_slot[3] == 0)
{
	printf("-Slot 4 is available fom 4:30 PM - 4:30 PM \n\n");
}
if (All_slot[4] == 0)
{
	printf("-Slot 5 is available fom 4:30 PM - 5:00 PM \n\n");
}

/*
If flag = 3 then mean reserve a slot 
*/
if(flag == 3)
{
	/* Declear Patient ID and reservation slot  */

	/* Ask user to Enter The patient ID and Slot */
	printf("What Slot do you want to reserve and for which Patient ID ? \n");
	printf("--> Enter The Patient ID: ");
	scanf("%d", &Patient_ID); 

	printf("--> Enter The Desired Slot to reserve: ");
	scanf("%d", &Slot_No); 
	/* Make the desired slot == 1 to delete from list */
	All_slot[Slot_No-1] = 1 ;
	
	/* 
	Save the slot number in the node 
	*/
	Patient_Recored *curr ; 
	curr = L->Head ; 
	while (curr != NULL) 
	{
		if(curr-> ID == Patient_ID)
		{
			curr->slot = Slot_No ; 
		}
		
		curr = curr->Next ;
		
	}
	
	printf("Slot Has been successfully reserved.... :) \n\n");
}
if(flag == 4)
{

	/*Ask user to enter the desired Patient ID to delete its reservation */	
	printf("Delete A slot for which patient ? \n");
	printf("Enter patient ID: \n -->");
	scanf("%d", &Patient_ID);

	/* 
	Find the ID and its reservation slot  
	*/
	Patient_Recored *curr ; 
	curr = L->Head ; 
	while (curr != NULL) 
	{
		if(curr-> ID == Patient_ID)
		{
		 Slot_No = curr->slot ;
		 curr->slot = 0 ;
		}
		
		curr = curr->Next ;
		
	}
	/* Put the deleted slot with zero to shown agin int the list  */
	All_slot[Slot_No-1] = 0 ; 
	
	
}
	
}
/*
 For user mode check if the ID is exsit and print its data
 */ 
void User_Check(list *L ,int User_ID)
{
	
	Patient_Recored *curr ; 
	curr = L->Head ; 
 
	while (curr != NULL) 
	{
		if(curr-> ID == User_ID)
		{
			printf("Patient Recored for patient ID number: %d \n", User_ID);
			printf("patient ID is :%d \n", curr->ID);
			printf("patient Name is: %s \n", curr->Name);
			printf("patient Age is: %d \n", curr->age);
			printf("patient Gender is: %c \n \n", curr->gender);
			if(curr->slot == 0)
			{
			printf("This Patient doesnot have any reservation slots \n \n");
			break ;
			}
			else
			{
			printf("This Patient is has a reservation at slot number %d \n \n", curr->slot);
			break ; 
			}
		}
		
		curr = curr->Next ;
		
	}
	
	if (curr == NULL)
	{
		printf("The enterd ID is not exsits \n \n"); 
	}


}

/* Display All slots with ID attached to it  */
void Display_reserved(list *L)
{
	printf("The Daily Solts are: \n" );
	printf("-Slot 1 is from 2:00 PM - 2:30 PM \n");
	printf("-Slot 2 is from 2:30 PM - 3:00 PM \n");
	printf("-Slot 3 is from 3:00 PM - 3:30 PM \n");
	printf("-Slot 4 is from 4:30 PM - 4:30 PM \n"); 
	printf("-Slot 5 is from 4:30 PM - 5:00 PM \n \n");
	
	printf("Reserved Slots are: \n" );
	if(L->Head == NULL)
	{
		printf("There is no reservations today \n ");
	}
	else 
	{
		int counter = 1 ;		  // count the patient number in list 
		Patient_Recored *curr ;  // Creat new pointer point to node 
		curr =L->Head ; 		// make first pointer point to the head 
		while( curr != NULL)
		{
			

			if(curr->slot != 0)
			{
			printf("Slot number %d is reserved for patient ID Number %d \n", curr->slot, curr->ID);
			}
			
			curr = curr-> Next ;
			counter ++ ; 			
		}
			
	}
		
	
printf("\n");
 
	
}	
	





