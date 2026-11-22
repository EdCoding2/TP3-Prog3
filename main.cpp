#include <string>
#include "Queue.hpp"
#include "Pile.hpp"

using namespace std;
/// @brief Validation d'un opérateur.
/// @param term Terme à valider
/// @return Vrai si le terme est un opérateur, faux si c'est une parenthèse.
bool isOperator(string term){
    /// TODO: Implementation
}

/// @brief Priorité d'un opérateur.
/// @param operateur Opérateur duquel obtenir la priorité.
/// @return Priorité de l'opérateur.
unsigned char getPriority(string operateur){
    /// TODO: Implementation
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


    /// TODO: Implémentation.
    return 0;
}