#include <stdio.h>
#include "SDB.h"
#include "STD.h"
student database[MAX_STUDENTS];
uint8 usedSize = 0;

bool SDB_IsFull()
{
    if (usedSize == MAX_STUDENTS)//checks if the array is full or not
        return true;
    else
        return false;
}

uint8 SDB_GetUsedSize()
{
    return usedSize;// here usedSize is a global var & in functions we increment it or decrement after every entry or delete
}

bool SDB_AddEntry()
{
    if (usedSize == MAX_STUDENTS)
        return false;

    student newStudent;// here we take the data from user & save it
    printf("\nEnter Student ID: ");
    scanf("%d", &newStudent.Student_ID);
    printf("\nEnter Student Year: ");
    scanf("%d", &newStudent.Student_year);
    printf("\nEnter Course 1 ID: ");
    scanf("%d", &newStudent.Course1_ID);
    printf("\nEnter Course 1 Grade: ");
    scanf("%d", &newStudent.Course1_grade);
    printf("\nEnter Course 2 ID: ");
    scanf("%d", &newStudent.Course2_ID);
    printf("\nEnter Course 2 Grade: ");
    scanf("%d", &newStudent.Course2_grade);
    printf("\nEnter Course 3 ID: ");
    scanf("%d", &newStudent.Course3_ID);
    printf("\nEnter Course 3 Grade: ");
    scanf("%d", &newStudent.Course3_grade);

    database[usedSize] = newStudent;
    usedSize++;// this is the increment of global var

    return true;
}

void SDB_DeleteEntry(uint32 id)
{
    for (uint8 i = 0; i < usedSize; i++)
    {
        if (database[i].Student_ID == id)//here we search for the id taken from user & compare it to the ids in the array
        {
            for (uint8 j = i; j < usedSize - 1; j++)
                database[j] = database[j + 1];
            usedSize--;
            printf("Student with ID %u deleted from the database.\n", id);//if id exists we delete it by incrementing the iterator & overwrite on the old one
            return;
        }
    }

    printf("ID %d is not found in the database.\n", id);
}

bool SDB_ReadEntry(uint32 id)
{
    for (uint8 i = 0; i < usedSize; i++)
    {
        if (database[i].Student_ID == id)
        {
            printf("Student ID: %d\n", database[i].Student_ID);
            printf("Student Year: %d\n", database[i].Student_year);
            printf("Course 1 ID: %d\n", database[i].Course1_ID);
            printf("Course 1 Grade: %d\n", database[i].Course1_grade);
            printf("Course 2 ID: %d\n", database[i].Course2_ID);
            printf("Course 2 Grade: %d\n", database[i].Course2_grade);
            printf("Course 3 ID: %d\n", database[i].Course3_ID);
            printf("Course 3 Grade: %d\n", database[i].Course3_grade);

            return true;
        }
    }

    printf("Student with ID %d not found in the database.\n", id);
    return false;
}

void SDB_GetList(uint8*count,uint32 *list)
{
    *count = usedSize;
    for (uint8 i = 0; i < usedSize; i++)
        {list[i] = database[i].Student_ID;
        printf("%d\t",list[i]);}//this loop prints all ids in the array
}
bool SDB_IsIdExist(uint32 id)
{for(int i=0;i<usedSize;i++)
{if(database[i].Student_ID==id)//checking if id exists
{
    printf("\nid exists\n");
    return true;
    break;
}

}
  return false;
}
