#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    struct info
    {
        char Surname[30];
        char BookName[30];
        int year;
    };

    ifstream Bibl("d:\\1\\Bibl.txt");
    info infoarr[5];

    char book[30] = "Informatics";
    int i = 0;
    bool need[5];
    string s;
    if (Bibl.is_open()) {

        while (!Bibl.eof())
        {
            Bibl >> infoarr[i].Surname >> infoarr[i].BookName >> infoarr[i].year;

            cout << infoarr[i].Surname << "\t\t" << infoarr[i].BookName << "\t\t" << infoarr[i].year << endl;
            if (string(infoarr[i].BookName) == book)
            {
                need[i] = true;
                /*cout << "\nАвтор\t" << infoarr[i].Surname << "\tНазвание\t" << infoarr[i].BookName << "\tГод написания книги " << infoarr[i].year << endl;*/
                
            }
            else
            {
                need[i] = false;
            }
            i++;

        }

        Bibl.close();
        for (i = 0; i < 5; i++) {
            if (need[i]) {
                cout << "\nАвтор\t" << infoarr[i].Surname << "\tНазвание\t" << infoarr[i].BookName << "\tГод написания книги " << infoarr[i].year << endl;
            }
        }
    }
    else cout << "файл не открыт";
    
    return 0;
}

