#include <iostream>
using namespace std;
#define MAX 10
int q[MAX];
int front = -1,rear=-1;

bool isempty(){
    return (front == -1 || front > rear);
}

bool isfull(){
    return rear == MAX-1;
}

void enqueue(int x){
    if(isfull()){
        cout<<"queue overflow"<<endl;
        return;
    }
    if(front == -1) front = 0;
    rear++;
    q[rear] = x;
}

int dequeue(){
    if(isempty()){
        cout<<"Queue underflow"<<endl;
        return -1;
    }
    int val = q[front++];
    if(front > rear) front = rear = -1;
    return val;
}

void top(){
    if(isempty()){
        cout<<"Queue is empty"<<endl;
        return;
    }
    cout<<q[front]<<endl;
}

void push(int x){
    enqueue(x);
    int n= rear-front;
    for (int i = 0; i < n; i++)
    {
        enqueue(dequeue());
    }
}

void pop(){
    if (isempty()) {
        cout << "Stack underflow\n";
        return;
    }
    cout << "Popped: " << dequeue() << endl;
}

void display(){
    for (int i = front; i <= rear; i++)
    {
        cout<<q[i]<<" ";
    }
    cout<<endl;
    
}

int main(){

    push(10);
    push(20);
    push(30);
    push(40);

    display();   
    top();       

    pop();       
    display();   
    top();       

}