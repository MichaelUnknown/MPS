/**
 * Copyright (c) 2012 Andrew Prock. All rights reserved.
 * $Id: DrawHighHandEvaluator.h 2649 2012-06-30 04:53:24Z prock $
 */
#ifndef PEVAL_DRAWHIGHHANDEVALUATOR_H_
#define PEVAL_DRAWHIGHHANDEVALUATOR_H_

#include <pokerstove/peval/PokerHandEvaluator.h>

namespace pokerstove
{
    /**
     * A specialized hand evaluator for hold'em.  Not as slow.
     */
    class DrawHighHandEvaluator : public PokerHandEvaluator
    {
       public:
        DrawHighHandEvaluator() : PokerHandEvaluator(), _handSize(5) {}

        virtual PokerHandEvaluation evaluateHand(const CardSet& hand, const CardSet&) const
        {
            return PokerHandEvaluation(hand.evaluateHigh());
        }

        virtual PokerEvaluation evaluateRanks(const CardSet& hand, const CardSet& board = CardSet(0)) const
        {
            return hand.evaluateHighRanks();
        }

        virtual PokerEvaluation evaluateSuits(const CardSet& hand, const CardSet& board = CardSet(0)) const
        {
            return hand.evaluateHighFlush();
        }

        virtual size_t handSize() const { return _handSize; }
        virtual size_t boardSize() const { return 0; }
        virtual size_t evaluationSize() const { return 1; }
        virtual void setHandSize(size_t sz) { _handSize = sz; }

       private:
        size_t _handSize;
    };

}    // namespace pokerstove
#endif    // PEVAL_DRAWHIGHHANDEVALUATOR_H_
