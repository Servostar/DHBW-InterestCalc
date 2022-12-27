#ifndef _OPTIONS_H_
#define _OPTIONS_H_

#include <stdio.h>
#include <inttypes.h>

typedef struct student {
    const char* name;
    const char* familyName;
    // 7-Decimal-Digit UUID number
    uint32_t matriculationNumber;
} Student;

/**
 * @brief create a new stack allocated student
 * 
 * @param name forename of the student
 * @param familyName 
 * @param matriculationNumber 7-digit unsigned uuid 
 * @return Student 
 */
Student new_student(const char *name, const char *familyName, uint32_t matriculationNumber);

/**
 * @brief fill a destination string with the format "Name <NAME>, <FAMILYNAME> Matriekelnummer: <NUMBER>"
 * 
 * @param dest string to store in, should be 100 bytes in size
 * @param author student to take inforamtion from
 */
void generate_string(char *dest, const Student *author);

/**
 * @brief export text to a file
 * 
 * @param text 
 */
void export_to_disk(const char* text);

#endif