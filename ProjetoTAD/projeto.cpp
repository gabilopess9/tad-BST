#include <iostream>
#include "no.cpp"
#include "bst.cpp"

using namespace std;

int main() {

    ArvoreBST arvoreBst;

    int opc;

    cout << "\n\n\n";
    cout << "\n-------------------------------------------------------------------";
    cout << "\n                       TAD ARVORE BST";
    cout << "\n (Esta arvore so aceita numeros inteiros maiores ou iguais a zero)";
    cout << "\n-------------------------------------------------------------------";

    do {
        cout << "\n\n________________________   MENU   _____________________________\n";
        cout << "\n0 - Sair";
        cout << "\n1 - Inserir elemento";
        cout << "\n2 - Imprimir a arvore em ordem";
        cout << "\n3 - Imprimir a arvore em pre-ordem";
        cout << "\n4 - Imprimir a arvore em pos-ordem";
        cout << "\n5 - Pesquisar elemento de forma recursiva";
        cout << "\n6 - Pesquisar elemento de forma iterativa";
        cout << "\n7 - Mostrar quantidade de nos";
        cout << "\n8 - Imprimir altura da arvore";
        cout << "\n8 - Consultar valor minimo";
        cout << "\n9 - Consultar valor maximo";
        cout << "\n11 - Imprimir todas as folhas em ordem crescente:";
        cout <<"\n12 - Remover folhas ";
        cout << "\n\n_______________________________________________________________\n";
        cout << "\n\nInforme sua opcao: ";
        cin >> opc;

        switch (opc) {

            /** Opção de saída */

            case 0: {
                cout << "\n\n ~~~~ Fim da execução! ~~~~\n\n";
                break;
            }

                /** Inserir elemento */

            case 1: {
                int item;
                cout << "Valor a ser inserido: ";
                cin >> item;
                arvoreBst.insereElemento(item);
                cout << "\nElemento " << item << " adicionado com sucesso!";
                break;
            }


                /** Imprimir a árvore em ordem */

            case 2: {
                if (arvoreBst.getRaiz() == nullptr) {
                    cout << "\n A arvore está vazia!";
                    break;
                } else {
                    arvoreBst.emOrdem(arvoreBst.getRaiz());
                    break;
                }
            }

                /** Imprime a a árvore em pré-ordem */

            case 3: {
                if (arvoreBst.getRaiz() == nullptr) {
                    cout << "\n A arvore esta vazia!";
                    break;
                } else {
                    arvoreBst.preOrdem(arvoreBst.getRaiz());
                    break;
                }
            }

                /** Imprime a a árvore em pós-ordem */

            case 4: {
                if (arvoreBst.getRaiz() == nullptr) {
                    cout << "\n A arvore esta vazia!";
                    break;
                } else {
                    arvoreBst.posOrdem(arvoreBst.getRaiz());
                    break;
                }
            }


                /** Pesquisa o elemento na árvore */

            case 5: {
                int item;
                cout << "Elemento a ser procurado: ";
                cin >> item;
                No *elemento = arvoreBst.pesquisarRec(arvoreBst.getRaiz(), item);
                if (elemento == nullptr) {
                    cout << "\n Elemento nao encontrado!";
                    break;
                } else {
                    cout << "\nO elemento " << item << " esta na arvore!";
                    break;
                }
            }
            
            case 6: {
                int item;
                cout << "Elemento a ser procurado: ";
                cin >> item;
                No *elemento = arvoreBst.pesquisarIter(arvoreBst.getRaiz(), item);
                if (elemento == nullptr) {
                    cout << "\n Elemento nao encontrado!";
                    break;
                } else {
                    cout << "\nO elemento " << item << " esta na arvore!";
                    break;
                }
            }
            

                /** Mostra quantidade de nós */

            case 7: {
                cout << "Quantidade de nos na arvore: " << arvoreBst.qdeNos(arvoreBst.getRaiz());
                break;
            }
            
            
            /** Imprime a altura da árvore */

            case 8: {
                int valor = arvoreBst.alturaBST(arvoreBst.getRaiz());
                if (valor == -1) {
                    cout << "\n A arvore esta vazia!";
                    break;
                } else {
                    cout << "Altura da arvore: " << valor;
                    break;
                }
            }


                /** Consulta o valor mínimo da árvore */

            case 9: {
                cout << "Valor minimo da arvore: " << arvoreBst.min(arvoreBst.getRaiz());
                break;
            }

                /** Consulta o valor máximo da árvore */

            case 10: {
                cout << "Valor maximo da arvore: " << arvoreBst.max(arvoreBst.getRaiz());
                break;
            }
            	
            	/** Imprime todas as folhas da árvore */
            
            case 11:{
            	if (arvoreBst.getRaiz() == nullptr) {
            		cout<< "\n A arvore esta vazia!";
            		break;
				} else{
						arvoreBst.folhas(arvoreBst.getRaiz());
				break;
				}
			}
			
			
			 /** Remove a folha */

            case 12: {
                int item;
                cout << "Valor a ser removido: ";
                cin >> item;
                bool resp = arvoreBst.removerFolha(item);
                if (resp)
                    cout << "\nElemento " << item << " removido com sucesso!";
                else
                    cout << "\nElemento não encontrado!";
                break;
            }

            default: {
                cout << "\n Opção invalida!";
                break;
            }
        }
    } while (opc != 0);
}
