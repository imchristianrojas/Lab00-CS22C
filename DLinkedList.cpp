#include <stack>
#include <queue>
#include <stdio.h>
#include "SLinkedList.cpp"


using namespace std;

template <typename T>
class DList
{
public:
    Node<T> * tail;
    Node<T> * head;
    
    DList(){tail = NULL; head = NULL;}


void  appendDl(T data)
{

    Node<T>* pdata = new Node<T>(data);

    
    
           if (tail == NULL && head == NULL)
           {
               tail = pdata;
               head = pdata;
               pdata->previous = NULL;
               pdata->next = NULL;
           }
           else
           {
               
                   pdata->previous = tail;
                   pdata->next = NULL;
                   tail->next = pdata;
                   tail = pdata;

           }
       }

void PrependDL(T data)
    {
        
        cout<<"Prepending: "<<data<<" to the doubly linked list"<<endl;
        Node <T> *pdata = new Node<T>(data);
        
        
        if (tail == NULL)
        {

            tail = pdata;
            head = pdata;

        }
        else
        {

            pdata->previous = NULL;
            pdata->next = head;
            head->previous = pdata;
            head = pdata;

        }
    }


void InsertAfter(T find, T data)
     {
         Node<T> *pdata = new Node<T>(data);
         Node<T>* rover = head;
         Node<T>* temp = nullptr;
         
         while (rover != NULL)
         {

             if(rover->data == find)
             {
                 temp = rover;
                 rover = rover->next;
                 temp->next = pdata;
                 rover->previous = pdata;
                 
                 pdata->previous = temp;
                 pdata->next = rover;
                 
                
                
                 break;

             }
             rover = rover->next;
         }
     }
     // inserts data before found data
     void InsertBefore(T find, T data)
     {

         Node<T> *pdata = new Node<T>(data);
         Node<T>* rover = head;
         Node<T>* temp = nullptr;
         
         while (rover != NULL)
         {

             if(rover->data == find)
             {
                 rover->previous = pdata;
                 temp->next = pdata;
                 
                 pdata->previous = temp;
                 pdata->next = rover;
                 break;
               
             }
             temp = rover;
             rover = rover->next;
         }
     }

void Delete(T data)
    {

        Node<T> *rover = head;
        Node<T> *previousNode = nullptr;
        Node<T> *temp = NULL;
        
        if(head == NULL && tail == NULL)
        {
            cout<<"The List is Empty! "<<endl;
            return;
        }
        
        
        while(rover!= NULL)
        {
            if(rover->data == data)
            {
                if((rover->previous == NULL) && (rover->next != NULL))
                {
                    temp = rover;
                    rover = rover->next;
                    head = rover;
                    rover->previous = NULL;
                    delete temp;
                    break;
   
                    
                }
                else if((rover->next == NULL) && (rover->previous == NULL))
                {
                    delete rover;
                    tail = NULL;
                    head = NULL;
                    break;
                }
                else if(rover->next == NULL)
                {
                    
                    previousNode->next = NULL;
                    tail = previousNode;
                    delete rover;
                    break;
                    
                }

                    
              
                
                previousNode->next = rover->next;
                temp = rover;
                
                rover = rover->next;
                rover->previous = previousNode;
                
                
                delete temp;
                break;
                
                
            }
            
            previousNode = rover;
            rover = rover->next;
            
        }
        

    }
    
    Node<T>* Search(T data)
    {
        Node<T>* rover = head;
        while (rover != NULL)
        {
           if((rover->data) == data)
           {
               return rover;
           }
            rover = rover->next;
        }
        
        return NULL;
        
    }

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
        
    }

    bool IsEmpty()
    {
        if((tail == NULL) && (head == NULL))
            return true;
       return false;

    }


    void Output()
    {
        
        Node<T>* rover = head;
    
        while (rover != NULL)
        {
            cout << rover->data << '\t';
            rover = rover->next;
        }
        cout << endl;
    }
    
};


