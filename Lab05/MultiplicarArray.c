#include <stdio.h>
#define LEN 5

int main()
{
    int values[LEN];
    int i, x;
    printf("Digite 1 para multiplicar o array por 4\nOu algum outro valor de sua escolha\nValor: ");
    scanf("%d", &x);

    if (x == 1)
    {
        x = 4;
    }

    for (i = 0; i < LEN; i++)
    {
        printf("Digite o valor para a posicao %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    for (i = 0; i < LEN; i++)
    {
        values[i] *= x;
        printf("%d ", values[i]);
    }

    return 0;
}