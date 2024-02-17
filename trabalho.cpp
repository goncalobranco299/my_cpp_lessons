#include <iostream>

using namespace std;

int a;
int b;
const float PI = 3.14159;
float r;
float area;
float notas[5];
float maior;
float menor;
int soma;
float media;
int numeros[10];
int tabuada;
int main()
{

    cout << "Insira o primeiro numero: ";
    cin >> a;

    cout << "Insira o segundo numero: ";
    cin >> b;

    cout << "Soma: " << a + b << endl; // Soma

    cout << "Diferenca: " << a - b << endl; // Diferença

    cout << "Multiplicao: " << a * b << endl; // Multiplicação

    cout << "Divisao: " << a / b << endl; // Divisão

    cout << "Resto da divisao: " << a % b << endl; // Resto da divisão

    cout << "Digite um valor do raio r: "; // Leitura do raio
    cin >> r;

    area = PI * r * r;
    cout << "O valor da area do circulo: " << area << endl;

    cout << "Nota do primeiro aluno: ";
    cin >> notas[0];

    cout << "Nota do segundo aluno: ";
    cin >> notas[1];

    cout << "Nota do terceiro aluno: ";
    cin >> notas[2];

    cout << "Nota do quarto aluno: ";
    cin >> notas[3];

    cout << "Nota do quinto aluno: ";
    cin >> notas[4];

    maior = notas[0];
    for (int i = 1; i < 5; i++)
    {
        // Se o elemento atual for maior que a variável "maior"
        // atualiza "maior" com o valor do elemento.
        if (notas[i] > maior)
        {
            maior = notas[i];
        }
    }

    menor = notas[0];
    for (int i = 1; i < 5; i++)
    {
        // Se o elemento atual for maior que a variável "menor",
        // atualiza "menor" com o valor do elemento.
        if (notas[i] < menor)
        {
            menor = notas[i];
        }
    }

    for (int i = 1; i < 5; i++)
    {
        soma += notas[i];
    }

    for (int i = 0; i < 5; i++)
    {
        media += notas[i];
    }

    media /= 5;

    cout << "A maior nota e: " << maior << endl;
    cout << "A menor nota e: " << menor << endl;
    cout << "A media nota e: " << media << endl;

    // Lendo os valores para o array
    for (int i = 0; i < 10; i++)
    {
        cout << "Digite o valor para o elemento " << i + 1 << ": ";
        cin >> numeros[i];
    }

    // Encontrar o maior elemento do array
    maior = numeros[0];
    for (int i = 1; i < 10; i++)
    {
        if (numeros[i] > maior)
        {
            maior = numeros[i];
        }
    }

    // Encontrar o menor elemento do array
    menor = numeros[0];
    for (int i = 1; i < 10; i++)
    {
        if (numeros[i] < menor)
        {
            menor = numeros[i];
        }
    }

    cout << "O maior elemento do array e: " << maior << endl;
    cout << "O menor elemento do array e: " << menor << endl;

    cout << "Insira o numero para fazer a tabuada: ";
    cin >> tabuada;

    for (int i = 1; i <= 10; i++)
    {
        cout << i << "x" << tabuada << "=" << tabuada * i << endl;
    }

    return 0;
}
