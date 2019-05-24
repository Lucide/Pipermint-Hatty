//Riccardo Cavasin

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int lettura();
void mole(int a[],int b[],int c[],int le);
void render(int a[],int b[],int c[],int le);
int splsh();

int main(int argv, char**argc){

	int a[50],b[50],c[50];
	int mov,pnt,pos;
	srand(time(NULL));
	
	do{
		mov=splsh();
		if(mov==1){
			do{
				mole(a,b,c,50);
				pnt=0;
				b[0]=2;
				pos=1;

				do{
					if(pos==2 && b[pnt]==0){				//fisica.
						a[pnt]=0;
						b[pnt]=2;
						pos=1;
					}
					if(pos==1 && c[pnt]==0){
						b[pnt]=0;
						c[pnt]=2;
						pos=0;
					}										//.fisica

					render(a,b,c,50);
					mov=lettura();

					if(mov==1){
						if(pnt==49)							//ultimo caso (fuori vettore)
							pnt=50;
						else{
							if(pos==0 && c[pnt+1]==0){
								c[pnt]=0;
								pnt=pnt+1;
								c[pnt]=2;
							}
							if(pos==1 && b[pnt+1]==0){
								b[pnt]=0;
								pnt=pnt+1;
								b[pnt]=2;
							}
							if(pos==2 && a[pnt+1]==0){
								a[pnt]=0;
								pnt=pnt+1;
								a[pnt]=2;
							}
							if(pos==0 && c[pnt+2]==0 && c[pnt+1]==3){
								c[pnt]=0;
								pnt=pnt+1;
								c[pnt]=2;
								c[pnt+1]=3;
							}
						}
					}
					
					if(mov==2 && pnt!=49){			// c'è bisogno degli else (si influenzano), ultimo caso
						if(pos==0 && (c[pnt+1]==1 || c[pnt+1]==3) && b[pnt]==0 && b[pnt+1]==0){	//caso con cassa
							c[pnt]=0;
							pnt=pnt+1;
							b[pnt]=2;
							pos=1;
						}
						else{
							if(pos==1 && b[pnt+1]==1){
								b[pnt]=0;
								pnt=pnt+1;
								a[pnt]=2;
								pos=2;
							}
						}
					}
				}while(pnt<50 && mov!=5 && mov!=6);
			}while(mov!=6);
		}
		else
			system("clear");
	}while(mov!=2);

return 0;
}

int lettura(){
	int lettura;
	scanf("%d", &lettura);
return lettura;
}

void mole(int a[],int b[],int c[],int le){
int i,temp,korg=1;

	for(i=0;i<50;i=i+1)
		a[i]=1;
	for(i=0;i<50;i=i+1)
		b[i]=1;
	for(i=0;i<50;i=i+1)
		c[i]=1;
i=0;
	for(;i<le;i=i+1){
		temp=(rand()%5);

		if(korg==0){
			a[i]=0;
			korg=0;
			if(temp>2){
				if(temp==3 && (i+2)<(le)){
					i=i+1;
					a[i]=0;
					b[i]=0;
					c[i]=0;
					korg=2;
				}
				else{
					b[i]=0;
					korg=1;
				}
			}
		}
		else{
			if(korg==1){
				b[i]=0;
				korg=1;
				if(temp>2){
					if(temp==3){
						a[i]=0;
						korg=0;
					}
					else{
						c[i]=0;
						korg=2;
					}
				}
			}
			else{
				if(korg==2){
					c[i]=0;
					korg=2;
					if(temp>2){
						if(temp==3 && (i+3)<(le)){		//boh
							c[i]=3;
							i=i+1;
							c[i]=0;
							b[i]=0;
							i=i+1;
							c[i]=0;
							b[i]=0;
							a[i]=0;
							korg=0;
						}
						else{
							b[i]=0;
							korg=1;
						}
					}
				}
			}
		}
//printf("newkorg=%d,temp=%d,i=%d,c0=%d ",korg,temp,i,c[0]);
	}
}


void render(int a[],int b[],int c[],int le){
int i;
	system("clear");
	printf("                                                               .---.\n                                                              /  .  \\\n                                                             |\\_/|   |\n                                                             |   |  /|\n  .----------------------------------------------------------------' |\n /  .-.                         MOLE VER 4.28a                       |\n|  /   \\                                                             |\n");

	printf("| |\\_.  |   ▓▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░");

	printf("▒▓   |\n|\\|  | /|   ▓▒");
	for(i=0;i<le;i=i+1){
		if(a[i]==0)
			printf(" ");
		if(a[i]==1)
			printf("░");
		if(a[i]==2)
			printf("♀");
		if(a[i]==3)
			printf("▪");
	}
	printf("▒▓   |\n| `---' |   ▓▒");
	for(i=0;i<le;i=i+1){
		if(b[i]==0)
			printf(" ");
		if(b[i]==1)
			printf("░");
		if(b[i]==2)
			printf("♀");
		if(b[i]==3)
			printf("▪");
	}
	printf("▒▓   |\n|       |   ▓▒");
	for(i=0;i<le;i=i+1){
		if(c[i]==0)
			printf(" ");
		if(c[i]==1)
			printf("░");
		if(c[i]==2)
			printf("♀");
		if(c[i]==3)
			printf("▪");
	}
	printf("▒▓   |\n|       |   ▓▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▓   |\n");

	printf("|       |                                                           /\n|       |----------------------------------------------------------'\n\\       |╭────────────────────┬──┰─────────────────────────────────────╮\n \\     / │◍ insert ⓵  to move ╷→ ┃◍ insert ⑤  to generate a new terrain│\n  `---'  │◍ insert ⓶  to jump ╵↷ ┃◍ insert ⑥  to exit                  │\n         ╰────────────────────┴──┸─────────────────────────────────────╯\n         ☛ ");
}

int splsh(){
int chc;
	do{
		system("clear");
		printf(" _____ ____  _____ _____ _____ _____ _____ _____ _____    _____ _____\n|  _  |    \\|  |  |   __|   | |_   _|  |  | __  |   __|  |     |   __|\n|     |  |  |  |  |   __| | | | | | |  |  |    -|   __|  |  |  |   __|\n|__|__|____/ \\___/|_____|_|___| |_| |_____|__|__|_____|  |_____|__|\n(    .   ╔══════════════════════════════════════════════════╗   .    )\n `.   `. ║          ░░░░░░          ﹌       ░░░░░░░░░░░    ║ .'   .'\n   )    )║     ░░░░░░░░░░░░░░░░░░ ﹌     ﹌      ░░░░░░░░░░ ║(    (\n .'   .' ║  ░░░░░░░░░░░░░░░░░ _.-\"\"\"\"-._  ░░░░░░░░░░░░░     ║ `.   `.\n(    (   ║    ░░░░░░░       .'          `.   ░░░░░░░░░░░░░░ ║   )    )\n `.   `. ║                 /              \\                 ║ .'   .'\n   )    )║_௱௱________௱____|______♀__▪______|____௱௱௱_____௱___║(    (\n .'   .' ║          __..--''_,-'.'  '.'-,_''--..__          ║ `.   `.\n(    (   ║  __..--''    _,-'  .'      '.  '-,_    ''--..__  ║   )    )\n `.   `. ║''         ,-'    .'          '.    '-,         ''║ .'   .'\n   )    )╚══════════════════════════════════════════════════╝(    (\n   ______  _____ ______  _____ ______ ___  ___ _____  _   _  _____\n   | ___ \\|_   _|| ___ \\|  ___|| ___ \\|  \\/  ||_   _|| \\ | ||_   _|\n   | |_/ /  | |  | |_/ /| |__  | |_/ /| .  . |  | |  |  \\| |  | |\n   |  __/   | |  |  __/ |  __| |    / | |\\/| |  | |  | . ` |  | |\n   | |     _| |_ | |    | |___ | |\\ \\ | |  | | _| |_ | |\\  |  | |\n   \\_|     \\___/ \\_|    \\____/ \\_| \\_|\\_|  |_/ \\___/ \\_| \\_/  \\_/\n    _   _   ___  _____  _____ __   __ ╭──────────────────────────────╮\n   | | | | / _ \\|_   _||_   _|\\ \\ / / │    ᖗ INSERT 1 TO START ᖘ     │\n   | |_| |/ /_\\ \\ | |    | |   \\ V /  │    ᖙ     2 to exit     ᖚ     │\n   |  _  ||  _  | | |    | |    \\ /   │                              │\n   | | | || | | | | |    | |    | |   │v4.71 alpha                   │\n   \\_| |_/\\_| |_/ \\_/    \\_/    \\_/   │28/12/15               ⓛⓤⓒⓘⓓⓔ │\n                                      ╰──────────────────────────────╯\n☛ ");
		scanf("%d", &chc);
	}while(chc!=1 && chc!=2);
return chc;
}





