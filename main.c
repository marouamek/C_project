#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

enum PointValues         // Enumeration *personal touch XD* //
{
    WIN = 3,
    DRAW = 1,
    LOSS = 0,
};

 typedef struct                       // A structure that contains the players info //
 {
    char name[20];
    int points,score,rank;
 }team;


 void printf_rules()                   // AP to print the rules of the league //
{
    printf("\n                                                        _______________________________________________ \n");
    printf("                                                       |                                                   |");
    printf("\n                                                       |               | RULES OF THE NFL |                |");
    printf("\n                                                       |                                                   |");
    printf("\n                                                       | * Teams cannot play the same team more than once .|");
    printf("\n                                                       | * Teams number between 10 and 20                  |");
    printf("\n                                                       | * Number of teams should be even                  |");
    printf("\n                                                       | * A team can't play with itself                   |");
    printf("\n                                                       | * Win  : %d points.                                |\n                                                       | * Lose : %d points.                                | \n                                                       | * Draw : %d point .                                |\n", WIN, LOSS, DRAW);
    printf("                                                       |                                                   |");
    printf("\n                                                       |___________________________________________________| \n");

}

 void fill(int n, team m[n/2][2])                 // AP to fill the 2D Array with the players info //
 {
     printf("\n\n                                                                   |   Enter team's information |               \n");
int k=1;
     for(int i=0; i<n/2; i++)
        {
             for(int j=0; j<2; j++)

         {
             printf("\n |  For team number %d  |:",k);
             printf("\n | The team's name |: ");
             scanf("%s",m[i][j].name);
             m[i][j].points=0;    // Initialization //
             m[i][j].score=0;
             m[i][j].rank=0;
             k++;

         }
     }
 }
           // AP to display the prev info //

 void display(int n, team m[n/2][2])
 {
     for(int i=0; i<n/2; i++)
     {
          for(int j=0; j<2; j++)
         {
             printf("\n_______________________________________________________________________________________________________________________________________________________________________\n");

             printf("\n                  | Team's name |: %s            | Points |: %d              | Score |: %d                | Rank |: %d   ",m[i][j].name,m[i][j].points,m[i][j].score,m[i][j].rank);
             printf("\n");
         }
     }
             printf("\n______________________________________________________________________________________________________________________________________________________________________\n\n");
 }
    // AP that will rotate our array //

                                     // example : 1  5      1  6      //
                                    //            2  6      5  7     //
                                   //             3  7 -->  2  8    //
                                  //              4  8      3  4   //

 void rotate(int n,team m[n/2][2])
 {
         team x;
         x=m[1][0];
         m[1][0]=m[0][1];
     for(int i=0; i<(n/2)-1; i++)
     {
         m[i][1]=m[i+1][1];
     }

     m[n/2-1][1]=m[n/2-1][0];


     for (int i=n/2-1; i>1; i--)
     {
         m[i][0]=m[i-1][0];
     }
     m[2][0]=x;
 }
       // AP that is responsible of updating the team's scores each round //

 void calculate_score(int n, team m[n/2][2])
{
     printf(" \n\n | Displaying The Matches Of The Day  |:");

    for (int i = 0; i < n/2  ; i++)
    {
        int team1_score, team2_score;

                 // Display the match of each day //

        printf("\n\n                                               ************     | Match %d :      | %s   V/S   %s |   ********************       ", i + 1, m[i][0].name, m[i][1].name);
    }
        printf(" \n\n | Scores Of Each Team And Their Results |: ");

        for (int i = 0; i < n/2  ; i++)
    {
        int team1_score, team2_score;

        printf("\n\n | Enter the points for %s |: ", m[i][0].name);       // register each team's score of the day //
        scanf("%d", &team1_score);
        printf("\n\n | Enter the points for %s |: ", m[i][1].name);
        scanf("%d", &team2_score);

        m[i][0].score += team1_score;  // initialization //
        m[i][1].score += team2_score;

        m[i][0].points =0;
        m[i][1].points =0;

    if (team1_score > team2_score)          // Comparing the teams : win , loss or draw //
    {
        printf("\n                                                     | * |   %s Won The Match           | * |              ", m[i][0].name);

        m[i][0].points += 3;          // WIN  //
        m[i][1].points += 0;         // LOSS //
    }
    else if (team2_score > team1_score)
    {
        printf("\n                                                     | * |   %s Won The Match           | * |             ", m[i][1].name);
        m[i][1].points += 3;        // WIN  //
        m[i][0].points +=0;        // LOSS //
    }
    else
    {
        printf("\n                                                    | * |  The Match Ended In A Draw    | * |     ");
        m[i][0].points += 1;           // DRAW //
        m[i][1].points += 1;          // DRAW //


    }
    printf("\n\n");
}
}
            // function to sort teams based on their scores

 void display_rank(int n, team m[n/2][2])
 {
       // create an array of pointers to the team structures

    team *team_ptrs[n];
    for (int i = 0; i < n/2; i++)
    {
        team_ptrs[i*2] = &m[i][0];
        team_ptrs[i*2+1] = &m[i][1];
    }

    // sort the array of pointers based on team's score //

    for (int i = 0; i < n-1; i++)
        {
        for (int j = i+1; j < n; j++)
        {
            int i_total = team_ptrs[i]->score;
            int j_total = team_ptrs[j]->score;

            if (i_total < j_total )
            {
                team *tmp = team_ptrs[i];
                team_ptrs[i] = team_ptrs[j];
                team_ptrs[j] = tmp;
            }
        }
    }


    // display the sorted team list with rank

    printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    printf("\n                                                                               R E S U L T S \n");
    printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n       | Team's name |: %s                      | Points |: %d                                   | Rank |: %d                           | Score |: %d\n", team_ptrs[i]->name, team_ptrs[i]->points,i+1,team_ptrs[i]->score);
    }
    printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
}

    // function to determine who's the winner of the league //

 void display_highest_score(int n, team m[n/2][2])
 {
    int max_score = 0;
    team* team_with_max_score = NULL;

    // Find team with highest score//

    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < 2; j++) {
            if (m[i][j].score > max_score) {
                max_score = m[i][j].score;
                team_with_max_score = &m[i][j];
            }
        }
    }

    // Display team with highest score //

    printf("\n\n                                                          The Winner Of This Football Tournament Is :     \n\n ");
    printf("\n\                                                            | Team's name |:%s", team_with_max_score->name);
    printf("\n                                                            |    Score    |: %d", team_with_max_score->score);
}

int main()
{
    int N, m=1;
    team teams[N/2][2] ;
    team trank [20];



     printf(" \n\n                                                  ************************************************************** ");
     printf(" \n                                                  *LADIES AND GENTELMAN WELCOME TO THE NATIONAL FOOTBALL LEAGUE !!!*");
     printf("\n                                                  ******************************************************************");
     printf("\n\n\n");




     // SETTING THE RULES //
       printf("\n\n\n");
       system(" COLOR 09");
       printf_rules();

    //ENTERING THE NUMBER OF THE TEAMS //

     printf(" \n\n             | *  Please enter the number of teams  |:");
     scanf(" \n%d",&N);

     // Check if the number is right //

    while( (N < 10 || N > 20) & N % 2 !=0 )
     {
         printf("\n ** Invalid number of teams , please enter a num between 10 and 20 , ensure that it's even :  ");
         scanf("%d",&N);
     }

       fill(N,teams);    // Call of the fun to fill //

       printf("\n\n     | Initial Teams Standings |  :\n");

       display(N,teams);   // Call of the fun to display //
       printf("\n\n");


       while(m<=N-1)
       {
          printf("\n");
          printf("========================================================================================================================================================================\n");
          printf("||                                                                                                                                                                    ||\n");
          printf("||                                                                                  ROUND %d                                                                           ||\n", m);
          printf("||                                                                                                                                                                    ||\n");
          printf("========================================================================================================================================================================\n");
          printf("\n");

           calculate_score(N,teams);
           printf("\n\n                                                    *              |  Current standings after round %d  |              * \n", m);
           display_rank(N,teams);
           printf("\n\n");
           rotate(N,teams);
           m++;
       }

       display_highest_score(N,teams) ;

       system(" COLOR 06");





 printf("\n\n\n");
 printf("\n                                                                     ##########################             ");
 printf("\n                                                                     ##########################             ");
 printf("\n                                                                ##################################          ");
 printf("\n                                                              ######################################        ");
 printf("\n                                                             ####     ######################     ####       ");
 printf("\n                                                             ###      ######################      ###       ");
 printf("\n                                                             ##       ######################       ##       ");
 printf("\n                                                             ###    ##########################    ###       ");
 printf("\n                                                             ###   ############################   ###       ");
 printf("\n                                                              ###  ##########################    ###        ");
 printf("\n                                                              ####  #########################   ####        ");
 printf("\n                                                               ####################################         ");
 printf("\n                                                                 ################################           ");
 printf("\n                                                                ##################################          ");
 printf("\n                                                                            ############                    ");
 printf("\n                                                                              ########                      ");
 printf("\n                                                                                ####                        ");
 printf("\n                                                                                ####                        ");
 printf("\n                                                                                ####                        ");
 printf("\n                                                                            ############                    ");
 printf("\n                                                                          ################                  ");
 printf("\n                                                                         ##################                 ");



 return 0;
}






