//https://www.reddit.com/r/dailyprogrammer/comments/ti5ji/5112012_challenge_51_intermediate/c4mtfd1/
//Interesting compiler - USER: Ttl

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define DATA_SIZE 30000
#define OUT(x) fprintf(source,x);break;

int main(int argc, char *argv[]) {
    FILE *source,*input;
    int c;
    if ((input = fopen(argv[1],"r")) == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    if ((source = fopen("/tmp/bftemp.c","w")) == NULL) {
        printf("Error while creating temporary file\n");
        exit(1);
    }
    fprintf(source,"#include <stdio.h>\nint main() {int ptr=0;int data[%d]={0};",DATA_SIZE);
    while ((c = fgetc(input)) != EOF) {
        switch (c) {
            case '>': OUT("++ptr;");
            case '<': OUT("--ptr;");
            case '+': OUT("++data[ptr];");
            case '-': OUT("--data[ptr];");
            case '.': OUT("putchar(data[ptr]);");
            case ',': OUT("data[ptr]=getchar();");
            case '[': OUT("while (data[ptr]) {");
            case ']': OUT("}");
            }
    }
    fprintf(source,"return 0;}");
    fclose(input);
    fclose(source);
    system("gcc -O3 -o /tmp/bf /tmp/bftemp.c");
    system("rm /tmp/bftemp.c");
    system("/tmp/bf");
    system("rm /tmp/bf");
    return 0;
}
