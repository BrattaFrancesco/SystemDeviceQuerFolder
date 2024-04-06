#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <io.h>
#include <ctype.h>

#define MAX_SURNAME_LEN 31
#define MAX_NAME_LEN 31
#define MAX_COMMAND_LENGTH 100

typedef struct {
    int identifier;
    long register_number;
    char surname[MAX_SURNAME_LEN];
    char name[MAX_NAME_LEN];
    int exam_mark;
} Record;

Record read_by_id(char* input_binary_filename, int id){
    int input_file = open(input_binary_filename, O_RDONLY);
    Record record;

    if (input_file == -1) {
        perror("Error opening file");
        return record;
    }

    lseek(input_file, sizeof(Record)*(id-1), SEEK_SET);
    read(input_file, &record, sizeof(Record));
    

    close(input_file);
    return record;
}

void write_by_id(char* output_binary_filename, Record record){
    int output_file = open(output_binary_filename, O_WRONLY | O_CREAT | O_TRUNC, _S_IREAD | _S_IWRITE);

    if (output_file == -1) {
        perror("Error opening the file");
        return;
    }

    lseek(output_file, sizeof(Record)*(record.identifier-1), SEEK_SET);
    write(output_file, &record, sizeof(Record));

    close(output_file);
    return;
}

void executeCommand(char command,int n) {
    char* file_2_write_path = "lab01\\data\\file_2_write.bin";
    command = toupper(command);
    Record r;
    
    switch (command)
    {
    case 'R':
        r = read_by_id(file_2_write_path, n);
        printf("%d %ld %s %s %d\n",
                  r.identifier, r.register_number,
                  r.surname, r.name, r.exam_mark);
        break;
    case 'W':
        r.identifier = n;
        char* register_number;
        char* exam_mark;
        
        printf("Insert register number: ");
        scanf("%ld", &r.register_number);
        
        printf("Insert surname: ");
        scanf("%s", r.surname);
        
        printf("Insert name: ");
        scanf("%s", r.name);

        printf("Insert exam mark: ");
        scanf("%d", &r.exam_mark);
        getchar();

        write_by_id(file_2_write_path, r);
        break;
    default:
        printf("Not existing command\n");
        break;
    }
}

void command_promt() {
    char input[MAX_COMMAND_LENGTH];
    int i = 0;
    printf("Type:\n-'R n' to read the n-th record\n-'W n' to write the n-th record\n-'E' to quit.\n\n\n");

    while (1) {
        if(i == 0){
            printf("Enter type of action (R, W, E)\n> ");
        }else if(i == 1){
            printf("Enter the index\n> ");
        }
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        
        // Remove newline character if present
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "E") == 0) {
            printf("Exiting...\n");
            break;
        } else {
            char command;
            int n;
            if(i == 0){
                command = (char) input[0];
                i++;
            }else if(i == 1){
                n = atoi(input);
                executeCommand(command, n);   
                i = 0;
            }
        }
    }

    return;
}

int main(){
    command_promt();
    
}