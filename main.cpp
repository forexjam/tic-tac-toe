#include <iostream>

	std::string triki[3][3] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};

void trikiplay(int a, int b, std::string piece) {

	triki[a][b] = piece;		
}

void print_matrix() {

	int i = 0;
	int z = 0;
	while (i < 3) {
		while (z < 3) {
			std::cout << triki[i][z];
			z++;
		}		
		i++; 
		z = 0;
		std::cout << "\n";
	}
}

void print_matrix_lines() {

	int i = 0;
	int z = 0;
	while (i < 3) {
		while (z < 3) {			
			if(z== 1 && i != 2 ||z == 2 && i != 2){
				std::cout << "_|_";
			}
			else if(i == 2 && z > 0) { std::cout << " | "; }
			std::cout << triki[i][z];
			z++;
		}
		i++;
		z = 0;
		std::cout << "\n";
	}
}

bool horizontal(){
	int i = 0;
	int z = 1;
	std::string acum = " ";
	int ymir = 0;
	while (i < 3) {
		while (z < 3) {
			if (triki[i][z] == "X" || triki[i][z] == "O") {
				acum = triki[i][0];
				if (acum == triki[i][z]) {
					ymir++;
				}
				else {
					break;
				}
			}
			z++;
		}
		if (ymir == 2) {
			return true;
		}
		ymir = 0;
		i++;
		z = 1;
	}
	return false;
}

bool vertical() { 

	int i = 1;
	int z = 0;
	int ymir = 0;
	std::string acum = " ";
	while (z < 3) {
		while (i < 3) {
			if (triki[i][z] == "X" || triki[i][z] == "O") {
				acum = triki[0][z];
				if (acum == triki[i][z]) {
					ymir++;
				}
				else {
					break;
				}
			}
			i++;
		}
		if (ymir == 2) {
			return true;
		}
		ymir = 0;
		z++;
		i = 1;
	}
	return false;
}

bool diagonal1() {
	int z = 2;
	int i = 0;
	int ymir = 0;
	std::string acum = " ";
	while (i < 3) {
		while (z < 3) {
			if (triki[i][z] == "X" || triki[i][z] == "O") {
				acum = triki[0][2];
				if (acum == triki[i][z]) {
					ymir++;
				}
				else {
					return false;
				}
			}
			i++;
			z--;
			break;
		}
		if (ymir == 3) {
			return true;
		}
	}
	return false;
}

bool diagonal2(){

	int i = 1;
	int ymir = 0;
	std::string acum = " ";
	while (i < 3) {			
			if (triki[i][i] == "X" || triki[i][i] == "O") {	
				acum = triki[0][0];
				if (acum == triki[i][i]) {
					ymir++;
				}		
				else return false;
			}
			else { break; }

		if (ymir == 2) {
			return true;
		}	
			i++;
	}
	return false;
}

bool endgame() {

	if (horizontal() || vertical() || diagonal1() || diagonal2()) {
		return true;	}
	
	return false;
}

void main() {

	int coordenada_x = 0;
	int coordenada_y = 0;
	std::string p = "X";
	std::string player1 = "X";
	std::string player2 = "O";
	bool v = true;
	std::string t = triki[coordenada_x][coordenada_y];
	std::cout << "Player 1 GO!\n";
	while (v) {
		std::cout << "\nPlease enter coordinate x: ";
		std::cin >> coordenada_x;
		std::cout << "\nPlease enter coordinate y: ";
		std::cin >> coordenada_y;
		if (coordenada_x <= 2 && coordenada_x >= 0 && coordenada_y <= 2 && coordenada_y >= 0) { 			
			t = triki[coordenada_x][coordenada_y];
			if (t == " ") {
				system("CLS");
				if (p == player1) {					
					std::cout << "Player 2 GO!\n";
					trikiplay(coordenada_x, coordenada_y, p);					
					p = "O";
				}
				else {
					trikiplay(coordenada_x, coordenada_y, player2);
					std::cout << "Player 1 GO!\n";
					p = "X";
				}
			}
			else {
				system("CLS");
				std::cout << "That's not a valid position, please try agan. \n \n";
			}
		}		
		else {
			system("CLS");
			std::cout << "That's out of range, please try again. \n";;
		}
		print_matrix_lines();		
		if (endgame()) {  
			system("CLS");
			if (p == "X") {				
				std::cout << "Player 2 wins \n";
			}
			else {
				std::cout << "Player 1 wins \n";
			}			
			print_matrix_lines();
			std::cout << "Supreme Victory!";			
			break;
		}
	}	
}
