#include "options.h"

// name of the file to write to on --export
const char *FILE_NAME = "info_export.txt";

Student new_student(const char *name, const char *familyName, uint32_t matriculationNumber) {
    Student new_stud = {
        .name = name,
        .familyName = familyName,
        .matriculationNumber = matriculationNumber,
    };

    return new_stud;
}

/**
 * @brief writes the format of student to the file specified by FILE_NAME. 
 * 
 * @param text 
 */
void export_to_disk(const char* text) {

    // open file in write mode only, truncating previous content to zero
    FILE* handle = fopen(FILE_NAME, "w");

    // file could not be opened
    if (handle == NULL) {
        fprintf(stderr, "could not open file to export\n");
        return;
    }

    fprintf(handle, "%s", text);

    fclose(handle);

    printf("Author exported to disk. Goodbye!\n");
}

void generate_string(char *dest, const Student *student) {
    sprintf(dest, "Name: %s %s, Matrikelnummer: %7d\n", student->name, student->familyName, student->matriculationNumber);
}