
#include <stdio.h>
#include <locale.h>


void switchDivisorTensao(){ //@Léo Angelo Zambone Neto

    double Vs, Vm, Im, R1, R2;

    // != 0 pela entrada, não valor, caso inclua-se um char invés de num acusará erro
     printf("Informe a tensão de entrada (Vs): ");
     if (scanf("%lf", &Vs) != 1) {
        printf("Entrada inválida para tensão de entrada (Vs)!\n");
        return;
    }

    printf("Informe a tensão de saída (Vm): ");
    if (scanf("%lf", &Vm) != 1) {
        printf("Entrada inválida para tensão de saída (Vm)!\n");
        return;
    }

    printf("Informe a corrente máxima no circuito: ");
    if (scanf("%lf", &Im) != 1) {
        printf("Entrada inválida para corrente máxima (Im)!\n");
        return;
    }

    // Verificar possíveis erros
    if (Vm >= Vs) {
        printf("\nErro: A tensão de saída (Vm) deve ser menor que a tensão de entrada (Vs) para um divisor de tensão.\n");
        return;
    }

    if (Im <= 0) {
        printf("\nErro: A corrente máxima no circuito deve ser maior que zero.\n");
        return;
    }

    R2 = Vm / Im;
    R1 = (Vs - Vm) / Im;

    printf("\nValor do R1: %.2lf ohms\n", R1);
    printf("Valor do R2: %.2lf ohms\n", R2);
    return;
}

float calcularResistorLED(float VF, float corrente, float tensaoLED) {
    // Cálculo da resistência do LED usando a Lei de Ohm: R = (V - VF) / I
    float RLED = (tensaoLED - VF) / corrente;
    return RLED;
}

void resistorLed(){
    float VF, corrente, tensaoLED;

        printf("\nResistor de LED:\n");

        printf("Digite a tensão de alimentação VF: ");
            if (scanf("%f", &VF) != 1) {
            printf("Entrada inválida para VF!\n");
}

        printf("Digite a corrente no LED: ");
             if (scanf("%f", &corrente) != 1) {
             printf("Entrada inválida para corrente!\n");
}

        printf("Digite a tensão no LED: ");
             if (scanf("%f", &tensaoLED) != 1) {
             printf("Entrada inválida para tensão LED!\n");
}

        // Verificar se a corrente e a tensão no LED não são zero para evitar divisão por zero
        if (corrente == 0 || tensaoLED == 0) {
            printf("Erro: A corrente ou a tensão no LED não podem ser zero!\n");
}

        // Calcular o valor do resistor do LED
        float RLED = calcularResistorLED(VF, corrente, tensaoLED);
        printf("O valor do resistor do LED (RLED) é: %.2f Ohms\n", RLED);
}

void CircuitoTransistorChave() {
    double VS, VCC, Ic, Rc, Rs, VBE = 0.7;

    printf("Informe VS (Tensao de sinal): ");
    if (scanf("%lf", &VS) != 1) {
        printf("Entrada invalida para VS!\n");
        return;
    }

    printf("Informe VCC (Tensao de alimentacao): ");
    if (scanf("%lf", &VCC) != 1) {
        printf("Entrada invalida para VCC!\n");
        return;
    }

    printf("Informe Ic (Corrente de coletor): ");
    if (scanf("%lf", &Ic) != 1) {
        printf("Entrada invalida para Ic!\n");
        return;
    }

    // Calcular valores de Rs e Rc
    Rs = (VS - VBE) / Ic;
    Rc = (VCC - VS) / Ic;

    printf("Valor de Rs: %.2lf ohms\n", Rs);
    printf("Valor de Rc: %.2lf ohms\n", Rc);
}

void PolarizacaoTransistor() {
    double VS, VCC, VCE, beta, IC, VBE = 0.7, RS, RC;

    printf("Informe VS (Tensao de sinal): ");
    if (scanf("%lf", &VS) != 1) {
        printf("Entrada invalida para VS!\n");
        return;
    }

    printf("Informe VCC (Tensao de alimentacao): ");
    if (scanf("%lf", &VCC) != 1) {
        printf("Entrada invalida para VCC!\n");
        return;
    }

    printf("Informe VCE (Tensao coletor-emissor): ");
    if (scanf("%lf", &VCE) != 1) {
        printf("Entrada invalida para VCE!\n");
        return;
    }

    printf("Informe o valor de Beta do transistor: ");
    if (scanf("%lf", &beta) != 1) {
        printf("Entrada invalida para Beta!\n");
        return;
    }

    printf("Informe IC (Corrente de coletor): ");
    if (scanf("%lf", &IC) != 1) {
        printf("Entrada invalida para IC!\n");
        return;
    }

    // Calcular valores de RS e RC
    RS = (VS - VBE) / IC;
    RC = (VCC - VCE) / IC;

    printf("Valor de RS: %.2lf ohms\n", RS);
    printf("Valor de RC: %.2lf ohms\n", RC);
}

void PolarizacaoDivisorTensao() {
    double VCC, VCE, VRE, IC, beta, VBE = 0.7, R1, R2, RC, RE;

    printf("Informe VCC (Tensao de alimentacao): ");
    if (scanf("%lf", &VCC) != 1) {
        printf("Entrada invalida para VCC!\n");
        return;
    }

    printf("Informe VCE (Tensao coletor-emissor): ");
    if (scanf("%lf", &VCE) != 1) {
        printf("Entrada invalida para VCE!\n");
        return;
    }

    printf("Informe VRE (Tensao emissor-base): ");
    if (scanf("%lf", &VRE) != 1) {
        printf("Entrada invalida para VRE!\n");
        return;
    }

    printf("Informe IC (Corrente de coletor): ");
    if (scanf("%lf", &IC) != 1) {
        printf("Entrada invalida para IC!\n");
        return;
    }

    printf("Informe o valor de Beta do transistor: ");
    if (scanf("%lf", &beta) != 1) {
        printf("Entrada invalida para Beta!\n");
        return;
    }

    // Calcular valores de R1, R2, RC e RE
    RC = VCE / IC;
    RE = VRE / IC;

    R2 = (VCE - VBE) * (RE + RC) / VRE;
    R1 = R2 / ((VCE - VBE) / VBE);

    printf("Valor de R1: %.2lf ohms\n", R1);
    printf("Valor de R2: %.2lf ohms\n", R2);
    printf("Valor de RC: %.2lf ohms\n", RC);
    printf("Valor de RE: %.2lf ohms\n", RE);
}

void RfAmplificadorInversor() {
    double Vi, Vo, R1, Rf;

    printf("Informe o valor de Vi (Tensao de entrada): ");
    if (scanf("%lf", &Vi) != 1) {
        printf("Entrada invalida para Vi!\n");
        return;
    }

    printf("Informe o valor de Vo (Tensao de saida): ");
    if (scanf("%lf", &Vo) != 1) {
        printf("Entrada invalida para Vo!\n");
        return;
    }

    printf("Informe o valor de R1: ");
    if (scanf("%lf", &R1) != 1) {
        printf("Entrada invalida para R1!\n");
        return;
    }

    // Calcular o valor de Rf
    Rf = (R1 * (Vo / Vi)) - R1;

    printf("Valor de Rf: %.2lf ohms\n", Rf);
}


void RfAmplificadorNaoInversor() {
    double Vi, Vo, R1, Rf;

    printf("Informe o valor de Vi (Tensao de entrada): ");
    if (scanf("%lf", &Vi) != 1) {
        printf("Entrada invalida para Vi!\n");
        return;
    }

    printf("Informe o valor de Vo (Tensao de saida): ");
    if (scanf("%lf", &Vo) != 1) {
        printf("Entrada invalida para Vo!\n");
        return;
    }

    printf("Informe o valor de R1: ");
    if (scanf("%lf", &R1) != 1) {
        printf("Entrada invalida para R1!\n");
        return;
    }

    // Calcular o valor de Rf
    Rf = R1 * ((Vo / Vi) - 1);

    printf("Valor de Rf: %.2lf ohms\n", Rf);
}

int main() {
        setlocale(LC_ALL, "Portuguese");

    char opcao;

    do {
        printf("\nEscolha uma opção:\n");

        printf("1. Circuito Divisor de Tensão\n");
        printf("2. Resistor de LED\n");
        printf("3. Transistor como Chave\n");
        printf("4. Polarização básica do transistor\n");
        printf("5. Polarização por divisor de tensão na base do transistor\n");
        printf("6. Montagem Amplificador Inversor com amp-op\n");
        printf("7. Montagem Amplificador não inversor com amp-op\n");
        printf("8. Sair\n");

        printf("\nOpção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1': {
                    switchDivisorTensao();
                    break;}

            case '2': {
                     resistorLed();
                     break;}

            case '3':{
                    CircuitoTransistorChave();
                    break;}

            case '4':{
                    PolarizacaoTransistor();
                    break;}

            case '5':{
                    PolarizacaoDivisorTensao();
                    break;}

            case '6':{
                    RfAmplificadorInversor();
                    break;}

            case '7':{
                    RfAmplificadorNaoInversor();
                    break;}

            case '8':{
                printf("Saindo do programa.\n");
                break;
                default:
                printf("Opção inválida. Tente novamente.\n");
                break;
            }
        }

}while (opcao != '8');

return 0;}
