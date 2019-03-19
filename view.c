#include "view.h"

#define BACK 0
#define EXIT -1

int sizeInt(int n){
    int i = 0;
    while(n != 0) {
        n /= 10;
        i++;
    }
    return i;
} 

int menuCheck(int size){
    int r;
    char s[10];
    fgets(s,10,stdin);
    if(strlen(s) == 2){
        if (s[0] >= '0' && s[0] <= '9'){
            r = (int)s[0] - (int)'0';
            if(r > 0 && r <= size){
                return r;
            }
        }
        else{
            if(s[0] == 'b' || s[0] == 'B'){
                return BACK;
            }
            if(s[0] == 'e' || s[0] == 'E'){
                return EXIT;
            }
        }
    }
    return -2;
}


int messageCheck(char* message){
    char s[10];
    printf("%s [Y/n]", message);
    fflush(stdout);
    while(1){
        fgets(s,10,stdin);
        if(s[0] == 'y' || s[0] == 'Y' || s[0] == '\n')
            return 1;
        if(s[0] == 'n' || s[0] == 'N')
            return 0;
    }
}

void replicate(char* s, int n){
    int i;
    for(i = 0; i < n; i++)
        printf("%s", s);
    fflush(stdout);
}

int printStrings(char** s, int ss, int pSize, int nCols, int pN){
    int i, j, pos, r = 0;

    for(i = pSize * pN; i < pSize * (pN + 1); i++){
        for(j = 0; j < nCols && j + i * nCols < ss; j++){
            pos = j + i * nCols;
            printf("%d.", pos + 1);
            replicate(" ", sizeInt(ss) + 1 - sizeInt(pos + 1));
            printf("%s      ", s[pos]);
        }
        r++;
        printf("\n");
    }
    return r;
}

void printTabela(const char* linLabl[], const char* colLabl[], int** iT, int lin, int col){
    int i, j;
    printf("+");
    replicate("-", strlen(linLabl[0]) + 2);
    for(j=0; j < col; j++)
        printf("+-----");
    printf("+\n");
    printf("|");
    replicate(" ", strlen(linLabl[0]) + 2);
    for(j = 0; j < col; j++)
        printf("| %s ", colLabl[j]);
    printf("|\n+");
    replicate("-", strlen(linLabl[1]) + 2);
    for(j=0; j < col; j++)
        printf("+-----");
    printf("+\n");
    
    for(i = 0; i < lin; i++){
        printf("| %s ", linLabl[i]);
        for(j = 0; j < col; j++)
            printf("|%4d ", iT[i][j]);
    printf("|\n+");
    replicate("-", strlen(linLabl[i]) + 2);
    for(j=0; j < col; j++)
        printf("+-----");
    printf("+\n");
    }
}