

/*  In this Project will contain Clinc Mangment system ...etc  */

#include<stdio.h> 
#include <stdlib.h>
#include"Prototype.h"
//#include"patient_record.h"



void main () 
{
	/* Variable Declerations  */
	char mode_type = '0'; 
	int Admin_Password = 0 ;
	int flag = 0 ; 
	char ESC = '0';
	
	LinkedList();

do{
	system("cls");
	printf("\n----------------------------------------------------------------------------"); 
	printf(" \n \t \t Welcome To Groat Clinic Mangment System \n"); 
	printf("\t \t    For Sychopath and Mental Heath  \n"); 
	printf("\t \t \t    By M. Alnomrosi \n"); 
	
	 
	printf("---------------------------------------------------------------------------- \n"); 
	printf(" \t \t\tYour Are in Home Screen \n \n");
	
/*Ask User To enter His/Her Mode Type */
	printf("Are You Admin Or User ? \n"); 
	printf("Enter A or U \n -->"); 
	scanf(" %c", &mode_type); 

/* IF statment to choose between Admin and user */

	if(mode_type == 'A' )	
	{
		Admin_Password = 0 ; 
		flag = 0 ;  
/* Ask user to enter the admin password if enter three time wrong will exist the loop */
		printf("Your are in Admin mode Please Enter the Password: \n -->" );
		scanf("%d", &Admin_Password);
		while(flag != 3 )
		{
			/* if the password is right then send to admin screen */
			if(Admin_Password == 1234)  /*Default Password is 1234 */
			{
				Admin() ; 
				flag = 3 ; 
			}
			/* if the password is wrong then increment flag by 1 add ask to enter pssword agin */
			else if (Admin_Password != 1234 )
			{
				flag ++ ; 
				printf("You Entered a Wrong password Please Try agin \n -->");
				scanf("%d", &Admin_Password);
			}
		
		}

	}
	/* Ask user to enter the admin password */
	else if(mode_type == 'U' )	
	{
		User();
		
	} 
	printf(" \t \t\tYour Are in Home Screen \n");
	printf("---------------------------------------------------------------------------- \n \n"); 

	printf("Do you want to exit the Program Enter Y/N \n\n -->");
	scanf(" %c", &ESC);
	
}while( (ESC != 'Y') );

}