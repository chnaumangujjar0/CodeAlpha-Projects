#include <iostream>
using namespace std;

int main() {

     int grid[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},

        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},

        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    cout << "Sudoku Grid:\n\n";
    cout<<" +---+---+---+---+---+---+---+---+---+"<<endl;
    for(int i = 0; i < 9; i++) {
        cout<<" | ";
        for(int j = 0; j < 9; j++) {
            cout << grid[i][j] << " | ";
        }
        cout << endl;
        cout<<" +---+---+---+---+---+---+---+---+---+"<<endl;
    }
    int row;
    int column;
    int num;
    cout<<"\n For inserting Number, please tell row number and coulmn number where do you want to add your number.";
    while(true){
        cout<<"\n Enter row number : ";
        cin>>row;
        row--;
        cout<<"\n Enter Coulmn : ";
        cin>>column;
        column--;
        cout<<"\n Enter Number : ";
        cin>>num;
        // ---- For Row check
        bool isSafe = true ;
        for(int i=0;i<9;i++){
           if(grid[row][i] == num){
              isSafe = false;
             break;
           }
        }
        
        if(!isSafe){
           continue;
        }else{   // check respective coulmn check
            for(int i=0;i<9;i++){
                if(grid[i][column] == num){
                   isSafe == false;
                   break;
                }
            }
           
        }

       
    }
  
    return 0;
}