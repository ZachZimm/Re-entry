#define FINT_H
#ifndef FINT_H

template<class T>
struct fint
{
    private:
        int intVal;
        T curr;


    public:
        template<class T>
        fint()
        {
            intVal = 0;
        }

        template<class T>
        fint(T input)
        {
            intVal = (int) (input * 10);
        }
    
        int getIntVal()
        {
            return intVal;
        }

        template<class T>
        void setIntVal(T input)
        {
            intVal = input;
        }    

        template<class T>
        void operator =(T other)
        {
            intVal = (int) (other * 10);
        }

        template<class T>
        fint<T> operator ++()
        {
            intVal = intVal + 10;
            return this;
        }
};

#endif