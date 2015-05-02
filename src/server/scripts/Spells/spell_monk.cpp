/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Scripts for spells with SPELLFAMILY_MONK and SPELLFAMILY_GENERIC spells used by monk players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_monk_".
 */

#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Cell.h"
#include "CellImpl.h"

enum MonkSpells
{
    SPELL_MONK_FORTIFYING_BREW                  = 120954,
    SPELL_MONK_PROVOKE                          = 118635,
    SPELL_MONK_ZEN_PILGRIMAGE                   = 126892,
    SPELL_MONK_ZEN_PILGRIMAGE_RETURN            = 126895,
    SPELL_MONK_DISABLE_ROOT                     = 116706,
    SPELL_MONK_DISABLE                          = 116095,
    SPELL_MONK_SOOTHING_MIST_VISUAL             = 125955,
    SPELL_MONK_SOOTHING_MIST_ENERGIZE           = 116335,
    SPELL_MONK_BREATH_OF_FIRE_DOT               = 123725,
    SPELL_MONK_BREATH_OF_FIRE_CONFUSED          = 123393,
    SPELL_MONK_ELUSIVE_BREW_STACKS              = 128939,
    SPELL_MONK_ELUSIVE_BREW                     = 115308,
    SPELL_MONK_KEG_SMASH_VISUAL                 = 123662,
    SPELL_MONK_KEG_SMASH_ENERGIZE               = 127796,
    SPELL_MONK_WEAKENED_BLOWS                   = 115798,
    SPELL_MONK_DIZZYING_HAZE                    = 116330,
    SPELL_MONK_LIGHT_STAGGER                    = 124275,
    SPELL_MONK_MODERATE_STAGGER                 = 124274,
    SPELL_MONK_HEAVY_STAGGER                    = 124273,
    SPELL_MONK_ROLL                             = 109132,
    SPELL_MONK_ROLL_TRIGGER                     = 107427,
    SPELL_MONK_CHI_TORPEDO_HEAL                 = 124040,
    SPELL_MONK_CHI_TORPEDO_DAMAGE               = 117993,
    SPELL_MONK_FLYING_SERPENT_KICK              = 101545,
    SPELL_MONK_FLYING_SERPENT_KICK_NEW          = 115057,
    SPELL_MONK_FLYING_SERPENT_KICK_AOE          = 123586,
    SPELL_MONK_TIGEREYE_BREW                    = 116740,
    SPELL_MONK_TIGEREYE_BREW_STACKS             = 125195,
    SPELL_MONK_SPEAR_HAND_STRIKE_SILENCE        = 116709,
    SPELL_MONK_ZEN_SPHERE_DAMAGE                = 124098,
    SPELL_MONK_ZEN_SPHERE_HEAL                  = 124081,
    SPELL_MONK_ZEN_SPHERE_DETONATE_HEAL         = 124101,
    SPELL_MONK_ZEN_SPHERE_DETONATE_DAMAGE       = 125033,
    SPELL_MONK_HEALING_ELIXIRS_AURA             = 134563,
    SPELL_MONK_HEALING_ELIXIRS_RESTORE_HEALTH   = 122281,
    SPELL_MONK_RENEWING_MIST_HOT                = 119611,
    SPELL_MONK_RENEWING_MIST_JUMP_AURA          = 119607,
    SPELL_MONK_GLYPH_OF_RENEWING_MIST           = 123334,
    SPELL_MONK_SURGING_MIST_HEAL                = 116995,
    SPELL_MONK_ENVELOPING_MIST_HEAL             = 132120,
    SPELL_MONK_PLUS_ONE_MANA_TEA                = 123760,
    SPELL_MONK_MANA_TEA_STACKS                  = 115867,
    SPELL_MONK_MANA_TEA_REGEN                   = 115294,
    SPELL_MONK_SPINNING_CRANE_KICK_HEAL         = 117640,
    MONK_NPC_JADE_SERPENT_STATUE                = 60849,
    SPELL_MONK_UPLIFT_ALLOWING_CAST             = 123757,
    SPELL_MONK_THUNDER_FOCUS_TEA                = 116680,
    SPELL_MONK_TOUCH_OF_KARMA_REDIRECT_DAMAGE   = 124280,
    SPELL_MONK_JADE_LIGHTNING_ENERGIZE          = 123333,
    SPELL_MONK_CRACKLING_JADE_SHOCK_BUMP        = 117962,
    SPELL_MONK_POWER_STRIKES_TALENT             = 121817,
    SPELL_MONK_POWER_STRIKES_AURA               = 129914,
    SPELL_MONK_CREATE_CHI_SPHERE                = 121286,
    SPELL_MONK_GLYPH_OF_ZEN_FLIGHT              = 125893,
    SPELL_MONK_ZEN_FLIGHT                       = 125883,
    SPELL_MONK_BEAR_HUG                         = 127361,
    ITEM_MONK_T14_TANK_4P                       = 123159,
    MONK_NPC_BLACK_OX_STATUE                    = 61146,
    SPELL_MONK_GUARD                            = 115295,
    SPELL_MONK_ITEM_2_S12_MISTWEAVER            = 131561,
    SPELL_MONK_ITEM_4_S12_MISTWEAVER            = 124487,
    SPELL_MONK_ZEN_FOCUS                        = 124488,
    SPELL_MONK_EMINENCE_HEAL                    = 126890,
    SPELL_MONK_CHI_WAVE_HEAL                    = 132463,
    SPELL_MONK_CHI_WAVE_DAMAGE                  = 132467,
    SPELL_MONK_CHI_WAVE_HEALING_BOLT            = 132464,
    SPELL_MONK_CHI_WAVE_TALENT_AURA             = 115098,
    SPELL_MONK_ITEM_PVP_GLOVES_BONUS            = 124489,
    SPELL_MONK_MUSCLE_MEMORY                    = 139598,
    SPELL_MONK_MUSCLE_MEMORY_EFFECT             = 139597,
    SPELL_MONK_CHI_BREW                         = 115399,
    SPELL_MONK_MASTERY_BOTTLED_FURY             = 115636,
    SPELL_MONK_BREWMASTER_TRAINING              = 117967,
    SPELL_MONK_STORM_EARTH_AND_FIRE             = 137639,
    SPELL_MONK_RING_OF_PEACE_AURA               = 140023,
    SPELL_MONK_RING_OF_PEACE_DISARM             = 137461,
    SPELL_MONK_RING_OF_PEACE_SILENCE            = 137460,
    SPELL_MONK_COMBO_BREAKER_AURA               = 137384,
    SPELL_MONK_COMBO_BREAKER_TIGER_PALM         = 118864,
    SPELL_MONK_COMBO_BREAKER_BLACKOUT_KICK      = 116768,
    SPELL_MONK_MORTEL_WOUNDS                    = 115804,
    SPELL_MONK_RISING_SUN_KICK_DAMAGE_BONUS     = 130320,
    SPELL_MONK_GLYPH_OF_RAPID_ROLLING           = 146951,
    SPELL_MONK_RAPID_ROLLING                    = 147364,
    SPELL_MONK_GLYPH_OF_TARGETED_EXPULSION      = 146950,
    SPELL_MONK_CRANES_ZEAL                      = 127722,
    SPELL_MONK_STANCE_OF_THE_WISE_SERPENT       = 115070,
    SPELL_MONL_SOOTHING_MIST                    = 115175,
    SPELL_MONK_CHI_EXPLOSION_WINWALKER          = 152174,
    SPELL_MONK_COMBO_BREAKER_CHI_EXPLOSION      = 159407
};

// Tiger Eye Brew - 123980 & Mana Tea - 123766
class PlayerScript_TigereEyeBrew_ManaTea: public PlayerScript
{
    public:
        PlayerScript_TigereEyeBrew_ManaTea() :PlayerScript("PlayerScript_TigereEyeBrew_ManaTea") {}

        void OnModifyPower(Player* p_Player, Powers p_Power, int32 p_OldValue, int32& p_NewValue, bool p_Regen)
        {
            // Get the power earn (if > 0 ) or consum (if < 0)
            int32 l_DiffValue = p_NewValue - p_OldValue;

            if (p_Power == POWER_CHI && l_DiffValue < 0)
            {
                if (AuraPtr tigereyeBrew = p_Player->GetAura(123980))
                    tigereyeBrew->SetScriptData(0, -l_DiffValue);
                else if (AuraPtr manaTea = p_Player->GetAura(123766))
                    manaTea->SetScriptData(0, -l_DiffValue);
            }
        }
};

// Called by 100780 / 108557 / 115698 / 115687 / 115693 / 115695 - Jab (and overrides)
// 115636 - Mastery : Combo Breaker
class spell_monk_combo_breaker: public SpellScriptLoader
{
    public:
        spell_monk_combo_breaker() : SpellScriptLoader("spell_monk_combo_breaker") { }

        class spell_monk_combo_breaker_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_combo_breaker_SpellScript);

            void HandleOnHit()
            {
                if (Unit* caster = GetCaster())
                {
                    if (Unit* target = GetHitUnit())
                    {
                        if (caster->HasAura(SPELL_MONK_COMBO_BREAKER_AURA))
                        {
                            if (roll_chance_i(12))
                            {
                                if (urand(0, 1))
                                    caster->CastSpell(caster, SPELL_MONK_COMBO_BREAKER_TIGER_PALM, true);
                                else
                                    if (caster->HasSpell(SPELL_MONK_CHI_EXPLOSION_WINWALKER))
                                        caster->CastSpell(caster, SPELL_MONK_COMBO_BREAKER_CHI_EXPLOSION, true);
                                    else
                                        caster->CastSpell(caster, SPELL_MONK_COMBO_BREAKER_BLACKOUT_KICK, true);
                            }
                        }
                    }
                }
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_monk_combo_breaker_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_combo_breaker_SpellScript();
        }
};

// Ring of Peace (dummy) - 140023
class spell_monk_ring_of_peace_dummy: public SpellScriptLoader
{
    public:
        spell_monk_ring_of_peace_dummy() : SpellScriptLoader("spell_monk_ring_of_peace_dummy") {}

        class spell_monk_ring_of_peace_dummy_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_ring_of_peace_dummy_AuraScript);

            void HandleDummyProc(constAuraEffectPtr /*aurEff*/, ProcEventInfo& /*eventInfo*/)
            {
                if (Unit* caster = GetCaster())
                {
                    if (Unit* target = GetTarget())
                    {
                        caster->CastSpell(target, SPELL_MONK_RING_OF_PEACE_SILENCE, true);
                        caster->CastSpell(target, SPELL_MONK_RING_OF_PEACE_DISARM, true);
                    }
                }
            }

            void Register()
            {
                OnEffectProc += AuraEffectProcFn(spell_monk_ring_of_peace_dummy_AuraScript::HandleDummyProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_monk_ring_of_peace_dummy_AuraScript();
        }
};

// Ring of Peace - 116844
class spell_monk_ring_of_peace: public SpellScriptLoader
{
    public:
        spell_monk_ring_of_peace() : SpellScriptLoader("spell_monk_ring_of_peace") { }

        class spell_monk_ring_of_peace_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_ring_of_peace_AuraScript);

            void OnUpdate(uint32 diff)
            {
                if (Unit* caster = GetCaster())
                {
                    if (Unit* target = GetUnitOwner())
                    {
                        std::list<Unit*> targetList;
                        float radius = 8.0f;

                        JadeCore::NearestAttackableUnitInObjectRangeCheck u_check(target, caster, radius);
                        JadeCore::UnitListSearcher<JadeCore::NearestAttackableUnitInObjectRangeCheck> searcher(target, targetList, u_check);
                        target->VisitNearbyObject(radius, searcher);

                        for (auto itr : targetList)
                            caster->CastSpell(itr, SPELL_MONK_RING_OF_PEACE_AURA, true);
                    }
                }
            }

            void Register()
            {
                OnAuraUpdate += AuraUpdateFn(spell_monk_ring_of_peace_AuraScript::OnUpdate);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_monk_ring_of_peace_AuraScript();
        }
};

const uint32 spiritEntry[3] = { 69680,  69792,  69791  }; // Storm, Earth and Fire
const uint32 summonsMonk[3] = { 138122, 138121, 138123 }; // Storm, Earth and Fire
const uint32 visualMorph[3] = { 138080, 138083, 138081 }; // Storm, Earth and Fire

// Storm, Earth and Fire - 138130
class spell_monk_storm_earth_and_fire_stats: public SpellScriptLoader
{
    public:
        spell_monk_storm_earth_and_fire_stats() : SpellScriptLoader("spell_monk_storm_earth_and_fire_stats") { }

        class spell_monk_storm_earth_and_fire_stats_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_storm_earth_and_fire_stats_AuraScript);

            void OnUpdate(uint32 /*diff*/, AuraEffectPtr aurEff)
            {
                if (!GetCaster())
                    return;

                if (Unit* caster = GetCaster()->GetOwner())
                {
                    if (AuraEffectPtr stormAura = caster->GetAuraEffect(SPELL_MONK_STORM_EARTH_AND_FIRE, EFFECT_1))
                    {
                        if (aurEff->GetAmount() != stormAura->GetAmount())
                            aurEff->ChangeAmount(stormAura->GetAmount());
                    }
                }
            }

            void CalculateReducedDamage(constAuraEffectPtr /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                if (!GetCaster() || !GetCaster()->GetOwner())
                    return;

                if (Unit* owner = GetCaster()->GetOwner())
                    if (AuraEffectPtr stormAura = owner->GetAuraEffect(SPELL_MONK_STORM_EARTH_AND_FIRE, EFFECT_1))
                        amount = stormAura->GetAmount();
            }

            void CalculateHealing(constAuraEffectPtr /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                if (!GetCaster() || !GetCaster()->GetOwner())
                    return;

                if (Unit* owner = GetCaster()->GetOwner())
                    amount = owner->GetTotalAuraModifier(SPELL_AURA_MOD_HEALING_DONE_PERCENT);
            }

            void CalculateAttackPower(constAuraEffectPtr /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                if (!GetCaster() || !GetCaster()->GetOwner())
                    return;

                if (Unit* owner = GetCaster()->GetOwner())
                    amount = owner->GetTotalAttackPowerValue(WeaponAttackType::BaseAttack);
            }

            void CalculateHaste(constAuraEffectPtr /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                if (!GetCaster() || !GetCaster()->GetOwner())
                    return;

                if (Player* owner = GetCaster()->GetOwner()->ToPlayer())
                {
                    if (Unit* caster = GetCaster())
                    {
                        // Convert Owner's haste into the Spirit haste
                        float ownerHaste = 1.0f  +  owner->GetUInt32Value(PLAYER_FIELD_COMBAT_RATINGS + CR_HASTE_MELEE) *
                                                    owner->GetRatingMultiplier(CR_HASTE_MELEE) / 100.0f;
                        caster->ApplyPercentModFloatValue(UNIT_FIELD_MOD_CASTING_SPEED, ownerHaste, false);
                        caster->ApplyPercentModFloatValue(UNIT_FIELD_MOD_SPELL_HASTE, ownerHaste, false);
                        caster->ApplyPercentModFloatValue(UNIT_FIELD_MOD_HASTE, ownerHaste, false);
                    }
                }
            }

            void Register()
            {
                OnEffectUpdate += AuraEffectUpdateFn(spell_monk_storm_earth_and_fire_stats_AuraScript::OnUpdate, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_monk_storm_earth_and_fire_stats_AuraScript::CalculateReducedDamage, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_monk_storm_earth_and_fire_stats_AuraScript::CalculateHealing, EFFECT_3, SPELL_AURA_MOD_HEALING_DONE_PERCENT);
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_monk_storm_earth_and_fire_stats_AuraScript::CalculateAttackPower, EFFECT_4, SPELL_AURA_MOD_ATTACK_POWER);
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_monk_storm_earth_and_fire_stats_AuraScript::CalculateHaste, EFFECT_5, SPELL_AURA_MOD_MELEE_RANGED_HASTE_2);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_monk_storm_earth_and_fire_stats_AuraScript();
        }
};

// Storm, Earth and Fire - 137639
class spell_monk_storm_earth_and_fire: public SpellScriptLoader
{
    public:
        spell_monk_storm_earth_and_fire() : SpellScriptLoader("spell_monk_storm_earth_and_fire") { }

        class spell_monk_storm_earth_and_fire_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_storm_earth_and_fire_SpellScript);

            uint8 summonsCount;
            uint8 firstSpirit;

            bool Load()
            {
                summonsCount = 0;
                firstSpirit  = 3;
                return true;
            }

            void HandleDummy(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                {
                    if (Unit* target = GetHitUnit())
                    {
                        for (uint8 i = 0; i < 3; ++i)
                        {
                            for (Unit::ControlList::const_iterator itr = caster->m_Controlled.begin(); itr != caster->m_Controlled.end(); ++itr)
                            {
                                if ((*itr)->GetEntry() == spiritEntry[i])
                                {
                                    ++summonsCount;

                                    if (firstSpirit == 3)
                                        firstSpirit = i;
                                }
                            }
                        }

                        if (!summonsCount)
                            caster->CastSpell(caster, visualMorph[urand(0, 2)], true);

                        ++summonsCount;

                        // Find summonned spirit
                        for (Unit::ControlList::const_iterator itr = caster->m_Controlled.begin(); itr != caster->m_Controlled.end(); ++itr)
                        {
                            if (Creature* spirit = (*itr)->ToCreature())
                            {
                                if (spirit->AI() && spirit->AI()->GetGUID() == target->GetGUID())
                                {
                                    spirit->AI()->DoAction(0);
                                    return;
                                }
                            }
                        }

                        Unit* spiritRemoved = NULL;
                        if (summonsCount > 2)
                        {
                            for (Unit::ControlList::const_iterator itr = caster->m_Controlled.begin(); itr != caster->m_Controlled.end(); ++itr)
                            {
                                if ((*itr)->GetEntry() == spiritEntry[firstSpirit])
                                {
                                    if (Creature* spirit = (*itr)->ToCreature())
                                    {
                                        spirit->GetMotionMaster()->Clear();
                                        spirit->GetMotionMaster()->MoveJump(caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), 15.0f, 10.0f, spirit->GetOrientation(), 1);
                                        spiritRemoved = spirit->ToUnit();
                                        break;
                                    }
                                }
                            }
                        }

                        Unit* pPet = NULL;
                        if (spiritRemoved)
                        {
                            for (uint8 i = 0; i < 3; ++i)
                            {
                                if (spiritEntry[i] == spiritRemoved->GetEntry())
                                {
                                    caster->CastSpell(caster, summonsMonk[i], true);

                                    // Find summonned spirit
                                    for (Unit::ControlList::const_iterator itr = caster->m_Controlled.begin(); itr != caster->m_Controlled.end(); ++itr)
                                    {
                                        if ((*itr)->GetEntry() == spiritEntry[i] && (*itr) != spiritRemoved)
                                        {
                                            pPet = *itr;
                                            break;
                                        }
                                    }

                                    if (pPet && pPet->GetAI())
                                        pPet->GetAI()->SetGUID(target->GetGUID());

                                    return;
                                }
                            }
                        }

                        for (uint8 i = 0; i < 3; ++i)
                        {
                            if (caster->HasAura(visualMorph[i]))
                                continue;

                            if (firstSpirit < 3 && firstSpirit == i)
                                continue;

                            caster->CastSpell(caster, summonsMonk[i], true);

                            // Find summonned spirit
                            for (Unit::ControlList::const_iterator itr = caster->m_Controlled.begin(); itr != caster->m_Controlled.end(); ++itr)
                            {
                                if ((*itr)->GetEntry() == spiritEntry[i] && (*itr) != spiritRemoved)
                                {
                                    pPet = *itr;
                                    break;
                                }
                            }

                            if (pPet && pPet->GetAI())
                                pPet->GetAI()->SetGUID(target->GetGUID());

                            if (firstSpirit == 3)
                                firstSpirit = i;

                            break;
                        }
                    }
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_monk_storm_earth_and_fire_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_storm_earth_and_fire_SpellScript();
        }

        class spell_monk_storm_earth_and_fire_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_storm_earth_and_fire_AuraScript);

            void OnUpdate(uint32 /*diff*/, AuraEffectPtr /*aurEff*/)
            {
                if (Unit* caster = GetCaster())
                {
                    uint8 count = 0;
                    for (Unit::ControlList::const_iterator itr = caster->m_Controlled.begin(); itr != caster->m_Controlled.end(); ++itr)
                        if ((*itr)->GetEntry() == 69680 || (*itr)->GetEntry() == 69792 || (*itr)->GetEntry() == 69791)
                            ++count;

                    if (!count)
                    {
                        caster->RemoveAura(GetSpellInfo()->Id);
                        return;
                    }

                    if (AuraPtr stormAura = caster->GetAura(GetSpellInfo()->Id))
                    {
                        if (count != stormAura->GetStackAmount())
                            stormAura->SetStackAmount(count);

                        if (stormAura->GetStackAmount() > 1)
                        {
                            stormAura->GetEffect(1)->ChangeAmount(-70);
                            stormAura->GetEffect(2)->ChangeAmount(-70);
                            stormAura->GetEffect(3)->ChangeAmount(-70);
                            stormAura->GetEffect(4)->ChangeAmount(-70);
                        }
                        else
                        {
                            stormAura->GetEffect(1)->ChangeAmount(-30);
                            stormAura->GetEffect(2)->ChangeAmount(-30);
                            stormAura->GetEffect(3)->ChangeAmount(-30);
                            stormAura->GetEffect(4)->ChangeAmount(-30);
                        }
                    }
                }
            }

            void OnRemove(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                {
                    for (uint8 i = 0; i < 3; ++i)
                        caster->RemoveAura(visualMorph[i]);

                    for (Unit::ControlList::const_iterator itr = caster->m_Controlled.begin(); itr != caster->m_Controlled.end(); ++itr)
                    {
                        if ((*itr)->GetEntry() == 69680 || (*itr)->GetEntry() == 69792 || (*itr)->GetEntry() == 69791)
                        {
                            if (Creature* spirit = (*itr)->ToCreature())
                            {
                                spirit->GetMotionMaster()->Clear();
                                spirit->GetMotionMaster()->MoveJump(caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), 15.0f, 10.0f, spirit->GetOrientation(), 1);
                            }
                        }
                    }
                }
            }

            void Register()
            {
                OnEffectUpdate += AuraEffectUpdateFn(spell_monk_storm_earth_and_fire_AuraScript::OnUpdate, EFFECT_2, SPELL_AURA_DUMMY);
                AfterEffectRemove += AuraEffectRemoveFn(spell_monk_storm_earth_and_fire_AuraScript::OnRemove, EFFECT_2, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_monk_storm_earth_and_fire_AuraScript();
        }
};

// Chi Brew - 115399
class spell_monk_chi_brew: public SpellScriptLoader
{
    public:
        spell_monk_chi_brew() : SpellScriptLoader("spell_monk_chi_brew") { }

        class spell_monk_chi_brew_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_chi_brew_SpellScript);

            bool Validate(SpellInfo const* /*spellEntry*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_CHI_BREW))
                    return false;
                return true;
            }

            void HandleOnHit()
            {
                if (Player* _player = GetCaster()->ToPlayer())
                {
                    if (Unit* target = GetHitUnit())
                    {
                        bool mastery = false;
                        // Mastery: Bottled Fury
                        float Mastery = _player->GetFloatValue(PLAYER_FIELD_MASTERY) * 2.5f;
                        if (_player->HasAura(SPELL_MONK_MASTERY_BOTTLED_FURY) && roll_chance_f(Mastery))
                            mastery = true;

                        switch (_player->GetSpecializationId(_player->GetActiveSpec()))
                        {
                            case SPEC_MONK_BREWMASTER:
                                _player->CastSpell(_player, SPELL_MONK_ELUSIVE_BREW_STACKS, true);
                                _player->CastSpell(_player, SPELL_MONK_ELUSIVE_BREW_STACKS, true);
                                break;
                            case SPEC_MONK_MISTWEAVER:
                                _player->CastSpell(_player, SPELL_MONK_MANA_TEA_STACKS, true);
                                _player->CastSpell(_player, SPELL_MONK_MANA_TEA_STACKS, true);
                                break;
                            case SPEC_MONK_WINDWALKER:
                                _player->CastSpell(_player, SPELL_MONK_TIGEREYE_BREW_STACKS, true);
                                _player->CastSpell(_player, SPELL_MONK_TIGEREYE_BREW_STACKS, true);

                                if (mastery)
                                    _player->CastSpell(_player, SPELL_MONK_TIGEREYE_BREW_STACKS, true);
                                break;
                            default:
                                break;
                        }
                    }
                }
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_monk_chi_brew_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_chi_brew_SpellScript();
        }
};

// Chi Wave (healing bolt) - 132464
class spell_monk_chi_wave_healing_bolt: public SpellScriptLoader
{
    public:
        spell_monk_chi_wave_healing_bolt() : SpellScriptLoader("spell_monk_chi_wave_healing_bolt") { }

        class spell_monk_chi_wave_healing_bolt_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_chi_wave_healing_bolt_SpellScript);

            void HandleOnHit()
            {
                if (!GetOriginalCaster())
                    return;

                if (Player* _player = GetOriginalCaster()->ToPlayer())
                    if (Unit* target = GetHitUnit())
                        _player->CastSpell(target, SPELL_MONK_CHI_WAVE_HEAL, true);
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_monk_chi_wave_healing_bolt_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_chi_wave_healing_bolt_SpellScript();
        }
};

// Chi Wave (damage) - 132467 and Chi Wave (heal) - 132463
class spell_monk_chi_wave_bolt: public SpellScriptLoader
{
    public:
        spell_monk_chi_wave_bolt() : SpellScriptLoader("spell_monk_chi_wave_bolt") { }

        class spell_monk_chi_wave_bolt_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_chi_wave_bolt_SpellScript);

            void HandleOnHit()
            {
                if (Unit* _player = GetOriginalCaster())
                {
                    if (Unit* target = GetHitUnit())
                    {
                        uint8 count = 0;
                        std::list<Unit*> targetList;
                        std::vector<uint64> validTargets;

                        if (AuraEffectPtr chiWave = _player->GetAuraEffect(SPELL_MONK_CHI_WAVE_TALENT_AURA, EFFECT_1))
                        {
                            count = chiWave->GetAmount();

                            if (count >= 7)
                            {
                                _player->RemoveAura(SPELL_MONK_CHI_WAVE_TALENT_AURA);
                                return;
                            }

                            count++;
                            chiWave->SetAmount(count);
                        }
                        else
                            return;

                        CellCoord p(JadeCore::ComputeCellCoord(target->GetPositionX(), target->GetPositionY()));
                        Cell cell(p);
                        cell.SetNoCreate();

                        JadeCore::AnyUnitInObjectRangeCheck u_check(_player, 20.0f);
                        JadeCore::UnitListSearcher<JadeCore::AnyUnitInObjectRangeCheck> searcher(_player, targetList, u_check);

                        TypeContainerVisitor<JadeCore::UnitListSearcher<JadeCore::AnyUnitInObjectRangeCheck>, WorldTypeMapContainer> world_unit_searcher(searcher);
                        TypeContainerVisitor<JadeCore::UnitListSearcher<JadeCore::AnyUnitInObjectRangeCheck>, GridTypeMapContainer>  grid_unit_searcher(searcher);

                        cell.Visit(p, world_unit_searcher, *_player->GetMap(), *_player, 20.0f);
                        cell.Visit(p, grid_unit_searcher, *_player->GetMap(), *_player, 20.0f);

                        for (auto itr : targetList)
                        {
                            if (!itr->IsWithinLOSInMap(_player))
                                continue;

                            if (itr == target)
                                continue;

                            validTargets.push_back(itr->GetGUID());
                        }

                        if (validTargets.empty())
                        {
                            _player->RemoveAurasDueToSpell(SPELL_MONK_CHI_WAVE_TALENT_AURA);
                            return;
                        }

                        std::random_shuffle(validTargets.begin(), validTargets.end());

                        if (Unit* newTarget = sObjectAccessor->FindUnit(validTargets.front()))
                        {
                            if (_player->IsValidAttackTarget(newTarget))
                                target->CastSpell(newTarget, SPELL_MONK_CHI_WAVE_DAMAGE, true, NULL, NULLAURA_EFFECT, _player->GetGUID());
                            else
                            {
                                std::list<Unit*> alliesList;

                                for (auto itr : validTargets)
                                {
                                    Unit* allyTarget = sObjectAccessor->FindUnit(itr);
                                    if (!allyTarget)
                                        continue;

                                    if (_player->IsValidAttackTarget(allyTarget))
                                        continue;

                                    alliesList.push_back(sObjectAccessor->FindUnit(itr));
                                }

                                if (alliesList.empty())
                                    return;

                                alliesList.sort(JadeCore::HealthPctOrderPred());

                                target->CastSpell(alliesList.front(), SPELL_MONK_CHI_WAVE_HEALING_BOLT, true, NULL, NULLAURA_EFFECT, _player->GetGUID());
                            }
                        }
                    }
                }
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_monk_chi_wave_bolt_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_chi_wave_bolt_SpellScript();
        }
};

// Chi Wave (talent) - 115098
class spell_monk_chi_wave: public SpellScriptLoader
{
    public:
        spell_monk_chi_wave() : SpellScriptLoader("spell_monk_chi_wave") { }

        class spell_monk_chi_wave_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_chi_wave_SpellScript);

            uint64 targetGUID;
            bool done;

            bool Load()
            {
                targetGUID = 0;
                done = false;
                return true;
            }

            void HandleDummy(SpellEffIndex effIndex)
            {
                if (Unit* target = GetHitUnit())
                    targetGUID = target->GetGUID();
            }

            void HandleApplyAura()
            {
                if (!targetGUID || done)
                    return;

                if (Player* _player = GetCaster()->ToPlayer())
                {
                    if (Unit* target = sObjectAccessor->FindUnit(targetGUID))
                    {
                        _player->CastSpell(target, _player->IsValidAttackTarget(target) ? SPELL_MONK_CHI_WAVE_DAMAGE : SPELL_MONK_CHI_WAVE_HEALING_BOLT, true);
                        done = true;
                    }
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_monk_chi_wave_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                AfterHit += SpellHitFn(spell_monk_chi_wave_SpellScript::HandleApplyAura);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_chi_wave_SpellScript();
        }
};

// Transcendence : Transfer - 119996
class spell_monk_transcendence_transfer: public SpellScriptLoader
{
    public:
        spell_monk_transcendence_transfer() : SpellScriptLoader("spell_monk_transcendence_transfer") { }

        class spell_monk_transcendence_transfer_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_transcendence_transfer_SpellScript);

            SpellCastResult CheckSpiritRange()
            {
                if (Unit* caster = GetCaster())
                {
                    for (Unit::ControlList::const_iterator itr = caster->m_Controlled.begin(); itr != caster->m_Controlled.end(); ++itr)
                    {
                        if ((*itr)->GetEntry() == 54569)
                        {
                            if ((*itr)->GetDistance(caster) > 40.0f)
                                return SPELL_FAILED_DONT_REPORT;
                        }
                    }
                }

                return SPELL_CAST_OK;
            }

            void HandleDummy()
            {
                if (Unit* caster = GetCaster())
                {
                    for (Unit::ControlList::const_iterator itr = caster->m_Controlled.begin(); itr != caster->m_Controlled.end(); ++itr)
                    {
                        if ((*itr)->GetEntry() == 54569)
                        {
                            Creature* clone = (*itr)->ToCreature();
                            if (clone && clone->AI())
                                clone->AI()->DoAction(1);
                        }
                    }
                }
            }

            void Register()
            {
                OnCheckCast += SpellCheckCastFn(spell_monk_transcendence_transfer_SpellScript::CheckSpiritRange);
                OnHit += SpellHitFn(spell_monk_transcendence_transfer_SpellScript::HandleDummy);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_transcendence_transfer_SpellScript();
        }
};

// Dampen Harm - 122278
class spell_monk_dampen_harm: public SpellScriptLoader
{
    public:
        spell_monk_dampen_harm() : SpellScriptLoader("spell_monk_dampen_harm") { }

        class spell_monk_dampen_harm_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_dampen_harm_AuraScript);

            uint32 healthPct;

            bool Load()
            {
                healthPct = GetSpellInfo()->Effects[EFFECT_0].CalcValue(GetCaster());
                return GetUnitOwner()->ToPlayer();
            }

            void CalculateAmount(constAuraEffectPtr /*auraEffect*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                amount = -1;
            }

            void Absorb(AuraEffectPtr auraEffect, DamageInfo& dmgInfo, uint32& absorbAmount)
            {
                Unit* target = GetTarget();

                uint32 health = target->CountPctFromMaxHealth(healthPct);

                if (dmgInfo.GetDamage() < health)
                    return;

                // The next 3 attacks within 45 sec that deal damage equal to 10% or more of your total health are reduced by half
                absorbAmount = dmgInfo.GetDamage() / 2;
                auraEffect->GetBase()->DropCharge();
            }

            void Register()
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_monk_dampen_harm_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
                OnEffectAbsorb += AuraEffectAbsorbFn(spell_monk_dampen_harm_AuraScript::Absorb, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_monk_dampen_harm_AuraScript();
        }
};

// Called by Thunder Focus Tea - 116680
// Item S12 4P - Mistweaver - 124487
class spell_monk_item_s12_4p_mistweaver: public SpellScriptLoader
{
    public:
        spell_monk_item_s12_4p_mistweaver() : SpellScriptLoader("spell_monk_item_s12_4p_mistweaver") { }

        class spell_monk_item_s12_4p_mistweaver_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_item_s12_4p_mistweaver_SpellScript);

            void HandleOnHit()
            {
                if (Player* _player = GetCaster()->ToPlayer())
                    if (_player->HasAura(SPELL_MONK_ITEM_4_S12_MISTWEAVER))
                        _player->CastSpell(_player, SPELL_MONK_ZEN_FOCUS, true);
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_monk_item_s12_4p_mistweaver_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_item_s12_4p_mistweaver_SpellScript();
        }
};

struct auraData
{
    auraData(uint32 id, uint64 casterGUID) : m_id(id), m_casterGuid(casterGUID) {}
    uint32 m_id;
    uint64 m_casterGuid;
};

// Diffuse Magic - 122783
class spell_monk_diffuse_magic: public SpellScriptLoader
{
    public:
        spell_monk_diffuse_magic() : SpellScriptLoader("spell_monk_diffuse_magic") { }

        class spell_monk_diffuse_magic_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_diffuse_magic_SpellScript);

            void HandleOnHit()
            {
                if (Player* _player = GetCaster()->ToPlayer())
                {
                    std::set<auraData*> auraListToRemove;
                    Unit::AuraApplicationMap AuraList = _player->GetAppliedAuras();
                    for (Unit::AuraApplicationMap::iterator iter = AuraList.begin(); iter != AuraList.end(); ++iter)
                    {
                        AuraPtr aura = iter->second->GetBase();
                        if (!aura)
                            continue;

                        Unit* caster = aura->GetCaster();
                        if (!caster || caster->GetGUID() == _player->GetGUID())
                            continue;

                        if (!caster->IsWithinDist(_player, 40.0f))
                            continue;

                        if (aura->GetSpellInfo()->IsPositive())
                            continue;

                        if (!(aura->GetSpellInfo()->GetSchoolMask() & SPELL_SCHOOL_MASK_MAGIC))
                            continue;

                        _player->AddAura(aura->GetSpellInfo()->Id, caster);

                        if (AuraPtr targetAura = caster->GetAura(aura->GetSpellInfo()->Id, _player->GetGUID()))
                        {
                            for (int i = 0; i < MAX_SPELL_EFFECTS; ++i)
                            {
                                if (targetAura->GetEffect(i) && aura->GetEffect(i))
                                {
                                    AuraEffectPtr auraEffect = _player->GetAuraEffect(aura->GetSpellInfo()->Id, i);
                                    if (!auraEffect)
                                        continue;

                                    int32 damage = auraEffect->GetAmount();

                                    // need to check auraEffect pointer here !!
                                    if (auraEffect->GetAuraType() == SPELL_AURA_PERIODIC_DAMAGE ||
                                        auraEffect->GetAuraType() == SPELL_AURA_PERIODIC_DAMAGE_PERCENT)
                                        damage = caster->SpellDamageBonusDone(_player, aura->GetSpellInfo(), damage, auraEffect->GetEffIndex(), DOT, auraEffect->GetBase()->GetStackAmount());

                                    targetAura->GetEffect(i)->SetAmount(damage);
                                }
                            }
                        }

                        auraListToRemove.insert(new auraData(aura->GetSpellInfo()->Id, caster->GetGUID()));
                    }

                    for (std::set<auraData*>::iterator itr = auraListToRemove.begin(); itr != auraListToRemove.end(); ++itr)
                    {
                        _player->RemoveAura((*itr)->m_id, (*itr)->m_casterGuid);
                        delete (*itr);
                    }

                    auraListToRemove.clear();
                }
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_monk_diffuse_magic_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_diffuse_magic_SpellScript();
        }
};

// Summon Black Ox Statue - 115315
class spell_monk_black_ox_statue: public SpellScriptLoader
{
    public:
        spell_monk_black_ox_statue() : SpellScriptLoader("spell_monk_black_ox_statue") { }

        class spell_monk_black_ox_statue_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_black_ox_statue_SpellScript)

            void HandleSummon(SpellEffIndex effIndex)
            {
                if (Player* player = GetCaster()->ToPlayer())
                {
                    PreventHitDefaultEffect(effIndex);

                    const SpellInfo* spell = GetSpellInfo();
                    std::list<Creature*> tempList;
                    std::list<Creature*> blackOxList;

                    player->GetCreatureListWithEntryInGrid(tempList, MONK_NPC_BLACK_OX_STATUE, 500.0f);

                    for (auto itr : tempList)
                        blackOxList.push_back(itr);

                    // Remove other players jade statue
                    for (std::list<Creature*>::iterator i = tempList.begin(); i != tempList.end(); ++i)
                    {
                        Unit* owner = (*i)->GetOwner();
                        if (owner && owner == player && (*i)->isSummon())
                            continue;

                        blackOxList.remove((*i));
                    }

                    // 1 statue max
                    if ((int32)blackOxList.size() >= spell->Effects[effIndex].BasePoints)
                        blackOxList.back()->ToTempSummon()->UnSummon();

                    Position pos;
                    GetExplTargetDest()->GetPosition(&pos);
                    const SummonPropertiesEntry* properties = sSummonPropertiesStore.LookupEntry(spell->Effects[effIndex].MiscValueB);
                    TempSummon* summon = player->SummonCreature(spell->Effects[effIndex].MiscValue, pos, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, spell->GetDuration());
                    if (!summon)
                        return;

                    summon->SetGuidValue(UNIT_FIELD_SUMMONED_BY, player->GetGUID());
                    summon->setFaction(player->getFaction());
                    summon->SetUInt32Value(UNIT_FIELD_CREATED_BY_SPELL, GetSpellInfo()->Id);
                    summon->SetMaxHealth(player->CountPctFromMaxHealth(50));
                    summon->SetHealth(summon->GetMaxHealth());
                    summon->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_HEAL, true);
                    summon->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_PERIODIC_HEAL, true);
                    summon->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_HEAL_PCT, true);
                }
            }

            void Register()
            {
                OnEffectHit += SpellEffectFn(spell_monk_black_ox_statue_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_black_ox_statue_SpellScript();
        }

};

/// last update : 6.1.2 19802
// Guard - 115295 and Guard - 118604
class spell_monk_guard: public SpellScriptLoader
{
    public:
        spell_monk_guard() : SpellScriptLoader("spell_monk_guard") { }

        class spell_monk_guard_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_guard_AuraScript);

            void CalculateAmount(constAuraEffectPtr /*aurEff*/, int32 & p_Amount, bool & /*canBeRecalculated*/)
            {
                Unit* l_Caster = GetCaster();
                if (!l_Caster)
                    return;

                if (l_Caster->GetTypeId() == TYPEID_PLAYER)
                    p_Amount += int32(l_Caster->GetTotalAttackPowerValue(WeaponAttackType::BaseAttack) * 18);
                else if (Unit* l_Player = GetCaster()->GetOwner()) // For Black Ox Statue
                    p_Amount += int32(l_Player->GetTotalAttackPowerValue(WeaponAttackType::BaseAttack) * 18);
            }

            void Register()
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_monk_guard_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_monk_guard_AuraScript();
        }
};

// Zen Flight - 125883
class spell_monk_zen_flight_check: public SpellScriptLoader
{
    public:
        spell_monk_zen_flight_check() : SpellScriptLoader("spell_monk_zen_flight_check") { }

        class spell_monk_zen_flight_check_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_zen_flight_check_SpellScript);

            SpellCastResult CheckTarget()
            {
                if (Player* _player = GetCaster()->ToPlayer())
                {
                    if (_player->GetMap()->IsBattlegroundOrArena())
                        return SPELL_FAILED_NOT_IN_BATTLEGROUND;

                    // In Kalimdor or Eastern Kingdom with Flight Master's License
                    if (!_player->HasSpell(90267) && (_player->GetMapId() == 1 || _player->GetMapId() == 0))
                        return SPELL_FAILED_NOT_HERE;

                    // In Pandaria with Wisdom of the Four Winds
                    if (!_player->HasSpell(115913) && (_player->GetMapId() == 870))
                        return SPELL_FAILED_NOT_HERE;
                }

                return SPELL_CAST_OK;
            }

            void Register()
            {
                OnCheckCast += SpellCheckCastFn(spell_monk_zen_flight_check_SpellScript::CheckTarget);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_zen_flight_check_SpellScript();
        }
};

// Glyph of Zen Flight - 125893
class spell_monk_glyph_of_zen_flight: public SpellScriptLoader
{
    public:
        spell_monk_glyph_of_zen_flight() : SpellScriptLoader("spell_monk_glyph_of_zen_flight") { }

        class spell_monk_glyph_of_zen_flight_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_glyph_of_zen_flight_AuraScript);

            void OnApply(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Player* _player = GetTarget()->ToPlayer())
                    _player->learnSpell(SPELL_MONK_ZEN_FLIGHT, false);
            }

            void OnRemove(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Player* _player = GetTarget()->ToPlayer())
                    if (_player->HasSpell(SPELL_MONK_ZEN_FLIGHT))
                        _player->removeSpell(SPELL_MONK_ZEN_FLIGHT, false, false);
            }

            void Register()
            {
                OnEffectApply += AuraEffectApplyFn(spell_monk_glyph_of_zen_flight_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_monk_glyph_of_zen_flight_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_monk_glyph_of_zen_flight_AuraScript();
        }
};

// Called by Jab - 100780, Soothing Mist (Energize) - 116335, Spinning Crane Kick (Energize) - 129881
// Crackling Jade Lightning (Energize) - 123333 and Expel Harm - 115072
// Power Strikes - 121817
class spell_monk_power_strikes: public SpellScriptLoader
{
    public:
        spell_monk_power_strikes() : SpellScriptLoader("spell_monk_power_strikes") { }

        class spell_monk_power_strikes_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_power_strikes_SpellScript)

            void HandleAfterCast()
            {
                if (Player* l_Player = GetCaster()->ToPlayer())
                {
                    if (l_Player->HasAura(SPELL_MONK_POWER_STRIKES_AURA))
                    {
                        if (l_Player->GetPower(POWER_CHI) >= l_Player->GetMaxPower(POWER_CHI))
                            l_Player->CastSpell(l_Player, SPELL_MONK_CREATE_CHI_SPHERE, true);
                        l_Player->RemoveAura(SPELL_MONK_POWER_STRIKES_AURA);
                    }
                }
            }

            void Register()
            {
                AfterCast += SpellCastFn(spell_monk_power_strikes_SpellScript::HandleAfterCast);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_power_strikes_SpellScript();
        }
};

// Crackling Jade Lightning - 117952
class spell_monk_crackling_jade_lightning: public SpellScriptLoader
{
    public:
        spell_monk_crackling_jade_lightning() : SpellScriptLoader("spell_monk_crackling_jade_lightning") { }

        class spell_monk_crackling_jade_lightning_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_crackling_jade_lightning_AuraScript);

            void OnTick(constAuraEffectPtr aurEff)
            {
                if (!GetCaster())
                    return;

                if (Player* l_Player = GetCaster()->ToPlayer())
                {
                    if (l_Player->GetSpecializationId(l_Player->GetActiveSpec()) == SPEC_MONK_MISTWEAVER)
                        l_Player->CastSpell(l_Player, SPELL_MONK_JADE_LIGHTNING_ENERGIZE, true);
                }
            }

            void OnProc(constAuraEffectPtr aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                if (!GetCaster())
                    return;

                if (eventInfo.GetActor()->GetGUID() != GetTarget()->GetGUID())
                    return;

                if (Player* l_Player = GetCaster()->ToPlayer())
                {
                    if (GetTarget()->HasAura(aurEff->GetSpellInfo()->Id, l_Player->GetGUID()))
                    {
                        const SpellInfo *l_SpellInfo = sSpellMgr->GetSpellInfo(SPELL_MONK_CRACKLING_JADE_SHOCK_BUMP);

                        if (!l_Player->HasSpellCooldown(SPELL_MONK_CRACKLING_JADE_SHOCK_BUMP) && l_SpellInfo != nullptr)
                        {
                            l_Player->CastSpell(GetTarget(), SPELL_MONK_CRACKLING_JADE_SHOCK_BUMP, true);
                            l_Player->AddSpellCooldown(SPELL_MONK_CRACKLING_JADE_SHOCK_BUMP, 0, l_SpellInfo->RecoveryTime);
                        }
                    }
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_monk_crackling_jade_lightning_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
                OnEffectProc += AuraEffectProcFn(spell_monk_crackling_jade_lightning_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_monk_crackling_jade_lightning_AuraScript();
        }
};

// Touch of Karma - 122470
class spell_monk_touch_of_karma: public SpellScriptLoader
{
    public:
        spell_monk_touch_of_karma() : SpellScriptLoader("spell_monk_touch_of_karma") { }

        class spell_monk_touch_of_karma_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_touch_of_karma_AuraScript);

            uint32 totalAbsorbAmount;

            bool Load()
            {
                totalAbsorbAmount = 0;
                return true;
            }

            void CalculateAmount(constAuraEffectPtr /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                if (GetCaster())
                    amount = GetCaster()->GetMaxHealth();
            }

            void OnAbsorb(AuraEffectPtr aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
            {
                if (Unit* caster = dmgInfo.GetVictim())
                {
                    if (Unit* attacker = dmgInfo.GetAttacker())
                    {
                        totalAbsorbAmount += dmgInfo.GetDamage();

                        if (attacker->HasAura(aurEff->GetSpellInfo()->Id, caster->GetGUID()))
                            caster->CastCustomSpell(SPELL_MONK_TOUCH_OF_KARMA_REDIRECT_DAMAGE, SPELLVALUE_BASE_POINT0, (totalAbsorbAmount / 16), attacker);
                    }
                }
            }

            void Register()
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_monk_touch_of_karma_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB);
                OnEffectAbsorb += AuraEffectAbsorbFn(spell_monk_touch_of_karma_AuraScript::OnAbsorb, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_monk_touch_of_karma_AuraScript();
        }
};

// Called by Uplift - 116670 and Uplift - 130316
// Thunder Focus Tea - 116680
class spell_monk_thunder_focus_tea: public SpellScriptLoader
{
    public:
        spell_monk_thunder_focus_tea() : SpellScriptLoader("spell_monk_thunder_focus_tea") { }

        class spell_monk_thunder_focus_tea_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_thunder_focus_tea_SpellScript)

            void FilterTargets(std::list<WorldObject*>& unitList)
            {
                unitList.remove_if(JadeCore::UnitAuraCheck(false, SPELL_MONK_RENEWING_MIST_HOT, GetCaster()->GetGUID()));
            }

            void HandleOnHit()
            {
                if (Player* _player = GetCaster()->ToPlayer())
                {
                    if (Unit* target = GetHitUnit())
                    {
                        if (_player->HasAura(SPELL_MONK_THUNDER_FOCUS_TEA))
                        {
                            std::list<Unit*> groupList;

                            _player->GetRaidMembers(groupList);

                            for (auto itr : groupList)
                                if (AuraPtr renewingMistGroup = itr->GetAura(SPELL_MONK_RENEWING_MIST_HOT, _player->GetGUID()))
                                    renewingMistGroup->RefreshDuration();

                            _player->RemoveAura(SPELL_MONK_THUNDER_FOCUS_TEA);
                        }
                    }
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_monk_thunder_focus_tea_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_CASTER_AREA_RAID);
                OnHit += SpellHitFn(spell_monk_thunder_focus_tea_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_thunder_focus_tea_SpellScript();
        }
};

/// last update : 6.1.2 19802
/// Eminence - 126890 and Eminence (status) - 117895
class spell_monk_eminence_heal : public SpellScriptLoader
{
    public:
    spell_monk_eminence_heal() : SpellScriptLoader("spell_monk_eminence_heal") { }

    class spell_monk_eminence_heal_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_eminence_heal_SpellScript);

        void FilterTargets(std::list<WorldObject*>& p_Targets)
        {
            Unit* l_Caster = GetCaster();

            for (std::list<WorldObject*>::iterator l_Itr = p_Targets.begin(); l_Itr != p_Targets.end();)
            {
                if ((*l_Itr) == nullptr || (*l_Itr)->ToUnit() == nullptr || !(*l_Itr)->ToUnit()->IsInRaidWith(l_Caster) || (*l_Itr)->ToUnit()->GetGUID() == l_Caster->GetGUID() || !l_Caster->IsValidAssistTarget((*l_Itr)->ToUnit()))
                    l_Itr = p_Targets.erase(l_Itr);
               else
                   l_Itr++;
            }

            if (p_Targets.size() > 1)
            {
                p_Targets.sort(JadeCore::HealthPctOrderPred());
                p_Targets.resize(1);
            }

        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_monk_eminence_heal_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_eminence_heal_SpellScript();
    }
};

// Summon Jade Serpent Statue - 115313
class spell_monk_jade_serpent_statue: public SpellScriptLoader
{
    public:
        spell_monk_jade_serpent_statue() : SpellScriptLoader("spell_monk_jade_serpent_statue") { }

        class spell_monk_jade_serpent_statue_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_jade_serpent_statue_SpellScript)

            void HandleSummon(SpellEffIndex effIndex)
            {
                if (Player* player = GetCaster()->ToPlayer())
                {
                    PreventHitDefaultEffect(effIndex);

                    const SpellInfo* spell = GetSpellInfo();
                    std::list<Creature*> tempList;
                    std::list<Creature*> jadeSerpentlist;

                    player->GetCreatureListWithEntryInGrid(tempList, MONK_NPC_JADE_SERPENT_STATUE, 500.0f);
                    player->GetCreatureListWithEntryInGrid(jadeSerpentlist, MONK_NPC_JADE_SERPENT_STATUE, 500.0f);

                    // Remove other players jade statue
                    for (std::list<Creature*>::iterator i = tempList.begin(); i != tempList.end(); ++i)
                    {
                        Unit* owner = (*i)->GetOwner();
                        if (owner && owner == player && (*i)->isSummon())
                            continue;

                        jadeSerpentlist.remove((*i));
                    }

                    // 1 statue max
                    if ((int32)jadeSerpentlist.size() >= spell->Effects[effIndex].BasePoints)
                        jadeSerpentlist.back()->ToTempSummon()->UnSummon();

                    Position pos;
                    GetExplTargetDest()->GetPosition(&pos);
                    const SummonPropertiesEntry* properties = sSummonPropertiesStore.LookupEntry(spell->Effects[effIndex].MiscValueB);
                    TempSummon* summon = player->SummonCreature(spell->Effects[effIndex].MiscValue, pos, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, spell->GetDuration());
                    if (!summon)
                        return;

                    summon->SetGuidValue(UNIT_FIELD_SUMMONED_BY, player->GetGUID());
                    summon->setFaction(player->getFaction());
                    summon->SetUInt32Value(UNIT_FIELD_CREATED_BY_SPELL, GetSpellInfo()->Id);
                    summon->SetMaxHealth(player->CountPctFromMaxHealth(50));
                    summon->SetHealth(summon->GetMaxHealth());
                }
            }

            void Register()
            {
                OnEffectHit += SpellEffectFn(spell_monk_jade_serpent_statue_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_jade_serpent_statue_SpellScript();
        }
};

// Called by Spinning Crane Kick - 107270
// Teachings of the Monastery - 116645
class spell_monk_teachings_of_the_monastery: public SpellScriptLoader
{
    public:
        spell_monk_teachings_of_the_monastery() : SpellScriptLoader("spell_monk_teachings_of_the_monastery") { }

        class spell_monk_teachings_of_the_monastery_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_teachings_of_the_monastery_SpellScript);

            void HandleHeal()
            {
                Unit* l_Caster = GetCaster();
                if (!l_Caster->HasAura(SPELL_MONK_STANCE_OF_THE_WISE_SERPENT))
                    return;

                std::list<Player*> l_TempListPlayer;

                l_Caster->GetPlayerListInGrid(l_TempListPlayer, 8.0f);
                for (std::list<Player*>::iterator i = l_TempListPlayer.begin(); i != l_TempListPlayer.end(); ++i)
                {
                    if ((*i)->IsFriendlyTo(l_Caster))
                        l_Caster->CastSpell((*i), SPELL_MONK_SPINNING_CRANE_KICK_HEAL, true);
                }
            }

            void Register()
            {
                OnCast += SpellCastFn(spell_monk_teachings_of_the_monastery_SpellScript::HandleHeal);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_teachings_of_the_monastery_SpellScript();
        }
};

// Mana Tea - 115294
class spell_monk_mana_tea: public SpellScriptLoader
{
    public:
        spell_monk_mana_tea() : SpellScriptLoader("spell_monk_mana_tea") { }

        class spell_monk_mana_tea_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_mana_tea_SpellScript);

            SpellModifier* spellMod;

            void HandleBeforeCast()
            {
                if (Player* _player = GetCaster()->ToPlayer())
                {
                    int32 stacks = 0;

                    if (AuraPtr manaTeaStacks = _player->GetAura(SPELL_MONK_MANA_TEA_STACKS))
                        stacks = manaTeaStacks->GetStackAmount();

                    int32 newDuration = (stacks * IN_MILLISECONDS) / 2;

                    spellMod = new SpellModifier();
                    spellMod->op = SPELLMOD_DURATION;
                    spellMod->type = SPELLMOD_FLAT;
                    spellMod->spellId = SPELL_MONK_MANA_TEA_REGEN;
                    spellMod->value = newDuration;
                    spellMod->mask[1] = 0x200000;
                    spellMod->mask[2] = 0x1;

                    _player->AddSpellMod(spellMod, true);
                }
            }

            void HandleAfterCast()
            {
                if (Player* _player = GetCaster()->ToPlayer())
                {
                    _player->AddSpellMod(spellMod, false);

                    if (AuraApplication* aura = _player->GetAuraApplication(SPELL_MONK_MANA_TEA_REGEN))
                    {
                        AuraPtr manaTea = aura->GetBase();
                        int32 newDuration = manaTea->GetDuration() - 1000;
                        manaTea->SetDuration(newDuration);
                    }
                }
            }

            void Register()
            {
                BeforeCast += SpellCastFn(spell_monk_mana_tea_SpellScript::HandleBeforeCast);
                AfterCast += SpellCastFn(spell_monk_mana_tea_SpellScript::HandleAfterCast);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_mana_tea_SpellScript();
        }

        class spell_monk_mana_tea_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_mana_tea_AuraScript);

            void OnTick(constAuraEffectPtr aurEff)
            {
                if (GetCaster())
                {
                    // remove one charge per tick instead of remove aura on cast
                    // "Cancelling the channel will not waste stacks"
                    if (AuraPtr manaTea = GetCaster()->GetAura(SPELL_MONK_MANA_TEA_STACKS))
                    {
                        if (manaTea->GetStackAmount() > 1)
                            manaTea->SetStackAmount(manaTea->GetStackAmount() - 1);
                        else
                            GetCaster()->RemoveAura(SPELL_MONK_MANA_TEA_STACKS);
                    }
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_monk_mana_tea_AuraScript::OnTick, EFFECT_0, SPELL_AURA_OBS_MOD_POWER);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_monk_mana_tea_AuraScript();
        }
};

// Brewing : Mana Tea - 123766
class spell_monk_mana_tea_stacks: public SpellScriptLoader
{
    public:
        spell_monk_mana_tea_stacks() : SpellScriptLoader("spell_monk_mana_tea_stacks") { }

        class spell_monk_mana_tea_stacks_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_mana_tea_stacks_AuraScript);

            uint32 chiConsumed;

            void OnApply(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                chiConsumed = 0;
            }

            void SetData(uint32 type, uint32 data)
            {
                while ((chiConsumed += data) >= 4)
                {
                    chiConsumed = 0;
                    data = data > 4 ? data - 4: 0;

                    if (GetCaster())
                    {
                        GetCaster()->CastSpell(GetCaster(), SPELL_MONK_MANA_TEA_STACKS, true);
                        GetCaster()->CastSpell(GetCaster(), SPELL_MONK_PLUS_ONE_MANA_TEA, true);
                    }

                    // Brewing: Mana Tea passive bonus
                    float crit_chance = 0.0f;
                    crit_chance += GetCaster()->GetFloatValue(PLAYER_FIELD_SPELL_CRIT_PERCENTAGE + SPELL_SCHOOL_MASK_NORMAL);
                    if (roll_chance_f(crit_chance))
                    {
                        if (GetCaster())
                        {
                            GetCaster()->CastSpell(GetCaster(), SPELL_MONK_MANA_TEA_STACKS, true);
                            GetCaster()->CastSpell(GetCaster(), SPELL_MONK_PLUS_ONE_MANA_TEA, true);
                        }
                    }
                }
            }

            void Register()
            {
                AfterEffectApply += AuraEffectApplyFn(spell_monk_mana_tea_stacks_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_monk_mana_tea_stacks_AuraScript();
        }
};

// Enveloping Mist - 124682
class spell_monk_enveloping_mist: public SpellScriptLoader
{
    public:
        spell_monk_enveloping_mist() : SpellScriptLoader("spell_monk_enveloping_mist") { }

        class spell_monk_enveloping_mist_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_enveloping_mist_SpellScript);

            void HandleAfterCast()
            {
                if (Player* _player = GetCaster()->ToPlayer())
                    if (Unit* target = GetExplTargetUnit())
                        _player->CastSpell(target, SPELL_MONK_ENVELOPING_MIST_HEAL, true);
            }

            void HandleOnPrepare()
            {
                if (Player* l_Player = GetCaster()->ToPlayer())
                {
                    if (l_Player->GetCurrentSpell(CURRENT_CHANNELED_SPELL) && l_Player->GetCurrentSpell(CURRENT_CHANNELED_SPELL)->GetSpellInfo()->Id == 115175)
                    {
                        TriggerCastFlags l_Flags = TriggerCastFlags(GetSpell()->getTriggerCastFlags() | TRIGGERED_CAST_DIRECTLY);
                        GetSpell()->setTriggerCastFlags(l_Flags);
                    }
                }
            }

            void Register()
            {
                AfterCast += SpellCastFn(spell_monk_enveloping_mist_SpellScript::HandleAfterCast);
                OnPrepare += SpellOnPrepareFn(spell_monk_enveloping_mist_SpellScript::HandleOnPrepare);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_enveloping_mist_SpellScript();
        }
};

// Surging Mist - 116694
class spell_monk_surging_mist: public SpellScriptLoader
{
    public:
        spell_monk_surging_mist() : SpellScriptLoader("spell_monk_surging_mist") { }

        class spell_monk_surging_mist_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_surging_mist_SpellScript);

            void HandleOnPrepare()
            {
                if (Player* l_Player = GetCaster()->ToPlayer())
                {
                    if (l_Player->GetCurrentSpell(CURRENT_CHANNELED_SPELL) && l_Player->GetCurrentSpell(CURRENT_CHANNELED_SPELL)->GetSpellInfo()->Id == SPELL_MONL_SOOTHING_MIST)
                    {
                        TriggerCastFlags l_Flags = TriggerCastFlags(GetSpell()->getTriggerCastFlags() | TRIGGERED_CAST_DIRECTLY);
                        GetSpell()->setTriggerCastFlags(l_Flags);
                    }
                }
            }

            void HandleHeal(SpellEffIndex effIndex)
            {
                Player* l_Caster = GetCaster()->ToPlayer();
                if (!l_Caster)
                    return;

                if (Unit* l_Target = GetExplTargetUnit())
                    l_Caster->CastSpell(l_Target, SPELL_MONK_SURGING_MIST_HEAL, true);
            }

            void HandleGivePower(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);

                Player* l_Caster = GetCaster()->ToPlayer();
                if (!l_Caster)
                    return;

                if (l_Caster->GetSpecializationId(l_Caster->GetActiveSpec()) != SPEC_MONK_MISTWEAVER)
                    return;

                GetSpell()->EffectEnergize(effIndex);
            }

            void Register()
            {
                OnPrepare += SpellOnPrepareFn(spell_monk_surging_mist_SpellScript::HandleOnPrepare);
                OnEffectHitTarget += SpellEffectFn(spell_monk_surging_mist_SpellScript::HandleGivePower, EFFECT_1, SPELL_EFFECT_ENERGIZE);
                OnEffectHitTarget += SpellEffectFn(spell_monk_surging_mist_SpellScript::HandleHeal, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_surging_mist_SpellScript();
        }
};

// Renewing Mist (heal) - 115151
class spell_monk_renewing_mist_hot: public SpellScriptLoader
{
    public:
        spell_monk_renewing_mist_hot() : SpellScriptLoader("spell_monk_renewing_mist_hot") { }

        class spell_monk_renewing_mist_hot_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_renewing_mist_hot_SpellScript);

            void HandleOnHit()
            {
                if (Unit* l_Caster = GetCaster())
                    if (Unit* l_Target = GetHitUnit())
                        l_Caster->CastSpell(l_Target, SPELL_MONK_RENEWING_MIST_HOT, true);
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_monk_renewing_mist_hot_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_renewing_mist_hot_SpellScript();
        }
};

// Renewing Mist - 119611
class spell_monk_renewing_mist: public SpellScriptLoader
{
    public:
        spell_monk_renewing_mist() : SpellScriptLoader("spell_monk_renewing_mist") { }

        class spell_monk_renewing_mist_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_renewing_mist_SpellScript);

            void HandleOnHit()
            {
                if (Player* _player = GetCaster()->ToPlayer())
                {
                    std::list<Unit*> playerList;
                    std::list<Creature*> tempList;
                    std::list<Creature*> statueList;
                    Creature* statue;

                    _player->GetRaidMembers(playerList);

                    if (playerList.size() > 1)
                    {
                        playerList.sort(JadeCore::HealthPctOrderPred());
                        playerList.resize(1);
                    }

                    _player->GetCreatureListWithEntryInGrid(tempList, 60849, 100.0f);
                    _player->GetCreatureListWithEntryInGrid(statueList, 60849, 100.0f);

                    // Remove other players jade statue
                    for (std::list<Creature*>::iterator i = tempList.begin(); i != tempList.end(); ++i)
                    {
                        Unit* owner = (*i)->GetOwner();
                        if (owner && owner == _player && (*i)->isSummon())
                            continue;

                        statueList.remove((*i));
                    }

                    for (auto itr : playerList)
                    {
                        if (statueList.size() == 1)
                        {
                            for (auto itrBis : statueList)
                                statue = itrBis;

                            if (statue && (statue->isPet() || statue->isGuardian()))
                            {
                                if (statue->GetOwner() && statue->GetOwner()->GetGUID() == _player->GetGUID())
                                {
                                    _player->AddAura(SPELL_MONK_RENEWING_MIST_HOT, itr);
                                    _player->CastSpell(itr, SPELL_MONK_RENEWING_MIST_JUMP_AURA, true);
                                }
                            }
                        }
                    }
                }
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_monk_renewing_mist_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_renewing_mist_SpellScript();
        }

        class spell_monk_renewing_mist_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_renewing_mist_AuraScript);

            uint32 update;
            uint8  spreadCount;

            bool Validate(SpellInfo const* /*spell*/)
            {
                update = 0;
                spreadCount = 1;

                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_RENEWING_MIST_HOT))
                    return false;
                return true;
            }

            void OnUpdate(uint32 diff, AuraEffectPtr aurEff)
            {
                update += diff;

                if (update >= 2500)
                {
                    if (GetCaster())
                        if (Player* _player = GetCaster()->ToPlayer())
                            _player->CastSpell(_player, SPELL_MONK_UPLIFT_ALLOWING_CAST, true);

                    update = 0;
                }
            }

            void OnTick(constAuraEffectPtr aurEff)
            {
                if (Unit* caster = GetCaster())
                {
                    if (Player* _player = caster->ToPlayer())
                    {
                        Player* target = GetTarget()->ToPlayer();
                        Unit* newTarget;

                        if (!target)
                            return;

                        if (target->HasAura(SPELL_MONK_RENEWING_MIST_JUMP_AURA, _player->GetGUID()))
                        {
                            if (_player->HasAura(SPELL_MONK_GLYPH_OF_RENEWING_MIST))
                                newTarget = target->GetNextRandomRaidMemberOrPet(40.0f);
                            else
                                newTarget = target->GetNextRandomRaidMemberOrPet(20.0f);

                            if (!newTarget)
                                return;

                            if (AuraPtr renewingMistJump = target->GetAura(SPELL_MONK_RENEWING_MIST_JUMP_AURA, _player->GetGUID()))
                            {
                                if (renewingMistJump->GetCharges() > 1)
                                {
                                    renewingMistJump->DropCharge();

                                    // Spreads Renewing Mists 3 times maximum
                                    if (AuraPtr renewingMistHot = target->GetAura(SPELL_MONK_RENEWING_MIST_HOT, _player->GetGUID()))
                                        _player->AddAura(SPELL_MONK_RENEWING_MIST_HOT, newTarget);
                                }
                                else
                                {
                                    target->RemoveAura(SPELL_MONK_RENEWING_MIST_JUMP_AURA, _player->GetGUID());

                                    // Spreads Renewing Mists 3 times maximum
                                    if (AuraPtr renewingMistHot = target->GetAura(SPELL_MONK_RENEWING_MIST_HOT, _player->GetGUID()))
                                        _player->AddAura(SPELL_MONK_RENEWING_MIST_HOT, newTarget);
                                }
                            }
                        }
                    }
                }
            }

            void HandleRemove(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes mode)
            {
                if (GetCaster())
                {
                    if (AuraPtr uplift = GetCaster()->GetAura(SPELL_MONK_UPLIFT_ALLOWING_CAST, GetCaster()->GetGUID()))
                        GetCaster()->RemoveAura(SPELL_MONK_UPLIFT_ALLOWING_CAST, GetCaster()->GetGUID());

                    if (GetCaster()->HasAura(SPELL_MONK_ITEM_2_S12_MISTWEAVER))
                    {
                        AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();
                        if (removeMode == AURA_REMOVE_BY_EXPIRE)
                        {
                            GetCaster()->CastSpell(GetCaster(), SPELL_MONK_MANA_TEA_STACKS, true);
                            GetCaster()->CastSpell(GetCaster(), SPELL_MONK_PLUS_ONE_MANA_TEA, true);
                        }
                    }
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_monk_renewing_mist_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
                OnEffectUpdate += AuraEffectUpdateFn(spell_monk_renewing_mist_AuraScript::OnUpdate, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
                OnEffectRemove += AuraEffectApplyFn(spell_monk_renewing_mist_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_monk_renewing_mist_AuraScript();
        }
};

// Healing Elixirs (aura) - 134563
class spell_monk_healing_elixirs_aura: public SpellScriptLoader
{
    public:
        spell_monk_healing_elixirs_aura() : SpellScriptLoader("spell_monk_healing_elixirs_aura") { }

        class spell_monk_healing_elixirs_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_healing_elixirs_aura_AuraScript);

            void OnProc(constAuraEffectPtr aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                if (!GetCaster())
                    return;

                if (!eventInfo.GetDamageInfo())
                    return;

                if (!eventInfo.GetDamageInfo()->GetDamage())
                    return;

                if (Unit* caster = GetCaster())
                {
                    if (caster->HealthBelowPctDamaged(35, eventInfo.GetDamageInfo()->GetDamage()))
                    {
                        caster->CastSpell(caster, SPELL_MONK_HEALING_ELIXIRS_RESTORE_HEALTH, true);
                        caster->RemoveAura(SPELL_MONK_HEALING_ELIXIRS_AURA);
                    }
                }
            }

            void Register()
            {
                OnEffectProc += AuraEffectProcFn(spell_monk_healing_elixirs_aura_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_monk_healing_elixirs_aura_AuraScript();
        }
};

// Called by : Fortifying Brew - 115203, Chi Brew - 115399, Elusive Brew - 115308, Tigereye Brew - 116740
// Purifying Brew - 119582, Mana Tea - 115294, Thunder Focus Tea - 116680 and Energizing Brew - 115288
// Healing Elixirs - 122280
class spell_monk_healing_elixirs: public SpellScriptLoader
{
    public:
        spell_monk_healing_elixirs() : SpellScriptLoader("spell_monk_healing_elixirs") { }

        class spell_monk_healing_elixirs_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_healing_elixirs_SpellScript);

            void HandleOnHit()
            {
                if (Unit* caster = GetCaster())
                {
                    if (caster->HasAura(SPELL_MONK_HEALING_ELIXIRS_AURA) && !caster->IsFullHealth())
                    {
                        caster->CastSpell(caster, SPELL_MONK_HEALING_ELIXIRS_RESTORE_HEALTH, true);
                        caster->RemoveAura(SPELL_MONK_HEALING_ELIXIRS_AURA);
                    }
                }
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_monk_healing_elixirs_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_healing_elixirs_SpellScript();
        }
};

/// last update : 6.1.2 19802
/// Zen Sphere - 124081
class spell_monk_zen_sphere: public SpellScriptLoader
{
    public:
        spell_monk_zen_sphere() : SpellScriptLoader("spell_monk_zen_sphere") { }

        class spell_monk_zen_sphere_hot_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_zen_sphere_hot_AuraScript);

            enum eSpells
            {
                ZenSphereTick = 182032
            };

            void OnTick(constAuraEffectPtr p_AurEff)
            {
                Unit* l_Caster = GetCaster();

                if (l_Caster == nullptr)
                    return;

                if (l_Caster->GetHealthPct() < (float)GetSpellInfo()->Effects[EFFECT_1].BasePoints)
                    p_AurEff->GetBase()->SetDuration(0);

                l_Caster->CastSpell(l_Caster, eSpells::ZenSphereTick, true);
            }

            void OnRemove(constAuraEffectPtr /*p_AurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* l_Caster = GetCaster())
                    l_Caster->CastSpell(l_Caster, eSpells::ZenSphereTick, true);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_monk_zen_sphere_hot_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_monk_zen_sphere_hot_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_monk_zen_sphere_hot_AuraScript();
        }
};

/// last update : 6.1.2 19802
/// Zen Sphere (tick) - 182032
class spell_monk_zen_sphere_tick : public SpellScriptLoader
{
    public:
        spell_monk_zen_sphere_tick() : SpellScriptLoader("spell_monk_zen_sphere_tick") { }

        enum eSpells
        {
            ZenSphereAura = 124081
        };

        class spell_monk_zen_sphere_tick_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_zen_sphere_tick_SpellScript);

            void HandleHealExplosion(SpellEffIndex p_EffIndex)
            {
                Unit* l_Caster = GetCaster();

                if (AuraEffectPtr l_ZenSphereAura = l_Caster->GetAuraEffect(eSpells::ZenSphereAura, EFFECT_0))
                {
                    if (l_ZenSphereAura->GetTickNumber() != l_ZenSphereAura->GetTotalTicks())
                        PreventHitDefaultEffect(p_EffIndex);
                }
            }

            void HandleDamageExplosion(SpellEffIndex p_EffIndex)
            {
                Unit* l_Caster = GetCaster();

                if (AuraEffectPtr l_ZenSphereAura = l_Caster->GetAuraEffect(eSpells::ZenSphereAura, EFFECT_0))
                {
                    if (l_ZenSphereAura->GetTickNumber() != l_ZenSphereAura->GetTotalTicks())
                        PreventHitDefaultEffect(p_EffIndex);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_monk_zen_sphere_tick_SpellScript::HandleHealExplosion, EFFECT_2, SPELL_EFFECT_HEAL);
                OnEffectHitTarget += SpellEffectFn(spell_monk_zen_sphere_tick_SpellScript::HandleDamageExplosion, EFFECT_3, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_zen_sphere_tick_SpellScript();
        }
};

enum ChiBurstSpells
{
    SPELL_MONK_STANCE_OF_THE_FIERCE_TIGER = 103985,
    //SPELL_MONK_STANCE_OF_THE_WISE_SERPENT = 115070,
    SPELL_MONK_CHI_BURST_DAMAGE           = 148135,
    SPELL_MONK_CHI_BURST_HEAL             = 130654,
};

// Chi Burst - 123986
class spell_monk_chi_burst: public SpellScriptLoader
{
    public:
        spell_monk_chi_burst() : SpellScriptLoader("spell_monk_chi_burst") { }

        class spell_monk_chi_burst_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_chi_burst_SpellScript);

            void HandleOnHit()
            {
                if (Player* l_Player = GetCaster()->ToPlayer())
                {
                    if (Unit* l_Target = GetHitUnit())
                    {
                        std::list<Unit*> l_TempUnitMap;

                        float l_DmgMult = l_Player->HasSpell(SPELL_MONK_STANCE_OF_THE_FIERCE_TIGER) ? 1.2f : 1.0f;
                        float l_HealMult = l_Player->HasSpell(SPELL_MONK_STANCE_OF_THE_WISE_SERPENT) ? 1.2f : 1.0f;

                        int32 l_Damage = sSpellMgr->GetSpellInfo(SPELL_MONK_CHI_BURST_DAMAGE)->Effects[EFFECT_0].BasePoints + l_DmgMult * l_Player->GetTotalAttackPowerValue(WeaponAttackType::BaseAttack) * 2.036f;
                        int32 l_Healing = sSpellMgr->GetSpellInfo(SPELL_MONK_CHI_BURST_HEAL)->Effects[EFFECT_0].BasePoints + l_HealMult * l_Player->GetTotalAttackPowerValue(WeaponAttackType::BaseAttack) * 1.00f;

                        // Chi Burst will always heal the Monk, but not heal twice if Monk targets himself
                        if (l_Target->GetGUID() != l_Player->GetGUID())
                            l_Player->CastCustomSpell(l_Player, SPELL_MONK_CHI_BURST_HEAL, &l_Healing, NULL, NULL, true);

                        if (l_Player->IsValidAttackTarget(l_Target))
                            l_Player->CastCustomSpell(l_Target, SPELL_MONK_CHI_BURST_DAMAGE, &l_Damage, NULL, NULL, true);
                        else
                            l_Player->CastCustomSpell(l_Target, SPELL_MONK_CHI_BURST_HEAL, &l_Healing, NULL, NULL, true);

                        l_Player->GetAttackableUnitListInRange(l_TempUnitMap, l_Player->GetDistance(l_Target));
                        for (auto l_Itr : l_TempUnitMap)
                        {
                            if (l_Itr->GetGUID() == l_Player->GetGUID())
                                continue;

                            if (!l_Itr->IsInBetween(l_Player, l_Target, 3.0f))
                                continue;

                            if (l_Player->IsValidAttackTarget(l_Itr))
                                l_Player->CastCustomSpell(l_Itr, SPELL_MONK_CHI_BURST_DAMAGE, &l_Damage, NULL, NULL, true);
                            else
                                l_Player->CastCustomSpell(l_Itr, SPELL_MONK_CHI_BURST_HEAL, &l_Healing, NULL, NULL, true);

                        }
                    }
                }
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_monk_chi_burst_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_chi_burst_SpellScript();
        }
};

// Energizing Brew - 115288
class spell_monk_energizing_brew: public SpellScriptLoader
{
    public:
        spell_monk_energizing_brew() : SpellScriptLoader("spell_monk_energizing_brew") { }

        class spell_monk_energizing_brew_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_energizing_brew_SpellScript);

            SpellCastResult CheckFight()
            {
                if (!GetCaster()->isInCombat())
                    return SPELL_FAILED_CASTER_AURASTATE;
                return SPELL_CAST_OK;
            }

            void Register()
            {
                OnCheckCast += SpellCheckCastFn(spell_monk_energizing_brew_SpellScript::CheckFight);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_energizing_brew_SpellScript();
        }
};

// Spear Hand Strike - 116705
class spell_monk_spear_hand_strike: public SpellScriptLoader
{
    public:
        spell_monk_spear_hand_strike() : SpellScriptLoader("spell_monk_spear_hand_strike") { }

        class spell_monk_spear_hand_strike_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_spear_hand_strike_SpellScript);

            void HandleOnHit()
            {
                if (Player* _player = GetCaster()->ToPlayer())
                {
                    if (Unit* target = GetHitUnit())
                    {
                        if (target->isInFront(_player))
                        {
                            _player->CastSpell(target, SPELL_MONK_SPEAR_HAND_STRIKE_SILENCE, true);
                            _player->AddSpellCooldown(116705, 0, 15 * IN_MILLISECONDS);
                        }
                    }
                }
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_monk_spear_hand_strike_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_spear_hand_strike_SpellScript();
        }
};

/// Tigereye Brew - 116740
class spell_monk_tigereye_brew: public SpellScriptLoader
{
    public:
        spell_monk_tigereye_brew() : SpellScriptLoader("spell_monk_tigereye_brew") { }

        class spell_monk_tigereye_brew_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_tigereye_brew_SpellScript);

            enum eSpells
            {
                MonkWoDPvPWindwalker4PBonus = 181742,
                MonkWoDPvPWindwalkerAura    = 181744
            };

            bool Validate(SpellInfo const* /*spellEntry*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_TIGEREYE_BREW))
                    return false;
                return true;
            }

            void HandleOnHit()
            {
                Unit* l_Caster = GetCaster();

                if (AuraPtr l_TigereyeBrewStacks = l_Caster->GetAura(SPELL_MONK_TIGEREYE_BREW_STACKS))
                {
                    uint8 l_StackConsumed = l_TigereyeBrewStacks->GetStackAmount();
                    uint8 l_Stacks = l_TigereyeBrewStacks->GetStackAmount();

                    if (l_StackConsumed > 10)
                        l_StackConsumed = 10;

                    int32 l_EffectAmount = l_StackConsumed * GetSpellInfo()->Effects[EFFECT_0].BasePoints;

                    if (AuraPtr l_TigereyeBrew = l_Caster->GetAura(SPELL_MONK_TIGEREYE_BREW))
                    {
                        l_TigereyeBrew->GetEffect(0)->ChangeAmount(l_EffectAmount);
                        l_TigereyeBrew->GetEffect(1)->ChangeAmount(l_EffectAmount);
                    }

                    if (l_Caster->HasAura(eSpells::MonkWoDPvPWindwalker4PBonus))
                    {
                        SpellInfo const * l_SpellInfo = sSpellMgr->GetSpellInfo(eSpells::MonkWoDPvPWindwalker4PBonus);

                        l_Caster->CastSpell(l_Caster, eSpells::MonkWoDPvPWindwalkerAura, true);
                        if (AuraPtr l_FortitudeOfXuen = l_Caster->GetAura(eSpells::MonkWoDPvPWindwalkerAura))
                            l_FortitudeOfXuen->GetEffect(0)->ChangeAmount(l_StackConsumed * (l_SpellInfo->Effects[EFFECT_0].BasePoints / 1000) * -1);
                    }

                    if (l_TigereyeBrewStacks->GetStackAmount() >= 10)
                        l_TigereyeBrewStacks->SetStackAmount(l_Stacks - l_StackConsumed);
                    else
                        l_Caster->RemoveAura(SPELL_MONK_TIGEREYE_BREW_STACKS);
                }
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_monk_tigereye_brew_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_tigereye_brew_SpellScript();
        }
};

// Tiger's Lust - 116841
class spell_monk_tigers_lust: public SpellScriptLoader
{
    public:
        spell_monk_tigers_lust() : SpellScriptLoader("spell_monk_tigers_lust") { }

        class spell_monk_tigers_lust_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_tigers_lust_SpellScript);

            bool Validate(SpellInfo const* /*spellEntry*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_FLYING_SERPENT_KICK_NEW))
                    return false;
                return true;
            }

            void HandleOnHit()
            {
                if (Player* _player = GetCaster()->ToPlayer())
                    if (Unit* target = GetHitUnit())
                        target->RemoveMovementImpairingAuras();
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_monk_tigers_lust_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_tigers_lust_SpellScript();
        }
};

// Flying Serpent Kick - 115057
class spell_monk_flying_serpent_kick: public SpellScriptLoader
{
    public:
        spell_monk_flying_serpent_kick() : SpellScriptLoader("spell_monk_flying_serpent_kick") { }

        class spell_monk_flying_serpent_kick_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_flying_serpent_kick_SpellScript);

            bool Validate(SpellInfo const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_FLYING_SERPENT_KICK_NEW))
                    return false;
                return true;
            }

            void HandleBeforeCast()
            {
                if (Unit* caster = GetCaster())
                {
                    if (Player* _player = caster->ToPlayer())
                    {
                        if (_player->HasAura(SPELL_MONK_FLYING_SERPENT_KICK))
                            _player->RemoveAura(SPELL_MONK_FLYING_SERPENT_KICK);

                        if (caster->HasAura(SPELL_MONK_ITEM_PVP_GLOVES_BONUS))
                            caster->RemoveAurasByType(SPELL_AURA_MOD_DECREASE_SPEED);
                    }
                }
            }

            void Register()
            {
                BeforeCast += SpellCastFn(spell_monk_flying_serpent_kick_SpellScript::HandleBeforeCast);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_flying_serpent_kick_SpellScript();
        }

        class spell_monk_flying_serpent_kick_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_flying_serpent_kick_AuraScript);

            void OnTick(constAuraEffectPtr aurEff)
            {
                if (!GetCaster())
                    return;

                GetCaster()->CastSpell(GetCaster(), SPELL_MONK_FLYING_SERPENT_KICK_AOE, true);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_monk_flying_serpent_kick_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_monk_flying_serpent_kick_AuraScript();
        }
};

// Chi Torpedo - 115008 or Chi Torpedo (3 charges) - 121828
class spell_monk_chi_torpedo: public SpellScriptLoader
{
    public:
        spell_monk_chi_torpedo() : SpellScriptLoader("spell_monk_chi_torpedo") { }

        class spell_monk_chi_torpedo_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_chi_torpedo_SpellScript);

            enum eSpells
            {
                MonkWoDPvPBrewmaster2PBonus = 165691,
                MonkWoDPvPBrewmasterAura = 165692
            };

            void HandleAfterCast()
            {
                Player* l_Player = GetCaster()->ToPlayer();

                if (l_Player == nullptr)
                    return;

                std::list<Unit*> l_TempUnitMap;
                l_Player->GetAttackableUnitListInRange(l_TempUnitMap, 20.0f);

                for (auto itr : l_TempUnitMap)
                {
                    if (!l_Player->isInFront(itr, M_PI / 3) && itr->GetGUID() != l_Player->GetGUID())
                        continue;

                    uint32 spell = l_Player->IsValidAttackTarget(itr) ? SPELL_MONK_CHI_TORPEDO_DAMAGE : SPELL_MONK_CHI_TORPEDO_HEAL;
                    l_Player->CastSpell(itr, spell, true);
                }

                if (l_Player->HasAura(SPELL_MONK_ITEM_PVP_GLOVES_BONUS))
                    l_Player->RemoveAurasByType(SPELL_AURA_MOD_DECREASE_SPEED);

                if (l_Player->HasAura(eSpells::MonkWoDPvPBrewmaster2PBonus))
                    l_Player->CastSpell(l_Player, eSpells::MonkWoDPvPBrewmasterAura, true);
            }

            void Register()
            {
                AfterCast += SpellCastFn(spell_monk_chi_torpedo_SpellScript::HandleAfterCast);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_chi_torpedo_SpellScript();
        }
};

// Purifying Brew - 119582
class spell_monk_purifying_brew: public SpellScriptLoader
{
    public:
        spell_monk_purifying_brew() : SpellScriptLoader("spell_monk_purifying_brew") { }

        class spell_monk_purifying_brew_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_purifying_brew_SpellScript);

            void HandleOnHit()
            {
                if (Unit* caster = GetCaster())
                {
                    if (Player* _player = caster->ToPlayer())
                    {
                        AuraApplication* staggerAmount = _player->GetAuraApplication(SPELL_MONK_LIGHT_STAGGER);

                        if (!staggerAmount)
                            staggerAmount = _player->GetAuraApplication(SPELL_MONK_MODERATE_STAGGER);
                        if (!staggerAmount)
                            staggerAmount = _player->GetAuraApplication(SPELL_MONK_HEAVY_STAGGER);

                        if (staggerAmount)
                            _player->RemoveAura(staggerAmount->GetBase()->GetId());
                    }
                }
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_monk_purifying_brew_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_purifying_brew_SpellScript();
        }
};

// Keg Smash - 121253
class spell_monk_keg_smash: public SpellScriptLoader
{
    public:
        spell_monk_keg_smash() : SpellScriptLoader("spell_monk_keg_smash") { }

        class spell_monk_keg_smash_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_keg_smash_SpellScript);

            void OnCast()
            {
                if (Unit* l_caster = GetCaster())
                {
                        l_caster->CastSpell(l_caster, SPELL_MONK_KEG_SMASH_ENERGIZE, true);
                }
            }
            void HandleOnHit()
            {
                if (Unit* l_caster = GetCaster())
                {
                        if (Unit* target = GetHitUnit())
                        {
                            l_caster->CastSpell(target, SPELL_MONK_KEG_SMASH_VISUAL, true);
                            l_caster->CastSpell(target, SPELL_MONK_WEAKENED_BLOWS, true);
                            l_caster->CastSpell(target, SPELL_MONK_DIZZYING_HAZE, true);
                        }
                }
            }

            void HandleDamage(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster())
                    return;

                float l_Low = 0;
                float l_High = 0;

                Player* l_Player = GetCaster()->ToPlayer();

                if (l_Player == nullptr)
                    return;

                l_Player->CalculateMonkMeleeAttacks(l_Low, l_High);

                SetHitDamage(int32(frand(14.5f * l_Low, 14.5f * l_High)));

            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_monk_keg_smash_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                OnHit += SpellHitFn(spell_monk_keg_smash_SpellScript::HandleOnHit);
                AfterCast += SpellCastFn(spell_monk_keg_smash_SpellScript::OnCast);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_keg_smash_SpellScript();
        }
};

// Elusive Brew - 115308
class spell_monk_elusive_brew: public SpellScriptLoader
{
    public:
        spell_monk_elusive_brew() : SpellScriptLoader("spell_monk_elusive_brew") { }

        class spell_monk_elusive_brew_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_elusive_brew_SpellScript);

            void HandleOnHit()
            {
                int32 stackAmount = 0;

                if (Unit* caster = GetCaster())
                {
                    if (Player* _player = caster->ToPlayer())
                    {
                        if (AuraApplication* brewStacks = _player->GetAuraApplication(SPELL_MONK_ELUSIVE_BREW_STACKS))
                            stackAmount = brewStacks->GetBase()->GetStackAmount();

                        _player->AddAura(SPELL_MONK_ELUSIVE_BREW, _player);

                        if (AuraApplication* aura = _player->GetAuraApplication(SPELL_MONK_ELUSIVE_BREW))
                        {
                            AuraPtr elusiveBrew = aura->GetBase();
                            int32 maxDuration = elusiveBrew->GetMaxDuration();
                            int32 newDuration = stackAmount * 1000;
                            elusiveBrew->SetDuration(newDuration);

                            if (newDuration > maxDuration)
                                elusiveBrew->SetMaxDuration(newDuration);

                            _player->RemoveAura(SPELL_MONK_ELUSIVE_BREW_STACKS);
                        }
                    }
                }
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_monk_elusive_brew_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_elusive_brew_SpellScript();
        }
};

enum BreathOfFireSpells
{
    SPELL_MONK_GLYPH_OF_BREATH_OF_FIRE = 123394,
    SPELL_MONK_IMPROVED_BREATH_OF_FIRE = 157362
};

// Breath of Fire - 115181
class spell_monk_breath_of_fire: public SpellScriptLoader
{
    public:
        spell_monk_breath_of_fire() : SpellScriptLoader("spell_monk_breath_of_fire") { }

        class spell_monk_breath_of_fire_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_breath_of_fire_SpellScript);

            void HandleAfterHit()
            {
                Unit* l_Caster = GetCaster();
                Unit* l_Target = GetHitUnit();
                if (!l_Target)
                    return;

                // if Dizzying Haze is on the target or has Improved Breath of Fire, they will burn for an additionnal damage over 8s
                if (l_Target->HasAura(SPELL_MONK_DIZZYING_HAZE) || l_Caster->HasAura(SPELL_MONK_IMPROVED_BREATH_OF_FIRE))
                {
                    l_Caster->CastSpell(l_Target, SPELL_MONK_BREATH_OF_FIRE_DOT, true);

                    // Glyph of Breath of Fire
                    if (l_Caster->HasAura(SPELL_MONK_GLYPH_OF_BREATH_OF_FIRE))
                        l_Caster->CastSpell(l_Target, SPELL_MONK_BREATH_OF_FIRE_CONFUSED, true);
                }
            }

            void Register()
            {
                AfterHit += SpellHitFn(spell_monk_breath_of_fire_SpellScript::HandleAfterHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_breath_of_fire_SpellScript();
        }
};

enum SoothingMist
{
    NPC_SNAKE_JADE_STATUE = 60849,
    SPELL_MONK_GLYPH_OF_SHOOTING_MIST_AURA = 159536,
    SPELL_MONK_GLYPH_OF_SHOOTING_MIST = 159537
};

// Soothing Mist - 115175
class spell_monk_soothing_mist: public SpellScriptLoader
{
    public:
        spell_monk_soothing_mist() : SpellScriptLoader("spell_monk_soothing_mist") { }

        class spell_monk_soothing_mist_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_soothing_mist_AuraScript);

            Unit*    GetRandomPartyMember(Unit* p_JadeStatue, Unit *p_Caster, Unit *p_Target)
            {
                if (p_Caster == nullptr)
                    return nullptr;

                std::list<Unit*> l_UnitList;
                std::list<Unit*> l_UnitTempList;

                p_Caster->GetRaidMembers(l_UnitList);
                p_Caster->GetRaidMembers(l_UnitTempList);

                /// Remove Unit out of range
                for (std::list<Unit*>::iterator i = l_UnitTempList.begin(); i != l_UnitTempList.end(); ++i)
                {
                    if (!(*i)->IsInRange(p_JadeStatue, 0.0f, 40.0f))
                        l_UnitList.remove((*i));
                }

                if (l_UnitList.size() > 1)
                {
                    l_UnitList.remove(p_Target);
                    l_UnitList.sort(JadeCore::HealthPctOrderPred());
                    l_UnitList.resize(1);
                }

                if (l_UnitList.size() == 1)
                    return l_UnitList.front();

                return nullptr;
            }

            Unit*   GetStatueOfUnit(Unit *p_Caster)
            {
                if (p_Caster == nullptr)
                    return nullptr;

                Unit *l_JadeStatue = nullptr;

                for (Unit::ControlList::const_iterator itr = p_Caster->m_Controlled.begin(); itr != p_Caster->m_Controlled.end(); ++itr)
                {
                    if ((*itr)->GetEntry() == NPC_SNAKE_JADE_STATUE)
                    {
                        if ((*itr)->GetDistance(p_Caster) <= 40.0f)
                            l_JadeStatue = (*itr);
                    }
                }

                return l_JadeStatue;
            }

            void OnApply(constAuraEffectPtr aurEff, AuraEffectHandleModes /*mode*/)
            {
                Unit* l_Caster = GetCaster();
                Unit* l_Target = GetTarget();

                if (l_Target == nullptr || l_Caster == nullptr)
                    return;

                l_Target->CastSpell(l_Target, SPELL_MONK_SOOTHING_MIST_VISUAL, true);

                Unit* l_JadeStatue = GetStatueOfUnit(l_Caster);

                if (l_JadeStatue == nullptr)
                    return;
                
                Unit* l_TargetOfJadeStatue = GetRandomPartyMember(l_JadeStatue, l_Caster, l_Target);

                if (l_TargetOfJadeStatue == nullptr)
                    return;

                int32 l_Bp = aurEff->GetAmount();
                l_JadeStatue->CastSpell(l_TargetOfJadeStatue, GetSpellInfo()->Id, true);
            }

            void OnRemove(constAuraEffectPtr p_AurEff, AuraEffectHandleModes /*mode*/)
            {
                Unit* l_Caster = GetCaster();
                Unit* l_Target = GetTarget();

                if (l_Target == nullptr || l_Caster == nullptr)
                    return;

                if (l_Target->HasAura(SPELL_MONK_SOOTHING_MIST_VISUAL))
                    l_Target->RemoveAura(SPELL_MONK_SOOTHING_MIST_VISUAL);

                if (l_Caster->HasAura(SPELL_MONK_GLYPH_OF_SHOOTING_MIST_AURA))
                {
                    SpellInfo const * l_SpellInfo = sSpellMgr->GetSpellInfo(SPELL_MONK_GLYPH_OF_SHOOTING_MIST_AURA);

                    if (l_SpellInfo != nullptr && l_SpellInfo->Effects[EFFECT_1].BasePoints > 0)
                    {
                        /// If already has buff, add duration with old duration
                        if (AuraPtr l_HasAlreadyAuraGlyph = l_Caster->GetAura(SPELL_MONK_GLYPH_OF_SHOOTING_MIST))
                            l_HasAlreadyAuraGlyph->SetDuration(l_HasAlreadyAuraGlyph->GetDuration() + ((p_AurEff->GetTickNumber() / l_SpellInfo->Effects[EFFECT_1].BasePoints) * IN_MILLISECONDS));
                        else
                        {
                            l_Caster->CastSpell(l_Caster, SPELL_MONK_GLYPH_OF_SHOOTING_MIST, true);

                            /// 1 sec for every sec you spent channeling Soothing Mist
                            if (AuraPtr l_AuraGlyph = l_Caster->GetAura(SPELL_MONK_GLYPH_OF_SHOOTING_MIST))
                                l_AuraGlyph->SetDuration(((p_AurEff->GetTickNumber() / l_SpellInfo->Effects[EFFECT_1].BasePoints) * IN_MILLISECONDS));
                        }
                    }
                }

                Unit *l_JadeStatue = GetStatueOfUnit(l_Caster);

                if (l_JadeStatue == nullptr)
                    return;

                Unit *l_TargetOfJadeStatue = GetRandomPartyMember(l_JadeStatue, l_Caster, l_Target);

                if (l_TargetOfJadeStatue == nullptr)
                    return;

                l_JadeStatue->CastStop();
            }

            void CalculateAmount(constAuraEffectPtr p_AurEff, int32 & p_Amount, bool & /*canBeRecalculated*/)
            {
                Unit* l_Caster = GetCaster();

                if (l_Caster == nullptr)
                    return;

                Unit* l_Owner = l_Caster->GetOwner();

                if (l_Owner == nullptr)
                    return;

                /// Apply amount with stats of owner
                p_Amount = l_Owner->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC) * p_AurEff->GetSpellEffectInfo()->BonusMultiplier;
            }

            void Register()
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_monk_soothing_mist_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
                AfterEffectApply += AuraEffectApplyFn(spell_monk_soothing_mist_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_monk_soothing_mist_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_monk_soothing_mist_AuraScript();
        }
};

// Disable - 116095
class spell_monk_disable: public SpellScriptLoader
{
    public:
        spell_monk_disable() : SpellScriptLoader("spell_monk_disable") { }

        class spell_monk_disable_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_disable_SpellScript);

            bool snaredOnHit;

            SpellCastResult CheckCast()
            {
                snaredOnHit = false;

                if (GetCaster())
                    if (Unit* target = GetCaster()->getVictim())
                        if (target->HasAuraType(SPELL_AURA_MOD_DECREASE_SPEED))
                            snaredOnHit = true;

                return SPELL_CAST_OK;
            }

            void HandleOnHit()
            {
                if (Unit* caster = GetCaster())
                    if (Player* _player = caster->ToPlayer())
                        if (Unit* target = GetHitUnit())
                            if (snaredOnHit)
                                _player->CastSpell(target, SPELL_MONK_DISABLE_ROOT, true);
            }

            void Register()
            {
                OnCheckCast += SpellCheckCastFn(spell_monk_disable_SpellScript::CheckCast);
                OnHit += SpellHitFn(spell_monk_disable_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_disable_SpellScript();
        }

        class spell_monk_disable_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_disable_AuraScript);

            void OnTick(constAuraEffectPtr aurEff)
            {
                if (Unit* caster = GetCaster())
                {
                    if (Unit* target = GetTarget())
                    {
                        if (target->GetDistance(caster) < 10.0f)
                            aurEff->GetBase()->RefreshDuration();
                    }
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_monk_disable_AuraScript::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_monk_disable_AuraScript();
        }
};

// Zen Pilgrimage - 126892 and Zen Pilgrimage : Return - 126895
class spell_monk_zen_pilgrimage: public SpellScriptLoader
{
    public:
        spell_monk_zen_pilgrimage() : SpellScriptLoader("spell_monk_zen_pilgrimage") { }

        class spell_monk_zen_pilgrimage_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_zen_pilgrimage_SpellScript);

            bool Validate(SpellInfo const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_ZEN_PILGRIMAGE) || !sSpellMgr->GetSpellInfo(SPELL_MONK_ZEN_PILGRIMAGE_RETURN))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                {
                    if (Player* _player = caster->ToPlayer())
                    {
                        if (GetSpellInfo()->Id == SPELL_MONK_ZEN_PILGRIMAGE)
                        {
                            _player->SaveRecallPosition();
                            _player->TeleportTo(870, 3818.55f, 1793.18f, 950.35f, _player->GetOrientation());
                        }
                        else if (GetSpellInfo()->Id == SPELL_MONK_ZEN_PILGRIMAGE_RETURN)
                        {
                            _player->TeleportTo(_player->m_recallMap, _player->m_recallX, _player->m_recallY, _player->m_recallZ, _player->m_recallO);
                            _player->RemoveAura(126896);
                        }
                    }
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_monk_zen_pilgrimage_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_zen_pilgrimage_SpellScript();
        }
};

/// last update : 6.1.2 19802
/// Provoke - 115546
class spell_monk_provoke: public SpellScriptLoader
{
    public:
        spell_monk_provoke() : SpellScriptLoader("spell_monk_provoke") { }

        class spell_monk_provoke_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_provoke_SpellScript);

            bool m_IsMultiTarget = false;

            enum eSpells
            {
                ProvokeSingleTarget = 116189,
                ProvokeMultiTarget = 118635
            };

            enum eNpcs
            {
                BlackOxStatue = 61146
            };

            SpellCastResult CheckCast()
            {
                Unit* l_Target = GetExplTargetUnit();
                if (!l_Target)
                    return SPELL_FAILED_NO_VALID_TARGETS;
                else if (l_Target->GetTypeId() == TYPEID_PLAYER)
                    return SPELL_FAILED_BAD_TARGETS;
                else if (!l_Target->IsWithinLOSInMap(GetCaster()))
                    return SPELL_FAILED_LINE_OF_SIGHT;

                if (l_Target->GetEntry() == eNpcs::BlackOxStatue)
                    m_IsMultiTarget = true;
                return SPELL_CAST_OK;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                    if (caster->getClass() == CLASS_MONK && caster->GetTypeId() == TYPEID_PLAYER)
                    if (Unit* target = GetHitUnit())
                    {
                        if (m_IsMultiTarget)
                            caster->CastSpell(target, eSpells::ProvokeMultiTarget, true);
                        else
                            caster->CastSpell(target, eSpells::ProvokeSingleTarget, true);
                    }
            }

            void Register()
            {
                OnCheckCast += SpellCheckCastFn(spell_monk_provoke_SpellScript::CheckCast);
                OnEffectHitTarget += SpellEffectFn(spell_monk_provoke_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_provoke_SpellScript();
        }
};

/// last update : 6.1.2 19802
/// Provoke (launch) - 118635
class spell_monk_provoke_launch : public SpellScriptLoader
{
    public:
        spell_monk_provoke_launch() : SpellScriptLoader("spell_monk_provoke_launch") { }

        class spell_monk_provoke_launch_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_provoke_launch_SpellScript);

            void FilterTargets(std::list<WorldObject*>& p_Targets)
            {
                p_Targets.remove_if([this](WorldObject* p_Object) -> bool
                {
                    if (p_Object == nullptr || p_Object->ToUnit() == nullptr)
                        return true;

                    /// Unusable on pvp
                    if (p_Object->GetTypeId() == TYPEID_PLAYER)
                        return true;

                    return false;
                });
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_monk_provoke_launch_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_monk_provoke_launch_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_monk_provoke_launch_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_DEST_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_provoke_launch_SpellScript();
        }
};

enum ParalysisSpells
{
    SPELL_MONK_GLYPH_OF_PARALYSIS = 125755
};

// Paralysis - 115078
class spell_monk_paralysis: public SpellScriptLoader
{
    public:
        spell_monk_paralysis() : SpellScriptLoader("spell_monk_paralysis") { }

        class spell_monk_paralysis_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_paralysis_SpellScript);

            void HandleOnHit()
            {
                Unit* l_Caster = GetCaster();
                Unit* l_Target = GetHitUnit();
                if (l_Target && l_Caster->HasAura(SPELL_MONK_GLYPH_OF_PARALYSIS))
                    l_Target->RemoveAllAurasByType(SPELL_AURA_PERIODIC_DAMAGE);
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_monk_paralysis_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_paralysis_SpellScript();
        }
};

/// last update : 6.1.2 19802
/// Touch of Death - 115080
class spell_monk_touch_of_death: public SpellScriptLoader
{
    public:
        spell_monk_touch_of_death() : SpellScriptLoader("spell_monk_touch_of_death") { }

        class spell_monk_touch_of_death_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_touch_of_death_SpellScript);

            SpellCastResult CheckCast()
            {
                if (Unit* caster = GetCaster())
                {
                    if (Unit* target = GetExplTargetUnit())
                    {
                        if (caster->HasAura(124490))
                        {
                            if (target->GetTypeId() == TYPEID_UNIT && !target->GetOwner() && target->GetHealthPct() > 10.0f && (target->GetHealth() > caster->GetMaxHealth()))
                                return SPELL_FAILED_BAD_TARGETS;
                            else if (((target->GetOwner() && target->GetOwner()->ToPlayer()) || target->GetTypeId() == TYPEID_PLAYER) &&
                                (target->GetHealthPct() > 10.0f))
                                return SPELL_FAILED_BAD_TARGETS;
                        }
                        else
                        {
                            if ((target->GetTypeId() == TYPEID_PLAYER || (target->GetOwner() && target->GetOwner()->ToPlayer())) && target->GetHealthPct() > 10.0f)
                                return SPELL_FAILED_BAD_TARGETS;
                            else if (target->GetTypeId() == TYPEID_UNIT && target->GetHealthPct() > 10.0f && target->GetHealth() > caster->GetMaxHealth())
                                return SPELL_FAILED_BAD_TARGETS;
                        }
                        return SPELL_CAST_OK;
                    }
                }

                return SPELL_FAILED_NO_VALID_TARGETS;
            }

            void Register()
            {
                OnCheckCast += SpellCheckCastFn(spell_monk_touch_of_death_SpellScript::CheckCast);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_touch_of_death_SpellScript();
        }
};

// Fortifying brew - 115203
class spell_monk_fortifying_brew: public SpellScriptLoader
{
    public:
        spell_monk_fortifying_brew() : SpellScriptLoader("spell_monk_fortifying_brew") { }

        class spell_monk_fortifying_brew_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_fortifying_brew_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (caster && caster->GetTypeId() == TYPEID_PLAYER)
                    caster->CastSpell(caster, SPELL_MONK_FORTIFYING_BREW, true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_monk_fortifying_brew_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_fortifying_brew_SpellScript();
        }
};

// Roll - 109132 or Roll (3 charges) - 121827
class spell_monk_roll: public SpellScriptLoader
{
    public:
        spell_monk_roll() : SpellScriptLoader("spell_monk_roll") { }

        class spell_monk_roll_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_roll_SpellScript);

            enum eSpells
            {
                MonkWoDPvPBrewmaster2PBonus     = 165691,
                MonkWoDPvPBrewmasterAura        = 165692
            };

            bool Validate(SpellInfo const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_ROLL))
                    return false;
                return true;
            }

            void HandleBeforeCast()
            {
                AuraPtr aur = GetCaster()->AddAura(SPELL_MONK_ROLL_TRIGGER, GetCaster());
                if (!aur)
                    return;

                AuraApplication* app =  aur->GetApplicationOfTarget(GetCaster()->GetGUID());
                if (!app)
                    return;

                app->ClientUpdate();
            }

            void HandleAfterCast()
            {
                Unit* l_Caster = GetCaster();
                if (!l_Caster || l_Caster->GetTypeId() != TYPEID_PLAYER)
                    return;

                l_Caster->CastSpell(l_Caster, SPELL_MONK_ROLL_TRIGGER, true);

                if (l_Caster->HasAura(SPELL_MONK_ITEM_PVP_GLOVES_BONUS))
                    l_Caster->RemoveAurasByType(SPELL_AURA_MOD_DECREASE_SPEED);

                if (l_Caster->HasAura(eSpells::MonkWoDPvPBrewmaster2PBonus))
                    l_Caster->CastSpell(l_Caster, eSpells::MonkWoDPvPBrewmasterAura, true);
            }

            void Register()
            {
                BeforeCast += SpellCastFn(spell_monk_roll_SpellScript::HandleBeforeCast);
                AfterCast += SpellCastFn(spell_monk_roll_SpellScript::HandleAfterCast);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_roll_SpellScript();
        }
};

// Brewing : Tigereye Brew - 123980
class spell_monk_tigereye_brew_stacks: public SpellScriptLoader
{
    public:
        spell_monk_tigereye_brew_stacks() : SpellScriptLoader("spell_monk_tigereye_brew_stacks") { }

        class spell_monk_tigereye_brew_stacks_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_tigereye_brew_stacks_AuraScript);

            uint32 chiConsumed;

            void OnApply(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                chiConsumed = 0;
            }

            void SetData(uint32 type, uint32 data)
            {
                if (!GetCaster())
                    return;

                if (Player* player = GetCaster()->ToPlayer())
                {
                    while ((chiConsumed += data) >= 4)
                    {
                        chiConsumed = 0;
                        data = data > 4 ? data - 4: 0;

                        player->CastSpell(player, SPELL_MONK_TIGEREYE_BREW_STACKS, true);

                        // Mastery: Bottled Fury
                        float Mastery = player->GetFloatValue(PLAYER_FIELD_MASTERY) * 2.5f;
                        if (player->HasAura(SPELL_MONK_MASTERY_BOTTLED_FURY) && roll_chance_f(Mastery))
                            player->CastSpell(player, SPELL_MONK_TIGEREYE_BREW_STACKS, true);
                    }
                }
            }

            void Register()
            {
                AfterEffectApply += AuraEffectApplyFn(spell_monk_tigereye_brew_stacks_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_monk_tigereye_brew_stacks_AuraScript();
        }
};

enum SpinningCraneKickSpells
{
    //SPELL_MONK_STANCE_OF_THE_FIERCE_TIGER = 103985,
    SPELL_MONK_SPINNING_CRANE_KICK_DAMAGE = 107270,
    SPELL_MONK_2H_STAFF_OVERRIDE          = 108561,
    SPELL_MONK_2H_POLEARM_OVERRIDE        = 115697,
    SPELL_MONK_MANA_MEDITATION            = 121278
};

// Spinning Crane Kick - 101546
class spell_monk_spinning_crane_kick: public SpellScriptLoader
{
    public:
        spell_monk_spinning_crane_kick() : SpellScriptLoader("spell_monk_spinning_crane_kick") { }

        class spell_monk_spinning_crane_kick_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_spinning_crane_kick_AuraScript);

            void OnTick(constAuraEffectPtr aurEff)
            {
                if (!GetCaster())
                    return;

                float l_Low = 0;
                float l_High = 0;

                Player* l_Player = GetCaster()->ToPlayer();

                if (l_Player == nullptr)
                    return;

                l_Player->CalculateMonkMeleeAttacks(l_Low, l_High);

                int l_Bp0 = (((4 * 0.75f * l_Low + 4 * 0.75f * l_High) / 2) / (GetSpellInfo()->GetDuration() / IN_MILLISECONDS));
                l_Player->CastCustomSpell(l_Player, SPELL_MONK_SPINNING_CRANE_KICK_DAMAGE, &l_Bp0, NULL, NULL, true);
            }
            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_monk_spinning_crane_kick_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_monk_spinning_crane_kick_AuraScript();
        }
};

enum RushingJadeWindSpells
{
    //SPELL_MONK_STANCE_OF_THE_FIERCE_TIGER = 103985,
    //SPELL_MONK_SPINNING_CRANE_KICK_DAMAGE = 107270,
    //SPELL_MONK_2H_STAFF_OVERRIDE          = 108561,
    //SPELL_MONK_2H_POLEARM_OVERRIDE        = 115697,
    //SPELL_MONK_MANA_MEDITATION            = 121278
    SPELL_MONK_SPINNING_CRANE_KICK = 129881,
    SPELL_MONK_RUSHING_JADE_WIND = 116847,
    SPELL_MONK_RUSHING_JADE_WIND_DAMAGE = 148187,
    SPELL_MONK_RUSHING_JADE_WIND_HEAL = 162530
};

// Rushing Jade Wind - 116847
class spell_monk_rushing_jade_wind: public SpellScriptLoader
{
    public:
        spell_monk_rushing_jade_wind() : SpellScriptLoader("spell_monk_rushing_jade_wind") { }

        class spell_monk_rushing_jade_wind_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_rushing_jade_wind_AuraScript);

            void OnTick(constAuraEffectPtr aurEff)
            {
                if (!GetCaster())
                    return;

                float l_Low = 0;
                float l_High = 0;

                Player* l_Player = GetCaster()->ToPlayer();

                if (l_Player == nullptr || GetSpellInfo()->GetDuration() <= 0)
                    return;


                if (l_Player->GetSpecializationId(l_Player->GetActiveSpec()) != SPEC_MONK_MISTWEAVER)
                {
                    l_Player->CalculateMonkMeleeAttacks(l_Low, l_High);

                    int l_Bp0 = (((0.6f * l_Low + 0.6f * l_High) / 2) * 9) / (GetSpellInfo()->GetDuration() / IN_MILLISECONDS);
                    l_Player->CastCustomSpell(l_Player, SPELL_MONK_RUSHING_JADE_WIND_DAMAGE, &l_Bp0, NULL, NULL, true);
                }
                else
                    l_Player->CastSpell(l_Player, SPELL_MONK_RUSHING_JADE_WIND_HEAL, true);
            }
            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_monk_rushing_jade_wind_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_monk_rushing_jade_wind_AuraScript();
        }
};

///  Rushing Jade Wind (damage) - 148187
class spell_monk_rushing_jade_wind_damage : public SpellScriptLoader
{
    public:
        spell_monk_rushing_jade_wind_damage() : SpellScriptLoader("spell_monk_rushing_jade_wind_damage") { }

        class spell_monk_rushing_jade_wind_damage_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_rushing_jade_wind_damage_SpellScript);

            void CorrectTargets(std::list<WorldObject*>& p_Targets)
            {
                if (Unit *l_Caster = GetCaster())
                {
                    SpellInfo const* l_SpellInfo = sSpellMgr->GetSpellInfo(SPELL_MONK_SPINNING_CRANE_KICK);

                    // Generates 1 Chi if it hits at least 3 targets.
                    if (l_SpellInfo != nullptr && p_Targets.size() >= l_SpellInfo->Effects[EFFECT_1].BasePoints)
                        l_Caster->CastSpell(l_Caster, SPELL_MONK_SPINNING_CRANE_KICK, true);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_monk_rushing_jade_wind_damage_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_rushing_jade_wind_damage_SpellScript();
        }
};

///  Rushing Jade Wind (heal) - 162530
class spell_monk_rushing_jade_wind_heal : public SpellScriptLoader
{
    public:
        spell_monk_rushing_jade_wind_heal() : SpellScriptLoader("spell_monk_rushing_jade_wind_heal") { }

        class spell_monk_rushing_jade_wind_heal_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_rushing_jade_wind_heal_SpellScript);

            void CorrectTargets(std::list<WorldObject*>& p_Targets)
            {
                if (Unit *l_Caster = GetCaster())
                {
                    SpellInfo const* l_SpellInfo = sSpellMgr->GetSpellInfo(SPELL_MONK_SPINNING_CRANE_KICK);

                    // Generates 1 Chi if it hits at least 3 targets.
                    if (l_SpellInfo != nullptr && p_Targets.size() >= l_SpellInfo->Effects[EFFECT_1].BasePoints)
                        l_Caster->CastSpell(l_Caster, SPELL_MONK_SPINNING_CRANE_KICK, true);

                    /// up to 6 allies
                    if (p_Targets.size() <= 6)
                        return;

                    JadeCore::RandomResizeList(p_Targets, 6);
                }
            }

            void HandleHeal(SpellEffIndex /*effIndex*/)
            {
                if (Unit *l_Caster = GetCaster())
                {
                    SpellInfo const* l_SpellInfo = sSpellMgr->GetSpellInfo(SPELL_MONK_RUSHING_JADE_WIND);

                    if (l_SpellInfo == nullptr || l_SpellInfo->GetDuration() <= 0)
                        return;

                    int l_Bp0 = (l_Caster->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_ALL) * GetSpellInfo()->Effects[EFFECT_0].BonusMultiplier) * 9;
                    l_Bp0 /= l_SpellInfo->GetDuration() / IN_MILLISECONDS;
                    SetHitHeal(l_Bp0);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_monk_rushing_jade_wind_heal_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
                OnEffectHitTarget += SpellEffectFn(spell_monk_rushing_jade_wind_heal_SpellScript::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_rushing_jade_wind_heal_SpellScript();
        }
};

enum FistsOfFurySpells
{
    //SPELL_MONK_STANCE_OF_THE_FIERCE_TIGER = 103985,
    //SPELL_MONK_2H_STAFF_OVERRIDE          = 108561,
    //SPELL_MONK_2H_POLEARM_OVERRIDE        = 115697,
    //SPELL_MONK_MANA_MEDITATION            = 121278
};

/// Fists of Fury (damage) - 117418
class spell_monk_fists_of_fury_damage : public SpellScriptLoader
{
    public:
        spell_monk_fists_of_fury_damage() : SpellScriptLoader("spell_monk_fists_of_fury_damage") { }

        class spell_monk_fists_of_fury_damage_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_fists_of_fury_damage_SpellScript);

            uint8   m_TotalTargets = 0;

            void TotalTarget(std::list<WorldObject*>& p_Targets)
            {
                m_TotalTargets = p_Targets.size();
            }

            void HandleDamage(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster())
                    return;

                Unit* l_Target = GetHitUnit();

                if (l_Target == nullptr)
                    return;

                float l_Low = 0;
                float l_High = 0;

                if (Player* l_Player = GetCaster()->ToPlayer())
                    l_Player->CalculateMonkMeleeAttacks(l_Low, l_High);

                if (l_Target->HasAura(113656))
                    SetHitDamage((7.755f * l_Low + 7.755f * l_High) / 2);
                else
                    SetHitDamage(((7.755f * l_Low + 7.755f * l_High) / 2) / m_TotalTargets);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_monk_fists_of_fury_damage_SpellScript::TotalTarget, EFFECT_0, TARGET_UNIT_CONE_ENEMY_24);
                OnEffectHitTarget += SpellEffectFn(spell_monk_fists_of_fury_damage_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_fists_of_fury_damage_SpellScript();
        }
};


/// Fists of Fury (Stun) - 120086
class spell_monk_fists_of_fury_stun: public SpellScriptLoader
{
    public:
        spell_monk_fists_of_fury_stun() : SpellScriptLoader("spell_monk_fists_of_fury_stun") { }

        class spell_monk_fists_of_fury_stun_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_fists_of_fury_stun_SpellScript);

            void RemoveInvalidTargets(std::list<WorldObject*>& p_Targets)
            {
                p_Targets.remove_if(JadeCore::UnitAuraCheck(true, GetSpellInfo()->Id, GetCaster()->GetGUID()));
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_monk_fists_of_fury_stun_SpellScript::RemoveInvalidTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_24);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_fists_of_fury_stun_SpellScript();
        }
};

enum JabSpells
{
    //SPELL_MONK_STANCE_OF_THE_FIERCE_TIGER = 103985,
    //SPELL_MONK_2H_STAFF_OVERRIDE          = 108561,
    //SPELL_MONK_2H_POLEARM_OVERRIDE        = 115697,
    //SPELL_MONK_MANA_MEDITATION            = 121278
};

class spell_monk_jab: public SpellScriptLoader
{
    public:
        spell_monk_jab() : SpellScriptLoader("spell_monk_jab") { }

        class spell_monk_jab_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_jab_SpellScript);

            void HandleDamage(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster())
                    return;

                float l_Low = 0;
                float l_High = 0;

                if (Player* l_Player = GetCaster()->ToPlayer())
                    l_Player->CalculateMonkMeleeAttacks(l_Low, l_High);

                SetHitDamage(int32(frand(1.15f * l_Low, 1.15f * l_High)));
            }
            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_monk_jab_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_jab_SpellScript();
        }
};

enum TigerPalmSpells
{
    //SPELL_MONK_STANCE_OF_THE_FIERCE_TIGER = 103985,
    //SPELL_MONK_2H_STAFF_OVERRIDE          = 108561,
    //SPELL_MONK_2H_POLEARM_OVERRIDE        = 115697,
    //SPELL_MONK_MANA_MEDITATION            = 121278
};

// Tiger Palm - 100787
class spell_monk_tiger_palm: public SpellScriptLoader
{
    public:
        spell_monk_tiger_palm() : SpellScriptLoader("spell_monk_tiger_palm") { }

        class spell_monk_tiger_palm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_tiger_palm_SpellScript);

            void HandleDamage(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster())
                    return;

                float l_Low = 0;
                float l_High = 0;
                float l_Coeff = 3.0f;

                if (Player* l_Player = GetCaster()->ToPlayer())
                {
                    l_Player->CalculateMonkMeleeAttacks(l_Low, l_High);

                    if (l_Player->GetSpecializationId(l_Player->GetActiveSpec()) == SPEC_MONK_MISTWEAVER)
                        l_Coeff = 6.0f;
                    l_Player->RemoveAurasDueToSpell(118864); // Combo Breaker
                }

                SetHitDamage(int32(frand(l_Coeff * l_Low, l_Coeff * l_High)));
            }
            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_monk_tiger_palm_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_tiger_palm_SpellScript();
        }
};

enum BlackoutKickSpells
{
    //SPELL_MONK_STANCE_OF_THE_FIERCE_TIGER = 103985,
    //SPELL_MONK_2H_STAFF_OVERRIDE          = 108561,
    //SPELL_MONK_2H_POLEARM_OVERRIDE        = 115697,
    //SPELL_MONK_MANA_MEDITATION            = 121278,
    SPELL_MONK_SHUFFLE                    = 115307,
    SPELL_MONK_BLACKOUT_KICK_DOT          = 128531,
    SPELL_MONK_BLACKOUT_KICK_HEAL         = 128591,
    SPELL_MONK_COMBAT_CONDITIONING        = 128595,
};

// Blackout Kick - 100784
class spell_monk_blackout_kick: public SpellScriptLoader
{
    public:
        spell_monk_blackout_kick() : SpellScriptLoader("spell_monk_blackout_kick") { }

        class spell_monk_blackout_kick_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_blackout_kick_SpellScript);

            void HandleDamage(SpellEffIndex /*p_EffIndex*/)
            {
                if (!GetCaster())
                    return;

                float l_Low = 0;
                float l_High = 0;

                Player* l_Player = GetCaster()->ToPlayer();
                Unit* l_Target = GetHitUnit();

                if (l_Player == nullptr || l_Target == nullptr)
                    return;

                l_Player->CalculateMonkMeleeAttacks(l_Low, l_High);

                // Base damage
                int32 l_Damage = GetHitDamage() + int32(frand(5.375f * l_Low, 5.375f * l_High));
                SetHitDamage(l_Damage);

                // Add additionnal stuff depending on spec
                if (l_Player->GetSpecializationId(l_Player->GetActiveSpec()) == SPEC_MONK_MISTWEAVER)
                {
                    l_Damage += int32(frand(4.9645f * l_Low, 4.9645f * l_High));

                    if (l_Player->HasAura(SPELL_MONK_MUSCLE_MEMORY))
                        l_Player->CastSpell(l_Player, SPELL_MONK_CRANES_ZEAL, true);
                }
                else if (l_Player->GetSpecializationId(l_Player->GetActiveSpec()) == SPEC_MONK_WINDWALKER && l_Player->getLevel() >= 20)
                {
                    if (l_Target->isInBack(l_Player))
                    {
                        int32 l_Bp0 = CalculatePct(l_Damage, GetSpellInfo()->Effects[EFFECT_1].BasePoints);
                        if (AuraPtr l_CombatConditioning = l_Player->GetAura(SPELL_MONK_COMBAT_CONDITIONING))
                            l_Bp0 += CalculatePct(l_Damage, l_CombatConditioning->GetEffect(EFFECT_0)->GetAmount());
                        l_Bp0 /= 4;

                        l_Player->CastCustomSpell(l_Target, SPELL_MONK_BLACKOUT_KICK_DOT, &l_Bp0, NULL, NULL, true);
                    }
                    else
                    {
                        int32 l_Bp0 = CalculatePct(l_Damage, GetSpellInfo()->Effects[EFFECT_1].BasePoints);
                        if (AuraPtr l_CombatConditioning = l_Player->GetAura(SPELL_MONK_COMBAT_CONDITIONING))
                            l_Bp0 += CalculatePct(l_Damage, l_CombatConditioning->GetEffect(EFFECT_0)->GetAmount());

                        l_Player->CastCustomSpell(l_Player, SPELL_MONK_BLACKOUT_KICK_HEAL, &l_Bp0, NULL, NULL, true);
                    }
                }
                else if (l_Player->GetSpecializationId(l_Player->GetActiveSpec()) == SPEC_MONK_BREWMASTER && l_Player->getLevel() >= 34)
                {
                    if (AuraPtr l_Shuffle = l_Player->GetAura(SPELL_MONK_SHUFFLE))
                    {
                        l_Shuffle->SetMaxDuration(l_Shuffle->GetMaxDuration() + 5 * IN_MILLISECONDS);
                        l_Shuffle->SetDuration(l_Shuffle->GetDuration() + 5 * IN_MILLISECONDS);
                    }
                    else
                        l_Player->CastSpell(l_Player, SPELL_MONK_SHUFFLE, true);
                }

                if (l_Player->HasAura(116768))
                    l_Player->RemoveAurasDueToSpell(116768);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_monk_blackout_kick_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_blackout_kick_SpellScript();
        }
};

enum ExpelHarmSpells
{
    //SPELL_MONK_STANCE_OF_THE_FIERCE_TIGER = 103985,
    //SPELL_MONK_2H_STAFF_OVERRIDE          = 108561,
    //SPELL_MONK_2H_POLEARM_OVERRIDE        = 115697,
    //SPELL_MONK_MANA_MEDITATION            = 121278
    SPELL_MONK_EXPEL_HARM_DAMAGE            = 115129
};

// Expel Harm - 115072
class spell_monk_expel_harm: public SpellScriptLoader
{
    public:
        spell_monk_expel_harm() : SpellScriptLoader("spell_monk_expel_harm") { }

        class spell_monk_expel_harm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_expel_harm_SpellScript);

            SpellCastResult CheckTarget()
            {
                Unit *l_Caster = GetCaster();
                Unit *l_Target = GetExplTargetUnit();

                if (l_Caster == nullptr || l_Target == nullptr)
                    return SPELL_FAILED_BAD_TARGETS;

                if (!l_Caster->HasAura(SPELL_MONK_GLYPH_OF_TARGETED_EXPULSION) && l_Target->GetGUID() != l_Caster->GetGUID())
                    return SPELL_FAILED_BAD_TARGETS;

                return SPELL_CAST_OK;
            }

            void HandleHeal(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster())
                    return;

                float l_Low = 0;
                float l_High = 0;

                Player* l_Player = GetCaster()->ToPlayer();
                Unit* l_Target = GetHitUnit();

                if (l_Player == nullptr || l_Target == nullptr)
                    return;

                l_Player->CalculateMonkMeleeAttacks(l_Low, l_High);

                int32 l_Heal = GetHitHeal() + int32(frand(7.5f * l_Low, 7.5f * l_High));

                SpellInfo const* l_SpellInfoGuard = sSpellMgr->GetSpellInfo(SPELL_MONK_GUARD);
                if (l_Target->GetGUID() == l_Player->GetGUID() && l_Player->HasAura(SPELL_MONK_GUARD) && l_SpellInfoGuard != nullptr)
                    l_Heal += CalculatePct(l_Heal, l_SpellInfoGuard->Effects[EFFECT_1].BasePoints);

                SpellInfo const* l_GlyphTargetedExpulsion = sSpellMgr->GetSpellInfo(SPELL_MONK_GLYPH_OF_TARGETED_EXPULSION);
                if (l_Player->HasAura(SPELL_MONK_GLYPH_OF_TARGETED_EXPULSION) && l_Target->GetGUID() != l_Player->GetGUID() && l_GlyphTargetedExpulsion != nullptr)
                    l_Heal = CalculatePct(l_Heal, l_GlyphTargetedExpulsion->Effects[EFFECT_1].BasePoints);

                SetHitHeal(l_Heal);

                float l_Radius = 10.0f;
                SpellInfo const* l_SpellInfo = sSpellMgr->GetSpellInfo(SPELL_MONK_EXPEL_HARM_DAMAGE);
                if (l_SpellInfo != nullptr)
                {
                    if (l_SpellInfo->Effects[EFFECT_0].RadiusEntry != nullptr)
                        l_Radius = l_SpellInfo->Effects[EFFECT_0].RadiusEntry->radiusHostile;
                }

                std::list<Unit*> l_TargetList;
                JadeCore::NearestAttackableUnitInObjectRangeCheck u_check(l_Player, l_Player, l_Radius);
                JadeCore::UnitListSearcher<JadeCore::NearestAttackableUnitInObjectRangeCheck> searcher(l_Player, l_TargetList, u_check);
                l_Player->VisitNearbyObject(l_Radius, searcher);

                for (auto l_Itr : l_TargetList)
                {
                    if (l_Player->IsValidAttackTarget(l_Itr))
                    {
                        int32 l_Bp0 = CalculatePct(l_Heal, sSpellMgr->GetSpellInfo(SPELL_MONK_EXPEL_HARM_DAMAGE)->Effects[EFFECT_1].BasePoints);
                        l_Player->CastCustomSpell(l_Itr, SPELL_MONK_EXPEL_HARM_DAMAGE, &l_Bp0, NULL, NULL, true);
                    }
                }
            }

            void Register()
            {
                OnCheckCast += SpellCheckCastFn(spell_monk_expel_harm_SpellScript::CheckTarget);
                OnEffectHitTarget += SpellEffectFn(spell_monk_expel_harm_SpellScript::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_expel_harm_SpellScript();
        }
};

enum HurricaneStrikeSpells
{
    //SPELL_MONK_STANCE_OF_THE_FIERCE_TIGER = 103985,
    //SPELL_MONK_SPINNING_CRANE_KICK_DAMAGE = 107270,
    //SPELL_MONK_2H_STAFF_OVERRIDE          = 108561,
    //SPELL_MONK_2H_POLEARM_OVERRIDE        = 115697,
    //SPELL_MONK_MANA_MEDITATION            = 121278,
    SPELL_MONK_HURRICANE_STRIKE             = 152175,
    SPELL_MONK_HURRICANE_STRIKE_DAMAGE      = 158221
};

// Hurricane Strike - 152175
class spell_monk_hurricane_strike : public SpellScriptLoader
{
    public:
        spell_monk_hurricane_strike() : SpellScriptLoader("spell_monk_hurricane_strike") { }

        class spell_monk_hurricane_strike_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_hurricane_strike_SpellScript);

            void HandleOnHit()
            {
                if (Unit* l_Caster = GetCaster())
                    l_Caster->CastSpell(l_Caster, SPELL_MONK_HURRICANE_STRIKE_DAMAGE, true);
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_monk_hurricane_strike_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_hurricane_strike_SpellScript();
        }
};

// Hurricane Strike (damage) - 158221
class spell_monk_hurricane_strike_damage: public SpellScriptLoader
{
    public:
        spell_monk_hurricane_strike_damage() : SpellScriptLoader("spell_monk_hurricane_strike_damage") { }

        class spell_monk_hurricane_strike_damage_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_hurricane_strike_damage_SpellScript);

            void HandleDamage(SpellEffIndex /*effIndex*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MONK_HURRICANE_STRIKE) || !sSpellMgr->GetSpellInfo(SPELL_MONK_HURRICANE_STRIKE)->GetDuration())
                    return;

                if (!GetCaster())
                    return;

                float l_Low = 0;
                float l_High = 0;

                Player* l_Player = GetCaster()->ToPlayer();
                if (!l_Player)
                    return;

                l_Player->CalculateMonkMeleeAttacks(l_Low, l_High);

                SetHitDamage(int32(frand(15 * 2 * l_Low, 15 * 2 * l_High) / (sSpellMgr->GetSpellInfo(SPELL_MONK_HURRICANE_STRIKE)->GetDuration() / IN_MILLISECONDS)));
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_monk_hurricane_strike_damage_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_hurricane_strike_damage_SpellScript();
        }
};


enum SerenitySpells
{
    SPELL_MONK_SERENITY = 152173
};

// Serenity - 152173
class spell_monk_serenity: public PlayerScript
{
    public:
        spell_monk_serenity() :PlayerScript("spell_monk_serenity") {}

        void OnModifyPower(Player* p_Player, Powers p_Power, int32 p_OldValue, int32& p_NewValue, bool p_Regen)
        {
            if (p_Player->getClass() != CLASS_MONK || p_Power != POWER_CHI || !p_Player->HasAura(SPELL_MONK_SERENITY) || p_Regen)
                return;

            // Get the power earn (if > 0 ) or consum (if < 0)
            int32 l_diffValue = p_NewValue - p_OldValue;

            // Only get spended chi
            if (l_diffValue > 0)
                return;

            // No cost
            p_NewValue = p_OldValue;
        }
};

enum VitalMistsSpell
{
    SPELL_MONK_VITALS_MISTS = 118674
};

/// Vital Mists - 118674  
class spell_monk_vital_mists : public PlayerScript
{
    public:
        spell_monk_vital_mists() :PlayerScript("spell_monk_vital_mists") {}

        void OnModifyPower(Player* p_Player, Powers p_Power, int32 p_OldValue, int32& p_NewValue, bool p_Regen)
        {
            if (p_Player->getClass() != CLASS_MONK || p_Power != POWER_CHI || !p_Player->HasAura(SPELL_MONK_MUSCLE_MEMORY) || p_Regen)
                return;

            // Get the power earn (if > 0 ) or consum (if < 0)
            int32 l_DiffValue = p_NewValue - p_OldValue;

            // Only get spended chi
            if (l_DiffValue > 0)
                return;

            for (int8 i = 0; i < -l_DiffValue; ++i)
                p_Player->CastSpell(p_Player, SPELL_MONK_VITALS_MISTS, true);
        }
};

enum DetoxSpells
{
    SPELL_MONK_GLYPH_OF_DETOX = 146954
};

// Detox - 115450
class spell_monk_detox: public SpellScriptLoader
{
    public:
        spell_monk_detox() : SpellScriptLoader("spell_monk_detox") { }

        class spell_monk_detox_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_detox_SpellScript);

            void HandleDispel(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);

                Player* l_Player = GetCaster()->ToPlayer();
                if (l_Player && l_Player->GetSpecializationId(l_Player->GetActiveSpec()) != SPEC_MONK_MISTWEAVER)
                    return;

                GetSpell()->EffectDispel(effIndex);
            }

            void HandleHeal(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);

                Unit* l_Caster = GetCaster();
                if (!l_Caster->HasAura(SPELL_MONK_GLYPH_OF_DETOX))
                    return;

                GetSpell()->EffectHealPct(effIndex);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_monk_detox_SpellScript::HandleDispel, EFFECT_2, SPELL_EFFECT_DISPEL);
                OnEffectHitTarget += SpellEffectFn(spell_monk_detox_SpellScript::HandleHeal, EFFECT_3, SPELL_EFFECT_HEAL_PCT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_detox_SpellScript();
        }
};

enum RisingSunKickSpells
{
    PoolOfMists = 173841
};

/// Rising Sun Kick - 107428
class spell_monk_rising_sun_kick: public SpellScriptLoader
{
    public:
        spell_monk_rising_sun_kick() : SpellScriptLoader("spell_monk_rising_sun_kick") { }

        class spell_monk_rising_sun_kick_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_rising_sun_kick_SpellScript);

            void HandleDamage(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster())
                    return;

                int32 l_PctModifier = 0;
                float l_Low = 0;
                float l_High = 0;

                Player* l_Player = GetCaster()->ToPlayer();
                Unit* l_Target = GetHitUnit();

                if (l_Player == nullptr || l_Target == nullptr)
                    return;

                l_Player->CalculateMonkMeleeAttacks(l_Low, l_High);

                if (l_Player->GetSpecializationId(l_Player->GetActiveSpec()) == SPEC_MONK_WINDWALKER)
                    l_Player->CastSpell(l_Target, SPELL_MONK_MORTEL_WOUNDS, true);

                /// Causing all enemies within 8 yards to take 20% increased damage from your abilities for 15 sec.
                l_Player->CastSpell(l_Player, SPELL_MONK_RISING_SUN_KICK_DAMAGE_BONUS, true);

                if (l_Player->HasAura(RisingSunKickSpells::PoolOfMists))
                    l_PctModifier = l_Player->GetAura(RisingSunKickSpells::PoolOfMists)->GetEffect(EFFECT_3)->GetAmount();

                int32 l_Bp = int32(frand(8.0f * l_Low, 8.0f * l_High));

                l_Bp += CalculatePct(l_Bp, l_PctModifier);

                SetHitDamage(l_Bp);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_monk_rising_sun_kick_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_rising_sun_kick_SpellScript();
        }
};

// Stance of the Fierce Tiger - 103985
class spell_monk_stance_of_tiger: public SpellScriptLoader
{
    public:
        spell_monk_stance_of_tiger() : SpellScriptLoader("spell_monk_stance_of_tiger") { }

        class spell_monk_stance_of_tiger_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_stance_of_tiger_AuraScript);

            void OnRemove(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    caster->RemoveAura(166646);
            }

            void OnApply(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    caster->CastSpell(caster, 166646, true);
            }

            void Register()
            {
                AfterEffectApply += AuraEffectApplyFn(spell_monk_stance_of_tiger_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_monk_stance_of_tiger_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_monk_stance_of_tiger_AuraScript();
        }
};

// Uplift - 116670
class spell_monk_uplift : public SpellScriptLoader
{
    public:
        spell_monk_uplift() : SpellScriptLoader("spell_monk_uplift") { }

        class spell_monk_uplift_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_uplift_SpellScript);

            void CorrectTarget(std::list<WorldObject*>& p_Targets)
            {
                std::list<WorldObject*> l_TempTargets = p_Targets;
                for (auto itr : l_TempTargets)
                {
                    if (itr->ToUnit() == nullptr || !itr->ToUnit()->HasAura(SPELL_MONK_RENEWING_MIST_HOT))
                        p_Targets.remove(itr);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_monk_uplift_SpellScript::CorrectTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_monk_uplift_SpellScript::CorrectTarget, EFFECT_1, TARGET_UNIT_SRC_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_uplift_SpellScript();
        }
};

// Glyph of rapid rolling - 146951
class spell_monk_glyph_of_rapid_rolling : public SpellScriptLoader
{
public:
    spell_monk_glyph_of_rapid_rolling() : SpellScriptLoader("spell_monk_glyph_of_rapid_rolling") { }

    class spell_monk_glyph_of_rapid_rolling_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_glyph_of_rapid_rolling_SpellScript);

        void HandleAfterCast()
        {
            if (Unit* l_Caster = GetCaster())
            {
                if (l_Caster->HasAura(SPELL_MONK_GLYPH_OF_RAPID_ROLLING))
                    l_Caster->CastSpell(l_Caster, SPELL_MONK_RAPID_ROLLING, true);
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_monk_glyph_of_rapid_rolling_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_glyph_of_rapid_rolling_SpellScript();
    }
};

enum AfterLifeSpells
{
    SPELL_MONK_BLACKOUT_KICK = 100784,
    SPELL_MONK_SUMMON_HEALING_SPHERE = 117032,
    SPELL_MONK_SUMMON_CHI_SPHERE = 121286,
    SPELL_MONK_CHI_EXPLOSION = 152174
};

// Afterlife - 116092
class spell_monk_afterlife: public SpellScriptLoader
{
    public:
        spell_monk_afterlife() : SpellScriptLoader("spell_monk_afterlife") { }

        class spell_monk_afterlife_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_afterlife_AuraScript);

            void OnProcHealingSphere(constAuraEffectPtr aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                if (eventInfo.GetDamageInfo()->GetSpellInfo() && eventInfo.GetDamageInfo()->GetSpellInfo()->Id == SPELL_MONK_BLACKOUT_KICK)
                    return;

                if (Unit* l_Caster = GetCaster())
                    l_Caster->CastSpell(l_Caster, SPELL_MONK_SUMMON_HEALING_SPHERE, true);
            }

            void OnProcChiSphere(constAuraEffectPtr aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                if (!eventInfo.GetDamageInfo()->GetSpellInfo())
                    return;

                Unit* l_Caster = GetCaster();
                if (!l_Caster)
                    return;

                /// Can proc only from Blackout Kick or Chi Explosion
                if ((!l_Caster->HasAura(SPELL_MONK_CHI_EXPLOSION) && eventInfo.GetDamageInfo()->GetSpellInfo()->Id != SPELL_MONK_BLACKOUT_KICK) ||(l_Caster->HasAura(SPELL_MONK_CHI_EXPLOSION) && eventInfo.GetDamageInfo()->GetSpellInfo()->Id != SPELL_MONK_CHI_EXPLOSION))
                    return;

                if (roll_chance_f(aurEff->GetAmount()))
                    l_Caster->CastSpell(l_Caster, SPELL_MONK_SUMMON_CHI_SPHERE, true);
            }

            void Register()
            {
                OnEffectProc += AuraEffectProcFn(spell_monk_afterlife_AuraScript::OnProcHealingSphere, EFFECT_0, SPELL_AURA_DUMMY);
                OnEffectProc += AuraEffectProcFn(spell_monk_afterlife_AuraScript::OnProcChiSphere, EFFECT_1, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_monk_afterlife_AuraScript();
        }
};

enum GiftOfTheSerpent
{
    SpellHealingSphere = 124041
};

/// Gift of the Serpent (healing sphere) - 119031
class AreaTrigger_healing_sphere : public AreaTriggerEntityScript
{
    public:
        AreaTrigger_healing_sphere() : AreaTriggerEntityScript("at_healing_sphere") { }

        AreaTriggerEntityScript* GetAI() const
        {
            return new AreaTrigger_healing_sphere();
        }

        void OnUpdate(AreaTrigger* p_AreaTrigger, uint32 p_Time)
        {
            SpellInfo const* l_CreateSpell = sSpellMgr->GetSpellInfo(p_AreaTrigger->GetSpellId());
            Unit* l_AreaTriggerCaster = p_AreaTrigger->GetCaster();

            if (l_AreaTriggerCaster && l_CreateSpell)
            {
                float l_Radius = 1.0f;
                Unit* l_Target = nullptr;

                JadeCore::AnyFriendlyUnitInObjectRangeCheck l_Checker(p_AreaTrigger, l_AreaTriggerCaster, l_Radius);
                JadeCore::UnitSearcher<JadeCore::AnyFriendlyUnitInObjectRangeCheck> l_Searcher(p_AreaTrigger, l_Target, l_Checker);
                p_AreaTrigger->VisitNearbyGridObject(l_Radius, l_Searcher);
                if (!l_Target)
                    p_AreaTrigger->VisitNearbyWorldObject(l_Radius, l_Searcher);

                if (l_Target != nullptr)
                {
                    l_AreaTriggerCaster->CastSpell(l_Target, GiftOfTheSerpent::SpellHealingSphere, true);
                    p_AreaTrigger->Remove(0);
                }
            }
        }
};

enum ChiExplosionMistweaverSpells
{
    SPELL_CHI_EXPLOSION_HEAL    = 182078,
    SPELL_CHI_EXPLOSION_HOT     = 157681,
    SPELL_CHI_EXPLOSION_DOT     = 157680
};

uint32 g_MonkHealingSphereSpells[] = { 157682, 157683, 157684, 157685, 157686, 157687, 157688, 157689 };

/// last update : 6.1.2 19802
/// Chi Explosion - 157675
class spell_monk_chi_explosion_mistweaver: public SpellScriptLoader
{
    public:
        spell_monk_chi_explosion_mistweaver() : SpellScriptLoader("spell_monk_chi_explosion_mistweaver") { }

        class spell_monk_chi_explosion_mistweaver_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_chi_explosion_mistweaver_SpellScript);

            void HandleDummy(SpellEffIndex effIndex)
            {
                Unit* l_Caster = GetCaster();
                Unit* l_Target = GetHitUnit();

                uint8 l_Chi = l_Caster->GetPower(POWER_CHI) + 1;    /// 1 was already consumed
                int32 l_HealAmount = sSpellMgr->GetSpellInfo(SPELL_CHI_EXPLOSION_HEAL)->Effects[EFFECT_0].CalcValue(l_Caster, nullptr, l_Target) * (l_Chi); /// 1 applied in calcvalue
                int32 l_HotTotalHealAmount = sSpellMgr->GetSpellInfo(SPELL_CHI_EXPLOSION_HEAL)->Effects[EFFECT_0].CalcValue(l_Caster, nullptr, l_Target) * (l_Chi + 1);
                int32 l_NullBP = 0;

                if (l_Chi <= 2)
                {
                    if (l_Chi == 2)
                    {
                        SpellInfo const* l_HotSpellInfo = sSpellMgr->GetSpellInfo(SPELL_CHI_EXPLOSION_HOT);
                        int32 l_HotHealing = CalculatePct(l_HotTotalHealAmount, l_HotSpellInfo->Effects[EFFECT_1].BasePoints / (l_HotSpellInfo->GetDuration() / l_HotSpellInfo->Effects[EFFECT_0].Amplitude));
                        l_Caster->CastCustomSpell(l_Target, SPELL_CHI_EXPLOSION_HOT, &l_HotHealing, nullptr, nullptr, true);
                    }

                    l_Caster->CastCustomSpell(l_Target, SPELL_CHI_EXPLOSION_HEAL, &l_HealAmount, &l_NullBP, nullptr, true);
                }
                else
                    l_Caster->CastCustomSpell(l_Target, SPELL_CHI_EXPLOSION_HEAL, &l_NullBP, &l_HealAmount, nullptr, true);

                if (l_Chi == 4)
                {
                    for (int l_I = 0; l_I < sizeof(g_MonkHealingSphereSpells) / sizeof(int); l_I++)
                        l_Caster->CastSpell(l_Caster, g_MonkHealingSphereSpells[l_I], true);
                }

                l_Caster->SetPower(POWER_CHI, 0);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_monk_chi_explosion_mistweaver_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_chi_explosion_mistweaver_SpellScript();
        }
};

/// last update : 6.1.2 19802
/// Chi Explosion - 182078
class spell_monk_chi_explosion_heal: public SpellScriptLoader
{
    public:
        spell_monk_chi_explosion_heal() : SpellScriptLoader("spell_monk_chi_explosion_heal") { }

        class spell_monk_chi_explosion_heal_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_chi_explosion_heal_SpellScript);

            bool Load()
            {
                m_Targets = 1;
                return true;
            }

            void FilterTargets(std::list<WorldObject*>& p_Targets)
            {
                SpellValue const* l_SpellValues = GetSpellValue();
                if (!l_SpellValues)
                    return;

                if (l_SpellValues->EffectBasePoints[EFFECT_1])
                {
                    if (!p_Targets.size())
                        return;

                    Unit* l_MainTarget = (*p_Targets.begin())->ToUnit();
                    std::list<Unit*> l_UnitList;
                    JadeCore::AnyFriendlyUnitInObjectRangeCheck u_check(l_MainTarget, l_MainTarget, 8.f);
                    JadeCore::UnitListSearcher<JadeCore::AnyFriendlyUnitInObjectRangeCheck> searcher(l_MainTarget, l_UnitList, u_check);
                    l_MainTarget->VisitNearbyObject(8.f, searcher);

                    for (auto& l_Iter : l_UnitList)
                        if (std::find(p_Targets.begin(), p_Targets.end(), l_Iter) == p_Targets.end())
                            p_Targets.push_back(l_Iter);
                }

                m_Targets = p_Targets.size();
                if (!m_Targets)
                    m_Targets = 1;
            }

            void HandleOnHit()
            {
                SetHitHeal(GetHitHeal() / m_Targets);
            }

            void HandleHitTarget(SpellEffIndex /*p_EffIndex*/)
            {
                if (GetCaster()->GetPower(POWER_CHI) < 2)
                    return;

                SpellInfo const* l_HotSpellInfo = sSpellMgr->GetSpellInfo(SPELL_CHI_EXPLOSION_HOT);
                int32 l_HotHealing = CalculatePct(GetHitHeal() / m_Targets, l_HotSpellInfo->Effects[EFFECT_1].BasePoints / (l_HotSpellInfo->GetDuration() / l_HotSpellInfo->Effects[EFFECT_0].Amplitude));
                GetCaster()->CastCustomSpell(GetHitUnit(), SPELL_CHI_EXPLOSION_HOT, &l_HotHealing, nullptr, nullptr, true);
            }

            uint8 m_Targets;

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_monk_chi_explosion_heal_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ALLY);
                OnHit += SpellHitFn(spell_monk_chi_explosion_heal_SpellScript::HandleOnHit);
                OnEffectHitTarget += SpellEffectFn(spell_monk_chi_explosion_heal_SpellScript::HandleHitTarget, EFFECT_1, SPELL_EFFECT_HEAL);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_chi_explosion_heal_SpellScript();
        }
};

/// last update : 6.1.2 19802
/// Chi Explosion - 159620
class spell_monk_chi_explosion_mistweaver_crane: public SpellScriptLoader
{
    public:
        spell_monk_chi_explosion_mistweaver_crane() : SpellScriptLoader("spell_monk_chi_explosion_mistweaver_crane") { }

        class spell_monk_chi_explosion_mistweaver_crane_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_chi_explosion_mistweaver_crane_SpellScript);

            void HandleHitDamage(SpellEffIndex /*p_EffIndex*/)
            {
                SetHitDamage(GetHitDamage()* GetCaster()->GetPower(POWER_CHI) + 2); /// 1 taken + 1 as base
            }

            void HandleHitTarget(SpellEffIndex p_EffIndex)
            {
                uint8 l_Chi = GetCaster()->GetPower(POWER_CHI) + 1;

                if (l_Chi < 2)
                {
                    PreventHitHeal();
                    return;
                }

                if (l_Chi > 2 && p_EffIndex == EFFECT_1)
                    return;
                else if (l_Chi < 3 && p_EffIndex == EFFECT_2)
                    return;

                SetHitHeal(GetHitHeal() * (l_Chi + 1));
            }

            void HandleAfterCast()
            {
                Unit* l_Caster = GetCaster();
                if (l_Caster->GetPower(POWER_CHI) == 3)
                    for (int l_I = 0; l_I < sizeof(g_MonkHealingSphereSpells) / sizeof(int); l_I++)
                        l_Caster->CastSpell(l_Caster, g_MonkHealingSphereSpells[l_I], true);

                l_Caster->SetPower(POWER_CHI, 0);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_monk_chi_explosion_mistweaver_crane_SpellScript::HandleHitDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                OnEffectHitTarget += SpellEffectFn(spell_monk_chi_explosion_mistweaver_crane_SpellScript::HandleHitTarget, EFFECT_1, SPELL_EFFECT_HEAL);
                OnEffectHitTarget += SpellEffectFn(spell_monk_chi_explosion_mistweaver_crane_SpellScript::HandleHitTarget, EFFECT_2, SPELL_EFFECT_HEAL);
                AfterCast += SpellCastFn(spell_monk_chi_explosion_mistweaver_crane_SpellScript::HandleAfterCast);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_chi_explosion_mistweaver_crane_SpellScript();
        }
};

/// last update : 6.1.2 19802
/// Chi Explosion - 152174
class spell_monk_chi_explosion_windwalker: public SpellScriptLoader
{
    public:
        spell_monk_chi_explosion_windwalker() : SpellScriptLoader("spell_monk_chi_explosion_windwalker") { }

        class spell_monk_chi_explosion_windwalker_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_chi_explosion_windwalker_SpellScript);

            void HandleHitTarget(SpellEffIndex p_EffIndex)
            {
                uint8 l_Chi = std::min(GetCaster()->GetPower(POWER_CHI) + 1, 4);

                if (l_Chi > 3 && p_EffIndex == EFFECT_0)
                    return;
                else if (l_Chi < 4 && p_EffIndex == EFFECT_1)
                    return;

                int32 l_Damage = GetHitDamage() * (l_Chi + 1);
                if (GetHitUnit() != GetExplTargetUnit())
                    l_Damage /= 3;

                SetHitDamage(l_Damage);

                if (l_Chi >= 1)
                {
                    SpellInfo const* l_DotSpellInfo = sSpellMgr->GetSpellInfo(SPELL_CHI_EXPLOSION_DOT);
                    l_Damage = CalculatePct(l_Damage , l_DotSpellInfo->Effects[EFFECT_1].BasePoints / (l_DotSpellInfo->GetDuration() / l_DotSpellInfo->Effects[EFFECT_0].Amplitude));
                    GetCaster()->CastCustomSpell(GetHitUnit(), SPELL_CHI_EXPLOSION_DOT, &l_Damage, nullptr, nullptr, true);
                }
            }

            void HandleAfterCast()
            {
                Unit* l_Caster = GetCaster();
                int32 l_Chi = l_Caster->GetPower(POWER_CHI) + 1;

                if (l_Chi >= 3)
                    l_Caster->CastSpell(l_Caster, SPELL_MONK_TIGEREYE_BREW_STACKS, true);

                l_Caster->ModifyPower(POWER_CHI, -3);
                if (AuraPtr l_Aura = l_Caster->GetAura(SPELL_MONK_COMBO_BREAKER_CHI_EXPLOSION))
                {
                    l_Caster->ModifyPower(POWER_CHI, std::min(2, l_Chi));
                    l_Aura->Remove();
                }
            }

            void FilterTargets(std::list<WorldObject*>& p_Targets)
            {
                Unit* l_Caster = GetCaster();
                if (l_Caster->GetPower(POWER_CHI) <= 3)
                {
                    p_Targets.clear();

                    if (Unit* l_Target = GetHitUnit())
                        p_Targets.push_back(l_Target);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_monk_chi_explosion_windwalker_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_monk_chi_explosion_windwalker_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                OnEffectHitTarget += SpellEffectFn(spell_monk_chi_explosion_windwalker_SpellScript::HandleHitTarget, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
                AfterCast += SpellCastFn(spell_monk_chi_explosion_windwalker_SpellScript::HandleAfterCast);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_chi_explosion_windwalker_SpellScript();
        }
};

/// last update : 6.1.2 19802
/// Chi Explosion - 157676
class spell_monk_chi_explosion_brewmaster: public SpellScriptLoader
{
    public:
        spell_monk_chi_explosion_brewmaster() : SpellScriptLoader("spell_monk_chi_explosion_brewmaster") { }

        class spell_monk_chi_explosion_brewmaster_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_chi_explosion_brewmaster_SpellScript);

            void HandleHitTarget(SpellEffIndex p_EffIndex)
            {
                uint8 l_Chi = std::min(GetCaster()->GetPower(POWER_CHI) + 1, 4);

                if (l_Chi > 3 && p_EffIndex == EFFECT_0)
                    return;
                else if (l_Chi < 4 && p_EffIndex == EFFECT_1)
                    return;

                int32 l_Damage = GetHitDamage() * (l_Chi + 1);
                if (GetHitUnit() != GetExplTargetUnit())
                    l_Damage /= 3;

                SetHitDamage(l_Damage);
            }

            void HandleAfterCast()
            {
                Unit* l_Caster = GetCaster();
                int32 l_Chi = l_Caster->GetPower(POWER_CHI) + 1;

                if (l_Chi >= 3)
                {
                    l_Caster->RemoveAurasDueToSpell(SPELL_MONK_LIGHT_STAGGER);
                    l_Caster->RemoveAurasDueToSpell(SPELL_MONK_MODERATE_STAGGER);
                    l_Caster->RemoveAurasDueToSpell(SPELL_MONK_HEAVY_STAGGER);
                }

                if (l_Chi >= 2)
                {
                    uint32 l_Duration = (l_Chi * 2 + 2) * IN_MILLISECONDS;

                    if (AuraPtr l_Aura = l_Caster->AddAura(SPELL_MONK_SHUFFLE, l_Caster))
                        l_Aura->SetDuration(l_Duration);
                }

                l_Caster->ModifyPower(POWER_CHI, -3);
            }

            void FilterTargets(std::list<WorldObject*>& p_Targets)
            {
                Unit* l_Caster = GetCaster();
                if (l_Caster->GetPower(POWER_CHI) <= 3)
                {
                    p_Targets.clear();

                    if (Unit* l_Target = GetHitUnit())
                        p_Targets.push_back(l_Target);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_monk_chi_explosion_brewmaster_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_monk_chi_explosion_brewmaster_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                OnEffectHitTarget += SpellEffectFn(spell_monk_chi_explosion_brewmaster_SpellScript::HandleHitTarget, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
                AfterCast += SpellCastFn(spell_monk_chi_explosion_brewmaster_SpellScript::HandleAfterCast);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_chi_explosion_brewmaster_SpellScript();
        }
};

/// last update : 6.1.2 19802
/// Monk WoD PvP Brewmaster 2P Bonus - 165691
class spell_monk_WoDPvPBrewmaster2PBonus : public SpellScriptLoader
{
    public:
        spell_monk_WoDPvPBrewmaster2PBonus() : SpellScriptLoader("spell_monk_WoDPvPBrewmaster2PBonus") { }

        class spell_monk_WoDPvPBrewmaster2PBonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_monk_WoDPvPBrewmaster2PBonus_AuraScript);

            void OnProc(constAuraEffectPtr aurEff, ProcEventInfo& p_ProcInfo)
            {
                PreventDefaultAction();
            }

            void Register()
            {
                OnEffectProc += AuraEffectProcFn(spell_monk_WoDPvPBrewmaster2PBonus_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_monk_WoDPvPBrewmaster2PBonus_AuraScript();
        }
};

/// last update : 6.1.2 19802
/// Detonate Chi - 115460
class spell_monk_detonate_chi : public SpellScriptLoader
{
    public:
        spell_monk_detonate_chi() : SpellScriptLoader("spell_monk_detonate_chi") { }

        class spell_monk_detonate_chi_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_monk_detonate_chi_SpellScript);

            enum eSpells
            {
                HealingSphereAreaTrigger    = 119031,
                HealingSphereDetonate       = 135920
            };

            void HandleCast()
            {
                Unit* l_Caster = GetCaster();

                std::list<AreaTrigger*> l_HealingSphereList;
                l_Caster->GetAreaTriggerList(l_HealingSphereList, eSpells::HealingSphereAreaTrigger);

                if (!l_HealingSphereList.empty())
                {
                    for (auto itr : l_HealingSphereList)
                    {
                        Unit* l_Caster = itr->GetCaster();

                        if (l_Caster != nullptr)
                            l_Caster->CastSpell(itr->GetPositionX(), itr->GetPositionY(), itr->GetPositionZ(), eSpells::HealingSphereDetonate, true);
                        itr->SetDuration(0);
                        break;
                    }
                }
            }

            void Register()
            {
                OnCast += SpellCastFn(spell_monk_detonate_chi_SpellScript::HandleCast);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_monk_detonate_chi_SpellScript();
        }
};

void AddSC_monk_spell_scripts()
{
    new spell_monk_uplift();
    new spell_monk_rising_sun_kick();
    new spell_monk_stance_of_tiger();
    new spell_monk_combo_breaker();
    new spell_monk_ring_of_peace_dummy();
    new spell_monk_ring_of_peace();
    new spell_monk_storm_earth_and_fire_stats();
    new spell_monk_storm_earth_and_fire();
    new spell_monk_chi_brew();
    new spell_monk_chi_wave_healing_bolt();
    new spell_monk_chi_wave_bolt();
    new spell_monk_chi_wave();
    new spell_monk_transcendence_transfer();
    new spell_monk_dampen_harm();
    new spell_monk_item_s12_4p_mistweaver();
    new spell_monk_diffuse_magic();
    new spell_monk_black_ox_statue();
    new spell_monk_guard();
    new spell_monk_zen_flight_check();
    new spell_monk_glyph_of_zen_flight();
    new spell_monk_power_strikes();
    new spell_monk_crackling_jade_lightning();
    new spell_monk_touch_of_karma();
    new spell_monk_thunder_focus_tea();
    new spell_monk_jade_serpent_statue();
    new spell_monk_teachings_of_the_monastery();
    new spell_monk_mana_tea();
    new spell_monk_mana_tea_stacks();
    new spell_monk_enveloping_mist();
    new spell_monk_surging_mist();
    new spell_monk_renewing_mist_hot();
    new spell_monk_renewing_mist();
    new spell_monk_healing_elixirs_aura();
    new spell_monk_healing_elixirs();
    new spell_monk_zen_sphere();
    new spell_monk_chi_burst();
    new spell_monk_energizing_brew();
    new spell_monk_spear_hand_strike();
    new spell_monk_tigereye_brew();
    new spell_monk_tigers_lust();
    new spell_monk_flying_serpent_kick();
    new spell_monk_chi_torpedo();
    new spell_monk_purifying_brew();
    new spell_monk_keg_smash();
    new spell_monk_elusive_brew();
    new spell_monk_breath_of_fire();
    new spell_monk_soothing_mist();
    new spell_monk_disable();
    new spell_monk_zen_pilgrimage();
    new spell_monk_fortifying_brew();
    new spell_monk_touch_of_death();
    new spell_monk_paralysis();
    new spell_monk_provoke();
    new spell_monk_provoke_launch();
    new spell_monk_roll();
    new spell_monk_tigereye_brew_stacks();
    new spell_monk_spinning_crane_kick();
    new spell_monk_rushing_jade_wind();
    new spell_monk_rushing_jade_wind_damage();
    new spell_monk_rushing_jade_wind_heal();
    new spell_monk_jab();
    new spell_monk_tiger_palm();
    new spell_monk_blackout_kick();
    new spell_monk_expel_harm();
    new spell_monk_hurricane_strike_damage();
    new spell_monk_hurricane_strike();
    new spell_monk_serenity();
    new spell_monk_detox();
    new spell_monk_glyph_of_rapid_rolling();
    new spell_monk_afterlife();
    new spell_monk_fists_of_fury_damage();
    new spell_monk_fists_of_fury_stun();
    new spell_monk_eminence_heal();
    new spell_monk_chi_explosion_mistweaver();
    new spell_monk_chi_explosion_heal();
    new spell_monk_chi_explosion_mistweaver_crane();
    new spell_monk_chi_explosion_brewmaster();
    new spell_monk_chi_explosion_windwalker();
    new spell_monk_detonate_chi();
    new spell_monk_WoDPvPBrewmaster2PBonus();
    new spell_monk_zen_sphere_tick();

    /// Player Script
    new PlayerScript_TigereEyeBrew_ManaTea();
    new spell_monk_vital_mists();

    /// AreaTrigger Script
    new AreaTrigger_healing_sphere();
}
