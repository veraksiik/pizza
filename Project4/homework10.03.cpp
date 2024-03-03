#include <iostream>
#include <string>
#include <Windows.h>

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string menu_pizzas[] = { "Пепперони", "Гавайская", "Четыре сыра", "Вегетарианская" };
    double prices_pizzas[] = { 10.0, 12.0, 15.0, 18.0 };
    int order_pizzas[4] = { 0 };

    std::string menu_drinks[] = { "Кола", "Фанта", "Спрайт" };
    double prices_drinks[] = { 2.5, 3.0, 4.0 };
    int order_drinks[3] = { 0 };

    double total_cost = 0.0;
    int user_choice, quantity;

    std::cout << "\n\tДобро пожаловать в нашу пиццерию \n";

   
    std::cout << "\n\t\tМеню пицц:\n";
    for (int i = 0; i < 4; ++i) {
        std::cout << i + 1 << ". " << menu_pizzas[i] << " - $" << prices_pizzas[i] << "\n";
    }

    std::cout << "\nВыберите пиццу (1-4) или 0 для завершения заказа: ";
    std::cin >> user_choice;

    while (user_choice != 0 && user_choice <= 4 && user_choice >= 1) {
        std::cout << "Сколько пицц \"" << menu_pizzas[user_choice - 1] << "\" вы хотите заказать?: ";
        std::cin >> quantity;
        order_pizzas[user_choice - 1] += quantity;
        total_cost += prices_pizzas[user_choice - 1] * quantity;

        std::cout << "\nВыберите пиццу (1-4) или 0 для завершения заказа: ";
        std::cin >> user_choice;
    }

    
    std::cout << "\nМеню напитков:\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << i + 1 << ". " << menu_drinks[i] << " - $" << prices_drinks[i] << "\n";
    }

    std::cout << "\nВыберите напиток (1-3) или 0 для завершения заказа: ";
    std::cin >> user_choice;

    while (user_choice != 0 && user_choice <= 3 && user_choice >= 1) {
        std::cout << "Сколько бутылок \"" << menu_drinks[user_choice - 1] << "\" вы хотите заказать?: ";
        std::cin >> quantity;
        order_drinks[user_choice - 1] += quantity;
        total_cost += prices_drinks[user_choice - 1] * quantity;

        std::cout << "\nВыберите напиток (1-3) или 0 для завершения заказа: ";
        std::cin >> user_choice;
    }

   
    if (total_cost > 50.0) {
        total_cost *= 0.8; 
    }

   
    std::cout << "\nЧек для оплаты:\n";

    
    for (int i = 0; i < 4; ++i) {
        if (order_pizzas[i] > 0) {
            std::cout << menu_pizzas[i] << " - " << order_pizzas[i] << " шт. - $" << prices_pizzas[i] * order_pizzas[i] << "\n";
        }
    }

   
    for (int i = 0; i < 3; ++i) {
        if (order_drinks[i] > 0) {
            std::cout << menu_drinks[i] << " - " << order_drinks[i] << " шт. - $" << prices_drinks[i] * order_drinks[i] << "\n";
        }
    }

    std::cout << "Итого к оплате: $" << total_cost << "\n";

    return 0;
}
