#include <stdio.h>

int main(){
   char nome[99];
   float saldo = 0.0;
   int saque = 0, cont100 = 0, cont50 = 0, cont20 = 0, cont10 = 0, cont5 = 0, cont2= 0;

   printf("Digite seu nome:\n");
   scanf("%s", &nome);

   printf("Digite seu saldo:\n");
   scanf("%f", &saldo);

   printf("Digite o saque\n");
   scanf("%d", &saque);

   if(saque > 0){
    for(;saque >= 100;){
        cont100++;
        saque = saque - 100;
    }
    for(;saque >= 50;){
        cont50++;
        saque = saque - 50;
    }
    for(;saque >= 20;){
        cont20++;
        saque = saque - 20;
    }
    for(;saque >= 10;){
        cont10++;
        saque = saque - 10;
    }
    for(;saque >= 5;){
        cont5++;
        saque = saque - 5;
    }
    for(;saque >= 2;){
        cont2++;
        saque = saque - 2;
    }

   }
   printf("100 %d\n", cont100);
   printf("50 %d\n", cont50);
   printf("20 %d\n", cont20);
   printf("10 %d\n", cont10);
   printf("5 %d\n", cont5);
   printf("2 %d\n", cont2);

   /*
   int sair = 1, escolha = 0;

   do{
        printf("Escolha uma das opcoes a seguir:\n1.Saque\n2.Deposito\n3.Emprestimo\n4.Consulta de Saldo\n5.Extrato\n6.Transferencia\n7.Sair\n");
        scanf("%d", &escolha);

        if(escolha == 1){

        }
        else if(escolha == 2){

        }
        else if(escolha == 3){

        }
        else if(escolha == 4){

        }
        else if(escolha == 5){

        }
        else if(escolha == 6){

        }
        else{
            sair = 0;
        }
   }while(sair != 0);


   */
}
