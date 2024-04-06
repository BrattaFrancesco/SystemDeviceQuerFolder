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

void text_to_binary(char* input_path, char* output_path){
    FILE* input_file = fopen(input_path, "r");
    int output_file = open(output_path, O_WRONLY | O_CREAT | O_TRUNC, _S_IREAD | _S_IWRITE);

    if (input_file == NULL || output_file == -1) {
        perror("Error opening file");
        return;
    }

    Record record;
    while (fscanf(input_file, "%d %ld %31s %31s %d",
                  &record.identifier, &record.register_number,
                  record.surname, record.name, &record.exam_mark) == 5) {
        write(output_file, &record, sizeof(Record));
    }

    fclose(input_file);
    close(output_file);
}

void binary_to_text(char* input_filename, char* output_filename){
    int input_file = open(input_filename, O_RDONLY);
    FILE *output_file = fopen(output_filename, "w");

    if (input_file == -1 || output_file == NULL) {
        perror("Error opening file");
        return;
    }

    Record record;
    while (read(input_file, &record, sizeof(Record)) > 0) {
        fprintf(output_file, "%d %ld %s %s %d\n",
                record.identifier, record.register_number,
                record.surname, record.name, record.exam_mark);
    }

    close(input_file);
    fclose(output_file);
}

int main(){
    char* file_1_path = "lab01\\data\\file_1.txt";
    char* file_2_path = "lab01\\data\\file_2.bin";
    char* file_3_path = "lab01\\data\\file_3.txt";

    text_to_binary(file_1_path, file_2_path);
    binary_to_text(file_2_path, file_3_path);
}