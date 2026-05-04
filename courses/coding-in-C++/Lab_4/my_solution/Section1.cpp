#include <iostream>
#include <cmath>


class Vector2D{
    private:
        double x;
        double y;

    public:
        /**
        * @brief: Default constructor and parameterized constructor for Vector2D class.
        * The default constructor initializes the vector to (0.0, 0.0), while the parameterized constructor allows setting specific x and y values.
        * @param[in] x The x-coordinate of the vector.
        * @param[in] y The y-coordinate of the vector.
        * @return: None
        */
        Vector2D() : x(0.0), y(0.0) {};
        /**
        * @brief: Parameterized constructor for Vector2D class.
        * @param[in] x The x-coordinate of the vector.
        * @param[in] y The y-coordinate of the vector.
        * @return: None
        */
        Vector2D(double x, double y) : x(x), y(y) {};
        /**
        * @brief: Getter function for the x-coordinate of the vector.
        * @param[in] None
        * @return: The x-coordinate of the vector.
        */
        double getX()const{
            return x;
        }
        /**
        * @brief: Getter function for the y-coordinate of the vector.
        * @param[in] None
        * @return: The y-coordinate of the vector.
        */
        double getY()const{
            return y;
        }
        /**
        * @brief: Function to print the vector in the format (x, y).
        * @param[in] None
        * @return: None
        */
        void printVector(){
            std::cout << "Vector: (" << x << ", " << y << ")" << std::endl;
        }
        /**
        * @brief: Function to calculate and print the length of the vector.
        * This function calculates the length using the formula sqrt(x^2 + y^2) and prints the result.
        * @param[in] None
        * @return: None
        */
        void getLength(){
            double length = sqrt(x*x + y*y);
            std::cout << "Length of the vector: " << length << std::endl;
        }
        /**
        * @brief: Function to calculate and print the length of the vector with specified precision.
        * This function calculates the length and rounds it to the specified number of decimal places before printing.
        * @param[in] precision The number of decimal places to round the length to.
        * @return: None
        */
        void getLength(int precision){
            double length = sqrt(x*x + y*y);
            double factor = std::pow(10.0, precision);
            std::cout << "Length of the vector (rounded): " << std::round(length * factor) / factor << std::endl;
        }
        /**
        * @brief: Overloaded addition assignment operator for Vector2D class.
        * This function takes another Vector2D object as input and adds its components to the current vector's components, modifying the current vector.
        * @param[in] other_vector The vector to be added to the current vector.
        * @return: None
        */  
        void operator +=(const Vector2D &other_vector){
            this->x += other_vector.getX();
            this->y += other_vector.getY();
        }
        
        
        
    };

    /**
    * @brief: Overloaded addition operator for Vector2D class.
    * This function takes two Vector2D objects as input and returns a new Vector2D object that represents the sum of the two vectors.
    * @param[in] left_vector The first vector to be added.
    * @param[in] right_vector The second vector to be added.
    * @return: A new Vector2D object that is the sum of the two input vectors.
    */
    Vector2D operator +(const Vector2D &left_vector, const Vector2D &right_vector){

        return Vector2D(left_vector.getX() + right_vector.getX(), left_vector.getY() + right_vector.getY());
    }
    
    Vector2D operator *(const Vector2D &vec, int scalar){
        return Vector2D(vec.getX() * scalar, vec.getY() * scalar);
    }
    Vector2D operator *(int scalar, const Vector2D &vec){
        return Vector2D(vec.getX() * scalar, vec.getY() * scalar);
    }   
    
    


int main(){
    
    Vector2D v1(3.5, 4.5); 
    Vector2D v2(1.0, 2.0);
    Vector2D v3 = v1 + v2;
    std::cout << "v1: ";
    v1.printVector();
    std::cout << "v2: ";
    v2.printVector();
    std::cout << "v3: ";
    v3.printVector();
    v3.operator+=(v1);
    std::cout << "v3 after adding v1: ";
    v3.printVector();
    Vector2D v4 = v3 * 2;
    std::cout << "v4 (v3 multiplied by 2): ";
    v4.printVector();
    
    return 0;
}