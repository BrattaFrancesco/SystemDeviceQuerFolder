#include <iostream>
#include <string>
#include <set>

using namespace std;

struct Player{
    string name;
    int score;

    friend bool operator==(const Player& left, const Player& right)
    {
        return left.name == right.name;
    }
};


struct cmp {
    bool operator() (Player a, Player b) {
        if(a.name == b.name){
            return false;
        }else{
            if (a.score > b.score)
                return true;

            if ( a.score == b.score && a.name < b.name)
                return true;
            
            return false;
        }
    }
};

struct Leaderboard{
    private:
        set<Player, cmp> players;
    public:

        void addPlayer(const std::string& name, int score){
            Player p {name, score};
            players.insert(p);
        }
        void removePlayer(const std::string& name){
            Player p {name, 7};
            players.erase(p);
        }
        void updateScore(const std::string& name, int newScore){
            Player p {name, newScore};
            players.erase(p);
            players.insert(p);
        }
        void printTopPlayers(int n){
            auto i = players.begin();
            int j = 0;

            cout << "*******TOP " << n << " PLAYERS*******\n";
            while (j < n && i != players.end())
            {
                cout << i->name << " " << i->score << "\n";
                i++;
                j++;
            }
            cout << "***************************\n";
        }
};

int main(){
    Leaderboard l;

    l.addPlayer("Francesco", 5);
    l.addPlayer("Luigi", 3);
    l.addPlayer("Anna", 7);
    l.addPlayer("Maria", 1);
    l.addPlayer("Lucia", 7);
    
    l.printTopPlayers(5);

    l.removePlayer("Anna");

    l.printTopPlayers(5);

    l.updateScore("Lucia", 10);

    l.printTopPlayers(4);
}