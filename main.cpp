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
Queue<string>* infixToPostfix(Queue<string>* infixExpression) {

    Queue<string>* postfix = new Queue<string>();
    Pile<string>* pileOperateurs = new Pile<string>();
    string devantInfix;

    while (infixExpression->size() > 0) {
        devantInfix = infixExpression->front();

        if (!isOperator(devantInfix)) {
            postfix->push(devantInfix);
            infixExpression->pop();
        }

        else if (devantInfix == "(") {
            pileOperateurs->push(devantInfix);
            infixExpression->pop();
        }

        else if (devantInfix == ")") {
            while (pileOperateurs->size() > 0
                   && pileOperateurs->top() != "(") {

                postfix->push(pileOperateurs->top());
                pileOperateurs->pop();
            }

            if (pileOperateurs->size() > 0) {
                pileOperateurs->pop();
            }

            infixExpression->pop();
        }

        else {
            while (pileOperateurs->size() > 0
                   && pileOperateurs->top() != "("
                   && getPriority(pileOperateurs->top())
                      >= getPriority(devantInfix)) {

                postfix->push(pileOperateurs->top());
                pileOperateurs->pop();
            }
            pileOperateurs->push(devantInfix);
            infixExpression->pop();
        }
    }

    while (pileOperateurs->size() > 0) {
        postfix->push(pileOperateurs->top());
        pileOperateurs->pop();
    }

    delete pileOperateurs;

    return postfix;
}

/// @brief Évaluation d'une expression postfixe.
/// @param postfixExpression Expression postfixe.
/// @return Résultat de l'expression. 
int postfixToResult(Queue<string>* postfixExpression){
    Pile<string>* pileOperandes = new Pile<string>();
    int resultat, n1, n2 = 0;

    while(postfixExpression->size() > 0){
        
        if(!isOperator(postfixExpression->front())){
            pileOperandes->push(postfixExpression->front());
            postfixExpression->pop();
        } 
        else{
            n1 = stoi(pileOperandes->top());
            pileOperandes->pop();
            n2 = stoi(pileOperandes->top());
            pileOperandes->pop();

            if(postfixExpression->front() == "*"){
                resultat = n2 * n1;
                pileOperandes->push(to_string(resultat));
                postfixExpression->pop();
            }
            else if(postfixExpression->front() == "/"){
                resultat = n2 / n1;
                pileOperandes->push(to_string(resultat));
                postfixExpression->pop();
            } 
            else if(postfixExpression->front() == "%"){
                resultat = n2 % n1;
                pileOperandes->push(to_string(resultat));
                postfixExpression->pop();
            }
            else if(postfixExpression->front() == "+"){
                resultat = n2 + n1;
                pileOperandes->push(to_string(resultat));
                postfixExpression->pop();
            }
            else if(postfixExpression->front() == "-"){
                resultat = n2 - n1;
                pileOperandes->push(to_string(resultat));
                postfixExpression->pop();
            }
        }
    }
    delete pileOperandes;
    
    return resultat;
}

/// @brief Affichage d'une file.
/// @param queue File contenant les données à afficher.
void printQueue(Queue<string>* queue){

    for (int i = 0; i < queue->size(); i++){
        cout << queue->front() << " ";
        queue->push(queue->front());
        queue->pop();
    }
    
    cout << "" << endl;
}

/// @brief Fonction principale.
/// @param argc Nombre d'arguments.
/// @param argv Arguments.
/// @return Code de fin de programme.
int main(int argc, char* argv){
   
    Queue<string>* infixExpression = new Queue<string>();

    infixExpression->push("100");
    infixExpression->push("/");
    infixExpression->push("(");
    infixExpression->push("2");
    infixExpression->push("+");
    infixExpression->push("3");
    infixExpression->push(")");
    infixExpression->push("-");
    infixExpression->push("7");
    infixExpression->push("%");
    infixExpression->push("4");
    infixExpression->push("-");
    infixExpression->push("1");
    
    cout << "Infixe : ";
    printQueue(infixExpression);

    Queue<string>* postfixExpression = infixToPostfix(infixExpression);

    cout << "Postfixe : ";
    printQueue(postfixExpression);

    cout << "Evaluation : " << postfixToResult(postfixExpression) << endl;

    delete infixExpression;
    delete postfixExpression;
    
    return 0;
}
