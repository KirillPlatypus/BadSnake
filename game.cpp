#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;
struct Ptr {
	const int sizeTimer=200;
	int score = 0, timer = 200;
	char snake = 'O',
		 coin = '*';	
	bool CoinSpaun = false;					//y
	char field[10][15] = { {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
						   {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
						   {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
						   {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
						   {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
						   {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
				/*x*/      {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
						   {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
						   {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
						   {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
						 };
};
struct Vector {
	int x = 7 ;// �����/������
	int y = 5;// ����/�����

	// �����))))))
	int CoinX = 0;
	int CoinY = 0;
};
///////////////////////////
Vector go;				 //
Ptr Player;				 //
bool ExitMoment = false;///
///////////////////////////

						//�����
void up(Ptr &_Player, Vector& _go) {
		_Player.field[_go.y -= 1][_go.x] = _Player.snake;
		_Player.field[_go.y + 1][_go.x] = ' ';
}
						//����
void down(Ptr &_Player, Vector& _go) {
	_Player.field[_go.y+=1][_go.x] = _Player.snake;
	_Player.field[_go.y - 1][_go.x] = ' ';
}
						//�����
void left(Ptr& _Player, Vector&_go) {
	_Player.field[_go.y][_go.x-=1] = _Player.snake;
	_Player.field[_go.y][_go.x+1] = ' ';
}
						//������
void right(Ptr& _Player, Vector&_go) {
	_Player.field[_go.y][_go.x+=1] = _Player.snake;
	_Player.field[_go.y][_go.x - 1] = ' ';
}
	
	

					//������������ ����
void Display(Ptr DisplayField) {

	for (int i = 0; i < 10; i++)
	{
		for (int y = 0; y < 15; y++)cout << DisplayField.field[i][y];
		cout << endl;
	}
}


void Input(Ptr &_Player, Vector& _go) {

	if (_kbhit())
	{
		switch (_getch()) {
		case 'w': up(_Player, _go);  break;
		case 's': down(_Player, _go); break;
		case 'a': left(_Player, _go); break;
		case 'd': right(_Player, _go); break;
		case 'e': ExitMoment = true; break;
		}
	}
}

void Logic() 
{
	cout << "  Score = " << Player.score<<endl;
	cout << "Time = " << Player.timer--<<endl;

	Input(Player, go); //������� ����������� �������� ������������ ����
	Display(Player); //������� ���� 
	
	//���� ���� � ������� ����, �� ��� ��������������� 
				  //�� ��� ��������������� �������

						// ���� ������
	if (go.y == 0) 
	{
		Player.field[go.y][go.x] = '#';
		go.y = 8; //���������� �� ������ ����� ���� �� y
		Player.field[go.y][go.x] = Player.snake;
	}
						//���� �����
	else if (go.y == 9) 
	{
		Player.field[go.y][go.x] = '#';
		go.y = 1;//���������� �� ������ ����� ���� �� y
		Player.field[go.y][go.x] = Player.snake;
	}
						//���� �����
	else if(go.x == 0)
	{
		Player.field[go.y][go.x] = '#';
		go.x = 13;//���������� �� ������ ����� ���� �� x
		Player.field[go.y][go.x] = Player.snake;
	}
						//���� ������
	else if (go.x == 14)
	{
		Player.field[go.y][go.x] = '#';
		go.x = 1;//���������� �� ������ ����� ���� �� x
		Player.field[go.y][go.x] = Player.snake;
	}
	////////////////////////////////////////////
	/*cout << "x " << go.x << endl
		 << "y " << go.y << endl;*/

	/////////////////////////////////////////////

	///////////////////Coins//////////////////////

	if (!Player.CoinSpaun) {//���� ������� �������� �� ������������� ������
		go.CoinX = 1 + rand() % 13; //������ ������ ������� �� x
		go.CoinY = 1 + rand() % 8;  //������ ������ ������� �� y 
	}
	if (go.CoinX != go.x && go.CoinY != go.y && !Player.CoinSpaun) // ���� ������ ���� �� ����� ������� �����
	//(��� ������� �����, ����� ������� �� ��������� ������� ������ � ���� ����� �� ������ ��� ������)
	{
		Player.field[go.CoinY][go.CoinX] = Player.coin;//����� ������
		Player.CoinSpaun = true;
	}  // �� ������� �� ���������� 

	else if (go.CoinX == go.x && go.CoinY == go.y ) {
		Player.CoinSpaun = !Player.CoinSpaun;
		Player.score++;
	}
	
	///////////////////////////////////////////////

	system("cls"); // ������� ����
}


int main()
{
	int Var;
	//Menu
	while (true)
	{
		cout << endl<<"        " << "Snake" << endl
			<< "1 - Play" << endl
			<< "2 - Author" << endl
			<< "3 - Exit" << endl 
			<< "if you wait exit for plaing, pressed 'e'"<<endl
			<< "Print your variant - ";
		cin >> Var;
		if (Var == 1) {

			Player.field[go.y][go.x] = Player.snake;

			while (!ExitMoment)
			{
				Logic();
				if (Player.timer <= 0) {
					bool Continue;
					system("cls"); // ������� ����
					cout << endl << "Time the end! " << endl
						 << "Your score - "<< Player.score<<endl
						 << "You wait again(1 - yes, 0 - no)? "<< endl;

					cin >> Continue;
					
					if (Continue == 1) {
						Player.timer = Player.sizeTimer;
						Player.field[go.y][go.x] = ' ';
						go.y = 5; go.x = 7;
						Player.score = 0;
					}
					else {  return 0; }
				}
			}
			
			cout << endl << "you pressed 'e', you exit from game." << endl;
			return 0;
		}
		else if (Var == 2) { cout << endl<< "texnar_man" << endl; }
		else if (Var == 3) {
			return 0;
		}
		else {
			cout << "unknown operation! " << endl;
		}
	}
}
