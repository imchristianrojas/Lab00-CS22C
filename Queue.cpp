
#include "Stack.cpp"
#include <stdio.h>


using namespace std;

template <typename T>
class Queue
{
    
public:
    DList<T> queueList;
    
    Queue(){queueList.tail = NULL; queueList.head = NULL;}
    
    void Push(T data)
    {
        cout<<"Pushing: "<<data<<endl;
        queueList.appendDl(data);
        
    }
    
    T Pop()
     {
         
         T data;
         if(queueList.IsEmpty())
         {
             cout<<"Queue List is Empty Cannot Pop! "<<endl;
             return 0;
         }
         data = (queueList.head)->data;
         queueList.Delete(data);
         cout<<"Returning and Popping "<< data<<endl;
         
         return data;
     }
    
    T peek()
    {
        
        T data;
        if(queueList.IsEmpty())
        {
            cout<<"Queue List is empty! "<<endl;
            return 0;
        }
        
        data = (queueList.head)->data;
        cout<<"Peeking: "<<data<<endl;
        
        return data;
    }
    
    bool isEmpty()
    {
        
        return queueList.IsEmpty();
        
    }
    
    
    int getLength()
    {
        
        return queueList.Count();
    }
    
    void outputQueue()
    {
        cout<<"\nOutputting Queue: "<<endl;
        queueList.Output();
        
    }
    
    
};


int main()
{
    
    //Singly Linked List Tests
    
    int count = 5;
    SList<int> singlyList;
    cout<<((singlyList.IsEmpty())? "The Singly Linked List is Empty!": "The Singly List Linked List is not empty!" )<<endl;


    for (int x = 0; x < count; x++)
    {

        singlyList.Append(x);

        }

    cout<<endl;

    singlyList.Output(singlyList.tail);
    cout<<endl;
    singlyList.Delete(2);
    singlyList.Output(singlyList.tail);
    cout<<endl;
    singlyList.InsertBefore(1, 20);
    singlyList.Output(singlyList.tail);
    cout<<endl;
    singlyList.InsertAfter(3, 77);
    singlyList.Output(singlyList.tail);
    cout<<endl;
    cout<<"The total number of nodes are "<<singlyList.Count()<<endl;

    cout<<endl;


    //Doubly Linked List Tests
    DList<int> doublyList;
    cout<<((doublyList.IsEmpty()) ? "The Doubly Linked List is Empty!" : " The Doubly Linked List is Not Empty")<<endl;

    for (int x = 0; x < count; x++)
    {

        cout<<"Appending "<<x<<" to doubly linked list."<<endl;
        doublyList.appendDl(x);

        }

    cout<<endl;
    cout<<"Outputting Doubly Linked List:\n";
    doublyList.Output();
    doublyList.PrependDL(100);
    
    doublyList.Output();
    cout<<"Inserted 20 before 3"<<endl;
    doublyList.InsertBefore(3, 20);
    
    doublyList.Output();
    
    cout<<"Deleted: 1\n";
    doublyList.Delete(1);
    cout<<"Deleted: 2\n";
    doublyList.Delete(2);
    cout<<"Deleted: 3\n";
    doublyList.Delete(3);
    cout<<"Deleted: 4\n";
    doublyList.Delete(4);

    cout<<"Outputting Doubly Linked List:\n";
    doublyList.Output();
    cout<<"Deleting 0:\n";
    doublyList.Delete(0);
    cout<<"Outputting Doubly Linked List:\n";
    doublyList.Output();
    cout<<((doublyList.IsEmpty()) ? "The Doubly Linked List is Empty!" : " The Doubly Linked List is Not Empty")<<endl;



    //Stack Tests
    cout<<"\nStack Test: \n";
    Stack<int> stackList;

    cout<<((stackList.isEmpty()) ? "The Stack List is Empty!" : " The Stack List is Not Empty")<<endl;
    for(int i = 5; i >=0; i--)
    {

        stackList.Push(i);

    }
    cout<<endl;

    stackList.outputStack();
    stackList.Peek();
    stackList.Pop();
    stackList.outputStack();
    stackList.Peek();
    cout<<((stackList.isEmpty()) ? "The Stack List is Empty!" : " The Stack List is Not Empty")<<endl;
    
    
    //Queue Tests
    cout<<"\nQueue Test: \n";
    Queue<int> queueList;
    
    cout<<((queueList.isEmpty()) ? "The Queue List is Empty!" : " The Queue List is Not Empty")<<endl;
    
    for(int i = 20; i<=30; i+=2)
    {
        queueList.Push(i);
        
    }
    queueList.outputQueue();
    queueList.peek();
    queueList.Pop();
    queueList.outputQueue();
    cout<<((queueList.isEmpty()) ? "The Queue List is Empty!" : " The Queue List is Not Empty")<<endl;
    

    cout << endl;


    return 0;
}


