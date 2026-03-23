#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// Função para inserir um valor de forma ordenada no vetor
int inserir_ordenado(int vetor[], int *tamanho, int valor) {
    if (*tamanho >= MAX) {
        printf("Vetor cheio! Nao e possivel inserir.\n");
        return 0;
    }
    int i;
    // Desloca elementos maiores para a direita
    for (i = *tamanho - 1; i >= 0 && vetor[i] > valor; i--) {
        vetor[i + 1] = vetor[i];
    }
    vetor[i + 1] = valor;
    (*tamanho)++;
    return 1;
}

// Busca binária: retorna o índice do elemento ou -1 se não encontrado
int busca_binaria(int vetor[], int tamanho, int chave) {
    int esq = 0, dir = tamanho - 1;
    while (esq <= dir) {
        int meio = (esq + dir) / 2;
        if (vetor[meio] == chave)
            return meio;
        else if (vetor[meio] < chave)
            esq = meio + 1;
        else
            dir = meio - 1;
    }
    return -1;
}

// Função para remover um elemento do vetor (se existir)
int remover_elemento(int vetor[], int *tamanho, int valor) {
    int pos = busca_binaria(vetor, *tamanho, valor);
    if (pos == -1) {
        printf("Elemento nao encontrado.\n");
        return 0;
    }
    // Desloca os elementos à direita para a esquerda
    for (int i = pos; i < *tamanho - 1; i++) {
        vetor[i] = vetor[i + 1];
    }
    (*tamanho)--;
    printf("Elemento removido com sucesso.\n");
    return 1;
}

// Função para imprimir todo o vetor
void imprimir_vetor(int vetor[], int tamanho) {
    if (tamanho == 0) {
        printf("Vetor vazio.\n");
        return;
    }
    printf("Vetor atual: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[MAX];
    int tamanho = 0;
    int opcao, valor, pos;

    // Solicita o tamanho inicial do vetor (entre 3 e MAX)
    printf("Digite o tamanho do vetor (entre 3 e %d): ", MAX);
    scanf("%d", &tamanho);
    if (tamanho < 3 || tamanho > MAX) {
        printf("Tamanho invalido. Usando tamanho padrao 3.\n");
        tamanho = 3;
    }

    // Preenchimento inicial com inserção ordenada
    printf("Digite %d valores inteiros para preencher o vetor:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        // Inserção ordenada manual para o preenchimento inicial
        int j;
        for (j = i - 1; j >= 0 && vetor[j] > valor; j--) {
            vetor[j + 1] = vetor[j];
        }
        vetor[j + 1] = valor;
    }

    // Menu interativo
    do {
        printf("\n--- MENU ---\n");
        printf("1 - Imprimir vetor\n");
        printf("2 - Consultar elemento (busca binaria)\n");
        printf("3 - Remover elemento\n");
        printf("4 - Inserir elemento\n");
        printf("5 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                imprimir_vetor(vetor, tamanho);
                break;
            case 2:
                printf("Digite o valor a ser consultado: ");
                scanf("%d", &valor);
                pos = busca_binaria(vetor, tamanho, valor);
                if (pos != -1)
                    printf("Elemento encontrado na posicao %d.\n", pos);
                else
                    printf("Elemento nao encontrado.\n");
                break;
            case 3:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                remover_elemento(vetor, &tamanho, valor);
                break;
            case 4:
                if (tamanho >= MAX) {
                    printf("Vetor cheio! Nao e possivel inserir.\n");
                } else {
                    printf("Digite o valor a ser inserido: ");
                    scanf("%d", &valor);
                    inserir_ordenado(vetor, &tamanho, valor);
                    printf("Elemento inserido com sucesso.\n");
                }
                break;
            case 5:
                printf("Encerrando programa.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 5);

    return 0;
}
