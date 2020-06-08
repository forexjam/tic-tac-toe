// 
//------------------------------------------------- MAY 7th DATA BASE -----------------------------------------------------------
//
//#include <iostream>
//#include <string>
//#include <fstream>
//
//using namespace std;
//
//struct person {
//
//	string name;
//	string last_name;
//	int day;
//	int month;
//	int year;
//	int ssn;
//	double balance;
//};
//
//person arr[100];
//
//
//void database() {
//
//	ifstream data("database.txt");
//
//	int i = 0;
//
//	while (i < 25) {
//
//		if (data.fail()) break;
//		
//
//		data >> arr[i].ssn >> arr[i].day >> arr[i].month >> arr[i].year >> arr[i].name >>
//			arr[i].last_name >> arr[i].balance;
//
//		
//
//		i++;
//	}
//
//	data.close();
//}
//
//void vector_print() {
//
//	int i = 0;
//
//	while (i < 25) {
//
//		std::cout << arr[i].ssn << " " << arr[i].day << " " << arr[i].month << " " << arr[i].year << " " << arr[i].name << " " <<
//			arr[i].last_name << " " << arr[i].balance << endl;
//
//		i++;
//	}
//}
//void basic_search() {
//
//	int i = 0;
//	string x = " ";
//
//	
//	cin >> x;
//	bool c = true;
//
//	while (i < 25) {
//
//		if (arr[i].name == x) {
//
//			std::cout << arr[i].ssn << " " << arr[i].day << " " << arr[i].month << " " << arr[i].year << " " << arr[i].name << " " <<
//				arr[i].last_name << " " << arr[i].balance << endl;
//			
//			c = false;
//		}
//
//		i++;
//	}
//	if (c == true) { 
//		
//		std::cout << "That name does not exist in the list, please try again: " << endl; 
//		basic_search();
//	
//	}	
//}
//
//int length_of_month (int year, int month) {
//	if(month == 2){	
//		if(year % 4 != 0){
//			return 28;
//		}else if(year % 100 != 0){
//			return 29;
//		}else if(year % 400 != 0){
//			return 28;
//		}else{
//			return 29;
//		}
//	}
//	if(month == 4){ return 30; }
//	else if (month == 6){ return 30; }
//	else if (month == 9){ return 30; }
//	else if (month == 11){ return 30; }	
//	if (month == 1 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)  return 31; 
//}
//
//int day_of_year(int year, int month, int day) {
//	if (month > 1) { 
//		int d1 = length_of_month( year, month-1 ); 
//		int d2 = day_of_year( year, month-1, day );	
//		return d1 + d2;  
//	}
//	if (month == 1){ 
//		return day; 
//	}
//return 0;
//}
//
//int day_of_forever(int year, int month, int day) {
//	if (year > 0) {
//		int doy = day_of_year(year - 1, 12, 31);
//		int dof = day_of_forever(year - 1, month, day);
//		return doy + dof;
//	}
//	else {
//		return day_of_year(year - 1, month, day);
//	}
//}
//	void find_the_oldest() {
//	
//		int x = 0;
//		int c = 0;
//		int y = 0;
//		int z = 0;
//		int m = 0;
//		
//		while (x < 24) {
//			
//			y = day_of_forever(arr[x].year, arr[x].month, arr[x].day);
//			z = day_of_forever(arr[x + 1].year, arr[x + 1].month, arr[x + 1].day);
//			
//			if (y < z) {
//				if (y < m) {
//					c = x;
//				}
//			}
//			else  {
//				if (z < m) { c = x + 1; }
//			}
//			m = day_of_forever(arr[c].year, arr[c].month, arr[c].day);
//			x++;
//
//		}
//		std::cout << arr[c].ssn << " " << arr[c].day << " " << arr[c].month << " " << arr[c].year << " " << arr[c].name << " " <<
//			arr[c].last_name << " " << arr[c].balance << endl;
//			
//	}	
//
//void Oldest_Person(){
//
//	int x = 1;
//	int m = 0;
//	while(m < 24){		
//
//		if(day_of_forever(arr[m].year, arr[m].month, arr[m].day) < 
//			day_of_forever(arr[x].year, arr[x].month, arr[x].day)){
//				
//			x = m;
//		}
//
//		m++;
//	}
//
//	std::cout << arr[x].ssn << " " << arr[x].day << " " << arr[x].month << " " << arr[x].year <<
//			" " << arr[x].name << " " << arr[x].last_name << " " << arr[x].balance << endl; 
//}
//
//void promote_the_youngest(){
//
//	int x = 1;
//	int m = 0;
//
//	while (m < 24) {
//
//		int y = day_of_forever(arr[m].year, arr[m].month, arr[m].day);
//		int z = day_of_forever(arr[x].year, arr[x].month, arr[x].day);
//
//		if ( y > z) {
//
//			x = m;
//		}
//
//		m++;
//	}
//
//	person aux[1];
//		aux[0].ssn = arr[x].ssn;
//		aux[0].day = arr[x].day;
//		aux[0].month = arr[x].month;
//		aux[0].year = arr[x].year;
//		aux[0].name = arr[x].name;
//		aux[0].last_name = arr[x].last_name;
//		aux[0].balance = arr[x].balance;
//
//		arr[x].ssn = arr[0].ssn;
//		arr[x].day = arr[0].day;
//		arr[x].month = arr[0].month;
//		arr[x].year = arr[0].year;
//		arr[x].name = arr[0].name;
//		arr[x].last_name = arr[0].last_name;
//		arr[x].balance = arr[0].balance;
//
//		arr[0].ssn = aux[0].ssn;
//		arr[0].day = aux[0].day;
//		arr[0].month = aux[0].month;
//		arr[0].year = aux[0].year;
//		arr[0].name = aux[0].name;
//		arr[0].last_name = aux[0].last_name;
//		arr[0].balance = aux[0].balance;
//	
//		
//}
//
//void promote_the_2ndyoungest() {
//
//	int x = 2;
//	int m = 1;
//
//	while (m < 24) {
//
//		int y = day_of_forever(arr[m].year, arr[m].month, arr[m].day);
//		int z = day_of_forever(arr[x].year, arr[x].month, arr[x].day);
//		
//		if (y > z) {
//
//			x = m;
//		}
//
//		m++;
//	}
//
//	person aux[1];
//		aux[0].ssn = arr[x].ssn;
//		aux[0].day = arr[x].day;
//		aux[0].month = arr[x].month;
//		aux[0].year = arr[x].year;
//		aux[0].name = arr[x].name;
//		aux[0].last_name = arr[x].last_name;
//		aux[0].balance = arr[x].balance;
//
//		arr[x].ssn = arr[1].ssn;
//		arr[x].day = arr[1].day;
//		arr[x].month = arr[1].month;
//		arr[x].year = arr[1].year;
//		arr[x].name = arr[1].name;
//		arr[x].last_name = arr[1].last_name;
//		arr[x].balance = arr[1].balance;
//
//		arr[1].ssn = aux[0].ssn;
//		arr[1].day = aux[0].day;
//		arr[1].month = aux[0].month;
//		arr[1].year = aux[0].year;
//		arr[1].name = aux[0].name;
//		arr[1].last_name = aux[0].last_name;
//		arr[1].balance = aux[0].balance;
//	
//}
//
//
//void vector_print1(int a) {
//
//	std::cout << arr[a].ssn << " " << arr[a].day << " " << arr[a].month << " " << arr[a].year << " " << arr[a].name << " " <<
//		arr[a].last_name << " " << arr[a].balance << endl;
//
//}
//
//void more_of_the_same(int m, int c) {
//	
//	int x = m + 1;
//	int a = m;
//	while (a < c) {
//	
//		while (m <= c) {
//
//			int y = day_of_forever(arr[m].year, arr[m].month, arr[m].day);
//			int z = day_of_forever(arr[x].year, arr[x].month, arr[x].day);
//
//			if (y > z) {
//
//				x = m;
//			}
//			m++;
//		}
//		person aux[1];
//		aux[0].ssn = arr[x].ssn;
//		aux[0].day = arr[x].day;
//		aux[0].month = arr[x].month;
//		aux[0].year = arr[x].year;
//		aux[0].name = arr[x].name;
//		aux[0].last_name = arr[x].last_name;
//		aux[0].balance = arr[x].balance;
//
//		arr[x].ssn = arr[a].ssn;
//		arr[x].day = arr[a].day;
//		arr[x].month = arr[a].month;
//		arr[x].year = arr[a].year;
//		arr[x].name = arr[a].name;
//		arr[x].last_name = arr[a].last_name;
//		arr[x].balance = arr[a].balance;
//
//		arr[a].ssn = aux[0].ssn;
//		arr[a].day = aux[0].day;
//		arr[a].month = aux[0].month;
//		arr[a].year = aux[0].year;
//		arr[a].name = aux[0].name;
//		arr[a].last_name = aux[0].last_name;
//		arr[a].balance = aux[0].balance;
//
//		vector_print1(a);
//
//		a++;
//		m = a;
//		x = m + 1;
//	}
//}
//
//
//
//int main() {
//
//	database();
//	//vector_print();
//	//std::cout << "Please enter the name of the client: " << endl;
//	//basic_search();
//	//find_the_oldest();
//	//Oldest_Person(); // better than find_the_oldest
//	//promote_the_youngest();
//	//promote_the_2ndyoungest();
//	//vector_print();
//	more_of_the_same(0, 10);
//	
//}
//
//
//
//------------------------------------------ MAY 7th ------------------------------------------------------


#include <iostream>
//#include <string>


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
	int u = 0;
	int q = 0;
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
		u = 0;
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
		return true;
	}
	
	return false;
}
void main() {

	//trikiplay(1, 1, "X");
	//print_matrix();
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
		if (coordenada_x <= 2 && coordenada_x >= 0 || coordenada_y <= 2 && coordenada_y >= 0) { 
			
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
		//print_matrix();
		
		if (endgame()) {  //no need to put if(endgame() == true) because it is redundant es como decir si si es true
			system("CLS");
			if (p == "X") {				
				std::cout << "Player 2 wins \n";
			}
			else {
				std::cout << "Player 1 wins \n";
			}
			//print_matrix();
			print_matrix_lines();
			std::cout << "Supreme Victory!";
			
			break;
		}
	}
	
}























