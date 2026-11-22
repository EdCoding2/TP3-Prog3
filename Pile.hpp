#include <stdexcept>
#include "SLNode.hpp"

template <typename T>
class Pile{
public:
    Pile(){
        first = nullptr;
        count = 0;
    }
    
    ~Pile(){
        while(first)
            pop();
    }

    void push(T data){
        first = new SLNode<T>(data, first);
        ++count;
    }

    void pop(){
        if(!first)
            throw std::length_error("Pile vide!");    
        
        SLNode<T>* toDelete = first;
        first = toDelete->right;
        delete toDelete;
        --count;
    }

    T top(){
        if(first)
            return first->data;
        throw std::length_error("Pile vide!");

        // first ? return first->data : throw std::length_error("Pile vide!");
    }

    size_t size(){
        return count;
    }
private:
    SLNode<T>* first;
    size_t count;
};