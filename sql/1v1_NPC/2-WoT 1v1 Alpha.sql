SET
@Entry = '89997';
DELETE FROM `creature_template` WHERE `entry`=@Entry;
insert into `creature_template` (`entry`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `health_mod`, `mana_mod`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `baseattacktime`, `family`, `ScriptName`, `type`)
values (@Entry, '342', '342', '342', '342', "WoT 1v1 Alpha", "Wot Dev", '1', '1', '35', '1', '2.50', '8.00', '1', '0', '1', '1', '100', '0', 'npc_1v1arena', '10');