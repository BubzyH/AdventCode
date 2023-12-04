#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int searchLeft(char line[100],int size){

    for(int i =size-1;i>=0;i--){
        for(int j = 0;j <10;j++){

            if(line[i] - '0'== j){
                return j;
            }
        }

    }
    printf("error\n");
   return 0;
}

int searchRight(char line[100],int size){

    for(int i =0;i<=size;i++){
        if(line[i] == '\n'){
            break;
        }
        for(int j = 0;j <10;j++){
            if(line[i] - '0'== j){
                return j;
            }
        }

    }
     printf("error\n");
   return 0;
}

int searchNumber(char line[100],int size){
   // printf("%s\n",line);
    int firstNumber;
    int secondNumber;
    char* number;
    firstNumber = searchRight(line, size);
    secondNumber = searchLeft(line,size);
    sprintf(number, "%d%d", firstNumber, secondNumber);
    printf("%s\n",number);
    return atoi(number);
}

void switchWordNumber(char *chaine) {
const char* words[9] = {"one","two","three","four","five","six","seven","eigh","nine"};
 const char *numbers[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    for (int i = 0; i < 9; i++) {
        char *position = strstr(chaine, words[i]);
        while (position != NULL) {
            // Remplacer le mot par le chiffre
            strncpy(position+1, numbers[i], strlen(numbers[i]));

            // Rechercher la prochaine occurrence du mot
            position = strstr(position + strlen(numbers[i]), words[i]);
        }
    }
}



int main(){
    FILE *file;
    FILE *file2;
file = fopen("input.txt", "r");
file2 = fopen("input2.txt", "w");


char * line = NULL;
size_t len = 0;
ssize_t read;
int sum = 0;

while ((read = getline(&line, &len, file))!=-1) {
 //   printf("%s",line);
switchWordNumber(line);
fprintf(file2, "%s",line);
 //printf("%s",line);
}
    fclose(file);
    fclose(file2);
file2 = fopen("input2.txt", "r");

while ((read = getline(&line, &len, file2))!=-1) {
        sum = sum + searchNumber(line,read);
}
printf("sum = %d\n",sum);
    fclose(file2);

    return 0;
}
