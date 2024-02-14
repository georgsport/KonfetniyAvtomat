#include <iostream>
#include <conio.h>

class CashRegister {
private:
	int cashOnHand;
public:
	int getCurrentBalance() {
		return cashOnHand;
	}
	void acceptAmount(int amount) {
		cashOnHand += amount;
	}
	CashRegister() {
		cashOnHand = 500;
	}
	CashRegister(int amount) {
		cashOnHand = amount;
	}
};

class DispenserType {
private:
	int numberOfItems;
	int cost;
public:
	DispenserType() {
		numberOfItems = 50;
		cost = 50;
	}
	DispenserType(int items, int itemCost) {
		numberOfItems = items;
		cost = itemCost;
	}
	int getNoOfItems() {
		return numberOfItems;
	}
	int getCost() {
		return cost;
	}
	void makeSale() {
		numberOfItems -= 1;
	}
};

void showSelection();
void sellProduct(CashRegister* cashRegister, DispenserType* dispenser);

int main()
{
    setlocale(LC_ALL, "rus");

    CashRegister* cashRegister = new CashRegister();
    DispenserType* gum = new DispenserType(10, 40);
    DispenserType* chipsy = new DispenserType(75, 70);
    DispenserType* pechenye = new DispenserType(80, 30);
    DispenserType* konfety = new DispenserType(20, 5);
    //и так далее

    int choice;
    showSelection();
    std::cin >> choice;
    while (choice != 0) {
        switch (choice) {
        case 1:
            sellProduct(cashRegister, gum);
            break;
        case 2:
            sellProduct(cashRegister, chipsy);
            break;
        case 3:
            sellProduct(cashRegister, pechenye);
            break;
        case 4:
            sellProduct(cashRegister, konfety);
            break;
        default:
            printf("Неверный выбор");
        }

        printf("Нажмите Enter, чтобы продолжить");
        _getch();
        system("cls");

        showSelection();
        std::cin >> choice;
    }


    system("pause");
    return 0;
}

void showSelection()
{
    printf("В наличии:\n"
        "1. Жвачка - 30 рублей\n"
        "2. Чипсы - 70 рублей\n"
        "3. Печенье - 30 рублей\n"
        "4. Конфеты - 5 рублей\n"
        "Введите номер соответствующего товара или 0, чтобы выйти: ");
}

void sellProduct(CashRegister* cashRegister, DispenserType* dispenser)
{
    int summa;

    if (dispenser->getNoOfItems() == 0) {
        printf("Товар закончился!\n");
        return;
    }

    printf("Стоимость товара: %i. Внесите оплату.\n"
        "Внесённая сумма: ", dispenser->getCost());
    std::cin >> summa;
    if (summa < dispenser->getCost()) {
        printf("Внесено недостаточно.\n");
        return;
    }

    cashRegister->acceptAmount(summa);
    dispenser->makeSale();
    printf("Заберите свой товар в окошке выдачи.\n");
}
