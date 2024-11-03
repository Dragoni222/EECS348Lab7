#include <iostream>

const int SIZE = 4;

class Matrix {
    public:
        int data[SIZE][SIZE];

        void readFromStdin() {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    std::cin >> data[i][j];
                }
            }
        }

        void display() const{
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    std::cout << data[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }

        Matrix operator+(const Matrix & m2) const{
            Matrix finalm;

            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    finalm.data[i][j] = data[i][j] + m2.data[i][j];
                }
            }
            return finalm;
        }

        Matrix operator*(const Matrix & m2) const{
            Matrix finalm;
            for (int i = 0; i < SIZE; i++) {
                for(int j = 0; j < SIZE; j++) {
                    finalm.data[i][j] = 0;
                    for (int k = 0; k < SIZE; k++) {
                        finalm.data[i][j] += data[i][k] * m2.data[k][j];
                    }

                }
            }
            return finalm;
        }

        int sumOfDiagonals() const {
            int sum = 0;
            for (int i = 0; i < SIZE; i++) {
                sum+=data[i][i];
            }
            return sum;
        }

        void swapRows(int row1, int row2) {
            if (row1 < SIZE && row2 < SIZE) {
                int temp[SIZE];
                for (int i = 0; i < SIZE; i++) {
                    temp[i] = data[row1][i];
                    data[row1][i] = data[row2][i];
                    data[row2][i] = temp[i];
                }
            }

        }



};


int main()
{
    Matrix m;
    Matrix m2;
    std::cout<<"Enter matrix 1 elements:"<<std::endl;
    m.readFromStdin();
    std::cout<<"Matrix 1(enter to continue):"<<std::endl;
    m.display();
    std::cin.ignore();
    std::cin.ignore();
    std::cout<<"Enter matrix 2 elements:"<<std::endl;
    m2.readFromStdin();
    std::cout<<"Matrix 2 (enter to continue):"<<std::endl;
    m2.display();
    std::cin.ignore();
    std::cin.ignore();
    std::cout<<"Matrix 1 + Matrix 2 (enter to continue):"<<std::endl;
    (m + m2).display();
    std::cin.ignore();
    std::cout<<"Matrix 1 * Matrix 2 (enter to continue):"<<std::endl;
    (m * m2).display();
    std::cin.ignore();
    std::cout<<"Matrix 1 sum of diagonal elements (enter to continue):" << m.sumOfDiagonals()<<std::endl;
    std::cin.ignore();
    std::cout<<"Matrix 1 swap rows 2 and 3: (enter to end):"<<std::endl;
    m.swapRows(1,2);
    m.display();
    std::cin.ignore();
    return 0;
}
