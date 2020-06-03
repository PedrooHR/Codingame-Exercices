#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int R; // number of rows.
    int C; // number of columns.
    int A; // number of rounds between the time the alarm countdown is activated and the time the alarm goes off.
    cin >> R >> C >> A; cin.ignore();

    stack <string> caminho;
    caminho.push("INIT");
    vector <int> tiles;
    tiles.resize(R * C);
    bool done = false;
    // game loop
    while (1) {
        int KR; // row where Kirk is located.
        int KC; // column where Kirk is located.
        cin >> KR >> KC; cin.ignore();
           vector <string> map;
        for (int i = 0; i < R; i++){
            string ROW;
            cin >> ROW; cin.ignore();
            map.push_back(ROW);
        }

        if (done) {
            if (caminho.top() != "INIT") {
                cout << caminho.top() << endl;
                caminho.pop();
            }
        } else {
            if (map[KR][KC] == 'C') {
                cout << caminho.top() << endl;
                caminho.pop();
                done = true;
            } else {
                cerr << tiles[KR * C + KC] << endl;
                switch (tiles[KR * C + KC]) {
                    case 0:
                        tiles[KR * C + KC]++;
                        if (0 <= KR-1 && KR-1 < R && 0 <= KC && KC < C) {
                            if (map[KR-1][KC] != '#' && caminho.top() != "UP") {
                                cout << "UP" << endl;
                                caminho.push("DOWN");
                                break;
                            }                    
                        }
                    case 1:
                        tiles[KR * C + KC]++;
                        if (0 <= KR && KR < R && 0 <= KC+1 && KC+1 < C) {
                            if (map[KR][KC+1] != '#' && caminho.top() != "RIGHT") {
                                cout << "RIGHT" << endl;
                                caminho.push("LEFT");
                                break;
                            }                    
                        }
                    case 2:
                        tiles[KR * C + KC]++;
                        if (0 <= KR+1 && KR+1 < R && 0 <= KC && KC < C) {
                            if (map[KR+1][KC] != '#' && caminho.top() !="DOWN") {
                                cout << "DOWN" << endl;
                                caminho.push("UP");
                                break;
                            }                    
                        }
                    case 3:
                        tiles[KR * C + KC]++;
                        if (0 <= KR && KR < R && 0 <= KC-1 && KC-1 < C) {
                            if (map[KR][KC-1] != '#' && caminho.top() != "LEFT") {
                                cout << "LEFT" << endl;
                                caminho.push("RIGHT");
                                break;
                            }                    
                        }
                    default:
                        cout << caminho.top() << endl;
                        caminho.pop();
                    break;            
                }
            }
        }
    }
}