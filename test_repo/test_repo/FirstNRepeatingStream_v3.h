// Реализовать класс, который обрабатывает поток символов и выдаёт первый символ (в порядке появления символа в потоке),
// который повторялся не больше N раз, а если такого символа нет - выдаёт std::nullopt.
//
// Например:
//
// N=1
// вход  выход
// a   ->   a
// b   ->   a
// b   ->   a
// c   ->   a
// a   ->   c
// c   ->   nullopt
// f   ->   f
// g   ->   f
//
//
// N=2
// вход     выход
// b   ->   b
// c   ->   b
// f   ->   b
// b   ->   b
// f   ->   b
// c   ->   b
// b   ->   c
// c   ->   f
// c   ->   f
// f   ->   nullopt
// c   ->   nullopt
// c   ->   nullopt
// b   ->   nullopt
// b   ->   nullopt
//
// На вход алгоритм должен уметь принимать любой char.
// Оценивается корректность, читаемость и эффективность (по быстродействию) реализации.
// Решение должно быть подано в виде одного .h файла с реализацией класса FirstNRepeatingStream,
// который должен иметь интерфейс, описанный ниже:

#include<iostream>
#include<optional>
#include<map>
#include<list>

class FirstNRepeatingStream {
public:
    FirstNRepeatingStream(int N);
    std::optional<char> next(char c);
private:
    int repeatCount;
    std::map<char, int> inputStreamMap;
    std::list<char> correctInputList;
};



// можно использовать любые заголовки из стандарта С++, код будет проверяться на C++17


void testCharacterInputStream(std::string a_inputStream, int a_repeatCount);