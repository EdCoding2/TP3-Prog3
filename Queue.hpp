#include <stdexcept>

template <typename T>
class Queue{
public:
    Dequeue(){
        last = nullptr;
        count = 0;
    }

    ~Dequeue(){
        while(last)
            pop_back();
    }

    /// @brief Enfiler au derrière.
	/// @param data Donnée à ajouter à l'arrière de la file
    void push_back(T data){
        if(last){
            last->right = new SLNode<T>(data, last->right);
            last = last->right;
        }
        else{
            last = new SLNode<T>(data, nullptr);
            last-right = last;
        }
        ++count;
    }
    
    // /// @brief Enfiler au devant.
    // /// @param data Donnée à enfiler.
    // void push_front(T data){
    //     if(last){
    //         last->right = new SLNode<T>(data, last->right);
    //     }
    //     else{
    //         last = new SLNode<T>(data, nullptr);
    //         last->right = last;
    //     }
    //     ++count;
    // }

    void pop_front(){
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

    // void pop_back(){
    //     if(!last)
    //         throw std::length_error("File vide!");

    //     if(last->right == last){   // un seul élément
    //         delete last;
    //         last = nullptr;
    //     }
    //     else{
    //         SLNode<T>* runner = last->right;   // le devant

    //         while(runner->right != last)       // s'arrête sur l'avant-dernier
    //             runner = runner->right;

    //         runner->right = last->right;       // l'avant-dernier pointe sur le devant
    //         delete last;
    //         last = runner;
    //     }
    //     --count;
    // }
private:
    SLNode<T>* last;    
    size_t count;
};