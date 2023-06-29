#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct Mes {
    int mes;
    int chamadosRecebidos;
    int chamadosAtendidos;
};

// Função para registrar os chamados recebidos e atendidos em um determinado mês

void registrarChamados(vector<Mes>& registros) {
    Mes novoMes;
    cout << "Informe o numero do mes (de 1 a 12): ";
    cin >> novoMes.mes;
    cout << "Informe o numero de chamados recebidos: ";
    cin >> novoMes.chamadosRecebidos;
    cout << "Informe o numero de chamados atendidos: ";
    cin >> novoMes.chamadosAtendidos;
    registros.push_back(novoMes);
}

// Função para exibir os chamados recebidos e atendidos

void exibirChamados(const vector<Mes>& registros, int mesSelecionado) {
    cout << "Mes\tChamados Recebidos\tChamados Atendidos" << endl;
    for (int i = 0; i < registros.size(); ++i) {
        const Mes& registro = registros[i];
        if (mesSelecionado == -1 || registro.mes == mesSelecionado) {
            cout << setw(3) << registro.mes << "\t";
            cout << setw(18) << registro.chamadosRecebidos << "\t";
            cout << setw(18) << registro.chamadosAtendidos << endl;
        }
    }
}

int main() {
    vector<Mes> registros;
    int opcao;
    
    do {
        cout << "Opcoes:" << endl;
        cout << "1. Registro de chamados recebidos e atendidos" << endl;
        cout << "2. Exibir chamados recebidos e atendidos" << endl;
        cout << "0. Encerrar o programa" << endl;
        cout << "Digite a opcao desejada: ";
        cin >> opcao;
        
        switch (opcao) {
            case 1:
                registrarChamados(registros);
                break;
            case 2:
                char mesSelecionado;
                cout << "Digite 0 para ver todos os meses ou um numero de 1 a 12 para um mes especifico: ";
                cin >> mesSelecionado;
                exibirChamados(registros, (mesSelecionado == '0' ? -1 : mesSelecionado - '0'));
                break;
            case 0:
                cout << "Encerrando o programa." << endl;
                break;
            default:
                cout << "Opcao invalida." << endl;
                break;
        }
        
        cout << endl;
    } while (opcao != 0);
    
    return 0;
}

