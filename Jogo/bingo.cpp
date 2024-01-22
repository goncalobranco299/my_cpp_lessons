#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include <algorithm>
#include <limits>
#include <chrono>

using namespace std;

// Função para imprimir o texto em vermelho
void printRedText(const string& text) {
    cout << "\033[1;31m" << text << "\033[0m";
}

int main() {
    int escolha;
    int maximo;
    vector<int> numeros;

    cout << "1: Sorteio Manual!\n";
    cout << "2: Sorteio automático\n";
    cout << "3: Gerar Cartões\n";
    cout << "4: Sair\n";
    cout << "Escolha uma opção: ";
    cin >> escolha;

    if (escolha != 1 && escolha != 2 && escolha != 3 && escolha != 4) {
        cout << "Opção inválida. Escolha 1, 2, 3 ou 4.\n";
        return 1;
    }
    if (escolha != 4) {
    cout << "Escolha o número máximo (75, 90 ou 100): ";
    cin >> maximo;

    if (maximo != 75 && maximo != 90 && maximo != 100) {
        cout << "Opção inválida. Escolha 75, 90 ou 100.\n";
        return 1;
    }

            // Limpar o buffer de entrada
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (escolha) {
        case 1: {
            // Sorteio Manual
            auto seed = static_cast<unsigned>(chrono::system_clock::now().time_since_epoch().count());
            mt19937 gerador(seed);
            uniform_int_distribution<int> distribuicao(1, maximo);

            while (numeros.size() < 14) {
                int numeroAleatorio = distribuicao(gerador);

                // Verifica se o número já foi incluído
                if (find(numeros.begin(), numeros.end(), numeroAleatorio) == numeros.end()) {
                    printRedText(to_string(numeroAleatorio));
                    cout << "\nPressione Enter para sortear a próxima bola.\n";
                    cin.get(); // Aguarda a entrada do usuário

                    numeros.push_back(numeroAleatorio);
                }
            }
            break;
            }
            case 2: {
                // Sorteio automático
                // Adicione o código para Sorteio automático aqui
                break;
            }
            case 3: {
                // Gerar Cartões - Adicione o código para Gerar Cartões aqui
                cout << "Funcionalidade ainda não implementada.\n";
                break;
            }
            case 4:
                cout << "Saindo do programa.\n";
                return 0;
        }
    }

    // Restante do código permanece igual...

    return 0;
}
