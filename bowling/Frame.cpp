#include "Frame.h"

bool Frame::IsCorrectRolls(int firstRoll, int secondRoll)
{
    if (firstRoll == NO_ROLL && secondRoll == NO_ROLL)
    {
        return true;
    }

    if (firstRoll <= TOTAL_PINS && secondRoll == NO_ROLL)
    {
        return true;
    }

    if (firstRoll != NO_ROLL && secondRoll != NO_ROLL && firstRoll + secondRoll <= TOTAL_PINS)
    {
        return true;
    }

    return false;
}

void Frame::SetFirstRoll(int val)
{
    if (m_FirstRoll != NO_ROLL)
    {
        throw std::logic_error("Roll is already done");
    }
    if (!IsCorrectRolls(val, NO_ROLL))
    {
        throw std::invalid_argument("Incorrect rolls");
    }
    m_FirstRoll = val;
}

void Frame::SetSecondRoll(int val)
{
    if (m_SecondRoll != NO_ROLL)
    {
        throw std::logic_error("Roll is already done");
    }
    if (m_FirstRoll == NO_ROLL)
    {
        throw std::logic_error("You should make first roll before second roll");
    }
    if (!IsCorrectRolls(m_FirstRoll, val))
    {
        throw std::invalid_argument("Incorrect rolls");
    }
    m_SecondRoll = val;
}

int Frame::TakeAdditinalRolls(int number) const
{
    if (m_NextFrames[0] != nullptr)
    {
        if (number == 2 && m_NextFrames[0]->CountRolls() == 2)
        {
            return m_NextFrames[0]->GetFirstRoll() + m_NextFrames[0]->GetSecondRoll();
        }
        if (number == 1 && m_NextFrames[0]->CountRolls() == 1)
        {
            return m_NextFrames[0]->GetFirstRoll();
        }
        if (number == 2 && m_NextFrames[0]->CountRolls() == 1)
        {
            int sum = m_NextFrames[0]->GetFirstRoll();
            if (m_NextFrames[1] != nullptr && m_NextFrames[1]->CountRolls() >= 1)
            {
                sum += m_NextFrames[1]->GetFirstRoll();
            }
            return sum;
        }
    }
    return 0;
}
