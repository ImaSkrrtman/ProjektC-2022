#include <iostream>
#include <map>

int fibbonaci(int a, std::map<int,int> *fib_data)
{
    if(a == 0)
    {
        return 0;
    }
    if(a == 1)
    {
        return 1;
    }
     //if(*fib_data.find(a)!=*fib_data.end())//true kiedy a jest kluczem w mapie
     if (*fib_data[5]==10)
    {

        std::cout<<"chuj nie wiem nie dziala cos";
    }

    return fibbonaci(a-1,fib_data)+fibbonaci(a-2,fib_data);
}

int main()
{
   std::map<int,int> fib_data;
   fib_data.insert(std::pair<int, int>{5, 112})
   fibbonaci(2,&fib_data);
}