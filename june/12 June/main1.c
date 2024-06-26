#include <fcntl.h>   // For open
#include <unistd.h>  // For read, write, close
#include <sys/stat.h>  // For file permissions constants
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_STUDENTS 100

typedef struct {
    int roll_no;
    char name[50];
    float marks;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void create_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }
    Student s;
    printf("Enter roll number: ");
    scanf("%d", &s.roll_no);
    printf("Enter name: ");
    scanf("%s", s.name);
    printf("Enter marks: ");
    scanf("%f", &s.marks);
    students[student_count++] = s;

    int fp = open("data.dat", O_RDWR);
    if(fp < 0) {
	    printf("File not opned");
	    exit(1);
	}
    write(fp, &s, sizeof(s));		
    printf("Student added successfully.\n");
}

void delete_student() {
    int roll_no;
    printf("Enter roll number of the student to delete: ");
    scanf("%d", &roll_no);
    int found = 0;
    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_no == roll_no) {
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            found = 1;
            printf("Student deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Student with roll number %d not found.\n", roll_no);
    }
}

void display_students() {
    if (student_count == 0) {
        printf("No students to display.\n");
        return;
    }
    printf("Roll No.\tName\t\tMarks\n");
    printf("----------------------------------------\n");
    int fp = open("data.dat", O_RDWR);
    if(fp < 0) {
	    printf("File not opned");
	    exit(1);
	}
	Student s;
	
    while (read(fp, &s, sizeof(Student)) == sizeof(Student)) {
        printf("Roll No.: %d\n", s.roll_no);
        printf("Name: %s\n", s.name);
        printf("Marks: %.2f\n", s.marks);
        printf("---------------------\n");
    }
    
    
}

void search_student() {
    int roll_no;
    printf("Enter roll number to search: ");
    scanf("%d", &roll_no);
    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_no == roll_no) {
            printf("Student found:\n");
            printf("Roll No.: %d\n", students[i].roll_no);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", roll_no);
}

int main() {


    int choice;
    while (0) {
        printf("\nMenu:\n");
        printf("1. Create Student\n");
        printf("2. Delete Student\n");
        printf("3. Display Students\n");
        printf("4. Search Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_student();
                break;
            case 2:
                delete_student();
                break;
            case 3:
                display_students();
                break;
            case 4:
                search_student();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

