# structures
## Infixe
-> File dynamique(stack)
contient les opérandes (infixe)

## Postfixe 
-> File dynamique(stack) 
contient les opérendes (postfixe)


## Opérateurs 
-> Pile dynamique (stack)
contient les opérateurs

# Début

1. coder les structures
2. IsOperator

# isOperator

#  Infixe à Postfixe:
(opérande: 2)
(Opérateur: +)

```c++
Queue<string>* postfix = new Queue<string>();
Pile<string>* pileOperateurs = new Pile<string>();

string devantInfix;

while (infixExpression->size() > 0) {

    devantInfix = infixExpression->front();

    // 1. Si c'est un opérande
    if (!isOperator(devantInfix)
        && devantInfix != "("
        && devantInfix != ")") {

        // Enfiler l'opérande dans postfix
        // Défiler infixExpression
    }

    // 2. Si c'est une parenthèse ouvrante
    else if (devantInfix == "(") {

        // Empiler "(" dans pileOperateurs
        // Défiler infixExpression
    }

    // 3. Si c'est une parenthèse fermante
    else if (devantInfix == ")") {

        while (pileOperateurs->size() > 0
               && pileOperateurs->top() != "(") {

            // Enfiler top de pileOperateurs dans postfix
            // Dépiler pileOperateurs
        }

        // Vérifier qu'une parenthèse ouvrante a été trouvée
        // Dépiler "(" de pileOperateurs
        // Défiler infixExpression
    }

    // 4. Si c'est un opérateur (+, -, *, /, %)
    else {

        while (pileOperateurs->size() > 0
               && pileOperateurs->top() != "("
               && getPriority(pileOperateurs->top())
                    >= getPriority(devantInfix)) {

            // Enfiler top de pileOperateurs dans postfix
            // Dépiler pileOperateurs
        }

        // Empiler devantInfix dans pileOperateurs
        // Défiler infixExpression
    }
}

// 5. Vider les opérateurs restants
while (pileOperateurs->size() > 0) {

    // Enfiler top de pileOperateurs dans postfix
    // Dépiler pileOperateurs
}
```
# postfixe à Résultat:

besoins:
pile d'opérandes
postfix

int resultat;

```c++
int postfixToResult(Queue<string>* postfixExpression){
    /// TODO: Implementation
    Pile<string>* pileOperandes = new Pile<string>();
    int resultat, n1, n2 = 0;

    while(postfixExpression->size() > 0){
        // tenir compte qu'on défilera postfix au fur et à mesure.

        if(!isOperator(postfixExpression->front())){
            // empiler 
            // défiler
            pileOperandes->push(postfixExpression->front());
            postfixExpression->pop();
        }

        if(isOperator(postfixExpression->front())){ // remplacer par un else
            n1 = stoi(pileOperandes);

            //savoir quel opérateur utiliser: ifs
        }
    }
}
```

# print
```c++
/// @brief Affichage d'une file.
/// @param queue File contenant les données à afficher.
void printQueue(Queue<string>* queue){
    
}
```