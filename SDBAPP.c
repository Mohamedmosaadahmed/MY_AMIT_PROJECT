/* Name : Mohamed Mosaad Ahmed
PROGRAM : Amit Project
*/
#include <stdio.h>
#include "STD.h"
#include "SDB.h"
void SDB_APP();
void SDB_action(uint8 choice);
int main() {
    uint8 userChoice;
    SDB_APP();
    scanf("%d",&userChoice);//this is the numb of the operation
    SDB_action(userChoice);
    return 0;
}
//lets test it with the right id
void SDB_APP()
{
printf("\n choose the action\n1. Add entry\n2.get used size in DB\n3.to read student data\n4.to get the list of IDs\n5.check if ID is existed\n6.delete student data\n7.check if DB is full\n0.exit\n");
}
void SDB_action(uint8 choice) {
  uint32 e,h;
  uint8 count;
  uint32 list[MAX_STUDENTS];
    switch(choice)// switching between operation
    {
        case 1:
            SDB_AddEntry();
            printf("\n enter id\n");
            scanf("%d",&e);
            SDB_ReadEntry(e);
             SDB_IsIdExist(e);
            //just for testing in order to save the given data and print it and iam going to test an extra func here
            break;
        case 2:
            h=SDB_GetUsedSize();
            printf("\nsize is %d\n",h);
            break;
        case 3:
            printf("\n enter id\n");
            scanf("%d",&e);
            SDB_ReadEntry(e);
            break;
	case 4:
		SDB_GetList(count,list);
		break;
    case 5:
        printf("\n enter id\n");
            scanf("%d",&e);
            SDB_IsIdExist(e);//lets test this one
        break;
	case 6:
	     printf("\n enter id\n");
            scanf("%d",&e);
		SDB_DeleteEntry(e);
		break;
	case 7:
		SDB_IsFull();
		break;
	case 0:
		printf("\nexiting");
		break;

        default:
            printf("Invalid choice\n");
            break;
    }
}
//now we are going to run the program and test it
