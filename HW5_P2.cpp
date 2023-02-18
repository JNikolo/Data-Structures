#include <iostream>
using namespace std;

struct FruitNode{
    string name;
    double price;
    FruitNode * left;
    FruitNode * right;
};
//function to create the root of a binary tree
FruitNode * createRoot(string name, double price){
    FruitNode * temp = new FruitNode;
    temp->name = name;
    temp->price = price;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}
//function to insert nodes in the binary tree
void insert(FruitNode * tree, string name, double price){
    if (price < tree->price){
        // insert left 
        if (tree->left != nullptr) {
            //recursive function
            insert(tree->left, name, price);
        }
        else{
            tree->left = new FruitNode;
            tree->left->price = price;
            tree->left->name = name;
            tree->left->left = nullptr;
            tree->left->right = nullptr;
        }
    }
    else{
        if (price >= tree->price){
        // insert right 
            if (tree->right != nullptr) {
                insert(tree->right, name, price);
            }
            else{
                tree->right = new FruitNode;
                tree->right->price = price;
                tree->right->name = name;
                tree->right->left = nullptr;
                tree->right->right = nullptr;
            }
        }
    }
}
//function to print the tree
void print_tree(FruitNode * current){
    if (current == NULL) return;   
    if (current->left != NULL) print_tree(current->left);
    if (current != NULL){
        cout<<"Fruit name: "<<current->name<<endl;
        cout<<"Price per lb: "<<current->price<<endl;
        cout<<"---------------"<<endl;
    }        
    if (current->right != NULL)  print_tree(current->right);
}
//function to get the total sum of prices and the number of nodes
void getAverage(FruitNode * current, double& sum, int& count){
    if(current == nullptr) return;
    sum = sum + current->price;
    count = count + 1;
    getAverage(current->left,sum,count); 
    getAverage(current->right,sum,count);
}
//function to search and print nodes with the first letter of the name >='L'
void searchPrint(FruitNode * current){
    if(current == nullptr) return;
    if(current->left != nullptr) searchPrint(current->left);
    if(current != nullptr){
        if(current->name[0] >= 'L'){
            cout<<current->name<<endl;
            cout<<current->price<<endl;
        }
    }
    if (current->right != NULL)  searchPrint(current->right);
}
//driver code
int main(){
    string Name = "Jair Ruiz";
    cout << "------------------------------------------------------------------------------\n"; 
    cout << "Name: " << Name << endl;
    cout << "FILE: " << __FILE__ << " DATE: " << __DATE__ << endl;
    cout << "------------------------------------------------------------------------------\n";
//////////////////////////////////////////////////////////////////
    string nameF;
    double priceF;
    FruitNode* tree;
    tree = createRoot("Lemon", 3.00);
    cout<<"Binary tree created and initiliazed with name->Lemon and price->3.00"<<endl;
    cout<<"Input a list of fruits and their prices... (input 'exit' to end the list)"<<endl;
    while(1){
        cin>>nameF;
        if(nameF=="exit"){
            break;
        }
        cin>>priceF;
        insert(tree,nameF,priceF);
    }
    print_tree(tree);
    double sum = 0;
    int count = 0;
    FruitNode * temp = tree;
    getAverage(temp, sum, count);
    cout << "Average price of fruits: "<< sum/count << endl;
    cout<<"Fruits with the first letter >='L' :"<<endl;
    searchPrint(tree);
    return 0;
}

