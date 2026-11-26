# Priorité d'opérations
Une expression arithmétique est composée d'opérandes et d'opérateurs exprimés de façon infixe. Mais pour évaluer une expression arithmétique, la priorité des opérations doit être respectée.

## 1. Priorités

1. * / et %
2. + et -
3. ( et )

## 2.Infixe à postfixe:
Les programmes informatiques, dont les compilateurs, sont confrontés à l'évaluation d'expressions arithmétiques. Afin de simplifier la tâche, les expressions sont d'abord exprimées de façon postfixe :

1. Un opérande est directement ajouté à la file postfixe.
2. Une parenthèse ouvrante est empilée sur la pile d'opérateurs.
3. Une parenthèse fermante dépile les opérateurs, dans la file postfixe, jusqu'à une parenthèse ouvrante. La parenthèse ouvrante est aussi dépilée, mais pas enfilée dans la file postfixe.
4. Un opérateur est empilé sur la pile d'opérateurs après en avoir dépilé, dans la file postfixe, ceux ayant une priorité supérieure ou égale à celui-ci.
5. Lorsque la file infixe est vide, dépiler, dans la file postfixe, jusqu'à ce que la pile d'opérateurs soit vide.

## 3. Postfixe au résultat
Les expressions postfixes permettent d'évaluer le résultat en respectant les priorités des opérateurs :

1. Un opérande est directement empilé dans la pile d'opérandes.
2. Un opérateur est appliqué aux deux opérandes dépilés et le résultat empilé.
3. Suite à l'évaluation, le sommet de la pile contiendra le résultat.

## 4. Implémentation

Le projet devra inclure les classes pour utiliser des piles et des files dynamiques et implémenter les fonctions suivantes pour résoudre une expression infixe déclarée manuellement dans la fonction principale :


## 5. Résultat
Le programme doit afficher les résultats sous la forme suivante :

Infixe : 100 / ( 2 + 3 ) - 7 % 4 - 1
Postfixe : 100 2 3 + / 7 4 % - 1 -
Évaluation : 16

La fonction « printQueue » doit laisser le contenu de la file intact, et en faire une copie n'est pas une façon efficace de faire.


# Règles

1. * Les expressions utilisées seront toujours valides.
2. ** Les opérandes de l'expression de départ ainsi que son résultat seront toujours entiers.
3. * Des points seront retirés pour toute documentation manquante.
4. ** Des points seront retirés pour tout non-respect des normes de programmation.
5. *** Les structures de données ne doivent pas contenir de méthodes supplémentaires.
6. **** Des points seront retirés pour toute utilisation de notion non présente dans les résumés.

