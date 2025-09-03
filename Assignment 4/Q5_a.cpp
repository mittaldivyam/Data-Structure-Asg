#include <iostream>
using namespace std;
#define MAX 5
int q1[MAX];
int q2[MAX];
int f1=-1,r1=-1,f2=-1,r2=-1;

bool isempty_q(int f,int r){
    return (f==-1 || f>r);
}

bool isfull(int r){
    return r == MAX-1;
}

void enqueue(int q[],int &f,int &r,int x){
    if(isfull(r)){
        cout<<"queue overflow"<<endl;
        return;
    }
    if(f == -1) f = 0;
    r++;
    q[r] = x;
}

int dequeue(int q[],int &f, int &r){
    if(isempty_q(f,r)){
        cout<<"Queue underflow"<<endl;
        return -1;
    }
    int a = q[f++];
    if(f > r) f = r = -1;
    return a;
}

bool isempty(int top){
    return top==-1;
}

void push(int x){
    enqueue(q1,f1,r1,x);

    while(!isempty_q(f2,r2)) {
        enqueue(q1,f1,r1,dequeue(q2,f2,r2));
    }
     for(int i=0;i<MAX;i++){
        int tmp = q1[i];
        q1[i] = q2[i];
        q2[i] = tmp;
    }

    swap(f1,f2);
    swap(r1,r2);
    f1=r1=-1;
}
void top(){
    if(isempty_q(f2,r2)){
        cout<<"stack empty"<<endl;
        return;
    }
    else cout<<q2[f2];
}

void display(){
    if(isempty_q(f2,r2)){
        cout<<"stack empty"<<endl;
        return;
    }
    for (int i = f2; i <= r2; i++)
    {
        cout<<q2[i]<<" ";
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

}