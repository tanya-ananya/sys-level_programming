#include <stdio.h>
#include <string.h>
#define MAX_NAME 50
#define NUM_STUDENTS 3

typedef struct {
    char name[MAX_NAME];
    int id;
    float gpa;
} Student;

void printStudent(Student *s) {
    printf("Name: %s\n", s->name);
    printf("ID: %d\n", s->id);
    printf("GPA: %.2f\n", s->gpa);
}

void updateGPA(Student *s, float newGPA) {
    printf("Updating %s's GPA...\n", s->name);
    s->gpa = newGPA;
}

Student *findTopStudent(Student *arr, int count) {
    Student *top = arr;
    for (int x = 1;x < count; x++) {
        if ((arr + x)->gpa > top->gpa) {
            top = arr + x;
        }
    }
    return top;
}

int main(void) {
    Student students[NUM_STUDENTS] = {
        {"Alice Johnson", 101, 3.50},
        {"Bob Smith", 102, 3.70},
        {"Carol Davis", 103, 3.95}
    };

    printf("\nAll Students:\n");

    Student *pntr = students;
    for (int x = 0; x< NUM_STUDENTS; x++) {
        printStudent(pntr);
        printf("\n");
        pntr++;
    }

    updateGPA(&students[0], 3.90);
    printStudent(&students[0]);
    printf("\n");

    printf("Top Student:");
    Student *top = findTopStudent(students, NUM_STUDENTS);
    printf("\n");
    printStudent(top);
}