#include <stdio.h>
#include <stdlib.h>

/* Display the student position in class and their respective averages */
#define NUM_SUBJECTS 4
#define COMPULSORY_SUBJECTS 2
#define MATH_ENGLISH_WEIGHT 2
#define OTHER_SUBJECT_WEIGHT 1

struct Student {
    char name[50];
    int marks[NUM_SUBJECTS];
    float average;
    int position;
};

// Function to calculate average marks
float calculateAverage(int marks[], int numSubjects) {
    int total = 0;
    for (int i = 0; i < numSubjects; ++i) {
        total += marks[i];
    }
    return (float)total / numSubjects;
}

// Function to compare students based on average marks (for sorting)
int compareStudents(const void *a, const void *b) {
    const struct Student *s1 = (const struct Student *)a;
    const struct Student *s2 = (const struct Student *)b;
    
    if (s1->average < s2->average) return 1;
    else if (s1->average > s2->average) return -1;
    else return 0;
}

int main() {
    int numStudents;
    printf("Enter the number of students in the class: ");
    scanf("%d", &numStudents);
    
    if (numStudents <= 0) {
        printf("Invalid number of students. Exiting program.\n");
        return 1;
    }
    
    struct Student students[numStudents];
    
    // Input marks and names for each student
    for (int i = 0; i < numStudents; ++i) {
        printf("\nEnter details for Student %d:\n", i + 1);
        
        printf("Enter name: ");
        scanf(" %[^\n]s", students[i].name);
        
        printf("Enter marks for Math: ");
        scanf("%d", &students[i].marks[0]);
        
        printf("Enter marks for English: ");
        scanf("%d", &students[i].marks[1]);
        
         printf("Enter marks for Physics: ");
        scanf("%d", &students[i].marks[2]);
        
        printf("Enter marks for Biology: ");
        scanf("%d", &students[i].marks[3]);
        
        // Calculate average marks
        float sum = MATH_ENGLISH_WEIGHT * (students[i].marks[0] + students[i].marks[1]);
        for (int k = COMPULSORY_SUBJECTS; k < NUM_SUBJECTS; ++k) {
            sum += OTHER_SUBJECT_WEIGHT * students[i].marks[k];
        }
        students[i].average = sum / NUM_SUBJECTS;
    }
    
    // Sort students based on average marks (descending order)
    qsort(students, numStudents, sizeof(struct Student), compareStudents);
    
    // Assign positions after sorting
    for (int i = 0; i < numStudents; ++i) {
        students[i].position = i + 1;
    }
    
    // Display results in tabular form
    printf("\n%-5s %-20s %-10s\n", "Rank", "Name", "Average");
    printf("---------------------------------\n");
    for (int i = 0; i < numStudents; ++i) {
        printf("%-5d %-20s %-10.2f\n", students[i].position, students[i].name, students[i].average);
    }
    
    return 0;
}