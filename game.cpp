
#include <iostream>
#include <windows.h>
#include <cstdlib>
using namespace std;

HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

void loadingbar() {
    
    char loadingBar=219;
    //clearing screen
    system("cls");

    //printing loading bar
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tLoading...\n";
    cout<<"\t\t\t\t";

    for (int i=0;i<30;i++) {
        cout<<loadingBar;
        Sleep(10);
    }

    //clearing screen
    system("cls");
}

void checkmate() {
    
    loadingbar();

    int row,col;
    int grid[8][8]={0};
    char box=219;

    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

    cout<<"\n\n";

    int count=0; 

    //coloring chess board
    for (int i=0;i<8;i++) {
        count=0;
        for (int j=0;j<8;j++) {

            if (i%2==0) {
                if (count%2==0) {
                    grid[i][j]=0;
                    count++;              
                }
                else if (count%2!=0) {
                    grid[i][j]=1;  
                    count++;               
                }
            }

            else if (i%2!=0) {
                if (count%2==0) {
                    grid[i][j]=1;
                    count++;              
                }
                else if (count%2!=0) {
                    grid[i][j]=0;  
                    count++;               
                }
            }
        }
    }

    cout<<"\n\n\n";  

    //printing chees board
    for (int i=0;i<8;i++) {
        cout<<"\t\t\t    "; 

        for (int j=0;j<8;j++) {

            if (grid[i][j]==1) {
                SetConsoleTextAttribute(h,15); //white
                cout<<box<<box<<"  ";                
            }
         
            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,0); //black
                cout<<box<<box<<"  ";                            
            }

        }
        cout<<"\n\n";
    }

    SetConsoleTextAttribute(h,15); //white
    cout<<"\n\t\t\t\t  C H E C K  M A T E\n";
    cout<<"\n\t\t\t\tThe  King  Has  Fallen\n\n\n\n\n";

    Sleep(3500);
    system("cls");
}

void king(int grid[][8], int r, int c) {

    system("cls");

    int current_BC, current_BR, row, col;
    char box=219;

    //Finding Location of BISHOP 1
    int b1row, b1col;
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==91) {
                b1row=i;
                b1col=j;
            }
        }
    }

    //Finding Location of BISHOP 2
    int b2row, b2col;
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==92) {
                b2row=i;
                b2col=j;
            }
        }
    }
    
    //finding KING's position
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==89) {
                row=i;
                col=j;
            }
        }
    }

    //vertical above
    if (row>0)
        grid[row-1][col]=90;
    
    //vertical below
    if (row<7)
        grid[row+1][col]=90;

    //horizontal right
    if (col<7)
        grid[row][col+1]=90;
  
    //horizontal left
    if (col>0)
        grid[row][col-1]=90;
    
    //North-West
    if (row>0 && col>0)
        grid[row-1][col-1]=90;

    //North-East
    if (row>0 && col<7)
        grid[row-1][col+1]=90;    

    //South-West
    if (row<7 && col>0)
        grid[row+1][col-1]=90;

    //South-East
    if (row<7 && col<7)
        grid[row+1][col+1]=90;

    //re-assigning position to BISHOP 1
    grid[b1row][b1col]=91;

    //re-assigning position to BISHOP 2
    grid[b2row][b2col]=92;


    //printing board
    cout<<"\n\n\n";
    for (int i=0;i<8;i++) {
        SetConsoleTextAttribute(h,15); 
        cout<<"\t\t   "<<i+1<<"  ";
        for (int j=0;j<8;j++) {
            
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==91) {
                SetConsoleTextAttribute(h,5);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==92) {
                SetConsoleTextAttribute(h,1);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==90) {
                SetConsoleTextAttribute(h,14); 
                cout<<box<<box<<"  ";   
            }

            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,15); 
                cout<<box<<box<<"  ";   
            }

        }
        cout<<"\n\n";
    }
    SetConsoleTextAttribute(h,15); 
    int num=1;
    cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

    SetConsoleTextAttribute(h,15); 
    cout<<"\n\n\t\t\tRow: ";
    cin>>current_BR;
    cout<<"\t\t\tColumn: ";
    cin>>current_BC;

    current_BR-- ; current_BC --;

    //checking for out of range inputs
    while (grid[current_BR][current_BC]!=90) {

        system("cls");

        //printing board
        cout<<"\n\n\n";
        for (int i=0;i<8;i++) {
            SetConsoleTextAttribute(h,15); 
            cout<<"\t\t   "<<i+1<<"  ";
            for (int j=0;j<8;j++) {
                
                if (grid[i][j]==89) {
                    SetConsoleTextAttribute(h,4);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==91) {
                    SetConsoleTextAttribute(h,5);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==92) {
                    SetConsoleTextAttribute(h,1);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==90) {
                    SetConsoleTextAttribute(h,14); 
                    cout<<box<<box<<"  ";   
                }

                if (grid[i][j]==0) {
                    SetConsoleTextAttribute(h,15); 
                    cout<<box<<box<<"  ";   
                }

            }
            cout<<"\n\n";
        }
        SetConsoleTextAttribute(h,15); 
        int num=1;
        cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

        SetConsoleTextAttribute(h,15);
        cout<<"\n\n\n\t\t\tOut of Range. Try Again\n";
        cout<<"\n\n\t\t\tRow: ";
        cin>>current_BR;
        cout<<"\t\t\tColumn: ";
        cin>>current_BC;

        current_BR-- ; current_BC --;
    }

    //changing position
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==89)
                grid[i][j]=0;
        }
    }
    grid[current_BR][current_BC]=89;

    //clearing possible moves
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==90) 
                grid[i][j]=0;
        }
    }

    //printing board
    cout<<"\n\n\n";
    for (int i=0;i<8;i++) {
        SetConsoleTextAttribute(h,15); 
        cout<<"\t\t   "<<i+1<<"  ";
        for (int j=0;j<8;j++) {
            
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==91) {
                SetConsoleTextAttribute(h,5);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==92) {
                SetConsoleTextAttribute(h,1);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,15); 
                cout<<box<<box<<"  ";   
            }

        }
        cout<<"\n\n";
    }
    num=1;
    cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

}

bool bishop1(int grid[][8],int r,int c,int randBR1,int randBC1) {

    system("cls");
    char box=219;
    int current_BR, current_BC, row, col;
    bool checkMate=false;

    //finding BISHOP's position
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==91) {
                row=i;
                col=j;
            }
        }
    }

    int kingrow, kingcol;
    //Finding Location of KING
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==89) {
                kingrow=i;
                kingcol=j;
            }
        }
    }

    //Finding Location of BISHOP 2
    int b2row, b2col;
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==92) {
                b2row=i;
                b2col=j;
            }
        }
    }

    //North-West
    int tempRow=row, tempCol=col;
    while (tempRow >= 0 && tempCol >= 0) 
        grid[tempRow--][tempCol--]=93;

    //North-East
    tempRow=row, tempCol=col;
    while (tempRow >= 0 && tempCol <= 7) 
        grid[tempRow--][tempCol++]=93;

    //South-West
    tempRow=row, tempCol=col;
    while (tempRow <= 7 && tempCol >= 0) 
        grid[tempRow++][tempCol--]=93;

    //South-East
    tempRow=row, tempCol=col;
    while (tempRow <= 7 && tempCol <= 7) 
        grid[tempRow++][tempCol++]=93;

    //re-assigning position to BISHOP 1
    grid[row][col]=91;

    //re-assigning position to KING
    grid[kingrow][kingcol]=89;

    //re-assigning position to BISHOP 2
    grid[b2row][b2col]=92;

    //printing board
    cout<<"\n\n\n";
    for (int i=0;i<8;i++) {
        SetConsoleTextAttribute(h,15); 
        cout<<"\t\t   "<<i+1<<"  ";
        for (int j=0;j<8;j++) {
            
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==91) {
                SetConsoleTextAttribute(h,5);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==92) {
                SetConsoleTextAttribute(h,1);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==93) {
                SetConsoleTextAttribute(h,14); 
                cout<<box<<box<<"  ";   
            }

            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,15); 
                cout<<box<<box<<"  ";   
            }

        }
        cout<<"\n\n";
    }
    SetConsoleTextAttribute(h,15); 
    int num=1;
    cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

    SetConsoleTextAttribute(h,15);
    cout<<"\n\n\t\t\tRow: ";
    cin>>current_BR;
    cout<<"\t\t\tColumn: ";
    cin>>current_BC;

    current_BR-- ; current_BC --;

    if (current_BR==kingrow && current_BC==kingcol) 
        checkMate=true;

    //checking for out of range inputs
    while (grid[current_BR][current_BC]!=93 && !checkMate) {

        system("cls");

        //printing board
        cout<<"\n\n\n";
        for (int i=0;i<8;i++) {
            SetConsoleTextAttribute(h,15); 
            cout<<"\t\t   "<<i+1<<"  ";
            for (int j=0;j<8;j++) {
                
                if (grid[i][j]==89) {
                    SetConsoleTextAttribute(h,4);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==91) {
                    SetConsoleTextAttribute(h,5);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==92) {
                    SetConsoleTextAttribute(h,1);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==93) {
                    SetConsoleTextAttribute(h,14); 
                    cout<<box<<box<<"  ";   
                }

                if (grid[i][j]==0) {
                    SetConsoleTextAttribute(h,15); 
                    cout<<box<<box<<"  ";   
                }

            }
            cout<<"\n\n";
        }
        SetConsoleTextAttribute(h,15); 
        int num=1;
        cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

        SetConsoleTextAttribute(h,15);
        cout<<"\n\n\n\t\t\tOut of Range. Try Again\n";
        cout<<"\n\n\t\t\tRow: ";
        cin>>current_BR;
        cout<<"\t\t\tColumn: ";
        cin>>current_BC;

        current_BR-- ; current_BC --;

        if (current_BR==kingrow && current_BC==kingcol) {
            checkMate=true;
            break;
        }
    }

    //changing position
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==91)
                grid[i][j]=0;
        }
    }
    grid[current_BR][current_BC]=91;

    if (!checkMate) {

    //clearing possible moves
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==93) 
                grid[i][j]=0;
        }
    }

    //printing board
    cout<<"\n\n\n";
    for (int i=0;i<8;i++) {
        SetConsoleTextAttribute(h,15); 
        cout<<"\t\t   "<<i+1<<"  ";
        for (int j=0;j<8;j++) {
            
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==91) {
                SetConsoleTextAttribute(h,5);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==92) {
                SetConsoleTextAttribute(h,1);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,15); 
                cout<<box<<box<<"  ";   
            }

        }
        cout<<"\n\n";
    }
    num=1;
    cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;


    }

    return checkMate;

}

bool bishop2(int grid[][8],int r,int c,int randBR2,int randBC2) {

    system("cls");
    char box=219;
    int current_BR, current_BC, row, col;
    bool checkMate=false;

    //finding BISHOP's position
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==92) {
                row=i;
                col=j;
            }
        }
    }

    int kingrow, kingcol;
    //Finding Location of KING
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==89) {
                kingrow=i;
                kingcol=j;
            }
        }
    }

    //Finding Location of BISHOP 1
    int b1row, b1col;
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==91) {
                b1row=i;
                b1col=j;
            }
        }
    }

    //North-West
    int tempRow=row, tempCol=col;
    while (tempRow >= 0 && tempCol >= 0) 
        grid[tempRow--][tempCol--]=94;

    //North-East
    tempRow=row, tempCol=col;
    while (tempRow >= 0 && tempCol <= 7) 
        grid[tempRow--][tempCol++]=94;

    //South-West
    tempRow=row, tempCol=col;
    while (tempRow <= 7 && tempCol >= 0) 
        grid[tempRow++][tempCol--]=94;

    //South-East
    tempRow=row, tempCol=col;
    while (tempRow <= 7 && tempCol <= 7) 
        grid[tempRow++][tempCol++]=94;

    //re-assigning position to BISHOP 2
    grid[row][col]=92;

    //re-assigning position to KING
    grid[kingrow][kingcol]=89;

    //re-assigning position to BISHOP 1
    grid[b1row][b1col]=91;

    //printing board
    cout<<"\n\n\n";
    for (int i=0;i<8;i++) {
        SetConsoleTextAttribute(h,15); 
        cout<<"\t\t   "<<i+1<<"  ";
        for (int j=0;j<8;j++) {
            
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==91) {
                SetConsoleTextAttribute(h,5);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==92) {
                SetConsoleTextAttribute(h,1);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==94) {
                SetConsoleTextAttribute(h,14);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,15); 
                cout<<box<<box<<"  ";   
            }

        }
        cout<<"\n\n";
    }
    SetConsoleTextAttribute(h,15); 
    int num=1;
    cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

    SetConsoleTextAttribute(h,15); 
    cout<<"\n\n\t\t\tRow: ";
    cin>>current_BR;
    cout<<"\t\t\tColumn: ";
    cin>>current_BC;

    current_BR-- ; current_BC --;

    if (current_BR==kingrow && current_BC==kingcol) 
        checkMate=true;

    //checking for out of range inputs
    while (grid[current_BR][current_BC]!=94 && !checkMate) {

        system("cls");

        //printing board
        cout<<"\n\n\n";
        for (int i=0;i<8;i++) {
            SetConsoleTextAttribute(h,15); 
            cout<<"\t\t   "<<i+1<<"  ";
            for (int j=0;j<8;j++) {
                
                if (grid[i][j]==89) {
                    SetConsoleTextAttribute(h,4);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==91) {
                    SetConsoleTextAttribute(h,5);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==92) {
                    SetConsoleTextAttribute(h,1);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==94) {
                    SetConsoleTextAttribute(h,14); 
                    cout<<box<<box<<"  ";   
                }

                if (grid[i][j]==0) {
                    SetConsoleTextAttribute(h,15); 
                    cout<<box<<box<<"  ";   
                }

            }
            cout<<"\n\n";
        }
        SetConsoleTextAttribute(h,15); 
        int num=1;
        cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

        SetConsoleTextAttribute(h,15);
        cout<<"\n\n\n\t\t\tOut of Range. Try Again\n";
        cout<<"\n\n\t\t\tRow: ";
        cin>>current_BR;
        cout<<"\t\t\tColumn: ";
        cin>>current_BC;

        current_BR-- ; current_BC --;

        if (current_BR==kingrow && current_BC==kingcol) {
            checkMate=true;
            break;
        }
    }

    //changing position
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==92)
                grid[i][j]=0;
        }
    }
    grid[current_BR][current_BC]=92;

    if (!checkMate) {

    //clearing possible moves
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==94) 
                grid[i][j]=0;
        }
    }

    //printing board
    cout<<"\n\n\n";
    for (int i=0;i<8;i++) {
        SetConsoleTextAttribute(h,15); 
        cout<<"\t\t   "<<i+1<<"  ";
        for (int j=0;j<8;j++) {
            
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==91) {
                SetConsoleTextAttribute(h,5);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==92) {
                SetConsoleTextAttribute(h,1);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,15); 
                cout<<box<<box<<"  ";   
            }

        }
        cout<<"\n\n";
    }
    num=1;
    cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

    }

    return checkMate;

}

void bishop() {

    loadingbar();

    srand(time(NULL));

    int randKingRow=rand()%6 , randKingCol=rand()%6;
    int randBR1=rand()%6, randBC1=rand()%6;
    int randBR2=rand()%6, randBC2=rand()%6;
    
    int select, count=0;
    int grid[8][8]={0};
    char box=219;
    bool checkMate=false;

    //assigning random values
    if (count==0) {
        //random position KING
        grid[randKingRow][randKingCol]=89;

        //random value to Bishop 1
        grid[randBR1][randBC1]=91;

        //random value to Bishop 2
        grid[randBR2][randBC2]=92;

        count++;
    }

    //printing board
    cout<<"\n\n\n";
    for (int i=0;i<8;i++) {
        SetConsoleTextAttribute(h,15); 
        cout<<"\t\t   "<<i+1<<"  ";
        for (int j=0;j<8;j++) {
            
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==91) {
                SetConsoleTextAttribute(h,5);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==92) {
                SetConsoleTextAttribute(h,1);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,15); 
                cout<<box<<box<<"  ";   
            }

        }
        cout<<"\n\n";
    }
    int num=1;
    cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

    cout<<"\n\n\t\t\tChoose Your Piece\n\n\t\t\t[1] Bishop 1\n\t\t\t[2] Bishop 2\n\n\t\t\tSelect: ";
    cin>>select;

    int counter=5;

    if (select==1) {
        bishop1(grid, 8, 8, randBR1, randBC1);
        king(grid,8,8);        
    }

    else if (select==2) {
        bishop2(grid, 8, 8, randBR2, randBC2);
        king(grid,8,8);
    }

    while (!checkMate) {

        system("cls");

        //printing board
        cout<<"\n\n\n";
        for (int i=0;i<8;i++) {
            SetConsoleTextAttribute(h,15); 
            cout<<"\t\t   "<<i+1<<"  ";
            for (int j=0;j<8;j++) {
                
                if (grid[i][j]==89) {
                    SetConsoleTextAttribute(h,4);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==91) {
                    SetConsoleTextAttribute(h,5);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==92) {
                    SetConsoleTextAttribute(h,1);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==0) {
                    SetConsoleTextAttribute(h,15); 
                    cout<<box<<box<<"  ";   
                }

            }
            cout<<"\n\n";
        }
        
        SetConsoleTextAttribute(h,15); 
        num=1;
        cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

        SetConsoleTextAttribute(h,15); 
        cout<<"\n\n\t\t\tChoose Your Piece\n\n\t\t\t[1] Bishop 1\n\t\t\t[2] Bishop 2\n\n\t\t\tSelect: ";
        cin>>select;

        if (select==1) {
            checkMate=bishop1(grid, 8, 8, randBR1, randBC1);
            if (!checkMate)
                king(grid,8,8); 
            else {
                checkmate();
                break;
            }
        }

        if (select==2) {
            checkMate=bishop2(grid, 8, 8, randBR2, randBC2);
            if (!checkMate)
                king(grid,8,8); 
            else {
                checkmate();
                break;
            }
        }

    }

}

bool knight1(int grid[][8], int r, int c, int randKR1, int randKC1) {
    
    system("cls");
    char box=219;
    int current_BR, current_BC, row, col;
    bool checkMate=false;

    //finding KNIGHT's position
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==91) {
                row=i;
                col=j;
            }
        }
    }

    int kingrow, kingcol;
    //Finding Location of KING
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==89) {
                kingrow=i;
                kingcol=j;
            }
        }
    }

    //Finding Location of KNIGHT 2
    int b2row, b2col;
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==92) {
                b2row=i;
                b2col=j;
            }
        }
    }

    //Above-right 1
    if (row >= 2 && col < 7)
        grid[row-2][col+1]=93;

    //Above-right 2
    if (row >= 1 && col <= 5)
        grid[row-1][col+2]=93;

    //Above-left 1
    if (row >= 2 && col > 0)
        grid[row-2][col-1]=93;

    //Above-left 2
    if (row >= 1 && col >= 2)
        grid[row-1][col-2]=93;

    //Below-right 1
    if (row <= 5 && col < 7)
        grid[row+2][col+1]=93;

    //Below-right 2
    if (row <= 6 && col <= 5)
        grid[row+1][col+2]=93;

    //Below-left 1
    if (row <= 5 && col > 0)
        grid[row+2][col-1]=93; 

    //Below-left 2
    if (row <= 6 && col >= 2)
        grid[row+1][col-2]=93; 

    //re-assigning position to KNIGHT 1
    grid[row][col]=91;
    
    //re-assigning position to KING
    grid[kingrow][kingcol]=89;

    //re-assigning position to KNIGHT 2
    grid[b2row][b2col]=92;

    //printing board
    cout<<"\n\n\n";
    for (int i=0;i<8;i++) {
        SetConsoleTextAttribute(h,15); 
        cout<<"\t\t   "<<i+1<<"  ";
        for (int j=0;j<8;j++) {
            
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==91) {
                SetConsoleTextAttribute(h,5);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==92) {
                SetConsoleTextAttribute(h,1);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==93) {
                SetConsoleTextAttribute(h,14); 
                cout<<box<<box<<"  ";   
            }

            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,15); 
                cout<<box<<box<<"  ";   
            }

        }
        cout<<"\n\n";
    }
    SetConsoleTextAttribute(h,15); 
    int num=1;
    cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

    cout<<"\n\n\t\t\tRow: ";
    cin>>current_BR;
    cout<<"\t\t\tColumn: ";
    cin>>current_BC;

    current_BR-- ; 
    current_BC --;

    if (current_BR==kingrow && current_BC==kingcol) 
        checkMate=true;

    //checking for out of range inputs
    while (grid[current_BR][current_BC]!=93 && !checkMate) {

        system("cls");

        //printing board
        cout<<"\n\n\n";
        for (int i=0;i<8;i++) {
            SetConsoleTextAttribute(h,15); 
            cout<<"\t\t   "<<i+1<<"  ";
            for (int j=0;j<8;j++) {
                
                if (grid[i][j]==89) {
                    SetConsoleTextAttribute(h,4);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==91) {
                    SetConsoleTextAttribute(h,5);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==92) {
                    SetConsoleTextAttribute(h,1);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==93) {
                    SetConsoleTextAttribute(h,14); 
                    cout<<box<<box<<"  ";   
                }

                if (grid[i][j]==0) {
                    SetConsoleTextAttribute(h,15); 
                    cout<<box<<box<<"  ";   
                }

            }
            cout<<"\n\n";
        }
        SetConsoleTextAttribute(h,15); 
        int num=1;
        cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

        SetConsoleTextAttribute(h,15);
        cout<<"\n\n\n\t\t\tOut of Range. Try Again\n";
        cout<<"\n\n\t\t\tRow: ";
        cin>>current_BR;
        cout<<"\t\t\tColumn: ";
        cin>>current_BC;

        current_BR-- ; current_BC --;

        if (current_BR==kingrow && current_BC==kingcol) {
            checkMate=true;
            break;
        }
    }

    //changing position
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==91)
                grid[i][j]=0;
        }
    }
    grid[current_BR][current_BC]=91;

    if (!checkMate) {

    //clearing possible moves
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==93) 
                grid[i][j]=0;
        }
    }

    //printing board
    cout<<"\n\n\n";
    for (int i=0;i<8;i++) {
        SetConsoleTextAttribute(h,15); 
        cout<<"\t\t   "<<i+1<<"  ";
        for (int j=0;j<8;j++) {
            
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==91) {
                SetConsoleTextAttribute(h,5);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==92) {
                SetConsoleTextAttribute(h,1);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,15); 
                cout<<box<<box<<"  ";   
            }

        }
        cout<<"\n\n";
    }
    num=1;
    cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

    }

    return checkMate;

}

bool knight2(int grid[][8], int r, int c, int randKR2, int randKC2) {

    system("cls");
    char box=219;
    int current_BR, current_BC, row, col;
    bool checkMate=false;

    //finding KNIGHT's position
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==92) {
                row=i;
                col=j;
            }
        }
    }

    int kingrow, kingcol;
    //Finding Location of KING
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==89) {
                kingrow=i;
                kingcol=j;
            }
        }
    }

    //Finding Location of KNIGHT 1
    int b1row, b1col;
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==91) {
                b1row=i;
                b1col=j;
            }
        }
    }

    //Above-right 1
    if (row >= 2 && col < 7)
        grid[row-2][col+1]=94;

    //Above-right 2
    if (row >= 1 && col <= 5)
        grid[row-1][col+2]=94;

    //Above-left 1
    if (row >= 2 && col > 0)
        grid[row-2][col-1]=94;

    //Above-left 2
    if (row >= 1 && col >= 2)
        grid[row-1][col-2]=94;

    //Below-right 1
    if (row <= 5 && col < 7)
        grid[row+2][col+1]=94;

    //Below-right 2
    if (row <= 6 && col <= 5)
        grid[row+1][col+2]=94;

    //Below-left 1
    if (row <= 5 && col > 0)
        grid[row+2][col-1]=94; 

    //Below-left 2
    if (row <= 6 && col >= 2)
        grid[row+1][col-2]=94; 

    //re-assigning position to KNIGHT 2
    grid[row][col]=92;

    //re-assigning position to KING
    grid[kingrow][kingcol]=89;

    //re-assigning position to KNIGHT 2
    grid[b1row][b1col]=91;

    //printing board
    cout<<"\n\n\n";
    for (int i=0;i<8;i++) {
        SetConsoleTextAttribute(h,15); 
        cout<<"\t\t   "<<i+1<<"  ";
        for (int j=0;j<8;j++) {
            
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==91) {
                SetConsoleTextAttribute(h,5);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==92) {
                SetConsoleTextAttribute(h,1);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==94) {
                SetConsoleTextAttribute(h,14); 
                cout<<box<<box<<"  ";   
            }

            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,15); 
                cout<<box<<box<<"  ";   
            }

        }
        cout<<"\n\n";
    }
    int num=1;
    cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

    cout<<"\n\n\t\t\tRow: ";
    cin>>current_BR;
    cout<<"\t\t\tColumn: ";
    cin>>current_BC;

    current_BR-- ; 
    current_BC --;

    if (current_BR==kingrow && current_BC==kingcol) 
        checkMate=true;

    //checking for out of range inputs
    while (grid[current_BR][current_BC]!=94 && !checkMate) {

        system("cls");

        //printing board
        cout<<"\n\n\n";
        for (int i=0;i<8;i++) {
            SetConsoleTextAttribute(h,15); 
            cout<<"\t\t   "<<i+1<<"  ";
            for (int j=0;j<8;j++) {
                
                if (grid[i][j]==89) {
                    SetConsoleTextAttribute(h,4);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==91) {
                    SetConsoleTextAttribute(h,5);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==92) {
                    SetConsoleTextAttribute(h,1);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==94) {
                    SetConsoleTextAttribute(h,14); 
                    cout<<box<<box<<"  ";   
                }

                if (grid[i][j]==0) {
                    SetConsoleTextAttribute(h,15); 
                    cout<<box<<box<<"  ";   
                }

            }
            cout<<"\n\n";
        }
        SetConsoleTextAttribute(h,15); 
        int num=1;
        cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

        SetConsoleTextAttribute(h,15);
        cout<<"\n\n\n\t\t\tOut of Range. Try Again\n";
        cout<<"\n\n\t\t\tRow: ";
        cin>>current_BR;
        cout<<"\t\t\tColumn: ";
        cin>>current_BC;

        current_BR-- ; current_BC --;

        if (current_BR==kingrow && current_BC==kingcol) {
            checkMate=true;
            break;
        }
    }

    //changing position
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==92)
                grid[i][j]=0;
        }
    }
    grid[current_BR][current_BC]=92;

    if (!checkMate) {

    //clearing possible moves
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==94) 
                grid[i][j]=0;
        }
    }

    //printing board
    cout<<"\n\n\n";
    for (int i=0;i<8;i++) {
        SetConsoleTextAttribute(h,15); 
        cout<<"\t\t   "<<i+1<<"  ";
        for (int j=0;j<8;j++) {
            
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==91) {
                SetConsoleTextAttribute(h,5);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==92) {
                SetConsoleTextAttribute(h,1);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,15); 
                cout<<box<<box<<"  ";   
            }

        }
        cout<<"\n\n";
    }
    num=1;
    cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

    }

    return checkMate; 

}

void knight() {

    loadingbar();

    srand(time(NULL));

    int randKingRow=rand()%6 , randKingCol=rand()%6;
    int randKR1=rand()%6, randKC1=rand()%6;
    int randKR2=rand()%6, randKC2=rand()%6;

    int select, count=0;
    int grid[8][8]={0};
    char box=219;
    bool checkMate=false;


    //assigning random values
    if (count==0) {
        //random position KING
        grid[randKingRow][randKingCol]=89;

        //random value to Bishop 1
        grid[randKR1][randKC1]=91;

        //random value to Bishop 2
        grid[randKR2][randKC2]=92;

        count++;
    }

    //printing board
    cout<<"\n\n\n";
    for (int i=0;i<8;i++) {
        SetConsoleTextAttribute(h,15); 
        cout<<"\t\t   "<<i+1<<"  ";
        for (int j=0;j<8;j++) {
            
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==91) {
                SetConsoleTextAttribute(h,5);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==92) {
                SetConsoleTextAttribute(h,1);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,15); 
                cout<<box<<box<<"  ";   
            }

        }
        cout<<"\n\n";
    }
    SetConsoleTextAttribute(h,15); 
    int num=1;
    cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

    cout<<"\n\n\t\t\tChoose Your Piece\n\n\t\t\t[1] Knight 1\n\t\t\t[2] Knight 2\n\n\t\t\tSelect: ";
    cin>>select;

    if (select==1) {
        knight1(grid, 8, 8, randKR1, randKC1);
        king(grid,8,8);        
    }

    else if (select==2) {
        knight2(grid, 8, 8, randKR2, randKC2);
        king(grid,8,8);
    }

    while (!checkMate) {

        system("cls");

        //printing board
        cout<<"\n\n\n";
        for (int i=0;i<8;i++) {
            SetConsoleTextAttribute(h,15); 
            cout<<"\t\t   "<<i+1<<"  ";
            for (int j=0;j<8;j++) {
                
                if (grid[i][j]==89) {
                    SetConsoleTextAttribute(h,4);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==91) {
                    SetConsoleTextAttribute(h,5);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==92) {
                    SetConsoleTextAttribute(h,1);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==0) {
                    SetConsoleTextAttribute(h,15); 
                    cout<<box<<box<<"  ";   
                }

            }
            cout<<"\n\n";
        }
        SetConsoleTextAttribute(h,15); 
        num=1;
        cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

        cout<<"\n\n\t\t\tChoose Your Piece\n\n\t\t\t[1] Knight 1\n\t\t\t[2] Knight 2\n\n\t\t\tSelect: ";
        cin>>select;

        if (select==1) {
            checkMate=knight1(grid, 8, 8, randKR1, randKC1);
            if (!checkMate)
                king(grid,8,8); 
            else {
                checkmate();
                break;
            }    
        }

        if (select==2) {
            checkMate=knight2(grid, 8, 8, randKR2, randKC2);
            if (!checkMate)
                king(grid,8,8); 
            else {
                checkmate();
                break;
            }        
        }

    }

}

bool rock1(int grid[][8], int r, int c, int randRR1, int randRC1) {

    system("cls");
    char box=219;
    int current_BR, current_BC, row, col;
    bool checkMate=false;

    //finding ROCK's position
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==91) {
                row=i;
                col=j;
            }
        }
    }

    int kingrow, kingcol;
    //Finding Location of KING
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==89) {
                kingrow=i;
                kingcol=j;
            }
        }
    }

    //Finding Location of ROCK 2
    int b2row, b2col;
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==92) {
                b2row=i;
                b2col=j;
            }
        }
    }

    //vertical above
    int tempRow=row;
    while (tempRow >= 0) 
        grid[tempRow--][col]=93; 
        
    //vertical below
    tempRow=row;
    while (tempRow <= 7) 
        grid[tempRow++][col]=93; 

    //horizontal right
    int tempCol=col;
    while (tempCol <= 7) 
        grid[row][tempCol++]=93;  

    //horizontal left
    tempCol=col;
    while (tempCol >= 0) 
        grid[row][tempCol--]=93;

    //re-assigning position to ROCK 1
    grid[row][col]=91;

    //re-assigning position to KING
    grid[kingrow][kingcol]=89;

    //re-assigning position to ROCK 2
    grid[b2row][b2col]=92;

    //printing board
    cout<<"\n\n\n";
    for (int i=0;i<8;i++) {
        SetConsoleTextAttribute(h,15); 
        cout<<"\t\t   "<<i+1<<"  ";
        for (int j=0;j<8;j++) {
            
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==91) {
                SetConsoleTextAttribute(h,5);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==92) {
                SetConsoleTextAttribute(h,1);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==93) {
                SetConsoleTextAttribute(h,14); 
                cout<<box<<box<<"  ";   
            }

            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,15); 
                cout<<box<<box<<"  ";   
            }

        }
        cout<<"\n\n";
    }
    SetConsoleTextAttribute(h,15); 
    int num=1;
    cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

    cout<<"\n\n\t\t\tRow: ";
    cin>>current_BR;
    cout<<"\t\t\tColumn: ";
    cin>>current_BC;

    current_BR-- ; 
    current_BC --;

    if (current_BR==kingrow && current_BC==kingcol) 
        checkMate=true;

    //checking for out of range inputs
    while (grid[current_BR][current_BC]!=93 && !checkMate) {

        system("cls");

        //printing board
        cout<<"\n\n\n";
        for (int i=0;i<8;i++) {
            SetConsoleTextAttribute(h,15); 
            cout<<"\t\t   "<<i+1<<"  ";
            for (int j=0;j<8;j++) {
                
                if (grid[i][j]==89) {
                    SetConsoleTextAttribute(h,4);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==91) {
                    SetConsoleTextAttribute(h,5);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==92) {
                    SetConsoleTextAttribute(h,1);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==93) {
                    SetConsoleTextAttribute(h,14); 
                    cout<<box<<box<<"  ";   
                }

                if (grid[i][j]==0) {
                    SetConsoleTextAttribute(h,15); 
                    cout<<box<<box<<"  ";   
                }

            }
            cout<<"\n\n";
        }
        SetConsoleTextAttribute(h,15); 
        int num=1;
        cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

        SetConsoleTextAttribute(h,15);
        cout<<"\n\n\n\t\t\tOut of Range. Try Again\n";
        cout<<"\n\n\t\t\tRow: ";
        cin>>current_BR;
        cout<<"\t\t\tColumn: ";
        cin>>current_BC;

        current_BR-- ; current_BC --;

        if (current_BR==kingrow && current_BC==kingcol) {
            checkMate=true;
            break;
        }
    }

    //changing position
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==91)
                grid[i][j]=0;
        }
    }
    grid[current_BR][current_BC]=91;

    if (!checkMate) {

    //clearing possible moves
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==93) 
                grid[i][j]=0;
        }
    }

    //printing board
    cout<<"\n\n\n";
    for (int i=0;i<8;i++) {
        SetConsoleTextAttribute(h,15); 
        cout<<"\t\t   "<<i+1<<"  ";
        for (int j=0;j<8;j++) {
            
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==91) {
                SetConsoleTextAttribute(h,5);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==92) {
                SetConsoleTextAttribute(h,1);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,15); 
                cout<<box<<box<<"  ";   
            }

        }
        cout<<"\n\n";
    }
    SetConsoleTextAttribute(h,15); 
    num=1;
    cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

    }

    return checkMate;

}

bool rock2(int grid[][8], int r, int c, int randRR2, int randRC2) {

    system("cls");
    char box=219;
    int current_BR, current_BC, row, col;
    bool checkMate=false;

    //finding ROCK's position
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==92) {
                row=i;
                col=j;
            }
        }
    }

    int kingrow, kingcol;
    //Finding Location of KING
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==89) {
                kingrow=i;
                kingcol=j;
            }
        }
    }

    //Finding Location of ROCK 1
    int b1row, b1col;
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==91) {
                b1row=i;
                b1col=j;
            }
        }
    }

    //vertical above
    int tempRow=row;
    while (tempRow >= 0) 
        grid[tempRow--][col]=94; 
        
    //vertical below
    tempRow=row;
    while (tempRow <= 7) 
        grid[tempRow++][col]=94; 

    //horizontal right
    int tempCol=col;
    while (tempCol <= 7) 
        grid[row][tempCol++]=94;  

    //horizontal left
    tempCol=col;
    while (tempCol >= 0) 
        grid[row][tempCol--]=94;

    //re-assigning position to ROCK 2
    grid[row][col]=92;  

    //re-assigning position to KING
    grid[kingrow][kingcol]=89;

    //re-assigning position to ROCK 1
    grid[b1row][b1col]=91;

    //printing board
    cout<<"\n\n\n";
    for (int i=0;i<8;i++) {
        SetConsoleTextAttribute(h,15); 
        cout<<"\t\t   "<<i+1<<"  ";
        for (int j=0;j<8;j++) {
            
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==91) {
                SetConsoleTextAttribute(h,5);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==92) {
                SetConsoleTextAttribute(h,1);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==94) {
                SetConsoleTextAttribute(h,14); 
                cout<<box<<box<<"  ";   
            }

            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,15); 
                cout<<box<<box<<"  ";   
            }

        }
        cout<<"\n\n";
    }
    SetConsoleTextAttribute(h,15); 
    int num=1;
    cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

    cout<<"\n\n\t\t\tRow: ";
    cin>>current_BR;
    cout<<"\t\t\tColumn: ";
    cin>>current_BC;

    current_BR-- ; 
    current_BC --;

    if (current_BR==kingrow && current_BC==kingcol) 
        checkMate=true;

    //checking for out of range inputs
    while (grid[current_BR][current_BC]!=94 && !checkMate) {

        system("cls");

        //printing board
        cout<<"\n\n\n";
        for (int i=0;i<8;i++) {
            SetConsoleTextAttribute(h,15); 
            cout<<"\t\t   "<<i+1<<"  ";
            for (int j=0;j<8;j++) {
                
                if (grid[i][j]==89) {
                    SetConsoleTextAttribute(h,4);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==91) {
                    SetConsoleTextAttribute(h,5);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==92) {
                    SetConsoleTextAttribute(h,1);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==94) {
                    SetConsoleTextAttribute(h,14); 
                    cout<<box<<box<<"  ";   
                }

                if (grid[i][j]==0) {
                    SetConsoleTextAttribute(h,15); 
                    cout<<box<<box<<"  ";   
                }

            }
            cout<<"\n\n";
        }
        SetConsoleTextAttribute(h,15); 
        int num=1;
        cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

        SetConsoleTextAttribute(h,15);
        cout<<"\n\n\n\t\t\tOut of Range. Try Again\n";
        cout<<"\n\n\t\t\tRow: ";
        cin>>current_BR;
        cout<<"\t\t\tColumn: ";
        cin>>current_BC;

        current_BR-- ; current_BC --;

        if (current_BR==kingrow && current_BC==kingcol) {
            checkMate=true;
            break;
        }
    }

    //changing position
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==92)
                grid[i][j]=0;
        }
    }
    grid[current_BR][current_BC]=92;

    if (!checkMate) {

    //clearing possible moves
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==94) 
                grid[i][j]=0;
        }
    }

    //printing board
    cout<<"\n\n\n";
    for (int i=0;i<8;i++) {
        SetConsoleTextAttribute(h,15); 
        cout<<"\t\t   "<<i+1<<"  ";
        for (int j=0;j<8;j++) {
            
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==91) {
                SetConsoleTextAttribute(h,5);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==92) {
                SetConsoleTextAttribute(h,1);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,15); 
                cout<<box<<box<<"  ";   
            }

        }
        cout<<"\n\n";
    }
    SetConsoleTextAttribute(h,15); 
    num=1;
    cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

    }

    return checkMate;


}

void rock() {

    loadingbar();

    srand(time(NULL));

    int randKingRow=rand()%6 , randKingCol=rand()%6;
    int randRR1=rand()%6, randRC1=rand()%6;
    int randRR2=rand()%6, randRC2=rand()%6;

    int select, count=0;
    int grid[8][8]={0};
    char box=219;
    bool checkMate=false;

    //assigning random values
    if (count==0) {
        //random position KING
        grid[randKingRow][randKingCol]=89;

        //random value to ROCK 1
        grid[randRR1][randRC1]=91;

        //random value to ROCK 2
        grid[randRR2][randRC2]=92;

        count++;
    }

    //printing board
    cout<<"\n\n\n";
    for (int i=0;i<8;i++) {
        SetConsoleTextAttribute(h,15); 
        cout<<"\t\t   "<<i+1<<"  ";
        for (int j=0;j<8;j++) {
            
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==91) {
                SetConsoleTextAttribute(h,5);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==92) {
                SetConsoleTextAttribute(h,1);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,15); 
                cout<<box<<box<<"  ";   
            }

        }
        cout<<"\n\n";
    }
    SetConsoleTextAttribute(h,15); 
    int num=1;
    cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;


    cout<<"\n\n\t\t\tChoose Your Piece\n\n\t\t\t[1] Rock 1\n\t\t\t[2] Rock 2\n\n\t\t\tSelect: ";
    cin>>select;

    if (select==1) {
        rock1(grid, 8, 8, randRR1, randRC1);
        king(grid,8,8);        
    }

    else if (select==2) {
        rock2(grid, 8, 8, randRR2, randRC2);
        king(grid,8,8);
    }

    while (!checkMate) {

        system("cls");

        //printing board
        cout<<"\n\n\n";
        for (int i=0;i<8;i++) {
            SetConsoleTextAttribute(h,15); 
            cout<<"\t\t   "<<i+1<<"  ";
            for (int j=0;j<8;j++) {
                
                if (grid[i][j]==89) {
                    SetConsoleTextAttribute(h,4);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==91) {
                    SetConsoleTextAttribute(h,5);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==92) {
                    SetConsoleTextAttribute(h,1);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==0) {
                    SetConsoleTextAttribute(h,15); 
                    cout<<box<<box<<"  ";   
                }

            }
            cout<<"\n\n";
        }
        SetConsoleTextAttribute(h,15); 
        num=1;
        cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

        cout<<"\n\n\t\t\tChoose Your Piece\n\n\t\t\t[1] Rock 1\n\t\t\t[2] Rock 2\n\n\t\t\tSelect: ";
        cin>>select;

        if (select==1) {
            checkMate=rock1(grid, 8, 8, randRR1, randRC1);
            if (!checkMate)
                king(grid,8,8); 
            else {
                checkmate();
                break;
            }    
        }

        if (select==2) {
            checkMate=rock2(grid, 8, 8, randRR2, randRC2);
            if (!checkMate)
                king(grid,8,8); 
            else {
                checkmate();
                break;
            }        
        }

    }

}

void king2(int grid[][8], int r, int c) {

    system("cls");

    int current_BC, current_BR, row, col;
    char box=219;

    //Finding Location of QUEEN
    int b1row, b1col;
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==91) {
                b1row=i;
                b1col=j;
            }
        }
    }

    //finding KING's position
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==89) {
                row=i;
                col=j;
            }
        }
    }

    //vertical above
    if (row>0)
        grid[row-1][col]=90;
    
    //vertical below
    if (row<7)
        grid[row+1][col]=90;

    //horizontal right
    if (col<7)
        grid[row][col+1]=90;
  
    //horizontal left
    if (col>0)
        grid[row][col-1]=90;
    
    //North-West
    if (row>0 && col>0)
        grid[row-1][col-1]=90;

    //North-East
    if (row>0 && col<7)
        grid[row-1][col+1]=90;    

    //South-West
    if (row<7 && col>0)
        grid[row+1][col-1]=90;

    //South-East
    if (row<7 && col<7)
        grid[row+1][col+1]=90;

    //re-assigning position to QUEEN
    grid[b1row][b1col]=91;

    //printing board
    cout<<"\n\n\n";
    for (int i=0;i<8;i++) {
        SetConsoleTextAttribute(h,15); 
        cout<<"\t\t   "<<i+1<<"  ";
        for (int j=0;j<8;j++) {
            
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==91) {
                SetConsoleTextAttribute(h,5);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==90) {
                SetConsoleTextAttribute(h,14); 
                cout<<box<<box<<"  ";   
            }

            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,15); 
                cout<<box<<box<<"  ";   
            }

        }
        cout<<"\n\n";
    }
    SetConsoleTextAttribute(h,15); 
    int num=1;
    cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

    cout<<"\n\n\t\t\tRow: ";
    cin>>current_BR;
    cout<<"\t\t\tColumn: ";
    cin>>current_BC;

    current_BR-- ; current_BC --;

    //checking for out of range inputs
    while (grid[current_BR][current_BC]!=90) {

        system("cls");

        //printing board
        cout<<"\n\n\n";
        for (int i=0;i<8;i++) {
            SetConsoleTextAttribute(h,15); 
            cout<<"\t\t   "<<i+1<<"  ";
            for (int j=0;j<8;j++) {
                
                if (grid[i][j]==89) {
                    SetConsoleTextAttribute(h,4);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==91) {
                    SetConsoleTextAttribute(h,5);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==92) {
                    SetConsoleTextAttribute(h,1);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==90) {
                    SetConsoleTextAttribute(h,14); 
                    cout<<box<<box<<"  ";   
                }

                if (grid[i][j]==0) {
                    SetConsoleTextAttribute(h,15); 
                    cout<<box<<box<<"  ";   
                }

            }
            cout<<"\n\n";
        }
        SetConsoleTextAttribute(h,15); 
        int num=1;
        cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

        SetConsoleTextAttribute(h,15);
        cout<<"\n\n\n\t\t\tOut of Range. Try Again\n";
        cout<<"\n\n\t\t\tRow: ";
        cin>>current_BR;
        cout<<"\t\t\tColumn: ";
        cin>>current_BC;

        current_BR-- ; current_BC --;
    }

    //changing position
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==89)
                grid[i][j]=0;
        }
    }
    grid[current_BR][current_BC]=89;

    //clearing possible moves
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==90) 
                grid[i][j]=0;
        }
    }

    //printing board
    cout<<"\n\n\n";
    for (int i=0;i<8;i++) {
        SetConsoleTextAttribute(h,15); 
        cout<<"\t\t   "<<i+1<<"  ";
        for (int j=0;j<8;j++) {
            
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==91) {
                SetConsoleTextAttribute(h,5);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,15); 
                cout<<box<<box<<"  ";   
            }

        }
        cout<<"\n\n";
    }
    SetConsoleTextAttribute(h,15); 
    num=1;
    cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;


}

bool queen(int grid[][8], int r, int c, int randQR, int randQC) {

    system("cls");
    char box=219;
    int current_BR, current_BC, row, col;
    bool checkMate=false;

    //finding QUEEN's position
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==91) {
                row=i;
                col=j;
            }
        }
    }

    int kingrow, kingcol;
    //Finding Location of KING
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==89) {
                kingrow=i;
                kingcol=j;
            }
        }
    }

    //vertical above
    int tempRow=row;
    while (tempRow >= 0) 
        grid[tempRow--][col]=93; 
        
    // //vertical below
    tempRow=row;
    while (tempRow <= 7) 
        grid[tempRow++][col]=93; 

    //horizontal right
    int tempCol=col;
    while (tempCol <= 7) 
        grid[row][tempCol++]=93;  

    //horizontal left
    tempCol=col;
    while (tempCol >= 0) 
        grid[row][tempCol--]=93; 


    //North-West
    tempRow=row, tempCol=col;
    while (tempRow >= 0 && tempCol >= 0) 
        grid[tempRow--][tempCol--]=93;

    //North-East
    tempRow=row, tempCol=col;
    while (tempRow >= 0 && tempCol <= 7) 
        grid[tempRow--][tempCol++]=93;

    //South-West
    tempRow=row, tempCol=col;
    while (tempRow <= 7 && tempCol >= 0) 
        grid[tempRow++][tempCol--]=93;

    //South-East
    tempRow=row, tempCol=col;
    while (tempRow <= 7 && tempCol <= 7) 
        grid[tempRow++][tempCol++]=93;

    //re-assigning position to QUEEN    
    grid[row][col]=91;

    //re-assigning position to KING
    grid[kingrow][kingcol]=89;

    //printing board
    cout<<"\n\n\n";
    for (int i=0;i<8;i++) {
        SetConsoleTextAttribute(h,15); 
        cout<<"\t\t   "<<i+1<<"  ";
        for (int j=0;j<8;j++) {
            
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==91) {
                SetConsoleTextAttribute(h,5);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==93) {
                SetConsoleTextAttribute(h,14); 
                cout<<box<<box<<"  ";   
            }

            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,15); 
                cout<<box<<box<<"  ";   
            }

        }
        cout<<"\n\n";
    }
    SetConsoleTextAttribute(h,15); 
    int num=1;
    cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

    cout<<"\n\n\t\t\tRow: ";
    cin>>current_BR;
    cout<<"\t\t\tColumn: ";
    cin>>current_BC;

    current_BR-- ; 
    current_BC--;

    if (current_BR==kingrow && current_BC==kingcol) 
        checkMate=true;

    //checking for out of range inputs
    while (grid[current_BR][current_BC]!=93 && !checkMate) {

        system("cls");

        //printing board
        cout<<"\n\n\n";
        for (int i=0;i<8;i++) {
            SetConsoleTextAttribute(h,15); 
            cout<<"\t\t   "<<i+1<<"  ";
            for (int j=0;j<8;j++) {
                
                if (grid[i][j]==89) {
                    SetConsoleTextAttribute(h,4);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==91) {
                    SetConsoleTextAttribute(h,5);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==92) {
                    SetConsoleTextAttribute(h,1);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==93) {
                    SetConsoleTextAttribute(h,14); 
                    cout<<box<<box<<"  ";   
                }

                if (grid[i][j]==0) {
                    SetConsoleTextAttribute(h,15); 
                    cout<<box<<box<<"  ";   
                }

            }
            cout<<"\n\n";
        }
        SetConsoleTextAttribute(h,15); 
        int num=1;
        cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

        SetConsoleTextAttribute(h,15);
        cout<<"\n\n\n\t\t\tOut of Range. Try Again\n";
        cout<<"\n\n\t\t\tRow: ";
        cin>>current_BR;
        cout<<"\t\t\tColumn: ";
        cin>>current_BC;

        current_BR-- ; current_BC --;

        if (current_BR==kingrow && current_BC==kingcol) {
            checkMate=true;
            break;
        }
    }

    //changing position
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==91)
                grid[i][j]=0;
        }
    }
    grid[current_BR][current_BC]=91;
    
    if (!checkMate) {

    //clearing possible moves
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (grid[i][j]==93) 
                grid[i][j]=0;
        }
    }

    //printing board
    cout<<"\n\n\n";
    for (int i=0;i<8;i++) {
        SetConsoleTextAttribute(h,15); 
        cout<<"\t\t   "<<i+1<<"  ";
        for (int j=0;j<8;j++) {
            
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==91) {
                SetConsoleTextAttribute(h,5);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,15); 
                cout<<box<<box<<"  ";   
            }

        }
        cout<<"\n\n";
    }
    SetConsoleTextAttribute(h,15); 
    num=1;
    cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

    }

    return checkMate;

}

void queenMenu() {

    loadingbar();

    srand(time(NULL));

    int randKingRow=rand()%6 , randKingCol=rand()%6;
    int randQR=rand()%6, randQC=rand()%6;

    int select, count=0;
    int grid[8][8]={0};
    char box=219;
    bool checkMate=false;

    //assigning random values
    if (count==0) {
        //random position KING
        grid[randKingRow][randKingCol]=89;

        //random value to QUEEN
        grid[randQR][randQC]=91;

        count++;
    }

    //printing board
    cout<<"\n\n\n";
    for (int i=0;i<8;i++) {
        SetConsoleTextAttribute(h,15); 
        cout<<"\t\t   "<<i+1<<"  ";
        for (int j=0;j<8;j++) {
            
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==91) {
                SetConsoleTextAttribute(h,5);
                cout<<box<<box<<"  ";
            }

            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,15); 
                cout<<box<<box<<"  ";   
            }

        }
        cout<<"\n\n";
    }
    SetConsoleTextAttribute(h,15); 
    int num=1;
    cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

    int counter=0;

    if (counter==0) {
        queen(grid, 8, 8, randQR, randQC);
        king2(grid,8,8);  
        counter++;
    }

    if (counter>0) {

        while (!checkMate) {

        system("cls");

        //printing board
        cout<<"\n\n\n";
        for (int i=0;i<8;i++) {
            SetConsoleTextAttribute(h,15); 
            cout<<"\t\t   "<<i+1<<"  ";
            for (int j=0;j<8;j++) {
                
                if (grid[i][j]==89) {
                    SetConsoleTextAttribute(h,4);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==91) {
                    SetConsoleTextAttribute(h,5);
                    cout<<box<<box<<"  ";
                }

                if (grid[i][j]==0) {
                    SetConsoleTextAttribute(h,15); 
                    cout<<box<<box<<"  ";   
                }

            }
            cout<<"\n\n";
        }
        SetConsoleTextAttribute(h,15); 
        num=1;
        cout<<"\t\t       "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num++<<"   "<<num;

        checkMate=queen(grid, 8, 8, randQR, randQC);

            if (!checkMate)
                king2(grid,8,8); 

            else {
                checkmate();
                break;
            }    
        }
    }

}

void menuSaveKing() {

    loadingbar();

    int menu;

    //printing menu
    cout<<"\n\n\n\t\t\t\tM E N U\n";
    cout<<"\n\n\t\tChoose Your Piece\n\n";
    cout<<"\t\t[1] Bishop (2x)\n\t\t[2] Knight (2x)\n\t\t[3] Rock (2x)\n\t\t[4] Queen\n\n\t\tSelect: ";
    cin>>menu;

    //menu check
    while (menu<1 || menu>4) {
        system("cls");
        cout<<"\n\t\t\tInvalid Input. Try Again\n";
        cout<<"\n\n\t\t\t\tM E N U\n";
        cout<<"\n\n\t\tChoose Your Piece\n\n";
        cout<<"\t\t[1] Bishop (2x)\n\t\t[2] Knight (2x)\n\t\t[3] Rock (2x)\n\t\t[4] Queen\n\n\t\tSelect: ";
        cin>>menu;
    }

    switch(menu) {
        case 1 : bishop();break;
        case 2 : knight();break;
        case 3 : rock();break;
        case 4 : queenMenu();break;
    }

}

int knightNM() {

    loadingbar();
    int row,col, select, count=0;
    int grid[8][8]={0};
    char box=219;

    //coloring chess board
    for (int i=0;i<8;i++) {
        count=0;
        for (int j=0;j<8;j++) {

            if (i%2==0) {
                if (count%2==0) {
                    grid[i][j]=0;
                    count++;              
                }
                else if (count%2!=0) {
                    grid[i][j]=1;  
                    count++;               
                }
            }

            else if (i%2!=0) {
                if (count%2==0) {
                    grid[i][j]=1;
                    count++;              
                }
                else if (count%2!=0) {
                    grid[i][j]=0;  
                    count++;               
                }
            }
        }
    }

    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

    cout<<"\n\n\t\t\tEnter Initial Position";

    cout<<"\n\n\t\t\tRow: ";
    cin>>row;

    //row check
    while (row<1 || row>8) {
        
        system("cls");
        cout<<"\n\n\t\t\tEnter Initial Position";
        cout<<"\n\n\t\t\tInvalid Row. Try Again: ";
        cin>>row;        

    }

    cout<<"\t\t\tColumn: ";
    cin>>col;

    //col check
    while (col<1 || col>8) {
        
        system("cls");
        cout<<"\n\n\t\t\tEnter Initial Position";
        cout<<"\n\n\t\t\tRow: "<<row;
        cout<<"\n\t\t\tInvalid Column. Try Again: ";
        cin>>col;        

    }

    int userRow=row, userCol=col;

    row-=1; col-=1;

    //Above-right 1
    if (row >= 2 && col < 7)
        grid[row-2][col+1]=90;

    //Above-right 2
    if (row >= 1 && col <= 5)
        grid[row-1][col+2]=90;

    //Above-left 1
    if (row >= 2 && col > 0)
        grid[row-2][col-1]=90;

    //Above-left 2
    if (row >= 1 && col >= 2)
        grid[row-1][col-2]=90;

    //Below-right 1
    if (row <= 5 && col < 7)
        grid[row+2][col+1]=90;

    //Below-right 2
    if (row <= 6 && col <= 5)
        grid[row+1][col+2]=90;

    //Below-left 1
    if (row <= 5 && col > 0)
        grid[row+2][col-1]=90; 

    //Below-left 2
    if (row <= 6 && col >= 2)
        grid[row+1][col-2]=90; 

    //initial position
    grid[row][col]=89;    

    cout<<"\n\n\n";

    //printing board
    for (int i=0;i<8;i++) {
        cout<<"\t\t\t";
        for (int j=0;j<8;j++) {
         
            if (grid[i][j]==1) {
                SetConsoleTextAttribute(h,15); //white
                cout<<box<<box<<"  ";                       
            }
         
            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,0); //black
                cout<<box<<box<<"  ";                                   
            }
         
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,14);
                cout<<box<<box<<"  ";                   
            }

            if (grid[i][j]==90) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";     
            }

        }
        cout<<"\n\n";
    }

    SetConsoleTextAttribute(h,15);
    cout<<"\n\t\tInitial Position ";
    if (1) {
        SetConsoleTextAttribute(h,14);
        cout<<" "<<box<<box;
    }

    SetConsoleTextAttribute(h,15);
    cout<<"\tPossible Movements ";
    if (1) {
        SetConsoleTextAttribute(h,4);
        cout<<" "<<box<<box;
    }

    SetConsoleTextAttribute(h,15);
    cout<<"\n\n\n\t\t\tPlay Again?\n\n\t\t\t[1] Yes\n\t\t\t[2] No\n\n\t\t\tSelect: ";  
    cin>>select;

    //select check
    while (select<1 || select>2 ) {

        system("cls");

        cout<<"\n\n\t\t\tEnter Initial Position";

        cout<<"\n\n\t\t\tRow: "<<userRow;
        cout<<"\n\t\t\tColumn: "<<userCol;

        cout<<"\n\n\n";

        //printing board
        for (int i=0;i<8;i++) {
            cout<<"\t\t\t";
            for (int j=0;j<8;j++) {
            
                if (grid[i][j]==1) {
                    SetConsoleTextAttribute(h,15); //white
                    cout<<box<<box<<"  ";                       
                }
            
                if (grid[i][j]==0) {
                    SetConsoleTextAttribute(h,0); //black
                    cout<<box<<box<<"  ";                                   
                }
            
                if (grid[i][j]==89) {
                    SetConsoleTextAttribute(h,14);
                    cout<<box<<box<<"  ";                   
                }

                if (grid[i][j]==90) {
                    SetConsoleTextAttribute(h,4);
                    cout<<box<<box<<"  ";     
                }

            }
            cout<<"\n\n";
        }

        SetConsoleTextAttribute(h,15);
        cout<<"\n\t\tInitial Position ";
        if (1) {
            SetConsoleTextAttribute(h,14);
            cout<<" "<<box<<box;
        }

        SetConsoleTextAttribute(h,15);
        cout<<"\tPossible Movements ";
        if (1) {
            SetConsoleTextAttribute(h,4);
            cout<<" "<<box<<box;
        }

        SetConsoleTextAttribute(h,15);
        cout<<"\n\n\n\t\t\tPlay Again?\n\n\t\t\t[1] Yes\n\t\t\t[2] No\n\n\t\t\tInvalid Input. Try Again: ";  
        cin>>select;

    }

    return select;

}

int bishopNM() {
    loadingbar();
    int row,col, select, count=0;
    int grid[8][8]={0};
    char box=219;

    //coloring chess board
    for (int i=0;i<8;i++) {
        count=0;
        for (int j=0;j<8;j++) {

            if (i%2==0) {
                if (count%2==0) {
                    grid[i][j]=0;
                    count++;              
                }
                else if (count%2!=0) {
                    grid[i][j]=1;  
                    count++;               
                }
            }

            else if (i%2!=0) {
                if (count%2==0) {
                    grid[i][j]=1;
                    count++;              
                }
                else if (count%2!=0) {
                    grid[i][j]=0;  
                    count++;               
                }
            }
        }
    }


    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

    system("cls");

    cout<<"\n\n\t\t\tEnter Initial Position";

    cout<<"\n\n\t\t\tRow: ";
    cin>>row;

    //row check
    while (row<1 || row>8) {
        
        system("cls");
        cout<<"\n\n\t\t\tEnter Initial Position";
        cout<<"\n\n\t\t\tInvalid Row. Try Again: ";
        cin>>row;        

    }

    cout<<"\t\t\tColumn: ";
    cin>>col;

    //col check
    while (col<1 || col>8) {
        
        system("cls");
        cout<<"\n\n\t\t\tEnter Initial Position";
        cout<<"\n\n\t\t\tRow: "<<row;
        cout<<"\n\t\t\tInvalid Column. Try Again: ";
        cin>>col;        

    }

    int userRow=row, userCol=col;

    row-=1; col-=1;

    //North-West
    int tempRow=row, tempCol=col;
    while (tempRow >= 0 && tempCol >= 0) 
        grid[tempRow--][tempCol--]=90;

    //North-East
    tempRow=row, tempCol=col;
    while (tempRow >= 0 && tempCol <= 7) 
        grid[tempRow--][tempCol++]=90;

    //South-West
    tempRow=row, tempCol=col;
    while (tempRow <= 7 && tempCol >= 0) 
        grid[tempRow++][tempCol--]=90;

    //South-East
    tempRow=row, tempCol=col;
    while (tempRow <= 7 && tempCol <= 7) 
        grid[tempRow++][tempCol++]=90;

    //initial position
    grid[row][col]=89;    

    cout<<"\n\n\n";

    //printing board
    for (int i=0;i<8;i++) {
        cout<<"\t\t\t";
        for (int j=0;j<8;j++) {
         
            if (grid[i][j]==1) {
                SetConsoleTextAttribute(h,15); //white
                cout<<box<<box<<"  ";                       
            }
         
            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,0); //black
                cout<<box<<box<<"  ";                                   
            }
         
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,14);
                cout<<box<<box<<"  ";                   
            }

            if (grid[i][j]==90) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";     
            }

        }
        cout<<"\n\n";
    }

    SetConsoleTextAttribute(h,15);
    cout<<"\n\t\tInitial Position ";
    if (1) {
        SetConsoleTextAttribute(h,14);
        cout<<" "<<box<<box;
    }

    SetConsoleTextAttribute(h,15);
    cout<<"\tPossible Movements ";
    if (1) {
        SetConsoleTextAttribute(h,4);
        cout<<" "<<box<<box;
    }

    SetConsoleTextAttribute(h,15);
    cout<<"\n\n\n\t\t\tPlay Again?\n\n\t\t\t[1] Yes\n\t\t\t[2] No\n\n\t\t\tSelect: ";  
    cin>>select;

    //select check
    while (select<1 || select>2 ) {

        system("cls");

        cout<<"\n\n\t\t\tEnter Initial Position";

        cout<<"\n\n\t\t\tRow: "<<userRow;
        cout<<"\n\t\t\tColumn: "<<userCol;

        cout<<"\n\n\n";

        //printing board
        for (int i=0;i<8;i++) {
            cout<<"\t\t\t";
            for (int j=0;j<8;j++) {
            
                if (grid[i][j]==1) {
                    SetConsoleTextAttribute(h,15); //white
                    cout<<box<<box<<"  ";                       
                }
            
                if (grid[i][j]==0) {
                    SetConsoleTextAttribute(h,0); //black
                    cout<<box<<box<<"  ";                                   
                }
            
                if (grid[i][j]==89) {
                    SetConsoleTextAttribute(h,14);
                    cout<<box<<box<<"  ";                   
                }

                if (grid[i][j]==90) {
                    SetConsoleTextAttribute(h,4);
                    cout<<box<<box<<"  ";     
                }

            }
            cout<<"\n\n";
        }

        SetConsoleTextAttribute(h,15);
        cout<<"\n\t\tInitial Position ";
        if (1) {
            SetConsoleTextAttribute(h,14);
            cout<<" "<<box<<box;
        }

        SetConsoleTextAttribute(h,15);
        cout<<"\tPossible Movements ";
        if (1) {
            SetConsoleTextAttribute(h,4);
            cout<<" "<<box<<box;
        }

        SetConsoleTextAttribute(h,15);
        cout<<"\n\n\n\t\t\tPlay Again?\n\n\t\t\t[1] Yes\n\t\t\t[2] No\n\n\t\t\tInvalid Input. Try Again: ";  
        cin>>select;

    }

    return select;

}

int rockNM() {

    loadingbar();
    int row,col, select, count=0;
    int grid[8][8]={0};
    char box=219;

    //coloring chess board
    for (int i=0;i<8;i++) {
        count=0;
        for (int j=0;j<8;j++) {

            if (i%2==0) {
                if (count%2==0) {
                    grid[i][j]=0;
                    count++;              
                }
                else if (count%2!=0) {
                    grid[i][j]=1;  
                    count++;               
                }
            }

            else if (i%2!=0) {
                if (count%2==0) {
                    grid[i][j]=1;
                    count++;              
                }
                else if (count%2!=0) {
                    grid[i][j]=0;  
                    count++;               
                }
            }
        }
    }

    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

    cout<<"\n\n\t\t\tEnter Initial Position";

    cout<<"\n\n\t\t\tRow: ";
    cin>>row;

    //row check
    while (row<1 || row>8) {
        
        system("cls");
        cout<<"\n\n\t\t\tEnter Initial Position";
        cout<<"\n\n\t\t\tInvalid Row. Try Again: ";
        cin>>row;        

    }

    cout<<"\t\t\tColumn: ";
    cin>>col;

    //col check
    while (col<1 || col>8) {
        
        system("cls");
        cout<<"\n\n\t\t\tEnter Initial Position";
        cout<<"\n\n\t\t\tRow: "<<row;
        cout<<"\n\t\t\tInvalid Column. Try Again: ";
        cin>>col;        

    }

    int userRow=row, userCol=col;

    row-=1; col-=1;

    //vertical above
    int tempRow=row;
    while (tempRow >= 0) 
        grid[tempRow--][col]=90; 
        
    //vertical below
    tempRow=row;
    while (tempRow <= 7) 
        grid[tempRow++][col]=90; 

    //horizontal right
    int tempCol=col;
    while (tempCol <= 7) 
        grid[row][tempCol++]=90;  

    //horizontal left
    tempCol=col;
    while (tempCol >= 0) 
        grid[row][tempCol--]=90;

    //initial position
    grid[row][col]=89;    

    cout<<"\n\n";
    //printing board
    for (int i=0;i<8;i++) {
        cout<<"\t\t\t";
        for (int j=0;j<8;j++) {
         
            if (grid[i][j]==1) {
                SetConsoleTextAttribute(h,15); //white
                cout<<box<<box<<"  ";                       
            }
         
            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,0); //black
                cout<<box<<box<<"  ";                                   
            }
         
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,14);
                cout<<box<<box<<"  ";                   
            }

            if (grid[i][j]==90) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";     
            }

        }
        cout<<"\n\n";
    }

    SetConsoleTextAttribute(h,15);
    cout<<"\n\t\tInitial Position ";
    if (1) {
        SetConsoleTextAttribute(h,14);
        cout<<" "<<box<<box;
    }

    SetConsoleTextAttribute(h,15);
    cout<<"\tPossible Movements ";
    if (1) {
        SetConsoleTextAttribute(h,4);
        cout<<" "<<box<<box;
    }

    SetConsoleTextAttribute(h,15);
    cout<<"\n\n\n\t\t\tPlay Again?\n\n\t\t\t[1] Yes\n\t\t\t[2] No\n\n\t\t\tSelect: ";  
    cin>>select;

    //select check
    while (select<1 || select>2 ) {

        system("cls");

        cout<<"\n\n\t\t\tEnter Initial Position";

        cout<<"\n\n\t\t\tRow: "<<userRow;
        cout<<"\n\t\t\tColumn: "<<userCol;

        cout<<"\n\n\n";
        //printing board
        for (int i=0;i<8;i++) {
            cout<<"\t\t\t";
            for (int j=0;j<8;j++) {
            
                if (grid[i][j]==1) {
                    SetConsoleTextAttribute(h,15); //white
                    cout<<box<<box<<"  ";                       
                }
            
                if (grid[i][j]==0) {
                    SetConsoleTextAttribute(h,0); //black
                    cout<<box<<box<<"  ";                                   
                }
            
                if (grid[i][j]==89) {
                    SetConsoleTextAttribute(h,14);
                    cout<<box<<box<<"  ";                   
                }

                if (grid[i][j]==90) {
                    SetConsoleTextAttribute(h,4);
                    cout<<box<<box<<"  ";     
                }

            }
            cout<<"\n\n";
        }

        SetConsoleTextAttribute(h,15);
        cout<<"\n\t\tInitial Position ";
        if (1) {
            SetConsoleTextAttribute(h,14);
            cout<<" "<<box<<box;
        }

        SetConsoleTextAttribute(h,15);
        cout<<"\tPossible Movements ";
        if (1) {
            SetConsoleTextAttribute(h,4);
            cout<<" "<<box<<box;
        }

        SetConsoleTextAttribute(h,15);
        cout<<"\n\n\n\t\t\tPlay Again?\n\n\t\t\t[1] Yes\n\t\t\t[2] No\n\n\t\t\tInvalid Input. Try Again: ";  
        cin>>select;

    }

    return select;

}

int kingNM() {

    loadingbar();

    int row,col, select, count=0;
    int grid[8][8]={0};
    char box=219;

    //coloring chess board
    for (int i=0;i<8;i++) {
        count=0;
        for (int j=0;j<8;j++) {

            if (i%2==0) {
                if (count%2==0) {
                    grid[i][j]=0;
                    count++;              
                }
                else if (count%2!=0) {
                    grid[i][j]=1;  
                    count++;               
                }
            }

            else if (i%2!=0) {
                if (count%2==0) {
                    grid[i][j]=1;
                    count++;              
                }
                else if (count%2!=0) {
                    grid[i][j]=0;  
                    count++;               
                }
            }
        }
    }

    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

    cout<<"\n\n\t\t\tEnter Initial Position";

    cout<<"\n\n\t\t\tRow: ";
    cin>>row;

    //row check
    while (row<1 || row>8) {
        
        system("cls");
        cout<<"\n\n\t\t\tEnter Initial Position";
        cout<<"\n\n\t\t\tInvalid Row. Try Again: ";
        cin>>row;        

    }

    cout<<"\t\t\tColumn: ";
    cin>>col;

    //col check
    while (col<1 || col>8) {
        
        system("cls");
        cout<<"\n\n\t\t\tEnter Initial Position";
        cout<<"\n\n\t\t\tRow: "<<row;
        cout<<"\n\t\t\tInvalid Column. Try Again: ";
        cin>>col;        

    }

    int userRow=row, userCol=col;

    row-=1; col-=1;

    //vertical above
    if (row>0)
        grid[row-1][col]=90;
    
    //vertical below
    if (row<7)
        grid[row+1][col]=90;

    //horizontal right
    if (col<7)
        grid[row][col+1]=90;
  
    //horizontal left
    if (col>0)
        grid[row][col-1]=90;
    
    //North-West
    if (row>0 && col>0)
        grid[row-1][col-1]=90;

    //North-East
    if (row>0 && col<7)
        grid[row-1][col+1]=90;    

    //South-West
    if (row<7 && col>0)
        grid[row+1][col-1]=90;

    //South-East
    if (row<7 && col<7)
        grid[row+1][col+1]=90;

    //initial position
    grid[row][col]=89;    

    cout<<"\n\n\n";

    //printing board
    for (int i=0;i<8;i++) {
        cout<<"\t\t\t";
        for (int j=0;j<8;j++) {
         
            if (grid[i][j]==1) {
                SetConsoleTextAttribute(h,15); //white
                cout<<box<<box<<"  ";                       
            }
         
            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,0); //black
                cout<<box<<box<<"  ";                                   
            }
         
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,14);
                cout<<box<<box<<"  ";                   
            }

            if (grid[i][j]==90) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";     
            }

        }
        cout<<"\n\n";
    }

    SetConsoleTextAttribute(h,15);
    cout<<"\n\t\tInitial Position ";
    if (1) {
        SetConsoleTextAttribute(h,14);
        cout<<" "<<box<<box;
    }

    SetConsoleTextAttribute(h,15);
    cout<<"\tPossible Movements ";
    if (1) {
        SetConsoleTextAttribute(h,4);
        cout<<" "<<box<<box;
    }

    SetConsoleTextAttribute(h,15);
    cout<<"\n\n\n\t\t\tPlay Again?\n\n\t\t\t[1] Yes\n\t\t\t[2] No\n\n\t\t\tSelect: ";  
    cin>>select;

    //select check
    while (select<1 || select>2 ) {

        system("cls");

        cout<<"\n\n\t\t\tEnter Initial Position";

        cout<<"\n\n\t\t\tRow: "<<userRow;
        cout<<"\n\t\t\tColumn: "<<userCol;

        cout<<"\n\n\n";

        //printing board
        for (int i=0;i<8;i++) {
            cout<<"\t\t\t";
            for (int j=0;j<8;j++) {
            
                if (grid[i][j]==1) {
                    SetConsoleTextAttribute(h,15); //white
                    cout<<box<<box<<"  ";                       
                }
            
                if (grid[i][j]==0) {
                    SetConsoleTextAttribute(h,0); //black
                    cout<<box<<box<<"  ";                                   
                }
            
                if (grid[i][j]==89) {
                    SetConsoleTextAttribute(h,14);
                    cout<<box<<box<<"  ";                   
                }

                if (grid[i][j]==90) {
                    SetConsoleTextAttribute(h,4);
                    cout<<box<<box<<"  ";     
                }

            }
            cout<<"\n\n";
        }

        SetConsoleTextAttribute(h,15);
        cout<<"\n\t\tInitial Position ";
        if (1) {
            SetConsoleTextAttribute(h,14);
            cout<<" "<<box<<box;
        }

        SetConsoleTextAttribute(h,15);
        cout<<"\tPossible Movements ";
        if (1) {
            SetConsoleTextAttribute(h,4);
            cout<<" "<<box<<box;
        }

        SetConsoleTextAttribute(h,15);
        cout<<"\n\n\n\t\t\tPlay Again?\n\n\t\t\t[1] Yes\n\t\t\t[2] No\n\n\t\t\tInvalid Input. Try Again: ";  
        cin>>select;

    }

    return select;

}

int queenNM() {

    loadingbar();

    int row,col, select, count=0;
    int grid[8][8]={0};
    char box=219;

    //coloring chess board
    for (int i=0;i<8;i++) {
        count=0;
        for (int j=0;j<8;j++) {

            if (i%2==0) {
                if (count%2==0) {
                    grid[i][j]=0;
                    count++;              
                }
                else if (count%2!=0) {
                    grid[i][j]=1;  
                    count++;               
                }
            }

            else if (i%2!=0) {
                if (count%2==0) {
                    grid[i][j]=1;
                    count++;              
                }
                else if (count%2!=0) {
                    grid[i][j]=0;  
                    count++;               
                }
            }
        }
    }

    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

    cout<<"\n\n\t\t\tEnter Initial Position";

    cout<<"\n\n\t\t\tRow: ";
    cin>>row;

    //row check
    while (row<1 || row>8) {
        
        system("cls");
        cout<<"\n\n\t\t\tEnter Initial Position";
        cout<<"\n\n\t\t\tInvalid Row. Try Again: ";
        cin>>row;        

    }

    cout<<"\t\t\tColumn: ";
    cin>>col;

    //col check
    while (col<1 || col>8) {
        
        system("cls");
        cout<<"\n\n\t\t\tEnter Initial Position";
        cout<<"\n\n\t\t\tRow: "<<row;
        cout<<"\n\t\t\tInvalid Column. Try Again: ";
        cin>>col;        

    }

    int userRow=row, userCol=col;

    row-=1; col-=1;

    //vertical above
    int tempRow=row;
    while (tempRow >= 0) 
        grid[tempRow--][col]=90; 
        
    //vertical below
    tempRow=row;
    while (tempRow <= 7) 
        grid[tempRow++][col]=90; 

    //horizontal right
    int tempCol=col;
    while (tempCol <= 7) 
        grid[row][tempCol++]=90;  

    //horizontal left
    tempCol=col;
    while (tempCol >= 0) 
        grid[row][tempCol--]=90; 


    //North-West
    tempRow=row, tempCol=col;
    while (tempRow >= 0 && tempCol >= 0) 
        grid[tempRow--][tempCol--]=90;

    //North-East
    tempRow=row, tempCol=col;
    while (tempRow >= 0 && tempCol <= 7) 
        grid[tempRow--][tempCol++]=90;

    //South-West
    tempRow=row, tempCol=col;
    while (tempRow <= 7 && tempCol >= 0) 
        grid[tempRow++][tempCol--]=90;

    //South-East
    tempRow=row, tempCol=col;
    while (tempRow <= 7 && tempCol <= 7) 
        grid[tempRow++][tempCol++]=90;

    //initial position
    grid[row][col]=89;    

    cout<<"\n\n\n";

    //printing board
    for (int i=0;i<8;i++) {
        cout<<"\t\t\t";
        for (int j=0;j<8;j++) {
         
            if (grid[i][j]==1) {
                SetConsoleTextAttribute(h,15); //white
                cout<<box<<box<<"  ";                       
            }
         
            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,0); //black
                cout<<box<<box<<"  ";                                   
            }
         
            if (grid[i][j]==89) {
                SetConsoleTextAttribute(h,14);
                cout<<box<<box<<"  ";                   
            }

            if (grid[i][j]==90) {
                SetConsoleTextAttribute(h,4);
                cout<<box<<box<<"  ";     
            }

        }
        cout<<"\n\n";
    }

    SetConsoleTextAttribute(h,15);
    cout<<"\n\t\tInitial Position ";
    if (1) {
        SetConsoleTextAttribute(h,14);
        cout<<" "<<box<<box;
    }

    SetConsoleTextAttribute(h,15);
    cout<<"\tPossible Movements ";
    if (1) {
        SetConsoleTextAttribute(h,4);
        cout<<" "<<box<<box;
    }

    SetConsoleTextAttribute(h,15);
    cout<<"\n\n\n\t\t\tPlay Again?\n\n\t\t\t[1] Yes\n\t\t\t[2] No\n\n\t\t\tSelect: ";  
    cin>>select;

    //select check
    while (select<1 || select>2 ) {

        system("cls");

        cout<<"\n\n\t\t\tEnter Initial Position";

        cout<<"\n\n\t\t\tRow: "<<userRow;
        cout<<"\n\t\t\tColumn: "<<userCol;

        cout<<"\n\n\n";

        //printing board
        for (int i=0;i<8;i++) {
            cout<<"\t\t\t";
            for (int j=0;j<8;j++) {
            
                if (grid[i][j]==1) {
                    SetConsoleTextAttribute(h,15); //white
                    cout<<box<<box<<"  ";                       
                }
            
                if (grid[i][j]==0) {
                    SetConsoleTextAttribute(h,0); //black
                    cout<<box<<box<<"  ";                                   
                }
            
                if (grid[i][j]==89) {
                    SetConsoleTextAttribute(h,14);
                    cout<<box<<box<<"  ";                   
                }

                if (grid[i][j]==90) {
                    SetConsoleTextAttribute(h,4);
                    cout<<box<<box<<"  ";     
                }

            }
            cout<<"\n\n";
        }

        SetConsoleTextAttribute(h,15);
        cout<<"\n\t\tInitial Position ";
        if (1) {
            SetConsoleTextAttribute(h,14);
            cout<<" "<<box<<box;
        }

        SetConsoleTextAttribute(h,15);
        cout<<"\tPossible Movements ";
        if (1) {
            SetConsoleTextAttribute(h,4);
            cout<<" "<<box<<box;
        }

        SetConsoleTextAttribute(h,15);
        cout<<"\n\n\n\t\t\tPlay Again?\n\n\t\t\t[1] Yes\n\t\t\t[2] No\n\n\t\t\tInvalid Input. Try Again: ";  
        cin>>select;

    }

    return select;
}

void end() {

    loadingbar();

    int row,col;
    int grid[8][8]={0};
    char box=219;

    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

    cout<<"\n\n";

    int count=0; 

    //coloring chess board
    for (int i=0;i<8;i++) {
        count=0;
        for (int j=0;j<8;j++) {

            if (i%2==0) {
                if (count%2==0) {
                    grid[i][j]=0;
                    count++;              
                }
                else if (count%2!=0) {
                    grid[i][j]=1;  
                    count++;               
                }
            }

            else if (i%2!=0) {
                if (count%2==0) {
                    grid[i][j]=1;
                    count++;              
                }
                else if (count%2!=0) {
                    grid[i][j]=0;  
                    count++;               
                }
            }
        }
    }

    cout<<"\n\n\n";  

    //printing chees board
    for (int i=0;i<8;i++) {
        cout<<"\t\t\t\t"; 

        for (int j=0;j<8;j++) {

            if (grid[i][j]==1) {
                SetConsoleTextAttribute(h,15); //white
                cout<<box<<box<<"  ";                 
            }
         
            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,0); //black
                cout<<box<<box<<"  ";                            
            }

        }
        cout<<"\n\n";
    }

    SetConsoleTextAttribute(h,15); //white
    cout<<"\n\n\t\t\t\t    THANK YOU FOR PLAYING\n";
    cout<<"\n\t\t\t\t\tG O O D - B Y E\n\n";

    Sleep(3000);
    system("cls");
    
}

void menuNextMove() {

    loadingbar();
    int menu; 

    //printing menu
    system("cls");
    cout<<"\n\n\n\t\t\t\t\tM E N U";
    cout<<"\n\n\t\t\t[1] King\n\t\t\t[2] Queen\n\t\t\t[3] Knight\n\t\t\t[4] Bishop\n\t\t\t[5] Rock\n";
    
    cout<<"\n\t\t\tSelect Your Piece: ";
    cin>>menu;

    //handling invalid menu input
    while (menu<1 || menu>5) {
        system("cls");
        cout<<"\n\n\t\t\t\tINVALID INPUT! TRY AGAIN";
        cout<<"\n\n\n\t\t\t\t\tM E N U";
        cout<<"\n\n\t\t\t[1] King\n\t\t\t[2] Queen\n\t\t\t[3] Knight\n\t\t\t[4] Bishop\n\t\t\t[5] Rock\n";
    
    
        cout<<"\n\t\t\tSelect Your Piece: ";
        cin>>menu;
    }

    int again;

    //function calling
    switch(menu) {
        case 1 : again=kingNM();break;
        case 2 : again=queenNM();break;
        case 3 : again=knightNM();break;
        case 4 : again=bishopNM();break;
        case 5 : again=rockNM();break;
    }

    //loop for playing again
    while (again==1) {

        loadingbar();
        int menu; 

        //printing menu
        system("cls");
        cout<<"\n\n\n\t\t\t\t\tM E N U";
        cout<<"\n\n\t\t\t[1] King\n\t\t\t[2] Queen\n\t\t\t[3] Knight\n\t\t\t[4] Bishop\n\t\t\t[5] Rock\n";
        
        cout<<"\n\t\t\tSelect Your Piece: ";
        cin>>menu;

        //handling invalid menu input
        while (menu<1 || menu>5) {
            system("cls");
            cout<<"\n\n\t\t\t\tINVALID INPUT! TRY AGAIN";
            cout<<"\n\n\n\t\t\t\t\tM E N U";
            cout<<"\n\n\t\t\t[1] King\n\t\t\t[2] Queen\n\t\t\t[3] Knight\n\t\t\t[4] Bishop\n\t\t\t[5] Rock\n";
        
        
            cout<<"\n\t\t\tSelect Your Piece: ";
            cin>>menu;
        }

        switch(menu) {
            case 1 : again=kingNM();break;
            case 2 : again=queenNM();break;
            case 3 : again=knightNM();break;
            case 4 : again=bishopNM();break;
            case 5 : again=rockNM();break;
        }

    }

    end();
}

void menu() {

    loadingbar();

    char menu;

    //printing menu
    cout<<"\n\n\n\t\t\t\tM E N U\n";
    cout<<"\n\n\t\tChoose Game Mode\n\n";
    cout<<"\t\t[1] Your Next Move\n\t\t[2] Save The King\n\n\t\tSelect: ";
    cin>>menu;

    //menu check
    while (menu!='1' && menu!='2') {
        system("cls");
        cout<<"\n\t\t\tInvalid Input. Try Again\n";
        cout<<"\n\n\t\t\t\tM E N U\n";
        cout<<"\n\n\t\tChoose Game Mode\n\n";
        cout<<"\t\t[1] Your Next Move\n\t\t[2] Save The King\n\n\t\tSelect: ";
        cin>>menu;
    }

    switch(menu) {
        case '1' : menuNextMove();break;
        case '2' : menuSaveKing();break;
    }


}

void start() {

    //clearing screen
    system("cls");

    int row,col;
    int grid[8][8]={0};
    char box=219;

    cout<<"\n\n"; 

    int count=0; 

    //coloring chess board
    for (int i=0;i<8;i++) {
        count=0;
        for (int j=0;j<8;j++) {

            if (i%2==0) {
                if (count%2==0) {
                    grid[i][j]=0;
                    count++;              
                }
                else if (count%2!=0) {
                    grid[i][j]=1;  
                    count++;               
                }
            }

            else if (i%2!=0) {
                if (count%2==0) {
                    grid[i][j]=1;
                    count++;              
                }
                else if (count%2!=0) {
                    grid[i][j]=0;  
                    count++;               
                }
            }
        }
    }


    cout<<"\n\n\n";  
    //printing chees board
    for (int i=0;i<8;i++) {
        cout<<"\t\t\t\t"; 

        for (int j=0;j<8;j++) {

            if (grid[i][j]==1) {
                SetConsoleTextAttribute(h,15); //white
                cout<<box<<box<<"  ";                 
            }
         
            if (grid[i][j]==0) {
                SetConsoleTextAttribute(h,0); //black
                cout<<box<<box<<"  ";                            
            }

        }
        cout<<"\n\n";
    }

    SetConsoleTextAttribute(h,15); 
    cout<<"\n\n\t\t\t\t\t  C H E S S\n";
    
    cout<<"\n\t\t\t\t   Press Any Key to Start ";
    char enter[20];
    cin.getline(enter, 20);

    //calling function
    menu();
}

int main () {

    start();    

    return 0;
}