#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream reader;
    ofstream writer;
    int status = 0;
    char znack;
    reader.open("pr10/vypoved.txt");
    writer.open("pr10/skutecne.txt");

    while((znack = reader.get())){
        if(znack == EOF) break;
        if(status == 0){
            if(znack == 32 || znack == '\n' || znack == '\t'){
                status = 1;
                //continue;
            }
            writer << znack;
        }else if(status == 1){ //mame mezeru
            if(znack == 110){
                status = 2;
                continue;
            }
            status = 0;
            writer << znack;
            //writer << " " << znack;
        }else if(status == 2){ //mame n
            status = 0;
            if(znack == 101){
                continue;
            }
            writer << "n" << znack;
        }
    }
    writer.close();
    reader.close();
}
