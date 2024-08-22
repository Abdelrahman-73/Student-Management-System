#ifndef PROJECTFUNCTION_H_
#define PROJECTFUNCTION_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct student{
	int id;           // Student ID
	char name[50];    // Student Name
	int age;          // Student Age
	float gpa;        // Student GPA
};
struct node{
	struct student data;
	struct node * next;
};
struct node * head = NULL;


/* Add Student Function */
void addStudent(const struct student * const ptr){
	/* Making New Node */
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	if (newnode == NULL){
		printf("memory allocation failed\n");
		return;
	}

	/* The User Add Student ID */
	printf("Enter ID: ");
	scanf("%d",&newnode->data.id);


	/* Checking if the ID exists or not */
	bool flag = false;
	struct node *current = head;
	while ( current != NULL ){
		if ( current -> data.id == newnode->data.id ){
			flag = true;
			break;
		}
		current = current->next;
	}
	if (flag){
		printf("ERROR: The ID Exists");
		free(newnode);
		return;
	}

	/* If the student ID doesn't exist */
	printf("Enter Student Name: ");
	scanf(" %[^\n]", newnode->data.name);

	printf("Enter age: ");
	scanf("%d",&newnode->data.age);

	printf("enter your gpa: ");
	scanf("%f",&newnode->data.gpa);
	newnode->next = NULL;

	/* Adding Student Process */
	if (head == NULL){
		head = newnode;
	}
	else{
		current = head;
		while(current->next!=NULL){
			current = current->next;
		}
		current->next = newnode;
	}
	printf("---------------------------------------\n");
	printf("The user added successfully\n");
}

/* Display Students Function */
void displayStudents(void){
	struct node *current = head;
	if (head == NULL){
		printf("empty");
		return;
	}
	else{
		printf("---------------------------------------\n");
		while ( current != NULL ){
			printf("Student ID: %d | Student Name: %s | Student Age: %d | Student GPA: %.2f\n",
					current->data.id,current->data.name,current->data.age,current->data.gpa);
			current = current -> next;
		}
	}
	printf("---------------------------------------\n");
}

/* Searching for a Student by ID Function */
void searchStudentByID(int id){
	struct node * current = head;
	/* Checking if the linked list is empty */
	if (head == NULL){
		printf("empty");
		return;
	}
	else{
		while(current!=NULL){
			if ( current->data.id == id ){
				printf("---------------------------------------\n");
				printf("Student ID: %d | Student Name: %s | Student Age: %d | Student GPA: %.2f\n",
						current->data.id,current->data.name,current->data.age,current->data.gpa);

				return;
			}
			current = current->next ;
		}
		/* In Case if the ID does't exist or not found */
		printf("---------------------------------------\n");
		printf("User Not Found\n");

	}
}

/* Update Student Data Function */
void updateStudent(int id){
	struct node * current = head;
	/* Checking if the linked list is empty or not */
	if (current == NULL){
		printf("empty");
		return;
	}
	else{
		while(current!=NULL){
			if ( current->data.id == id ){
				/* In Case if the student is found */
				printf("The Student Found !! Enter the Updated Information : \n");
				printf("Enter Student Name: ");
				scanf(" %[^\n]", current->data.name);

				printf("Enter age: ");
				scanf("%d",&current->data.age);

				printf("enter your gpa: ");
				scanf("%f",&current->data.gpa);

				printf("---------------------------------------\n");
				printf("The Student Updated Successfully \n");

				return;
			}
			current = current->next ;
		}
		/* in case if the student isn't found */
		printf("---------------------------------------\n");
		printf("User Not Found\n");

	}
}
/* Calculate the average GPA of all students function */
float calculateAverageGPA(void){
	/* Checking if the linked list is empty */
	if (head == NULL){
		printf("empty");
		return 0;
	}
	else{
		struct node * current =head;
		float avg = 0; int cnt = 0;
		while(current!=NULL){
			avg+=current->data.gpa;
			cnt++;
			current = current->next ;
		}
		/* if function to see if there is no students or not :
		 * if yes -> return 0 to prevent division by 0 (count is 0 in case there's no students)
		 * if no -> it does the calculation avg/cnt */
		return (cnt == 0) ? 0.0 : (avg/cnt);
	}
}

/* Search the highest GPA student function */
void searchHighestGPA(void){
	/* Check if the linked list is empty */
	if (head == NULL) {
		printf("No students available\n");
		return;
	}
	/* current to moves in the linked list and maxStudent (with initial value equals head) takes the highest value of the current */
	struct node *current = head;
	struct node *maxStudent = head;
	while (current != NULL) {
		if (current->data.gpa > maxStudent->data.gpa) {
			maxStudent = current;
		}
		current = current->next;
	}
	printf("---------------------------------------\n");
	printf("The student with the highest GPA:\n");
	printf("Student ID: %d | Student Name: %s | Student Age: %d | Student GPA: %.2f\n",
			maxStudent->data.id, maxStudent->data.name, maxStudent->data.age, maxStudent->data.gpa);

}

/* Delete Student Function */
void deleteStudent(int id){
	/* Check if the linked list is empty */
	if (head == NULL){
		printf("empty");
		return;
	}
	else{
		struct node *current = head;
		struct node *prev = NULL;
		while (current != NULL) {
			/* Check if the current id is equal to the id i search for */
			if (current->data.id == id) {
				/* check if the id at the first position */
				if (prev == NULL) {
					head = current->next;
				}
				else {
					prev->next = current->next;
				}
				free(current);
				printf("--------------------------------------------\n");
				printf("The student was deleted successfully\n");

				return;
			}
			/* ( prev = current and current = current->next ) when the current moves in the linked list searching for the id i want to delete */
			prev = current;
			current = current->next;
		}
		/* In case of i havn't found the ID */
		printf("--------------------------------------------\n");
		printf("Student not found\n");


	}
}


#endif /* PROJECTFUNCTION_H_ */
