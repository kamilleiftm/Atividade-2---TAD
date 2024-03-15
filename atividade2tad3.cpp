#include <stdio.h>

struct Conjunto {
    int elemento[20];
    int tamanho;

    Conjunto() {
        tamanho = 0;
    }

    void ler() {
        tamanho = 0;
        printf("Digite o tamanho do conjunto: ");
        scanf("%d", &tamanho);
        if (tamanho <= 20) {
            printf("Digite os elementos do conjunto:\n");
            for (int i = 0; i < tamanho; i++) {
                printf("Elemento %d: ", i + 1);
                scanf("%d", &elemento[i]);
            }
        } else {
            printf("Tamanho maior que o permitido\n");
            return;
        }
    }

    Conjunto uniao(Conjunto outroConjunto) {
        Conjunto uniaoConjunto = *this;
        for (int i = 0; i < outroConjunto.tamanho; ++i) {
            bool encontrado = false;
            for (int j = 0; j < tamanho; ++j) {
                if (elemento[j] == outroConjunto.elemento[i]) {
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado && uniaoConjunto.tamanho < 20) {
                uniaoConjunto.elemento[uniaoConjunto.tamanho++] = outroConjunto.elemento[i];
            }
        }
        return uniaoConjunto;
    }

    void intersecao(Conjunto outroConjunto) {
        Conjunto intersecaoConjunto;

        for (int i = 0; i < tamanho; ++i) {
            for (int j = 0; j < outroConjunto.tamanho; ++j) {
                if (elemento[i] == outroConjunto.elemento[j]) {
                    intersecaoConjunto.elemento[intersecaoConjunto.tamanho++] = elemento[i];
                    break;
                }
            }
        }

        printf("Intersecao dos conjuntos:\n");
        intersecaoConjunto.imprimir();
    }

    void imprimir() {
        printf("{ ");
        for (int i = 0; i < tamanho; ++i) {
            printf("%d", elemento[i]);
            if (i != tamanho - 1) {
                printf(", ");
            }
        }
        printf("}\n");
    }
};

int main() {
    Conjunto conjunto1, conjunto2;

    int opcao;

    do {
        printf("1. Ler\n");
        printf("2. Uniao\n");
        printf("3. Intersecao\n");
        printf("4. Sair\n");

        scanf("%d%*c", &opcao);

        switch (opcao) {
            case 1:
                conjunto1.ler();
                conjunto2.ler();
                break;
            case 2: {
                Conjunto uniaoConjunto = conjunto1.uniao(conjunto2);
                uniaoConjunto.imprimir();
                break;
            }
            case 3:
                conjunto1.intersecao(conjunto2);
                break;
        };

    } while (opcao != 4);

    return 0;
}
