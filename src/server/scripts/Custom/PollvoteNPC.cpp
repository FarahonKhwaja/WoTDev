#include "ScriptMgr.h"

class PollvoteNPC : public CreatureScript
{
public:
	PollvoteNPC() : CreatureScript("PollVote") {}
	uint32 option1Pollvote;
	uint32 option2Pollvote;
	void setOption1Pollvote(uint32 option){ option1Pollvote = option; } //POLLVOTE WORLD OF TWINK
	void setOption2Pollvote(uint32 option){ option2Pollvote = option; } //POLLVOTE WORLD OF TWINK
	uint32 getOption1Pollvote(){ return option1Pollvote; }
	uint32 getOption2Pollvote(){ return option2Pollvote; }

	bool OnGossipHello(Player* plr, Creature* npc) override {
		if (plr->getPollvote() == false)
		{
			plr->ADD_GOSSIP_ITEM(3, "Option 1", GOSSIP_SENDER_MAIN, 1);
			plr->ADD_GOSSIP_ITEM(3, "Option 2", GOSSIP_SENDER_MAIN, 2);
			plr->ADD_GOSSIP_ITEM(3, "Show results", GOSSIP_SENDER_MAIN, 3);
			plr->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
		}
		else
		{
			plr->GetSession()->SendAreaTriggerMessage("You already voted for this poll !");
			plr->ADD_GOSSIP_ITEM(3, "Show results", GOSSIP_SENDER_MAIN, 3);
			plr->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
		}
		return true;
	}
	bool OnGossipSelect(Player* plr, Creature* npc, uint32 sender, uint32 uiAction) {
		if (!plr)
			return false;

		switch (uiAction){
		case 1:
			plr->PlayerTalkClass->ClearMenus();
			setOption1Pollvote(getOption1Pollvote() + 1);
			plr->GetSession()->SendAreaTriggerMessage("You voted for option 1.");
			plr->setPollvote(true);
			plr->ADD_GOSSIP_ITEM(1, "Show results", GOSSIP_SENDER_MAIN, 3);
			plr->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
			break;
		case 2:
			plr->PlayerTalkClass->ClearMenus();
			setOption2Pollvote(getOption2Pollvote() + 1);
			plr->GetSession()->SendAreaTriggerMessage("You voted for option 2.");
			plr->setPollvote(true);
			plr->ADD_GOSSIP_ITEM(1, "Show results", GOSSIP_SENDER_MAIN, 3);
			plr->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
			break;
		case 3:
			plr->PlayerTalkClass->ClearMenus();
			uint32 pv1 = getOption1Pollvote();
			uint32 pv2 = getOption2Pollvote();
			plr->ADD_GOSSIP_ITEM(1, "Option 1 : pv1", GOSSIP_SENDER_MAIN, 4);
			plr->ADD_GOSSIP_ITEM(1, "Option 2 : pv2", GOSSIP_SENDER_MAIN, 4);
			plr->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
			//plr->setPollvote(true);
			break;
		}
		plr->CLOSE_GOSSIP_MENU();
		return true;
	}
};
void AddSC_PollVote()
{
	new PollvoteNPC();
}