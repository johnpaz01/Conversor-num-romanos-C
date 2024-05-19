#include <stdio.h>
#include <string.h>
#include <ctype.h>

int retornaValor(char letra) {
    switch(letra) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int converteNum(const char* str) {
    int i, numAnt = 0, numAtt = 0, result = 0;

    for (i = strlen(str) - 1; i >= 0; i--) {
        numAtt = retornaValor(str[i]);

        if (numAtt < numAnt) {
            result -= numAtt;
        } else {
            result += numAtt;
        }

        numAnt = numAtt;
    }

    return result;
}

int main() {
    char str[11];
    int i;

    printf("Digite o numero a se converter: ");
    scanf("%10s", str); // Limita a entrada para evitar buffer overflow
    
    
    for(i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }

    // Limpa o buffer de entrada
    while (getchar() != '\n');

    // Verifica se a entrada contém apenas caracteres romanos válidos
    for (i = 0; str[i]; i++) {
        if (retornaValor(toupper(str[i])) == 0) {
            printf("Entrada invalida. Certifique-se de usar apenas caracteres romanos (I, V, X, L, C, D, M).\n");
            return 1; // Retorna 1 para indicar erro
        }
    }

    printf("String de entrada: %s\n", str);

    int result = converteNum(str);
    printf("Numero convertido: %d\n", result);

    return 0;
}

