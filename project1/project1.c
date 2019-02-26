/*
 * project1.c
 *
 *  Created on: 2019年2月21日
 *      Author: 111111
 */


#include <stdio.h>
#include <conio.h>
void seatChart();
int i,j,x,y,rate,res,q;
int total = 0;
int totalSeats = 450;
int totalSeats2 = 0;
int conformSeat =0;
const int rows =15;
const int columns =30;
char chart[15][30];
int Menu();
int main(){
	int cost[15];
	for(i = 0;i<15;i++){
		 printf("enter the cost for the row %d",i+1);
		 fflush(stdout);
		 scanf("%d", &cost[i]);
	}
	for(i = 0;i<15;i++){
							for(j = 0;j<30;j++){
								chart[i][j]='#';
							}
						}
	int choice2;
	do{
		choice2 = Menu();
		switch (choice2)
		{
			case 1:
				printf("view seat prices\n\n");
				for( i = 0;i<15;i++){
					printf("The prices for raw  %d      " ,i+1);
					printf("%d\n",cost[i]);
				}
				break;
			case 2:
				 do{
					 printf("Select the row: \n");
					 fflush(stdout);
					scanf("%d", &x);
					printf("Select the colunm: \n");
					 fflush(stdout);
					scanf("%d", &y);
					if(chart[x-1][y-1] == '*'){
					 printf("Sorry that seat is sold-out, select an another seat.\n");

				 }
				 else{
					rate = cost[x-1] + 0;
					 /*total = total + rate;
					 totalSeats = totalSeats -1;*/
					 printf("Ticket cost: %d \n",rate);
					 printf("Book the Ticket(1 = YES / 2 = NO)):");
					 fflush(stdout);
					 scanf("%d", &res);
					 if (res == 1)
					     {
						 rate = cost[x-1] + 0;
						 total = total + rate;
						totalSeats = totalSeats -1;
						 printf("Your ticket purchase has been confirmed\n");
						 chart[x-1][y-1] = '*';
						 printf("the total is %d \n",total);
						 printf("the totalSeats is %d \n",totalSeats);
					     }
					  else if (res == 2)
					     {
						  printf("Would you continue for another seat? (YES=1 / NO=2)\n");
						  fflush(stdout);
						  scanf("%d", &q);
					     }
					 printf("Would you continue for another seat? (YES=1 / NO=2)\n");
					 fflush(stdout);
					 scanf("%d", &q);
				 }
				 }
				  while (q == 1);
				   break;
			case 3:
				printf("Available Seats displays # symobl, filled seats displays * symbol\n\n");
					seatChart();
					break;
			case 4:
				 for( i = 0;i<15;i++){
						 printf("row %d ",i+1);
						 for(j = 0; j<30;j++){
							 if(chart[i][j] == '#'){
								 totalSeats2 = totalSeats2 +1;

							 }

						 }
						 printf("Left seat is %d",totalSeats2);
						 printf("\n");
						 totalSeats2 = 0;
					 }
				 break;
			case 5:
				exit(0);
					break;
			default :
				printf("Error input\n");

		}

	}
	while (choice2 != 5);
				return 0;
}
void seatChart(){
	 printf("the totalSeats is %d \n",totalSeats);
	 printf("     1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30");
	 printf("\n");
	 for( i = 0;i<15;i++){
		 printf("row %d ",i+1);
		 for(j = 0; j<30;j++){
			 printf("%c ",chart[i][j]);

		 }
		 printf("\n");
	 }
}
int Menu(){
	int choice;
	 printf("\n");
	 printf("1. cost for the seat\n");
	 printf("2. buy one seat\n");
	 printf("3. display all available seats like a figure\n");
	 printf("4. display each row available seats\n");
	 printf("5. exit\n");
	 fflush(stdout);
	 scanf("%d", &choice);
	 return choice;
}
