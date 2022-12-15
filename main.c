#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

typedef struct{
  int  id_aluno;
  char nm_aluno[50];
} arq_aluno;

void consulta(arq_aluno Alunos[], int quant_alunos){
  FILE *entrada = fopen("alunos.txt", "r");
  int id;
  if(entrada == NULL){
    printf("Erro na leitura do arquivo...!\n");
    return;
  }
    printf("\n------BUSCA DE ALUNOS------\n");
    printf("Digite o id do aluno: ");
    scanf("%i", &id);
    getchar();

  for (int i = 1 ; i <= quant_alunos ; i++){
    if (id == Alunos[i].id_aluno){
      printf("Aluno: %s\n", Alunos[i].nm_aluno);
    }
    else if (id != Alunos[i].id_aluno)
      printf("Aluno não existe na base!\n");
  }
  
    printf("---------------------------\n");
  fclose(entrada);
}

void relatorio(arq_aluno Alunos[], int quant_alunos){
  FILE* entrada = fopen("alunos.txt", "r");
  if(entrada == NULL){
    printf("Erro na leitura do arquivo...!\n");
    return;
  }
  int i;
  printf(         "_________________________________________\n\n"
                   " ----------RELATÓRIO DE ALUNOS--------- \n"
                "___________________________________________\n"
                  "------------------------------------------\n"
                "|         ID        |         NOME         |    \n");
  
  for ( int i = 0 ; i < quant_alunos ; i++ ){
    fscanf(entrada,"%d", &Alunos[i].id_aluno);
    fscanf(entrada,"%s", &Alunos[i].nm_aluno[50]);
    printf("  %10d    |   %5s\n", Alunos[i].id_aluno, Alunos[i].nm_aluno);
  }
  struct tm *data_hora_atual;
  time_t segundos;
  time(&segundos);
  data_hora_atual = localtime(&segundos);
  printf("-----------------------------\n\n");
  printf
  (
    "_______________________________\n\n"
    " Gerado em %d/%d/%d %i:%i:%i",data_hora_atual->tm_mday, data_hora_atual->tm_mon  + 1,data_hora_atual->tm_year + 1900, data_hora_atual->tm_hour,data_hora_atual->tm_min, data_hora_atual->tm_sec);
  fclose(entrada);
}

int main(){
  FILE* arq;
  int quant_alunos = 50;
  arq_aluno Alunos[24];
  int escolha;
  arq = fopen("alunos.txt","a"); /// abre para ler ou gravar a partir o final do arquivo
  fprintf(arq,"%s","\n");  /// id antes e nome depois
  fclose(arq);
  do{
    setlocale(LC_ALL, "");
    struct tm *data_hora_atual;
    time_t segundos;
    time(&segundos);
    data_hora_atual = localtime(&segundos);
    printf("\nAcesso em %d/%d/%d %i:%i:%i\n\n",data_hora_atual->tm_mday,data_hora_atual->tm_mon + 1, data_hora_atual->tm_year + 1900,data_hora_atual->tm_hour, data_hora_atual->tm_min,data_hora_atual->tm_sec);
    printf("   --MENU PRINCIPAL--\n");
    printf("|------------------------|\n");
    printf("| [1] - Consultar por id |\n"
           "| [2] - Relatório        |\n"
           "| [3] - Sair             |\n"
           "|------------------------|\n"
           "        Opção: "           );
    scanf("%d", &escolha);
    switch(escolha){
    case 1:
      consulta(Alunos, quant_alunos);
      break;
    case 2:
      relatorio(Alunos, quant_alunos);
      break;
    case 3:
      printf("Saindo do Programa...!\n\n\n");
    }
  }
  while (escolha != 3);
  return 0;
}
