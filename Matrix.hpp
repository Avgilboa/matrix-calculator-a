#pragma once

#include <iostream>
#include <vector>

namespace zich{
    class Matrix{
        private:
            unsigned int column;
            unsigned int line;
            std::vector<double> mat;

        public:

            unsigned int getCol() const {return this->column;}
            Matrix operator+(Matrix const other) const;                                                        /////V     
            Matrix& operator++();                          ///prefix
            Matrix operator++(int nevermind);              //postfix
            Matrix operator+=(Matrix const  other);
            Matrix operator +();


            Matrix operator-(Matrix const  other) const;
            void operator-=(Matrix const  other);
            void operator-=(double num);
            Matrix& operator--();   ///prefix operator
            Matrix operator--(int nevermind);
            Matrix operator -();                                                                              //////V


            friend Matrix operator * (double scalar , Matrix const other);                                    //////V
            Matrix operator*(Matrix const  other) const;
            void operator*(double scalar);
            Matrix operator*=(Matrix const  other);
            void operator*=(double scalar);                                                                 //////V
            friend Matrix operator*=(double scalar, Matrix const other);                                      //////V

            bool operator<=(Matrix const & other) const ;
            bool operator<(Matrix  const & other)const ;
            bool operator>(Matrix  const & other) const ;
            bool operator>=(Matrix const & other)const ;
            Matrix operator<<(Matrix const & other)const ;
            Matrix operator>>(Matrix const & other)const ;

            bool operator == (Matrix const & other) const;

            friend std::ostream & operator << (std::ostream & oStream ,Matrix const &  other);                 ////V
            friend std::istream & operator >> (std::istream & iStream , Matrix & other);

            Matrix(std::vector<double> value,unsigned int line,unsigned int column);                           ////V
            Matrix();
            ~Matrix(){};
    };
}