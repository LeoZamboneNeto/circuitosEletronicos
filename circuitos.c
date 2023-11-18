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

float calcularResistorLED(float VF, float corrente, float tensaoLED){
        float RLED = (tensaoLED - VF) / corrente;
        return RLED;
}

void resistorLed(){
        float VF, corrente, tensaoLED;
        
        printf("\nResistor de LED:\n");
       
        printf("Digite a tensão de alimentação VF: ");
        //!=0 para o scanf, não para o valor em si. Caso usuário insira char será = 0, logo, acusará o erro 
        if (scanf("%f", &VF) != 0) {
                printf("Entrada inválida para VF.\n");
        }
        
        printf("Digite a corrente no LED: ");
        if (scanf("%f", &corrente) != 1){
                printf("Entrada inválida para corrente.\n");
        }
        
        printf("Digite a tensão no LED: ");
        if (scanf("%f", &tensaoLED) != 1){
                printf("Entrada inválida para tensão no LED.\n");
        }
        if (corrente == 0 || tensaoLED == 0){
                printf("A corrente ou tensão no LED não pode ser igual a 0.\n");
        }
        float RLED = calcularResistorLED(VF, corrente, tensaoLED);
        printf("O valor do resistor do LED (RLED) é: %.2f Ohms\n", RLED);

}

int main() {
        setlocale(LC_ALL, "Portuguese");

    char opcao;

    do {
        printf("Escolha uma opção:\n");
        printf("1. Circuito Divisor de Tensão\n");
        printf("2. Resistor de LED\n");
        printf("3. Transistor como Chave\n");
        printf("4. Polarização básica do transistor\n");
        printf("5. Polarização por divisor de tensão na base do transistor\n");
        printf("6. Montagem Amplificador Inversor com amp-op\n");
        printf("7. Montagem Amplificador não inversor com amp-op\n");
        printf("8. Sair\n");
        printf("Opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1': {
                    switchDivisorTensao();}

            case '2': {
                     resistorLed();}


            case '3':{}


            case '4':{}


            case '5':{}


            case '6':{}


            case '7':{}

            case '8':{
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

}while (opcao != '8');
return 0;}
