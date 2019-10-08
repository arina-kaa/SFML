#include <iostream>

int main()
{
    // начальное действие: объявить переменную num, равную 1
    // условие: пока num меньше или равно 100
    // после каждого шага (итерации) цикла добавляем к num единицу
    for (int num = 1; num <= 100; num += 1)
    {
        //  - если число кратно 3 и 5
        if ((num % 3 == 0) && (num % 5 == 0))
        {
            // выводим FizzBuzz
            std::cout << "FizzBuzz" << std::endl;
        }
        //  - если число кратно 3
        else if (num % 3 == 0)
        {
            // выводим Fizz
            std::cout << "Fizz" << std::endl;
        }
        //  - если число кратно 5
        else if (num % 5 == 0)
        {
            // выводим Buzz
            std::cout << "Buzz" << std::endl;
        }
        else
        {
            // выводим num
            std::cout << num << std::endl;
        }
    }
}