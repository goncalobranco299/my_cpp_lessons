#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <windows.h>

using namespace std;

int main() {
    int escolha;
    int opcao;
    int qtdSair = 0;
    cout << "Escolha a opção:\n";
    cout << "1: Sorteio Manual!\n";
    cout << "2: Sorteio automático\n";
    cout << "3: Gerar Cartões\n";
    cout << "4: Sair\n";

    cin >> escolha;

    if (escolha == 2) {
        int maximo;

        // Solicitar ao usuário que escolha um número máximo
        cout << "Escolha o número máximo (75, 90 ou 100): ";
        cin >> maximo;

        // Verificar se o número máximo está dentro das opções permitidas
        if (maximo != 75 && maximo != 90 && maximo != 100) {
            cout << "Opção inválida. Escolha 75, 90 ou 100.\n";
            return 1; // Saída com código de erro
        }

        random_device rd;
        mt19937 gerador(rd());
        uniform_int_distribution<int> distribuicao(1, maximo);

        vector<int> numeros;

        while (numeros.size() < maximo) {
            int numeroAleatorio = distribuicao(gerador);

            // Verificar se o número já foi gerado antes de adicioná-lo
            if (find(numeros.begin(), numeros.end(), numeroAleatorio) == numeros.end()) {
                numeros.push_back(numeroAleatorio);
            }
        }

        // Ordenar o vetor de números
        sort(numeros.begin(), numeros.end());

        // Array para armazenar os números lançados
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
            system("cls"); // Comando para limpar o console em sistemas Windows
            #else
            system("clear"); // Comando para limpar o console em sistemas Unix/Linux
            #endif

            // Adicionar o número sorteado ao array de números lançados
            numerosLancados.push_back(numeroSorteado);
            // Exibir os números ordenados novamente
            cout << "\033[1;34m";
            cout << setw(espacosAntes) << "" << "PAINEL - BINGO" << endl;
            cout << setw(espacosAntes) << "" << "SORTEIO COM " << maximo << " BOLAS" << endl;
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            cout << "\033[0m";

            // Exibir os números ordenados novamente, marcando os lançados em vermelho
            for (int j = 0; j < maximo; ++j) {
                // Verificar se o número atual está no array de números lançados
                if (find(numerosLancados.begin(), numerosLancados.end(), numeros[j]) != numerosLancados.end()) {
                    // Definir cor do texto para vermelho brilhante (código ANSI)
                    cout << "\033[1;31m";
                } else {
                    // Definir cor do texto para azul (código ANSI)
                    cout << "\033[1;34m";
                }

                cout << setw(4) << numeros[j];

                // Restaurar cor original do texto (código ANSI)
                cout << "\033[0m";

                if ((j + 1) % 20 == 0) {
                    cout << "\n";
                } else {
                    cout << " "; // Adiciona um espaço entre os números
                }
            }

            cout << "\033[1;34m";
            cout << " " << endl;
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            cout << "\033[0m";
            cout << endl << endl;
            cout << "Sorteado anterior: " << numeroAnterior << endl;
            cout << "Sorteado " << i + 1 << ": " << numeroSorteado << endl;

            numeroAnterior = numeroSorteado;
            #ifdef _WIN32
            Sleep(1000); // Atraso de 1000 milissegundos (1 segundo) em sistemas Windows
            #else
            sleep(1);    // Atraso de 1 segundo em sistemas Unix/Linux
            #endif
        }
    } else if (escolha == 2) {
        // Implementar Sorteio automático
        // ...
    } else if (escolha == 3) {
  // Abrir um arquivo para escrita
    ofstream arquivo("numeros.txt");

    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo.\n";
        return 1; // Saída com código de erro
    }

    // Gerar 10 números aleatórios e gravar no arquivo
    for (int i = 0; i < qtdSair; ++i) {
        int numeroAleatorio = rand() % 100; // Números aleatórios entre 0 e 99

        // Gravar o número no arquivo
        arquivo << numeroAleatorio << " ";
    }

    // Fechar o arquivo
    arquivo.close();

    cout << "Números foram escritos no arquivo com sucesso.\n";

    return 0;
    } else if (escolha == 4) {
        // Implementar Sair
        return 0;
    } else {
        cout << "Opção inválida.\n";
        return 1; // Saída com código de erro
    }

    return 0;
}
