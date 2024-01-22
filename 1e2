#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <windows.h>
#include <iomanip>  // Para setw
#include <unistd.h>

using namespace std;

int main() {
    int escolha;
    int qtdSair = 0;

    cout << "Escolha a opcao:\n";
    cout << "1: Sorteio Manual!\n";
    cout << "2: Sorteio automático\n";
    cout << "3: Gerar Cartões\n";
    cout << "4: Sair\n";
    cin >> escolha;

    // Criando um motor de geração de números aleatórios
    mt19937 gerador(random_device{}());

    if (escolha == 1) {
        int maximo;

        cout << "Escolha o numero máximo (75, 90 ou 100): ";
        cin >> maximo;

        if (maximo != 75 && maximo != 90 && maximo != 100) {
            cout << "Opção inválida. Escolha 75, 90 ou 100.\n";
            return 1;
        }

        vector<int> numeros;
        for (int i = 1; i <= maximo; ++i) {
            numeros.push_back(i);
        }

        vector<int> numerosLancados;
        int numeroAnterior = 0;

        if (maximo == 75) {
            qtdSair = 4;
        } else if (maximo == 100) {
            qtdSair = 25;
        } else if (maximo == 90) {
            qtdSair = 14;
        }

        cin.ignore();

        uniform_int_distribution<> distribuicao(0, maximo - 1);

        for (int i = 0; i < qtdSair; ++i) {
            int larguraDoConsole = 80;
            int espacosAntes = (larguraDoConsole - ("SORTEIO COM " + to_string(maximo) + " BOLAS").length()) / 2;
            int indiceSorteado;
            do {
                indiceSorteado = distribuicao(gerador);
            } while (find(numerosLancados.begin(), numerosLancados.end(), numeros[indiceSorteado]) != numerosLancados.end());

            int numeroSorteado = numeros[indiceSorteado];
            #ifdef _WIN32
            system("cls");
            #else
            system("clear");
            #endif

            cout << "\033[1;34m";
            cout << setw(espacosAntes) << "" << "PAINEL - BINGO" << endl;
            cout << setw(espacosAntes) << "" << "SORTEIO COM " << maximo << " BOLAS" << endl;
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            cout << "\033[0m";

             for (int j = 0; j < maximo; ++j) {
                if (find(numerosLancados.begin(), numerosLancados.end(), numeros[j]) != numerosLancados.end()) {
                        cout << "\033[1;31m";
                    cout << setw(4) << numeros[j];
                } else {
                    cout << "\033[1;34m";
                    cout << setw(4) << numeros[j];
                }

                if ((j + 1) % 20 == 0) {
                    cout << "\n";
                } else {
                    cout << " ";
                }
            }

            cout << "\033[1;34m";
            cout << " " << endl;
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            cout << "\033[0m";
            cout << endl << endl;
            cout << "\033[1;34m"; // Inicia a cor azul
            cout << "Sorteado anterior: ";
            cout << "\033[1;31m" << numeroAnterior << "\033[0m"; // Exibe 'numeroAnterior' em vermelho e depois reseta a cor
            cout << endl;
            cout << "\033[1;34m"; // Inicia a cor azul
            cout << "Sorteado " << i + 1 << ": ";
            cout << "\033[1;31m" << numeroSorteado << "\033[0m"; // Exibe 'numeroSorteado' em vermelho e depois reseta a cor
            cout << endl;

            numeroAnterior = numeroSorteado;

            cout << "\033[1;34m";
            cout << "Pressione Enter para sortear o proximo numero...\n";
            cout << "\033[0m";
            cin.ignore();

            numerosLancados.push_back(numeroSorteado);
        }

        cout << "Pressione Enter para encerrar o programa...\n";
        cin.ignore();
    } else if (escolha == 2) {
        int maximo;

        cout << "Escolha o número máximo (75, 90 ou 100): ";
        cin >> maximo;

        if (maximo != 75 && maximo != 90 && maximo != 100) {
            cout << "Opção inválida. Escolha 75, 90 ou 100.\n";
            return 1;
        }

        uniform_int_distribution<> distribuicao(1, maximo);

        vector<int> numeros;
        while (numeros.size() < maximo) {
            int numeroAleatorio = distribuicao(gerador);
            if (find(numeros.begin(), numeros.end(), numeroAleatorio) == numeros.end()) {
                numeros.push_back(numeroAleatorio);
            }
        }

        sort(numeros.begin(), numeros.end());

        vector<int> numerosLancados;
        int numeroAnterior = 0;

        if (maximo == 75) {
            qtdSair = 4;
        } else if (maximo == 100) {
            qtdSair = 25;
        } else if (maximo == 90) {
            qtdSair = 14;
        }

        for (int i = 0; i < qtdSair; ++i) {
            int numeroSorteado = distribuicao(gerador);
            int larguraDoConsole = 80;
            int espacosAntes = (larguraDoConsole - ("SORTEIO COM " + to_string(maximo) + " BOLAS").length()) / 2;

            #ifdef _WIN32
            system("cls");
            #else
            system("clear");
            #endif

            numerosLancados.push_back(numeroSorteado);
            cout << "\033[1;34m";
            cout << setw(espacosAntes) << "" << "PAINEL - BINGO" << endl;
            cout << setw(espacosAntes) << "" << "SORTEIO COM " << maximo << " BOLAS" << endl;
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            cout << "\033[0m";
            for (int j = 0; j < maximo; ++j) {
                if (find(numerosLancados.begin(), numerosLancados.end(), numeros[j]) != numerosLancados.end()) {
                        cout << "\033[1;31m";
                    cout << setw(4) << numeros[j];
                } else {
                    cout << "\033[1;34m";
                    cout << setw(4) << numeros[j];
                }

                if ((j + 1) % 20 == 0) {
                    cout << "\n";
                } else {
                    cout << " ";
                }
            }

            cout << " " << endl;
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            cout << endl << endl;
            cout << "\033[1;34m"; // Inicia a cor azul
            cout << "Sorteado anterior: ";
            cout << "\033[1;31m" << numeroAnterior << "\033[0m"; // Exibe 'numeroAnterior' em vermelho e depois reseta a cor
            cout << endl;
            cout << "\033[1;34m"; // Inicia a cor azul
            cout << "Sorteado " << i + 1 << ": ";
            cout << "\033[1;31m" << numeroSorteado << "\033[0m"; // Exibe 'numeroSorteado' em vermelho e depois reseta a cor
            cout << endl;

            numeroAnterior = numeroSorteado;
            #ifdef _WIN32
            Sleep(1000);
            #else
            sleep(1);
            #endif
        }
    } else if (escolha == 3) {
        // Gerar Cartões
        // ...
    } else if (escolha == 4) {
        // Sair
        return 0;
    } else {
        cout << "Opção inválida.\n";
        return 1;
    }

    return 0;
}
