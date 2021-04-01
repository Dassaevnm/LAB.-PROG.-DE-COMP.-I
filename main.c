#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#define TAMANHO 10 //Declara��o de constante, pode ser alterado conforme a necessidade do usu�rio de armazenar mais cartas.

char artista[TAMANHO][50];          // Recebe o nome do artista da gravura usada.
char caixa_de_texto[TAMANHO][500];  // Recebe a descricao das habilidades da carta.
char cor[TAMANHO][50];              // Recebe o nome da cor que a carta representa.
char formatos_validos[TAMANHO][50]; // Recebe a descricao de quais formatos de jogo a carta pode ser usada.
char linha_de_tipo[TAMANHO][50];    // Recebe o tipo da carta.
char subtipo[TAMANHO][50];          // Recebe o subtipo da carta.
char titulo[TAMANHO][50];           // Recebe o nome da carta.
char custo_de_mana[TAMANHO][50];    // Recebe o custo para conjurar a m�gica.
char ed_numero[TAMANHO][50];        // Recebe o nome da edi��o e o n�mero que a carta representa na cole��o.
char poder[TAMANHO][50];            // Recebe o valor da quantidade de dano que a criatura causar em combate.
char resistencia[TAMANHO][50];      // Recebe o valor da quantidade de dano que ela tem que sofrer em um �nico turno para ser destru�da.
char preco_medio[TAMANHO][50];      // Recebe o valor do pre�o m�dio em reais qua a carta custa.
char raridade[TAMANHO][50];         // Recebe a indicacao de qual a raridade da carta.

int opcao;              //Vari�vel usada para escolha de op��es do usu�rio.

void cadastro();        //C�digos da parte de cadastro.
void pesquisa();        //C�digos da parte de pesquisa.
void lista();           //C�digos da parte de lista.
void editar();          //C�digos da parte de edi��o de dados.

int main(void) {

    setlocale(LC_ALL, "Portuguese");


    do{
        system("cls");      //Como o programa mostra muitos textos, achei melhor limpar a tela frequentemente para ficar mais organizado.

        printf("  --------------------------------------------------------------------------- \n");
        printf(" |             Menu de Cadastro de Cartas de Magic The Gathering             |\n");
        printf("  --------------------------------------------------------------------------- \n\n");


        printf("1 - Cadastrar nova carta\n2 - Listar todas as cartas cadastradas\n3 - Pesquisar carta\n4 - Editar cadastro\n5 - Sair\n");       //Op��es principais do programa para escolha do usu�rio.
        printf("\nSelecione uma op��o de 1 a 5 por favor: ");       //Usu�rio digita um n�mero de 1 a 5.
        scanf("%d", &opcao);        //opcao recebe esse valor digitado.


        switch (opcao) {        //Entra na fun��o referente ao valor digitado.
            case 1:
                cadastro();     //Entra na fun��o cadastro.
                break;
            case 2:
                lista();        //Entra na fun��o lista.
                break;
            case 3:
                pesquisa();     //Entra na fun��o pesquisa.
                break;
            case 4:
                editar();       //Entra na fun��o editar dados.
                break;
            case 5:
                fflush(stdin);      //Limpando o buffer do teclado.
                system("exit");     //Op��o de sair do programa.
                break;

            default:

                printf("\nOp��o inv�lida!\n");      //Caso o usu�rio n�o digite um n�mero entre as op��es dadas.
                getchar();
                getchar();
                break;

        }
    } while (opcao!=5);         //Enquanto o usu�rio n�o digitar a op��o para sair do programa, o Menu principal ser� chamado.

} //Fim da fun��o menu

void cadastro() {
    static int linha;
        system("cls");



    do {

        fflush(stdin);
        printf("\nDigite o nome da carta: ");
        gets(titulo[linha]);

        printf("\nDigite o texto da carta: ");
        gets(caixa_de_texto[linha]);

        printf("\nDigite a cor da carta: ");
        gets(cor[linha]);

        printf("\nDigite o tipo da carta: ");
        gets(linha_de_tipo[linha]);

        printf("\nDigite o subtipo da carta: ");
        gets(subtipo[linha]);

        printf("\nDigite a raridade da carta: ");
        gets(raridade[linha]);

        printf("\nDigite o n�mero referente ao poder da carta: ");
        gets(poder[linha]);

        printf("\nDigite o n�mero referente a resist�ncia da carta: ");
        gets(resistencia[linha]);

        printf("\nDigite o custo de mana da carta: ");
        gets(custo_de_mana[linha]);

        printf("\nDigite os formatos v�lidos da carta: ");
        gets(formatos_validos[linha]);

        printf("\nDigite o nome do artista da carta: ");
        gets(artista[linha]);

        printf("\nDigite o nome da edi��o e o n�mero da carta: ");
        gets(ed_numero[linha]);

        printf("\nDigite o pre�o m�dio da carta R$: ");
        gets(preco_medio[linha]);

        printf("\nA carta foi armazenada na posi��o %d.\n", linha);

        printf("\n1 - Cadastrar outra carta.\n0 - Voltar ao MENU PRINCIPAL.\n");
        scanf(" %d", &opcao);

        linha++;        //Avan�a para a pr�xima posi��o na mem�ria para novo armazenamento.
        }
        while (opcao==1);       //Se usu�rio digitar 1 ele continua cadastrando, qualquer outro n�mero ele volta para menu principal.


} //Fim da funcao cadastro

void pesquisa(){
    system("cls");      //Limpando a tela.
    fflush(stdin);      //Limpando o Buffer do teclado.

    char pesquisatitulo[50];
    int i;

                printf("\nDigite o nome da carta j� cadastrada que voc� deseja encontrar: ");
                gets(pesquisatitulo);
                for(i=0;i<TAMANHO;i++){         //Percorre o vetor.

                        if(strcmp(titulo[i],pesquisatitulo)==0)         //Compara o que est� nos vetores, com o que foi digitado pelo usu�rio.
                        printf("\n\nSeguem os dados da carta cadastrada:\n\nPosi��o de cadastro: %d\nNome: %s\nTexto: %s\nCor: %s\nTipo: %s\nSubtipo: %s\nCusto de mana: %s\nRaridade: %s\nPoder: %s\nResist�ncia: %s\nArtista: %s\nNome e n�mero da edi��o: %s\nFormatos v�lidos: %s\nPre�o m�dio R$ %s\n\n", i, titulo[i],caixa_de_texto[i],cor[i],linha_de_tipo[i],subtipo[i],custo_de_mana[i],raridade[i],poder[i],resistencia[i],artista[i],ed_numero[i],formatos_validos[i],preco_medio[i]);
                        }
                        getchar();
                        getchar();

} //Fim da fun��o pesquisa

void lista(){
    system("cls");
    fflush(stdin);

    int i;
    for(i=0;i<TAMANHO;i++) {
        if (titulo[i][0] != '\0') {         //Lista todas as cartas que n�o tem um espa�o vazio na primeira posi��o.
            printf("\n\nSeguem os dados da carta cadastrada na posi��o %d:\n\nNome: %s\nTexto: %s\nCor: %s\nTipo: %s\nSubtipo: %s\nCusto de mana: %s\nRaridade: %s\nPoder: %s\nResist�ncia: %s\nArtista: %s\nNome e n�mero da edi��o: %s\nFormatos v�lidos: %s\nPre�o m�dio R$ %s\n\n", i, titulo[i], caixa_de_texto[i], cor[i], linha_de_tipo[i], subtipo[i], custo_de_mana[i],raridade[i], poder[i], resistencia[i], artista[i], ed_numero[i], formatos_validos[i], preco_medio[i]);
        }
        else{
            printf("N�o h� mais cartas cadastradas na base de dados.");
            getchar();

            break;
            }

        }
    }

main();


 //Fim da fun��o lista

void editar(){
    system("cls");
    fflush(stdin);

    int i;
    printf("\nDigite o n�mero da posi��o da carta que voc� deseja substituir os dados armazendos.\n");
    printf("Obs. Verificar a posi��o de cada carta j� armazenada na op��o 'lista' do menu principal\n\n");
    scanf("%d", &i);

    printf("\n\nFoi escolhida a posi��o %d.\n\n", i);

        if(titulo[i][0]!='\0'){     //Caso a posi��o 0 esteja vazia, ele considera que n�o tem carta cadastrada al�.
        fflush(stdin);

        printf("\nDigite o nome da nova carta: ");
        gets(titulo[i]);

        printf("\nDigite o texto da nova carta: ");
        gets(caixa_de_texto[i]);

        printf("\nDigite a cor da nova carta: ");
        gets(cor[i]);

        printf("\nDigite o tipo da nova carta: ");
        gets(linha_de_tipo[i]);

        printf("\nDigite o subtipo da nova carta: ");
        gets(subtipo[i]);

        printf("\nDigite a raridade da nova carta: ");
        gets(raridade[i]);

        printf("\nDigite o n�mero referente ao poder da nova carta: ");
        gets(poder[i]);

        printf("\nDigite o n�mero referente a resist�ncia da nova carta: ");
        gets(resistencia[i]);

        printf("\nDigite o custo de mana da nova carta: ");
        gets(custo_de_mana[i]);

        printf("\nDigite os formatos v�lidos da nova carta: ");
        gets(formatos_validos[i]);

        printf("\nDigite o nome do artista da nova carta: ");
        gets(artista[i]);

        printf("\nDigite o nome da edi��o e o n�mero da nova carta: ");
        gets(ed_numero[i]);

        printf("\nDigite o pre�o m�dio da nova carta R$: ");
        gets(preco_medio[i]);

        printf("\nA nova carta foi armazenada na posi��o %d.\n", i);

        getchar();

        }else{          //Caso n�o exista carta cadastrada na posi��o digitada, segue uma mensagem informando como proceder.
        printf("\n\nN�o existe carta cadastrada na posi��o %d. Por favor verifique o valor correto e tente novamente.\n",i);
        getchar();
        getchar();
        }

        main();

} //Fim da fun��o editar


