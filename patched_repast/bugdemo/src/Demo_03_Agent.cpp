/* Demo_03_Agent.cpp */

#include "Demo_03_Agent.h"
#include <iostream>

RepastHPCDemoAgent::RepastHPCDemoAgent(repast::AgentId id): id_(id) { }

RepastHPCDemoAgent::RepastHPCDemoAgent(repast::AgentId id, unsigned int counter): id_(id), counter_(counter){ }

RepastHPCDemoAgent::~RepastHPCDemoAgent(){ }


void RepastHPCDemoAgent::set(int currentRank, unsigned int counter){
    id_.currentRank(currentRank);
    counter_ = counter;
}

void RepastHPCDemoAgent::play(repast::SharedContext<RepastHPCDemoAgent>* context){
	
    // Print the value of the counter, increment it
    std::cout << getId() 
              << " counter value: "
              << counter_ << ",";
    counter_ += 1;
    std::cout << " incremented to "
              << counter_ << "\n";
	
}

void RepastHPCDemoAgent::move(repast::SharedDiscreteSpace<RepastHPCDemoAgent, repast::StrictBorders, repast::SimpleAdder<RepastHPCDemoAgent> >* space){

    // Walk to the right until the limit (9 is reached)
    std::vector<int> agentLoc;
    space->getLocation(id_, agentLoc);
    std::vector<int> agentNewLoc;
    agentNewLoc.push_back(agentLoc[0] + 1);
    agentNewLoc.push_back(agentLoc[1]);

    if (agentNewLoc[0] < 10) {
        space->moveTo(id_,agentNewLoc);
    }
}


/* Serializable Agent Package Data */

RepastHPCDemoAgentPackage::RepastHPCDemoAgentPackage(){ }

RepastHPCDemoAgentPackage::RepastHPCDemoAgentPackage(int _id, int _rank, int _type, int _currentRank, unsigned int _counter):
id(_id), rank(_rank), type(_type), currentRank(_currentRank), counter(_counter){ }
