/** ******************************************************************
 TAD Árvore BST
 Estrutura de Dados II
 GRUPO
 Nome: Gabriela Lopes Francisco
 TIA: 31744591
 Nome: 
 TIA: 

****************************************************************** */

#ifndef TAD_ARVORE_BST_NO_H
#define TAD_ARVORE_BST_NO_H

class No {

private:
    No *esq, *dir;

public:
    No(int);
    int  getChave();
    No* getEsq();
    No* getDir();
    void setEsq(No*);
    void setDir(No*);

    int chave;
};
#endif
