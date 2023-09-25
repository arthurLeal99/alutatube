#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definimos a classe Contato
class Contato {
public:
  string nome;
  string telefone;
  string email;
  string endereco;

  // Construtor para inicializar o nome e telefone do contato
  Contato(string nome, string telefone, string email, string endereco)
      : nome(nome), telefone(telefone), email(email), endereco(endereco) {}
};

// Função para exibir um menu
int mostrarMenu() {
  int escolha;
  cout << "\nMenu:\n";
  cout << "1. Adicionar Contato\n";
  cout << "2. Excluir Contato\n";
  cout << "3. Editar Contato\n";
  cout << "4. Inspecionar Contato\n";
  cout << "5. Listar Contatos\n";
  cout << "6. Sair\n";
  cout << "Escolha uma opção: ";
  cin >> escolha;
  return escolha;
}

int main() {
  vector<Contato>
      listaDeContatos; // Uma lista de contatos simples usando um vetor

  while (true) {
    int escolha = mostrarMenu();

    // Adicionar Contato
    if (escolha == 1) {
      string nome, telefone, email, endereco;
      cout << "Nome do contato: ";
      cin >> nome;
      cout << "Número do contato: ";
      cin >> telefone;
      cout << "Email do contato: ";
      cin >> email;
      cout << "Endereço do contato: ";
      cin >> endereco;
      listaDeContatos.push_back(Contato(nome, telefone, email, endereco));
      cout << "Contato adicionado com sucesso!\n";
    }
    // Apagar contato
    else if (escolha == 2) {
      if (listaDeContatos.empty()) {
        cout << "A lista não tem contatos salvos\n";
      } else {
        string nome;
        cout << "Digite o nome do contato que deseja excluír: ";
        cin >> nome;

        bool encontrado = false;
        for (auto it = listaDeContatos.begin(); it != listaDeContatos.end();
             ++it) {
          if (it->nome == nome) {
            it = listaDeContatos.erase(it);
            encontrado = true;
            cout << "Contato excluído com sucesso!\n";
            break;
          }
        }

        if (!encontrado) {
          cout << "Contato não encontrado.\n";
        }
      }
    }
    // Editar Contato
    else if (escolha == 3) {
      if (listaDeContatos.empty()) {
        cout << "A lista não tem contatos salvos\n";
      } else {
        string nome, novoTelefone, novoNome, novoEmail, novoEnde;
        cout << "Digite o nome do contato a ser editado: ";
        cin >> nome;

        bool encontrado = false;
        for (auto &contato : listaDeContatos) {
          if (contato.nome == nome) {
            cout << "Novo nome: ";
            cin >> novoNome;
            contato.nome = novoNome;
            cout << "Novo telefone: ";
            cin >> novoTelefone;
            contato.telefone = novoTelefone;
            cout << "Novo Email: ";
            cin >> novoEmail;
            contato.email = novoEmail;
            cout << "Novo Endereço: ";
            cin >> novoEnde;
            contato.endereco = novoEnde;
            encontrado = true;
            cout << "Contato editado com sucesso!\n";
            break;
          }
        }

        if (!encontrado) {
          cout << "Contato não encontrado.\n";
        }
      }
    }
    // Inspecionar contato
    else if (escolha == 4) {
      if (listaDeContatos.empty()) {
        cout << "A lista não tem contatos salvos\n";
      } else {
        string nome;
        cout << "Digite o nome do contato que deseja inspecionar: ";
        cin >> nome;

        bool encontrado = false;
        for (const Contato &contato : listaDeContatos) {
          if (contato.nome == nome) {
            encontrado = true;
            cout << "\nDetalhes do Contato:\n";
            cout << "Nome:" << contato.nome << "\n";
            cout << "Número: " << contato.telefone << "\n";
            cout << "Email: " << contato.email << "\n";
            cout << "Endereço: " << contato.endereco << "\n";
          }
        }
      }
    }
    // Ver todos os contatos
    else if (escolha == 5) {
      if (listaDeContatos.empty()) {
        cout << "A lista de contatos está vazia.\n";
      } else {
        cout << "\nLista de Contatos:\n";
        for (const Contato &contato : listaDeContatos) {
          cout << "Nome: " << contato.nome << ", Telefone: " << contato.telefone
               << endl;
        }
      }
    }
    // Encerrar o programa
    else if (escolha == 6) {
      break;
    } else {
      cout << "Opção inválida. Tente novamente.\n";
    }
  }

  return 0;
}