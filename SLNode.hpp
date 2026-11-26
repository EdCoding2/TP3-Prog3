#pragma once

/// @brief Noeud simplement lié.
/// @tparam T Type de données.
template <typename T>
class SLNode{
    public:
        T data; ///< Donnée.
        SLNode<T>* right; ///< Noeud à droite.

        /// @brief Constructeur.
        /// @param data Donnée.
        /// @param right Noeud à droite.
        SLNode(T data, SLNode<T>* right){
            this->data = data;
            this->right = right;
        }
};
