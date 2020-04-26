//
//  main.c
//  OperationSystems-Multithreading
//
//  Created by Артем Шарапов on 26.04.2020.
//  Copyright © 2020 Hooba-booba. All rights reserved.
//

#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

void *readingFile() {
    FILE *ptr;
    char line[100];
    if ((ptr = fopen("/Users/frez2zerovshik/Documents/Универ/Третий курс/6 семестр/OperationSystems-Multithreading/OperationSystems-Multithreading/File.txt", "rt")) == NULL) {
        fprintf(stderr, "Невозможно открыть файл на чтение");
        return (void*)EXIT_FAILURE;
    }
    while (fgets(line, 100, ptr)) {
        puts(line);
    }
    close(ptr);
    return EXIT_SUCCESS;
}

int main(int argc, const char * argv[]) {
    
    return EXIT_SUCCESS;
}
