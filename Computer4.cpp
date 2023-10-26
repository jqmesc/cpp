/* Connect 4 against computer */

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Computer4{
public:
	void Display();
	int Place(string[8][8],int);
	int TryStrategy();
	int TryWin();
	int TryBlock(string[8][8]);
	int CheckWin();
	int TryPlacement(int);
	Computer4();
	string Turn;
	string Board[8][8];
private:
};

Computer4::Computer4(){
	Turn="X";
	for (int x=0;x<8;x++){
		for (int y=0;y<8;y++){
			Board[x][y]=" ";
		}
	}
}

void Computer4::Display(){
	cout<<"\n 1 2 3 4 5 6 7 8"<<endl;
	for (int x=0;x<8;x++){
		string z="|";
		for (int y=0;y<8;y++){
			z+=Board[x][y]+"|";
		}
		cout<<z<<endl;
	}
	cout<<"-----------------"<<endl;
}

int Computer4::Place(string B[8][8],int col){
	if (col<1||col>8) {return 0;}
	for (int x=7;x>=0;x--){
		if (B[x][col-1]==" "){
			B[x][col-1]=Turn;
			return 1;
		}
	}
	return 0;
}

int Computer4::CheckWin(){
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
	// Tie
	for (int x=0;x<8;x++){
		for (int y=0;y<8;y++){
			if (Board[x][y]==" "){
				return 0;
			}
		}
	}
	return 3;
}

int Computer4::TryWin(){
	// Horizontal
	for (int y=0;y<5;y++){ // Check win first
		for (int x=0;x<8;x++){
			string _test="";
			for (int i=y;i<y+4;i++){
				_test = _test+Board[x][i];
			}
			string::difference_type n=count(_test.begin(),_test.end(),'X');
			int index=_test.find(" ");
			if (n==3&&index>=0){
				if (x==7||Board[x+1][y+index]!=" "){
					return y+index;
				}
			}
		}
	}
	// Vertical
	for (int x=0;x<5;x++){ // Check win first
		for (int y=0;y<8;y++){
			string _test="";
			for (int i=x;i<x+4;i++){
				_test=_test+Board[i][y];
			}
			string::difference_type n=count(_test.begin(),_test.end(),'X');
			int index=_test.find(" ");
			if (n==3&&index>=0){
				return y;
			}
		}
	}
	// Diagonal Right
	for (int x=0;x<5;x++){ // Check win first
		for (int y=0;y<5;y++){
			string _test="";
			int _index=0;
			for (int i=x;i<x+4;i++){
				_test=_test+Board[i][y+_index];
				_index=_index+1;
			}
			string::difference_type n=count(_test.begin(),_test.end(),'X');
			int index=_test.find(" ");
			if (n==3&&index>=0){
				if (x+index==7||Board[x+index+1][y+index]!=" "){
					return y+index;
				}
			}
		}
	}
	// Diagonal Left
	for (int x=7;x>2;x--){ // Check win first
		for (int y=0;y<5;y++){
			string _test="";
			int _index=0;
			for (int i=x;i>x-4;i--){
				_test=_test+Board[i][y+_index];
				_index=_index+1;
			}
			string::difference_type n=count(_test.begin(),_test.end(),'X');
			int index=_test.find(" ");
			if (n==3&&index>=0){
				if (x-index==7||Board[x-index+1][y+index]!=" "){
					return y+index;
				}
			}
		}
	}
	return -1;
}
int Computer4::TryBlock(string B[8][8]){
	// Horizontal
	for (int y=0;y<5;y++){ // Block opponent second
		for (int x=0;x<8;x++){
			string _test="";
			for (int i=y;i<y+4;i++){
				_test = _test+B[x][i];
			}
			
			string::difference_type n=count(_test.begin(),_test.end(),'O');
			int index=_test.find(" ");
			if (n==3&&index>=0){
				if (x==7||B[x+1][y+index]!=" "){
					return y+index;
				}
			}
		}
	}
	// Vertical
	for (int x=0;x<5;x++){ // Block opponent second
		for (int y=0;y<8;y++){
			string _test="";
			for (int i=x;i<x+4;i++){
				_test=_test+B[i][y];
			}
			string::difference_type n=count(_test.begin(),_test.end(),'O');
			int index=_test.find(" ");
			if (n==3&&index>=0){
				return y;
			}
		}
	}
	// Diagonal Right
	for (int x=0;x<5;x++){ // Block opponent second
		for (int y=0;y<5;y++){
			string _test="";
			int _index=0;
			for (int i=x;i<x+4;i++){
				_test=_test+B[i][y+_index];
				_index=_index+1;
			}
			string::difference_type n=count(_test.begin(),_test.end(),'O');
			int index=_test.find(" ");
			if (n==3&&index>=0){
				if (x+index==7||B[x+index+1][y+index]!=" "){
					return y+index;
				}
			}
		}
	}
	// Diagonal Left
	for (int x=7;x>2;x--){ // Block opponent second
		for (int y=0;y<5;y++){
			string _test="";
			int _index=0;
			for (int i=x;i>x-4;i--){
				_test=_test+B[i][y+_index];
				_index=_index+1;
			}
			string::difference_type n=count(_test.begin(),_test.end(),'O');
			int index=_test.find(" ");
			if (n==3&&index>=0){
				if (x-index==7||B[x-index+1][y+index]!=" "){
					return y+index;
				}
			}
		}
	}
	return -1;
}
int Computer4::TryPlacement(int col){
	// Check possible to place without win
	int n=0;
	for (int x=1;x<8;x++){	
		string newBoard[8][8];
		for (int x=0;x<8;x++){
			for (int y=0;y<8;y++){
				newBoard[x][y]=Board[x][y];
			}
		}
		Place(newBoard,x);
		if (TryBlock(newBoard)==-1) {break;}
		else {n++;}
		if (n==8){return col;}
	}
	// Check next placement will not cause player to win
	string newBoard[8][8];
	for (int x=0;x<8;x++){
		for (int y=0;y<8;y++){
			newBoard[x][y]=Board[x][y];
		}
	}
	Place(newBoard,col);
	return TryBlock(newBoard);
}
int Computer4::TryStrategy(){
	// Check for _ XX _
	for (int y=0;y<4;y++){
		for (int x=0;x<8;x++){
			string _test="";
			for (int i=y;i<y+4;i++){
				_test = _test+Board[x][i];
			}
			int index=0;
			if (_test==" OO "){
				index=0;
				if (TryPlacement(y+index+1)==-1){
					if (x==7||Board[x+1][y+index]!=" "){
						return y+index;
					}
				}
				index=3;
				if (TryPlacement(y+index+1)==-1){
					if(x==7||Board[x+1][y+index]!=" "){
						return y+index;
					}
				}
			}
		}
	}
	// Between two
	for (int y=0;y<5;y++){
		for (int x=0;x<8;x++){
			string _test="";
			for (int i=y;i<y+4;i++){
				_test = _test+Board[x][i];
			}
			int index=1;
			if (_test=="O O "){
				if (TryPlacement(y+index+1)==-1){
					if (x==7||Board[x+1][y+index]!=" "){
						return y+index;
					}
				}
			}
			else if (_test==" O O"){
				index=2;
				if (TryPlacement(y+index+1)==-1){
					if (x==7||Board[x+1][y+index]!=" "){
						return y+index;
					}
				}
			}
		}
	}
	// Horizontal
	for (int y=0;y<5;y++){ // Try for 3 in a row
		for (int x=0;x<8;x++){
			string _test="";
			for (int i=y;i<y+4;i++){
				_test = _test+Board[x][i];
			}
			int index=0;
			if (_test==" X X"){
				index=0;
				if (TryPlacement(y+index+1)==-1){
					if (x==7||Board[x+1][y+index]!=" "){
						return y+index;
					}
				}
				else if (TryPlacement(y+index+1)==-1){
					index=2;
					if (x==7||Board[x+1][y+index]!=" "){
						return y+index;
					}
				}
			}
			else if (_test=="X X "){
				index=1;
				if (TryPlacement(y+index+1)==-1){
					if (x==7||Board[x+1][y+index]!=" "){
						return y+index;
					}
				}
				else if (TryPlacement(y+index+1)==-1){
					index=3;
					if (x==7||Board[x+1][y+index]!=" "){
						return y+index;
					}
				}
			}
			else if (_test=="XX  "){
				index=2;
				if (TryPlacement(y+index+1)==-1){
					if (x==7||Board[x+1][y+index]!=" "){
						return y+index;
					}
				}
				else if (TryPlacement(y+index+1)==-1){
					index=3;
					if (x==7||Board[x+1][y+index]!=" "){
						return y+index;
					}
				}
			}
			else if (_test=="  XX"){
				index=0;
				if (TryPlacement(y+index+1)==-1){
					if (x==7||Board[x+1][y+index]!=" "){
						return y+index;
					}
				}
				else if (TryPlacement(y+index+1)==-1){
					index=1;
					if (x==7||Board[x+1][y+index]!=" "){
						return y+index;
					}
				}
			}
			else if (_test=="X  X"){
				index=1;
				if (TryPlacement(y+index+1)==-1){
					if (x==7||Board[x+1][y+index]!=" "){
						return y+index;
					}
				}
				else if (TryPlacement(y+index+1)==-1){
					index=3;
					if (x==7||Board[x+1][y+index]!=" "){
						return y+index;
					}
				}
			}
			else if (_test==" XX "){
				index=2;
				if (TryPlacement(y+index+1)==-1){
					if (x==7||Board[x+1][y+index]!=" "){
						return y+index;
					}
				}
				else if (TryPlacement(y+index+1)==-1){
					index=3;
					if (x==7||Board[x+1][y+index]!=" "){
						return y+index;
					}
				}
			}
		}
	}
	// Vertical
	for (int x=0;x<5;x++){ // Try for 3 in a row
		for (int y=0;y<8;y++){
			string _test="";
			for (int i=x;i<x+4;i++){
				_test=_test+Board[i][y];
			}
			if (_test=="  XX"){
				if (TryPlacement(y+1)==-1){
					return y;
				}
			}
		}
	}
	// Diagonal Right
	for (int x=0;x<5;x++){ // Try for 3 in a row
		for (int y=0;y<5;y++){
			string _test="";
			int _index=0;
			for (int i=x;i<x+4;i++){
				_test=_test+Board[i][y+_index];
				_index=_index+1;
			}
			if (_test=="XX  "){
				int index=2;
				if (TryPlacement(y+index+1)==-1){	
					if (x+index==7||Board[x+index+1][y+index]!=" "){
						return y+index;
					}
				}
				index=3;
				if (TryPlacement(y+index+1)==-1){	
					if (x+index==7||Board[x+index+1][y+index]!=" "){
						return y+index;
					}
				}
			}
			else if(_test=="X X "){
				int index=1;
				if (TryPlacement(y+index+1)==-1){	
					if (x+index==7||Board[x+index+1][y+index]!=" "){
						return y+index;
					}
				}
				index=3;
				if (TryPlacement(y+index+1)==-1){	
					if (x+index==7||Board[x+index+1][y+index]!=" "){
						return y+index;
					}
				}
			}
			else if (_test=="  XX"){
				int index=0;
				if (TryPlacement(y+index+1)==-1){	
					if (x+index==7||Board[x+index+1][y+index]!=" "){
						return y+index;
					}
				}
				index=1;
				if (TryPlacement(y+index+1)==-1){	
					if (x+index==7||Board[x+index+1][y+index]!=" "){
						return y+index;
					}
				}
			}
			else if (_test==" X X"){
				int index=0;
				if (TryPlacement(y+index+1)==-1){	
					if (x+index==7||Board[x+index+1][y+index]!=" "){
						return y+index;
					}
				}
				index=2;
				if (TryPlacement(y+index+1)==-1){	
					if (x+index==7||Board[x+index+1][y+index]!=" "){
						return y+index;
					}
				}
			}
			else if (_test==" XX "){
				int index=0;
				if (TryPlacement(y+index+1)==-1){	
					if (x+index==7||Board[x+index+1][y+index]!=" "){
						return y+index;
					}
				}
				index=3;
				if (TryPlacement(y+index+1)==-1){	
					if (x+index==7||Board[x+index+1][y+index]!=" "){
						return y+index;
					}
				}
			}
			else if (_test=="OO  "){
				int index=2;
				if (TryPlacement(y+index+1)==-1){	
					if (x+index==7||Board[x+index+1][y+index]!=" "){
						return y+index;
					}
				}
				index=3;
				if (TryPlacement(y+index+1)==-1){	
					if (x+index==7||Board[x+index+1][y+index]!=" "){
						return y+index;
					}
				}
			}
		}
	}
	// Diagonal Left
	for (int x=7;x>2;x--){ // Try for 3 in a row
		for (int y=0;y<5;y++){
			string _test="";
			int _index=0;
			for (int i=x;i>x-4;i--){
				_test=_test+Board[i][y+_index];
				_index=_index+1;
			}
			if (_test=="XX  "){
				int index=2;
				if (TryPlacement(y+index+1)==-1){	
					if (x+index==7||Board[x-index+1][y+index]!=" "){
						return y+index;
					}
				}
				index=3;
				if (TryPlacement(y+index+1)==-1){	
					if (x+index==7||Board[x-index+1][y+index]!=" "){
						return y+index;
					}
				}
			}
			else if(_test=="X X "){
				int index=1;
				if (TryPlacement(y+index+1)==-1){	
					if (x-index==7||Board[x-index+1][y+index]!=" "){
						return y+index;
					}
				}
				index=3;
				if (TryPlacement(y+index+1)==-1){	
					if (x-index==7||Board[x-index+1][y+index]!=" "){
						return y+index;
					}
				}
			}
			else if(_test=="  XX"){
				int index=0;
				if (TryPlacement(y+index+1)==-1){	
					if (x-index==7||Board[x-index+1][y+index]!=" "){
						return y+index;
					}
				}
				index=1;
				if (TryPlacement(y+index+1)==-1){	
					if (x-index==7||Board[x-index+1][y+index]!=" "){
						return y+index;
					}
				}
			}
			else if(_test==" X X"){
				int index=0;
				if (TryPlacement(y+index+1)==-1){	
					if (x-index==7||Board[x-index+1][y+index]!=" "){
						return y+index;
					}
				}
				index=2;
				if (TryPlacement(y+index+1)==-1){	
					if (x-index==7||Board[x-index+1][y+index]!=" "){
						return y+index;
					}
				}
			}
			else if(_test==" XX "){
				int index=0;
				if (TryPlacement(y+index+1)==-1){	
					if (x-index==7||Board[x-index+1][y+index]!=" "){
						return y+index;
					}
				}
				index=3;
				if (TryPlacement(y+index+1)==-1){	
					if (x-index==7||Board[x-index+1][y+index]!=" "){
						return y+index;
					}
				}
			}
		}
	}
	return -1;
}

int main(){
	Computer4 game;
	int rng=0;
	while (game.CheckWin()==0){
		// Game in progress
		if (game.Turn=="O") {game.Turn="X";}
		else {game.Turn="O";}
		string answer="0";
		while (answer!="1"&&answer!="2"&&answer!="3"&&answer!="4"&&answer!="5"&&answer!="6"&&answer!="7"&&answer!="8"||(game.Place(game.Board,stoi(answer))==0)){
			if (game.Turn=="O"){
				// Player turn
				game.Display();
				if (rng>0){
					cout<<"Computer chose: "<<rng<<endl;
				}
				cout<<"Player O, choose a column (1-8): ";
				cin>>answer;
			}
			else{
				// Computer turn
				int win=game.TryWin();
				int block=game.TryBlock(game.Board);
				int strategy=game.TryStrategy();
				if (win!=-1){
					// Computer can win
					rng=win+1;
					answer=to_string(win+1);
				}
				else if(block!=-1){
					// Player is about to win
					rng=block+1;
					answer=to_string(block+1);
				}
				else if(strategy!=-1){
					cout<<"strategic placement"<<endl;
					rng=strategy+1;
					answer=to_string(strategy+1);
				}
				else{
					// Random placement
					rng=rand()%8+1;
					while (game.TryPlacement(rng)!=-1){
						rng=rand()%8+1;
					}
					answer=to_string(rng);
				}
			}
		}
	}
	// Player won
	game.Display();
	if (game.CheckWin()==3){cout<<"The game was a tie!"<<endl;}
	else if(game.Turn=="O"){cout<<"Player won!"<<endl;}
	else{cout<<"Computer chose: "<<rng<<"\nComputer won!"<<endl;}
	return 0;
}