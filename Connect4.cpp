/* Connect 4 against player */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Class Definition
class Connect4{
public:
	void Display();
	int Place(int);
	int CheckWin();
	Connect4();
	string Turn;
private:
	string Board[8][8];
};

Connect4::Connect4(){
	Turn="O";
	for (int x=0;x<8;x++){
		for (int y=0;y<8;y++){
			Board[x][y]=" ";
		}
	}
}

void Connect4::Display(){
	cout<<" 1 2 3 4 5 6 7 8"<<endl;
	for (int x=0;x<8;x++){
		string z="|";
		for (int y=0;y<8;y++){
			z+=Board[x][y]+"|";
		}
		cout<<z<<endl;
	}
	cout<<"-----------------"<<endl;
}

int Connect4::Place(int col){
	if (col<1||col>8) {return 0;}
	for (int x=7;x>=0;x--){
		if (Board[x][col-1]==" "){
			Board[x][col-1]=Turn;
			return 1;
		}
	}
	return 0;
}

int Connect4::CheckWin(){
	// Horizontal
	for (int y=0;y<5;y++){
		for (int x=0;x<8;x++){
			string _test="";
			for (int i=y;i<y+4;i++){
				_test = _test+Board[x][i];
			}
			if (_test=="OOOO"||_test=="XXXX"){
				return 1;
			}
		}
	}
	// Vertical
	for (int x=0;x<5;x++){
		for (int y=0;y<8;y++){
			string _test="";
			for (int i=x;i<x+4;i++){
				_test=_test+Board[i][y];
			}
			if (_test=="OOOO"||_test=="XXXX"){
				return 1;
			}
		}
	}
	// Diagonal Right
	for (int x=0;x<5;x++){
		for (int y=0;y<5;y++){
			string _test="";
			int _index=0;
			for (int i=x;i<x+4;i++){
				_test=_test+Board[i][y+_index];
				_index=_index+1;
			}
			if (_test=="OOOO"||_test=="XXXX"){
				return 1;
			}
		}
	}
	// Diagonal Left
	for (int x=7;x>2;x--){
		for (int y=0;y<5;y++){
			string _test="";
			int _index=0;
			for (int i=x;i>x-4;i--){
				_test=_test+Board[i][y+_index];
				_index=_index+1;
			}
			if (_test=="OOOO"||_test=="XXXX"){
				return 1;
			}
		}
	}
	for (int x=0;x<8;x++){
		for (int y=0;y<8;y++){
			if (Board[x][y]==" "){
				return 0;
			}
		}
	}
	return 3;
}

// Main Function
int main(){
	Connect4 game;
	while (game.CheckWin()==0){
		// Game in progress
		if (game.Turn=="O") {game.Turn="X";}
		else {game.Turn="O";}
		game.Display();
		string answer="0";
		while (game.Place(stoi(answer))==0){
			cout<<"Player "+game.Turn+" choose a column (1-8): ";
			cin>>answer;
		}
	}
	// Player won
	game.Display();
	if (game.CheckWin()==3){cout<<"The game was a tie!"<<endl;}
	else{cout<<"Player "+game.Turn+" won!"<<endl;}
	return 0;
}