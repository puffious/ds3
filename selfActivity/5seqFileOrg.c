// Write a program to create and display records using sequential file organization.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "records.dat"
#define MAX_NAME 50

typedef struct {
    int id;
    char name[MAX_NAME];
    float marks;
} Student;

void create_records(int n);
void display_records(void);

int main(void){
    int n;
    printf("Enter number of records to create: ");
    scanf("%d", &n);
    create_records(n);
    display_records();
    return 0;
}

void create_records(int n){
    FILE *fp = fopen(FILENAME, "wb");
    if (!fp){
        printf("Error opening file.\n");
        return;
    }
    Student s;
    for (int i = 0; i < n; i++){
        printf("\nEnter details for student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &s.id);
        getchar(); // Consume newline after ID
        printf("Name: ");
        fgets(s.name, MAX_NAME, stdin);
        s.name[strcspn(s.name, "\n")] = 0; 
        printf("Marks: ");
        scanf("%f", &s.marks);
        getchar(); // Consume newline after marks
        fwrite(&s, sizeof(Student), 1, fp);
    }
    fclose(fp);
    printf("\n%d records created successfully.\n", n);
}

void display_records(void){
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp){
        printf("Error opening file.\n");
        return;
    }
    Student s;
    printf("\nRecords:\n");
    while (fread(&s, sizeof(Student), 1, fp)){
        printf("ID: %d, Name: %s, Marks: %.2f\n", s.id, s.name, s.marks);
    }
    fclose(fp);
}