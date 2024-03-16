#include <stdio.h>
#include <stdint.h>
#include "compress.h"

#define BUFFER_SIZE 1

int arguments_error(){
    perror("Arguments error\n");
    return -1;
}

char* file_name_tobin(char* src_name){
    size_t len = strlen(src_name);
    char res[len+1];
    strcpy(res, src_name);
    size_t i = 0;
    while(res[i] != '.'){
        i++;
    }
    res[i++] = 'b';
    res[i++] = 'i';
    res[i++] = 'n';
    res[i++] = '\0';
    return res;
    
}

int main(int argc, int argv[]){

    // Handling arguments:
    if (argc != 3){
        return arguments_error();
    }

    FILE *src_file, *dst_file;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    char filename[15] = {0};
    
    // Handling encoding:
    if(strcmp(argv[1], "-c") == 0){
        // Opening src file:
        src_file = fopen(argv[2], "r");
        if(src_file == NULL){
            perror("Error occured while opening file.\n");
            return 1;
        }
        // Creating new name:
        char* new_file_name = file_name_tobin(argv[2]);
        // Creating a new file:
        dst_file = fopen(new_file_name, "w");
        if(dst_file == NULL){
            perror("Error occured while opening file.\n");
            fclose(src_file);
            return 1;
        }

        // Reading from src file:
        while(fread(buffer, 1, BUFFER_SIZE, src_file) > 0){
            uint8_t num = encode(atoi(buffer));
            uint8_t res = num;
            res<<4;
            if(fread(buffer, 1, BUFFER_SIZE, src_file) > 0){
                num = encode(atoi(buffer));
                res += num;
            }
            fprintf(dst_file, "%d", res);
        }
    }

    // Handling decoding:
    if(strcmp(argv[1], "-d") == 0){
        
    }
    else{ return arguments_error();}




    return 0;
}