#include<stdio.h>

struct Funcionario {

    char nome[100];
    char cargo[100];
    float salariobase;
    float beneficios;
    float descontos;
    float salarioliquido;

    void ler() {
        printf("Nome: ");
        scanf("%[^\n]%*c", nome);
        printf("Cargo: ");
        scanf("%[^\n]%*c", cargo);
        printf("Salario base: ");
        scanf("%f", &salariobase);
        printf("Valor beneficios: ");
        scanf("%f", &beneficios);
        printf("Valor descontos: ");
        scanf("%f", &descontos);
    }

    void imprimir() {
        printf("Nome: %s\n", nome);
        printf("Cargo: %s\n", cargo);
        salarioliquido = salariobase + beneficios - descontos;
        printf("Salario liquido: %f\n", salarioliquido);
    }

};

struct Cadastro {

    Funcionario lista[10];
    int qtdfuncionarios;

    Cadastro() {
        qtdfuncionarios = 0;
    }

    void ler() {
        if (qtdfuncionarios >= 10) {
            printf("Quantidade maxima de funcionarios alcancada.\n");
            return;
        }
        lista[qtdfuncionarios].ler();
        qtdfuncionarios++;
    }

    void imprimir() {
        for (int i = 0; i < qtdfuncionarios; i++) {
            lista[i].imprimir();
        }
    }

    void imprimirMaior() {
        if (qtdfuncionarios == 0) {
            printf("Nao ha funcionarios cadastrados.\n");
            return;
        }
        float maior = lista[0].salarioliquido;
        int posicao = 0;
        for (int i = 1; i < qtdfuncionarios; i++) {
            if (lista[i].salarioliquido > maior) {
                maior = lista[i].salarioliquido;
                posicao = i;
            }
        }
        lista[posicao].imprimir();
    }

    void imprimirMedia(){
        if (qtdfuncionarios == 0) {
            printf("Nao ha funcionarios cadastrados.\n");
            return;
        }
        float somaSalarios = 0;
        for (int i = 0; i < qtdfuncionarios; i++) {
            somaSalarios += lista[i].salarioliquido;
        }
        float media = somaSalarios / qtdfuncionarios;
        printf("Media salarial: %f\n", media);
    }
};

int main() {

    Cadastro f;

    int opcao;

    do {

        printf("1. Ler\n");
        printf("2. Imprimir\n");
        printf("3. Imprimir Maior\n");
        printf("4. Imprimir Media salarial\n");
        printf("5. Sair\n");

        scanf("%d%*c", &opcao);

        switch(opcao) {
            case 1:
                f.ler();
                break;
            case 2:
                f.imprimir();
                break;
            case 3:
                f.imprimirMaior();
                break;
            case 4:
                f.imprimirMedia();
                break;
        };

    } while (opcao != 5);

    return 0;
}
