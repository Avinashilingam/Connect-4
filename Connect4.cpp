#include<bits/stdc++.h>
using namespace std;


class Player
{
  public:
  string name;
  char piece;
};

bool checkLine(vector<char>);
void printBoard(vector<vector<char>> &board);
void StartGame();
string makePlayer();
void gamePlay(Player &p1, Player &p2);
bool gameOver(vector<vector<char>> &board,int);

int main()
{
	StartGame();
}

void StartGame()
{
	Player p1;
	Player p2;

	p1.name = makePlayer();
	p1.piece = 'R';

	p2.name = makePlayer();
	p2.piece = 'B';

	gamePlay(p1 , p2);
}

void gamePlay(Player &p1, Player &p2)
{
	int n = 7;
	int m = 6;
	vector<vector<char>>board(n, vector<char> (m,' '));
	int pos = 0;
	int turn = 0;
		while(!gameOver(board,pos))
	{
       printBoard(board);
	   cout << "Which Row? (1-7 ";
	   cin >> pos;
	   -- pos;
	   bool placed = false;

	   for(int i=0; i<6;++i){
		   if((i==6 || board[pos][i+1]!= ' 1')&&!placed){
			   if(turn % 2 == 0 ){
				   board[pos][i] = p1.piece;
			   }
			   else{
				   board[pos][i] =p2.piece;
			   }
			   placed = true;
		   }
	   }
       ++ turn; 

	      
	}

	printBoard(board);

	if(turn % 2 == 1){
		cout << p1.name <<"Wins \n";
	}
	else{
		cout << p2.name <<"Wins \n";
	}
}

void printBoard(vector<vector<char>> &board)
{
	string line = "";
	for(int i=0; i<6; ++i){
		printf("%c %c %c %c %c %c %c \n", board[0][i],board[1][i],board[2][i],board[3][i],board[4][i],board[5][i],board[6][i]);
	}

	printf("1 2 3 4 5 6 7 \n\n\n");
}

bool gameOver(vector<vector<char>> &board,int pos){
	vector<char> vertical;
	vector<char> horizontal;
	vector<char> DR;
	vector<char> UR;

	int row = 10;
	bool rowfound = false;
	bool full = true;
	for(int i=0; i<7; ++i){
		for(int j=0; j<6; ++j){
			if(board[i][j] ==' '){
                full = false;
			}
		}
	}

	for(int i=0; i<6; ++i){
		vertical.push_back(board[pos][i]);
		if(!rowfound && board[pos][i] != ' '){
			row = i;
			rowfound = true;
		}
	}

	int DRstart = row - pos;
	int URstart = row + pos;
	for(int i=0 ; i<7 ; ++i){
		horizontal.push_back(board[pos][i]);
		if(DRstart + i >= 0){
			DR.push_back(board[i][DRstart+i]);
		}
		if(URstart - i <= 5){
			UR.push_back(board[i][URstart-i]);
		}

	}
	return (checkLine(vertical) || checkLine(horizontal) || checkLine(DR) || checkLine(UR) || full);
}

bool checkLine(vector <char> line)
{
	if(line.size() < 4){
		return false;
	}

	for(int i=0; i<int(line.size())-3; ++i){
		if(line[i]!=' ' && line[i]==line[i+1] && line[i]==line[i+2] && line[i]==line[i+3]){
			return true;
		}
	}
	return false;
}

string makePlayer()
{
	string name;
	cout << "Enter Player Name : ";
	cin >> name;
	return name;


}