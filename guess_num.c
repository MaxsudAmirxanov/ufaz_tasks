#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    void comp_guess(int user_rand_num,int comp_estim_num){
    char hint;
    int min_lim=1;
    int max_lim=999;
    printf("enter a number between(1-999)");
    scanf("%d",&user_rand_num);
    do{ 
    srand(time(NULL));
    int random_number = rand() % (max_lim - min_lim + 1) + min_lim;
    printf("%d\n",random_number);
    getchar();
    scanf("%c",&hint);
    if(hint=='s'){
        min_lim=random_number;
    }else if(hint=='g'){
        max_lim=random_number;
    }else if(hint=='f'){
        break;
    }else{
        printf("you entered a wrong hint try again");
    }
    }while(comp_estim_num!=user_rand_num);}


void user_guess(int random_number,int user_number){
    printf("Enter an estimated number (1-999): ");
    do{
        scanf("%d",&user_number);
        if(user_number<random_number){
            printf("Your number is SMALLER than estimated\n");
        }else if(user_number>random_number){
            printf("GYour number is GRATER than estimated\n");
        }else if(user_number==random_number){
            printf("You FIND the number\n");
            break;
        }else if(user_number<1 || user_number>999){
            printf("You entered a wrong number\n");
        }else{
            printf("ERROR!\n");
        }
    }while(random_number!=user_number);
}

int main() {
    int user_rand_num,comp_estim_num,user_number;
    char player;
    char play_again = 'y';

    srand(time(NULL));

    do {
        int random_number = rand() % 999 + 1;
        printf("Who will guess the number? Computer or User (c/u): ");
        scanf("%c", &player);
        getchar();

        if (player == 'c') {
            comp_guess(user_rand_num,comp_estim_num);
        } else if (player == 'u') {
            user_guess(random_number, user_number);
        } else {
            printf("You entered a wrong answer!\n");
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
        getchar(); // Consume newline character

    } while (play_again == 'y');

    return 0;
}