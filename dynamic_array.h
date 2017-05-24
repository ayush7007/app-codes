
class dynamic_array
    {
        int * data;
        int capacity;
        int lastIndex;


    public:

        dynamic_array()
        {
            capacity=2;
            lastIndex=-1;
            data= new int[capacity];
        }

        dynamic_array(int* toCopy, int Size) {
            // TODO
            capacity=2*Size;
            data=new int[capacity];
            int i;
            for(i=0;i<Size;i++)
            {
                data[i]=toCop[i];
            }
            lastIndex=i;

        }

        dynamic_array(dynamic_array const & d) {
            // TODO





        }


        ~dynamic_array()
        {
            capacity=0;
            lastIndex=-1;
            delete [] data;
        }

        int Size()
        {
            return lastIndex+1;
        }

        bool isEmpty()
        {
            return Size()==0 ;
        }


        int Pop_back()
        {
            if(isEmpty())
            {
                cout<<"NO element"<<endl;
                throw 10000;
            }
            int value=data[lastIndex];
            lastIndex--;
            return value;
        }

        int getElement(int index)
        {
            if(index>lastIndex)
            {
                return -1;
            }

            return data[index];

        }


        void Push_back(int element)
        {
            checkSize();
            data[lastIndex+1]=element;
            lastIndex++;
        }

        void setter(int index,int element)
        {
            if(index>lastIndex+1)
            {
                //error
                return ;
            }

            else if(index==lastIndex+1)
            {
                Push_back(element);
                return;
            }
            else{
                data[index]=element;
            }


        }


        void print()
        {
            cout<<" size="<<Size()<<endl;
            cout<<" capacity="<<capacity<<endl;
            for(int i=0;i<=lastIndex;i++)
            {
                cout<<data[i]<<" ";
            }
            cout<<endl;

        }

        dynamic_array& operator= (dynamic_array const & d) {

		// deep copy, update capacity & lastIndex
            if(d.Size()>=this->capacity)
            {
                capacity=2*capacity;
            }

            int * temp=new int[capacity];

            for(int i=0;i<d.Size();i++)
            {
                temp[i]=d.data[i];
            }

            delete [] data;
            this->data=temp;
            this->lastIndex=d.Size()-1;
            return *this;
        }



    private:

        void checkSize()
        {
            if(lastIndex==capacity-1)
            {
                int* temp=new int[2*capacity];
                for(int i=0;i<=lastIndex;i++)
                {
                    temp[i]=data[i];
                }
                delete [] data;
                data =temp;
                capacity=2*capacity;
            }
        }



    };
