#pragma once
#include <vector>

struct IParticipant {
    virtual void broadcast(int value) = 0;
};

struct Mediator {
    void add(IParticipant* participant) {
        participants.push_back(participant);
    }
    void say(IParticipant* participant, int value) {
        for (auto p : participants) {
            if (p != participant) {
                p->broadcast(value);
            }
        }
    }
private:
    std::vector<IParticipant*> participants;
};


struct Participant : IParticipant {
    int value{0};
    Mediator& mediator;

    Participant(Mediator &mediator) : 
        mediator(mediator)
    {
        mediator.add(this);
    }

    void broadcast(int val) override {
        value += val;
    }

    void say(int value) {
        mediator.say(this, value);
    }
};