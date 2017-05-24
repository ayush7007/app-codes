#include<iostream>
#include<vector>

class polynomial
    {
            int degree;

            vector<int>* coefficient;


        public:

            polynomial(int degree)
            {
                this->degree=degree;
               coefficient=new vector<int>(degree+1);
            }

            int getCoefficient(int i)
            {
                if(i>degree)
                {
                    return 0;
                }

                else{
                    return coefficient[i];
                }
            }



            void setCoefficient(int i,int coeff)
            {
                if(i>coefficient.size())
                {
                    for(int j=coefficient.size();j<i;i++)
                    {
                        coefficient.push_back(0);
                    }
                    push_back(coeff);
                    degree=i;

                }

                else{

                    coefficient[i]=coeff;
                }

            }

    };
