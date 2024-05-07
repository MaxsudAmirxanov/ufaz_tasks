#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
char main_gusse(int guesses_number, int user_answer){
    if (guesses_number < user_answer){
        return 'g';
    }
    else if (guesses_number > user_answer)
    {
        return 's';
    }
    else if (guesses_number == user_answer){
        return 'f';
    }
    


}


int gusse_user(void){
    //Наша основная функция


    int a,b;

    
    // printf("Enter a gusses_number: \n");
    // scanf("%d", &a);

    a = rand()%1000;

    for (;;){
        printf("Enter a answer: ");
        scanf("%d", &b);
        char answ = main_gusse(a, b);
        // printf("%c\n",answ);
        // printf("123\n");

        if (answ == 'f'){
            printf("You find number !!! \n");
            break;
            
        }
        else if (answ == 's'){
            printf("Smaller\n");
        }
        else if (answ == 'g'){
            printf("Greater\n");
        }
   
    }
    return 0;
}

int gusse_computer(gusses_number){
    
    // for (int i=0;i!=400;i++){
    //     int rand_num = rand()%1000;
    //     printf("%d\n",rand_num);
    // }
    // rand_num = 0;
    int limit_min=0, limit_max=999;


    for(;;){
        //
        int rand_num = rand()%1000;
        if (limit_min<rand_num && limit_max>rand_num){
           
        }
        else continue;
        // printf("min - %d\n", limit_min);
        // printf("zagadannoe - %d\n", rand_num);
        // printf("max - %d\n", limit_max);


        char answ = main_gusse(gusses_number, rand_num);
        if (answ=='s'){
            limit_min=rand_num;
            printf("Smaller\n");
        }
        else if (answ=='g')
        {
            limit_max=rand_num;
            printf("Greater\n");
        }
        else if (answ=='f')
        {
            printf("You find number !!! \n");
            break;
        }
        
        
    }
    
    
    return 0;

    

}


int main(void){
    //Наша основная функция
    char user_answ;
    int num;
    printf("Who guesses the number? (u/c)");
    scanf("%c", &user_answ);
   
    if (user_answ == 'u'){
        //Какойто алгоритм с выполнением отгадывание пользователя
        gusse_user();

    }
    else if (user_answ=='c'){
        //Алгоритм для отгадывания компьютера 
        printf("Enter a number from 1 to 999\n");
        scanf("%d", &num);
        gusse_computer(num);
        
    }
    else printf("Wrong answer");




}