#include <cstdlib>
#include <iostream>



using namespace std;

template <typename T>
class Node
{
public:
    T data;
    // introduce a 'next' node for doubly linked list
    Node<T>* previous;
    Node<T> * next;
    Node<T>() { previous = NULL; next = NULL; data = 0; }
    Node<T>(T t) { previous = NULL; next = NULL; data = t; }
};

// Convert Singly Linked List to Doubly Linked List
template <typename T>
class SList
{
public:
    Node<T>* tail;
    // introduce 'head' node for double link
    SList() { tail = NULL; }  // default constructor
    // appends to tail of list
    
    void Append(T data)
    {
        cout<<"Appending: "<<data<< " to Singly Linked List "<<endl;
        Node<T>* pdata = new Node<T>(data);
        if (tail == NULL)
        {
            tail = pdata;
        }
        else
        {
            
            pdata->previous = tail;
            tail = pdata;
        }
        
    }
    
    void Prepend(T data)
    {
        cout<<"Prepending: "<<data<< "to Singly Linked List "<<endl;
        Node <T> *pdata = new Node<T>(data);
        if (tail == NULL)
        {
            tail = pdata;

        }
        else
        {

            pdata->previous = NULL;
            tail->previous = pdata;
            tail = pdata;

        }
        //
    }
    // inserts data after found data
    void InsertAfter(T find, T data)
    {
        Node<T> *pdata = new Node<T>(data);
        Node<T>* rover = tail;
        while (rover != NULL)
        {
            
            if(rover->data == find)
            {
                
                pdata->previous = rover->previous;
                
                rover->previous = pdata;
                cout<<"Inserted: "<<data<<" after: "<<find<<endl;
                break;
                
            }
            rover = rover->previous;
        }
    }
    // inserts data before found data
    void InsertBefore(T find, T data)
    {
        
        
        Node<T> *pdata = new Node<T>(data);
        Node<T>* rover = tail;
        Node<T>* temp = nullptr;
        while (rover != NULL)
        {
            
            if(rover->data == find)
            {
                pdata->previous = rover;
                
                temp->previous = pdata;
                cout<<"Inserted: "<<data<<" before: "<<find<<endl;
                break;
                         
            }
            temp = rover;
            rover = rover->previous;
        }
    }
    // finds data node and returns it
    Node<T>* Search(T data)
    {
        Node<T>* rover = tail;
        while (rover != NULL)
        {
           if((rover->data) == data)
           {
               return rover;
           }
            rover = rover->previous;
        }
        
    }
    // deletes a node from the list
    void Delete(T data)
    {
        cout<<"Deleting: "<<data<<endl;
        
        Node<T>* rover = tail;
        Node<T>* temp = NULL;
        
        while (rover != NULL)
        {
        
          if(rover->data == data)
          {
              if(rover->previous == NULL)
              {
                  temp->previous = NULL;
                  delete rover;
                  break;
              }
              temp->previous = rover->previous;
              delete rover;
              break;
              
          }
            temp = rover; //recent node
            
            rover = rover->previous;
            
        }
        
    }
    // returns number of nodes in list
    int Count()
    {
        int count = 0;
        Node<T>* rover = tail;
        
        while (rover != NULL)
        {
            count++;
            rover = rover->previous;
            
        }
        
        rover = tail;
        return count;
        
        //
    }
    // returns true if list is empty
    bool IsEmpty()
    {
        if(tail == NULL)
            return true;
        return false;
        
    }
    
    // prints list from tail of list
    
    Node<T>* Output(Node<T>* current)//Recursion
    {
      
        if(current == NULL)//base case
        {
            return NULL;
        }
        
        cout<<current->data<<'\t';
        Output(current->previous);
        
        
        
        return NULL;
        
    }
        
        
        
        
//        while(recur->previous != NULL)
//        {
//            cout<<rover->data<<'\t';
//            rover = rover->previous;
//        }
//
        
    
    
    
};

