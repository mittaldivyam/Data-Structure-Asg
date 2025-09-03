#include <iostream>
using namespace std;
#define MAX 5
int queue[MAX];
int front = -1,rear =-1;

bool isempty(){
    return (front == -1 || front > rear);
}

bool isfull(){
    return rear == MAX-1;
}

void enqueue(int queue[],int &rear,int &front,int x){

    if(front == -1) front = 0;
    rear++;
    queue[rear] = x;
}

void dequeue(int queue[],int &rear,int &front){
    if(isempty()){
        cout<<"Queue underflow"<<endl;
        return;
    }
    front++;
    if(front > rear) front = rear = -1;
}

void sol(int q1[],int f1,int r1,int q2[],int f2,int r2){
    int i = f1,j=f2;
    while (i<=r1 && j<=r2)
    {
        enqueue(queue,rear,front,q1[i++]);
        enqueue(queue,rear,front,q2[j++]);
    }
    while(i<=r1){
        enqueue(queue,rear,front,q1[i++]);
    }
     while(j<=r2){
        enqueue(queue,rear,front,q2[j++]);
    } 
}

void display(int queue[]){
    if(isempty()){
        cout<<"queue is empty"<<endl;
        return;
    }

    for (int i = front; i <= rear; i++)
    {
        cout<<queue[i]<<" ";
    }
    cout<<endl;  
}


int main(){

int q1[3];
int q2[2];
int f1=-1,r1=-1,f2=-1,r2=-1;
enqueue(q1,r1,f1,1);
enqueue(q1,r1,f1,3);
enqueue(q1,r1,f1,5);
enqueue(q2,r2,f2,2);
enqueue(q2,r2,f2,4);
sol(q1,f1,r1,q2,f2,r2);
display(queue);

}