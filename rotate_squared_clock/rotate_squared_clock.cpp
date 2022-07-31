#include <iostream>
#include <utility>


using namespace std;


bool isCorner( pair<int, int> position, int size ){
    if( position.first == position.second )
        return true;
    if( position.first + position.second == size -1  )
        return true;
    return false;
}


void rotate( int size,  char** matrix ){
    int directions[4][2] = { {0,1},{1,0},{0,-1},{-1,0}};
    pair<int,int> currentPosition = {0,0};
    int currentDirection = 0;
    int lastValue = matrix[0][0];

    for( int i =0; i<size/2; i++ ){
        cout << endl << endl;
        currentPosition = {i,i};
        currentDirection = 0;
        lastValue = matrix[i][i];
        do{

            currentPosition.first +=  directions[ currentDirection ][ 0 ];
            currentPosition.second +=  directions[ currentDirection ][ 1 ];
            if( isCorner( currentPosition, size ) ) currentDirection++; 
            int temp = lastValue;
            lastValue = matrix[ currentPosition.first ][ currentPosition.second ];
            matrix[ currentPosition.first ][ currentPosition.second ] = temp;

        }while( currentPosition.first != i or currentPosition.second != i );

   }
//  matrix[ currentPosition.first ][ currentPosition.second ] = lastValue;

}


int main(){

   char** matrix;

   int size;
   cin >> size;

   matrix = (char**)malloc( size*sizeof(char*) );
   for( int i=0; i<size; i++ )
       matrix[i] = (char*)malloc( size*sizeof(char) );

    for( int i=0; i<size; i++ )
        for( int j=0; j<size; j++ )
            cin >> matrix[i][j];

    cout<<"antes:"<<endl;
    for( int i=0; i<size; i++ ){
        for( int j=0; j<size; j++ )
            cout << matrix[i][j];
         cout<<endl;
    }

    rotate( size, (char**)matrix );
    cout<<endl<<"depois:"<<endl;
    for( int i=0; i<size; i++ ){
        for( int j=0; j<size; j++ )
            cout << matrix[i][j];
         cout<<endl;
    }


return 0;
}
