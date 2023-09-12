/*RockPaperScissors game by JerryOil(=Gerasimo Lada)

/*To parwn apotelei pneymatikh idiokthsia toy Gerasimou Lada,
o opoios apopoieitai opoiasdhpote ey8ynhs gia proklhsh zhmias/wn 
apo to parwn arxeio kwdika h'/kai to ektelesimo arxeio poy aporreei apo auto,
apagorevetai h antigrafh h'/kai dia8esh 
oloklhrou h' merous toy kwdika h'/ kai tou ektelesimou arxeiou
apo tritous pros pwlhsh h' opoioudhpote antallagmatos

This is the intellectual property of Gerasimos Ladas,
who disclaims any liability for causing damage/s
from this source code or/and the executive program made by it,
is also not allowed to be copied or/and be sold by third parties or in any exchange*/

#include <stdio.h>
#include <stdlib.h> //for randomization && screen cleanliness
#include <time.h> //for randomization based on clock
#define NAMELENGTH 1002//=Guinness world longest name as until 2022

void date();
void clrprnt();
void date2();
void clrprnt2();

int main(void){
	
	char name1[NAMELENGTH], name2[NAMELENGTH];
	int contract, i, maxTurns, turn, winp1, winp2, game=1, error, langchck, bell, dark, again, lang, maxPlayers, gameMode, fingersp1, fingersp2, wish;
	
	system("color 09");
	clrprnt();
	printf("%c",218);for(i=0;i<19;i++)printf("%c",196);printf("%c",191);
	printf("\a\n%c%c%c%cGame language%c%c%c%c\n",179,178,177,176,176,177,178,179);
	printf("%c",192);for(i=0;i<19;i++)printf("%c",196);printf("%c",217);
	//game languages
	do{
		//language selection
		do{
			lang=0;
			printf("\n(1)ENGLISH/(2)GREEK/(3)FRENCH\nType 1, 2 or 3: ");
			scanf("%d",&lang);
			error=((lang<1)||(lang>3));
			if (error)
				printf("Wrong number!\n");
			fflush(stdin);
		}while(error);
		//language confirmation
		switch(lang){
			//english version
			case 1:
				do{
					langchck=0;
					printf("\nENGLISH?\n(1)Yes/(2)No\nType 1 or 2: ");
					scanf("%d",&langchck);
					error=((langchck<1)||(langchck>2));
					if (error)
						printf("Wrong number!\n");
					fflush(stdin);
				}while(error);
				break;
			//Greek
			case 2:
				do{
					langchck=0;
					printf("\nELLHNIKA?\n(1)Nai/(2)Oxi\nPlhktrologhste 1 h' 2: ");
					scanf("%d",&langchck);
					error=((langchck<1)||(langchck>2));
					if (error)
						printf("Lathos arithmos!\n");
					fflush(stdin);
				}while(error);
				break;
			//French
			case 3:
				do{
					langchck=0;
					printf("\nFRANCAIS?\n(1)Oui/(2)Non\nDactylographie 1 ou 2: ");
					scanf("%d",&langchck);
					error=((langchck<1)||(langchck>2));
					if (error)
						printf("Erreur numero!\n");
					fflush(stdin);
				}while(error);
				break;
		}
	}while(langchck==2);
	system("color 0B");
	clrprnt();
	//actual rock-paper-scissors game
	switch(lang){
		//English
		case 1:
			printf("\nThis is the intellectual property of Gerasimos Ladas,\nwho disclaims any liability for causing damage/s from the game,\nis not allowed to be sold by third parties or in any exchange,\nthe owner has the right to take legal action against these contract offenders\n");
			//contract
			do{
				contract=0;
				printf("\nDo you accept these terms?\nType (1)yes/(2)no: ");
				scanf("%d",&contract);
				fflush(stdin);
			}while((contract<1)||(contract>2));
			if (contract==2) exit(0);
			
			system("color 0D");
			clrprnt();
			printf("%c",218);for(i=0;i<31;i++)printf("%c",196);printf("%c",191);
			printf("\a\n%c%c%c%cSound & Dark_Mode Enabled%c%c%c%c\n",179,178,177,176,176,177,178,179);
			printf("%c",192);for(i=0;i<31;i++)printf("%c",196);printf("%c",217);
			//sound check
			do{
				bell=0;
				printf("\nWould you like to play in silent mode?\n(1)yes/(2)no: ");
				scanf("%d",&bell);
				fflush(stdin);
			}while((bell<1)||(bell>2));
			//vision check
			do{
				dark=0;
				printf("\nWould you like to play in light mode?\n(recommended if you barely see the letters)\n(1)yes/(2)no: ");
				scanf("%d",&dark);
				fflush(stdin);
			}while((dark<1)||(dark>2));
			do{
				(dark==2)?system("color 03"):system("color F3");
				clrprnt();
				if(bell==2){
					printf("\a");
				}
				printf("%c",218);for(i=0;i<23;i++)printf("%c",196);printf("%c",191);
				printf("\n%c%c%c%cHow many players?%c%c%c%c\n",179,178,177,176,176,177,178,179);
				printf("%c",192);for(i=0;i<23;i++)printf("%c",196);printf("%c",217);
				//number of players
				do{
					maxPlayers=0;
					printf("\n(1 or 2): ");
					scanf("%d",&maxPlayers);
					error=((maxPlayers<1)||(maxPlayers>2));
					if (error)
						printf("Two modes only!\n(1 player) Player vs AI\n(2 players) Player vs Player\n");
					fflush(stdin);
				}while(error);
				(dark==2)?system("color 06"):system("color F6");
				clrprnt();
				//player vs AI
				if (maxPlayers==1){
					if(bell==2){
						printf("\a");
					}
					printf("%c",218);for(i=0;i<14;i++)printf("%c",196);printf("%c",191);
					printf("\n%c%c%c%cWelcome!%c%c%c%c\n",179,178,177,176,176,177,178,179);
					printf("%c",192);for(i=0;i<14;i++)printf("%c",196);printf("%c",217);
					printf("\n(You can use caps, numbers and special characters)\nWhat's your name? ");
					fflush(stdin);
					fgets(name1, NAMELENGTH, stdin);
					turn=1;
					winp1=winp2=0;
					(dark==2)?system("color 0C"):system("color F4");
					clrprnt();
					if(bell==2){
						printf("\a");
					}
					printf("%c",218);for(i=0;i<16;i++)printf("%c",196);printf("%c",191);
					printf("\n%c%c%c%cGame modes%c%c%c%c\n",179,178,177,176,176,177,178,179);
					printf("%c",192);for(i=0;i<16;i++)printf("%c",196);printf("%c",217);
					//game mode/max turns
					do{
						gameMode=0;
						printf("\n(1)Bo5/(2)QuickRun/(3)Custom: ");
						scanf("%d",&gameMode);
						fflush(stdin);
					}while((gameMode<1)||(gameMode>3));
					(dark==2)?system("color 0A"):system("color F2");
					clrprnt();
					switch (gameMode){
						//Bo5 5 turns max
						case 1: 
							maxTurns=5;
							//check for maxTurns or Winner
							do{
								printf("\nGame:%d\nTurn:%d\n\nScore\nPlayer1: %d\nAI: %d\n",game,turn,winp1,winp2);
								//fingers choice
								do{
									fingersp1=0;
									printf("\n%s(1)Rock/(2)Paper/(3)Scissors\nChoice: ",name1);
									scanf("%d",&fingersp1);
									fflush(stdin);
								}while((fingersp1<1)||(fingersp1>3));
								srand(time(NULL));
								fingersp2=(rand()%3)+1;
								printf("\nAI choice: %s\n\n",(fingersp2==1)?"Rock":(fingersp2==2)?"Paper":"Scissors");
								//winning check
								if (fingersp1==1){
									//2 rocks
									if (fingersp2==1){
										printf("Rock vs Rock\nDRAW");
									}
									//rock/paper
									else if (fingersp2==2){
										printf("Paper wraps Rock\nAI +1 point");
										winp2++;
									}
									//rock/scissors
									else{
										printf("Rock breaks Scissors\n%s+1 point",name1);
										winp1++;
									}
								}
								else if (fingersp1==2){
									//paper/rock
									if (fingersp2==1){
										printf("Paper wraps Rock\n%s+1 point",name1);
										winp1++;
									}
									//2 papers
									else if (fingersp2==2){
										printf("Paper vs Paper\nDRAW");
									}
									//paper/scissors
									else{
										printf("Scissors cuts Paper\nAI +1 point");
										winp2++;
									}
								}
								else{
									//scissors/rock
									if (fingersp2==1){
										printf("Rock breaks Scissors\nAI +1 point");
										winp2++;
									}
									//scissors/paper
									else if (fingersp2==2){
										printf("Scissors cuts Paper\n%s+1 point",name1);
										winp1++;
									}
									//2 scissors
									else{
										printf("Scissors vs Scissors\nDRAW");
									}
								}
								printf("\n\n");
								for(i=0;i<10;i++)printf("%c%c%c",223,219,220);
								//for(i=0;i<7;i++)printf("%c%c%c%c",223,219,220,219); //another printable line
								printf("\n");
								turn++;
							}while((turn<=maxTurns)&&(winp1<=(maxTurns/2))&&(winp2<=(maxTurns/2)));
							if (winp1>winp2){
								if (winp1>=3){
									printf("\n%sWINNER!\n",name1);
									if (winp2==0)
										printf("AND LUCKIEST PERSON ON EARTH\n");
								}
								else 
									printf("\n%sAlmost winner with %d points\n",name1,winp1);
							}
							else if (winp1<winp2){
								if (winp2>=3){
									printf("\nAI WON\n");
									if (winp1==0)
										printf("UNBEATABLE MACHINE!\n");
								}
								else
									printf("\nAI almost won with %d points\n",winp2);
							}
							else{
								printf("\nDRAW -.-\n");
							}
							break;
						//QuickRun 1 turn
						case 2:
							maxTurns=1;
							//check for maxTurns or Winner
							printf("\nGame:%d\nTurn:%d\n\nScore\nPlayer1: %d\nAI: %d\n",game,turn,winp1,winp2);
							//fingers choice
							do{
								fingersp1=0;
								printf("\n%s(1)Rock/(2)Paper/(3)Scissors\nChoice: ",name1);
								scanf("%d",&fingersp1);
								fflush(stdin);
							}while((fingersp1<1)||(fingersp1>3));
							srand(time(NULL));
							fingersp2=(rand()%3)+1;
							printf("\nAI choice: %s\n\n",(fingersp2==1)?"Rock":(fingersp2==2)?"Paper":"Scissors");
							//winning check
							if (fingersp1==1){
								//2 rocks
								if (fingersp2==1){
									printf("Rock vs Rock\nDRAW");
								}
								//rock/paper
								else if (fingersp2==2){
									printf("Paper wraps Rock\nAI +1 point");
									winp2++;
								}
								//rock/scissors
								else{
									printf("Rock breaks Scissors\n%s+1 point",name1);
									winp1++;
								}
							}
							else if (fingersp1==2){
								//paper/rock
								if (fingersp2==1){
									printf("Paper wraps Rock\n%s+1 point",name1);
									winp1++;
								}
								//2 papers
								else if (fingersp2==2){
									printf("Paper vs Paper\nDRAW");
								}
								//paper/scissors
								else{
									printf("Scissors cuts Paper\nAI +1 point");
									winp2++;
								}
							}
							else{
								//scissors/rock
								if (fingersp2==1){
									printf("Rock breaks Scissors\nAI +1 point");
									winp2++;
								}
								//scissors/paper
								else if (fingersp2==2){
									printf("Scissors cuts Paper\n%s+1 point",name1);
									winp1++;
								}
								//2 scissors
								else{
									printf("Scissors vs Scissors\nDRAW");
								}
							}
							printf("\n\n");
							for(i=0;i<10;i++)printf("%c%c%c",223,219,220);
							//for(i=0;i<7;i++)printf("%c%c%c%c",223,219,220,219); //another printable line
							printf("\n");
							turn++;
							if (winp1>winp2){
								printf("\n%sWINNER!\n",name1);
							}
							else if (winp1<winp2){
								printf("\nAI WON\n");
							}
							else{
								printf("\nDRAW -.-\n");
							}
							break;
						//Custom/player choose turns
						case 3:
							do{
								maxTurns=0;
								printf("How many turns you want? ");
								scanf("%d",&maxTurns);
								fflush(stdin);
							}while(maxTurns<1);
							//check for maxTurns or Winner
							do{
								printf("\nGame:%d\nTurn:%d\n\nScore\nPlayer1: %d\nAI: %d\n",game,turn,winp1,winp2);
								//fingers choice
								do{
									fingersp1=0;
									printf("\n%s(1)Rock/(2)Paper/(3)Scissors\nChoice: ",name1);
									scanf("%d",&fingersp1);
									fflush(stdin);
								}while((fingersp1<1)||(fingersp1>3));
								srand(time(NULL));
								fingersp2=(rand()%3)+1;
								printf("\nAI choice: %s\n\n",(fingersp2==1)?"Rock":(fingersp2==2)?"Paper":"Scissors");
								//winning check
								if (fingersp1==1){
									//2 rocks
									if (fingersp2==1){
										printf("Rock vs Rock\nDRAW");
									}
									//rock/paper
									else if (fingersp2==2){
										printf("Paper wraps Rock\nAI +1 point");
										winp2++;
									}
									//rock/scissors
									else{
										printf("Rock breaks Scissors\n%s+1 point",name1);
										winp1++;
									}
								}
								else if (fingersp1==2){
									//paper/rock
									if (fingersp2==1){
										printf("Paper wraps Rock\n%s+1 point",name1);
										winp1++;
									}
									//2 papers
									else if (fingersp2==2){
										printf("Paper vs Paper\nDRAW");
									}
									//paper/scissors
									else{
										printf("Scissors cuts Paper\nAI +1 point");
										winp2++;
									}
								}
								else{
									//scissors/rock
									if (fingersp2==1){
										printf("Rock breaks Scissors\nAI +1 point");
										winp2++;
									}
									//scissors/paper
									else if (fingersp2==2){
										printf("Scissors cuts Paper\n%s+1 point",name1);
										winp1++;
									}
									//2 scissors
									else{
										printf("Scissors vs Scissors\nDRAW");
									}
								}
								printf("\n\n");
								for(i=0;i<10;i++)printf("%c%c%c",223,219,220);
								//for(i=0;i<7;i++)printf("%c%c%c%c",223,219,220,219); //another printable line
								printf("\n");
								turn++;
							}while((turn<=maxTurns)&&(winp1<=(maxTurns/2))&&(winp2<=(maxTurns/2)));
							if (winp1>winp2){
								printf("\n%sWINNER!\n",name1);
								if ((maxTurns>=3)&&(winp2==0))
									printf("AND LUCKIEST PERSON ON EARTH\n");
							}
							else if (winp1<winp2){
								printf("\nAI WON\n");
								if ((maxTurns>=3)&&(winp1==0))
									printf("UNBEATABLE MACHINE!\n");
							}
							else{
								printf("\nDRAW -.-\n");
							}
							break;
					}
				}
				//player vs player
				else{
					if(bell==2){
						printf("\a");
					}
					printf("%c",218);for(i=0;i<14;i++)printf("%c",196);printf("%c",191);
					printf("\n%c%c%c%cWelcome!%c%c%c%c\n",179,178,177,176,176,177,178,179);
					printf("%c",192);for(i=0;i<14;i++)printf("%c",196);printf("%c",217);
					printf("\n(You can use caps, numbers and special characters)\nWhat's your name Player1 ? ");
					fflush(stdin);
					fgets(name1, NAMELENGTH, stdin);
					printf("\n(You can use caps, numbers and special characters)\nWhat's your name Player2 ? ");
					fflush(stdin);
					fgets(name2, NAMELENGTH, stdin);
					turn=1;
					winp1=winp2=0;
					(dark==2)?system("color 0C"):system("color FA");
					clrprnt();
					if(bell==2){
						printf("\a");
					}
					printf("%c",218);for(i=0;i<16;i++)printf("%c",196);printf("%c",191);
					printf("\n%c%c%c%cGame modes%c%c%c%c\n",179,178,177,176,176,177,178,179);
					printf("%c",192);for(i=0;i<16;i++)printf("%c",196);printf("%c",217);
					//game mode/max turns
					do{
						gameMode=0;
						printf("\n(1)Bo5/(2)QuickRun/(3)Custom: ");
						scanf("%d",&gameMode);
						fflush(stdin);
					}while((gameMode<1)||(gameMode>3));
					(dark==2)?system("color 0A"):system("color F2");
					clrprnt();
					switch (gameMode){
						//Bo5 5 turns max
						case 1: 
							maxTurns=5;
							//check for maxTurns or Winner
							do{
								printf("\nGame:%d\nTurn:%d\n\nScore\nPlayer1: %d\nPlayer2: %d\n",game,turn,winp1,winp2);
								//fingers choice Player 1
								do{
									fingersp1=0;
									printf("\n%s(1)Rock/(2)Paper/(3)Scissors\nChoice: ",name1);
									scanf("%d",&fingersp1);
									fflush(stdin);
								}while((fingersp1<1)||(fingersp1>3));
								clrprnt();
								printf("\nGame:%d\nTurn:%d\n\nScore\nPlayer1: %d\nPlayer2: %d\n",game,turn,winp1,winp2);
								//fingers choice Player 2
								do{
									fingersp2=0;
									printf("\n%s(1)Rock/(2)Paper/(3)Scissors\nChoice: ",name2);
									scanf("%d",&fingersp2);
									fflush(stdin);
								}while((fingersp2<1)||(fingersp2>3));
								printf("\n%schoice: %s\n\n",name1,(fingersp2==1)?"Rock":(fingersp2==2)?"Paper":"Scissors");
								//winning check
								if (fingersp1==1){
									//2 rocks
									if (fingersp2==1){
										printf("Rock vs Rock\nDRAW");
									}
									//rock/paper
									else if (fingersp2==2){
										printf("Paper wraps Rock\n%s+1 point",name2);
										winp2++;
									}
									//rock/scissors
									else{
										printf("Rock breaks Scissors\n%s+1 point",name1);
										winp1++;
									}
								}
								else if (fingersp1==2){
									//paper/rock
									if (fingersp2==1){
										printf("Paper wraps Rock\n%s+1 point",name1);
										winp1++;
									}
									//2 papers
									else if (fingersp2==2){
										printf("Paper vs Paper\nDRAW");
									}
									//paper/scissors
									else{
										printf("Scissors cuts Paper\n%s+1 point",name2);
										winp2++;
									}
								}
								else{
									//scissors/rock
									if (fingersp2==1){
										printf("Rock breaks Scissors\n%s+1 point",name2);
										winp2++;
									}
									//scissors/paper
									else if (fingersp2==2){
										printf("Scissors cuts Paper\n%s+1 point",name1);
										winp1++;
									}
									//2 scissors
									else{
										printf("Scissors vs Scissors\nDRAW");
									}
								}
								printf("\n\n");
								for(i=0;i<10;i++)printf("%c%c%c",223,219,220);
								//for(i=0;i<7;i++)printf("%c%c%c%c",223,219,220,219); //another printable line
								printf("\n");
								turn++;
							}while((turn<=maxTurns)&&(winp1<=(maxTurns/2))&&(winp2<=(maxTurns/2)));
							if (winp1>winp2){
								if (winp1>=3){
									printf("\n%sWINNER!\n",name1);
									if (winp2==0)
										printf("AND LUCKIEST PERSON ON EARTH\n");
								}
								else
									printf("\n%sAlmost winner with %d points\n",name1,winp1);
							}
							else if (winp1<winp2){
								if (winp2>=3){
									printf("\n%sWINNER!\n",name2);
									if (winp1==0)
										printf("AND LUCKIEST PERSON ON EARTH\n");
								}
								else
									printf("\n%sAlmost winner with %d points\n",name2,winp2);
							}
							else{
								printf("\nDRAW -.-\n");
							}
							break;
						//QuickRun 1 turn
						case 2:
							maxTurns=1;
							//check for maxTurns or Winner
							printf("\nGame:%d\nTurn:%d\n\nScore\nPlayer1: %d\nPlayer2: %d\n",game,turn,winp1,winp2);
							//fingers choice Player 1
							do{
								fingersp1=0;
								printf("\n%s(1)Rock/(2)Paper/(3)Scissors\nChoice: ",name1);
								scanf("%d",&fingersp1);
								fflush(stdin);
							}while((fingersp1<1)||(fingersp1>3));
							clrprnt();
							printf("\nGame:%d\nTurn:%d\n\nScore\nPlayer1: %d\nPlayer2: %d\n",game,turn,winp1,winp2);
							//fingers choice Player 2
							do{
								fingersp2=0;
								printf("\n%s(1)Rock/(2)Paper/(3)Scissors\nChoice: ",name2);
								scanf("%d",&fingersp2);
								fflush(stdin);
							}while((fingersp2<1)||(fingersp2>3));
							printf("\n%schoice: %s\n\n",name1,(fingersp2==1)?"Rock":(fingersp2==2)?"Paper":"Scissors");
							//winning check
							if (fingersp1==1){
								//2 rocks
								if (fingersp2==1){
									printf("Rock vs Rock\nDRAW");
								}
								//rock/paper
								else if (fingersp2==2){
									printf("Paper wraps Rock\n%s+1 point",name2);
									winp2++;
								}
								//rock/scissors
								else{
									printf("Rock breaks Scissors\n%s+1 point",name1);
									winp1++;
								}
							}
							else if (fingersp1==2){
								//paper/rock
								if (fingersp2==1){
									printf("Paper wraps Rock\n%s+1 point",name1);
									winp1++;
								}
								//2 papers
								else if (fingersp2==2){
									printf("Paper vs Paper\nDRAW");
								}
								//paper/scissors
								else{
									printf("Scissors cuts Paper\n%s+1 point",name2);
									winp2++;
								}
							}
							else{
								//scissors/rock
								if (fingersp2==1){
									printf("Rock breaks Scissors\n%s+1 point",name2);
									winp2++;
								}
								//scissors/paper
								else if (fingersp2==2){
									printf("Scissors cuts Paper\n%s+1 point",name1);
									winp1++;
								}
								//2 scissors
								else{
									printf("Scissors vs Scissors\nDRAW");
								}
							}
							printf("\n\n");
							for(i=0;i<10;i++)printf("%c%c%c",223,219,220);
							//for(i=0;i<7;i++)printf("%c%c%c%c",223,219,220,219); //another printable line
							printf("\n");
							turn++;
							if (winp1>winp2){
								printf("\n%sWINNER!\n",name1);
							}
							else if (winp1<winp2){
								printf("\n%sWINNER!\n",name2);
							}
							else{
								printf("\nDRAW -.-\n");
							}
							break;
						//Custom/player choose turns
						case 3:
							do{
								maxTurns=0;
								printf("How many turns you want? ");
								scanf("%d",&maxTurns);
								fflush(stdin);
							}while(maxTurns<1);
							//check for maxTurns or Winner
							do{
								printf("\nGame:%d\nTurn:%d\n\nScore\nPlayer1: %d\nPlayer2: %d\n",game,turn,winp1,winp2);
								//fingers choice Player 1
								do{
									fingersp1=0;
									printf("\n%s(1)Rock/(2)Paper/(3)Scissors\nChoice: ",name1);
									scanf("%d",&fingersp1);
									fflush(stdin);
								}while((fingersp1<1)||(fingersp1>3));
								clrprnt();
								printf("\nGame:%d\nTurn:%d\n\nScore\nPlayer1: %d\nPlayer2: %d\n",game,turn,winp1,winp2);
								//fingers choice Player 2
								do{
									fingersp2=0;
									printf("\n%s(1)Rock/(2)Paper/(3)Scissors\nChoice: ",name2);
									scanf("%d",&fingersp2);
									fflush(stdin);
								}while((fingersp2<1)||(fingersp2>3));
								printf("\n%schoice: %s\n\n",name1,(fingersp2==1)?"Rock":(fingersp2==2)?"Paper":"Scissors");
								//winning check
								if (fingersp1==1){
									//2 rocks
									if (fingersp2==1){
										printf("Rock vs Rock\nDRAW");
									}
									//rock/paper
									else if (fingersp2==2){
										printf("Paper wraps Rock\n%s+1 point",name2);
										winp2++;
									}
									//rock/scissors
									else{
										printf("Rock breaks Scissors\n%s+1 point",name1);
										winp1++;
									}
								}
								else if (fingersp1==2){
									//paper/rock
									if (fingersp2==1){
										printf("Paper wraps Rock\n%s+1 point",name1);
										winp1++;
									}
									//2 papers
									else if (fingersp2==2){
										printf("Paper vs Paper\nDRAW");
									}
									//paper/scissors
									else{
										printf("Scissors cuts Paper\n%s+1 point",name2);
										winp2++;
									}
								}
								else{
									//scissors/rock
									if (fingersp2==1){
										printf("Rock breaks Scissors\n%s+1 point",name2);
										winp2++;
									}
									//scissors/paper
									else if (fingersp2==2){
										printf("Scissors cuts Paper\n%s+1 point",name1);
										winp1++;
									}
									//2 scissors
									else{
										printf("Scissors vs Scissors\nDRAW");
									}
								}
								printf("\n\n");
								for(i=0;i<10;i++)printf("%c%c%c",223,219,220);
								//for(i=0;i<7;i++)printf("%c%c%c%c",223,219,220,219); //another printable line
								printf("\n");
								turn++;
							}while((turn<=maxTurns)&&(winp1<=(maxTurns/2))&&(winp2<=(maxTurns/2)));
							if (winp1>winp2){
								printf("\n%sWINNER!\n",name1);
								if ((maxTurns>=3)&&(winp2==0))
									printf("AND LUCKIEST PERSON ON EARTH\n");
							}
							else if (winp1<winp2){
								printf("\n%sWINNER!\n",name2);
								if ((maxTurns>=3)&&(winp1==0))
									printf("AND LUCKIEST PERSON ON EARTH\n");
							}
							else{
								printf("\nDRAW -.-\n");
							}
							break;
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
					again=0;
					printf("\n(1)yes/(2)no: ");
					scanf("%d",&again);
					fflush(stdin);
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
			//ellhnikh ekdosh
			printf("\nTo parwn apotelei pneymatikh idiokthsia toy Gerasimou Lada,\no opoios apopoieitai opoiasdhpote ey8ynhs gia proklhsh zhmias/wn apo to paixnidi,\napagorevetai h dia8esh tou apo tritous pros pwlhsh h' opoioudhpote antallagmatos,\no idiokthths exei dikaiwma na kinh8ei nomika enantiwn paravatwn aytou tou sumvolaiou\n");
			//sumvolaio
			do{
				contract=0;
				printf("\nApodexeste autous tous orous?\nPlhktrologhste (1)nai/(2)oxi: ");
				scanf("%d",&contract);
				fflush(stdin);
			}while((contract<1)||(contract>2));
			if (contract==2) exit(0);
			
			system("color 0D");
			clrprnt();
			printf("%c",218);for(i=0;i<39;i++)printf("%c",196);printf("%c",191);
			printf("\a\n%c%c%c%cHxos & Skoteinh_Leitourgia Energa%c%c%c%c\n",179,178,177,176,176,177,178,179);
			printf("%c",192);for(i=0;i<39;i++)printf("%c",196);printf("%c",217);
			//elegxos hxou
			do{
				bell=0;
				printf("\n8elete na paiksete se a8oruvh leitourgia?\n(1)nai/(2)oxi: ");
				scanf("%d",&bell);
				fflush(stdin);
			}while((bell<1)||(bell>2));
			//elegxos opshs
			do{
				dark=0;
				printf("\n8elete na paiksete se fwteinh leitourgia?\n(sunistatai ean meta vias vlepete ta grammata)\n(1)nai/(2)oxi: ");
				scanf("%d",&dark);
				fflush(stdin);
			}while((dark<1)||(dark>2));
			do{
				(dark==2)?system("color 03"):system("color F3");
				clrprnt2();
				if(bell==2){
					printf("\a");
				}
				printf("%c",218);for(i=0;i<22;i++)printf("%c",196);printf("%c",191);
				printf("\n%c%c%c%cAri8mos paixtwn?%c%c%c%c\n",179,178,177,176,176,177,178,179);
				printf("%c",192);for(i=0;i<22;i++)printf("%c",196);printf("%c",217);
				//ari8mos paixtwn
				do{
					maxPlayers=0;
					printf("\n(1 h' 2): ");
					scanf("%d",&maxPlayers);
					error=((maxPlayers<1)||(maxPlayers>2));
					if (error)
						printf("Dyo leitourgies mono!\n(1 paixth/ria) Paixths/ria enantiwn Texnhths Nohmosunhs\n(2 paixtes/ries) Paixths/ria enantiwn Paixth/rias\n");
					fflush(stdin);
				}while(error);
				(dark==2)?system("color 06"):system("color F6");
				clrprnt2();
				//paixths/ria enantiwn Texnhths Nohmosunhs
				if (maxPlayers==1){
					if(bell==2){
						printf("\a");
					}
					printf("%c",218);for(i=0;i<18;i++)printf("%c",196);printf("%c",191);
					printf("\n%c%c%c%cKalwshr8ate!%c%c%c%c\n",179,178,177,176,176,177,178,179);
					printf("%c",192);for(i=0;i<18;i++)printf("%c",196);printf("%c",217);
					printf("\n(Mporeite na xrhsimopoihsete kefalaia, ari8mous kai eidikous xarakthres)\nPws onomazeste paixth/ria1? ");
					fflush(stdin);
					fgets(name1, NAMELENGTH, stdin);
					turn=1;
					winp1=winp2=0;
					(dark==2)?system("color 0C"):system("color F4");
					clrprnt2();
					if(bell==2){
						printf("\a");
					}
					printf("%c",218);for(i=0;i<28;i++)printf("%c",196);printf("%c",191);
					printf("\n%c%c%c%cLeitourgies paixnidiou%c%c%c%c\n",179,178,177,176,176,177,178,179);
					printf("%c",192);for(i=0;i<28;i++)printf("%c",196);printf("%c",217);
					//eidh paixnidiou/megistos gyros
					do{
						gameMode=0;
						printf("\n(1)Bo5/(2)Grhgoro/(3)Prosarmosmeno: ");
						scanf("%d",&gameMode);
						fflush(stdin);
					}while((gameMode<1)||(gameMode>3));
					(dark==2)?system("color 0A"):system("color F2");
					clrprnt2();
					switch (gameMode){
						//Bo5 5 gyroi to polu
						case 1: 
							maxTurns=5;
							//elegxos megistou gyrou h' nikhth/rias
							do{
								printf("\nPaixnidi:%d\nGyros:%d\n\nSkor\nPaixths/ria1: %d\nTexnhth Nohmosunh: %d\n",game,turn,winp1,winp2);
								//epilogh daxtylwn
								do{
									fingersp1=0;
									printf("\n%s(1)Petra/(2)Xarti/(3)Psalidi\nEpilogh: ",name1);
									scanf("%d",&fingersp1);
									fflush(stdin);
								}while((fingersp1<1)||(fingersp1>3));
								srand(time(NULL));
								fingersp2=(rand()%3)+1;
								printf("\nTexnhth Nohmosunh epilogh: %s\n\n",(fingersp2==1)?"Petra":(fingersp2==2)?"Xarti":"Psalidi");
								//elegxos nikhs gyrou
								if (fingersp1==1){
									//2 petres
									if (fingersp2==1){
										printf("Petra enantiwn Petras\nISOPALIA");
									}
									//petra/xarti
									else if (fingersp2==2){
										printf("To Xarti tuligei th Petra\nTexnhth Nohmosunh +1 pontos");
										winp2++;
									}
									//petra/psalidi
									else{
										printf("H Petra spaei to Psalidi\n%s+1 pontos",name1);
										winp1++;
									}
								}
								else if (fingersp1==2){
									//xarti/petra
									if (fingersp2==1){
										printf("To Xarti tuligei th Petra\n%s+1 pontos",name1);
										winp1++;
									}
									//2 xartia
									else if (fingersp2==2){
										printf("Xarti enantiwn Xartiou\nISOPALIA");
									}
									//xarti/psalidi
									else{
										printf("To Psalidi kovei to Xarti\nTexnhth Nohmosunh +1 pontos");
										winp2++;
									}
								}
								else{
									//psalidi/petra
									if (fingersp2==1){
										printf("H Petra spaei to Psalidi\nTexnhth Nohmosunh +1 pontos");
										winp2++;
									}
									//psalidi/xarti
									else if (fingersp2==2){
										printf("To Psalidi kovei to Xarti\n%s+1 pontos",name1);
										winp1++;
									}
									//2 psalidia
									else{
										printf("Psalidi enantiwn Psalidiou\nISOPALIA");
									}
								}
								printf("\n\n");
								for(i=0;i<10;i++)printf("%c%c%c",223,219,220);
								//for(i=0;i<7;i++)printf("%c%c%c%c",223,219,220,219); //diaforetikh ektypwsimh grammh
								printf("\n");
								turn++;
							}while((turn<=maxTurns)&&(winp1<=(maxTurns/2))&&(winp2<=(maxTurns/2)));
							if (winp1>winp2){
								if (winp1>=3){
									printf("\n%sNIKH!\n",name1);
									if (winp2==0)
										printf("KAI H PIO TYXERH ONTOTHTA STO KOSMO\n");
								}
								else 
									printf("\n%sSxedon nikh me %d pontous\n",name1,winp1);
							}
							else if (winp1<winp2){
								if (winp2>=3){
									printf("\nH Texnhth Nohmosunh NIKHSE\n");
									if (winp1==0)
										printf("ANIKHTO MHXANHMA!\n");
								}
								else
									printf("\nH Texnhth Nohmosunh sxedon nikhse me %d pontous\n",winp2);
							}
							else{
								printf("\nISOPALIA -.-\n");
							}
							break;
						//Grhgoro 1 gyros
						case 2:
							maxTurns=1;
							printf("\nPaixnidi:%d\nGyros:%d\n\nSkor\nPaixths/ria1: %d\nTexnhth Nohmosunh: %d\n",game,turn,winp1,winp2);
							//epilogh daxtylwn
							do{
								fingersp1=0;
								printf("\n%s(1)Petra/(2)Xarti/(3)Psalidi\nEpilogh: ",name1);
								scanf("%d",&fingersp1);
								fflush(stdin);
							}while((fingersp1<1)||(fingersp1>3));
							srand(time(NULL));
							fingersp2=(rand()%3)+1;
							printf("\nTexnhth Nohmosunh epilogh: %s\n\n",(fingersp2==1)?"Petra":(fingersp2==2)?"Xarti":"Psalidi");
							//elegxos nikhs
							if (fingersp1==1){
								//2 petres
								if (fingersp2==1){
									printf("Petra enantiwn Petras\nISOPALIA");
								}
								//petra/xarti
								else if (fingersp2==2){
									printf("To Xarti tuligei th Petra\nTexnhth Nohmosunh +1 pontos");
									winp2++;
								}
								//petra/psalidi
								else{
									printf("H Petra spaei to Psalidi\n%s+1 pontos",name1);
									winp1++;
								}
							}
							else if (fingersp1==2){
								//xarti/petra
								if (fingersp2==1){
									printf("To Xarti tuligei th Petra\n%s+1 pontos",name1);
									winp1++;
								}
								//2 petres
								else if (fingersp2==2){
									printf("Xarti enantiwn Xartiou\nISOPALIA");
								}
								//xarti/psalidi
								else{
									printf("To Psalidi kovei to Xarti\nTexnhth Nohmosunh +1 pontos");
									winp2++;
								}
							}
							else{
								//psalidi/petra
								if (fingersp2==1){
									printf("H Petra spaei to Psalidi\nTexnhth Nohmosunh +1 pontos");
									winp2++;
								}
								//psalidi/xarti
								else if (fingersp2==2){
									printf("To Psalidi kovei to Xarti\n%s+1 pontos",name1);
									winp1++;
								}
								//2 psalidia
								else{
									printf("Psalidi enantiwn Psalidiou\nISOPALIA");
								}
							}
							printf("\n\n");
							for(i=0;i<10;i++)printf("%c%c%c",223,219,220);
							//for(i=0;i<7;i++)printf("%c%c%c%c",223,219,220,219); //diaforetikh ektypwsimh grammh
							printf("\n");
							turn++;
							if (winp1>winp2){
								printf("\n%sNIKH!\n",name1);
							}
							else if (winp1<winp2){
								printf("\nH Texnhth Nohmosunh NIKHSE\n");
							}
							else{
								printf("\nISOPALIA -.-\n");
							}
							break;
						//Prosarmosmeno o/h paixths/ria epilegei to megisto gyro
						case 3:
							do{
								maxTurns=0;
								printf("Posous gurous 8elete? ");
								scanf("%d",&maxTurns);
								fflush(stdin);
							}while(maxTurns<1);
							//elegxos megistou gyrou h' nikhth/ria
							do{
								printf("\nPaixnidi:%d\nGyros:%d\n\nSkor\nPaixths/ria1: %d\nTexnhth Nohmosunh: %d\n",game,turn,winp1,winp2);
								//epilogh daxtylwn
								do{
									fingersp1=0;
									printf("\n%s(1)Petra/(2)Xarti/(3)Psalidi\nEpilogh: ",name1);
									scanf("%d",&fingersp1);
									fflush(stdin);
								}while((fingersp1<1)||(fingersp1>3));
								srand(time(NULL));
								fingersp2=(rand()%3)+1;
								printf("\nTexnhth Nohmosunh epilogh: %s\n\n",(fingersp2==1)?"Petra":(fingersp2==2)?"Xarti":"Psalidi");
								//elegxos nikhs gyrou
								if (fingersp1==1){
									//2 petres
									if (fingersp2==1){
										printf("Petra enantiwn Petras\nISOPALIA");
									}
									//petra/xarti
									else if (fingersp2==2){
										printf("To Xarti tuligei th Petra\nTexnhth Nohmosunh +1 pontos");
										winp2++;
									}
									//petra/psalidi
									else{
										printf("H Petra spaei to Psalidi\n%s+1 pontos",name1);
										winp1++;
									}
								}
								else if (fingersp1==2){
									//xarti/petra
									if (fingersp2==1){
										printf("To Xarti tuligei th Petra\n%s+1 pontos",name1);
										winp1++;
									}
									//2 xartia
									else if (fingersp2==2){
										printf("Xarti enantiwn Xartiou\nISOPALIA");
									}
									//xarti/psalidi
									else{
										printf("To Psalidi kovei to Xarti\nTexnhth Nohmosunh +1 pontos");
										winp2++;
									}
								}
								else{
									//psalidi/petra
									if (fingersp2==1){
										printf("H Petra spaei to Psalidi\nTexnhth Nohmosunh +1 pontos");
										winp2++;
									}
									//psalidi/xarti
									else if (fingersp2==2){
										printf("To Psalidi kovei to Xarti\n%s+1 pontos",name1);
										winp1++;
									}
									//2 psalidia
									else{
										printf("Psalidi enantiwn Psalidiou\nISOPALIA");
									}
								}
								printf("\n\n");
								for(i=0;i<10;i++)printf("%c%c%c",223,219,220);
								//for(i=0;i<7;i++)printf("%c%c%c%c",223,219,220,219); //diaforetikh ektypwsimh grammh
								printf("\n");
								turn++;
							}while((turn<=maxTurns)&&(winp1<=(maxTurns/2))&&(winp2<=(maxTurns/2)));
							if (winp1>winp2){
								printf("\n%sNIKH!\n",name1);
								if ((maxTurns>=3)&&(winp2==0))
									printf("KAI H PIO TYXERH ONTOTHTA STO KOSMO\n");
							}
							else if (winp1<winp2){
								printf("\nH Texnhth Nohmosunh NIKHSE\n");
								if ((maxTurns>=3)&&(winp1==0))
									printf("ANIKHTO MHXANHMA!\n");
							}
							else{
								printf("\nISOPALIA -.-\n");
							}
							break;
					}
				}
				//paixths/ria enantiwn paixth/rias
				else{
					if(bell==2){
						printf("\a");
					}
					printf("%c",218);for(i=0;i<18;i++)printf("%c",196);printf("%c",191);
					printf("\n%c%c%c%cKalwshr8ate!%c%c%c%c\n",179,178,177,176,176,177,178,179);
					printf("%c",192);for(i=0;i<18;i++)printf("%c",196);printf("%c",217);
					printf("\n(Mporeite na xrhsimopoihsete kefalaia, ari8mous kai eidikous xarakthres)\nPws onomazeste paixth/ria1? ");
					fflush(stdin);
					fgets(name1, NAMELENGTH, stdin);
					printf("\n(Mporeite na xrhsimopoihsete kefalaia, ari8mous kai eidikous xarakthres)\nPws onomazeste paixth/ria2? ");
					fflush(stdin);
					fgets(name2, NAMELENGTH, stdin);
					turn=1;
					winp1=winp2=0;
					(dark==2)?system("color 0C"):system("color FA");
					clrprnt2();
					if(bell==2){
						printf("\a");
					}
					printf("%c",218);for(i=0;i<28;i++)printf("%c",196);printf("%c",191);
					printf("\n%c%c%c%cLeitourgies paixnidiou%c%c%c%c\n",179,178,177,176,176,177,178,179);
					printf("%c",192);for(i=0;i<28;i++)printf("%c",196);printf("%c",217);
					//eidh paixnidiou/megistoi gyroi
					do{
						gameMode=0;
						printf("\n(1)Bo5/(2)Grhgoro/(3)Prosarmosmeno: ");
						scanf("%d",&gameMode);
						fflush(stdin);
					}while((gameMode<1)||(gameMode>3));
					(dark==2)?system("color 0A"):system("color F2");
					clrprnt2();
					switch (gameMode){
						//Bo5 5 gyroi to polu
						case 1: 
							maxTurns=5;
							//elegxos megistou gyrou h' nikhth/rias
							do{
								printf("\nPaixnidi:%d\nGyros:%d\n\nSkor\nPaixths/ria1: %d\nPaixths/ria2: %d\n",game,turn,winp1,winp2);
								//epilogh daxtylwn paixth/rias 1
								do{
									fingersp1=0;
									printf("\n%s(1)Petra/(2)Xarti/(3)Psalidi\nEpilogh: ",name1);
									scanf("%d",&fingersp1);
									fflush(stdin);
								}while((fingersp1<1)||(fingersp1>3));
								clrprnt2();
								printf("\nPaixnidi:%d\nGyros:%d\n\nSkor\nPaixths/ria1: %d\nPaixths/ria2: %d\n",game,turn,winp1,winp2);
								//epilogh daxtylwn paixth/rias 2
								do{
									fingersp2=0;
									printf("\n%s(1)Petra/(2)Xarti/(3)Psalidi\nEpilogh: ",name2);
									scanf("%d",&fingersp2);
									fflush(stdin);
								}while((fingersp2<1)||(fingersp2>3));
								printf("\n%sepilogh: %s\n\n",name1,(fingersp2==1)?"Petra":(fingersp2==2)?"Xarti":"Psalidi");
								//elegxos nikhs
								if (fingersp1==1){
									//2 petres
									if (fingersp2==1){
										printf("Petra enantiwn Petras\nISOPALIA");
									}
									//petra/xarti
									else if (fingersp2==2){
										printf("To Xarti tuligei th Petra\n%s+1 pontos",name2);
										winp2++;
									}
									//petra/psalidi
									else{
										printf("H Petra spaei to Psalidi\n%s+1 pontos",name1);
										winp1++;
									}
								}
								else if (fingersp1==2){
									//xarti/petra
									if (fingersp2==1){
										printf("To Xarti tuligei th Petra\n%s+1 pontos",name1);
										winp1++;
									}
									//2 xartia
									else if (fingersp2==2){
										printf("Xarti enantiwn Xartiou\nISOPALIA");
									}
									//xarti/psalidi
									else{
										printf("To Psalidi kovei to Xarti\n%s+1 pontos",name2);
										winp2++;
									}
								}
								else{
									//psalidi/petra
									if (fingersp2==1){
										printf("H Petra spaei to Psalidi\n%s+1 pontos",name2);
										winp2++;
									}
									//psalidi/xarti
									else if (fingersp2==2){
										printf("To Psalidi kovei to Xarti\n%s+1 pontos",name1);
										winp1++;
									}
									//2 psalidia
									else{
										printf("Psalidi enantiwn Psalidiou\nISOPALIA");
									}
								}
								printf("\n\n");
								for(i=0;i<10;i++)printf("%c%c%c",223,219,220);
								//for(i=0;i<7;i++)printf("%c%c%c%c",223,219,220,219); //another printable line
								printf("\n");
								turn++;
							}while((turn<=maxTurns)&&(winp1<=(maxTurns/2))&&(winp2<=(maxTurns/2)));
							if (winp1>winp2){
								if (winp1>=3){
									printf("\n%sNIKH!\n",name1);
									if (winp2==0)
										printf("KAI H PIO TYXERH ONTOTHTA STO KOSMO\n");
								}
								else
									printf("\n%sSxedon nikh me %d pontous\n",name1,winp1);
							}
							else if (winp1<winp2){
								if (winp2>=3){
									printf("\n%sNIKH!\n",name2);
									if (winp1==0)
										printf("KAI H PIO TYXERH ONTOTHTA STO KOSMO\n");
								}
								else
									printf("\n%sSxedon nikh me %d pontous\n",name2,winp2);
							}
							else{
								printf("\nISOPALIA -.-\n");
							}
							break;
						//Grhgoro 1 gyros
						case 2:
							maxTurns=1;
							printf("\nPaixnidi:%d\nGyros:%d\n\nSkor\nPaixths/ria1: %d\nPaixths/ria2: %d\n",game,turn,winp1,winp2);
							//epilogh daxtylwn paixth/rias 1
							do{
								fingersp1=0;
								printf("\n%s(1)Petra/(2)Xarti/(3)Psalidi\nEpilogh: ",name1);
								scanf("%d",&fingersp1);
								fflush(stdin);
							}while((fingersp1<1)||(fingersp1>3));
							clrprnt2();
							printf("\nPaixnidi:%d\nGyros:%d\n\nSkor\nPaixths/ria1: %d\nPaixths/ria2: %d\n",game,turn,winp1,winp2);
							//epilogh daxtylwn paixth/rias 2
							do{
								fingersp2=0;
								printf("\n%s(1)Petra/(2)Xarti/(3)Psalidi\nEpilogh: ",name2);
								scanf("%d",&fingersp2);
								fflush(stdin);
							}while((fingersp2<1)||(fingersp2>3));
							printf("\n%sepilogh: %s\n\n",name1,(fingersp2==1)?"Petra":(fingersp2==2)?"Xarti":"Psalidi");
							//elegxos nikhs
							if (fingersp1==1){
								//2 petres
								if (fingersp2==1){
									printf("Petra enantiwn Petras\nISOPALIA");
								}
								//petra/xarti
								else if (fingersp2==2){
									printf("To Xarti tuligei th Petra\n%s+1 pontos",name2);
									winp2++;
								}
								//petra/psalidi
								else{
									printf("H Petra spaei to Psalidi\n%s+1 pontos",name1);
									winp1++;
								}
							}
							else if (fingersp1==2){
								//xarti/petra
								if (fingersp2==1){
									printf("To Xarti tuligei th Petra\n%s+1 pontos",name1);
									winp1++;
								}
								//2 xartia
								else if (fingersp2==2){
									printf("Xarti enantiwn Xartiou\nISOPALIA");
								}
								//xarti/psalidi
								else{
									printf("To Psalidi kovei to Xarti\n%s+1 pontos",name2);
									winp2++;
								}
							}
							else{
								//psalidi/petra
								if (fingersp2==1){
									printf("H Petra spaei to Psalidi\n%s+1 pontos",name2);
									winp2++;
								}
								//psalidi/xarti
								else if (fingersp2==2){
									printf("To Psalidi kovei to Xarti\n%s+1 pontos",name1);
									winp1++;
								}
								//2 psalidia
								else{
									printf("Psalidi enantiwn Psalidiou\nISOPALIA");
								}
							}
							printf("\n\n");
							for(i=0;i<10;i++)printf("%c%c%c",223,219,220);
							//for(i=0;i<7;i++)printf("%c%c%c%c",223,219,220,219); //another printable line
							printf("\n");
							turn++;
							if (winp1>winp2){
								printf("\n%sNIKH!\n",name1);
							}
							else if (winp1<winp2){
								printf("\n%sNIKH!\n",name2);
							}
							else{
								printf("\nISOPALIA -.-\n");
							}
							break;
						//Prosarmosmeno oi paixtes epilegoun to megisto gyro
						case 3:
							do{
								maxTurns=0;
								printf("Posous gurous 8elete? ");
								scanf("%d",&maxTurns);
								fflush(stdin);
							}while(maxTurns<1);
							//elegxos megistou gyrou h' nikhth/rias
							do{
								printf("\nPaixnidi:%d\nGyros:%d\n\nSkor\nPaixths/ria1: %d\nPaixths/ria2: %d\n",game,turn,winp1,winp2);
								//epilogh daxtylwn paixth/rias 1
								do{
									fingersp1=0;
									printf("\n%s(1)Petra/(2)Xarti/(3)Psalidi\nEpilogh: ",name1);
									scanf("%d",&fingersp1);
									fflush(stdin);
								}while((fingersp1<1)||(fingersp1>3));
								clrprnt2();
								printf("\nPaixnidi:%d\nGyros:%d\n\nSkor\nPaixths/ria1: %d\nPaixths/ria2: %d\n",game,turn,winp1,winp2);
								//epilogh daxtylwn paixth/rias 2
								do{
									fingersp2=0;
									printf("\n%s(1)Petra/(2)Xarti/(3)Psalidi\nEpilogh: ",name2);
									scanf("%d",&fingersp2);
									fflush(stdin);
								}while((fingersp2<1)||(fingersp2>3));
								printf("\n%sepilogh: %s\n\n",name1,(fingersp2==1)?"Petra":(fingersp2==2)?"Xarti":"Psalidi");
								//elegxos nikhs
								if (fingersp1==1){
									//2 petres
									if (fingersp2==1){
										printf("Petra enantiwn Petras\nISOPALIA");
									}
									//petra/xarti
									else if (fingersp2==2){
										printf("To Xarti tuligei th Petra\n%s+1 pontos",name2);
										winp2++;
									}
									//petra/psalidi
									else{
										printf("H Petra spaei to Psalidi\n%s+1 pontos",name1);
										winp1++;
									}
								}
								else if (fingersp1==2){
									//xarti/petra
									if (fingersp2==1){
										printf("To Xarti tuligei th Petra\n%s+1 pontos",name1);
										winp1++;
									}
									//2 xartia
									else if (fingersp2==2){
										printf("Xarti enantiwn Xartiou\nISOPALIA");
									}
									//xarti/psalidi
									else{
										printf("To Psalidi kovei to Xarti\n%s+1 pontos",name2);
										winp2++;
									}
								}
								else{
									//psalidi/petra
									if (fingersp2==1){
										printf("H Petra spaei to Psalidi\n%s+1 pontos",name2);
										winp2++;
									}
									//psalidi/xarti
									else if (fingersp2==2){
										printf("To Psalidi kovei to Xarti\n%s+1 pontos",name1);
										winp1++;
									}
									//2 psalidia
									else{
										printf("Psalidi enantiwn Psalidiou\nISOPALIA");
									}
								}
								printf("\n\n");
								for(i=0;i<10;i++)printf("%c%c%c",223,219,220);
								//for(i=0;i<7;i++)printf("%c%c%c%c",223,219,220,219); //another printable line
								printf("\n");
								turn++;
							}while((turn<=maxTurns)&&(winp1<=(maxTurns/2))&&(winp2<=(maxTurns/2)));
							if (winp1>winp2){
								printf("\n%sNIKH!\n",name1);
								if ((maxTurns>=3)&&(winp2==0))
									printf("KAI H PIO TYXERH ONTOTHTA STO KOSMO\n");
							}
							else if (winp1<winp2){
								printf("\n%sNIKH!\n",name2);
								if ((maxTurns>=3)&&(winp1==0))
									printf("KAI H PIO TYXERH ONTOTHTA STO KOSMO\n");
							}
							else{
								printf("\nISOPALIA -.-\n");
							}
							break;
					}
				}
				if(bell==2){
					printf("\a");
				}
				printf("\n\n%c",218);for(i=0;i<30;i++)printf("%c",196);printf("%c",191);
				printf("\n%c%c%c%c8elete na ksanapaiksete?%c%c%c%c\n",179,178,177,176,176,177,178,179);
				printf("%c",192);for(i=0;i<30;i++)printf("%c",196);printf("%c",217);
				//epanalhpsh paixnidiou
				do{
					again=0;
					printf("\n(1)nai/(2)oxi: ");
					scanf("%d",&again);
					fflush(stdin);
				}while((again<1)||(again>2));
				if (again==1){
					clrprnt2();
					game++;
				}
				//apoxairetisthries eyxes
				else{
					srand(time(NULL));
					wish=(rand()%3);
					switch(wish){
						case 0:
							printf("\nEntaksei\nKalh sas mera ^.^");
							break;
						case 1:
							printf("\nMexri thn epomenh fora...\nAntio :D");
							break;
						case 2:
							printf("\nNa exete mia omorfh mera <3");
							break;
					}
				}
			}while(again==1);
			break;
		case 3:
			//french version
			printf("\nPARDON\nCETTE LANGUE\nEN COURS DE CONSTRUCTION\n");
			break;
	}	
	return 0;
}

//clear_screen+game_title+date_time
void clrprnt(){
	int i;

	system("cls");
	printf("%c",201);for(i=0;i<25;i++)printf("%c",205);printf("%c",187);
	printf("\n%c%c%c%cROCK-PAPER-SCISSORS%c%c%c%c\n",186,178,177,176,176,177,178,186);
	printf("%c",200);for(i=0;i<25;i++)printf("%c",205);printf("%c",188);
	printf("\n");for(i=0;i<27;i++)printf("%c",246);
	date();
	for(i=0;i<27;i++)printf("%c",246);printf("\n");
}

//current_date+time
void date(){
	time_t t=time(NULL);
    struct tm tm=*localtime(&t);
	int day, month, year, seconds, minutes, hour;
	
	day=tm.tm_mday;
	month=tm.tm_mon+1;
	year=tm.tm_year+1900;
	
	printf("\n ");
	
	switch(tm.tm_wday) {
		case 0: printf("Sunday"); break;
		case 1: printf("Monday"); break;
		case 2: printf("Tuesday"); break;
		case 3: printf("Wednesday"); break;
		case 4: printf("Thursday"); break;
		case 5: printf("Friday"); break;
		case 6: printf("Saturday"); break;
		default: printf("WRONG DAY");
	}
	
	printf("\n %d ",day);
	
	switch(month) {
		case 1: printf("January"); break;
		case 2: printf("February"); break;
		case 3: printf("March"); break;
		case 4: printf("April"); break;
		case 5: printf("May"); break;
		case 6: printf("June"); break;
		case 7: printf("July"); break;	
		case 8: printf("August"); break;
		case 9: printf("September"); break;
		case 10: printf("October"); break;
		case 11: printf("November"); break;
		case 12: printf("December"); break;
		default: printf("WRONG MONTH");
	}
	
	printf(" %d\n ",year);
	
	minutes=tm.tm_min;
	hour=tm.tm_hour;
	
	if(hour>12)
        printf("%d:%d p.m.",(hour-12), minutes);
    else
		printf("%d:%d a.m.",hour, minutes);
	
	printf("\n");
}

//ekka8arish_o8onhs+titlos_paixnidiou+hmeromhnia_wra
void clrprnt2(){
	int i;

	system("cls");
	printf("%c",201);for(i=0;i<25;i++)printf("%c",205);printf("%c",187);
	printf("\n%c%c%c%cPETRA-PSALIDI-XARTI%c%c%c%c\n",186,178,177,176,176,177,178,186);
	printf("%c",200);for(i=0;i<25;i++)printf("%c",205);printf("%c",188);
	printf("\n");for(i=0;i<27;i++)printf("%c",246);
	date2();
	for(i=0;i<27;i++)printf("%c",246);printf("\n");
}

//twrinh_hmeromhnia+wra
void date2(){
	time_t t=time(NULL);
    struct tm tm=*localtime(&t);
	int day, month, year, seconds, minutes, hour;
	
	day=tm.tm_mday;
	month=tm.tm_mon+1;
	year=tm.tm_year+1900;
	
	printf("\n ");
	
	switch(tm.tm_wday) {
		case 0: printf("Kuriakh"); break;
		case 1: printf("Deutera"); break;
		case 2: printf("Trith"); break;
		case 3: printf("Tetarth"); break;
		case 4: printf("Pempth"); break;
		case 5: printf("Paraskevh"); break;
		case 6: printf("Savvato"); break;
		default: printf("LATHOS MERA");
	}
	
	printf("\n %d ",day);
	
	switch(month) {
		case 1: printf("Ianouariou"); break;
		case 2: printf("Fevrouariou"); break;
		case 3: printf("Martiou"); break;
		case 4: printf("Apriliou"); break;
		case 5: printf("Maiou"); break;
		case 6: printf("Iouniou"); break;
		case 7: printf("Iouliou"); break;	
		case 8: printf("Avgoustou"); break;
		case 9: printf("Septemvriou"); break;
		case 10: printf("Oktwvriou"); break;
		case 11: printf("Noemvriou"); break;
		case 12: printf("Dekemvriou"); break;
		default: printf("LATHOS MHNAS");
	}
	
	printf(" %d\n ",year);
	
	minutes=tm.tm_min;
	hour=tm.tm_hour;
	
	if(hour>12)
        printf("%d:%d m.m.",(hour-12), minutes);
    else
		printf("%d:%d p.m.",hour, minutes);
	
	printf("\n");
}

/*							CAUTION
1)
This program was created with Greek 8bit ASCII code and runs properly according to:
this ASCII version, Hebrew version, Portuguese version, French_Canadian version, Nordic version, Cyrillic version
2)
a)Ôhis program was created from Windows10 Operating System and for Windows10 Operating System
b)Other operating systems may or may not support this program with or without bugs
3)
Ôhis program was created from IDE-compiler Dev-C++ 5.5.3
*/
