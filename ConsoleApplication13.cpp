// ConsoleApplication13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

class adress
{

public:
    void set_gorod(std::string gorod) { this->gorod = gorod; }
    std::string get_gorod() { return this->gorod; }
    void set_street(std::string street) { this->street = street; }
    std::string get_street() { return this->street; }
    void set_dom(int dom) { this->dom = dom; }
    int get_dom() { return this->dom; }
    void set_kvartira(int kvartira) { this->kvartira = kvartira; }
    int get_kvartira() { return this->kvartira; }
    adress()
    {
        this->gorod = "НЕТ";
        this->street = "НЕТ";
        this->dom = 0;
        this->kvartira = 0;

    }


private:
    std::string gorod;
    std::string street;
    int dom;
    int kvartira;
};






int main()
{
    setlocale(LC_ALL, "Russian");
    std::ifstream fin("in.txt");
    std::string s;
    int i, j, kol, vrem;
    if (fin.is_open())
    {
        fin >> s;
        kol = stoi(s);
        //std::cout << "количество строк: " << kol << std::endl;
        adress* adr = new adress[kol];
        for (i = 0; i < kol; i++)
        {
            fin >> s;
            adr[i].set_gorod(s);
            // std::cout << "Город: " << s << std::endl;
            fin >> s;
            // std::cout << "Улица: " << s << std::endl;
            adr[i].set_street(s);
            fin >> s;
            // std::cout << "Дом: " << s << std::endl;
            adr[i].set_dom(stoi(s));
            fin >> s;
            // std::cout << "Квартира: " << s << std::endl;
            adr[i].set_kvartira(stoi(s));
        }// for (i = 0; i < kol; i++)

        fin.close();
        
        for (j = 0; j < kol-1; j++)
        {
            for (i = kol - 1; i>j; i--)
            {
                if (adr[i].get_gorod().compare(adr[i - 1].get_gorod())==1)
                {
                    s = adr[i].get_gorod();
                    adr[i].set_gorod( adr[i - 1].get_gorod());
                    adr[i - 1].set_gorod(s);
                    s = adr[i].get_street();
                    adr[i].set_street(adr[i - 1].get_street());
                    adr[i - 1].set_street(s);
                    vrem = adr[i].get_dom();
                    adr[i].set_dom(adr[i - 1].get_dom());
                    adr[i - 1].set_dom(vrem);
                    vrem = adr[i].get_kvartira();
                    adr[i].set_kvartira(adr[i - 1].get_kvartira());
                    adr[i - 1].set_kvartira(vrem);

                }
            }
        }




        std::ofstream fout("out.txt");
        fout << kol << std::endl;








        for (i = kol-1; i >=0; i--)
        {
            s = adr[i].get_gorod();
            fout << s;
            // std::cout << "Город: " << s << std::endl;
            fout << ", ";
            s = adr[i].get_street();
            fout << s;
            // std::cout << "Улица: " << s << std::endl;
            fout << ", ";
            vrem = adr[i].get_dom();
            fout << vrem;
            // std::cout << "Дом: " <<vrem << std::endl;
            fout << ", ";
            vrem = adr[i].get_kvartira();
            fout << vrem;
            // std::cout << "Квартира: " << vrem << std::endl;
            fout << std::endl;

        }

        fout.close();
        delete[] adr;
    }
    else
    {
        std::cout << "Не получилось открыть файл! in.txt" << std::endl;
    }


}
/*
Задание:
В этом задании вы будете читать из файла адреса и выводить их в другой файл в другом формате, отсортированными по названию города.
Вам дан файл in.txt, в котором находится N адресов. Число N идёт первым в файле. После числа N располагаются N блоков по 4 строки в каждом. 
Каждый блок состоит из следующих строк: название города, название улицы, номер дома, номер квартиры.
Задача программы заключается в том, чтобы считать адреса из файла in.txt, отсортировать их по названию города и вывести отсортированный список адресов в файл out.txt в другом формате. 
Не забудьте вывести количество адресов в начале.
Города должны быть отсортированы в алфавитном порядке.
Формат вывода адреса: <название города>, <название улицы>, <номер дома>, <номер квартиры>.

Пример работы программы
in.txt
5
Москва
Строителей
34
12
Новокузнецк
Науки
5
16
Омск
Пушкина
2
13
Москва
Арбат
4
1
Новосибирск
Мира
85
64



out.txt
5
Москва, Строителей, 34, 12
Москва, Арбат, 4, 1
Новокузнецк, Науки, 5, 16
Новосибирск, Мира, 85, 64
Омск, Пушкина, 2, 13
*/



// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
