#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){

    cout << "Seja bem vindo ao Bingo" >>;
}
class BingoJogo {
private:
    int maxNumbers;
    vector<int> drawnNumbers;
    bool isAutoMode;

public:
    BingoGame(int maxNum) : maxNumbers(maxNum), isAutoMode(false) {
        // Inicializar a semente para números aleatórios
        srand(static_cast<unsigned int>(time(nullptr)));
    }

    void startGame() {
        cout << "Bem-vindo ao Jogo de Bingo Eletrônico!" << endl;
        cout << "Escolha o tipo de bingo (75, 90, 100): ";
        int bingoType;
        cin >> bingoType;

        if (bingoType != 75 && bingoType != 90 && bingoType != 100) {
            cout << "Tipo de bingo inválido. Saindo do jogo." << endl;
            return;
        }

        maxNumbers = bingoType;

        cout << "Quantos cartões você deseja gerar? ";
        int numCards;
        cin >> numCards;

        generateCards(numCards);

        cout << "Escolha o modo de sorteio (0 para automático, 1 para manual): ";
        int mode;
        cin >> mode;

        isAutoMode = (mode == 0);

        playGame();
    }

    void generateCards(int numCards) {
        for (int i = 1; i <= numCards; ++i) {
            string filename = "card" + to_string(i) + ".txt";
            ofstream outFile(filename);

            if (!outFile.is_open()) {
                cerr << "Erro ao criar arquivo para o cartão " << i << endl;
                continue;
            }

            vector<int> cardNumbers;
            generateUniqueNumbers(cardNumbers, 1, maxNumbers, 25); // Gera 25 números únicos para cada cartão

            for (int j = 0; j < 25; ++j) {
                outFile << cardNumbers[j] << "\t";
                if ((j + 1) % 5 == 0) {
                    outFile << endl;
                }
            }

            outFile.close();

            cout << "Cartão " << i << " gerado com sucesso. (" << filename << ")" << endl;
        }
    }

    void playGame() {
        cout << "Pressione Enter para começar o sorteio..." << endl;
        cin.ignore(); // Ignorar a quebra de linha pendente
        cin.get();

        while (true) {
            if (isAutoMode) {
                drawNumberAuto();
            } else {
                drawNumberManual();
            }

            displayDrawnNumbers();
        }
    }

    void drawNumberAuto() {
        int number;
        do {
            number = rand() % maxNumbers + 1;
        } while (find(drawnNumbers.begin(), drawnNumbers.end(), number) != drawnNumbers.end());

        drawnNumbers.push_back(number);
    }

    void drawNumberManual() {
        int number;
        cout << "Pressione Enter para sortear um novo número...";
        cin.ignore(); // Ignorar a quebra de linha pendente
        cin.get();

        do {
            number = rand() % maxNumbers + 1;
        } while (find(drawnNumbers.begin(), drawnNumbers.end(), number) != drawnNumbers.end());

        drawnNumbers.push_back(number);
    }

    void displayDrawnNumbers() {
        system("clear || cls"); // Limpar a tela (compatível com sistemas Unix e Windows)

        if (drawnNumbers.size() >= 2) {
            cout << "Número Sorteado: " << drawnNumbers.back() << endl;
            cout << "Anterior: " << drawnNumbers[drawnNumbers.size() - 2] << endl;
        } else if (!drawnNumbers.empty()) {
            cout << "Número Sorteado: " << drawnNumbers.back() << endl;
            cout << "Anterior: N/A" << endl;
        } else {
            cout << "Números Sorteados: N/A" << endl;
        }

        cout << "----- Números Sorteados Ordenados -----" << endl;
        sort(drawnNumbers.begin(), drawnNumbers.end());

        for (int number : drawnNumbers) {
            cout << number << "\t";
        }

        cout << endl;
    }
};

int main() {
    BingoGame game(75); // Inicializar com um máximo de 75 números por padrão
    game.startGame();

    return 0;
}