#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;
void playRound() {
    int secret = rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;
    cout << "\nЯ загадала число от 1 до 100. Попробуй угадать!" << endl;
    while (true) {
        cout << "Твоё число: ";
        cin >> guess;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Введи целое число." << endl;
            continue;
        }
        attempts++;
        if (guess < secret) {
            cout << "Больше!" << endl;
        } else if (guess > secret) {
            cout << "Меньше!" << endl;
        } else {
            cout << "Поздравляю! Ты угадал(а) за " << attempts << " попыток." << endl;
            break;
        }
    }
}
int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    cout << "=== Игра 'Угадай число' ===" << endl;
    char again;
    do {
        playRound();
        cout << "Сыграем ещё? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');
    cout << "Спасибо за игру!" << endl;
    return 0;
}