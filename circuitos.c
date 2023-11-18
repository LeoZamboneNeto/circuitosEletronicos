#include <stdio.h>
#include <locale.h>


void switchDivisorTensao(){ //@Léo Angelo Zambone Neto
        double Vs, Vm, Im, R1, R2;

        printf("Informe a tensão de entrada (Vs): ");
        scanf("%lf", &Vs);
        
        printf("Informe a tensão de saída (Vm): ");
        scanf("%lf", &Vm);
        
        printf("Informe a corrente máxima no circuito: ");
        scanf("%lf", &Im);

        // Verificar possíveis erros
        if (Vm >= Vs) {
                printf("\nErro: A tensão de saída (Vm) deve ser menor que a tensão de entrada (Vs).\n");
}

        if (Im <= 0) {
                printf("\nErro: A corrente máxima no circuito deve ser maior que zero.\n");
}
        // Calcular resistências
        R2 = Vm / Im;
        R1 = (Vs - Vm) / Im;

        printf("Valor do R1: %.2lf ohms\n", R1);
        printf("Valor do R2: %.2lf ohms\n", R2);

}

int main() {
        setlocale(LC_ALL, "Portuguese");

    char opcao;

    do {
        printf("Escolha uma opção:\n");
        printf("1. Circuito Divisor de Tensão\n");
        printf("2. Sair\n");
        printf("Opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1': {
                    switchDivisorTensao();

            case '2':
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

        // Aguardar uma tecla
        printf("\nPressione Enter para continuar...");
        while (getchar() != '\n');

        // Limpar a tela
        }

}while (opcao != '2');
return 0;}
