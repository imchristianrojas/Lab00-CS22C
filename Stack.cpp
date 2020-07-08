
#include <stdio.h>
#include "DLinkedList.cpp"

using namespace std;

template <typename T>

class Stack
{
public:
    
    DList<T> stackList;
    
    Stack()
    {
        stackList.tail = NULL;
        stackList.head = NULL;
    }

    void Push(T data)
    {
        cout<<"Pushing: "<<data<<endl;
        stackList.appendDl(data);
  
    }
    
    
    T Pop()
    {
        T data;
        data = (stackList.tail)->data;
        stackList.Delete(data);
        cout<<"Returning and Popping "<< data<<endl;
        
        return data;
    }
    
    
    
    T Peek()
    {
        T data;
        Node<T>* temp;
        temp = stackList.tail;
        data = temp->data;
        
        cout<<"Peeking: "<< data<<endl;
        return data;
        
    }
    
    bool isEmpty()
    {
        return stackList.IsEmpty();
        
    }
    
    int getLength()
    {
    
        return stackList.Count();
        
    }
    
    
    
    void outputStack()
    {
        
        if(stackList.IsEmpty())
        {
            cout<<"Stack is Empty!"<<endl;
        }
        
        cout<<"Outputting Stack: "<<endl;
        stackList.Output();
        
        
    }
    
    

};

