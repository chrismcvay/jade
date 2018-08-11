//
//  Bunco.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Bunco.h"
#include <iostream>

namespace cs31
{
    Bunco::Bunco() : mRound( 0 )
    {

    }

    // stringify the game by stringifying the board
    std::string Bunco::display( std::string msg ) const
    {
        using namespace std;
        std::string s = mBoard.display();
        s = s + msg;

        if (gameIsOver())
        {
            if (determineGameOutcome() == TIEDGAME)
            {
                s = s + "\n\t\tBunco wound up tied!\n";
            }
            else if (determineGameOutcome() == HUMANWONGAME)
            {
                s = s + "\n\t\tyou won Bunco!\n";
            }
            else
            {
                s = s + "\n\t\tyou lost Bunco!\n";
            }
        }
        return( s );
    }

    // set the current round of play, notifying the board and each
    // player of the current round
    void Bunco::setRound( int round )
    {
        mRound = round;
        mBoard.setCurrentRound( round );
        mHuman.setRound(round);
        mComputer.setRound(round);
    }

    // let the human player play
    // when the amount is zero, the Die should be rolled for random play
    // when the amount is not zero, we are trying to cheat for testing
    // purposes.  in that case, this method should force a specific roll
    // amount.
    int Bunco::humanPlay( int amount )
    {
        int amountrolled = mHuman.roll(amount);
        return( amountrolled );
    }

    // let the computer player play
    // when the amount is zero, the Die should be rolled for random play
    // when the amount is not zero, we are trying to cheat for testing
    // purposes.  in that case, this method should force a specific roll
    // amount.
    int Bunco::computerPlay( int amount )
    {
        int amountrolled = mComputer.roll(amount);
        return( amountrolled );
    }

    // considering each player's score, determine the
    // winner of this round of play
    Bunco::ROUNDOUTCOME Bunco::determineRoundOutcome( )
    {
        ROUNDOUTCOME result = ROUNDOUTCOME::NOTDECIDED;

        if(mHuman.getScore() > mComputer.getScore()) {
            mBoard.markHumanAsWinner();
            result = ROUNDOUTCOME::HUMANWON;
        }
        else if(mComputer.getScore() > mHuman.getScore()) {
            mBoard.markComputerAsWinner();
            result = ROUNDOUTCOME::COMPUTERWON;
        }

        return( result );
    }

    // TODO: count up the number of won rounds by each player to determine
    // the game's outcome
    Bunco::GAMEOUTCOME  Bunco::determineGameOutcome( ) const
    {
        // stubbed out for now...
        GAMEOUTCOME result = GAMEOUTCOME::GAMENOTOVER;
        if(mRound <= 6) return result;

        int hWins = mBoard.countUpHumanRoundWins();
        int cWins = mBoard.countUpComputerRoundWins();

        hWins > cWins ? result = GAMEOUTCOME::HUMANWONGAME :
        cWins > hWins ? result = GAMEOUTCOME::COMPUTERWONGAME :
                        result = GAMEOUTCOME::TIEDGAME;
        return( result );
    }

    // is the game over?
    bool Bunco::gameIsOver() const
    {
        GAMEOUTCOME result = determineGameOutcome();
        return( result != GAMENOTOVER );
    }

}
