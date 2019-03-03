#include "produtos.h"

char* produtos[200000];

int productNumber;

void readProducts() {
    int i;
    FILE* f = fopen("db/Produtos.txt", "r");
    char* buff = malloc(10);
    for(i = 0; fgets(buff, 10, f); i++) {
        produtos[i] = malloc(10);
        strcpy(produtos[i], strtok(buff, "\n\r"));
    }
    free(buff);
    productNumber = i;
    fclose(f);
}

void verifyProducts() {
    int r, w, id;
    FILE* f = fopen("db/ProdutosOK.txt", "w");
    for(r = w = 0; r < productNumber; r++) {
        sscanf(produtos[r], "%*2c%4d%*s", &id);
        if(id >= 1000 && id <= 9999) {
            fprintf(f, produtos[r]);
            if(w != r) {
                produtos[w] = malloc(10); 
                strcpy(produtos[w], produtos[r]);
                free(produtos[r]);
            }
            w++;
        }
    }
    productNumber = w;
    fclose(f);
}

int searchProduct(char* id) {
    int i;
    for(i = 0; i < productNumber; i++)
        if(!strcmp(produtos[i], id)) return 1;
    return 0;
}

int getProductNumber() {
    return productNumber;
}

void initProducts(int filter) {
    readProducts();
    if(filter) verifyProducts();
}
