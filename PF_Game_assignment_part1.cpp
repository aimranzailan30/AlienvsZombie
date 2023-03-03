#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <limits>
#include <thread>
#include <windows.h>

using namespace std;

int main() {

	system("cls");

    int def_rows, def_cols, rows, cols, def_zombiec, zombiec;

    bool game_status = true;
    char usr_in;
    char array[7] = {'p', 'r', '^', 'V','>','<',' '};
    char change_setting;
    const char* alien_action;

   int a_cols;
   int a_rows;

   int a_cols_prev;
   int a_rows_prev;

   int a_cols_prev_random;
   int a_rows_prev_random;

   def_rows = 5;
   def_cols = 7;
   def_zombiec = 1;

   cout << "================================" << endl
       	<< "*                              *" << endl
       	<< "*     !! ALIEN VS ZOMBIE !!    *" << endl
       	<< "*          !! GAME !!          *" << endl
       	<< "*                              *" << endl
       	<< "================================" << endl;

   cout << "*     Default Game Setting     *" << endl
		<< "================================" << endl << endl;

   cout << "~ Board Rows : " << def_rows << endl
   << "~ Board Columns : " << def_rows << endl
   << "~ Zombie Count : " << def_zombiec << endl << endl ;

   cout << "Do you wish to change the setting? (y/n) : ";
   cin >> change_setting;

   cout << endl;

   if(change_setting == 'y'){

	   system("cls");

	   rows = def_rows;
	   cols = def_cols;

	   cout << "================" << endl
			<< "  GAME SETTING" << endl
			<< "================" << endl << endl;

	   cout << "Enter the new number of Rows : ";
	   cin >> rows;

	   cout << "Enter the new number of Columns : ";
	   cin >> cols;

	   cout << "Enter the new number of Zombies : ";
	   cin >> zombiec;

	   system("cls");
   }
   if(change_setting == 'n'){

	   rows = def_rows;
	   cols = def_cols;

	   system("cls");
   }

    char grid[rows][cols]; // 3x3

    // fill in grid with blank space
    for (int i = 0; i < rows; i++){
        for(int j = 0; j< cols; j++){
            int RanIndex = rand()%7;
            grid[i][j] = array[RanIndex];
        }
     }

    // print the grid
    //for (int i = 0; i < rows; i++){
    	//cout << '|';

        //for(int j = 0; j< cols; j++){

            //cout << grid[i][j] << "|";
        //};
        //cout << endl;

    //}
    //cout << endl;

    // alien pos
    a_rows = rows/2; //5
    a_cols = cols/2; //5

    grid[a_rows][a_cols] = 'A';

    while(game_status){

    	 cout << "================================" << endl
    	      << "*                              *" << endl
    	      << "*     !! ALIEN VS ZOMBIE !!    *" << endl
    		  << "*          !! GAME !!          *" << endl
    		  << "*                              *" << endl
    		  << "================================" << endl << endl;

        for (int f = 0; f < cols; f++) {
                    	cout << "--";
                    	}
                    cout << endl;

        for (int i = 0; i < rows; i++){
        	cout << '|';
            for(int j = 0; j< cols; j++){

                cout << grid[i][j] << "|";
            }
            cout << endl;
            for (int f = 0; f < cols; f++) {
            	cout << "--";
                                                }
            cout << endl;
        }

    	cout << endl << "Turn : Alien" << endl << endl;

    	cout << "                  Game Stats" <<endl
			 << "================================================" <<endl
    		 << "*  Alien     ||  Health : 100% | Attack : 0 || *"	<<endl
			 << "================================================" <<endl;

    	for(int zstat=1; zstat<=zombiec; zstat++){
    		cout << "* Zombie    " << zstat << "||  Health : 100% | Attack : 0 || *"<<endl
    			 << "================================================" <<endl;
    	}

    	cout << endl << "Enter a command (h = help) : ";

    	cin >> usr_in;

        system("cls");

        a_rows_prev = a_rows; //5
        a_cols_prev = a_cols; //5

        const char* direction[4] = {"up", "down", "left", "right"};

        if (usr_in == 'w'){

        	int random_obj = rand()%7;

            a_rows = a_rows - 1; //4
            grid[a_rows][a_cols] = 'A'; // 4 5

            grid[a_rows_prev][a_cols_prev] = '.'; // 5 5

            grid[a_rows_prev_random][a_cols_prev_random] = array[random_obj];

            alien_action = direction[0];

        }
        if (usr_in == 's'){

        	int random_obj = rand()%7;

            a_rows = a_rows + 1;
            grid[a_rows][a_cols] = 'A';

            grid[a_rows_prev][a_cols_prev] = '.';

            grid[a_rows_prev_random][a_cols_prev_random] = array[random_obj];

            alien_action = direction[1];
        }
        if (usr_in == 'a'){

        	int random_obj = rand()%7;

            a_cols = a_cols - 1;
            grid[a_rows][a_cols] = 'A';

            grid[a_rows_prev][a_cols_prev] = '.';

            grid[a_rows_prev_random][a_cols_prev_random] = array[random_obj];

            alien_action = direction[2];
        }
        if (usr_in == 'd'){

        	int random_obj = rand()%7;

            a_cols = a_cols + 1;
            grid[a_rows][a_cols] = 'A';

            grid[a_rows_prev][a_cols_prev] = '.';

            grid[a_rows_prev_random][a_cols_prev_random] = array[random_obj];

            alien_action = direction[3];
        }

        cout << "================================" << endl
        	 << "*                              *" << endl
        	 << "*     !! ALIEN VS ZOMBIE !!    *" << endl
    		 << "*          !! GAME !!          *" << endl
    		 << "*                              *" << endl
    		 << "================================" << endl << endl;

        for (int f = 0; f < cols; f++) {
        	cout << "--";
            }
        cout << endl;

        for (int i = 0; i < rows; i++){
        	cout << '|';
            for(int j = 0; j< cols; j++){

                cout << grid[i][j] << "|";
            }
            cout << endl;
            for (int f = 0; f < cols; f++) {
            	cout << "--";
            	}

            cout << endl;

        }

        a_rows_prev_random = a_rows_prev;
        a_cols_prev_random = a_cols_prev;

        if(usr_in == 'h'){
        	cout << endl << "Game Instruction :" << endl << endl
        		 << "Move Up = w" << endl
				 << "Move Down = d" << endl
				 << "Move Left = a" << endl
				 << "Move Right = s" << endl<< endl;
        }
        else{
        	cout << endl << "Alien has moved " << alien_action << endl << endl;
        }

        cout << "Press Enter to continue.." << endl << flush;
        cin.sync();
        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');

        system("cls");

    }

}
