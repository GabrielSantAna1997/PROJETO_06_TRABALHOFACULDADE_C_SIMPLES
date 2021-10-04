#include<stdio.h>
#include<string.h>


#define TF 200

struct Registro {
    char nome[40], status;
    int ra;
};
typedef struct Registro reg;
/*---------------------------------------------------------------------------*/
void menuPrincipal();
void cadastrar(reg lista[TF], int *tl);
void listar(reg lista[TF], int tl);
void consultarRa(reg lista[TF], int tl);
void excluir(reg lista[TF], int tl);
void buscaNome(reg lista[TF], int tl);
void MaiorMenor(reg lista[TF], int tl);

/*---------------------------------------------------------------------------*/

int main(int argc, char** argv) {
    menuPrincipal();
    
}

/*---------------------------------------------------------------------------*/
void menuPrincipal() {
    char menu[6][85];	
    reg lista[TF];
    int i, op, tl = 0;
    strcpy(menu[0], "[ 1 ] Cadastrar");
    strcpy(menu[1], "[ 2 ] Consultar ra");
    strcpy(menu[2], "[ 3 ] Listar todos");
    strcpy(menu[3], "[ 4 ] Busca por nome");
    strcpy(menu[4], "[ 5 ] Excluir TODOS");
    strcpy(menu[5], "[ 6 ] Exibir o maior e o menor nome cadastrado");
    strcpy(menu[6], "[ 7 ] Sair");

    do {
        for (i = 0; i < 7; i++) {
            printf("%s\n", menu[i]);
        }
        fflush(stdin);
        scanf("%d", &op);
        switch (op) {
            case 1:
                cadastrar(lista, &tl);
                break;
            case 2:
                consultarRa(lista, tl);
                break;
        	case 3:
                listar(lista, tl);
                break;
            case 4:
                buscaNome(lista,tl);
                break;
            case 5:
                excluir(lista, tl);
                break;
            case 6:
                MaiorMenor(lista, tl);
                break;
            case 7:
                break;
        }
    } while (op != 7);
}

/*----------------------------CADASTRAR------------------------------*/
void cadastrar(reg lista[TF], int *tl) {
    reg aux;
    printf("Nome:\n");
    scanf("%s", &aux.nome);
    printf("Ra:");
    scanf("%d", &aux.ra);
    aux.status = 1;
    lista[*tl] = aux;
    *tl = *tl + 1;
}

/*--------------------------CONSULTAR RA------------------------------*/

void consultarRa(reg lista[TF], int tl) {
    int raPesquisa;
    int op;

    printf("digite o RA a consultar:\n");
    scanf("%d", &raPesquisa);

    while (tl-- && lista[tl].ra != raPesquisa ) {
    }
    if (lista[tl].ra==raPesquisa) {
        printf("Reg [%2d] - Nome[%s], Ra[%d]\n", tl, lista[tl].nome, lista[tl].ra);
    } else {
        printf("Registro não encontrado\n");
    }
   

printf("Digite um numero para voltar.\n");
scanf("%d", &op);
}


/*-----------------------LISTAR TODOS--------------------------------------*/
void listar(reg lista[TF], int tl) {
    int op;
    while (tl--) {
        if (lista[tl].status == 1)
            printf("Nome:[%s], Ra[%d]\n", lista[tl].nome, lista[tl].ra);
    }
    


printf("Digite um numero para voltar.\n");
scanf("%d", &op);
}


/*-------------------------BUSCAR POR NOME-----------------------------------*/

void buscaNome(reg lista[TF], int tl) {
    char nome[50];
    int op;
    
    printf("Digite um nome a cunsultar:\n");
    scanf("%s", &nome);
    printf("\n");

while(tl--){
  if(strstr(lista[tl].nome, nome) !=0){
    printf("Nome:[%s], Ra[%d]\n", lista[tl].nome, lista[tl].ra);
  }
}


printf("Digite um numero para voltar.\n");
scanf("%d", &op);

}





/*------------------------EXCLUIR TODOS--------------------------*/
void excluir(reg lista[TF], int tl) {
    int ra = -3;
    int op; 
    int i;
    char nomevazio[20];
    
    
    for(i=0;i < 200; i++){
      
      if(lista[tl].ra > ra,tl--){
        lista[tl].status = 0 ;
        lista[tl].ra = 0 ;
        strcpy(lista[tl].nome,nomevazio);
        
        
      }
    }printf("Informações apagadas com sucesso!\n");
    if(lista[tl].ra < ra){
      printf("Registro não encontrado\n");
    }


printf("Digite um numero para voltar.\n");
scanf("%d", &op);

}
   


/*------------------EXIBIR O MAIOR E O MENOR NOME----------------------*/

void MaiorMenor(reg lista[TF], int tl) {
char maior[50];
char menor[20];
int op;


while(tl--){
  
  if(strlen(lista[tl].nome) > strlen(maior)){
    strcpy(maior, lista[tl].nome);
  }
  if(strlen(menor) == 0 ){
    strcpy(menor, lista[tl].nome);
  }
  if(strlen(menor) > strlen(lista[tl].nome)){
    strcpy(menor, lista[tl].nome);
  }

}

printf("Maior nome:[%s]\n", maior);

printf("Menor nome:[%s]\n", menor);


printf("digite um numero para voltar.\n");
scanf("%d", &op);

}




/*---------------------------------------------------------------------------*/
