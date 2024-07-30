#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
using namespace std;
struct game{
	string name;
	int choice;
};
struct cas{
	int amount;
	int bidAmount;
	int guess;
	int dice;
	string choice;
};
//rps stands for rock paper scissors in this program
struct rpsGame{
	int cChoice; //computers choice
	int pChoice; //players choice
	int pScore; //players score
	int cScore; //computers score
	int rounds;
};
void rules_cas(); //rules for casino game
void rules_rps(); //rules for rps game
void welcome(); //displays welcome screen for the game
void winner(rpsGame g, game game); //function for the final winner of rps game
void rps_Game(rpsGame g, game game); //body of the rps game
void casino(cas c, game game); //body of the casino game

int main()
{
	 srand(time(0)); //this is a function into a function. We are using the rand function through <cstdlib> and combining it with <ctime> we get srand(time(0))
	 game game; 
	 cas c; 
	 rpsGame g;
	 g.cScore=0, g.pScore=0;
	
	welcome();
	
	 cout<<"Enter name: "<<endl;
	 cin>>game.name;
	 cout<<"Hello "<<game.name<<"!!"<<endl;
	 cout<<" Lets play a game."<<endl;
		
	do{
	 	cout<<" Press 1 for Rock PAPER AND Scissors Game "<<endl;
	 	cout<<" or "<<endl;
	 	cout<<" 2 for Casino number Guessing Game"<<endl;
	 	cout<<" What game do you want to play?"<<endl;
	 	cin>>game.choice;
		     system("cls");
	     switch(game.choice)
		{
		     case 1:
			     rules_rps();
			     do{
			         cout<<"How many round you want to play?"<<endl;
	                 cin>>g.rounds;
	                 rps_Game(g, game);
	                 cout<<"Do you want to play again? yes/Yes"<<endl;
                     cin>>c.choice;
                   }while(c.choice=="Yes"||c.choice=="yes");
                 cout<<"See you soon!!"<<endl;
	             break;
		     case 2:
		         rules_cas();
			     do{
			         casino(c, game);
		         	 cout<<"Do you want to play again? yes/Yes"<<endl;
                     cin>>c.choice;
                   }while(c.choice=="Yes"||c.choice=="yes");
                 cout<<"See you soon!!"<<endl;
		         break;
	    	default:
		      	cout<<"Invalid input"<<endl;	
		}
     cout<<"Do you want to go to the main menu? yes/Yes"<<endl;
     cin>>c.choice;
    }	while(c.choice=="Yes"||c.choice=="yes");
     cout<<"Come soon to play a game. BYE BYE "<<game.name<<" ^_^ "<<endl;
}
		
void welcome(){
     cout<<"          __________________________________________"<<endl;
 	cout<<"         |------------------------------------------|"<<endl;
 	cout<<"         |------------------------------------------|"<<endl;
 	cout<<"         |---------WELCOME TO THE GAME HUB----------|"<<endl;
 	cout<<"         |------------------------------------------|"<<endl;
 	cout<<"         |------------------------------------------|"<<endl;
 	cout<<"         |__________________________________________|"<<endl; }

void rules_rps(){
 	cout<<"You would already know the rules for rock paper scissors."<<endl;
 	cout<<"But in case you are an alien. Here they are: "<<endl;
 	cout<<"You will play how ever many rounds you like. The final winner will be the one with the highest score."<<endl;
 	cout<<"If you play rock you will win if computer plays scissors but will lose if computer plays paper."<<endl;
 	cout<<"If you play scissors you will win if computer plays paper but will lose if computer plays rock."<<endl;
 	cout<<"If you play paper you will win if computer plays rock but will lose if computer plays scissors."<<endl;
 	cout<<"Good luck!"<<endl; }

void rps_Game(rpsGame g, game game)//function for the main part of the rps game
{	for(int i=1; i<=g.rounds; i++)
	{
	 	cout<<"Round No."<<i<<"/"<<g.rounds<<endl;
	 	cout<<"1. ROCK"<<endl;
	 	cout<<"2. PAPER"<<endl;
	 	cout<<"3. SCISSOR"<<endl;
	     	do{
	 	     cout<<"Enter your choice: "<<endl;
	         cin>>g.pChoice;
	         }while(g.pChoice!=1 && g.pChoice!=2 && g.pChoice!=3);
	         
	 //We need the computer to choose a random choice for both the games in this program so we use the rand function and store it in the choice variable.
	 g.cChoice=(rand()%3)+1; /*now if we get any random number however big it may be it will be divided by 3 and the remainder will always be less than 3. We add it with 1 incase
	the remainder is 0.*/
	
		if(g.pChoice==1 /*rock*/ && g.cChoice==3 /*scissors*/)
		    {
	     	cout<<"Computers choice was: "<<g.cChoice<<endl;
		    cout<<"You Win"<<endl;
		    g.pScore++;
		    cout<<"Player score is: "<<g.pScore<<endl;	
			}
	    else if(g.pChoice==2 /*paper*/ && g.cChoice==1 /*rock*/)
			{
	     	cout<<"Computers choice was: "<<g.cChoice<<endl;
	 	    cout<<"You Win"<<endl;
	 	    g.pScore++;
	 	    cout<<"Player score is:"<<g.pScore<<endl;
     	 	}
	    else if(g.pChoice==3 /*scissors*/ && g.cChoice==2 /*paper*/)
		    {
	  	    cout<<"Computers choice was: "<<g.cChoice<<endl;
	 	    cout<<"You Win"<<endl;
	  	    g.pScore++;
	 	    cout<<"Player score is:"<<g.pScore<<endl;		
			}
	    else if (g.pChoice == g.cChoice)
		    {
	 	    cout<<"Computers choice was: "<<g.cChoice<<endl;
     	    cout<<"Its a draw."<<endl;	
			}
        else
		    {
	        cout<<" Computer wins."<<endl;
	        g.cScore++;
	        cout<<"Computers choice was: "<<g.cChoice<<endl;
	        cout<<"Computer score is: "<<g.cScore<<endl;
       	    }
     	 cout<<"Press any key to continue...."<<endl;
	     getch();
    	 system("cls");   
	}
	     winner(g, game);//This is a function into a function. The winner function tells us about the final winner of the rps game    
 }
	
void winner(rpsGame g, game game)//function for final winner of the rps game
{
	if (g.cScore==g.pScore)	{
		 cout<<"Looks like its a draw better luck next time  ._."<<endl;	}
		
	else if(g.pScore>g.cScore)	{
		 cout<<"Hurray!! This is your lucky day :D "<<game.name<<" ~ ~ You win by "<<g.pScore<<endl;	}
		
	else	{
		 cout<<"Oh no!! Looks like its not your lucky day T_T ~ ~  Computer wins by "<<g.cScore<<" score"<<endl;	}  
}
 
void rules_cas()
{
	 cout<<"Here are the rules: "<<endl;
	 cout<<"Choose Number Between 1 To 10"<<endl;
	 cout<<"If you guessed the number that the computer randomly selected you will win"<<endl;
     cout<<"Winner will win double the bidding amount"<<endl;
     cout<<"Loser will lose biding Amount"<<endl;
}
void casino(cas c, game game)
{
	do{
	    cout<<"Enter total amount: "<<endl;
	    cin>>c.amount;
    	cout<<"Enter bid amount: "<<endl;
	    cin>>c.bidAmount;
	    while(c.bidAmount>c.amount){
	        cout<<"Re-enter bid amount. It can not be greater than total amount."<<endl;
	        cout<<"Enter bid amount: "<<endl;
            cin>>c.bidAmount;	}
	    cout<<"Guess a number between 1-10: "<<endl;
	    cin>>c.guess;
        while(c.guess>10||c.guess<0){
		    cout<<"Number cannot be greater than 10 or lesser than 0. Please re-enter number: "<<endl;
	        cin>>c.guess; }
	        c.dice=(rand()%10)+1;
			//if we get any random number however big it may be it will be divided by 3 and the remainder will always be less than 3. We add it with 1 incase the remainder is 0.
	    if(c.guess==c.dice){
	  	     c.amount=c.amount+c.bidAmount*2;
	         cout <<"Hurray!! You have won "<<c.amount<<"$"<<endl;
	         break;	}
        else(c.guess!=c.dice);{
             cout<<"Sorry!! You lost "<<c.bidAmount<<"$"<<endl;
             c.amount=c.amount-c.bidAmount;	}
             cout<<"The winning number was "<<c.dice<<endl;
             cout<<game.name<<" Your remaining balance is "<<c.amount<<"$"<<endl;
        if(c.amount==0){
             cout<<"Since your wallet is now empty, you can not play again."<<endl;		}
             cout<<"Do you want to go to the menu?"<<endl;
             cin>>c.choice;
    } 
    while(c.choice=="Yes"||c.choice=="yes");
    system("cls");
    cout<<"Thanks for playing the game. GOODBYE "<<game.name<<"!!"<<endl;
}
