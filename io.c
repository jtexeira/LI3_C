#include "io.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define RESET "\033[0m"


static void menuClientes();
static void menuProdutos();
static void menuVendas();
static void menuQueries(int * loop);


int menuCheck(int size){
    int r;
    char s[10];
    fgets(s,10,stdin);
    if (s[0] >= '0' && s[0] <= '9'){
        r = (int)s[0] - (int)'0';
        if(r > 0 && r <= size){
            return r;
        }
    }
    else{
        if(s[0] == 'b' || s[0] == 'B'){
            return 0;
        }
        if(s[0] == 'e' || s[0] == 'E'){
            return -1;
        }
    }
    return -2;
}

void menuInicial(){
    int loop = 1;
    initDB(1, "db/Produtos.txt", "db/Clientes.txt", "db/Vendas_1M.txt");
    menuQueries(&loop);
    clearClients();
    clearProducts();
}

void menuQueries(int * loop){
    while(*loop){
        system("clear");
        printf(KRED "\t-- Categoria --\n\n" RESET);
        printf("1 - Clientes\n");
        printf("2 - Produtos\n");
        printf("3 - Vendas\n");
        printf("e - EXIT\n");
        switch (menuCheck(3))
        {
            case 0:
                menuQueries(loop);
                break;

            case 1:
               menuClientes(loop);
               break;

            case 2:
                menuProdutos(loop);
                break;

            case 3:
                menuVendas(loop);
                break;

            case -1:
                *loop = 0;
                break;

            default:
                break;
        }
    }
}

void menuClientes(int * loop){
    while(*loop){
        system("clear");
        printf(KRED "\t-- Clientes --\n\n" RESET);
        printf("1 - Clientes em todas as filiais\n");
        printf("2 - Stats sobre cliente (ano)\n");
        printf("3 - Stats sobre cliente (mes)\n");
        printf("4 - \n");
        switch (menuCheck(3))
        {
            case 0:
                menuQueries(loop);
                break;

            case 1:
                break;

            case 2:
                break;

            case 3:
                break;

            default:
                break;
        }
    }
}

void menuProdutos(int * loop){
    while(*loop){
        system("clear");
        printf(KRED "\t-- Produtos --\n\n" RESET);
        printf("1 - Navegar Produtos por Letra\n");
        printf("2 - Informações de Produto por mês\n");
        printf("3 - Stats de compras de um produto numa filial\n");
        printf("4 - Produtos mais vendidos\n");
        switch (menuCheck(4))
        {
            case 0:
                menuQueries(loop);
                break;

            case 1:
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            default:
                break;
        }
    }
}

void menuVendas(int * loop){
    while(*loop){
        system("clear");
        printf(KRED "\t-- Vendas --\n\n" RESET);
        printf("1 - total faturado em intervalo de tempo\n");
        printf("2 - \n");
        printf("3 - \n");
        printf("4 - \n");
        switch (menuCheck(1))
        {
            case 0:
                menuQueries(loop);
                break;

            case 1:
                break;

            default:
                break;
        }
    }
}

int printStrings(char ** s, int ss, int pSize, int pN){
    int i, r = 0;

    for(i = pSize * pN; i < pSize * (pN + 1) && i < ss; i++){
        printf("%s\n", s[i]);
        r++;
    }
    return r;
}

int messageCheck(char * message){
    int r = 1;
    char s[10];
    printf("%s[Y/n]\n", message);
    fgets(s,10,stdin);
    if(s[0] == 'n' || s[0] == 'N'){
        r = 0;
    }
    return r;
}