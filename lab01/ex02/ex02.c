#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <io.h>

#define MAX_SURNAME_LEN 31
#define MAX_NAME_LEN 31

typedef struct {
    int identifier;
    long register_number;
    char surname[MAX_SURNAME_LEN];
    char name[MAX_NAME_LEN];
    int exam_mark;
} Record;

void read_by_id(char* input_binary_filename, int id){
    int input_file = open(input_binary_filename, O_RDONLY);

    if (input_file == -1) {
        perror("Error opening file");
        return;
    }

    lseek(input_file, sizeof(Record)*id, SEEK_SET);

    Record record;
    while (read(input_file, &record, sizeof(Record)) > 0) {
        fprintf(output_file, "%d %ld %s %s %d\n",
                record.identifier, record.register_number,
                record.surname, record.name, record.exam_mark);
    }

    close(input_file);
    fclose(output_file);
}