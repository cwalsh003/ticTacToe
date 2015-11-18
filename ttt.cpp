#include <iostream>
#include <vector>


using namespace std;

void getBoard (vector< vector<char> >);
vector< vector<char> > userMove(vector< vector<char> >);
vector< vector<char> > computerMove(vector< vector<char> >);
bool checkWinner(vector< vector<char> >);
void findWinner(vector< vector<char> >);
bool isValid(vector< vector<char> >, int, int);

int main(int argc, char *argv[]) {
	
	bool win = false;
	vector< vector<char> > board(3, vector<char>(3));

while(!win){

	board = userMove(board);
	win = checkWinner(board);
if(!win){
	board = computerMove(board);
}
	win = checkWinner(board);
	}
	
	findWinner(board);
	
	int stop;
	cout << "\n\n\nEnter any key to stop.....";
	cin >> stop;
	return 0;
}


void findWinner(vector< vector<char> > board){
	char win;
		if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
			win = 'X';
		else if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
			win = 'O';
	  	else if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
			win = 'X';
		else if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
			win = 'O';
		else if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
			win = 'X';
		else if(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
			win = 'O';
		else if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
			win = 'X';
		else if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
			win = 'O';
		else if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
			win = 'X';
		else if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
			win = 'O';
		else if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
			win = 'X';
		else if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
			win = 'O';
		else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
			win = 'X';
		else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
			win = 'O';
		else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
			win = 'X';
		else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
			win = 'O';
		
if (win == 'X'){
	cout << "You Win: "  << endl;
}
else if (win == 'O'){
	cout << "The Computer won: "  << endl;
}
else{
	cout << "This game was a draw: " << endl;
}
}
bool checkWinner(vector< vector<char> > board){
	bool win = false;
	int ctr =0;
		if ((board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')||(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O'))
			win = true;
		else if ((board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')||(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O'))
			win = true;
		else if ((board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')||(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O'))
			win = true;
		else if ((board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')||(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O'))
			win = true;
		else if ((board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')||(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O'))
			win = true;
		else if ((board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')||(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O'))
			win = true;
		else if ((board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')||(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
			win = true;
		else if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')||(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'))
			win = true;

		else{
			for (int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					if (board[i][j] == 'X' || board[i][j] == 'O'){
						ctr++;
					}
				}
			}
		}
			if (ctr >= 9){
				win = true;
			}
		
	return win;
	
}
vector< vector<char> > userMove(vector< vector<char> > board){
	int row, column;
	bool flag = true;
do{	
	cout << "Enter a row and a column (between 0 and 2): ";
	cin >> row >> column;
	}while((row < 0 || row > 2) || (column < 0 || column > 2));	
	
	while(flag){
		
		if(board[row][column] == 'X' || board[row][column] == 'O'){
			cout << "Enter a row and a column (between 0 and 2): ";
			cin >> row >> column;
		}else{
			board[row][column] = 'X';
			flag = false;
		}
	}
	cout << endl<< endl<< "The board after your move is: \n\n";
	getBoard(board);
	
	return board;

}
vector< vector<char> > computerMove(vector< vector<char> > board){
	int row, column ;
	bool flag = true;

	

	//win
	if(((board[0][0] == 'O' && board[0][1] == 'O')||(board[2][2] == 'O' && board[1][2] == 'O')||(board[2][0] == 'O' && board[1][1] == 'O')) && isValid(board, 0, 2))
		board[0][2] = 'O';
	else if(((board[0][0] == 'O' && board[1][0] == 'O')||(board[0][2] == 'O' && board[1][1] == 'O')||(board[2][2] == 'O' && board[2][1] == 'O')) && isValid(board, 2, 0))
		board[2][0] = 'O';
	else if(((board[0][1] == 'O' && board[1][1] == 'O')||(board[2][0] == 'O' && board[2][2] == 'O')) && isValid(board, 2, 1))
		board[2][1] = 'O';
	else if(((board[0][0] == 'O' && board[2][2] == 'O')||(board[0][2] == 'O' && board[2][0] == 'O')||(board[0][1] == 'O' && board[2][1] == 'O')||(board[2][0] == 'O' && board[0][2] == 'O')||(board[1][0] == 'O' && board[1][2] == 'O'))&& isValid(board, 1, 1))
		board[1][1] = 'O';
	else if(((board[0][0] == 'O' && board[2][0] == 'O')||(board[1][2] == 'O' && board[1][1] == 'O'))&&isValid(board, 1, 0))
		board[1][0] = 'O';
	else if(((board[0][0] == 'O' && board[1][1] == 'O')||(board[2][0] == 'O' && board[2][1] == 'O')||(board[0][2] == 'O' && board[1][2] == 'O'))&&isValid(board, 2, 2))
		board[2][2] = 'O';
	else if(((board[0][0] == 'O' && board[0][2] == 'O')||(board[2][1] == 'O' && board[1][1] == 'O'))&&isValid(board, 0, 1))
		board[0][1] = 'O';
	else if(((board[2][2] == 'O' && board[0][2] == 'O')||(board[1][0] == 'O' && board[2][2] == 'O')||(board[1][0] == 'O' && board[1][1] == 'O')) && isValid(board, 1, 2))
		board[1][2] = 'O';

//block win
	else if(((board[0][0] == 'X' && board[0][1] == 'X') || (board[2][2] == 'X' && board[1][2] == 'X')||(board[2][0] == 'X' && board[1][1] == 'X')) && isValid(board, 0, 2))
		board[0][2] = 'O';
	else if(((board[0][0] == 'X' && board[1][0] == 'X')||(board[0][2] == 'X' && board[1][1] == 'X')||(board[2][2] == 'X' && board[2][1] == 'X')) && isValid(board, 2, 0))
		board[2][0] = 'O';
	else if(((board[0][1] == 'X' && board[1][1] == 'X')||(board[2][0] == 'X' && board[2][2] == 'X')) && isValid(board, 2, 1))
		board[2][1] = 'O';
	else if(((board[0][0] == 'X' && board[2][2] == 'X')||(board[0][2] == 'X' && board[2][0] == 'X')||(board[0][1] == 'X' && board[2][1] == 'X')||(board[2][0] == 'X' && board[0][2] == 'X')||(board[1][0] == 'X' && board[1][2] == 'X'))&& isValid(board, 1, 1))
		board[1][1] = 'O';
	else if(((board[0][0] == 'X' && board[2][0] == 'X')||(board[1][2] == 'X' && board[1][1] == 'X')) && isValid(board, 1, 0))
		board[1][0] = 'O';
	else if(((board[0][0] == 'X' && board[1][1] == 'X')||(board[2][0] == 'X' && board[2][1] == 'X')||(board[0][2] == 'X' && board[1][2] == 'X'))&&isValid(board, 2, 2))
		board[2][2] = 'O';
	else if(((board[0][0] == 'X' && board[0][2] == 'X')||(board[2][1] == 'X' && board[1][1] == 'X'))&&isValid(board, 0, 1))
		board[0][1] = 'O';
	else if(((board[2][2] == 'X' && board[0][2] == 'X')||(board[1][0] == 'X' && board[2][2] == 'X')||(board[1][0] == 'X' && board[1][1] == 'X'))&&isValid(board, 1, 2))
		board[1][2] = 'O';

//create fork
	else if(board[0][0] == 'O' && isValid(board, 2, 2))
		board[2][2] = 'O';
	else if(board[0][0] == 'O'  && isValid(board, 0, 2))
		board[0][2] = 'O';
	else if(board[0][0] == 'O' && isValid(board, 2, 0))
		board[2][0] = 'O';
	else if(board[2][0] == 'O' && isValid(board, 2, 2))
		board[2][2] = 'O';
	else if(board[2][0] == 'O' && isValid(board, 0, 2))
		board[0][2] = 'O';
	else if(board[2][0] == 'O' && isValid(board, 0, 0))
		board[0][0] = 'O';
	else if(board[2][2] == 'O' && isValid(board, 0, 0))
		board[0][0] = 'O';
	else if(board[2][2] == 'O' && isValid(board, 0, 2))
		board[0][2] = 'O';
	else if(board[2][2] == 'O' && isValid(board, 2, 0))
		board[2][0] = 'O';
	else if(board[0][2] == 'O' && isValid(board, 2, 2))
		board[2][2] = 'O';
	else if(board[0][2] == 'O' && isValid(board, 2, 0))
		board[2][0] = 'O';
	else if(board[0][2] == 'O' && isValid(board, 0, 0))
		board[0][0] = 'O';
	else if(board[1][0] == 'O' && isValid(board, 1, 2))
		board[1][2] = 'O';
	else if(board[2][1] == 'O' && isValid(board, 0, 1))
		board[0][1] = 'O';
		
	//center
else if(isValid(board, 1, 1))
		board[1][1] = 'O';

	//opposite corner
	else if(board[0][0] == 'X' && isValid(board, 2, 2))
		board[2][2] = 'O';
	else if(board[2][0] == 'X' && isValid(board, 0, 2))
		board[0][2] = 'O';
	else if(board[2][2] == 'X' && isValid(board, 0, 0))
		board[0][0] = 'O';
	else if(board[0][2] == 'X' && isValid(board, 2, 0))
		board[2][0] = 'O';

//empty corner
	else if(isValid(board, 0, 0))
		board[0][0] = 'O';
	else if(isValid(board, 2, 0))
		board[2][0] = 'O';
	else if(isValid(board, 2, 2))
		board[2][2] = 'O';
	else if(isValid(board, 0, 2))
		board[0][2] = 'O';

	//empty side
	else if(isValid(board, 0, 1))
		board[0][1] = 'O';
	else if(isValid(board, 1, 2))
		board[1][2] = 'O';
	else if(isValid(board, 1, 0))
		board[1][0] = 'O';
	else if(isValid(board, 2, 1))
		board[2][1] = 'O';
	
	cout << "\nThe board after the computer's move is: \n" << endl;
	getBoard(board);
	
	return board;

}
void getBoard(vector< vector<char> >board ){
	
for (int i = 0; i < 3; i++){
	for(int j = 0; j < 3; j++){
		if (board[i][j] == 'X' || board[i][j] == 'O'){
			cout << board[i][j];
		}else {
			cout << ' ';
		}
		if ( j < 2){
				cout << " | ";
			}
	}
		if ( i < 2){
			cout<< endl <<"---------"<<endl;
		}
}
cout << endl << endl;
}

bool isValid(vector< vector<char> > board, int row, int column){
	if (board[row][column] != 'X' && board[row][column] != 'O'){
		return true;
	}
	else{
		return false;
	}
}
