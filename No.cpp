/** ******************************************************************
 TAD Árvore BST
 Estrutura de Dados II
 GRUPO
 Nome: Gabriela Lopes Francisco
 TIA: 31744591
 Nome: 
 TIA: 

****************************************************************** */

using namespace std;
#include "No.h"

No::No(int chave) {
    this->chave = chave;
    esq = nullptr;
    dir = nullptr;
}

int No::getChave() {
    return chave;
}

No* No::getEsq() {
    return esq;
}

No* No::getDir() {
    return dir;
}

void No::setEsq(No *no) {
    esq = no;
}

void No::setDir(No *no) {
    dir = no;
}
