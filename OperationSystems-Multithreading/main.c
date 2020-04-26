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

void *readingFile(void *arg) {
    FILE *ptr;
    char line[100];
    if ((ptr = fopen("/Users/frez2zerovshik/Documents/Универ/Третий курс/6 семестр/OperationSystems-Multithreading/OperationSystems-Multithreading/File.txt", "rt")) == NULL) {
        fprintf(stderr, "Невозможно открыть файл на чтение");
        return (void*)EXIT_FAILURE;
    }
    int id = *((int*)arg);
    printf("Поток с ID %d читает файл\n" , id);
    while (fgets(line, 100, ptr)) {
        puts(line);
    }
    pthread_yield_np();
    fclose(ptr);
    return EXIT_SUCCESS;
}

int main(int argc, const char * argv[]) {
    pthread_t thread_1, thread_2;
    int id_1,id_2, result;
    id_1 = 1;
    id_2 = 2;
    
    if ((result = pthread_create(&thread_1, NULL, readingFile, &id_1)) != NULL) {
        fprintf(stderr, "Ошибка создания потока с id %d\n" , id_1);
        perror("Ошибка создания потока 1\n");
        return EXIT_FAILURE;
    }
    
    if ((result = pthread_create(&thread_2, NULL, readingFile, &id_2)) != NULL) {
        fprintf(stderr, "Ошибка создания потока с id %d\n" , id_2);
        perror("Ошибка создания потока 2\n");
        return EXIT_FAILURE;
    }
    
    if ((result = pthread_join(thread_1, NULL)) != NULL) {
        fprintf(stderr, "Ошибка обращения к первому потоку\n");
        perror("Ошибка обращения к первому потоку\n");
        return EXIT_FAILURE;
    }
    
    if ((result = pthread_join(thread_2, NULL)) != NULL) {
        fprintf(stderr, "Ошибка обращения ко второму потоку\n");
        perror("Ошибка обращения ко второму потоку\n");
        return EXIT_FAILURE;
    }
    
    printf("Операции успешно завершены\n");
    return EXIT_SUCCESS;
}
