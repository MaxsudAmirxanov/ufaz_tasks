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
        if (b >999 || 0>b){
            printf("try again !");
            continue;
        }
        char answ = main_gusse(a, b);
        // printf("%c\n",answ);
        // printf("123\n");

        if (answ == 'f'){
            printf("You find number !!! \n");
            return 'f';
            
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
        printf("zagadannoe - %d\n", rand_num);
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
            return 'f';
        }
        
        
    }
    
    
    return 0;

    

}

int gusse_computer_2(gusses_number){
    
    // for (int i=0;i!=400;i++){
    //     int rand_num = rand()%1000;
    //     printf("%d\n",rand_num);
    // }
    // rand_num = 0;
    int limit_min=0, limit_max=999;


    for(;;){
        //
        char user_answer;
        int rand_num = rand()%1000;
        if (limit_min<rand_num && limit_max>rand_num){
           
        }
        else continue;
        printf("min - %d\n", limit_min);
        printf("zagadannoe - %d\n", rand_num);
        printf("max - %d\n", limit_max);


        char answ = main_gusse(gusses_number, rand_num);

        for (;;){
            // getchar();
            scanf(" %c", &user_answer);
            // getchar();

            if (user_answer != main_gusse(gusses_number, rand_num)){
                printf("(Your answer is corect ?) )\n");
            }
            else break;
        }

        // if (answ == 'f'){
        //     printf("You find number !!! \n");
        //     return 'f';
        // }

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
            return 'f';
        }

        
        
    }
    
    
    return 0;

    

}


int main(void){
    //Наша основная функция
    char user_answ, an;
    int num;
    for (;;){
        printf("Who guesses the number? (u/c)\n");
        scanf("%c", &user_answ);
        printf("%c",user_answ);
        getchar();
    
        if (user_answ == 'u'){
            //Какойто алгоритм с выполнением отгадывание пользователя
            char res = gusse_user();
            if (res == 'f'){
                printf_s("Did you vanna try again ? (y/n)");
                scanf(" %c", &an);
                if (an == 'y'){
                    continue;
                }
                else if (an == 'n')
                {
                    printf("Good luk !!");
                    exit(0);
                }
                
            }

        }
        else if (user_answ=='c'){
            //Алгоритм для отгадывания компьютера 
            char an_1;
            printf("Enter a number from 1 to 999\n");
            scanf("%d", &num);
            if (num >999 || 0>num){
                printf("try again !\n");
                exit(0);
            }
            // printf("test");
            char res = gusse_computer_2(num);
            if (res == 'f'){
                printf_s("Did you vanna try again ? (y/n)\n");
                // scanf("%c", &an_1);
                scanf_s(" %c", &an_1);
                printf("tes\n");
                if (an_1 == 'y'){
                    printf("test_2\n");
                    continue;
                }
                else if (an_1 == 'n')
                {
                    printf("Good luk !!\n");
                    exit(0);
                }
                
            }
            
        }
        else printf("Wrong answer\n");

    }





}


// scanf(" %с%с%с", &k1, &k2, &k3);//"Не рабочий" вариант
// scanf(" %c%c%c", &k1, &k2, &k3);//Рабочий вариант