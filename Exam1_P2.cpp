#include<iostream>

using namespace std;
class Array{
private:
    int *pType;		//array elements are created on the heap
    int  Size;
public:
    // constructors
    Array(int Size = 1);			//write “parametrized constructor” 
    ~Array( );       //destructor		//write “destructor” 
// accessors & mutators
    int getSize() const{ return Size;}
    void setSize(int size){ this->Size = size;}
// operators
    Array& operator=(const Array& rhs);
    int & operator[](int offSet){ return *(pType + offSet);}
    const int& operator[](int offSet) const{ return pType[offSet];}	 //works with const object	
//Overloaded arithmetic operators
    Array operator+(const Array & rhs);	
// friend function
    friend Array operator+(int K, const Array& rhs);
};

int main(){
    string Name;
    cout << "Input student name: " << endl;
    cin >> Name;
    cout << "------------------------------------------------------------------------------\n"; 
    cout << "Name: " << Name << endl;
    cout << "FILE: " << __FILE__ << " DATE: " << __DATE__ << endl;
    cout << "------------------------------------------------------------------------------\n";

    cout<<"X(10), Y(10), Z"<<endl;
    Array X(10), Y(10), Z;
    int s = X.getSize();
    for(int i = 0; i < s; ++i){
        X[i] = i * 2;
        Y[i] = i * i;
    }

    cout<<"Array X() = ";
    for(int i = 0; i < s; ++i) cout<<X[i]<<" ";

    cout<<"\nArray Y() = ";
    for(int i = 0; i < s; ++i) cout<<Y[i]<<" ";
    
    cout<<"\nZ = X + Y\n";
    Z = X + Y;

    cout<<"Array Z() = ";
    for(int i = 0; i < s; ++i) cout<<Z[i]<<" ";
    
    cout<<"\nZ = 10 + X\n";
    Z = 10 + X;

    cout<<"Array X() = ";
    for(int i = 0; i < s; ++i) cout<<X[i]<<" ";

    cout<<"\nArray Z() = ";
    for(int i = 0; i < s; ++i) cout<<Z[i]<<" ";
    cout<<endl;

    return 0;
}

Array::Array(int Size){
    this->Size = Size;
    pType = new int[Size];
    cout<<"Parametrized constructor"<<endl;
}			
Array::~Array( ){
    delete[] this->pType;
    cout<<"Destructor"<<endl;
}
Array & Array::operator=(const Array& rhs){
    if(this!=&rhs){
        delete[] pType;
        this-> Size = rhs.Size; 
        pType = new int[Size];
        for(int i = 0; i < Size; ++i) pType[i] = rhs.pType[i];
    }
    return *this;
} 
Array Array::operator+(const Array & rhs){
    Array temp(10);
    for(int i = 0; i< rhs.Size; ++i) temp[i] = *(pType + i) + rhs.pType[i];
    return temp;
}	
Array operator+(int K, const Array& rhs){
    Array temp(10);
    for(int i = 0; i< rhs.Size; ++i) temp[i] = K + rhs.pType[i];
    return temp;
}