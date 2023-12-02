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
     printf("ERROR\n");
   return -1;
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
    printf("ERROR\n");
   return -1;
}

int searchNumber(char line[100],int size){
    printf("%s\n",line);
    int firstNumber;
    int secondNumber;
    char* number;
    firstNumber = searchRight(line, size);
    secondNumber = searchLeft(line,size);
    sprintf(number, "%d%d", firstNumber, secondNumber);
    printf("%s\n",number);
    return atoi(number);
}

int main(){
    FILE *file;
file = fopen("input.txt", "r");
char * line = NULL;
size_t len = 0;
ssize_t read;
int sum = 0;
while ((read = getline(&line, &len, file))!=-1) {

        sum = sum + searchNumber(line,read);


}
    fclose(file);

     printf("sum = %d\n",sum);
    return 0;
}
