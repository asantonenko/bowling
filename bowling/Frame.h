#ifndef FRAME_H
#define FRAME_H

#include<stdexcept>

const int TOTAL_PINS = 10;
const int NO_ROLL = -1;

class Frame
{
    public:
        Frame(int firstRoll = NO_ROLL, int secondRoll = NO_ROLL) : m_FirstRoll(firstRoll), m_SecondRoll (secondRoll)
        {
            if (!IsCorrectRolls(firstRoll, secondRoll))
            {
                throw std::invalid_argument("Incorrect rolls");
            }
        }
        virtual ~Frame(){}

        int GetFirstRoll() const{ return m_FirstRoll; }
        void SetFirstRoll(int val);
        int GetSecondRoll() const { return m_SecondRoll; }
        void SetSecondRoll(int val);

        bool isStrike() const
        {
            return m_FirstRoll == TOTAL_PINS;
        }

        bool isSpare() const
        {
            return !isStrike() && m_FirstRoll + m_SecondRoll == TOTAL_PINS;
        }

        int CountRolls() const
        {
            if (m_FirstRoll == NO_ROLL)
            {
                return 0;
            }
            if (m_SecondRoll == NO_ROLL)
            {
                return 1;
            }
            return 2;
        }

		virtual int Sum() const;
        

        bool IsFrameFinished() const
        {
            return (CountRolls() == 2) || (CountRolls() == 1 && isStrike());
        }

    protected:

    private:
        int m_FirstRoll;
        int m_SecondRoll;

        Frame* m_NextFrames[2];

        static bool IsCorrectRolls(int firstRoll, int secondRoll); // Чи може бути два кмдки firstRoll secondRoll

        int TakeAdditinalRolls(int number) const;
};

#endif // FRAME_H
