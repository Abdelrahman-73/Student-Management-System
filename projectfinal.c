#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "projectFunction.h"
/* Main Function */
int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int n,t=1; // t=1 to make t true always unless the user want to exit , he write 0
	while(t){
		printf("----------------------------------------------\n"
				"' Welcome To Student Management System '\n"
				"1) Add Student\n"
				"2) Display Students\n"
				"3) Search by ID\n"
				"4) Update Student\n"
				"5) Delete Student\n"
				"6) Calculate AVG GPA\n"
				"7) Search for Highest GPA\n"
				"0) EXIT\n"
				"Choose a number: \n");
		scanf("%d",&n);
		/* switch case for the function the user wants */
		switch(n){
		case 1: {
			struct student newStudent;
			addStudent(&newStudent);
			break;
		}
		case 2: {
			displayStudents();
			break;
		}
		case 3:{
			printf("Enter ID to search: ");
			int x;
			scanf("%d",&x);
			searchStudentByID(x);
			break;
		}
		case 4:{
			printf("Enter ID to update: ");
			int x;
			scanf("%d", &x);
			updateStudent(x);
			break;
		}
		case 5:{
			printf("Enter ID to delete: ");
			int x;
			scanf("%d", &x);
			deleteStudent(x);
			break;
		}
		case 6: {
			printf("--------------------------------------------\n");
			printf("The total average is : %.2f\n", calculateAverageGPA());
			break;
		}
		case 7:{
			searchHighestGPA();
			break;
		}
		case 0:{
			printf("--------------------------------------------\n");
			printf("You Exit the Program");
			t = 0;
			break;
		}
		default: printf("Invalid number\n");
		}
	}
	return 0;
}
