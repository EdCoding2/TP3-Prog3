#include <stdexcept>
#include "SLNode.hpp"

/// @brief Pile dynamique
/// @tparam T Type de donnée.
template <typename T>
class Pile{
public:
    /// @brief Constructeur
    Pile(){
        first = nullptr;
        count = 0;
    }
    /// @brief Destructeur.
    ~Pile(){
        while(first)
            pop();
    }
    /// @brief Empiler
    /// @param data Donnée à empiler.
    void push(T data){
        first = new SLNode<T>(data, first);
        ++count;
    }

    /// @brief Dépiler.
    void pop(){
        if(!first)
            throw std::length_error("Pile vide!");    
        
        SLNode<T>* toDelete = first;
        first = toDelete->right;
        delete toDelete;
        --count;
    }

    /// @brief Sommet de la pile.
    /// @return Donnée au sommet de la pile.
    T top(){
        if(first)
            return first->data;
        throw std::length_error("Pile vide!");
    }

    /// @brief Compte.
    /// @return Nombre de données.
    size_t size(){
        return count;
    }
private:
    SLNode<T>* first; ///< Premier Noeud.
    size_t count;  ///< Nombre de données.
};