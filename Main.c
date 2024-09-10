#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
   char nSaldo[99];
   char nValor[99];

   printf("Digite seu nome:\n");
   scanf("%s", &nome);
   printf("------------------------------------------\n");

   printf("Digite seu saldo:\n");
   scanf("%f", &saldo);
   printf("------------------------------------------\n");

   itoa(saldo, nSaldo, 10);

   int sair = 1, escolha = 0;
   char extrato[100][100];


   //, contador = 0
    // Inicializando a matriz com algumas strings
    snprintf(extrato[0], 100, "Operacao");
    snprintf(extrato[1], 100, "Valor");
    snprintf(extrato[2], 100, "Saldo");
    snprintf(extrato[3], 100, "0 - Saldo Inicial");
    snprintf(extrato[4], 100, nSaldo);
    snprintf(extrato[5], 100, nSaldo);



    int contador = 6; //contador das posicoes de matriz
    int n = 6; // contador para a impressao de matriz
    int vNome = 0; //Colocar o nome no extrato
    int nomes[50];


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
               itoa(saldo, nSaldo, 10);
               itoa(saque, nValor, 10);


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

               n+=3;

               snprintf(extrato[contador], 100, "1 - Saque");
               snprintf(extrato[contador+1], 100, nValor);
               snprintf(extrato[contador+2], 100, nSaldo);

               contador+=3;

            }
        }
        else if(escolha == 2){
            float deposito = 0;
            printf ("Qual valor vai ser depositado?\n");
            scanf("%f", &deposito);
            saldo = adi (saldo, deposito);
            itoa(saldo, nSaldo, 10);
            itoa(deposito, nValor, 10);
            printf("Deposito aprovado\n");
            printf("------------------------------------------\n");

             n+=3;

               snprintf(extrato[contador], 100, "2 - Deposito");
               snprintf(extrato[contador+1], 100, nValor);
               snprintf(extrato[contador+2], 100, nSaldo);

               contador+=3;


        }
        else if(escolha == 3){
            float emprestimo = 0, parcela = 0, rendaM = 0;

            printf("Seu Saldo eh %.2f\n", saldo);
            printf ("Qual o valor do emprestimo?\n");
            scanf ("%f", &emprestimo);

            printf ("Em quantas vezes deseja pagar?\n");
            scanf ("%f", &parcela);
            printf ("Qual sua renda mensal?\n");
            scanf ("%f", &rendaM);

            if(emprestimo / parcela > rendaM * 0.3){
                printf("Emprestimo Recusado\n");
                 printf("------------------------------------------\n");
            }
            else{
                 printf("Emprestimo Aprovado\n");
                 saldo += emprestimo;
                  printf("------------------------------------------\n");
            }
            itoa(saldo, nSaldo, 10);
            itoa(emprestimo, nValor, 10);

               n+=3;

               snprintf(extrato[contador], 100, "3 - Emprestimo");
               snprintf(extrato[contador+1], 100, nValor);
               snprintf(extrato[contador+2], 100, nSaldo);

               contador+=3;

        }
        else if(escolha == 4){
            ReSaldo(saldo);
        }
        else if(escolha == 5){
                printf("Correntista: %s\n\n", nome);
                for (int i = 0; i < n; i++) {
                        if(nomes[i] == i && i != 0){
                            printf("\n4 - Transf %s", extrato[i]);
                        }

                        else if(i % 3 == 0){
                            printf("\n%12s",extrato[i]);
                        }
                        else{
                           printf("%12s",extrato[i]);
                        }
                }
        printf("------------------------------------------\n");
        printf("\n\n");

        }
        else if(escolha == 6){
            float transf = 0.0,valor = 0;
            char nome2[99];

            printf ("Quem vai receber a transferencia?\n");
            scanf ("%s", &nome2);
            printf ("Saldo atual: %.2f\n", saldo);
            printf ("Qual valor deseja transferir?\n");
            scanf ("%f", &transf);

        if(saldo >= transf){
                printf ("Valor transferido\n");
                saldo = sub(saldo, transf);
                printf("------------------------------------------\n");
            }else{
                printf("Saldo insuficiente\n");
                printf("------------------------------------------\n");
            }

            itoa(saldo, nSaldo, 10);
            itoa(transf, nValor, 10);

            vNome = n;
            nomes[n] = vNome;
            n+=3;

               snprintf(extrato[contador], 100, nome2);
               snprintf(extrato[contador+1], 100, nValor);
               snprintf(extrato[contador+2], 100, nSaldo);

               contador+=3;

        }

        else if(escolha == 7){
            sair = 0;
        }
        else{
            printf("Operacao Invalida\n");
            printf("------------------------------------------\n");
        }
   }while(sair != 0);

   return 0;
}
