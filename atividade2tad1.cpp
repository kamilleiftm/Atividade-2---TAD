#include<stdio.h>
#include <time.h>

struct Cliente {

    char nome[100];
    char sexo[1];
    int dia, mes, ano, idade;

    void ler() {
        printf("Nome: ");
        scanf("%[^\n]%*c", nome);
        printf("Sexo: (M/F)");
        scanf("%[^\n]%*c", sexo);
        printf("Data de nascimento: \nDia: ");
        scanf("%d%*c", &dia);
        printf("Mes: ");
        scanf("%d%*c", &mes);
        printf("Ano: ");
        scanf("%d%*c", &ano);

        struct tm data_nascimento_tm = {0};
        data_nascimento_tm.tm_year = ano - 1900;
        data_nascimento_tm.tm_mon = mes - 1;
        data_nascimento_tm.tm_mday = dia;

        time_t t_nascimento = mktime(&data_nascimento_tm);
        time_t t_atual = time(NULL);

        struct tm *data_atual = localtime(&t_atual);
        int ano_atual = data_atual->tm_year + 1900;
        int mes_atual = data_atual->tm_mon + 1;
        int dia_atual = data_atual->tm_mday;

        idade = ano_atual - (data_nascimento_tm.tm_year + 1900);
        if (mes_atual < data_nascimento_tm.tm_mon + 1 || (mes_atual == data_nascimento_tm.tm_mon + 1 && dia_atual < data_nascimento_tm.tm_mday)) {
            idade--;
        }
    }

    void imprimir() {
        printf("Nome: %s\n", nome);
        printf("Data de nascimento: %d/%d/%d\n", dia, mes, ano);
        printf("Idade: %d\n", idade);
        printf("Sexo: %s\n", sexo);
    }
};

struct Lista{

    Cliente clientes[50];
    int qtdclientes;

    Lista(){
        qtdclientes = 0;
    }

    void ler(){
        if(qtdclientes >= 50){
            printf("Quantidade maxima de clientes atingida.\n");
            return;
        }
        clientes[qtdclientes].ler();
        qtdclientes++;
    }

    void imprimir(){
        for (int i = 0; i < qtdclientes; i++){
            clientes[i].imprimir();
        }
    }

};

int main() {

    Lista clientes;
    int opcao;

    do{
        printf("1. Ler\n");
        printf("2. Imprimir\n");
        printf("3. Sair\n");

        scanf("%d%*c", &opcao);

        switch(opcao){
            case 1:
                clientes.ler();
                break;
            case 2:
                clientes.imprimir();
                break;
        };
    } while (opcao != 3);

    return 0;
}
