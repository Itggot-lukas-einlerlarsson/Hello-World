#include <iostream>
#include <fstream>

class Person
{
public:
    int age,
        height,
        weight;
    std::string name,
                country;
    bool create_data();
    void send_data_to_file();
};

class Young : Person
{
private:
    Person young;
public:
    void set_data();
    void change_data();
    void print_data();
};

bool Person::create_data()
{
    char answer;
    std::cout << "Welcome to DataMem! Do you want to store your info? (Y/N)";
    std::cin >> answer;
    while ((answer != 'N') && (answer != 'Y') && !std::cin.fail())//(answer != 'y') || (answer != 'Y') || (answer != 'n') || (answer != 'N'))
    {
        std::cout << "Answer needs to only be either Y or N" << "\nYour answer: ";
        std::cin >> answer;
    }
    if (answer == 'y' || answer == 'Y')
        return true;
    else
        return false;
}

void Person::send_data_to_file()
{
    std::ofstream afile("filename.txt", std::ios_base::app);
    if (afile.is_open())
    {
        afile << "Person: " << name << '\n'
              << "Country: " << country << '\n'
              << "Age: " << age << " years old\n"
              << "Height: " << height << "cm\n"
              << "Weight: " << weight << "kg\n\n";
        afile.close();
    }
}

void Young::set_data()
{
    std::cout << "Fill in your info under:" << '\n';
    std::cout << "Age: ";
    std::cin >> young.age;
    std::cout << "Height(cm): ";
    std::cin >> young.height;
    std::cout << "Weight(kg): ";
    std::cin >> young.weight;
    std::cout << "Name: ";
    std::cin >> young.name;
    std::cout << "Country: ";
    std::cin >>  young.country;
    young.send_data_to_file();
    std::cout << "Your info is saved." << "\n\n";
 }

 void Young::change_data()
 {
     int answer;
     std::cout << "What data do you wish to change?" << '\n'
               << "0. I don't want to change any data." << '\n'
               << "1. Age" << '\n'
               << "2. Height" << '\n'
               << "3. Weight" << '\n'
               << "4. Name" << '\n'
               << "5. Country" << '\n';
     std::cout << "Your answer: " << '\n';
     std::cin >> answer;
     while (answer < 0 || answer > 5) // cin fail fungerar ej.
     {
         std::cout << "Answer can only be 0-5 and integers." << '\n';
         std::cout << "Your answer: " << '\n';
         std::cin >> answer;
     }
     switch (answer)
     {
         case 1:
            std::cout << "Your age: ";
            std::cin >> young.age;
            std::cout << "Your new age: " << young.age << '\n';
            break;
        case 2:
            std::cout << "Your height: ";
            std::cin >> young.height;
            std::cout << "Your new height: " << young.height << '\n';
            break;
        case 3:
            std::cout << "Your weight: ";
            std::cin >> young.weight;
            std::cout << "Your new weight: " << young.weight << '\n';
            break;
        case 4:
            std::cout << "Your Name: ";
            std::cin >> young.name;
            std::cout << "Your new name: " << young.name << '\n';
            break;
        case 5:
            std::cout << "Your country: ";
            std::cin >> young.country;
            std::cout << "Your new country: " << young.country << '\n';
            break;
        default:
            break;
     }
     std::cout << std::endl;
}

void Young::print_data()
{
    std::cout << "Your age: " << young.age <<'\n'
              << "Your height: " << young.height << '\n'
              << "Your weight: " << young.weight << '\n'
              << "Your name: " << young.name << '\n'
              << "Your country: " << young.country << "\n\n";
}

int main(int argc, char const *argv[])
 {
     Person welcome;
     bool agree;
     do
     {
         agree = welcome.create_data();
         if (agree)
         {
             Young bengt;
             bool sure; // control i user want to change data.
             bengt.set_data();
             bengt.change_data();
             bengt.print_data();
         }
     } while(agree);
     std::cout << "Have a nice day." << '\n';
     return 0;
 }
