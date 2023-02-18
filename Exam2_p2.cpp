#include <iostream>
using namespace std;

const int SIZE = 11;
struct ListNode{
	string key;
	ListNode *link;
};

ListNode*  addLink(ListNode * head, string str){
	if(head==nullptr){
		head = new ListNode;
		head->link = nullptr;
		head->key = str;
		return head;
	}
	else{
		ListNode *current = new ListNode;   
		current->key = str;
		current->link = head;			
		head = current;			
		return head;
	}				
} 
int countNodes(ListNode * head){
	int counter = 0;
	while(head!=nullptr){
		counter++;
		head = head->link;
	}
	return counter;
}
void PrintList(ListNode * head){
    ListNode * temp = head;	
	if(temp == NULL) 
	   return;
	else{
		int NodeCnt = countNodes(temp);
		while(temp!= NULL)
		{
			cout << temp->key<<" --> ";
			temp = temp->link;		
		}
		cout<<NodeCnt<<" nodes in total";
	}
}
int hashFunc(string S){
	int sum = 0;
	for(int i = 0; i<S.size();++i){
		sum = sum + S[i];
	}
	return sum % SIZE;
}
void inputHashTab(ListNode * hash[SIZE], string str){
	int index = hashFunc(str);
	hash[index] = addLink(hash[index],str);
}
void PrintHash(ListNode * hash[]){
	for(int i = 0; i < SIZE ; ++i){
		cout<<"|"<<i<<"|-->";
		PrintList(hash[i]);
		cout<<endl;
	}
}
void FindKey(ListNode * hash[], string str){
	int index = hashFunc(str);
	ListNode * temp = hash[index];
	int NodeCnt = 1;
	bool strFound = false;
	while(temp!=nullptr){
		if(temp->key==str){
			strFound = true; 
			break;
		}
		NodeCnt++;
		temp = temp->link;
	}
	if(strFound){
		cout<<"Word found: index-->"<<index;
		cout<<"  Node-->"<<NodeCnt<<endl;
		return;
	}
	else cout<<"WORD CANNOT BE FOUND"<<endl;
		return;
}
int main(){
	string Name = "Jair Ruiz";
    cout << "------------------------------------------------------------------------------\n"; 
    cout << "Name: " << Name << endl;
    cout << "FILE: " << __FILE__ << " DATE: " << __DATE__ << endl;
    cout << "------------------------------------------------------------------------------\n";

	string str[32];
	int index;
	ListNode * HashTable[SIZE] = {};
	cout<<"Input the encrypted message:"<<endl;
	for(int i = 0; i< 32; i++){
		cin>>str[i];	
	}
	for(int i = 0; i< 32; i++){
		inputHashTab(HashTable,str[i]);
	}
	PrintHash(HashTable);
	string found;
	for(int i = 0; i<6; ++i){
		cout<<"Input the word you want to search:"<<endl;
		cin>>found;
		FindKey(HashTable, found);
	}
	return 0;
}
