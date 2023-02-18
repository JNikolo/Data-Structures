#include <iostream>
using namespace std;

int TotalNodeCnt = 0;
struct Queue{
	string Item;
	int count;
	Queue * next;    
};
bool Queue_Empty(Queue * rear){
    if(rear==nullptr) return 1;
    
    else return 0;
}
Queue * Push(Queue * back){
    if(back==nullptr){
        back = new Queue;
        cout<<"Enter item name:"<<endl;
        cin>> back->Item;
        cout<<"Enter count:"<<endl;
        cin>>back->count;
        back->next = nullptr;
        ::TotalNodeCnt++;
        return back;
    }
    else{
        Queue * current = new Queue;
        cout<<"Enter item name:"<<endl;
        cin>> current->Item;
        cout<<"Enter count:"<<endl;
        cin>>current->count;
        current->next = back;
        back = current;
        ::TotalNodeCnt++;
        return back;
    }
}
void Print(Queue * rear){
    if(rear==nullptr) return;
    else{
        Queue * temp = rear;
        while(temp!=nullptr){
            cout << "Item = " << temp->Item << endl;
            cout << "Count = " << temp->count<< endl;
            cout << "------------------"<<endl;
            temp = temp->next;
        }
    }
}
Queue * Pop(Queue * rear){
    if (rear == nullptr) return nullptr;
    
    if (rear->next == nullptr) {
        ::TotalNodeCnt--;
        delete rear;
        return nullptr;
    }
 
    Queue * second_last = rear;
    while (second_last->next->next != nullptr){
        second_last = second_last->next;
    }
        
    delete (second_last->next);
    second_last->next = nullptr;
    ::TotalNodeCnt--;
    return rear;
}
string Queue_Peak(Queue * head){
    Queue * temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    return temp->Item;
}
int main(){
    string Name = "Jair Ruiz";
    cout << "------------------------------------------------------------------------------\n"; 
    cout << "Name: " << Name << endl;
    cout << "FILE: " << __FILE__ << " DATE: " << __DATE__ << endl;
    cout << "------------------------------------------------------------------------------\n";

	Queue * rear = nullptr;
    char flag = 'y';
    while(flag=='y'){
        rear = Push(rear);
        cout<<"Continue? (y)(n)"<<endl;
        cin>>flag;
        if(flag!='y' && flag!='n'){
            cout<<"Ups!! Wrong input. Try 'y' for yes or 'n' for no"<<endl;
            cout<<"Continue? (y)(n)"<<endl;
            cin>>flag;
        }
    }
    cout<<"------------"<<endl;
    Print(rear);
    cout<<"You have "<<::TotalNodeCnt<<" items in total"<<endl;
    cout<<"-------Removing three items--------"<<endl;
    for(int i = 0; i<3;++i) rear = Pop(rear);
    cout<<"------------"<<endl;
    Print(rear);
    cout<<"Now you have "<<::TotalNodeCnt<<" items in total"<<endl;
    cout<<"Fruit name of the top: "<<Queue_Peak(rear)<<endl;
    cout<<"------Deleting all the list------"<<endl;

    int size = ::TotalNodeCnt;
    for(int i = 0; i<size;++i) rear = Pop(rear);
    
    if(Queue_Empty(rear)) cout<<"List is empty"<<endl;
    else cout<<"ups! Check code again"<<endl;

    delete rear;

	return 0;
}