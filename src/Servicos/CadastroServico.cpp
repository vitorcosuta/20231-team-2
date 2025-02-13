#include "Servicos/CadastroServico.hpp"

#include <string>
#include <iostream>

#include "cores.hpp"
#include "Usuario.hpp"
#include "Cliente.hpp"
#include "Restaurante.hpp"
#include "EntidadeBase.hpp"
#include "Utils/InputManager.hpp"
#include "Repositories/DatabaseManager.hpp"
#include "Repositories/ClienteRepositorio.hpp"
#include "Repositories/RestauranteRepositorio.hpp"

CadastroServico::CadastroServico(DatabaseManager *dbManager) {
  _clienteRepositorio = dbManager->GetClienteRepositorio();
  _restauranteRepositorio = dbManager->GetRestauranteRepositorio();
}

Usuario* CadastroServico::MenuCadastro()
{
    int opcao;
    std::cout << CIANO << "Escolha o tipo de cadastro! Pressione" << RESET <<std::endl;
    std::cout << "[0] Se você quiser sair" << std::endl;
    std::cout << "[1] Cliente" << std::endl;
    std::cout << "[2] Restaurante" << std::endl;
    std::cout << "Opção escolhida: ";
    opcao = InputManager::LerInt();
    
    std::string nome, login, senha, cpf, cnpj;

    switch (opcao) {
      case 0:
        break;     
      case 1:
        std::cout << "Digite o nome do cliente: ";
        nome = InputManager::LerString();
        std::cout << "Digite o CPF(11 digitos) do cliente: ";
        cpf = InputManager::LerDocumento(TipoUsuario::CLIENTE);
        std::cout << "Digite o login do cliente: ";
        login = InputManager::LerString();
        std::cout << "Digite a senha do cliente: ";
        senha = InputManager::LerString();
        return CadastrarCliente(nome, cpf, login, senha);
        break;
      case 2:
        std::cout << "Digite o nome do restaurante: ";
        nome = InputManager::LerString();
        std::cout << "Digite o CNPJ(14 digitos) do restaurante: ";
        cnpj = InputManager::LerDocumento(TipoUsuario::RESTAURANTE);
        std::cout << "Digite o login do restaurante: ";
        login = InputManager::LerString();
        std::cout << "Digite a senha do restaurante: ";
        senha = InputManager::LerString();
        return CadastrarRestaurante(nome, cnpj, login, senha);
        break;

      default:
        std::cout << VERMELHO << "Opção inválida." << RESET << std::endl;
        break; 
    }

    return nullptr;
}

Cliente* CadastroServico::CadastrarCliente(std::string& nome, std::string& cpf, std::string& login, std::string& senha) {
  Cliente* novoCliente = new Cliente(nome, login, senha, cpf);
  try {
    Carteira* novaCarteira = new Carteira(0);
    novoCliente->SetCarteira(novaCarteira);
    _clienteRepositorio->Inserir(novoCliente);
    std::cout << VERDE << "Cadastro realizado com sucesso!" << RESET << std::endl;
  } catch (std::exception& ex) {
    std::cout << "Erro ao cadastrar cliente: " << ex.what() << std::endl;
  }

  return novoCliente;
}

Restaurante* CadastroServico::CadastrarRestaurante(std::string& nome, std::string& cnpj, std::string& login, std::string& senha) {
  Restaurante* novoRestaurante = new Restaurante(nome, login, senha, cnpj);
  try {
    _restauranteRepositorio->Inserir(novoRestaurante);
    std::cout << VERDE << "Cadastro realizado com sucesso!" << RESET << std::endl;
  } catch (std::exception& ex) {
    std::cout << "Erro ao cadastrar Restaurante: " << ex.what() << std::endl;
  }

  return novoRestaurante;
}