// execution.cpp
//
// Copyright (C) 2001 Chris Laurel <claurel@shatters.net>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

#include "execution.h"

#include <utility>

namespace celestia::scripts
{

Execution::Execution(CommandSequence&& cmd, ExecutionEnvironment& _env) :
    commandSequence(std::move(cmd)),
    env(_env)
{
}


bool Execution::tick(double dt)
{
    // ignore the very first call to tick, because on windows dt may include the
    // time spent in the "Open File" dialog. Using commandTime < 0 as a flag
    // to recognize the first call:
    if (commandTime < 0.0)
    {
        commandTime = 0.0;
        return false;
    }

    while (dt > 0.0 && currentCommand < commandSequence.size())
    {
        Command* cmd = commandSequence[currentCommand].get();

        double timeLeft = cmd->getDuration() - commandTime;
        if (dt >= timeLeft)
        {
            cmd->process(env, cmd->getDuration(), timeLeft);
            dt -= timeLeft;
            commandTime = 0.0;
            currentCommand++;
        }
        else
        {
            commandTime += dt;
            cmd->process(env, commandTime, dt);
            dt = 0.0;
        }
    }

    return currentCommand == commandSequence.size();
}

}
