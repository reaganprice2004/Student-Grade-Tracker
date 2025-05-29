#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    float grade;
} Student;

Student students[MAX_STUDENTS];
int count = 0;

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addStudent() {
    if (count >= MAX_STUDENTS) {
        printf("Student limit reached.\n");
        return;
    }

    printf("Enter student name: ");
    clearInputBuffer();  // Clear leftover newline
    fgets(students[count].name, NAME_LEN, stdin);
    students[count].name[strcspn(students[count].name, "\n")] = 0;  // Remove newline

    printf("Enter grade: ");
    if (scanf("%f", &students[count].grade) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        return;
    }

    count++;
    printf("Student added!\n");
}

void viewStudents() {
    if (count == 0) {
        printf("No students yet.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("%d. %s - %.2f\n", i + 1, students[i].name, students[i].grade);
    }
}

void averageGrade() {
    if (count == 0) {
        printf("No students to calculate average.\n");
        return;
    }

    float total = 0;
    for (int i = 0; i < count; i++) {
        total += students[i].grade;
    }
    printf("Class average: %.2f\n", total / count);
}

void saveToFile() {
    FILE *fp = fopen("grades.txt", "w");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s|%.2f\n", students[i].name, students[i].grade);
    }

    fclose(fp);
    printf("Data saved to grades.txt\n");
}

void loadFromFile() {
    FILE *fp = fopen("grades.txt", "r");
    if (!fp) {
        printf("No previous data to load.\n");
        return;
    }

    count = 0;
    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        char *sep = strchr(line, '|');
        if (!sep) continue;

        *sep = '\0'; // Split at '|'
        strncpy(students[count].name, line, NAME_LEN);
        students[count].name[NAME_LEN - 1] = '\0';

        if (sscanf(sep + 1, "%f", &students[count].grade) == 1) {
            count++;
            if (count >= MAX_STUDENTS) break;
        }
    }

    fclose(fp);
    printf("Loaded %d students from file.\n", count);
}

int main() {
    loadFromFile();
    int choice;

    while (1) {
        printf("\n1. Add student\n2. View students\n3. Class average\n4. Save & Exit\nChoose: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: averageGrade(); break;
            case 4: saveToFile(); return 0;
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}
