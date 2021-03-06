/*
 * =====================================================================================
 *
 *       Filename: standnpc.hpp
 *        Created: 04/12/2020 12:49:26
 *    Description: 
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
#include "processrun.hpp"
#include "actionnode.hpp"
#include "clientcreature.hpp"

class StandNPC: public ClientCreature
{
    public:
        StandNPC(uint64_t, ProcessRun *, const ActionNode &);

    public:
        uint16_t lookID() const
        {
            return uidf::getLookID(UID());
        }

    protected:
        int32_t gfxID() const;

    public:
        bool draw(int, int, int) override;

    public:
        int motionFrameCount(int, int) const override;

    private:
        int32_t gfxShadowID(int32_t) const;
        bool canFocus(int , int) const override;

    public:
        std::tuple<int, int> location() const override
        {
            return {m_currMotion.endX, m_currMotion.endY};
        }

        bool parseAction(const ActionNode &) override;
        bool update(double) override;
        bool motionValid(const MotionNode &) const override;

    public:
        int gfxMotionID(int) const override;

    public:
        bool moveNextMotion() override
        {
            m_currMotion = makeIdleMotion();
            return true;
        }
};
