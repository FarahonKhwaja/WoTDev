#include "ScriptMgr.h"

class LevelNPC : public CreatureScript
{
public:
	LevelNPC() : CreatureScript("LevelTwink") {}

	bool OnGossipHello(Player* plr, Creature* npc) override {
		if (plr->getLevel() != 19){
			plr->GetSession()->SendAreaTriggerMessage("You already used this NPC, you can't use it again !");
			plr->CLOSE_GOSSIP_MENU();
		}
		else {
			plr->ADD_GOSSIP_ITEM(3, "Level 39", GOSSIP_SENDER_MAIN, 1);
			plr->ADD_GOSSIP_ITEM(3, "Level 49", GOSSIP_SENDER_MAIN, 2);
			plr->ADD_GOSSIP_ITEM(3, "Level 79", GOSSIP_SENDER_MAIN, 3);
			plr->ADD_GOSSIP_ITEM(5, "I want to keep this level.", GOSSIP_SENDER_MAIN, 4);
			plr->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
		}
		return true;
	}
	bool OnGossipSelect(Player* plr, Creature* npc, uint32 sender, uint32 uiAction) {
		if (!plr)
			return false;

		plr->PlayerTalkClass->ClearMenus();

		switch (uiAction){
		case 1:
			plr->GiveLevel(39);
			plr->GetSession()->SendAreaTriggerMessage("You're now level 39.");
			break;
		case 2:
			plr->GiveLevel(49);
			plr->GetSession()->SendAreaTriggerMessage("You're now level 49.");
			break;
		case 3:
			plr->GiveLevel(79);
			plr->GetSession()->SendAreaTriggerMessage("You're now level 79.");
			break;
		case 4:
			plr->CLOSE_GOSSIP_MENU();
			break;
		}
		plr->CLOSE_GOSSIP_MENU();
		return true;
	}
};
void AddSC_LevelNPC(){
	new LevelNPC();
}