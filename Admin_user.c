
#include<stdio.h> 
#include <stdlib.h>
#include"patient_record.h"




/* List decleration as global */ 
	list L ;

	/* Patient DATA  */ 
	int ID = 0; 
	char gender = 'M' ; 
	int age = 0 ;
	char Name[100] ;
	/* Variable Declerations  */
	
	char Esc = '0' ; 		// Char
	int Admin_choice ; 	// int
	int flag = 0 ;		// for check ID 
	int Edit_ID = 0 ; 	// ID want to edit 
	int All_slot[5] = {0,0,0,0,0} ;
	
	

void LinkedList()
{
	/* Create Lis for first time  */
	creat_LinkedList(&L);
}
	
/*  Admin Mode */
void Admin () 
{	
	/* Remove screen */ 
	system("cls");
	
	printf("\n --------------------------------------"); 
	printf("\n \t Welcome To Admin Mode \n"); 
	printf("-------------------------------------- \n \n"); 
	




/* do-While loop to allow admin to enter data Unit He/Her Finished */ 

do
{
/* Ask Admin what he/her want to do */
	printf("What I can do for you ? \n  \n");
	printf("1) Add New Patient 			Press' 1 '\n");
	printf("2) Edit an exisiting patient 		Press' 2 '\n");
	printf("3) Reserve a slot for patient  		Press' 3 '\n");
	printf("4) Delete existing patient slot		Press' 4 '\n");
	printf("5) Want to exist to home screen		Press' 5 '\n ->");
	scanf("%d", &Admin_choice); 
	
	/*
		If Admin choice is 1 then Add new 
	*/
	if(Admin_choice == 1) 
	{
		
		/* Add new Patient Data (NEW NODE)*/
		system("cls");
		printf("You will enter new Patient recored: \n \n");
		
		/*
			Loop to check if the ID is used before or not 
		*/ 
		do{
		flag = 0 ;
		printf("-> Please Enter Your New Patient ID: ");
		scanf("%d", &ID); 
		flag = check_ID(&L,ID); 
		
		}while(flag != 0);
		
		printf("-> Please Enter Your New Patient Name: ");
		scanf(" %s", &Name); 		

		printf("-> Please Enter Your New Patient Gender M/F: ");
		scanf(" %c", &gender);

 		printf("-> Please Enter Your New Patient Age: ");
		scanf("%d", &age); 
		
		Add_New(&L,ID, gender,age , Name ) ;
		
		printf(" \n-Patient Record added succssfuly ... :) \n\n");

	}
	/*
		If Admin choice is 2 then Edit exsiting patient recored 
	*/	
	else if(Admin_choice == 2) 
	{
		/* Edit An exsisting Patient */
		/* First Print all patients data */
		system("cls");
		printf("\t All Patients Data  \n ");
		printf("-----------------------------\n");
		Print_ALL(&L); 
		
		/* ask user to enter which ID to edit */
		printf("--> Which Patient ID you want to edit: ");
		scanf(" %d", &Edit_ID);
		
		Edit_Record(&L,Edit_ID); 
			
		
	}
	/*
		If Admin choice is 3 then Reserve a slot with doctor  
	*/
	else if(Admin_choice == 3) 
	{
		/*  Reserve a slot with the doctor  */
		
		system("cls");
		
		printf("\t All Patients Data  \n");
		printf("-----------------------------\n");
		Print_ALL(&L);	
		printf("-----------------------------\n ");
		printf("\t Reservation List \n ");
		printf("-----------------------------\n");
		flag = 3 ; 
		Avilable_Slot(&L, flag, All_slot); 
		
		
		
	}
	/*
		If Admin choice is 4 then delete the current slot with doctor  
	*/
	else if(Admin_choice == 4) 
	{
		/*  Delete a slot with the doctor  */
		
		system("cls");
		
		printf("\t All Patients Data  \n ");
		printf("-----------------------------\n ");
		Print_ALL(&L);	
		printf("-----------------------------\n ");
		printf("\t Reservation List \n ");
		printf("-----------------------------\n ");
		flag = 4 ; 
		Avilable_Slot(&L, flag, All_slot); 
		
		
		system("cls");
	}
	else if (Admin_choice == 5)
	{
		break;
	}

	

/*Ask user if want to exist the program or not */
	printf("Do you want to return to 'Home Screen' Y/N \n");
	printf("-Press 'Y' to Exit Admin Mode Y/N \n");
	printf("-Press 'N' to Stay in Admin Mode Y/N \n\n -->");
	
	scanf(" %c", &Esc); 
	
	system("cls");
	printf("\n --------------------------------------"); 
	printf("\n \t Welcome To Admin Mode \n"); 
	printf("-------------------------------------- \n \n"); 
	
	
}while(Esc != 'Y' );

system("cls");
	
	
	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void User()
{
	/* Variable Declerations  */ 
	int User_ID ;
	int User_Choice ; 
	
do{
	printf("\n --------------------------------------"); 
	printf("\n \t Welcome To User Mode \n"); 
	printf("-------------------------------------- \n \n"); 

	printf("-You can see your record or see the avilable slots \n" );
	
	printf("1) To show your record press   '1' : \n" );
	printf("1) To View Today's Slots press '2' : \n -->" );
	scanf("%d", &User_Choice);
	
	/*
	Ask his ID and print his/her  record
	*/
	if (User_Choice == 1) 
	{
	printf("--> Enter Your ID: \n" );
	scanf("%d", &User_ID);
	User_Check(&L,User_ID);
	}
	
	/*
	Display All slots
	*/
	if (User_Choice == 2) 
	{
	
	Display_reserved(&L);
	}
	
 /*Ask user if want to exist the to home screen or not */
	printf("Do you want to return to 'Home Screen' Y/N \n");
	printf("-Press 'Y' to Exit User Mode \n");
	printf("-Press 'N' to Stay in User Mode \n\n -->");
	scanf(" %c", &Esc); 
	
	system("cls");
	
}while(Esc != 'Y' );
 
 
}


