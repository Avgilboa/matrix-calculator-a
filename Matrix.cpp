#include "Matrix.hpp"
namespace zich{
    Matrix::Matrix(std::vector<double> value,unsigned int line,unsigned int column){
        if(value.size()!=column*line || line<1 || column<1){
            throw std::runtime_error("can't build this matrix");
        }
            this->column = column;
            this->line = line;
            this->mat = value;
    }
    Matrix Matrix::operator + (Matrix const other) const{
        if(this->line != other.line || this->column != other.column){
            throw std::runtime_error ("can't do the + functions between this matrixs");
        }
        std::vector<double> value;
        for(size_t i=0; i<this->line;i++){
            for(size_t j=0; j<this->column;j++){
                value.push_back(this->mat.at(i*this->column +j) + other.mat.at(i*this->column +j));
            }
        }
        return Matrix{value, this->line, this->column};
    }
    Matrix Matrix::operator--(int nevermind){
        Matrix temp(*this);
        for(size_t i=0; i<this->column*this->line;i++){
            this->mat.at(i)--;
        }
        return temp;
    }

    Matrix Matrix::operator++(int nevermind){
        Matrix temp(*this);
         for(size_t i=0; i<this->column*this->line;i++){
            this->mat.at(i)++;
        }
        return temp;
    }

    Matrix& Matrix::operator++(){
         for(size_t i=0; i<this->column*this->line;i++){
            this->mat.at(i)++;
        }
        return *this;
    }

    Matrix& Matrix::operator--(){
        for(size_t i=0; i<this->column*this->line;i++){
            this->mat.at(i)--;
        }
        return *this;
}


    Matrix Matrix::operator -(){
        std::vector<double> value;
        for(size_t i=0; i<this->line;i++){
            for(size_t j=0; j<this->column;j++){
                if(this->mat.at(i*column +j)!=0){
                    value.push_back(-1 * this->mat.at(i*column +j));
                }
                else{
                    value.push_back(0);
                }
            }
        }
        Matrix temp{value, this->line,this->column};
        return temp;
    }

    void Matrix::operator-=(Matrix const  other){
        if(this->line!=other.line || this->column!=other.column){
            throw std::runtime_error("The matrix not at the same size");
        }
        for(size_t i=0; i<this->column*this->line;i++){
            this->mat.at(i)-=other.mat.at(i);}
    }
    void Matrix::operator-=(double num){
        for(size_t i=0; i<this->column*this->line;i++){
            this->mat.at(i)-=num;}
    }
    void Matrix::operator*=(double scalar){
        for(size_t i=0; i<this->line;i++){
            for(size_t j=0; j<this->column;j++){
                this->mat.at((this->column*i) +j)*=scalar;
            }
        }
    }


    bool Matrix::operator == (Matrix const & other) const{
        if(this->line != other.line || this->column != other.column){
            throw std::runtime_error ("can't do the + functions between this matrixs");
        }
        for(size_t i=0; i<this->line;i++){
            for(size_t j=0; j<this->column;j++){
                if(this->mat.at(i*this->column +j)!=other.mat.at(i*this->column +j)){
                    return false;
                }
            }
        }
        return true;
    }

    void Matrix::operator*(double scalar){
        for(size_t i=0; i<this->line;i++){
            for(size_t j=0; j<this->column;j++){
                this->mat.at(i*this->column +j)*=scalar;
            }
        }
    }

    Matrix Matrix::operator*(Matrix const  other) const{
        if(this->column!=other.line){ throw std::runtime_error ("this matrixs vamt be multifiction");}
        std::vector<double> value(this->line*other.column,0);
        for(size_t place=0; place<this->line;place++){
            for(size_t i=0; i<other.column;i++){
                for(size_t j=0; j<this->column;j++){
                    value.at(place*other.column +i) += this->mat.at(place*this->column+j)* other.mat.at(j*other.column +i);
                }
            }
        }
        return Matrix(value,this->line, other.column);
    }

    Matrix Matrix::operator-(Matrix const other) const{
        if(this->line != other.line || this->column != other.column){
            throw std::runtime_error ("can't do the + functions between this matrixs");
        }
        std::vector<double> value;
        for(size_t i=0; i<this->line;i++){
            for(size_t j=0; j<this->column;j++){
                value.push_back(this->mat.at(i*this->column +j) - other.mat.at(i*this->column +j));
            }
        }
        return Matrix{value, this->line, this->column};
    }

    /* Friends functions  */

    Matrix operator*=(double scalar, Matrix const other){
        std::vector <double> value;
        for(size_t i=0; i<other.line;i++){
            for(size_t j=0; j<other.column;j++){
                value.push_back(scalar* other.mat.at(i*(other.column)  + j));
            }
        }
        Matrix temp ={value, other.line, other.column};
        return temp;
    }

    Matrix operator * (double scalar , Matrix const other){
        std::vector<double> value;
        for(size_t i=0; i<other.line;i++){
            for(size_t j=0; j<other.column;j++){
                value.push_back(scalar * other.mat.at(i*other.line +j));
            }
        }
        return Matrix{value,other.line,other.column};
    }

    std::ostream & operator << (std::ostream & oStream, Matrix const &  other){
        for(size_t i=0; i<other.line;i++){
            oStream << "[";
            for(size_t j=0;j<other.column-1;j++){
                oStream<<other.mat.at(i*other.column + j)<<" ";
            }
            oStream <<other.mat.at(i*other.column +other.column-1)<< "]" <<'\n';
        }
        return oStream;
    }
    
}