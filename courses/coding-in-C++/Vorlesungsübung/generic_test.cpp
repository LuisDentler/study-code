#include <iostream>


template <typename T, typename U>
class Pair{

    private: 
        T val1;
        U val2;

    public:

    Pair(T v1, U v2): val1(v1), val2(v2){};
    T getV1()const{
        return this->val1;
    }
    T setV1(T value){
        val1 = value;
    }
    U getV2()const{
        return this->val2;
    }
    U setV2(U value){
        val2 = value;
    }

};

int main(){

    Pair p(1,2);
    std::cout << p.getV1() << " " << p.getV2() << std::endl;
    
    return 0;
}