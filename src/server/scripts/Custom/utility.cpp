#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "MapManager.h"
#include "Chat.h"
#include "Group.h"
#include "ArenaTeam.h"
#include "ArenaTeamMgr.h"


class utility_commandscript : public CommandScript
{
public:
    utility_commandscript() : CommandScript("utility_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand utilityCommandTable[] =
        {
            { "changerace",             rbac::RBAC_PERM_COMMAND_CHARACTER_CHANGERACE ,  false, &HandleChangeRaceCommand,           "", NULL },
			{ "changefaction",			rbac::RBAC_PERM_COMMAND_CHARACTER_CHANGEFACTION,  false, &HandleChangeFactionCommand,		"", NULL },
			{ "maxskills",			    rbac::RBAC_PERM_COMMAND_MAXSKILL,  false, &HandleMaxSkillsCommand,	    	"", NULL },
			{ "customize",			    rbac::RBAC_PERM_COMMAND_CHARACTER_CUSTOMIZE,  false, &HandleCustomizeCommand,	       	"", NULL },
            { NULL,             0,                   false, NULL,                               "", NULL }
        };
        static ChatCommand commandTable[] =
        {
            { "tools",           SEC_PLAYER,      true, NULL,                   "", utilityCommandTable },
            { "to",           SEC_PLAYER,      true, NULL,                   "", utilityCommandTable },
            { NULL,             0,                  false, NULL,                               "", NULL }
        };
        return commandTable;
    }

    static bool HandleChangeRaceCommand(ChatHandler* handler, const char* args)
    {

        Player* me = handler->GetSession()->GetPlayer();
		me->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
		handler->PSendSysMessage("Relog to change race of your character.");
        return true;
    }

    static bool HandleChangeFactionCommand(ChatHandler* handler, const char* args)
    {

        Player* me = handler->GetSession()->GetPlayer();
		me->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
		handler->PSendSysMessage("Relog to change faction of your character.");
        return true;
    }

	static bool HandleMaxSkillsCommand(ChatHandler* handler, char const* /*args*/)
    {
        Player* me=handler->GetSession()->GetPlayer();
        {
            handler->SendSysMessage("Your Weapon Skills are now maximized.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        // each skills that have max skill value dependent from level seted to current level max skill value
        me->UpdateSkillsToMaxSkillsForLevel();
        return true;
    }

	static bool HandleCustomizeCommand(ChatHandler* handler, const char* args)
    {

        Player* me = handler->GetSession()->GetPlayer();
		me->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
		handler->PSendSysMessage("Relog to customize your character.");
        return true;
    }

};

void AddSC_utility_commandscript()
{
    new utility_commandscript();
}
