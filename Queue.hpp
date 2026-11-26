#include <stdexcept>
#include "SLNode.hpp"
#include "SLNode.hpp"

/// @brief Queue dynamique.
/// @tparam T Type de donnée.
template <typename T>
class Queue{
public:
    /// @brief Constructeur.
    Queue(){
        last = nullptr;
        count = 0;
    }

    /// @brief Destructeur.
    ~Queue(){
        while(last)
            pop();
    }

    /// @brief Enfiler.
	/// @param data Donnée à ajouter à l'arrière de la file
    void push(T data){
        if(last){
            last->right = new SLNode<T>(data, last->right);
            last = last->right;
        }
        else{
            last = new SLNode<T>(data, nullptr);
            last->right = last;
            last->right = last;
        }
        ++count;
    }
    
    /// @brief Défiler.
    void pop(){
        if(!last)
            throw std::length_error("File vide!");

        SLNode<T>* toDelete = last->right;   // le devant

        if(toDelete == last)                 // un seul élément
            last = nullptr;
        else
            last->right = toDelete->right;   // last pointe sur le nouveau devant

        delete toDelete;
        --count;
    }

    /// @brief Premier élément.
	/// @return Donnée à l'avant de la file.
    T front(){
        if(last)
            return last->right->data;
        throw::length_error("File vide!");
    }
    
    /// @brief Dernier élément.
    /// @return Donnée en arrière de la file. 
    T back(){
        if(last)
            return last->data;
        throw::length_error("File vide!")
    }
    
    /// @brief Compte
	/// @return Nombre de données dans la file
    size_t size(){
        return count;
    }

private:
    SLNode<T>* last; ///< Dernier Noeud.
    size_t count; ///< Nombre de données
};
