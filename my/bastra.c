
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Количество карт в колоде
#define NUM_CARDS 52
// Количество карт на руке у каждого игрока
#define HAND_SIZE 4
// Количество игроков
#define NUM_PLAYERS 4

// Структура для представления карты
typedef struct {
    char* rank;
    char* suit;
    int value;
} Card;

// Структура для представления колоды карт
typedef struct {
    Card cards[NUM_CARDS];
    int top;
} Deck;

// Структура для представления игрока
typedef struct {
    Card hand[HAND_SIZE];
    int score;
} Player;

// Функция для создания новой колоды карт
void create_deck(Deck* deck) {
    char* ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    char* suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    int index = 0;
    for (int rank = 0; rank < 13; rank++) {
        for (int suit = 0; suit < 4; suit++) {
            deck->cards[index].rank = ranks[rank];
            deck->cards[index].suit = suits[suit];
            deck->cards[index].value = (rank < 9) ? (rank + 2) : 10; // Для карт от 2 до 10 значение равно их рангу, для остальных 10
            index++;
        }
    }

    deck->top = NUM_CARDS - 1;
}

// Функция для перемешивания колоды
void shuffle_deck(Deck* deck) {
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

// Функция для раздачи карт каждому игроку
void deal_cards(Deck* deck, Player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < HAND_SIZE; j++) {
            players[i].hand[j] = deck->cards[deck->top];
            deck->top--;
        }
    }
}

// Функция для вывода карты на экран
void print_card(Card card) {
    printf("%s of %s\n", card.rank, card.suit);
}

// Функция для вывода карт на руке игрока
void print_hand(Player player) {
    printf("Player's Hand:\n");
    for (int i = 0; i < HAND_SIZE; i++) {
        print_card(player.hand[i]);
    }
}

// Функция для совершения хода игрока
void player_turn(Player* player, Card* table, int* num_table_cards) {
    int choice;
    printf("Player's Hand:\n");
    for (int i = 0; i < HAND_SIZE; i++) {
        printf("%d. ", i + 1);
        print_card(player->hand[i]);
    }
    printf("Choose a card to play (1-%d): ", HAND_SIZE);
    scanf("%d", &choice);

    // Перемещаем выбранную карту на стол
    table[*num_table_cards] = player->hand[choice - 1];
    (*num_table_cards)++;

    // Удаляем карту из руки игрока
    for (int i = choice - 1; i < HAND_SIZE - 1; i++) {
        player->hand[i] = player->hand[i + 1];
    }
}

// Функция для сбора карт со стола и начисления очков
void collect_cards(Player* player, Card* table, int* num_table_cards) {
    for (int i = 0; i < *num_table_cards; i++) {
        player->score += table[i].value;
    }
    *num_table_cards = 0;
}

int main() {
    srand(time(NULL)); // Инициализация генератора случайных чисел

    // Создание колоды и ее перемешивание
    Deck deck;
    create_deck(&deck);
    shuffle_deck(&deck);

    // Инициализация игроков
    Player players[NUM_PLAYERS];
    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i].score = 0;
    }

    // Раздача карт
    deal_cards(&deck, players, NUM_PLAYERS);

    // Игровой цикл
    int current_player = 0;
    int num_table_cards = 0;
    Card table[HAND_SIZE];

    while (deck.top >= 0) {
        printf("\nPlayer %d's turn:\n", current_player + 1);
        print_hand(players[current_player]);
        player_turn(&players[current_player], table, &num_table_cards);
        current_player = (current_player + 1) % NUM_PLAYERS;
    }

    // Сбор карт со стола и начисление очков
    for (int i = 0; i < NUM_PLAYERS; i++) {
        collect_cards(&players[i], table, &num_table_cards);
    }

    // Вывод результатов
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d's score: %d\n", i + 1, players[i].score);
    }

    return 0;
}
