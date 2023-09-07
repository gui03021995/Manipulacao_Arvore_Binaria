/*estritamente binária  = Quando todos os nós tem dois filhos com excessão dos nós folhas
arvore N area = AEDs III completa  = e quando todos os nós tem dois filhos com excessão dos nós folhas
altura de uma Arvore = A altura de um nó x em uma árvore binária é a distância
        entre x e o seu descendente mais afastado. Mais precisamente,
        a altura de x é o número de passos no mais longo caminho que leva de x até uma folha.
        quase completa = Se a diferença de altura entre as sub-árvores de qualquer nó é no máximo 1.
        profundidade = A profundidade de um nó é a distância deste nó até a raiz.
        Um conjunto de nós com a mesma profundidade é denominado nível da árvore.
        A maior profundidade de um nó, é a altura da árvore.*/


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<locale.h>
#include<string.h>

typedef struct Nodo* Arvore;
struct Nodo{​
    int info;
    struct Nodo *esq;
    struct Nodo *dir;
}​;

Arvore* CriarArvore()
{​
    Arvore* raiz = (Arvore*) malloc(sizeof(Arvore));
    if(raiz != NULL)
    {​
        *raiz = NULL;
    }​
    return raiz;
}​
void LiberaNodo(struct Nodo* nodo)
{​
    if(nodo != NULL)
    {​
        LiberaNodo(nodo->esq);
        LiberaNodo(nodo->dir);
        free(nodo);
        nodo = NULL;
    }​
}​
void LiberaArvore(Arvore *raiz)
{​
    if(raiz != NULL)
    {​
        LiberaNodo(*raiz);
        free(raiz);
    }​
}​
int ArvoreEstaVazia(Arvore *raiz)
{​
    int retorno = 0;
    if(raiz == NULL)
    {​
        retorno = 1;
    }​
    else if(*raiz == NULL)
    {​
        retorno = 1;
    }​
    return retorno;
}​
int ArvoreAltura(Arvore *raiz)
{​
    int retorno = 0;
    if(raiz != NULL && *raiz != NULL)
    {​
        int alt_esq = ArvoreAltura(&((*raiz)->esq));
        int alt_dir = ArvoreAltura(&((*raiz)->dir));
        if(alt_esq > alt_dir)
        {​
            retorno = alt_esq + 1;
        }​
        else        {​
            retorno = alt_dir + 1;
        }​
    }​
}​
int TotalNodoArvore(Arvore *raiz)
{​
    int retorno = 0;
    if(raiz != NULL && *raiz != NULL)
    {​
        int alt_esq = TotalNodoArvore(&((*raiz)->esq));
        int alt_dir = TotalNodoArvore(&((*raiz)->dir));
        retorno = alt_esq + alt_dir + 1;
    }​
}​
void ListarArvore(Arvore *raiz)
{​
    int retorno = 0;
    if(raiz != NULL && *raiz != NULL)
    {​
        printf("%i \n", (*raiz)->info);
        ListarArvore(&((*raiz)->esq));
        ListarArvore(&((*raiz)->dir));
    }​
}​
void InsereArvore(Arvore *raiz)
{​
    int retorno = 0;
    if(raiz != NULL)
    {​
        int valor = 0;
        printf("informe um Número\n");
        scanf("%i", &valor);
        struct Nodo* novo = (struct Nodo*)malloc(sizeof(struct Nodo));
        novo->info = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        if(*raiz == NULL)
        {​
            *raiz = novo;
        }​
        else        {​
            struct Nodo* atual = *raiz;
            struct Nodo* anterior = NULL;
            while(atual != NULL)
            {​
                anterior = atual;
                if(valor >= atual->info)
                {​
                    atual = atual->dir;
                }​
                else                {​
                    atual = atual->esq;
                }​
            }​
            if(valor >= anterior->info)
            {​
                anterior->dir = novo;
            }​
            else            {​
                anterior->esq = novo;
            }​
        }​
    }​
}​
Nodo* RemoveNodoAtualArvore(struct Nodo *nodoRemover)
{​
    struct Nodo * nodo1, *nodo2;
    if(nodoRemover->esq == NULL)
    {​
        nodo2 = nodoRemover->dir;
        free(nodoRemover);
    }​
    else    {​   nodo1 = nodoRemover;
        nodo2 = nodoRemover->esq;
        while(nodo2->dir != NULL)
        {​
            nodo1 = nodo2;
            nodo2 = nodo2->dir;
        }​
        if(nodo1 != nodoRemover)
        {​
            nodo1->dir = nodo2->esq;
            nodo2->esq = nodoRemover->esq;
        }​
        nodo2->dir = nodoRemover->dir;
        free(nodoRemover);
        nodoRemover = NULL;
    }​
    return nodo2;
}​
void RemoveArvore(Arvore *raiz)
{​
    int retorno = 0;
    if(raiz != NULL)
    {​
        int valor = 0;
        printf("informe um Número a Deletar\n");
        scanf("%i", &valor);
        struct Nodo* atual = *raiz;
        struct Nodo* anterior = NULL;
        while(atual != NULL)
        {​
            if(valor == atual->info)
            {​
                if(atual == *raiz)
                {​
                    *raiz = RemoveNodoAtualArvore(atual);
                }​
                else                {​
                    if(anterior->dir == atual)
                    {​
                        anterior->dir = RemoveNodoAtualArvore(atual);
                    }​
                    else                    {​
                        anterior->esq = RemoveNodoAtualArvore(atual);
                    }​
                }​
                break;
            }​
            else            {​
                anterior = atual;
                if(valor > atual->info)
                {​
                    atual = atual->dir;
                }​
                else                {​
                    atual = atual->esq;
                }​
            }​
        }​
    }​
}​
void ConsultaArvore(Arvore *raiz)
{​
    if(raiz != NULL)
    {​
        int valor = 0;
        printf("informe um Número\n");
        scanf("%i", &valor);
        if(raiz != NULL)
        {​
            struct Nodo* atual = *raiz;
            int alturaValor = 1;
            bool registroEncontrado = false;
            while(atual != NULL)
            {​
                if(valor == atual->info)
                {​
                    printf("Resgistro encontrado na altura %i\n", alturaValor);
                    registroEncontrado = true;
                    break;
                }​
                else if(valor >= atual->info)
                {​
                    alturaValor = alturaValor + 1;
                    atual = atual->dir;
                }​
                else                {​
                    alturaValor = alturaValor + 1;
                    atual = atual->esq;
                }​
            }​
            if(registroEncontrado == false)
            {​
                printf("Resgistro não encontrado\n");
            }​
        }​
    }​
}​
int main()
{​
    bool sair = false;
    int opcao = 0;
    Arvore *raiz = CriarArvore();
    int altura = 0;
    do    {​
        system("cls");
        printf("************************************************************************************************\n");
        printf("******************************************Menu**************************************************\n");
        printf("************************************************************************************************\n");
        printf("1 - Inserir\n");
        printf("2 - Deletar\n");
        printf("3 - Listar\n");
        printf("4 - Consultar\n");
        printf("5 - Altura Arvore\n");
        printf("6 - sair\n");
        scanf("%i", &opcao);
        fflush(stdin);
        switch(opcao)
        {​
            case 1:
                InsereArvore(raiz);
                break;
                case 2:
                RemoveArvore(raiz);
                break;
            case 3:
                ListarArvore(raiz);
                system("PAUSE");
                break;
            case 4:
                ConsultaArvore(raiz);
                system("PAUSE");
                break;
            case 5:
                altura = ArvoreAltura(raiz);
                printf("Altura total da Arvore %i\n", altura);
                system("PAUSE");
                break;
            default :
                sair = true;
                break;
        }​
    }​
    while(sair == false);
    LiberaArvore(raiz);
    return 0;
}​
