/*Write a program that creates a singly link list of used automobiles containing nodes that 
describe the model name (string), price(int) and owner’s name.  The program should create 
a list containing 12 nodes created by the user. There are only three types of models (BMW, Cadillac, Toyota) 
and the prices range from $2500 – $12,500.  The program should allow the user to provide
•	Print a printout of all cars contained in the list (model, price, owner)
•	Provide a histogram(global array) of all cars in the list portioned into $500 buckets
•	Calculate the average price of the cars contained in the list
•	Provide the details for all cars more expensive than the average price
•	Remove all nodes having a price less than 25% of average price
•	Print a printout of all cars contained in the updated list (model, price, owner)
*/

#include <iostream>
using namespace std;

struct CarNode{
    string model;
    int price;
    string owner;
    CarNode * next;
}; 

CarNode * insertNode(CarNode * head){
    if(head==nullptr){
        head = new CarNode;
        cout<< "Insert car model"<<endl;
        cin >> head->model;
        cout<< "Insert car price"<<endl;
        cin >> head->price;
        cout<< "Insert car's owner"<<endl;
        cin >> head->owner;
        head->next = nullptr;
        return head;
    }
    else{
        CarNode * current = new CarNode;
        cout<< "Insert car model"<<endl;
        cin >> current->model;
        cout<< "Insert car price"<<endl;
        cin >> current->price;
        cout<< "Insert car's owner"<<endl;
        cin >> current->owner;
        current->next = head;
        head = current;
        return head; 
    }
}
void printList(CarNode * head){
    CarNode * temp = head;
    while(temp!=nullptr){
        cout<<"**************\n"<<"Car Info:\n";
        cout<<"Model->"<<temp->model<<endl;
        cout<<"Price->"<<temp->price<<endl;
        cout<<"Owner->"<<temp->owner<<endl;
        temp = temp->next;
    }
}
void deleteCheapCar(CarNode * head, int Link){
    CarNode * temp = head;		
    CarNode * out = head;		
    CarNode * prev = head;		
    int NodeId = 1;
    while(temp != NULL){
		prev = temp;
		if(NodeId == Link){
            cout << "NodeId = " << NodeId <<endl;
            out = temp->next;           	//save present link 
            temp = temp->next;          
            prev->next = temp->next;			//assign previous link to next link
		    delete out;				//remove link from heap
		    break;
        }
        NodeId++;
        temp = temp->next;  
    }
}
int findCheapCar( CarNode * head, double average){
    CarNode * temp = head;
    int NodeId = 0;		
    while(temp != NULL){
        if(temp->price < (average*0.25)){
            return NodeId;
	    }
	    NodeId++;
	    temp = temp->next;			
    }
	return -1;
} 
void countCars(CarNode * head, int * counter){
    CarNode * temp = head;
    while(temp!=nullptr){
        if(temp->price>=2500 && temp->price<3000){
            ++counter[0];
        }
        if(temp->price>=3000 && temp->price<3500){
            ++counter[1];
        }
        if(temp->price>=3500 && temp->price<4000){
            ++counter[2];
        }
        if(temp->price>=4000 && temp->price<4500){
            ++counter[3];
        }
        if(temp->price>=4500 && temp->price<5000){
            ++counter[4];
        }
        if(temp->price>=5000 && temp->price<5500){
            ++counter[5];
        }
        if(temp->price>=5500 && temp->price<6000){
            ++counter[6];
        }
        if(temp->price>=6000 && temp->price<6500){
            ++counter[7];
        }
        if(temp->price>=6500 && temp->price<7000){
            ++counter[8];
        }
        if(temp->price>=7000 && temp->price<7500){
            ++counter[9];
        }
        if(temp->price>=7500 && temp->price<8000){
            ++counter[10];
        }
        if(temp->price>=8000 && temp->price<8500){
            ++counter[11];
        }
        if(temp->price>=8500 && temp->price<9000){
            ++counter[12];
        }
        if(temp->price>=9000 && temp->price<9500){
            ++counter[13];
        }
        if(temp->price>=9500 && temp->price<10000){
            ++counter[14];
        }
        if(temp->price>=10000 && temp->price<10500){
            ++counter[15];
        }
        if(temp->price>=10500 && temp->price<11000){
            ++counter[16];
        }
        if(temp->price>=11000 && temp->price<11500){
            ++counter[17];
        }
        if(temp->price>=11500 && temp->price<12000){
            ++counter[18];
        }
        if(temp->price>=12000 && temp->price<=12500){
            ++counter[19];
        }
        temp = temp->next;
    }
}
double priceAverage(CarNode * head){
    CarNode * temp = head;
    double totalSum = 0;
    int num = 0;
    while(temp!=nullptr){
        totalSum += temp->price;
        num++;
        temp = temp->next;
    }
    return totalSum/num;
}
void printExpensiveCar(CarNode * head, int average){
    CarNode * temp = head;
    while(temp!=nullptr){
        if(temp->price > average){
            cout<<"**************\n"<<"Car Info:\n";
            cout<<"Model->"<<temp->model<<endl;
            cout<<"Price->"<<temp->price<<endl;
            cout<<"Owner->"<<temp->owner<<endl;
        }
        temp = temp->next;
    }
}

int main(){
    string Name = "Jair Ruiz";
    cout << "------------------------------------------------------------------------------\n"; 
    cout << "Name: " << Name << endl;
    cout << "FILE: " << __FILE__ << " DATE: " << __DATE__ << endl;
    cout << "------------------------------------------------------------------------------\n";
//////////////////////////////////////////////////////////////////
    int * histogram = new int[20];
    for(int i = 0; i<20;++i) *(histogram + i)=0;
    CarNode * head = nullptr;
    cout<<"Inserting nodes to the linkedlist:"<<endl;
    for(int i = 0; i<12; i++){
        head = insertNode(head);
    }
    cout<<"Printing the list"<<endl;
    printList(head);
    countCars(head,histogram);
    cout<<"Printing a histogram of prices:"<<endl;
    for(int i = 0; i<20; ++i){
        cout<<"["<<i<<"]-> "<<*(histogram + i)<<endl;
    }
    double average = priceAverage(head);
    cout<<"Price Average = "<<average<<endl;
    printExpensiveCar(head,average);
    int id;
    cout<<"Deleting cheap cars"<<endl;
    for(int i = 0; i<12; ++i){
        id = findCheapCar(head, average);
        if(id!=-1){
            cout<<"Cheap car found at->"<<id<<endl;
            deleteCheapCar(head, id);
        } 
    }
    cout<<"Printing modified list"<<endl;
    printList(head);
    return 0;
}