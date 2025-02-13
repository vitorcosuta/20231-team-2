#pragma once

#ifndef CUPOM_HPP
#define CUPOM_HPP

#include <string>
#include <sstream>
#include "EntidadeBase.hpp"

class impossivel_desconto_negativo_e {};
class impossivel_descricao_vazia_e {};

enum class CupomType{
    BASICO,
    CUSTOMIZADO
};

/**
 * @class Cupom
 * @brief Classe que representa um cupom de desconto.
 *
 * Essa classe representa um cupom que pode ser utilizado para fornecer descontos aos clientes em suas compras.
 */
class Cupom : public EntidadeBase {
protected:
    std::string _etiqueta; //Ex: NIVER15
    std::string _descricao;
    CupomType _tipo;
    double _valor_desconto;
    bool _valido;
    int _idDoCliente;

public:
    /**
     * @brief Construtor da classe Cupom.
     * @param codigo O código do cupom.
     * @param desconto O valor do desconto em porcentagem.
     * @param idDoCliente O id do cliente que tem esse cupom.
     */
    Cupom(std::string etiqueta, double desconto, int idDoCliente, CupomType tipo);

    /**
     * @brief Retorna o valor do desconto do cupom.
     * @return O valor do desconto em porcentagem.
     */
    double GetValor();

    /**
     * @brief Retorna a etiqueta do cupom.
     * @return A etiqueta do cupom.
     */
    std::string GetEtiqueta();

    /**
     * @brief Verifica se o cupom está válido.
     * @return true se o cupom estiver válido, false caso contrário.
     */
    bool EstaValido();

    /**
     * @brief Define o status do cupom como válido.
     */
    void SetaValido();

    /**
     * @brief REtorna o id do cliente.
     * @return O id do cliente.
     */
    int GetIdDoCliente();

    /**
     * @brief Acessa o tipo do cupom de desconto.
     * @return O tipo do cupom.
     */
    CupomType GetTipoCupom();

    /**
     * Retorna uma mensagem ou slogan descrevendo o cupom.
    */
    virtual std::string Descricao() = 0;
};

#endif // CUPOM_HPP
