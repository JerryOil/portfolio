/* пкгяожояийг
A' еналгмо
кадас цеяасилос */

#include <stdio.h>
#include <stdlib.h> //for randomization && screen cleanliness
#include <time.h> //for randomization based on clock
#define NAMELENGTH 1002//=Guinness world longest name as until 3/2/2022

void clrprnt();

int main(void){
	
	char bugeater[2], name1[NAMELENGTH], name2[NAMELENGTH];
	int i, maxTurns, turn, winp1, winp2, game=1, error, langchck, again, bell, lang, maxPlayers, gameMode, fingersp1, fingersp2, wish;
	
	clrprnt();
	printf("%c",218);for(i=0;i<19;i++)printf("%c",196);printf("%c",191);
	printf("\a\n%c%c%c%cGame language%c%c%c%c\n",179,178,177,176,176,177,178,179);
	printf("%c",192);for(i=0;i<19;i++)printf("%c",196);printf("%c",217);
	//game languages
	do{
		//language selection
		do{
			printf("\n(1)ENGLISH/(2)GREEK/(3)FRENCH\nType 1, 2 or 3: ");
			scanf("%d",&lang);
			error=((lang<1)||(lang>3));
			if (error)
				printf("Wrong number!\n");
		}while(error);
		//language confirmation
		switch(lang){
			//English
			case 1:
				do{
					printf("\nENGLISH?\n(1)Yes/(2)No\nType 1 or 2: ");
					scanf("%d",&langchck);
					error=((langchck<1)||(langchck>2));
					if (error)
						printf("Wrong number!\n");
				}while(error);
				break;
			//Greek
			case 2:
				do{
					printf("\nELLHNIKA?\n(1)Nai/(2)Oxi\nPlhktrologhste 1 h' 2: ");
					scanf("%d",&langchck);
					error=((langchck<1)||(langchck>2));
					if (error)
						printf("Lathos arithmos!\n");
				}while(error);
				break;
			//French
			case 3:
				do{
					printf("\nFRANCAIS?\n(1)Oui/(2)Non\nDactylographie 1 ou 2: ");
					scanf("%d",&langchck);
					error=((langchck<1)||(langchck>2));
					if (error)
						printf("Erreur numero!\n");
				}while(error);
				break;
		}
	}while(langchck==2);
	clrprnt();
	//actual rock-paper-scissors game
	switch(lang){
		case 1:
			printf("%c",218);for(i=0;i<19;i++)printf("%c",196);printf("%c",191);
			printf("\a\n%c%c%c%cSound Enabled%c%c%c%c\n",179,178,177,176,176,177,178,179);
			printf("%c",192);for(i=0;i<19;i++)printf("%c",196);printf("%c",217);
			do{
			printf("\nWould you like to play in silent mode?\n(1)yes/(2)no: ");
			scanf("%d",&bell);
			}while((bell<1)||(bell>2));
			do{
				clrprnt();
				if(bell==2){
					printf("\a");
				}
				printf("%c",218);for(i=0;i<23;i++)printf("%c",196);printf("%c",191);
				printf("\n%c%c%c%cHow many players?%c%c%c%c\n",179,178,177,176,176,177,178,179);
				printf("%c",192);for(i=0;i<23;i++)printf("%c",196);printf("%c",217);
				//number of players
				do{
					printf("\n(1 or 2): ");
					scanf("%d",&maxPlayers);
					error=((maxPlayers<1)||(maxPlayers>2));
					if (error)
						printf("Two modes only!\n(1 player) Player vs AI\n(2 players) Player vs Player\n");
				}while(error);
				clrprnt();
				if(bell==2){
					printf("\a");
				}
				printf("%c",218);for(i=0;i<16;i++)printf("%c",196);printf("%c",191);
				printf("\n%c%c%c%cGame modes%c%c%c%c\n",179,178,177,176,176,177,178,179);
				printf("%c",192);for(i=0;i<16;i++)printf("%c",196);printf("%c",217);
				//game mode/max turns
				do{
					printf("\n(1)Casual/(2)QuickRun/(3)Custom:\n");
					scanf("%d",&gameMode);
				}while((gameMode<1)||(gameMode>3));
				switch (gameMode){
					//Casual 5 turns max
					case 1: 
						maxTurns=5;
						break;
					//QuickRun 1 turn
					case 2:
						maxTurns=1;
						break;
					//Custom/player choose turns
					case 3:
						do{
							printf("How many turns you want? ");
							scanf("%d",&maxTurns);
						}while(maxTurns<1);
						break;
				}
				clrprnt();
				//player vs AI
				if (maxPlayers==1){
					fgets(bugeater, 2, stdin);
					if(bell==2){
						printf("\a");
					}
					printf("%c",218);for(i=0;i<14;i++)printf("%c",196);printf("%c",191);
					printf("\n%c%c%c%cWelcome!%c%c%c%c\n",179,178,177,176,176,177,178,179);
					printf("%c",192);for(i=0;i<14;i++)printf("%c",196);printf("%c",217);
					printf("\n(You can use caps, numbers and special characters)\nWhat's your name? ");
					fgets(name1, NAMELENGTH, stdin);
					clrprnt();
					turn=1;
					winp1=winp2=0;
					//check for maxTurns or Winner
					do{
						printf("\nGame:%d\nTurn:%d\n\nScore\nPlayer1: %d\nAI: %d\n",game,turn,winp1,winp2);
						//fingers choice
						do{
							printf("\n%s(1)Rock/(2)Paper/(3)Scissors\nChoice: ",name1);
							scanf("%d",&fingersp1);
						}while((fingersp1<1)||(fingersp1>3));
						srand(time(NULL));
						fingersp2=(rand()%3)+1;
						printf("\nAI choice: %s\n\n",(fingersp2==1)?"Rock":(fingersp2==2)?"Paper":"Scissors");
						//winning check
						if (fingersp1==1){
							//2 rocks
							if (fingersp2==1){
								printf("DRAW");
							}
							//rock/paper
							else if (fingersp2==2){
								printf("AI WINNER");
								winp2++;
							}
							//rock/scissors
							else{
								printf("%sWINNER",name1);
								winp1++;
							}
						}
						else if (fingersp1==2){
							//paper/rock
							if (fingersp2==1){
								printf("%sWINNER",name1);
								winp1++;
							}
							//2 papers
							else if (fingersp2==2){
								printf("DRAW");
							}
							//paper/scissors
							else{
								printf("AI WINNER");
								winp2++;
							}
						}
						else{
							//scissors/rock
							if (fingersp2==1){
								printf("AI WINNER");
								winp2++;
							}
							//scissors/paper
							else if (fingersp2==2){
								printf("%sWINNER",name1);
								winp1++;
							}
							//2 scissors
							else{
								printf("DRAW");
							}
						}
						printf("\n\n");
						for(i=0;i<10;i++)printf("%c%c%c",223,219,220);
						//for(i=0;i<7;i++)printf("%c%c%c%c",223,219,220,219); //another printable line
						printf("\n");
						turn++;
					}while((turn<=maxTurns)&&(winp1<=(maxTurns/2))&&(winp2<=(maxTurns/2)));
					if (winp1>winp2){
						printf("\n%sULTIMATE WINNER!!!\n",name1);
						if ((maxTurns>=3)&&(winp1>(maxTurns/2))&&(winp2==0))
							printf("AND LUCKIEST PERSON ON EARTH");
					}
					else if (winp1<winp2){
						printf("\nAI UNBEATABLE MACHINE!\n");
					}
					else{
						printf("\nDRAW -.-\n");
					}
					if(bell==2){
						printf("\a");
					}
					printf("\n\n%c",218);for(i=0;i<35;i++)printf("%c",196);printf("%c",191);
					printf("\n%c%c%c%cWould you like to play again?%c%c%c%c\n",179,178,177,176,176,177,178,179);
					printf("%c",192);for(i=0;i<35;i++)printf("%c",196);printf("%c",217);
					//play again
					do{
						printf("\n(1)yes/(2)no: ");
						scanf("%d",&again);
					}while((again<1)||(again>2));
					if (again==1){
						clrprnt();
						game++;
					}
					//good bye wishes
					else{
						srand(time(NULL));
						wish=(rand()%4);
						switch(wish){
							case 0:
								printf("\nHave a nice day ^.^");
								break;
							case 1:
								printf("\nUntil next time...\nBye Bye :D");
								break;
							case 2:
								printf("\nWish you a beautiful day <3");
								break;
							case 3:
								printf("\nMay the force be with you!");
								break;
						}
					}
				}
				//player vs player
				else{
					fgets(bugeater, 2, stdin);
					if(bell==2){
						printf("\a");
					}
					printf("%c",218);for(i=0;i<14;i++)printf("%c",196);printf("%c",191);
					printf("\n%c%c%c%cWelcome!%c%c%c%c\n",179,178,177,176,176,177,178,179);
					printf("%c",192);for(i=0;i<14;i++)printf("%c",196);printf("%c",217);
					printf("\n(You can use caps, numbers and special characters)\nWhat's your name Player1 ? ");
					fgets(name1, NAMELENGTH, stdin);
					printf("\n(You can use caps, numbers and special characters)\nWhat's your name Player2 ? ");
					fgets(name2, NAMELENGTH, stdin);
					clrprnt();
					turn=1;
					winp1=winp2=0;
					//check for maxTurns or Winner
					do{
						printf("\nGame:%d\nTurn:%d\n\nScore\nPlayer1: %d\nPlayer2: %d\n",game,turn,winp1,winp2);
						//fingers choice Player 1
						do{
							printf("\n%s(1)Rock/(2)Paper/(3)Scissors\nChoice: ",name1);
							scanf("%d",&fingersp1);
						}while((fingersp1<1)||(fingersp1>3));
						clrprnt();
						printf("\nGame:%d\nTurn:%d\n\nScore\nPlayer1: %d\nPlayer2: %d\n",game,turn,winp1,winp2);
						//fingers choice Player 2
						do{
							printf("\n%s(1)Rock/(2)Paper/(3)Scissors\nChoice: ",name2);
							scanf("%d",&fingersp2);
						}while((fingersp2<1)||(fingersp2>3));
						printf("\n%schoice: %s\n\n",name1,(fingersp2==1)?"Rock":(fingersp2==2)?"Paper":"Scissors");
						//winning check
						if (fingersp1==1){
							//2 rocks
							if (fingersp2==1){
								printf("DRAW");
							}
							//rock/paper
							else if (fingersp2==2){
								printf("%sWINNER",name2);
								winp2++;
							}
							//rock/scissors
							else{
								printf("%sWINNER",name1);
								winp1++;
							}
						}
						else if (fingersp1==2){
							//paper/rock
							if (fingersp2==1){
								printf("%sWINNER",name1);
								winp1++;
							}
							//2 papers
							else if (fingersp2==2){
								printf("DRAW");
							}
							//paper/scissors
							else{
								printf("%sWINNER",name2);
								winp2++;
							}
						}
						else{
							//scissors/rock
							if (fingersp2==1){
								printf("%sWINNER",name2);
								winp2++;
							}
							//scissors/paper
							else if (fingersp2==2){
								printf("%sWINNER",name1);
								winp1++;
							}
							//2 scissors
							else{
								printf("DRAW");
							}
						}
						printf("\n\n");
						for(i=0;i<10;i++)printf("%c%c%c",223,219,220);
						//for(i=0;i<7;i++)printf("%c%c%c%c",223,219,220,219); //another printable line
						printf("\n");
						turn++;
					}while((turn<=maxTurns)&&(winp1<=(maxTurns/2))&&(winp2<=(maxTurns/2)));
					if (winp1>winp2){
						printf("\n%sULTIMATE WINNER!!!\n",name1);
						if ((maxTurns>=3)&&(winp1>(maxTurns/2))&&(winp2==0))
							printf("AND LUCKIEST PERSON ON EARTH");
					}
					else if (winp1<winp2){
						printf("\n%sULTIMATE WINNER!!!\n",name2);
						if ((maxTurns>=3)&&(winp2>(maxTurns/2))&&(winp1==0))
							printf("AND LUCKIEST PERSON ON EARTH");
					}
					else{
						printf("\nDRAW -.-\n");
					}
				}
				if(bell==2){
					printf("\a");
				}
				printf("\n\n%c",218);for(i=0;i<35;i++)printf("%c",196);printf("%c",191);
				printf("\n%c%c%c%cWould you like to play again?%c%c%c%c\n",179,178,177,176,176,177,178,179);
				printf("%c",192);for(i=0;i<35;i++)printf("%c",196);printf("%c",217);
				//play again
				do{
					printf("\n(1)yes/(2)no: ");
					scanf("%d",&again);
				}while((again<1)||(again>2));
				if (again==1){
					clrprnt();
					game++;
				}
				//good bye wishes
				else{
					srand(time(NULL));
					wish=(rand()%4);
					switch(wish){
						case 0:
							printf("\nHave a nice day ^.^");
							break;
						case 1:
							printf("\nUntil next time...\nBye Bye :D");
							break;
						case 2:
							printf("\nWish you a beautiful day <3");
							break;
						case 3:
							printf("\nMay the force be with you!");
							break;
					}
				}
			}while(again==1);
			break;
		case 2:
			//greek version
			break;
		case 3:
			//french version
			break;
	}	
	return 0;
}

void clrprnt(){
	int i;
	system("cls");
	printf("%c",201);for(i=0;i<25;i++)printf("%c",205);printf("%c",187);
	printf("\n%c%c%c%cROCK-PAPER-SCISSORS%c%c%c%c\n",186,178,177,176,176,177,178,186);
	printf("%c",200);for(i=0;i<25;i++)printf("%c",205);printf("%c\n",188);
}
/*The array bugeater[2] was created to execute smoothly the program on compiler Dev-C++ 5.5.3 
should be removed in other compilers*/
