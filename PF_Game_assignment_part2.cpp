// ******************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT3L 
// Names: BALVINDER SINGH A/L SITHWANTA  | JEEVA PRAKASH A/L SIVARAJAH | ABDULLAH IMRAN BIN ZAILAN 
// IDs: 1221303623 | 1221303709 | 1221303599 
// Emails: 1221303623@student.mmu.edu.my | 1221303709@student.mmu.edu.my | 1221303599@student.mmu.edu.my
// Phones: 0149832907 | 0174449220 | 0137700701
// ******************* 

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <limits>
#include <thread>
#include <windows.h>
#include <cmath>

using namespace std;

void Zombie (int x_alien, int y_alien, int x_zomb, int y_zomb, int health, int attack,int a_health,int z_att, int range){
    double distance = sqrt(pow(x_zomb - x_alien, 2) + pow(y_zomb - y_alien, 2));

    if (distance <= range) {
        // alien inflicts damage on zombie
        // alien attack reset to zero
        cout << "Zombie deals" << z_att << " on zombie!" << endl;
        if(z_att > a_health){
            // zombie dies, gone to oblivion
            // Alien replaces zombie
            cout << "Zombie gets banished to the shadow realm!!!" << endl;
        }

    } else {
        cout << "Zombie cannot reach the alien." << endl;
    }
}

char objects[8] = {'p', 'r', '^', 'V','>','<','h',' '};

int main() {

	system("cls");

    int def_rows, def_cols, rows, cols, def_zombiec, zombiec;

    bool game_status = true;
    char usr_in;
    char objects[8] = {'p', 'r', '^', 'V','>','<','h',' '};
    char change_setting;
    const char* alien_action;


    int zombie;
    int zstat;
    int z_health;
    int z_att;

    int a_cols;
    int a_rows;

    int z_cols;
    int z_rows;

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
   << "~ Board Columns : " << def_cols << endl
   << "~ Zombie Count : " << def_zombiec << endl << endl ;

   cout << "Do you wish to change the setting? (y/n) : ";
   cin >> change_setting;

   cout << endl;

   if(change_setting == 'y'){

	   system("cls");

	   cout << "================" << endl
			<< "  GAME SETTING" << endl
			<< "================" << endl << endl;

	   cout << "Enter the new number of Rows : ";
	   cin >> rows;

	   cout << "Enter the new number of Columns : ";
	   cin >> cols;

	   cout << "Enter the new number of zombies : ";
	   cin >> zombiec;

	   system("cls");
   }

   if(change_setting == 'n'){

	   rows = def_rows;
	   cols = def_cols;
	   zombiec = def_zombiec;

	   system("cls");
   }

    char grid[rows][cols]; // 3x3

    // fill in grid with blank space
    for (int i = 0; i < rows; i++){
        for(int j = 0; j< cols; j++){
            int random_obj = rand()%7;
            grid[i][j] = objects[random_obj];
        }
     }

    //alien position
    a_rows = rows/2;
    a_cols = cols/2;

    grid[a_rows][a_cols] = 'A';

	if(zombiec == 1)
    {
        z_rows = rand()%rows;
        z_cols = rand()%cols;
        grid[z_rows][z_cols] = '1';
    }
    else if(zombiec == 2)
    {
        z_rows = rand()%rows;
        z_cols = rand()%cols;
        grid[z_rows][z_cols] = '1';

        z_rows = rand()%rows;
        z_cols = rand()%cols;
        grid[z_rows][z_cols] = '2';
    }
    else if(zombiec == 3)
    {
        z_rows = rand()%rows;
        z_cols = rand()%cols;
        grid[z_rows][z_cols] = '1';

        z_rows = rand()%rows;
        z_cols = rand()%cols;
        grid[z_rows][z_cols] = '2';

        z_rows = rand()%rows;
        z_cols = rand()%cols;
        grid[z_rows][z_cols] = '3';
    }
    else if(zombiec == 4)
    {
        z_rows = rand()%rows;
        z_cols = rand()%cols;
        grid[z_rows][z_cols] = '1';

        z_rows = rand()%rows;
        z_cols = rand()%cols;
        grid[z_rows][z_cols] = '2';

        z_rows = rand()%rows;
        z_cols = rand()%cols;
        grid[z_rows][z_cols] = '3';

        z_rows = rand()%rows;
        z_cols = rand()%cols;
        grid[z_rows][z_cols] = '4';
    }

    int a_health=30; //alien health
    int a_att=0; //alien attack

    a_health=0;
    a_att=0;


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
    		 << "* Alien      ||  Health : "<< a_health << " " << " | Attack : " << a_att << "  || *" <<endl
			 << "================================================" <<endl;

    	for(zstat=1; zstat<=zombiec; zstat++){
    		cout << "* Zombie " << zstat << "   " << "||  Health : 100% | Attack : 0 || *"<<endl
    			 << "================================================" <<endl;
    	}

    	cout << endl << "Enter a command (h = help to start): " << endl;

    	cin >> usr_in;

        system("cls");

        a_rows_prev = a_rows;
        a_cols_prev = a_cols;

        const char* direction[4] = {"up", "down", "left", "right"}; //the direction of the movement
        const char* objects_name[5] = {"a pod", "a rock", "an arrow", "a health pack", "an empty space"};

        int obj;
        obj=0;

        if (usr_in == 'w'){

                	int random_obj = rand()%7;

                    if((a_rows - 1) < 0){
				        obj = 5;
						}
                	else if(grid[a_rows-1][a_cols]==objects[0]){ //initialize pod
                		obj=0;

                		a_att=a_att+20; //increase alien attack
                		a_rows = a_rows - 1;

                		grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                		grid[a_rows_prev][a_cols_prev] = '.';
                		grid[a_rows][a_cols] = 'A';

                	}
                	else if(grid[a_rows-1][a_cols]==objects[1]){ //initialize rock
                		obj=1;

                		grid[a_rows-1][a_cols] = objects[random_obj];
                		grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];

                		grid[a_rows][a_cols] = 'A';

                	}
                	else if(grid[a_rows-1][a_cols]==objects[2]){ //initialize ^

                		obj=2;

                		a_att=a_att+20; //increase alien attack
                		a_rows = a_rows - 1;

                		grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                		grid[a_rows_prev][a_cols_prev] = '.';
                		grid[a_rows][a_cols] = 'A';

                	}
                	else if(grid[a_rows-1][a_cols]==objects[3]){ //initialize V
                		obj=2;

                		a_att=a_att+20; //increase alien attack
                		a_rows = a_rows - 1;

                		grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                		grid[a_rows_prev][a_cols_prev] = '.';
                		grid[a_rows][a_cols] = 'A';

                	}

                	else if(grid[a_rows-1][a_cols]==objects[4]){ //initialize >
                		obj=2;

                		a_att=a_att+20; //increase alien attack
                		a_rows = a_rows - 1;

                		grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                		grid[a_rows_prev][a_cols_prev] = '.';
                		grid[a_rows][a_cols] = 'A';

                	}

                	else if(grid[a_rows-1][a_cols]==objects[5]){ //initialize <
                		obj=2;

                		a_att=a_att+20; //increase alien attack
                		a_rows = a_rows - 1;

                		grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                		grid[a_rows_prev][a_cols_prev] = '.';
                		grid[a_rows][a_cols] = 'A';

                	}

                	else if(grid[a_rows-1][a_cols]==objects[6]){ //initialize health
                		obj=3;

                		a_health = a_health+20;
                		a_rows = a_rows - 1;

                	    grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                	    grid[a_rows_prev][a_cols_prev] = '.';
                	    grid[a_rows][a_cols] = 'A';

                	}
                    else{
                    	a_rows = a_rows - 1;
                    	obj=4;

                    	grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                    	grid[a_rows_prev][a_cols_prev] = '.';
                    	grid[a_rows][a_cols] = 'A';

                    }

                    alien_action = direction[0];

                }
		else if (usr_in == 's'){

                	int random_obj = rand()%7;

                    if((a_rows + 1) >= rows ){
				        obj = 5;
                        }
                	else if(grid[a_rows+1][a_cols]==objects[0]){ //initialize pod
                		obj=0;

                		a_att=a_att+20; //increase alien attack
                		a_rows = a_rows+1;

                		grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                		grid[a_rows_prev][a_cols_prev] = '.';
                		grid[a_rows][a_cols] = 'A';


                	}
                	else if(grid[a_rows+1][a_cols]==objects[1]){ //initialize rock
                		obj=1;

                		grid[a_rows+1][a_cols] = objects[random_obj];
                		grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];

                		grid[a_rows][a_cols] = 'A';


                	}
                	else if(grid[a_rows+1][a_cols]==objects[2]){ //initialize ^
                		obj=2;
                		a_rows = a_rows+1;

                		grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                		grid[a_rows_prev][a_cols_prev] = '.';
                		grid[a_rows][a_cols] = 'A';


                	}
                	else if(grid[a_rows+1][a_cols]==objects[3]){ //initialize V
                		obj=2;
                		a_rows = a_rows+1;

                		grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                		grid[a_rows_prev][a_cols_prev] = '.';
                		grid[a_rows][a_cols] = 'A';

                	}

                	else if(grid[a_rows+1][a_cols]==objects[4]){ //initialize >
                		obj=2;
                		a_rows = a_rows+1;

                		grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                		grid[a_rows_prev][a_cols_prev] = '.';
                		grid[a_rows][a_cols] = 'A';

                	}

                	else if(grid[a_rows+1][a_cols]==objects[5]){ //initialize <
                		obj=2;
                		a_rows = a_rows+1;

                		grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                		grid[a_rows_prev][a_cols_prev] = '.';
                		grid[a_rows][a_cols] = 'A';

                	}

                	else if(grid[a_rows+1][a_cols]==objects[6]){ //initialize health
                		obj=3;

                		a_health = a_health+20;
                		a_rows = a_rows+1;

                	    grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                	    grid[a_rows_prev][a_cols_prev] = '.';
                	    grid[a_rows][a_cols] = 'A';
                	}
                    else{
                    	obj=4;
                    	a_rows = a_rows+1;

                    	grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                    	grid[a_rows_prev][a_cols_prev] = '.';
                    	grid[a_rows][a_cols] = 'A';


                    }

                    alien_action = direction[1];
                }
		else if (usr_in == 'a'){

                	int random_obj = rand()%7;

                    if((a_cols - 1) < 0){
				            obj = 5;
                            }
                	else if(grid[a_rows][a_cols-1]==objects[0]){ //initialize pod
                		obj=0;

                		a_att=a_att+20; //increase alien attack
                		a_cols = a_cols-1;

                		grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                		grid[a_rows_prev][a_cols_prev] = '.';
                		grid[a_rows][a_cols] = 'A';


                	}
                	else if(grid[a_rows][a_cols-1]==objects[1]){ //initialize rock
                		obj=1;

                		grid[a_rows][a_cols-1] = objects[random_obj];
                		grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                		grid[a_rows][a_cols] = 'A';


                	}
                	else if(grid[a_rows][a_cols-1]==objects[2]){ //initialize ^
                		obj=2;

                		a_att=a_att+20; //increase alien attack
                		a_cols = a_cols-1;

                		grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                		grid[a_rows_prev][a_cols_prev] = '.';
                		grid[a_rows][a_cols] = 'A';


                	}
                	else if(grid[a_rows][a_cols-1]==objects[3]){ //initialize V
                		obj=2;

                		a_att=a_att+20; //increase alien attack
                		a_cols = a_cols-1;

                		grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                		grid[a_rows_prev][a_cols_prev] = '.';
                		grid[a_rows][a_cols] = 'A';

                	}

                	else if(grid[a_rows][a_cols-1]==objects[4]){ //initialize >
                		obj=2;

                		a_att=a_att+20; //increase alien attack
                		a_cols = a_cols-1;

                		grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                		grid[a_rows_prev][a_cols_prev] = '.';
                		grid[a_rows][a_cols] = 'A';

                	}

                	else if(grid[a_rows][a_cols-1]==objects[5]){ //initialize <
                		obj=2;

                		a_att=a_att+20; //increase alien attack
                		a_cols = a_cols-1;

                		grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                		grid[a_rows_prev][a_cols_prev] = '.';
                		grid[a_rows][a_cols] = 'A';

                	}

                	else if(grid[a_rows][a_cols-1]==objects[6]){ //initialize health
                		obj=3;

                		a_health = a_health+20;
                		a_cols = a_cols-1;

                	    grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                	    grid[a_rows_prev][a_cols_prev] = '.';
                	    grid[a_rows][a_cols] = 'A';

                	}
                    else{
                    	obj=4;

                    	a_cols = a_cols-1;

                    	grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                    	grid[a_rows_prev][a_cols_prev] = '.';
                    	grid[a_rows][a_cols] = 'A';

                	}

                    alien_action = direction[2];
                }

		else if (usr_in == 'd'){

                	int random_obj = rand()%7;

                    if((a_cols + 1) >= cols){
				            obj = 5;
			                        }
                	else if(grid[a_rows][a_cols+1]==objects[0]){ //initialize pod
                		obj=0;

                		a_att=a_att+20; //increase alien attack
                		a_cols = a_cols+1;

                		grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                		grid[a_rows_prev][a_cols_prev] = '.';
                		grid[a_rows][a_cols] = 'A';

                	}
                	else if(grid[a_rows][a_cols+1]==objects[1]){ //initialize rock
                		obj=1;

                		grid[a_rows][a_cols+1] = objects[random_obj];
                		grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                		grid[a_rows][a_cols] = 'A';

                	}
                	else if(grid[a_rows][a_cols+1]==objects[2]){ //initialize ^
                		obj=2;

                		a_att=a_att+20; //increase alien attack
                		a_cols = a_cols+1;

                		grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                		grid[a_rows_prev][a_cols_prev] = '.';
                		grid[a_rows][a_cols] = 'A';

                	}
                	else if(grid[a_rows][a_cols+1]==objects[3]){ //initialize V
                		obj=2;

                		a_att=a_att+20; //increase alien attack
                		a_cols = a_cols+1;

                		grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                		grid[a_rows_prev][a_cols_prev] = '.';
                		grid[a_rows][a_cols] = 'A';

                	}

                	else if(grid[a_rows][a_cols+1]==objects[4]){ //initialize >
                		obj=2;

                		a_att=a_att+20; //increase alien attack
                		a_cols = a_cols+1;

                		grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                		grid[a_rows_prev][a_cols_prev] = '.';
                		grid[a_rows][a_cols] = 'A';

                	}

                	else if(grid[a_rows][a_cols+1]==objects[5]){ //initialize >
                		obj=2;

                		a_att=a_att+20; //increase alien attack
                		a_cols = a_cols+1;

                		grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                		grid[a_rows_prev][a_cols_prev] = '.';
                		grid[a_rows][a_cols] = 'A';

                	}

                	else if(grid[a_rows][a_cols+1]==objects[6]){ //initialize health
                		obj=3;

                		a_health = a_health+20;
                		a_cols = a_cols+1;

                	    grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                	    grid[a_rows_prev][a_cols_prev] = '.';
                	    grid[a_rows][a_cols] = 'A';

                	}
                    else{
                    	obj=4;
                    	a_cols = a_cols+1;

                    	grid[a_rows_prev_random][a_cols_prev_random] = objects[random_obj];
                    	grid[a_rows_prev][a_cols_prev] = '.';
                    	grid[a_rows][a_cols] = 'A';

                    }
                    alien_action = direction[3];
                }
		else if(usr_in == 'h'){
                	cout << endl << "Game Instruction :" << endl << endl
                		 << "Move Up = w" << endl
        				 << "Move Down = d" << endl
        				 << "Move Left = a" << endl
        				 << "Move Right = s" << endl<< endl;
                }
			else{
        		if(obj==1){
					cout << "Alien hits a rock and discovered a new object!" << endl << endl;
                	}
				else{
                	cout << "Alien has found " << objects_name[obj] << endl;
                    }
				if(obj==2){
					cout << "Alien attack has increased by +20" << endl << endl;
                	}
				else if(obj==3){
					cout << "Alien health has increased by +20" << endl << endl;
                	}
				else if(obj==4){
                    }
				else if(obj==5){    
					cout <<"You are on the edge, pls move another direction" << endl;
                	}

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

                cout << "Press Enter to continue.." << endl << flush;
                cin.sync();
                cin.ignore(std::numeric_limits<streamsize>::max(),'\n');

                system("cls");
            }

        }
