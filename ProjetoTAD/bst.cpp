#include <iostream>
#include "No.h"
#include "BST.h"

using namespace std;

ArvoreBST::ArvoreBST() {
    raiz = nullptr;
}

void ArvoreBST::insereElemento(int chave) {
    if (raiz == nullptr)                                  
        raiz = new No(chave);                              
    else insereAux(raiz, chave);
}

void ArvoreBST::insereAux(No *no, int chave) {
    if (chave < no->getChave()) {                           
        if (no->getEsq() == nullptr) {                      
            No *novo_no = new No(chave);
            no->setEsq(novo_no);                            
        } else {
            insereAux(no->getEsq(), chave);                 
        }
    } else if (chave > no->getChave()) {                   
        if (no->getDir() == nullptr) {                      
            No *novo_no = new No(chave);
            no->setDir(novo_no);                            
        } else {
            insereAux(no->getDir(), chave);                 
        }
    }     
}

No *ArvoreBST::getRaiz() {
    return raiz;
}

void ArvoreBST::emOrdem(No *no) {
    if (no != nullptr) 
    {
        emOrdem(no->getEsq());
        cout << no->getChave() << " ";
        emOrdem(no->getDir());
    }
}

void ArvoreBST::preOrdem(No *no) {
    if (no != nullptr) {
        cout << no->getChave() << " ";
        preOrdem(no->getEsq());
        preOrdem(no->getDir());
    }
}

void ArvoreBST::posOrdem(No *no) {
    if (no != nullptr) {
        posOrdem(no->getEsq());
        posOrdem(no->getDir());
        cout << no->getChave() << " ";
    }
}

No *ArvoreBST::pesquisarRec(No *no, int chave) {
    if (no == nullptr || no->getChave() == chave) return no;      /**Se o nó for nulo ou o nó for a chave ele retorna o elemento*/                                                     
    else if (no->getChave() > chave) {                             
        return pesquisarRec(no->getEsq(), chave);            /**Recursão para esquerda da árvore se o elemento for menor que nó*/
    } 
	else {
        return pesquisarRec(no->getDir(), chave);             
    }
}

No *ArvoreBST::pesquisarIter(No *no, int chave){
	while (no !=nullptr ){
		if (no->getChave()==chave) return no;
		else if(no->getChave() >chave)
			no->getEsq();
		else
			no->getDir();
			
	}
	return nullptr;
}


int ArvoreBST::qdeNos(No *no) {
    if (no == nullptr) return 0;    /**Se o nó estiver apontando para nullptr retorna 0*/                                                                
    else return (1 + qdeNos(no->getEsq()) + qdeNos(no->getDir()));                
}


int ArvoreBST::alturaBST(No *no) {
    if (no == nullptr) return -1;                                                                 
    else {
        if (no->getEsq() == nullptr && no->getDir() == nullptr)
            return 0;       /**Se for uma folha ou a raiz retorna 0*/                                   
        else {
            if (alturaBST(no->getEsq()) >
                alturaBST(no->getDir()))         
                return (1 + alturaBST(no->getEsq()));
            else
                return (1 + alturaBST(no->getDir()));
        }
    }
}

int ArvoreBST::min(No *no) {
    if (no == nullptr) return 0;
    if (no->getEsq() == nullptr) return no->getChave();         
    else return min(no->getEsq());       /**Recursão até achar o menor elemento*/       
}

int ArvoreBST::max(No *no) {
    if (no == nullptr) return 0;
    if (no->getDir() == nullptr) return no->getChave();         
    else return max(no->getDir());  /**Recursão até achar o maior elemento*/              
}

int ArvoreBST::folhas(No *no) {
    if (no != nullptr){
    	if (no->getEsq() == nullptr && no->getDir() == nullptr){
    		cout<<no->getChave() << " ";    /**Se for uma folha, o programa irá imprimir o elemento*/
		}
		folhas(no->getEsq());.         /**Recursividade*/
		folhas(no->getDir());
	}
    
}

bool ArvoreBST::removerFolha(int chave) {     /**Remove folha*/
    if (raiz == nullptr) return false;       /**Se a árvore tiver vazia, retorna nullptr*/                                               
    No *anda = raiz;.                      /**declarando dois nó apontando para raiz*/
    No *ant = raiz; 
	bool temFilhoEsq = true;                                           
    while (anda->getChave() != chave) {       /**percorre a árvore e para quando achar o elemento*/                             
        ant = anda;
        if (chave < anda->getChave()) {                                                
            anda = anda->getEsq();
            temFilhoEsq = true;
        } else {                                                                         
            anda = anda->getDir();
            temFilhoEsq = false;
        }                        
    }
    
 	if (anda->getEsq() == nullptr && anda->getDir() == nullptr) {  //**verifica se é uma folha*/
        if (anda == raiz) raiz = nullptr;                 /**Caso o elemento for uma ele deleta o elemento*/
        else if (temFilhoEsq
            ant->setEsq(nullptr);
        else
            ant->setDir(nullptr);                                                               
    }
    
    else{
    	return false      /**retornando falso caso não seja uma folha*/
	}
	return true;   /**retornando true caso seja uma folha*/
}

