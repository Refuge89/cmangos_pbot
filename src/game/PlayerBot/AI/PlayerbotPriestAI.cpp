/*
 * This file is part of the CMaNGOS Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "PlayerbotPriestAI.h"

class PlayerbotAI;

PlayerbotPriestAI::PlayerbotPriestAI(Player* const master, Player* const bot, PlayerbotAI* const ai) : PlayerbotClassAI(master, bot, ai)
{
	// TODO: fail on non-postivie return
    PlayerbotClassAI_ClassAIInit();
}


PlayerbotPriestAI::~PlayerbotPriestAI()
{
}


bool PlayerbotPriestAI::PlayerbotClassAI_ClassAIInit(void)
{
    RENEW                         = m_botdata->GetAI()->initSpell(RENEW_1);
    LESSER_HEAL                   = m_botdata->GetAI()->initSpell(LESSER_HEAL_1);
    FLASH_HEAL                    = m_botdata->GetAI()->initSpell(FLASH_HEAL_1);
    (FLASH_HEAL > 0) ? FLASH_HEAL : FLASH_HEAL = LESSER_HEAL;
    HEAL                          = m_botdata->GetAI()->initSpell(HEAL_1);
    (HEAL > 0) ? HEAL : HEAL = FLASH_HEAL;
    GREATER_HEAL                  = m_botdata->GetAI()->initSpell(GREATER_HEAL_1);
    (GREATER_HEAL > 0) ? GREATER_HEAL : GREATER_HEAL = HEAL;
    RESURRECTION                  = m_botdata->GetAI()->initSpell(RESURRECTION_1);
    SMITE                         = m_botdata->GetAI()->initSpell(SMITE_1);
    MANA_BURN                     = m_botdata->GetAI()->initSpell(MANA_BURN_1);
    HOLY_NOVA                     = m_botdata->GetAI()->initSpell(HOLY_NOVA_1);
    HOLY_FIRE                     = m_botdata->GetAI()->initSpell(HOLY_FIRE_1);
    DESPERATE_PRAYER              = m_botdata->GetAI()->initSpell(DESPERATE_PRAYER_1);
    PRAYER_OF_HEALING             = m_botdata->GetAI()->initSpell(PRAYER_OF_HEALING_1);
    CIRCLE_OF_HEALING             = m_botdata->GetAI()->initSpell(CIRCLE_OF_HEALING_1);
    BINDING_HEAL                  = m_botdata->GetAI()->initSpell(BINDING_HEAL_1);
    PRAYER_OF_MENDING             = m_botdata->GetAI()->initSpell(PRAYER_OF_MENDING_1);
    CURE_DISEASE                  = m_botdata->GetAI()->initSpell(CURE_DISEASE_1);
	PRIEST_DISPEL_MAGIC			  = m_botdata->GetAI()->initSpell(DISPEL_MAGIC_1);

    // SHADOW
    FADE                          = m_botdata->GetAI()->initSpell(FADE_1);
    SHADOW_WORD_PAIN              = m_botdata->GetAI()->initSpell(SHADOW_WORD_PAIN_1);
    MIND_BLAST                    = m_botdata->GetAI()->initSpell(MIND_BLAST_1);
    SCREAM                        = m_botdata->GetAI()->initSpell(PSYCHIC_SCREAM_1);
    MIND_FLAY                     = m_botdata->GetAI()->initSpell(MIND_FLAY_1);
    DEVOURING_PLAGUE              = m_botdata->GetAI()->initSpell(DEVOURING_PLAGUE_1);
    SHADOW_PROTECTION             = m_botdata->GetAI()->initSpell(SHADOW_PROTECTION_1);
    VAMPIRIC_TOUCH                = m_botdata->GetAI()->initSpell(VAMPIRIC_TOUCH_1);
    PRAYER_OF_SHADOW_PROTECTION   = m_botdata->GetAI()->initSpell(PRAYER_OF_SHADOW_PROTECTION_1);
    SHADOWFIEND                   = m_botdata->GetAI()->initSpell(SHADOWFIEND_1);
    MIND_SEAR                     = m_botdata->GetAI()->initSpell(MIND_SEAR_1);
    SHADOWFORM                    = m_botdata->GetAI()->initSpell(SHADOWFORM_1);
    VAMPIRIC_EMBRACE              = m_botdata->GetAI()->initSpell(VAMPIRIC_EMBRACE_1);

    // RANGED COMBAT
    SHOOT                         = m_botdata->GetAI()->initSpell(SHOOT_1);

    // DISCIPLINE
    PENANCE                       = m_botdata->GetAI()->initSpell(PENANCE_1);
    INNER_FIRE                    = m_botdata->GetAI()->initSpell(INNER_FIRE_1);
    POWER_WORD_SHIELD             = m_botdata->GetAI()->initSpell(POWER_WORD_SHIELD_1);
    POWER_WORD_FORTITUDE          = m_botdata->GetAI()->initSpell(POWER_WORD_FORTITUDE_1);
    PRAYER_OF_FORTITUDE           = m_botdata->GetAI()->initSpell(PRAYER_OF_FORTITUDE_1);
    FEAR_WARD                     = m_botdata->GetAI()->initSpell(FEAR_WARD_1);
    DIVINE_SPIRIT                 = m_botdata->GetAI()->initSpell(DIVINE_SPIRIT_1);
    PRAYER_OF_SPIRIT              = m_botdata->GetAI()->initSpell(PRAYER_OF_SPIRIT_1);
    MASS_DISPEL                   = m_botdata->GetAI()->initSpell(MASS_DISPEL_1);
    POWER_INFUSION                = m_botdata->GetAI()->initSpell(POWER_INFUSION_1);
    INNER_FOCUS                   = m_botdata->GetAI()->initSpell(INNER_FOCUS_1);

    // racial
    ARCANE_TORRENT                = m_botdata->GetAI()->initSpell(ARCANE_TORRENT_MANA_CLASSES);
    GIFT_OF_THE_NAARU             = m_botdata->GetAI()->initSpell(GIFT_OF_THE_NAARU_PRIEST); // draenei
    STONEFORM                     = m_botdata->GetAI()->initSpell(STONEFORM_ALL); // dwarf
    EVERY_MAN_FOR_HIMSELF         = m_botdata->GetAI()->initSpell(EVERY_MAN_FOR_HIMSELF_ALL); // human
    SHADOWMELD                    = m_botdata->GetAI()->initSpell(SHADOWMELD_ALL);
    BERSERKING                    = m_botdata->GetAI()->initSpell(BERSERKING_ALL); // troll
    WILL_OF_THE_FORSAKEN          = m_botdata->GetAI()->initSpell(WILL_OF_THE_FORSAKEN_ALL); // undead
	
    m_botdata->SetRezSpell(RESURRECTION);

	buff_list[0] = new PlayerbotBufflist;

	buff_list[0]->spellid.group			  = { PRAYER_OF_FORTITUDE };	// Group Version
	buff_list[0]->spellid.single		  = { POWER_WORD_FORTITUDE };	// Standard Version
	buff_list[0]->spellid.single_enhanced = { NULL };					// Greater Version
	buff_list[0]->spec_required			  = { NULL };					// Spec Required to cast
	buff_list[0]->caston_non_bot_all	  = { PBOT_CLASS_ALL };			// Non-bot buff control
	buff_list[0]->caston_pet_all		  = { PBOT_PET_ALL };		    // Pet buff control

	buff_list[1] = new PlayerbotBufflist;

	buff_list[1]->spellid.group			  = { PRAYER_OF_SPIRIT };		// Group Version
	buff_list[1]->spellid.single		  = { DIVINE_SPIRIT };			// Standard Version
	buff_list[1]->spellid.single_enhanced = { NULL };					// Greater Version
	buff_list[1]->spec_required			  = { NULL };					// Spec Required to cast
	buff_list[1]->caston_non_bot_all	  = { PBOT_CLASS_ALL };			// Non-bot buff control
	buff_list[1]->caston_pet_all		  = { PBOT_PET_ALL };		    // Pet buff control

	buff_list[2] = new PlayerbotBufflist;

	buff_list[2]->spellid.group			  = { PRAYER_OF_SHADOW_PROTECTION }; // Group Version
	buff_list[2]->spellid.single		  = { SHADOW_PROTECTION };		// Standard Version
	buff_list[2]->spellid.single_enhanced = { NULL };					// Greater Version
	buff_list[2]->spec_required		      = { NULL };					// Spec Required to cast
	buff_list[2]->caston_non_bot_all	  = { PBOT_CLASS_ALL };			// Non-bot buff control
	buff_list[2]->caston_pet_all		  = { PBOT_PET_ALL };		    // Pet buff control


	m_botdata->SetDispellDiseaseSpell(CURE_DISEASE);
	m_botdata->SetDispellMagicSpell(MASS_DISPEL ? MASS_DISPEL : PRIEST_DISPEL_MAGIC);

	m_botdata->SetRolePrimary(BOT_ROLE::ROLE_HEAL);

    return PlayerbotClassAI::PlayerbotClassAI_ClassAIInit();
}


CombatManeuverReturns PlayerbotPriestAI::DoNextManeuver_Heal_ClassSetup(Unit* pTarget)
{
	// No healing setup needed, so pass success
	return RETURN_CONTINUE;
}


CombatManeuverReturns PlayerbotPriestAI::DoFirstCombatManeuverPVE(Unit* /*pTarget*/)
{

    if (m_botdata->GetAI()->IsHealer())
    {
        // TODO: This must be done with toggles: FullHealth allowed
        Unit* healTarget = Get_Prioritized_Heal_Target(ROLE_TANK);
        // This is cast on a target, which activates (and switches to another target within the group) upon receiving+healing damage
        // Mana efficient even at one use
        if (healTarget && PRAYER_OF_MENDING > 0 && m_botdata->GetAI()->In_Reach(healTarget,PRAYER_OF_MENDING) && !healTarget->HasAura(PRAYER_OF_MENDING, EFFECT_INDEX_0) && CastSpell(PRAYER_OF_MENDING, healTarget) & RETURN_CONTINUE)
            return RETURN_FINISHED_FIRST_MOVES;
    }
    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotPriestAI::DoFirstCombatManeuverPVP(Unit* /*pTarget*/)
{
    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotPriestAI::DoNextCombatManeuverPVE(Unit *pTarget)
{
     bool meleeReach = m_botdata->GetBot()->CanReachWithMeleeAttack(pTarget);

    if (m_botdata->GetAI()->GetCombatStyle() != PlayerbotAI::COMBAT_RANGED && !meleeReach)
        m_botdata->GetAI()->SetCombatStyle(PlayerbotAI::COMBAT_RANGED);
    // if in melee range OR can't shoot OR have no ranged (wand) equipped
    else if(m_botdata->GetAI()->GetCombatStyle() != PlayerbotAI::COMBAT_MELEE 
            && (SHOOT == 0 || !m_botdata->GetBot()->GetWeaponForAttack(RANGED_ATTACK, true, true))
            && !m_botdata->GetAI()->IsHealer())
        m_botdata->GetAI()->SetCombatStyle(PlayerbotAI::COMBAT_MELEE);

    //Used to determine if this bot is highest on threat
    Unit* newTarget = m_botdata->GetAI()->FindAttacker((PlayerbotAI::ATTACKERINFOTYPE) (PlayerbotAI::AIT_VICTIMSELF | PlayerbotAI::AIT_HIGHESTTHREAT), m_botdata->GetBot());
    if (newTarget) // TODO: && party has a tank
    {
        if (newTarget && FADE > 0 && !m_botdata->GetBot()->HasAura(FADE, EFFECT_INDEX_0))
        {
            if (CastSpell(FADE, m_botdata->GetBot()))
            {
                //m_botdata->GetAI()->TellMaster("I'm casting fade.");
                return RETURN_CONTINUE;
            }
            else
                m_botdata->GetAI()->TellMaster("I have AGGRO.");
        }

        // Heal myself
        // TODO: move to HealTarget code
        // TODO: you forgot to check for the 'temporarily immune to PW:S because you only just got it cast on you' effect
        //       - which is different effect from the actual shield.
        if (m_botdata->GetAI()->GetHealthPercent() < 25 && POWER_WORD_SHIELD > 0 && !m_botdata->GetBot()->HasAura(POWER_WORD_SHIELD, EFFECT_INDEX_0))
        {
            if (CastSpell(POWER_WORD_SHIELD) & RETURN_CONTINUE)
            {
                //m_botdata->GetAI()->TellMaster("I'm casting PW:S on myself.");
                return RETURN_CONTINUE;
            }
            else if (m_botdata->GetAI()->IsHealer()) // Even if any other RETURN_ANY_OK - aside from RETURN_CONTINUE
                m_botdata->GetAI()->TellMaster("Your healer's about TO DIE. HELP ME.");
        }
        if (m_botdata->GetAI()->GetHealthPercent() < 35 && DESPERATE_PRAYER > 0 && m_botdata->GetAI()->In_Reach(m_botdata->GetBot(),DESPERATE_PRAYER) && CastSpell(DESPERATE_PRAYER, m_botdata->GetBot()) & RETURN_CONTINUE)
        {
            //m_botdata->GetAI()->TellMaster("I'm casting desperate prayer.");
            return RETURN_CONTINUE;
        }

        // Already healed self or tank. If healer, do nothing else to anger mob.
        if (m_botdata->GetAI()->IsHealer())
            return RETURN_NO_ACTION_OK; // In a sense, mission accomplished.

        // Have threat, can't quickly lower it. 3 options remain: Stop attacking, lowlevel damage (wand), keep on keeping on.
        if (newTarget->GetHealthPercent() > 25)
        {
            // If elite, do nothing and pray tank gets aggro off you
            // TODO: Is there an IsElite function? If so, find it and insert.
            //if (newTarget->IsElite())
            //    return;

            // Not an elite. You could insert PSYCHIC SCREAM here but in any PvE situation that's 90-95% likely
            // to worsen the situation for the group. ... So please don't.
            return CastSpell(SHOOT, pTarget);
        }
    }

    // Heal
    if (m_botdata->GetAI()->IsHealer())
    {
        if (HealPlayer(Get_Prioritized_Heal_Target()) & RETURN_CONTINUE)
            return RETURN_CONTINUE;
    }
    else
    {
        // Is this desirable? Debatable.
        // ... Certainly could be very detrimental to a shadow priest
        // TODO: In a group/raid with a healer you'd want this bot to focus on DPS (it's not specced/geared for healing either)
        if (HealPlayer(m_botdata->GetBot()) & RETURN_CONTINUE)
            return RETURN_CONTINUE;
    }

    // Do damage tweaking for healers here
    if (m_botdata->GetAI()->IsHealer())
    {
        // TODO: elite exception
        //if (Any target is an Elite)
        //    return;

        return CastSpell(SHOOT, pTarget);
    }

    // Damage Spells
    switch (m_botdata->GetSpec())
    {
        case PRIEST_SPEC_HOLY:
            if (HOLY_FIRE > 0 && m_botdata->GetAI()->In_Reach(pTarget,HOLY_FIRE) && !pTarget->HasAura(HOLY_FIRE, EFFECT_INDEX_0) && CastSpell(HOLY_FIRE, pTarget))
                return RETURN_CONTINUE;
            if (SMITE > 0 && m_botdata->GetAI()->In_Reach(pTarget,SMITE) && CastSpell(SMITE, pTarget))
                return RETURN_CONTINUE;
            //if (HOLY_NOVA > 0 && m_botdata->GetAI()->In_Reach(pTarget,HOLY_NOVA) && meleeReach && m_botdata->GetAI()->CastSpell(HOLY_NOVA))
            //    return RETURN_CONTINUE;
            break;

        case PRIEST_SPEC_SHADOW:
            if (DEVOURING_PLAGUE > 0 && m_botdata->GetAI()->In_Reach(pTarget,DEVOURING_PLAGUE) && !pTarget->HasAura(DEVOURING_PLAGUE, EFFECT_INDEX_0) && CastSpell(DEVOURING_PLAGUE, pTarget))
                return RETURN_CONTINUE;
            if (VAMPIRIC_TOUCH > 0 && m_botdata->GetAI()->In_Reach(pTarget,VAMPIRIC_TOUCH) && !pTarget->HasAura(VAMPIRIC_TOUCH, EFFECT_INDEX_0) && CastSpell(VAMPIRIC_TOUCH, pTarget))
                return RETURN_CONTINUE;
            if (SHADOW_WORD_PAIN > 0 && m_botdata->GetAI()->In_Reach(pTarget,SHADOW_WORD_PAIN) && !pTarget->HasAura(SHADOW_WORD_PAIN, EFFECT_INDEX_0) && CastSpell(SHADOW_WORD_PAIN, pTarget))
                return RETURN_CONTINUE;
            if (MIND_BLAST > 0 && m_botdata->GetAI()->In_Reach(pTarget,MIND_BLAST) && (m_botdata->GetBot()->IsSpellReady(MIND_BLAST)) && CastSpell(MIND_BLAST, pTarget))
                return RETURN_CONTINUE;
            if (MIND_FLAY > 0 && m_botdata->GetAI()->In_Reach(pTarget,MIND_FLAY) && CastSpell(MIND_FLAY, pTarget))
            {
                m_botdata->GetAI()->SetIgnoreUpdateTime(3);
                return RETURN_CONTINUE;
            }
            if (SHADOWFIEND > 0 && m_botdata->GetAI()->In_Reach(pTarget,SHADOWFIEND) && !m_botdata->GetBot()->GetPet() && CastSpell(SHADOWFIEND))
                return RETURN_CONTINUE;
            /*if (MIND_SEAR > 0 && m_botdata->GetAI()->GetAttackerCount() >= 3 && CastSpell(MIND_SEAR, pTarget))
            {
                m_botdata->GetAI()->SetIgnoreUpdateTime(5);
                return RETURN_CONTINUE;
            }*/
            if (SHADOWFORM == 0 && MIND_FLAY == 0 && SMITE > 0 && m_botdata->GetAI()->In_Reach(pTarget,SMITE) && CastSpell(SMITE, pTarget)) // low levels
                return RETURN_CONTINUE;
            break;

        case PRIEST_SPEC_DISCIPLINE:
            if (POWER_INFUSION > 0 && m_botdata->GetAI()->In_Reach(m_botdata->GetMaster(),POWER_INFUSION) && CastSpell(POWER_INFUSION, m_botdata->GetMaster())) // TODO: just master?
                return RETURN_CONTINUE;
            if (INNER_FOCUS > 0 && m_botdata->GetAI()->In_Reach(m_botdata->GetBot(),INNER_FOCUS) && !m_botdata->GetBot()->HasAura(INNER_FOCUS, EFFECT_INDEX_0) && CastSpell(INNER_FOCUS, m_botdata->GetBot()))
                return RETURN_CONTINUE;
            if (PENANCE > 0 && CastSpell(PENANCE))
                return RETURN_CONTINUE;
            if (SMITE > 0 && m_botdata->GetAI()->In_Reach(pTarget,SMITE) && CastSpell(SMITE, pTarget))
                return RETURN_CONTINUE;
            break;
    }

    // No spec due to low level OR no spell found yet
    if (MIND_BLAST > 0 && m_botdata->GetAI()->In_Reach(pTarget,MIND_BLAST) && (m_botdata->GetBot()->IsSpellReady(MIND_BLAST)) && CastSpell(MIND_BLAST, pTarget))
        return RETURN_CONTINUE;
    if (SHADOW_WORD_PAIN > 0 && m_botdata->GetAI()->In_Reach(pTarget,SHADOW_WORD_PAIN) && !pTarget->HasAura(SHADOW_WORD_PAIN, EFFECT_INDEX_0) && CastSpell(SHADOW_WORD_PAIN, pTarget))
        return RETURN_CONTINUE;
    if (MIND_FLAY > 0 && m_botdata->GetAI()->In_Reach(pTarget,MIND_FLAY) && CastSpell(MIND_FLAY, pTarget))
    {
        m_botdata->GetAI()->SetIgnoreUpdateTime(3);
        return RETURN_CONTINUE;
    }
    if (SHADOWFORM == 0 && SMITE > 0 && m_botdata->GetAI()->In_Reach(pTarget,SMITE) && CastSpell(SMITE, pTarget))
        return RETURN_CONTINUE;

    return RETURN_NO_ACTION_OK;
} // end DoNextCombatManeuver

CombatManeuverReturns PlayerbotPriestAI::DoNextCombatManeuverPVP(Unit* pTarget)
{
    switch (m_botdata->GetAI()->GetScenarioType())
    {
        case PlayerbotAI::SCENARIO_PVP_DUEL:
            // TODO: spec tweaking
            if (m_botdata->GetAI()->HasAura(SCREAM, *pTarget) && m_botdata->GetAI()->GetHealthPercent() < 60 && HEAL && m_botdata->GetAI()->In_Reach(pTarget,HEAL) && CastSpell(HEAL) & RETURN_ANY_OK)
                return RETURN_CONTINUE;

            if (SHADOW_WORD_PAIN && m_botdata->GetAI()->In_Reach(pTarget,SHADOW_WORD_PAIN) && CastSpell(SHADOW_WORD_PAIN) & RETURN_ANY_OK) // TODO: Check whether enemy has it active yet
                return RETURN_CONTINUE;

            if (m_botdata->GetAI()->GetHealthPercent() < 80 && RENEW && m_botdata->GetAI()->In_Reach(pTarget,RENEW) && CastSpell(RENEW) & RETURN_ANY_OK) // TODO: Check whether you have renew active on you
                return RETURN_CONTINUE;

            if (SCREAM && m_botdata->GetAI()->In_Reach(pTarget,SCREAM) && CastSpell(SCREAM) & RETURN_ANY_OK) // TODO: Check for cooldown
                return RETURN_CONTINUE;

            if (MIND_BLAST && m_botdata->GetAI()->In_Reach(pTarget,MIND_BLAST) && CastSpell(MIND_BLAST) & RETURN_ANY_OK) // TODO: Check for cooldown
                return RETURN_CONTINUE;

            if (m_botdata->GetAI()->GetHealthPercent() < 50 && GREATER_HEAL && m_botdata->GetAI()->In_Reach(pTarget,GREATER_HEAL) && CastSpell(GREATER_HEAL) & RETURN_ANY_OK)
                return RETURN_CONTINUE;

            if (SMITE && m_botdata->GetAI()->In_Reach(pTarget,SMITE) && CastSpell(SMITE) & RETURN_ANY_OK)
                return RETURN_CONTINUE;

            m_botdata->GetAI()->TellMaster("Couldn't find a spell to cast while dueling");
        default:
            break;
    }

    return DoNextCombatManeuverPVE(pTarget); // TODO: bad idea perhaps, but better than the alternative
}

CombatManeuverReturns PlayerbotPriestAI::HealPlayer(Player* target)
{
    CombatManeuverReturns r = PlayerbotClassAI::HealPlayer(target);
    if (r != RETURN_NO_ACTION_OK)
        return r;

    if (!target->isAlive())
    {
        if (RESURRECTION && m_botdata->GetAI()->In_Reach(target,RESURRECTION) && m_botdata->GetAI()->CastSpell(RESURRECTION, *target))
        {
            std::string msg = "Resurrecting ";
            msg += target->GetName();
            m_botdata->GetBot()->Say(msg, LANG_UNIVERSAL);
            return RETURN_CONTINUE;
        }
        return RETURN_NO_ACTION_ERROR; // not error per se - possibly just OOM
    }

    if (CURE_DISEASE > 0 && (m_botdata->GetAI()->GetCombatOrder() & PlayerbotAI::ORDERS_NODISPEL) == 0)
    {
        uint32 dispelMask  = GetDispellMask(DISPEL_DISEASE);
        Unit::SpellAuraHolderMap const& auras = target->GetSpellAuraHolderMap();
        for (Unit::SpellAuraHolderMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
        {
            SpellAuraHolder *holder = itr->second;
            if ((1 << holder->GetSpellProto()->Dispel) & dispelMask)
            {
                if (holder->GetSpellProto()->Dispel == DISPEL_DISEASE)
                {
                    m_botdata->GetAI()->CastSpell(CURE_DISEASE, *target);
                    return RETURN_CONTINUE;
                }
            }
        }
    }

    uint8 hp = target->GetHealthPercent();
    uint8 hpSelf = m_botdata->GetAI()->GetHealthPercent();

    if (hp >= 90)
        return RETURN_NO_ACTION_OK;

    // TODO: Integrate shield here
    if (hp < 35 && FLASH_HEAL > 0 && m_botdata->GetAI()->In_Reach(target,FLASH_HEAL) && m_botdata->GetAI()->CastSpell(FLASH_HEAL, *target))
        return RETURN_CONTINUE;
    if (hp < 45 && GREATER_HEAL > 0 && m_botdata->GetAI()->In_Reach(target,GREATER_HEAL) && m_botdata->GetAI()->CastSpell(GREATER_HEAL, *target))
        return RETURN_CONTINUE;
    // Heals target AND self for equal amount
    if (hp < 60 && hpSelf < 80 && BINDING_HEAL > 0 && m_botdata->GetAI()->In_Reach(target,BINDING_HEAL) && m_botdata->GetAI()->CastSpell(BINDING_HEAL, *target))
        return RETURN_CONTINUE;
    if (hp < 60 && PRAYER_OF_MENDING > 0 && m_botdata->GetAI()->In_Reach(target,PRAYER_OF_MENDING) && !target->HasAura(PRAYER_OF_MENDING, EFFECT_INDEX_0) && CastSpell(PRAYER_OF_MENDING, target))
        return RETURN_FINISHED_FIRST_MOVES;
    if (hp < 60 && HEAL > 0 && m_botdata->GetAI()->In_Reach(target,HEAL) && m_botdata->GetAI()->CastSpell(HEAL, *target))
        return RETURN_CONTINUE;
    if (hp < 90 && RENEW > 0 && m_botdata->GetAI()->In_Reach(target,RENEW) && !target->HasAura(RENEW) && m_botdata->GetAI()->CastSpell(RENEW, *target))
        return RETURN_CONTINUE;

    // Group heal. Not really useful until a group check is available?
    //if (hp < 40 && PRAYER_OF_HEALING > 0 && m_botdata->GetAI()->CastSpell(PRAYER_OF_HEALING, *target) & RETURN_CONTINUE)
    //    return RETURN_CONTINUE;
    // Group heal. Not really useful until a group check is available?
    //if (hp < 50 && CIRCLE_OF_HEALING > 0 && m_botdata->GetAI()->CastSpell(CIRCLE_OF_HEALING, *target) & RETURN_CONTINUE)
    //    return RETURN_CONTINUE;

    return RETURN_NO_ACTION_OK;
} // end HealTarget



CombatManeuverReturns PlayerbotPriestAI::DoManeuver_Idle_SelfBuff(void)
{
    if (m_botdata->GetAI()->SelfBuff(INNER_FIRE)) return RETURN_CONTINUE;

    if (m_botdata->GetSpec() == PRIEST_SPEC_SHADOW)
    {
        if (m_botdata->GetAI()->SelfBuff(SHADOWFORM)) return RETURN_CONTINUE;
    }

    return RETURN_NO_ACTION_OK;
}

CombatManeuverReturns PlayerbotPriestAI::DoManeuver_Idle_Heal_Prep(Player* target)
{
    uint8 hp        = target->GetHealthPercent();
    uint8 hpSelf    = m_botdata->GetAI()->GetHealthPercent();
    uint32 uiSpellID = 0;

    // TODO: We should flag if we want this option
    if (VAMPIRIC_EMBRACE > 0)
    {
        m_botdata->GetAI()->SelfBuff(VAMPIRIC_EMBRACE);   // Heal
    }

    // TODO: Integrate shield here
    // TODO: Thresholds need to be variable
    // TODO: Factor raid, group, mana level, and char level
    if (hp >= 90)
    {
        return RETURN_NO_ACTION_OK;
    }
    else if (hp < 35 && FLASH_HEAL > 0 && m_botdata->GetAI()->In_Reach(target, FLASH_HEAL))
    {
        m_botdata->SetHealSpell(FLASH_HEAL);
    }
    else if (hp < 45 && GREATER_HEAL > 0 && m_botdata->GetAI()->In_Reach(target, GREATER_HEAL))
    {
        m_botdata->SetHealSpell(GREATER_HEAL);
    }
    else if (hp < 60 && hpSelf < 80 && BINDING_HEAL > 0 && m_botdata->GetAI()->In_Reach(target, BINDING_HEAL))
    {
        m_botdata->SetHealSpell(BINDING_HEAL);
    }
    else if (hp < 60 && PRAYER_OF_MENDING > 0 && m_botdata->GetAI()->In_Reach(target, PRAYER_OF_MENDING) && !target->HasAura(PRAYER_OF_MENDING, EFFECT_INDEX_0))
    {
        m_botdata->SetHealSpell(PRAYER_OF_MENDING);
    }
    else if (hp < 60 && HEAL > 0 && m_botdata->GetAI()->In_Reach(target, HEAL))
    {
        m_botdata->SetHealSpell(HEAL);
    }
    else if (hp < 90 && RENEW > 0 && m_botdata->GetAI()->In_Reach(target, RENEW) && !target->HasAura(RENEW))
    {
        m_botdata->SetHealSpell(RENEW);
    }

	m_botdata->SetHealSpell(0);

    return RETURN_NO_ACTION_OK;
}



bool PlayerbotPriestAI::CastHoTOnTank()
{
    if (!m_botdata->GetAI()) return false;

    if ((PlayerbotAI::ORDERS_HEAL & m_botdata->GetAI()->GetCombatOrder()) == 0) return false;

    // Priest HoTs: Renew, Penance (with talents, channeled)
    if (RENEW > 0 && m_botdata->GetAI()->In_Reach(m_botdata->GetAI()->GetGroupTank(),RENEW))
        return (RETURN_CONTINUE & CastSpell(RENEW, m_botdata->GetAI()->GetGroupTank()));

    return false;
}
