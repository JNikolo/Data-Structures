#include<iostream>
using namespace std;

template<class T>
class Matrix{
private:
    T **array;
    int M, N;
    T value;
public:
    Matrix();
    Matrix(int M, int N, T Val);
    ~Matrix();
    Matrix(const Matrix & rhs);
    int getRowSize() const{return this->M;}
    int getColSize() const{return this->N;}
    const Matrix & operator=(const Matrix &rhs){
        if(M!=rhs.M && N!=rhs.N){
            cout<<"Error: Row and column size must be equal"<<endl;
            return *this;
        }
        else{
            if(this!=&rhs){
                for(int i = 0; i<M; i++) delete[] array[i];
                delete array;
                this->M = rhs.M;
                this->N = rhs.N;
                this->value = rhs.value;
                array = new T *[M];
                for(int i = 0; i<M;i++) array[i] = new T[N];
                for(int i = 0; i<M;i++){
                    for (int j = 0; j<N; ++j){
                        array[i][j] = rhs.array[i][j];
                    }
                }
            }
        }
        return *this;
    }
    const Matrix operator+(const Matrix &rhs){
        Matrix temp(rhs.M, rhs.N, 0.0);
        for(int i = 0; i< rhs.M; ++i){
            for(int j = 0; j < rhs.N; ++j){
                temp.array[i][j] = this->array[i][j] + rhs.array[i][j];
            }
        }
        return temp;
    }
    friend ostream & operator<<(ostream & os, const Matrix &rhs){
        for(int i = 0; i< rhs.M; ++i){
            os << "| ";
            for(int j = 0; j<rhs.N;++j) os << rhs.array[i][j] <<" ";
            os << "|"<<endl;
        }
        return os;
    }
    void incrementRow(int row, int val);
};

int main(){
    string Name = "Jair Ruiz";
    cout << "------------------------------------------------------------------------------\n"; 
    cout << "Name: " << Name << endl;
    cout << "FILE: " << __FILE__ << " DATE: " << __DATE__ << endl;
    cout << "------------------------------------------------------------------------------\n";

    Matrix<double> A(8, 8, 5.0);
    Matrix<double> B(8, 8, 10.0);
    Matrix<double> R(8,8,0.0);
    
    cout<<"MAtrix A:"<<endl;
    cout<<A;
    cout<<"Matrix B:"<<endl;
    cout<<B; 
    for(int i = 0; i<A.getRowSize(); ++i){
        A.incrementRow(i,i);
    }
    for(int i = 0; i<B.getRowSize(); ++i){
        B.incrementRow(i,i);
    }
    R = A + B;
    cout<<"A and B are incremented"<<endl;
    cout<<"A + B :"<<endl;
    cout<<R;   
    return 0;
}
//some definitions
template<class T>
Matrix<T>::Matrix(){
    M = 1; 
    N = 1;
    array = new T *[M];
    for(int i = 0; i<M;i++) array[i] = new T[N];
    cout<<"Default matrix constructor"<<endl;
}
template<class T>
Matrix<T>::Matrix(int M, int N, T Val){
        this->M = M;
        this->N = N;
        this->value = Val;
        array = new T *[M];
        for(int i = 0; i<M;i++) array[i] = new T[N];
        for(int i = 0; i<M;i++){
            for (int j = 0; j<N; ++j){
                array[i][j] = value;
            }
        }
        cout<<"Parametrized matrix constructor"<<endl;
}
template<class T>
Matrix<T>::~Matrix(){
        for(int i = 0; i<M; i++) delete[] array[i];
        delete array;
        cout<<"Matrix destructor"<<endl;
}
template<class T>
Matrix<T>::Matrix(const Matrix & rhs){
        for(int i = 0; i<M; i++) delete[] array[i];
        delete array;
        this->M = rhs.M;
        this->N = rhs.N;
        this->value = rhs.value;
        array = new T *[M];
        for(int i = 0; i<M;i++) array[i] = new T[N];
        for(int i = 0; i<M;i++){
            for (int j = 0; j<N; ++j) array[i][j] = value;
        }
}
template<class T>
void Matrix<T>::incrementRow(int row, int val){
    for(int i = 0; i <N; i++) array[row][i] = val*array[row][i];
}