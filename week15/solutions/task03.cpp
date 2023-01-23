#include <iostream>

/*
    Да се напише рекурсивна функция, която намира броя на всички числа от интервала [a,b], цифрите на които образуват монотонно намаляваща редица.
*/

// Функция, която проверява дали цифрите на едно число образуват монотонно намаляваща редица.
bool isMonotonic(int n)
{
    // Ако числото е едноцифрено, тривиално цифрите му образуват такава редица
    if (n < 10)
        return true;

    // Вземаме последните две цифри на числото
    int lastDigit = n % 10;
    int lastToLastDigit = (n / 10) % 10;

    // Числото отговаря на условието, ако последната му цифра е по-голяма на предпоследната
    // и ако цифрите на числото без последната също образуват монотонно намаляваща редица
    return lastDigit >= lastToLastDigit && isMonotonic(n / 10);
}

// Основната функция
int countMonotonic(int a, int b)
{
    // Ако интервалът е празен, такива числа няма
    if (a > b)
        return 0;

    // Проверяваме дали текущото число отговаря на условието и добавяме бройката на всички останали числа от интервала, които отговарят на условието
    if (isMonotonic(a))
    {
        return 1 + countMonotonic(a + 1, b);
    }
    else
    {
        return countMonotonic(a + 1, b);
    }
}

int main()
{
    std::cout << countMonotonic(8, 35) << std::endl;
    return 0;
}