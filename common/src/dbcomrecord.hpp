/*
 * =====================================================================================
 *
 *       Filename: dbcomrecord.hpp
 *        Created: 07/28/2017 23:03:43
 *    Description: split from dbcom.hpp
 *                 don't include dbcomid.hpp in this header file
 *
 *        Version: 1.0
 *       Revision: none
 *       Compiler: gcc
 *
 *         Author: ANHONG
 *          Email: anhonghe@gmail.com
 *   Organization: USTC
 *
 * =====================================================================================
 */

#pragma once
#include <cstdint>
#include "npcrecord.hpp"
#include "maprecord.hpp"
#include "itemrecord.hpp"
#include "magicrecord.hpp"
#include "monsterrecord.hpp"

const ItemRecord &DBCOM_ITEMRECORD(uint32_t);
const ItemRecord &DBCOM_ITEMRECORD(const char *);

const MagicRecord &DBCOM_MAGICRECORD(uint32_t);
const MagicRecord &DBCOM_MAGICRECORD(const char *);

const MonsterRecord &DBCOM_MONSTERRECORD(uint32_t);
const MonsterRecord &DBCOM_MONSTERRECORD(const char *);

const MapRecord &DBCOM_MAPRECORD(uint32_t);
const MapRecord &DBCOM_MAPRECORD(const char *);

const NPCRecord &DBCOM_NPCRECORD(uint32_t);
const NPCRecord &DBCOM_NPCRECORD(const char *);
