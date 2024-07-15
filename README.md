Имплементирайте функцията
char **stringSplit(const char *string, const char *delimiter, bool keepEmptyElements);

Функцията трябва да върне масив от под-стрингове които са получени чрез премахването на всички срещания на delimiter от string. Масивът трябва да е с точна големина като последният му елемент е nullptr. Елементите на масива трябва да са низове с точна дължина. Булевият флаг keepEmptyElements определя дали върнатият масив съдържа празни стрингове или не (в случай на последователни разделители).

Пример:
stringSplit("the  quick brown fox jumps over the brown fence ", " ", true) -> {"the", "", "quick", "brown", "fox", "jumps", "over", "the", "brown", "fence", nullptr}
