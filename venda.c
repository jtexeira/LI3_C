#include "venda.h"
#include <stdlib.h>
#include <string.h>

#define CAMPOSVENDA 7

/**
\brief Estrutura para guardar uma venda.
*/
struct venda {
    char* codProd;    /**< código de produto */
    char* codCli;     /**< código de clientes */
    double precoUnit; /**< preço unitário */
    int quantidade;   /**< quantidade comprada */
    char tipo;       /**< tipo de compra (N/P) */
    int mes;          /**< mês da compra */
    Filial filial;       /**< filial */
};

static char** saleFields(const char* sale) {
    int i;
    char** fieldOfSales = malloc(sizeof(char*) * CAMPOSVENDA);
    char* buff = malloc(strlen(sale) + 1);
    char* freee = buff;
    strcpy(buff, sale);
    buff = strtok(buff, " ");
    for(i = 0; i < CAMPOSVENDA && buff; i++) {
        fieldOfSales[i] = malloc(strlen(buff) + 1);
        strcpy(fieldOfSales[i], buff);
        buff = strtok(NULL, " ");
    }
    free(freee);
    return fieldOfSales;
}

int verifySale(const char* sale, const Produtos p, const Clientes c) {
    int r = 0, i;
    char** fieldOfSales = saleFields(sale);
    if(atoi(fieldOfSales[6]) > 3 || atoi(fieldOfSales[6]) < 1);
    else if(atoi(fieldOfSales[5]) > 12 || atoi(fieldOfSales[5]) < 1);
    else if(fieldOfSales[3][0] != 'P' && fieldOfSales[3][0] != 'N');
    else if(atoi(fieldOfSales[2]) > 250 || atoi(fieldOfSales[2]) < 0);
    else if(atof(fieldOfSales[1]) > 999.99 && atof(fieldOfSales[1]) < 0);
    else if(!searchClient(c, fieldOfSales[4]));
    else if(!searchProduct(p, fieldOfSales[0]));
    else r = 1;
    for(i = 0; i < CAMPOSVENDA; i++)
        free(fieldOfSales[i]);
    free(fieldOfSales);
    return r;
}

Venda mkSale(const char* sale) {
    int i;
    char** fieldOfSales = malloc(sizeof(char*) * CAMPOSVENDA);
    Venda venda = malloc(sizeof(struct venda));
    fieldOfSales = saleFields(sale);
    venda->codProd = malloc(strlen(fieldOfSales[0]) + 1);
    strcpy(venda->codProd, fieldOfSales[0]);

    venda->precoUnit = atof(fieldOfSales[1]);
    venda->quantidade = atoi(fieldOfSales[2]);
    venda->tipo = fieldOfSales[3][0];
    venda->codCli = malloc(strlen(fieldOfSales[4]) + 1);
    strcpy(venda->codCli, fieldOfSales[4]);
    venda->mes = atoi(fieldOfSales[5]);
    venda->filial = atoi(fieldOfSales[6]) - 1;
    for(i = 0; i < CAMPOSVENDA; i++)
        free(fieldOfSales[i]);

    free(fieldOfSales);

    return venda;
}

char* getClientSale(Venda v) {
    char* r = malloc(strlen(v->codCli) + 1);
    strcpy(r, v->codCli);
    return r;
}

char* getProductSale(Venda v) {
    char* r = malloc(strlen(v->codProd) + 1);
    strcpy(r, v->codProd);
    return r;
}

int getFilialSale(Venda v) {
    return v->filial;
}

Tipo getTipoSale(Venda v) {
    if(v->tipo == 'N') return 0;
    if(v->tipo == 'P') return 1;
    return -1;
}

double getPUnitSale(Venda v) {
    return v->precoUnit;
}

int getQuantSale(Venda v) {
    return v->quantidade;
}

int getMesSale(Venda v) {
    return v->mes;
}
double getTotalSale(Venda v) {
    return v->quantidade * v->precoUnit;
}

void destroySale(Venda venda) {
    free(venda->codCli);
    free(venda->codProd);
    free(venda);
}
