#include "vendas.h"

#define CAMPOSVENDA 7

/**
\brief Estrutura para guardar uma venda.
*/
struct venda {
    char* codProd;    /**< código de produto */
    char* codCli;     /**< código de clientes */
    double precoUnit; /**< preço unitário */
    int quantidade;   /**< quantidade comprada */
    char* tipo;       /**< tipo de compra (N/P) */
    int mes;          /**< mês da compra */
    int filial;       /**< filial */
};

/**
\brief Array que contem as vendas.
*/
char* vendas[1000000];

/**
\brief Número de vendas no array vendas.
*/
int salesNumber;

/**
\brief Lê os produtos de um ficheiro e coloca-os no array vendas.

@param path ficheiro onde estão as vendas
*/
void readSalesFile(char* path) {
    int i;
    FILE* f = fopen(path, "r");
    char* buff = malloc(35);
    for(i = 0; fgets(buff, 35, f); i++) {
        vendas[i] = malloc(35);
        strcpy(vendas[i], buff);
    }
    salesNumber = i;
    fclose(f); 
}

/**
\brief Filtra as vendas do array de vendas.
*/
void verifySales() {
    int r, w, i;
    char* buff;
    char* tempSale;
    char* fieldOfSales[7];
    FILE* f = fopen("db/VendasOK.txt", "w");
    for(r = w = 0; r < salesNumber; r++) {
        tempSale = malloc(strlen(vendas[r]) + 1);
        strcpy(tempSale, vendas[r]);
        buff = strtok(tempSale, " ");
        for(i = 0; i < 7 && buff; i++) {
            fieldOfSales[i] = malloc(strlen(buff) + 1);
            strcpy(fieldOfSales[i], buff);
            buff = strtok(NULL, " ");
        }
        if(atoi(fieldOfSales[6]) > 3 || atoi(fieldOfSales[6]) < 1);
        else if(atoi(fieldOfSales[5]) > 12 || atoi(fieldOfSales[5]) < 1);
        else if(fieldOfSales[3][0] != 'P' && fieldOfSales[3][0] != 'N');
        else if(atoi(fieldOfSales[2]) > 250 || atoi(fieldOfSales[2]) < 0);
        else if(atof(fieldOfSales[1]) > 999.99 && atof(fieldOfSales[1]) < 0);
        else if(!searchClient(fieldOfSales[4]));
        else if(!searchProduct(fieldOfSales[0]));
        else {
            fprintf(f, "%s", vendas[r]);
            if(w != r) {
                free(vendas[w]);
                vendas[w] = malloc(strlen(vendas[r]) + 1);
                strcpy(vendas[w], vendas[r]);
            }
            w++;
        }
        for(i = 0; i < 7; i++)
            free(fieldOfSales[i]);
        free(tempSale);
    }
    fclose(f);
    salesNumber = w;
}

int getSalesNumber() {
    return salesNumber;
}

void cleanVendas() {
    int i;
    for(i = 0; i < salesNumber; i++)
        free(vendas[i]);
}

void initDB(int filter, char * pathProdutos, char * pathClientes, char * pathVendas){
    initProducts(filter, pathProdutos);
    initClients(filter, pathClientes);
    
    readSalesFile(pathVendas);
    if (filter) verifySales();
}

void printVenda(Venda vendaAux) {
    printf("Produto %s - ", vendaAux -> codProd);
    printf("Cliente: %s ", vendaAux -> codCli);
    printf("Preco: %f ", vendaAux -> precoUnit);
    printf("Quant: %d ", vendaAux -> quantidade);
    printf("Tipo: %s ",  vendaAux -> tipo); 
    printf("Mes: %d ", vendaAux -> mes);
    printf("Filial: %d\n ", vendaAux -> filial); 
    printf("Total da Venda = %f\n", vendaAux->precoUnit * vendaAux->quantidade);
}
