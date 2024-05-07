#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int value;
    enum {SPADES, HEARTS, DIAMONDS, CLUBS} suit;
} Card;

typedef struct {
    Card cards[4];
    int num_cards;
} Hand;

void initialize_deck(Card deck[]) {
    int index = 0;
    for (int value = 1; value <= 13; value++) {
        for (int suit = SPADES; suit <= CLUBS; suit++) {
            deck[index].value = value;
            deck[index].suit = suit;
            index++;
        }
    }
}

void shuffle_deck(Card deck[]) {
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal_cards(Card deck[], Hand hands[], Card board[]) {
    int index = 0;
    for (int i = 0; i < 4; i++) {
        hands[i].num_cards = 0;
        for (int j = 0; j < 4; j++) {
            hands[i].cards[j] = deck[index++];
            hands[i].num_cards++;
        }
    }
    for (int i = 0; i < 4; i++) {
        board[i] = deck[index++];
    }
}

void print_card(Card card) {
    const char *values[] = {"", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    const char *suits[] = {"♠", "♥", "♦", "♣"};
    printf("%s%s ", values[card.value], suits[card.suit]);
}

void print_hand(Hand *hand) {
    for (int i = 0; i < hand->num_cards; i++) {
        print_card(hand->cards[i]);
    }
    printf("\n");
}

void print_board(Card board[]) {
    printf("Board: ");
    for (int i = 0; i < 4; i++) {
        print_card(board[i]);
    }
    printf("\n");
}

Card choose_card(Hand *hand) {
    printf("Select a card to play (1-4): ");
    int choice;
    scanf("%d", &choice);
    return hand->cards[choice - 1];
}

void play_card(Card card, Hand *hand, Card board[]) {
    int empty_slot = -1;
    for (int i = 0; i < 4; i++) {
        if (board[i].value == 0) {
            empty_slot = i;
            break;
        }
    }
    if (empty_slot != -1) {
        board[empty_slot] = card;
    } else {
        int replace_index = -1;
        for (int i = 0; i < 4; i++) {
            if (card.value == 11 && board[i].value == 11) {
                replace_index = i;
                break;
            } else if (card.value != 11 && board[i].value == 11) {
                replace_index = i;
                break;
            }
        }
        if (replace_index != -1) {
            board[replace_index] = card;
        }
    }

    for (int i = 0; i < hand->num_cards; i++) {
        if (hand->cards[i].value == card.value && hand->cards[i].suit == card.suit) {
            for (int j = i; j < hand->num_cards - 1; j++) {
                hand->cards[j] = hand->cards[j + 1];
            }
            hand->num_cards--;
            break;
        }
    }
}

int check_winner(Hand hands[], int scores[]) {
    for (int i = 0; i < 4; i++) {
        if (scores[i] >= 100) {
            return i + 1;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    Card deck[52];
    initialize_deck(deck);
    shuffle_deck(deck);
    Hand hands[4];
    Card board[4];
    deal_cards(deck, hands, board);

    int scores[4] = {0};

    int round_num = 1;
    while (1) {
        printf("\nRound %d\n", round_num);
        for (int i = 0; i < 4; i++) {
            printf("Player %d hand: ", i + 1);
            print_hand(&hands[i]);
        }
        print_board(board);

        for (int i = 0; i < 4; i++) {
            printf("\nPlayer %d's turn:\n", i + 1);
            Card played_card = choose_card(&hands[i]);
            play_card(played_card, &hands[i], board);
        }

        int winner = check_winner(hands, scores);
        if (winner != 0) {
            printf("\nPlayer %d wins with %d points!\n", winner, scores[winner - 1]);
            break;
        }

        round_num++;
    }

    return 0;
}
