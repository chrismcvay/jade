#ifndef __FOOTBALLTEAM_H__
#define __FOOTBALLTEAM_H__

#include <string>
using namespace std;

class FootballTeam {
    public:
        enum Conference { NFC, AFC };
        FootballTeam();
        FootballTeam(Conference conference, string city, string name);

        // Return read-only access to enumeration setting.
        Conference getConference() { return mConference; }

        // Read-only access to private member variables
        string getCity()    { return mCity;         }
        string getName()    { return mName;         }
        int getHomeWins()   { return mHomeWins;     }
        int getHomeLosses() { return mHomeLosses;   }
        int getHomeTies()   { return mHomeTies;     }
        int getRoadWins()   { return mRoadWins;     }
        int getRoadLosses() { return mRoadLosses;   }
        int getRoadTies()   { return mRoadTies;     }

        void gameScore(int us, int them, bool homeGame);
        string homeRecord();
        string roadRecord();
        string overallRecord();

    protected:
    // No protected variables in this case, but I always found this to be a good
    // practice to include.
    private:
        Conference  mConference;
        string      mCity;
        string      mName;
        int         mHomeWins;
        int         mRoadWins;
        int         mHomeTies;
        int         mRoadTies;
        int         mHomeLosses;
        int         mRoadLosses;
};

#endif //__FOOTBALLTEAM_H__
