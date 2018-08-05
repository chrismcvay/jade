#include "FootballTeam.h"

// Generic constructor. Initialize all the member variables here.
FootballTeam::FootballTeam() {
    mHomeWins = 0;
    mRoadWins = 0;
    mHomeTies = 0;
    mRoadTies = 0;
    mHomeLosses = 0;
    mRoadLosses = 0;
    mConference = Conference::AFC;
    mCity = "";
    mName = "";
}

FootballTeam::FootballTeam(Conference conference, string city, string name)
// This line says to call the constructor that has no arguments before
// continuing with this constructor. That's a good way to consolidate all
// the initialization of variables into one spot. Then you just have to
// worry about the specifics of _this_ constructor.
:FootballTeam() {
    mConference = conference;
    mCity = city;
    mName = name;
}

// Set a game score.
void FootballTeam::gameScore(int us, int them, bool homeGame) {
    if(homeGame) {
        // Way to read the below line:
        // (if statement) ? (execute on true answer) : (execute on false answer)
        // This is a shorter way of writing one statement if/else statements
        // If us > them, then increment homeWins, else if us < them, then
        // increment homeLosses, else increase homeTies
        us > them ? mHomeWins++ : us < them ? mHomeLosses++ : mHomeTies++;
    }
    else {
        us > them ? mRoadWins++ : us < them ? mRoadLosses++ : mRoadTies++;
    }
}

// Return string with team's home record
// A better function signature would be to pass in a string pointer
// and rely on the class to allocate space and return it.
// Even better is that the class doesn't return a function like this
// and it's up to the caller to print out variables the way it wants.
string FootballTeam::homeRecord() {
    char buffer[100]; // Hate this. No idea what the length will be ultimately.
    // snprintf is a more secure string formatting function that doesn't allow
    // buffer overruns - it will stop at 100 characters since that's what we
    // told it. In general, this whole thing isn't a great solution and is
    // full of what we'd call "code smell". It's technically ok for now, but 
    // is prone to causing errors later.
    snprintf(buffer, 100, "%d - %d - %d", mHomeWins, mHomeLosses, mHomeTies);
    string record = buffer;
    return record;
}

string FootballTeam::roadRecord() {
    char buffer[100]; // Hate this.
    snprintf(buffer, 100, "%d - %d - %d", mRoadWins, mRoadLosses, mRoadTies);
    string record = buffer;
    return record;
}

string FootballTeam::overallRecord() {
    char buffer[100]; // Hate this.
    snprintf(buffer, 100, "%d - %d - %d", 
            mRoadWins+mHomeWins, mRoadLosses+mHomeLosses, mRoadTies+mRoadTies);
    string record = buffer;
    return record;
}
