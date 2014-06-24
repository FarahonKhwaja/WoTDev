/*
<--------------------------------------------------------------------------->
- Developer(s): JessiqueBA
- Complete: %100
- ScriptName: 'vipmall_security'
- Comment: Untested.
- Shared for:Emudevs by Synth
- Edited by FarahonKhwaja for World of Twink
<--------------------------------------------------------------------------->
*/

enum ForbiddenAreas
{
	AREA_VIP_MALL = 3817,  // Testing Zone
	AREA_VIP_ISLAND = 2317,  // South Seas (Tanaris)
	AREA_GM_ISLAND = 876,    // GM Island
	AREA_VIP_FJORD = 3981	//VIP World of Twink Zone
};

class vipmall_security : public PlayerScript
{
public:
	vipmall_security() : PlayerScript("vipmall_security") {}

	void OnUpdateZone(Player* player, uint32 newZone, uint32 newArea)
	{
		switch (newArea)
		{
		case AREA_VIP_MALL:
		case AREA_VIP_ISLAND:
		case AREA_VIP_FJORD:
			// if player is vip and reach the vipmall..
			if (player->GetSession()->GetSecurity() >= 1) // Or RBAC 'HasPermission(rbac::PERMISSION_NAME);'
				return;
			player->TeleportTo(571, 5804.140137, 624.760010, 647.760010, 1.64); // Teleport to Dalaran
			break;
		case AREA_GM_ISLAND:
			// Allow acces to GM island only for staff members
			if (player->GetSession()->GetSecurity() >= 2) // Or RBAC 'HasPermission(rbac::PERMISSION_NAME);'
				return;
			player->TeleportTo(571, 5804.140137, 624.760010, 647.760010, 1.64); // Teleport to Dalaran
			break;
		}
	}
};

void AddSC_vipmall_security()
{
	new vipmall_security();
}