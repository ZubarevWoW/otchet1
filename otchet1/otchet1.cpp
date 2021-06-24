#include <iostream>
#include <string>
using namespace std;
class Harbinger
{
private:
    string h_name;
    string CatchPhrase;
    int h_age;
public:
    Harbinger(string name = " Some Harbinger ", int age = 20, string catchPhrase = " Hello there ")
        : h_name(name), h_age(age), CatchPhrase(catchPhrase) {}
    string getName() { return h_name; } //геттер
    const string& getCatchPhrase() { return CatchPhrase; } //геттер
    void setCatchPhrase(const string& catchPhrase) { CatchPhrase = catchPhrase; } //сеттер
    int getAge() { return h_age; } // геттер
};
class Prophet : public Harbinger {
private:
    string MagnumOpus[3];
    string ph_name;
    int ph_age;
    string ph_call;
public:
    const string* getMagnumOpus() { return MagnumOpus; }
    void setMagnumOpus(string magnumOpus[]) {
        for (int i = 0; i < 3; ++i) {
            if (magnumOpus[i].length() > 25) { // Проверка на размер
                cout << " Элементы слишком большие " << endl;
                return;
            }
        }
        for (int i = 0; i < 3; ++i) {
            MagnumOpus[i] = magnumOpus[i];

            if (!ph_call.empty() && ph_call.length() < magnumOpus[i].length()) { // при пустом ph_all и больше ph call меняется ph_call
                ph_call = magnumOpus[i];
            }
        }
    };
    const string& getPhName() { return ph_name; } //геттер
    void setPhName(const string& phName) { ph_name = phName; } //сеттер
    const string& getPhCall() { return ph_call; } //геттер
    void setPhCall(const string& phCall) { ph_call = phCall; } //сеттер
    int getPhAge() { return ph_age; } //геттер
    void setPhAge(int phAge) { ph_age = phAge; } //сеттер
};
class DeusEx : public Prophet {

private:
    string gd_name;
    int gd_year;
public:
    DeusEx(const string& gdName = " Инокентий ", int gdYear = 1967) : gd_name(gdName), gd_year(gdYear) {
    }
    string& getGdName() { return gd_name; }
    int getGdYear() { return gd_year; }
    void inTheNameOfGod() {
        setlocale(LC_ALL, "RU");
        cout << " %s в возрасте %d говорил, что %s\n " << getName().c_str() << getAge() << getCatchPhrase().c_str();
        cout << " Первое пророчество: %s\n " << getMagnumOpus()[0].c_str();
        cout << " Второе пророчество: %s\n " << getMagnumOpus()[1].c_str();
        cout << " Главное пророчество: %s\n " << getPhCall().c_str();
        cout << " Так говорил %s в возрасте %d.\n " << getPhName().c_str() << getPhAge();
        cout << " В год %d пришёл %s, которого предрекали %s и %s.\n " << getGdYear() << getGdName().c_str() << getName().c_str() << getPhName().c_str();
    }
};
class Believer : public DeusEx { //унаследование DeusEx
private:
    string bv_name;
    int bv_age;
public:
    Believer(const string& bvName, int bvAge) : bv_name(bvName), bv_age(bvAge), DeusEx() {}
    string& getBvName() { return bv_name; } //геттер 
    void setBvName(string& bvName) { bv_name = bvName; } //сеттер
    int getBvAge() { return bv_age; }//геттер
    void setBvAge(int bvAge) { bv_age = bvAge; } //сеттер
    void believerSays() {
        cout << " Верующий %s молится %s именем %s. C %d и по сей день.\n " << getBvName().c_str() << getGdName().c_str() << getPhName().c_str() << getGdYear();
    }
};
int main()
{
    Believer believer(" Супер ", 12);
    believer.setCatchPhrase(" Боже мой ");

    believer.setPhAge(12);
    believer.setPhCall(" Вау ");
    believer.setPhName(" Воу ");

    string magnumOpus[] = { " Москва "," Питер "," Новгород " };
    believer.setMagnumOpus(magnumOpus);

    believer.inTheNameOfGod();
    cout << endl;
    believer.believerSays();
    system("pause");
    return 0;
}
