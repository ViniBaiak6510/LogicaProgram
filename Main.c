#include <stdio.h>

void ReSaldo (float saldo){
    printf("Seu Saldo eh %.2f\n", saldo);
    printf("------------------------------------------\n");
}
float sub (float n1, float n2){
    return n1 - n2;

}
float adi (float n1, float n2){
    return n1 + n2;
}

int main(){
   char nome[99];
   float saldo = 0.0;

   printf("Digite seu nome:\n");
   scanf("%s", &nome);
   printf("------------------------------------------\n");

   printf("Digite seu saldo:\n");
   scanf("%f", &saldo);
   printf("------------------------------------------\n");

   int sair = 1, escolha = 0, contador = 0;
   char extrato[100][100];

    // Inicializando a matriz com algumas strings
    snprintf(extrato[contador], 100, "Operacao");
    snprintf(extrato[contador+1], 100, "Valor");
    snprintf(extrato[contador+2], 100, "Saldo");



    contador = 3; //contador das posicoes de matriz
    int n = 3; // contador para a impressao de matriz


   do{
        printf("Escolha uma das opcoes a seguir:\n1.Saque\n2.Deposito\n3.Emprestimo\n4.Consulta de Saldo\n5.Extrato\n6.Transferencia\n7.Sair\n");
        scanf("%d", &escolha);
        printf("------------------------------------------\n");

        if(escolha == 1){
            float saque = 0.0;
            printf("Digite o saque:\n");
            scanf("%f", &saque);
            printf("------------------------------------------\n");
            if(saque > saldo){
                printf("Saldo Insuficiente\n");
            }
            else{
               printf("Saque aprovado\n");
               int  cont100 = 0, cont50 = 0, cont20 = 0, cont10 = 0, cont5 = 0, cont2= 0; //Contador de cedulas
               saldo = sub(saldo, saque); // Sub do Saldo, usando a funcao
                while(saque >= 2){ // verificadores de cedulas
                    if(saque >= 100){
                        cont100++;
                        saque = saque - 100;
                    }
                    else if(saque >= 50){
                        cont50++;
                        saque = saque - 50;
                    }
                    else if(saque >= 20){
                        cont20++;
                        saque = saque - 20;
                    }
                    else if(saque >= 10){
                        cont10++;
                        saque = saque - 10;
                    }
                    else if(saque >= 5){
                        cont5++;
                        saque = saque - 5;
                    }
                    else if(saque >= 2){
                        cont2++;
                        saque = saque - 2;
                    }
               }
               printf("Notas retiradas:\n");
               printf("Notas de 100: %d\n", cont100);
               printf("Notas de 50: %d\n", cont50);
               printf("Notas de 20: %d\n", cont20);
               printf("Notas de 10: %d\n", cont10);
               printf("Notas de 5: %d\n", cont5);
               printf("Notas de 2: %d\n", cont2);
               printf("------------------------------------------\n");

               char num[99];

               sprintf(num, "%d", saldo);

               n+=3;

               snprintf(extrato[contador], 100, "1 - Saque");
               snprintf(extrato[contador+1], 100, "5000");
               snprintf(extrato[contador+2], 100, "60000");

               contador+=3;

            }
        }
        else if(escolha == 2){
            float deposito = 0;
            printf ("Qual valor vai ser depositado?\n");
            scanf("%f", &deposito);
            saldo = adi (saldo, deposito);
            printf("------------------------------------------\n");


        }
        else if(escolha == 3){
            float emprestimo = 0, parcela = 0, rendaM = 0;

            printf ("Qual o valor do emprestimo?\n");
            scanf ("%f", &emprestimo);
            ReSaldo(saldo);
            printf ("Em quantas vezes deseja pagar?\n");
            scanf ("%f", &parcela);
            printf ("Qual sua renda mensal?\n");
            scanf ("%f", &rendaM);

            if(emprestimo / parcela > rendaM * 0.3){
                printf("Emprestimo Recusado\n");
            }
            else{
                 printf("Emprestimo Aprovado\n");
                 saldo += emprestimo;
            }
        }
        else if(escolha == 4){
            ReSaldo(saldo);
        }
        else if(escolha == 5){
                printf("Correntista: %s\n\n", nome);
                for (int i = 0; i < n; i++) {
                        if(i % 3 == 0){
                            printf("\n5%s |",extrato[i]);

                        }
                        else{
                           printf("%5s |",extrato[i]);
                        }

                       // printf("%10s | ", extrato[i]);
                       // printf("%10s | ", ex[i]);
                       // printf("\n");
                }
        printf("\n");

        }
        else if(escolha == 6){
            float transf = 0,valor = 0;
            char nome2[99];
            printf ("Quem vai receber a transferencia?");
            scanf ("%s", &nome2);
            printf ("Saldo atual: %.2f\n", saldo);
            printf ("");
            scanf ("%f", &transf);




        }
        else if(escolha == 7){
            sair = 0;
        }
        else{
            printf("Operacao Invalida\n");
            printf("------------------------------------------\n");
        }
   }while(sair != 0);

   return 0; //
}
