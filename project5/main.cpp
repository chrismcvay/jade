#include <iostream>
#include <cstdlib>
#include "FootballTeam.h"

bool betterRecord(FootballTeam f, FootballTeam g);
// Return random number between 0 and 49.
int RandomScore() { return rand() % 49; }
// Print some handy information about the team.
void PrintTeam(FootballTeam t) {
    cout << t.getCity() << " " << t.getName() << ": ";
    cout << (t.getConference() ? "AFC" : "NFC") << endl;
    cout << "Home Record: " << t.homeRecord() << endl;
    cout << "Road Record: " << t.roadRecord() << endl;
    cout << "Overall Record: " << t.overallRecord() << endl;
}
int main()
{
    srand(time(NULL));

    FootballTeam team1(FootballTeam::Conference::NFC, "Chicago", "Bears");
    FootballTeam team2(FootballTeam::Conference::AFC, "New York", "Jets");

    for(int i=0; i<17; i++) // Just make some random scores
    {
        team1.gameScore(RandomScore(), RandomScore(), i%2);
        team2.gameScore(RandomScore(), RandomScore(), i%2);
    }
    PrintTeam(team1);
    PrintTeam(team2);

    cout << "Team 1 better: " << (betterRecord(team1, team2) ? "Yes" : "No") << endl;
    return 0;
}

bool betterRecord(FootballTeam f, FootballTeam g) {
    int fHW = f.getHomeWins();
    int gHW = g.getHomeWins();
    int fHL = f.getHomeLosses();
    int gHL = g.getHomeLosses();
    int fHT = f.getHomeTies();
    int gHT = g.getHomeTies();
    int fRW = f.getRoadWins();
    int gRW = g.getRoadWins();
    int fRL = f.getRoadLosses();
    int gRL = g.getRoadLosses();
    int fRT = f.getRoadTies();
    int gRT = g.getRoadTies();
    int fTW = fHW+fRW;
    int gTW = gHW+gRW;
    int fTL = fHL+fRL;
    int gTL = gHL+gRL;
    int fTT = fHT+fRT;
    int gTT = gHT+gRT;

    if(fTW > gTW) return true;
    if(gTW > fTW) return false;

    if(fTL < gTL) return true;
    if(fTL > gTL) return false;

    return fTT > gTT;
}