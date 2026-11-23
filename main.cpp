#include <string>
#include <iostream>
#include "Queue.hpp"
#include "Pile.hpp"

using namespace std;
using std::string;

/// @brief Validation d'un opérateur.
/// @param term Terme à valider
/// @return Si le terme est un opérateur ou une parenthèse.
bool isOperator(string term){
    if (term == "*" || term == "/" ||
        term == "%" || term == "+" || 
        term == "-" || term == "(" || term == ")")
        return true;
    
    return false;
}

/// @brief Priorité d'un opérateur.
/// @param operateur Opérateur duquel obtenir la priorité.
/// @return Priorité de l'opérateur.
unsigned char getPriority(string operateur){
    if (operateur == "*" || operateur == "/" || operateur == "%")
        return 2;
    else if (operateur == "+" || operateur == "-") 
        return 1;
    else if (operateur == "(" || operateur == ")")
        return 0;
    return -1;
}

/// @brief Création d'une expression postfixe à partir d'une expression infixe.
/// @param infixExpression Expression infixe/
/// @return Expression postfixe.
Queue<string>* infixToPostfix(Queue<string>* infixExpression){
    /// TODO: Implementation
}

/// @brief Évaluation d'une expression postfixe.
/// @param postfixExpression Expression postfixe.
/// @return Résultat de l'expression. 
int postfixToResult(Queue<string>* postfixExpression){
    /// TODO: Implementation
}

/// @brief Affichage d'une file.
/// @param queue File contenant les données à afficher.
void printQueue(Queue<string>* queue){
    /// TODO: Implementation
}

/// @brief Fonction principale.
/// @param argc Nombre d'arguments.
/// @param argv Arguments.
/// @return Code de fin de programme.
int main(int argc, char* argv){

    Queue<string>* infixExpression = new Queue<string>();

    infixExpression->push_back("100");
    infixExpression->push_back("/");
    infixExpression->push_back("(");
    infixExpression->push_back("2");
    infixExpression->push_back("+");
    infixExpression->push_back("3");
    infixExpression->push_back(")");
    infixExpression->push_back("-");
    infixExpression->push_back("7");
    infixExpression->push_back("%");
    infixExpression->push_back("4");
    infixExpression->push_back("-");
    infixExpression->push_back("1");
    

    /// TODO: Implémentation.
    return 0;
}
