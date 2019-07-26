#include <iostream>

#include <random>
#include <string>
#include <time.h>
#include <math.h>
#include <exception>

// std::string* filterNumerals(std::string *input, int r)
template<typename T> // Does this really need to be here? // What is a realistic alternative to string? Stream? For voice control? Or maybe even something cooler.
class finance
{
    private:

    int startingCapital;
    T startingCurr;

    std::string input;

    int getFutureValue()
    {
        input.clear();
        std::cout << "What is your desired Total?" << "\nTotal : $";
        std::getline(std::cin, input);


        filterNumerals(&input, 0);

        std::string presentable = (*insertCharacters(&input, '.', (input.length() - 3), 0, 0)); // begin, frequency, stop >-< negative means it is input->length() - b
        presentable = (*insertCharacters(&presentable, ',', 4, 3, 0));


        int val = makeFloat(&input);

        std::cout << " * input * ->" << input << "\n";
        std::cout << "I got here!\n";
        std::cout << "std::stoi() : " <<  std::stoi(input) << "\n";
        return val;
    }

    T * insertCharacters(T *input, char src, int b, int f, int s) // b = begin, f = frequency, s = stop
    {
        std::cout << "insertCharacter()\n";
            try
            {
                if (input == nullptr || src == NULL  || b == NULL || f == NULL || s == NULL
                    || 0 > b || (b > (input->length() - 1)) || 0 > f || (f > (input->length() - 1)) || 0 > s || (s > (input->length() - 1)))
                {
                    std::cout << "\n\n**There was an error with these inputs, check them and try again.**\n";
                    std::cout << "\tinput : " << (*input) << " | input length : " << (input->length() - 1) << " | src : " << src << " | b : " << b << " | f : " << f <<" | s : " << s << " " << "\n\n\n";
                    std::exception e;
                    throw e;
                    return 0;
                }
            }
            catch(std::exception& e)
            {
            //    std::cerr << e.what() << '\n';
            }

        // flags
        
        bool si = false; // single insert
        bool dec = false;

        if(f == 0)
        {
            si = true;
        }

        if(si)
        {
            (*input)[b] = src;
        }
        std::cout << "src | si : " << src << std::boolalpha <<  " | " << si << "\n";
        if(src == '.' && si)
        {
            std::cout << "Decimal Check : " << (*input) << "\n";
            if((*input)[b] == src)
            {
                std::cout << "Decimal Index : " << input->find('.') << "\n";
                std::cout << "All good to go on the decimal front!\n\n";
                return input;
            }
            else 
            {
            }
        }

        if(si)
        {
            // (*input)[b] = src;
            // return input;
        }
        else
        {
            for(int i = 0; i < input->length() - s; (i += f))
            {
                (*input)[i] = src;
            }
            return input;
        }
        return input;
    }

    static T* filterNumerals(T* input, int ri)
    {
        int keyCode = (*input)[ri];
        bool replicatable = false;
        if((keyCode > 47 && keyCode < 58) || keyCode == 46) // 46 = . 47-58 = 0-9 
        {
            replicatable = true;
        }

        if(ri != (input->length() - 1))
        {
            filterNumerals(input, (ri + 1));
        }

        // std::cout << "\nKeycode : " << keyCode << "\nKeyChar : " << ((char) keyCode) << "\nReplicatable : " << std::boolalpha << replicatable << "\n";
        // std::cout << "ri : " << ri << "\nri++ : " << (ri + 1) << "\ninput : " << (*input) << "\n\n";

        char keyChar = (char) keyCode;
        if(replicatable)
        {
            (*input)[ri] = (char) keyCode;
        }
        else
        {
            if(ri < input->length())
            {
                input->erase(input->begin() + ri);
            }
        }

        // std::cout << "ri : " << ri << "\n";
        if(ri == (input->length() - 1))
        {
            return input;
        }
    }

    float makeFloat(std::string * input)
    {
        filterNumerals(input, 0);

        std::cout << "makeFloat() : " << (*input) << "\n";

        return std::stof(*input);
    }

    float makeFloat(std::string input)
    {
        filterNumerals(&input, 0);

        std::cout << "makeFloat() : " << input << "\n";
        
        return std::stof(input);
    }

    public:

    finance(int capital, T curr)
    {
        this->startingCapital = capital;
        this->startingCurr = curr;
    }

    void getKeyCodes()
    {
        std::string key;
        while(true)
        {
            std::getline(std::cin, key);
            std::cout << (int) key[0] << "\n";
        }
    }
    
    int getCompoundValue()
    {

        int a = 0;
        int p = 0;
        double r = 0;
        int c = 0;
        int y = 0;
        int u = 0;
        int g = 0;

        a  = getFutureValue();
        // p = getPricipal();
        // r = getInterestRate();
        // n = getTimesToContributeYearly();
        // c = getContribution();
        // y = getYears();
        // u = getTimeUnit(); // Codes that correspont to the correct unit of time
        // g = getCompoundValue(); // Growth, should previous growth go towards future growath?

        std::cout << " - " << a << " - \n"; 

        //solving for A
        double ip;
        // ip = pow((1 + (r/n)),  (n * y));
        // ip = (ip * p); 

        return ip;
    }

    
};