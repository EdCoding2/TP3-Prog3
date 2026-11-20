template <typename T>
class Queue{
public:
    

    Dequeue(){
        last = nullptr;
        count = 0;
    }

    void push_back(){
        
    }

    void push_front(){

    }

    void pop_front(){

    }

    void pop_back(){

    }
private:
    SLNode<T>* last;    
    size_t count;
};